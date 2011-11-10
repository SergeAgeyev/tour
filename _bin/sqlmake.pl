# �������� ������� :
# SourceFileName ScriptDropFileName ScriptCreateFileName
#
# SourceFileName         - ���� ����������� PowerDesigner (������ �� ��������)
#                           ���� ������ � ��������� �� ��������
# ScriptDropFileName     - ��� ����� ������� ����� ��������� ������� ��
#                           �������� ���� ������
# ScriptCreateFileName   - ��� ����� ������� ����� ��������� ������� ��
#                           ������� ����� ������
#


use POSIX;
#----------------------------------------------------------------------------
sub FileHeaderOut(\*)
 {
  my($OutputFileHandler) = @_;

  print $OutputFileHandler '--'.('=' x 76)."\n";
  print $OutputFileHandler "-- \n";
  print $OutputFileHandler '-- ������: ';
  print $OutputFileHandler strftime "%H:%M:%S %d/%m/%Y", localtime;
  print $OutputFileHandler "\n";
  print $OutputFileHandler "-- \n";
  print $OutputFileHandler '--'.('=' x 76)."\n"."\n";
 }
#----------------------------------------------------------------------------
sub FileTableOut(\*$)
 {
  my $OutputFileHandler = $_[0];
  my $OutStr = $_[1];


  if ($OutStr =~ /create table/)
   {
    my $TableNameStr;
    $TableNameStr = $OutStr;
    $TableNameStr =~ s/( *create table *)(\w+)(.*)/$2/gsi;

    #������� �������� �������
    $TableNameStr =~ s/(\s)//g;

    #����� ����������� � ������ ����������� �������
    print $OutputFileHandler '--'.('=' x 76)."\n";
    print $OutputFileHandler '-- Table : '.$TableNameStr."\n";
    print $OutputFileHandler '--'.('=' x 76)."\n";
   }

  #����� ���� �������
  print $OutputFileHandler $OutStr;
 }
#----------------------------------------------------------------------------

#main

if ($#ARGV != 2)
 {
  print '�������� ������� :'."\n";
  print "\n";
  print 'SourceFileName ScriptDropFileName ScriptCreateFileName'."\n";
  print "\n";
  print 'SourceFileName         - ���� ����������� PowerDesigner (������ �� ��������)'."\n";
  print '                         ���� ������ � ��������� �� ��������'."\n";
  print 'ScriptDropFileName     - ��� ����� ������� ����� ��������� ������� ��'."\n";
  print '                         �������� ���� ������'."\n";
  print 'ScriptCreateFileName   - ��� ����� ������� ����� ��������� ������� ��'."\n";
  print '                         ������� ���� ������'."\n";
  die (1);
 }
else
 {
  open(SourceFileHandler,"$ARGV[0]")  or die  "������ �������� ����� : $ARGV[0]";
  open(DropFileHandler,">$ARGV[1]") or die  "������ �������� ����� : $ARGV[1]";
  open(CreateFileHandler,">$ARGV[2]") or die "������ �������� ����� : $ARGV[2]";


  FileHeaderOut(*DropFileHandler);
  FileHeaderOut(*CreateFileHandler);

  my $BufferStr;
  my @FileCreateItem;
  my @FileDropItem;
  my $InStr;
  my $OutStr;

  $BufferStr = "";
  $InStr     = "";
  $OutStr    = "";

  while($InStr = <SourceFileHandler>)
   {
    #���������� ���� �� ������������ ���������� � ������
    $InStr =~ s/(\w*)(--.*)/$1/;

    #���������� � ����� �� ����������� ;
    $BufferStr = $BufferStr.$InStr;

    while (($BufferStr !~ /;/) && !(eof))
     {
      $InStr=<SourceFileHandler>;
      #���������� ���� �� ������������ ���������� � ������
      $InStr =~ s/(\w*)(--.*)/$1/;
      $BufferStr = $BufferStr.$InStr;
     }

    $OutStr = $BufferStr;
    $OutStr =~ s/(.*;)(.*)/$1/is;

    #������� ������ ;
    $BufferStr =~ s/(.*)(;)(.*)/$3/s;

    #������ ������ � ������ �������
    $OutStr =~ s/(\n*)(\w+)/$2/i;

    if ($OutStr =~ /drop/)
     {
      $OutStr = $OutStr."\n";
      push(@FileDropItem,$OutStr);
     }
    else
     {
      $OutStr =~ s/(")//g;
      $OutStr = $OutStr."\n";
      FileTableOut(*CreateFileHandler,$OutStr);
      push(@FileCreateItem,$OutStr);
     }
   }

  print DropFileHandler @FileDropItem;
  #print CreateFileHandler @FileCreateItem;

  close(CreateFileHandler) or die "������ �������� ����� : $ARGV[2]";
  close(DropFileHandler) or die "������ �������� ����� : $ARGV[1]";
  close(SourceFileHandler) or die "������ �������� ����� : $ARGV[0]";
  exit(0);
 }
#----------------------------------------------------------------------------
__END__

