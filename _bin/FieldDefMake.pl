#! perl
# Парамертры запуска :
# CreateDb.SQL FieldDef.h
# CreateDb.SQL - файл содержащий скрипты на создание ДБ
# FieldDef.h   - имя файл в котором будут хранится имена поле данной ДБ

use File::Basename;


#-----------------------------------------------------------------------------
# создает строку по шаблону : char Table1TableNameStr[] = "Table1";
# и выводит ее в указаный поток
#-----------------------------------------------------------------------------
sub CppFileTableNameOut(\*$$)
 {
  my $OutputFileHandler = $_[0];
  my $TableNameStr = $_[1];
  my $ValuePosition = $_[2];

  my $OutStr;

  $OutStr = $TableNameStr;

  #Перевод регистров nn_mm =>NnMm

  $OutStr =~ s/^(.)/\U$1/;
  $OutStr =~ s/_(.)/\U$1/g;

  #формирование строки вывода
  $OutStr = 'char '.$OutStr.'TableNameStr[] =';

  #отстуи перед занчением
  $OutStr = $OutStr.' ' x ($ValuePosition - length($OutStr));

  #значение
  $OutStr = $OutStr."\"$TableNameStr\";";

  print $OutputFileHandler $OutStr."\n";
 }
#-----------------------------------------------------------------------------
# создает строку по шаблону : extern char Table1TableNameStr[];
# и выводит ее в указаный поток
#-----------------------------------------------------------------------------
sub HeaderFileTableNameOut(\*$)
 {
  my $OutputFileHandler = $_[0];
  my $TableNameStr = $_[1];

  my $OutStr;

  $OutStr = $TableNameStr;

  #Перевод регистров nn_mm =>NnMm

  $OutStr =~ s/^(.)/\U$1/;
  $OutStr =~ s/_(.)/\U$1/g;

  #формирование строки вывода
  $OutStr = 'extern char '.$OutStr.'TableNameStr[];';

  print $OutputFileHandler $OutStr."\n";
 }
#-----------------------------------------------------------------------------
#main

 if ($#ARGV != 1)
  {
   print  "\nПарамертры запуска : \n";
   print  " CreateDb.SQL FieldDef.h \n";
   print  " CreateDb.SQL - файл содержащий скрипты на создание ДБ \n";
   print  " FieldDef.h   - файл в котором будут хранится имена поле данной ДБ \n";
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

  open(IN,"$ARGV[0]")  or die "Ошибка открытия файла : $ARGV[0]";

  while($InStr = <IN>)
   {
    chomp($InStr);

    #коментарий если он присутствует выкидываем в никуда
    $InStr =~ s/(\w*)(--.*)/$1/;

    #вычитываем в буфер до закрывающей ;
    $BufferStr = $BufferStr.$InStr;

    if ($BufferStr =~ /create table/)
     {
      $BufferStr =~ s/(.*)(create table)(.*)/$3/i;

      #имя таблицы
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

        #остаток полсле ;
        $BufferStr =~ s/(.*)(;)(.*)/$3/i;

        #FieldsName

        # отсреливаем первую "(" после имени таблицы
        # ExpresionStr - содержит строку с описаниями полей
        $ExpresionStr    =~ s/\x28(.*)/$1/i;

        while (length($ExpresionStr) != 0 && $ExpresionStr !~ /^;\x20*/)
         {
          $ExpresionStr =~ s/(.*?)(\w*)/$2/;

          if ($ExpresionStr =~ /^primary key/)
           {
            #Удаляем primary key
            $ExpresionStr =~ s/(^primary key.*?\x29)(.*)/$2/;
           }
          else
           {
            if ($ExpresionStr =~ /^constraint/)
             {
              #Удаляем constraint
              $ExpresionStr =~ s/(^constraint \w+ )(.*)/$2/;
             }
            else
             {
              push(@FieldsName,$ExpresionStr =~ /(\w+)/);
             }
           }

          # обьявление типа с (10,0) заменяем па пустоту из-за запятой
          # cчитем что после , следует имя поля
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

  close(IN) or die "Ошибка закрытия файла : $ARGV[0]";


  # Вывод разпрарсенной инфы в файл
  my $OutStr;
  my $PathStr;
  my $CppOutFileNameStr;
  my $HeaderOutFileNameStr;

  # Имена выходных файлов
  $CppOutFileNameStr = $ARGV[1];
  $PathStr = dirname($CppOutFileNameStr);
  $CppOutFileNameStr = basename($CppOutFileNameStr,".");

  # обрезка расширения
  $CppOutFileNameStr =~ s/(\..*)//g;

  $HeaderOutFileNameStr = $CppOutFileNameStr;

  $HeaderOutFileNameStr = $PathStr . "\\" . $HeaderOutFileNameStr . '.' . $HeaderOutFileExtentionStr;
  $CppOutFileNameStr    = $PathStr . "\\" . $CppOutFileNameStr    . '.' . $CppOutFileExtentionStr;


  open(HeaderOutFileHadler,">$HeaderOutFileNameStr") or die "Ошибка создания файла : $HeaderOutFileNameStr";
  open(CppOutFileHadler,">$CppOutFileNameStr") or die "Ошибка создания файла : $CppOutFileNameStr";

  # формирование define в header файл
  # #ifndef FieldDefH
  # #define FieldDefH

  $OutStr = basename($HeaderOutFileNameStr,".");

  $OutStr =~ s/(\..*)//g;

  print HeaderOutFileHadler '#ifndef '.$OutStr.'H'."\n";
  print HeaderOutFileHadler '#define '.$OutStr.'H'."\n";


  # в С файл строку #include
  print CppOutFileHadler "\n".'#include <';
  print CppOutFileHadler basename($HeaderOutFileNameStr,".");
  print CppOutFileHadler " >\n";


  # имена талиц

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

  # имена полей

  # section delimeter
  print HeaderOutFileHadler ('/' x 78)."\n";
  print HeaderOutFileHadler '//FieldsName'."\n"."\n";

  print CppOutFileHadler ('/' x 78)."\n";
  print CppOutFileHadler '//FieldsName'."\n"."\n";
  print HeaderOutFileHadler "\n".."\n"."\n";

  my %FieldsNameUnique;
  my $FieldName;

  #Уникальность полей
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
    #формирование строки вывода для заголовочного файла
    $OutStr = $FieldsNameUnique{$FieldName};
    $OutStr = 'char '.$OutStr.'FieldNameStr[] =';

    #отступ перед значением
    $OutStr = $OutStr.' ' x ($ValuePosition - length($OutStr));

    #значение
    $OutStr = $OutStr."\"$FieldName\";";

    print CppOutFileHadler $OutStr."\n";

    #формирование строки вывода для H файла
    $OutStr = $FieldsNameUnique{$FieldName};
    $OutStr = 'extern char '.$OutStr.'FieldNameStr[];';

    print HeaderOutFileHadler $OutStr."\n";
   }


  # section delimeter for headers
  print HeaderOutFileHadler "\n";
  print HeaderOutFileHadler '/' x 78;
  print HeaderOutFileHadler "\n";

  print HeaderOutFileHadler '#endif'."\n";

  close(HeaderOutFileHadler) or die "Ошибка закрытия файла : $HeaderOutFileNameStr";
  close(CppOutFileHadler) or die "Ошибка закрытия файла : $CppOutFileNameStr";
 }

__END__



