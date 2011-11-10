#! perl
# ��ࠬ����� ����᪠ :
# CreateDb.SQL FieldDef.h
# CreateDb.SQL - 䠩� ᮤ�ঠ騩 �ਯ�� �� ᮧ����� ��
# FieldDef.h   - ��� 䠩� � ���஬ ���� �࠭���� ����� ���� ������ ��

use File::Basename;


#-----------------------------------------------------------------------------
# ᮧ���� ��ப� �� 蠡���� : char Table1TableNameStr[] = "Table1";
# � �뢮��� �� � 㪠���� ��⮪
#-----------------------------------------------------------------------------
sub CppFileTableNameOut(\*$$)
 {
  my $OutputFileHandler = $_[0];
  my $TableNameStr = $_[1];
  my $ValuePosition = $_[2];

  my $OutStr;

  $OutStr = $TableNameStr;

  #��ॢ�� ॣ���஢ nn_mm =>NnMm

  $OutStr =~ s/^(.)/\U$1/;
  $OutStr =~ s/_(.)/\U$1/g;

  #�ନ஢���� ��ப� �뢮��
  $OutStr = 'char '.$OutStr.'TableNameStr[] =';

  #����� ��। ���祭���
  $OutStr = $OutStr.' ' x ($ValuePosition - length($OutStr));

  #���祭��
  $OutStr = $OutStr."\"$TableNameStr\";";

  print $OutputFileHandler $OutStr."\n";
 }
#-----------------------------------------------------------------------------
# ᮧ���� ��ப� �� 蠡���� : extern char Table1TableNameStr[];
# � �뢮��� �� � 㪠���� ��⮪
#-----------------------------------------------------------------------------
sub HeaderFileTableNameOut(\*$)
 {
  my $OutputFileHandler = $_[0];
  my $TableNameStr = $_[1];

  my $OutStr;

  $OutStr = $TableNameStr;

  #��ॢ�� ॣ���஢ nn_mm =>NnMm

  $OutStr =~ s/^(.)/\U$1/;
  $OutStr =~ s/_(.)/\U$1/g;

  #�ନ஢���� ��ப� �뢮��
  $OutStr = 'extern char '.$OutStr.'TableNameStr[];';

  print $OutputFileHandler $OutStr."\n";
 }
#-----------------------------------------------------------------------------
#main

 if ($#ARGV != 1)
  {
   print  "\n��ࠬ����� ����᪠ : \n";
   print  " CreateDb.SQL FieldDef.h \n";
   print  " CreateDb.SQL - 䠩� ᮤ�ঠ騩 �ਯ�� �� ᮧ����� �� \n";
   print  " FieldDef.h   - 䠩� � ���஬ ���� �࠭���� ����� ���� ������ �� \n";
   die(1);
  }
 else
 {
  #const
  my $ValuePosition  = 50;
  my $HeaderOutFileExtentionStr = 'h';
  my $CppOutFileExtentionStr    = 'cpp';


  my $BufferStr = '';
  my @TablesName;
  my @FieldsName;

  open(IN,"$ARGV[0]")  or die "�訡�� ������ 䠩�� : $ARGV[0]";

  while($InStr = <IN>)
   {
    chomp($InStr);

    #������਩ �᫨ �� ��������� �모�뢠�� � ���㤠
    $InStr =~ s/(\w*)(--.*)/$1/;

    #����뢠�� � ���� �� ����뢠�饩 ;
    $BufferStr = $BufferStr.$InStr;

    if ($BufferStr =~ /create table/)
     {
      $BufferStr =~ s/(.*)(create table)(.*)/$3/i;

      #��� ⠡����
      if ($BufferStr =~ /(\w+)/)
       {
        push(@TablesName,$BufferStr =~ /(\w+)/);

        $BufferStr =~ s/(\w+)(.*)/$2/;

        while (($BufferStr !~ /\;/) && !(eof))
         {
          $InStr=<IN>;
          chomp($InStr);
          $BufferStr = $BufferStr.$InStr;
         }

        $ExpresionStr    = $BufferStr;

        $ExpresionStr    =~ s/(.*)(;)(.*)/$1$2/i;

        #���⮪ ���᫥ ;
        $BufferStr =~ s/(.*)(;)(.*)/$3/i;

        #FieldsName

        # ���५����� ����� "(" ��᫥ ����� ⠡����
        # ExpresionStr - ᮤ�ন� ��ப� � ���ᠭ�ﬨ �����
        $ExpresionStr    =~ s/\x28(.*)/$1/i;

        while (length($ExpresionStr) != 0 && $ExpresionStr !~ /^;\x20*/)
         {
          $ExpresionStr =~ s/(.*?)(\w*)/$2/;

          if ($ExpresionStr =~ /^primary key/)
           {
            #����塞 primary key
            $ExpresionStr =~ s/(^primary key.*?\x29)(.*)/$2/;
           }
          else
           {
            if ($ExpresionStr =~ /^constraint/)
             {
              #����塞 constraint
              $ExpresionStr =~ s/(^constraint \w+ )(.*)/$2/;
             }
            else
             {
              push(@FieldsName,$ExpresionStr =~ /(\w+)/);
             }
           }

          # ������� ⨯� � (10,0) �����塞 �� ������ ��-�� ����⮩
          # c�⥬ �� ��᫥ , ᫥��� ��� ����
          #             type       (     1 , 1    )
          $ExpresionStr =~ s/[a-zA-Z]+ *\x28 *\d+,\d* *\x29//gi;

          if ($ExpresionStr =~ /,/)
           {
            $ExpresionStr =~ s/(.*?),(.*)/$2/;
           }
          else
           {
            $ExpresionStr =~ s/(.*)(;)/$2/;
           }
         }

       }
     }
   }

  close(IN) or die "�訡�� ������� 䠩�� : $ARGV[0]";


  # �뢮� ࠧ���ᥭ��� ���� � 䠩�
  my $OutStr;
  my $PathStr;
  my $CppOutFileNameStr;
  my $HeaderOutFileNameStr;

  # ����� ��室��� 䠩���
  $CppOutFileNameStr = $ARGV[1];
  $PathStr = dirname($CppOutFileNameStr);
  $CppOutFileNameStr = basename($CppOutFileNameStr,".");

  # ��१�� ���७��
  $CppOutFileNameStr =~ s/(\..*)//g;

  $HeaderOutFileNameStr = $CppOutFileNameStr;

  $HeaderOutFileNameStr = $PathStr . "\\" . $HeaderOutFileNameStr . '.' . $HeaderOutFileExtentionStr;
  $CppOutFileNameStr    = $PathStr . "\\" . $CppOutFileNameStr    . '.' . $CppOutFileExtentionStr;


  open(HeaderOutFileHadler,">$HeaderOutFileNameStr") or die "�訡�� ᮧ����� 䠩�� : $HeaderOutFileNameStr";
  open(CppOutFileHadler,">$CppOutFileNameStr") or die "�訡�� ᮧ����� 䠩�� : $CppOutFileNameStr";

  # �ନ஢���� define � header 䠩�
  # #ifndef FieldDefH
  # #define FieldDefH

  $OutStr = basename($HeaderOutFileNameStr,".");

  $OutStr =~ s/(\..*)//g;

  print HeaderOutFileHadler '#ifndef '.$OutStr.'H'."\n";
  print HeaderOutFileHadler '#define '.$OutStr.'H'."\n";


  # � � 䠩� ��ப� #include
  print CppOutFileHadler "\n".'#include <';
  print CppOutFileHadler basename($HeaderOutFileNameStr,".");
  print CppOutFileHadler " >\n";


  # ����� ⠫��

  # File section delimeter
  print HeaderOutFileHadler ('/' x 78)."\n";
  print HeaderOutFileHadler '//TablesName'."\n"."\n";

  print CppOutFileHadler ('/' x 78)."\n";
  print CppOutFileHadler '//TablesName'."\n"."\n";

  foreach $TablesName (@TablesName)
   {
    HeaderFileTableNameOut(*HeaderOutFileHadler,$TablesName);
    CppFileTableNameOut   (*CppOutFileHadler,$TablesName,$ValuePosition);
   }

  # ����� �����

  # section delimeter
  print HeaderOutFileHadler ('/' x 78)."\n";
  print HeaderOutFileHadler '//FieldsName'."\n"."\n";

  print CppOutFileHadler ('/' x 78)."\n";
  print CppOutFileHadler '//FieldsName'."\n"."\n";
  print HeaderOutFileHadler "\n".."\n"."\n";

  my %FieldsNameUnique;
  my $FieldName;

  #������쭮��� �����
  foreach $FieldsName (@FieldsName)
   {
    $FieldName = $FieldsName;

    $FieldName =~ s/^(.+)/\L$1/;

    $FieldsName =~ s/^(.)/\U$1/;
    $FieldsName =~ s/_(.)/\U$1/g;

    $FieldsNameUnique{$FieldName} = $FieldsName;
   }

  foreach $FieldName (sort keys %FieldsNameUnique)
   {
    #�ନ஢���� ��ப� �뢮�� ��� ��������筮�� 䠩��
    $OutStr = $FieldsNameUnique{$FieldName};
    $OutStr = 'char '.$OutStr.'FieldNameStr[] =';

    #����� ��। ���祭���
    $OutStr = $OutStr.' ' x ($ValuePosition - length($OutStr));

    #���祭��
    $OutStr = $OutStr."\"$FieldName\";";

    print CppOutFileHadler $OutStr."\n";

    #�ନ஢���� ��ப� �뢮�� ��� H 䠩��
    $OutStr = $FieldsNameUnique{$FieldName};
    $OutStr = 'extern char '.$OutStr.'FieldNameStr[];';

    print HeaderOutFileHadler $OutStr."\n";
   }


  # section delimeter for headers
  print HeaderOutFileHadler "\n";
  print HeaderOutFileHadler '/' x 78;
  print HeaderOutFileHadler "\n";

  print HeaderOutFileHadler '#endif'."\n";

  close(HeaderOutFileHadler) or die "�訡�� ������� 䠩�� : $HeaderOutFileNameStr";
  close(CppOutFileHadler) or die "�訡�� ������� 䠩�� : $CppOutFileNameStr";
 }

__END__



