# Праметры запуска :
# SourceFileName ScriptDropFileName ScriptCreateFileName
#
# SourceFileName         - файл сгенеренный PowerDesigner (скрипт на создание)
#                           базы данных с скриптами на удаление
# ScriptDropFileName     - имя файла который будет содержать скрипты на
#                           удаление базы данных
# ScriptCreateFileName   - имя файла который будет содержать скрипты на
#                           создние баззы данных
#


use POSIX;
#----------------------------------------------------------------------------
sub FileHeaderOut(\*)
 {
  my($OutputFileHandler) = @_;

  print $OutputFileHandler '--'.('=' x 76)."\n";
  print $OutputFileHandler "-- \n";
  print $OutputFileHandler '-- создан: ';
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

    #символы перевода каретки
    $TableNameStr =~ s/(\s)//g;

    #вывод комментария с именем создаваемой таблицы
    print $OutputFileHandler '--'.('=' x 76)."\n";
    print $OutputFileHandler '-- Table : '.$TableNameStr."\n";
    print $OutputFileHandler '--'.('=' x 76)."\n";
   }

  #вывод тела скрипта
  print $OutputFileHandler $OutStr;
 }
#----------------------------------------------------------------------------

#main

if ($#ARGV != 2)
 {
  print 'Праметры запуска :'."\n";
  print "\n";
  print 'SourceFileName ScriptDropFileName ScriptCreateFileName'."\n";
  print "\n";
  print 'SourceFileName         - файл сгенеренный PowerDesigner (скрипт на создание)'."\n";
  print '                         базы данных с скриптами на удаление'."\n";
  print 'ScriptDropFileName     - имя файла который будет содержать скрипты на'."\n";
  print '                         удаление базы данных'."\n";
  print 'ScriptCreateFileName   - имя файла который будет содержать скрипты на'."\n";
  print '                         создние базы данных'."\n";
  die (1);
 }
else
 {
  open(SourceFileHandler,"$ARGV[0]")  or die  "Ошибка открытия файла : $ARGV[0]";
  open(DropFileHandler,">$ARGV[1]") or die  "Ошибка создания файла : $ARGV[1]";
  open(CreateFileHandler,">$ARGV[2]") or die "Ошибка создания файла : $ARGV[2]";


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
    #коментарий если он присутствует выкидываем в никуда
    $InStr =~ s/(\w*)(--.*)/$1/;

    #вычитываем в буфер до закрывающей ;
    $BufferStr = $BufferStr.$InStr;

    while (($BufferStr !~ /;/) && !(eof))
     {
      $InStr=<SourceFileHandler>;
      #коментарий если он присутствует выкидываем в никуда
      $InStr =~ s/(\w*)(--.*)/$1/;
      $BufferStr = $BufferStr.$InStr;
     }

    $OutStr = $BufferStr;
    $OutStr =~ s/(.*;)(.*)/$1/is;

    #остаток полсле ;
    $BufferStr =~ s/(.*)(;)(.*)/$3/s;

    #пустые строки в начале скрипта
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

  close(CreateFileHandler) or die "Ошибка закрытия файла : $ARGV[2]";
  close(DropFileHandler) or die "Ошибка закрытия файла : $ARGV[1]";
  close(SourceFileHandler) or die "Ошибка закрытия файла : $ARGV[0]";
  exit(0);
 }
#----------------------------------------------------------------------------
__END__

