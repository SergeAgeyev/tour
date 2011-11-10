#include "TourConst.h"
#include "FieldDef.h"
#include "TourTool.h"
#include "MessageModuleForm.h"
#include "ErrorMessageDialogForm.h"

#if !defined(TOUR_DEMO_MODE)

  #include "DataModuleForm.h"

#endif

#include <direct.h>
#include <io.h>
#include "PathMasterProcessForm.h"

#define  GetTranslatedStr(Index)  TourMessageModule->VStringStorage->Lines->Strings[Index]
#define  TourToolNULLStr          "NULL"

//---------------------------------------------------------------------------
TDateTime          TourLocalDateTime   (void)
 {
  return(TDateTime::CurrentDateTime());
 }

//---------------------------------------------------------------------------
void               TourShowDialogExceptionStr
                   (AnsiString                       *ErrorMessageStrPtr,
                    AnsiString                       *ExceptionStrPtr)
 {
  TTourErrorMessageDialogForm         *ErrorDlg;

  try
   {
    Application->CreateForm(__classid(TTourErrorMessageDialogForm),
                            &ErrorDlg);

    if (ErrorDlg != NULL)
     {
      ErrorDlg->Caption = Application->Title;

      if (ErrorMessageStrPtr != NULL)
       {
        ErrorDlg->ErrorMessageLabel->Caption = *ErrorMessageStrPtr;
       }

      if (ExceptionStrPtr != NULL)
       {
        ErrorDlg->DetailsMemo->Lines->Text = *ExceptionStrPtr;
       }
      else
       {
        ErrorDlg->DetailsButton->Visible = false;
       }

      ErrorDlg->ShowModal();

      delete (ErrorDlg);
      ErrorDlg = NULL;
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogError(exception.Message.c_str());
   }
 }

//---------------------------------------------------------------------------

void               TourShowDialogException
                   (AnsiString                       *ErrorMessageStrPtr,
                    Exception                        *ExceptionPtr)
 {
  if (ExceptionPtr != NULL)
   {
    AnsiString                         ExceptionInfoStr;

    ExceptionInfoStr  = AnsiString("ClassName : ");
    ExceptionInfoStr += AnsiString(ExceptionPtr->ClassName());
    ExceptionInfoStr += AnsiString("\n");
    ExceptionInfoStr += AnsiString("Message   : ");
    ExceptionInfoStr += ExceptionPtr->Message;

    TourShowDialogExceptionStr(ErrorMessageStrPtr,&ExceptionInfoStr);
   }
  else
   {
    TourShowDialogExceptionStr(ErrorMessageStrPtr,NULL);
   }
 }

//---------------------------------------------------------------------------

#if !defined(TOUR_DEMO_MODE)

// Функция проверки существования записи в таблице
bool               TourCheckRecordExist
                   (AnsiString                        TableNameStr,
                    TStringList                      *KeyFieldListPtr,
                    TStringList                      *KeyValueListPtr)
 {
  TADOQuery                           *QueryPtr;
  AnsiString                           SQLStr;
  bool                                 ResultFlag;
  int                                  ListIndex;

  ResultFlag = false;

  try
   {
    if ((KeyFieldListPtr->Count != KeyValueListPtr->Count) ||
        (KeyFieldListPtr == NULL) ||
        (KeyValueListPtr == NULL) ||
        TableNameStr.IsEmpty())
     {
      Exception(GetTranslatedStr(TourMessageModuleIncorrectFuncArgsErrorMessageStr));
     }

    SQLStr  = "SELECT ";

    for (ListIndex = 0; ListIndex < KeyFieldListPtr->Count;ListIndex++)
     {
      SQLStr += KeyFieldListPtr->Strings[ListIndex];

      if (ListIndex < KeyFieldListPtr->Count - 1)
       {
        SQLStr += ",";
       }
     }

    SQLStr += (" FROM " + TableNameStr + " WHERE ");

    for (ListIndex = 0; ListIndex < KeyValueListPtr->Count;ListIndex++)
     {
      SQLStr += (" ( " + KeyFieldListPtr->Strings[ListIndex]);
      SQLStr += " = ";
      SQLStr += (KeyValueListPtr->Strings[ListIndex] + " ) ");

      if (ListIndex < KeyFieldListPtr->Count - 1)
       {
        SQLStr += " AND ";
       }
     }

    QueryPtr = new TADOQuery(NULL);

    if (QueryPtr != NULL)
     {
      QueryPtr->SQL->Text = SQLStr;
      QueryPtr->Connection = TourDataModule->TourDataBaseConnection;

      QueryPtr->Open();

      if (!QueryPtr->IsEmpty())
       {
        ResultFlag = true;
       }

      QueryPtr->Close();

      delete (QueryPtr);
      QueryPtr = NULL;
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  return (ResultFlag);
 }

//---------------------------------------------------------------------------

bool               TourCheckTripExist
                   (AnsiString                        TripIdStr)
 {
  bool                                 ResultFlag;
  TStringList                         *KeyListPtr;
  TStringList                         *ValueListPtr;

  ResultFlag = false;
  KeyListPtr = new TStringList();

  if (KeyListPtr != NULL)
   {
    KeyListPtr->Text = TripIdFieldNameStr;

    ValueListPtr = new TStringList();

    if (ValueListPtr != NULL)
     {
      ValueListPtr->Text = TripIdStr;

      ResultFlag = TourCheckRecordExist(TripTableNameStr,KeyListPtr,ValueListPtr);

      delete (ValueListPtr);
      ValueListPtr = NULL;
     }

    delete (KeyListPtr);
    KeyListPtr = NULL;
   }

  return (ResultFlag);
 }

#endif

//---------------------------------------------------------------------------

AnsiString __fastcall TourDefaultIniNameStr(void)
 {
  AnsiString                 IniFileNameStr;
  AnsiString                 PathStr;
  char                       TmpPathStr[MAXPATH]; // for run from CD-ROM

  GetTempPath(sizeof(TmpPathStr),TmpPathStr);
  PathStr  = IncludeTrailingBackslash(TmpPathStr) + "Tour";
/*
  PathStr  = IncludeTrailingBackslash(ExtractFileDir(Application->ExeName));
  PathStr += "Desktop";
*/

  if (access(PathStr.c_str(),0) != 0)
   {
    mkdir(PathStr.c_str());
   }

  IniFileNameStr  = IncludeTrailingBackslash(PathStr);

  #if !defined(TOUR_DEMO_MODE)
   {
    IniFileNameStr += TourDataModule->CurrentClerkIdStr;
   }
  #else
   {
    IniFileNameStr += "TourDemo";
   }
  #endif

  IniFileNameStr += ".ini";

  return (IniFileNameStr);
 }

//---------------------------------------------------------------------------
#if !defined(TOUR_DEMO_MODE)

// Функция проверки существования марки автобуса в таблице bus
bool               TourCheckBusExist
                   (AnsiString                        BusModelStr)
 {
  bool                                 ResultFlag;
  TStringList                         *KeyListPtr;
  TStringList                         *ValueListPtr;

  ResultFlag = false;
  KeyListPtr = new TStringList();

  if (KeyListPtr != NULL)
   {
    KeyListPtr->Text = "bus_model";

    ValueListPtr = new TStringList();

    if (ValueListPtr != NULL)
     {
      ValueListPtr->Text = QuotedStr(BusModelStr);

      ResultFlag = TourCheckRecordExist("bus",KeyListPtr,ValueListPtr);

      delete (ValueListPtr);
      ValueListPtr = NULL;
     }

    delete (KeyListPtr);
    KeyListPtr = NULL;
   }

  return (ResultFlag);
 }

//---------------------------------------------------------------------------
// Функция проверки существования региона в таблице region
bool               TourCheckRegionExist
                   (AnsiString                        RegionIdStr)
 {
  bool                                 ResultFlag;
  TStringList                         *KeyListPtr;
  TStringList                         *ValueListPtr;

  ResultFlag = false;
  KeyListPtr = new TStringList();

  if (KeyListPtr != NULL)
   {
    KeyListPtr->Text = "region_id";

    ValueListPtr = new TStringList();

    if (ValueListPtr != NULL)
     {
      ValueListPtr->Text = QuotedStr(RegionIdStr);

      ResultFlag = TourCheckRecordExist("region",KeyListPtr,ValueListPtr);

      delete (ValueListPtr);
      ValueListPtr = NULL;
     }

    delete (KeyListPtr);
    KeyListPtr = NULL;
   }

  return (ResultFlag);
 }

//---------------------------------------------------------------------------

bool               TourCheckCityExist
                   (AnsiString                        CityZIPStr)
 {
  bool                                 ResultFlag;
  TStringList                         *KeyListPtr;
  TStringList                         *ValueListPtr;

  ResultFlag = false;
  KeyListPtr = new TStringList();

  if (KeyListPtr != NULL)
   {
    KeyListPtr->Text = CityZIPFieldNameStr;

    ValueListPtr = new TStringList();

    if (ValueListPtr != NULL)
     {
      ValueListPtr->Text = QuotedStr(CityZIPStr);

      ResultFlag = TourCheckRecordExist(CityTableNameStr,KeyListPtr,ValueListPtr);

      delete (ValueListPtr);
      ValueListPtr = NULL;
     }

    delete (KeyListPtr);
    KeyListPtr = NULL;
   }

  return (ResultFlag);
 }

//---------------------------------------------------------------------------

bool               TourCheckStopExist
                   (AnsiString                        StopIdStr)
 {
  bool                                 ResultFlag;
  TStringList                         *KeyListPtr;
  TStringList                         *ValueListPtr;

  ResultFlag = false;
  KeyListPtr = new TStringList();

  if (KeyListPtr != NULL)
   {
    KeyListPtr->Text = StopIdFieldNameStr;

    ValueListPtr = new TStringList();

    if (ValueListPtr != NULL)
     {
      ValueListPtr->Text = QuotedStr(StopIdStr);

      ResultFlag = TourCheckRecordExist(StopTableNameStr,KeyListPtr,ValueListPtr);

      delete (ValueListPtr);
      ValueListPtr = NULL;
     }

    delete (KeyListPtr);
    KeyListPtr = NULL;
   }

  return (ResultFlag);
 }

// Функция проверки существования модели ост.пункта в таблице stopmodel
bool               TourCheckStopModelExist
                   (AnsiString                        StopModelStr)
 {
  bool                                 ResultFlag;
  TStringList                         *KeyListPtr;
  TStringList                         *ValueListPtr;

  ResultFlag = false;
  KeyListPtr = new TStringList();

  if (KeyListPtr != NULL)
   {
    KeyListPtr->Text = "stop_model";

    ValueListPtr = new TStringList();

    if (ValueListPtr != NULL)
     {
      ValueListPtr->Text = QuotedStr(StopModelStr);

      ResultFlag = TourCheckRecordExist("stopmodel",KeyListPtr,ValueListPtr);

      delete (ValueListPtr);
      ValueListPtr = NULL;
     }

    delete (KeyListPtr);
    KeyListPtr = NULL;
   }

  return (ResultFlag);
 }

//---------------------------------------------------------------------------

// Функция проверки существования владельца ост.пункта в таблице stopowner
bool               TourCheckStopOwnerExist
                   (AnsiString                        StopOwnerStr)
 {
  bool                                 ResultFlag;
  TStringList                         *KeyListPtr;
  TStringList                         *ValueListPtr;

  ResultFlag = false;
  KeyListPtr = new TStringList();

  if (KeyListPtr != NULL)
   {
    KeyListPtr->Text = "stopowner_id";

    ValueListPtr = new TStringList();

    if (ValueListPtr != NULL)
     {
      ValueListPtr->Text = QuotedStr(StopOwnerStr);

      ResultFlag = TourCheckRecordExist("stopowner",KeyListPtr,ValueListPtr);

      delete (ValueListPtr);
      ValueListPtr = NULL;
     }

    delete (KeyListPtr);
    KeyListPtr = NULL;
   }

  return (ResultFlag);
 }

//---------------------------------------------------------------------------

// Функция проверки существования владельца рейса в таблице tripowner
bool               TourCheckTripOwnerExist
                   (AnsiString                        TripOwnerStr)
 {
  bool                                 ResultFlag;
  TStringList                         *KeyListPtr;
  TStringList                         *ValueListPtr;

  ResultFlag = false;
  KeyListPtr = new TStringList();

  if (KeyListPtr != NULL)
   {
    KeyListPtr->Text = "tripowner_id";

    ValueListPtr = new TStringList();

    if (ValueListPtr != NULL)
     {
      ValueListPtr->Text = QuotedStr(TripOwnerStr);

      ResultFlag = TourCheckRecordExist("tripowner",KeyListPtr,ValueListPtr);

      delete (ValueListPtr);
      ValueListPtr = NULL;
     }

    delete (KeyListPtr);
    KeyListPtr = NULL;
   }

  return (ResultFlag);
 }

#endif
//---------------------------------------------------------------------------

bool               TourGetCommandLineParameter
                   (AnsiString                       *DataSourceNameStrPtr,
                    bool                             *DataBaseEditModeFlagPtr)
//                    bool                             *ShowHelpFlagPtr)

 {
  /* Scan Argument parametrs */

  AnsiString                           ArgumentStr;
  AnsiString                           OptionTextStr;
  char                                 OptionChar;
  unsigned int                         ArgumentLength;
  unsigned int                         Index;
  unsigned int                         Limit;
  unsigned int                         ParameterIndex;
  bool                                 ResultFlag;

  /*  Init parameter by default value */

  *DataSourceNameStrPtr    = "";
  *DataBaseEditModeFlagPtr = false;
//  *ShowHelpFlagPtr         = false;

  /* Init Cycle */

  ResultFlag = true;
  Index      = 1;
  Limit      = ParamCount();

  ParameterIndex = 0;

  while ((Index <= Limit) && (ResultFlag))
   {
    ResultFlag = false;

    ArgumentStr    = ParamStr(Index);
    ArgumentLength = ArgumentStr.Length();

    if (ArgumentLength <= 0)
     {

      /* Skip void Argument */

      ResultFlag = true;
     }
    else
     {
      switch(ArgumentStr[1])
       {
        case ('-') :
        case ('/') :
         {
          /* Option */
          if (ArgumentLength <= 1)
           {
            /* Just Option Char with out any option - skip it */
            ResultFlag = true; /* As Success */
           }
          else
           {
            OptionChar = UpCase(ArgumentStr[2]);

            if (ArgumentLength <= 2)
             {
              /* Just option Char suppled */
              OptionTextStr = "";
             }
            else
             {
              OptionTextStr = ArgumentStr.SubString(2,ArgumentLength - 1);
             }

            /* Parse Option */

            switch (OptionChar)
             {
/*
              case ('H') :
              case ('?') :
               {
                *ShowHelpFlagPtr = true;
                 ResultFlag = true;
               } break;
*/
              case ('E') :
               {
                if (OptionTextStr.UpperCase() == "EDITBASE")
                 {
                  *DataBaseEditModeFlagPtr = true;
                  ResultFlag = true;
                 }
               } break;

              default :
               {
               }
             }
           }
         } break;

        default    :
         {
          switch (ParameterIndex)
           {
            case (0)    :
             {
              *DataSourceNameStrPtr = ArgumentStr;
              ResultFlag = true;
             } break;

            default :
             {
              /* Skip unneeded parameter */
             }
           }

          /* Increment parameter Index */

          ParameterIndex++;
         }
       }
     }

    Index++;
   }

  return (ResultFlag);
 }

//---------------------------------------------------------------------------
AnsiString         TourTimeStrByDateTime
                   (TDateTime                         DateTimeVar)
 {
  unsigned short                       HourValue;
  unsigned short                       MinValue;
  unsigned short                       SecValue;
  unsigned short                       MSecValue;
  AnsiString                           HourValueStr;
  AnsiString                           MinValueStr;
  AnsiString                           TimeStr;

  HourValue = 0;
  MinValue  = 0;
  SecValue  = 0;
  MSecValue = 0;
  HourValueStr = "";
  MinValueStr  = "";
  TimeStr      = "";

  DateTimeVar.DecodeTime(&HourValue,&MinValue,&SecValue,&MSecValue);

//  HourValueStr = IntToStr(HourValue);
//  MinValueStr  = IntToStr(MinValue);

  TimeStr.printf("%02u:%02u",HourValue,MinValue);
/*
  if (HourValue < 10)
   {
    HourValueStr = "0" + HourValueStr;
   }
  if (MinValue < 10)
   {
    MinValueStr = "0" + MinValueStr;
   }

  return(AnsiString(HourValueStr + TimeSeparator + MinValueStr));
*/
  return (TimeStr);
 }

#if !defined(TOUR_DEMO_MODE)

// Функция проверки существования рейса в таблице paths
bool               TourCheckPathExist
                   (AnsiString                        FromStopIdStr,
                    AnsiString                        ToStopIdStr)
 {
  bool                                 ResultFlag;
  TStringList                         *KeyListPtr;
  TStringList                         *ValueListPtr;

  ResultFlag = false;
  KeyListPtr = new TStringList();

  if (KeyListPtr != NULL)
   {
    KeyListPtr->Add(PathFromStopIdFieldNameStr);
    KeyListPtr->Add(PathToStopIdFieldNameStr);

    ValueListPtr = new TStringList();

    if (ValueListPtr != NULL)
     {
      ValueListPtr->Add(QuotedStr(FromStopIdStr));
      ValueListPtr->Add(QuotedStr(ToStopIdStr));

      ResultFlag = TourCheckRecordExist(PathsTableNameStr,KeyListPtr,ValueListPtr);

      delete (ValueListPtr);
      ValueListPtr = NULL;
     }

    delete (KeyListPtr);
    KeyListPtr = NULL;
   }

  return (ResultFlag);
 }

// Функция добавления записи в таблицу
bool               TourRecordAppend
                   (AnsiString                        TableNameStr,
                    TStringList                      *ValueListPtr)
 {
  TADOQuery                           *QueryPtr;
  AnsiString                           SQLStr;
  bool                                 ResultFlag;
  int                                  ListIndex;

  ResultFlag = false;

  try
   {
    if ((ValueListPtr == NULL) ||
        TableNameStr.IsEmpty())
     {
      Exception(GetTranslatedStr(TourMessageModuleIncorrectFuncArgsErrorMessageStr));
     }

    SQLStr  = "INSERT INTO ";
    SQLStr += TableNameStr;
    SQLStr += " VALUES (";

    for (ListIndex = 0; ListIndex < ValueListPtr->Count;ListIndex++)
     {
      SQLStr += ValueListPtr->Strings[ListIndex];

      if (ListIndex < ValueListPtr->Count - 1)
       {
        SQLStr += ",";
       }
     }
    SQLStr += ")";

    QueryPtr = new TADOQuery(NULL);

    if (QueryPtr != NULL)
     {
      QueryPtr->SQL->Text = SQLStr;
      QueryPtr->Connection = TourDataModule->TourDataBaseConnection;

      QueryPtr->ExecSQL();

      ResultFlag = true;

      delete (QueryPtr);
      QueryPtr = NULL;
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  return (ResultFlag);
 }

// Функция добавления записи в таблицу Path
bool               TourPathRecordAppend
                   (AnsiString                        PathFromStopIdStr,
                    AnsiString                        PathToStopIdStr,
                    const float                      *PathLengthValuePtr,
                    const float                      *PathNormSpeedValuePtr)
 {
  bool                                 ResultFlag;
  TStringList                         *ValueListPtr;

  ResultFlag = true;

  if (PathFromStopIdStr.IsEmpty() ||
      PathToStopIdStr.IsEmpty()   ||
      PathFromStopIdStr == PathToStopIdStr)
   {
    ResultFlag = false;
   }
  else
   {
    ValueListPtr = new TStringList();

    if (ValueListPtr != NULL)
     {
      ValueListPtr->Add(PathFromStopIdStr);
      ValueListPtr->Add(PathToStopIdStr);

      try
       {
        if (PathLengthValuePtr == NULL)
         {
          ValueListPtr->Add(TourToolNULLStr);
         }
        else
         {
          ValueListPtr->Add(FloatToStr(*PathLengthValuePtr));
         }

        if (PathNormSpeedValuePtr == NULL)
         {
          ValueListPtr->Add(TourToolNULLStr);
         }
        else
         {
          ValueListPtr->Add(FloatToStr(*PathNormSpeedValuePtr));
         }
       }
      catch (...)
       {
        ResultFlag = false;
       }

      if (ResultFlag)
       {
        ResultFlag = TourRecordAppend(PathsTableNameStr,ValueListPtr);
       }

      delete (ValueListPtr);
      ValueListPtr = NULL;
     }
   }

  return (ResultFlag);
 }

// Пользовательский диалог добавления записи в таблицу Path
bool               TourPathRecordAppendDialog
                   (AnsiString                        PathFromStopIdStr,
                    AnsiString                        PathToStopIdStr,
                    const float                      *PathLengthValuePtr,
                    const float                      *PathNormSpeedValuePtr)
 {
  bool                                 ResultFlag;
  TTourPathMasterProcessForm          *PathAddDialogPtr;
  float                                PathLengthValue;
  float                                PathNormSpeedValue;
  float                               *WorkPathLengthValuePtr;
  float                               *WorkPathNormSpeedValuePtr;

  ResultFlag = false;
  PathAddDialogPtr = NULL;

  WorkPathLengthValuePtr    = &PathLengthValue;
  WorkPathNormSpeedValuePtr = &PathNormSpeedValue;

  try
   {
    PathAddDialogPtr = new TTourPathMasterProcessForm(NULL);

    if (PathAddDialogPtr != NULL)
     {
      PathAddDialogPtr->StopIdFrom = PathFromStopIdStr;
      PathAddDialogPtr->StopIdTo   = PathToStopIdStr;
      PathAddDialogPtr->StopSelectMode     = false;

      if (PathNormSpeedValuePtr != NULL)
       {
        PathAddDialogPtr->PathNormSpeedEdit->Text = FloatToStr(*PathNormSpeedValuePtr);
       }
      else
       {
        PathAddDialogPtr->PathNormSpeedEdit->Text = FloatToStr(TourPathNormSpeedDefaultValue);
       }

      if (PathLengthValuePtr != NULL)
       {
        PathAddDialogPtr->PathLengthEdit->Text = FloatToStr(*PathLengthValuePtr);
       }
      else
       {
        PathAddDialogPtr->PathLengthEdit->Text = FloatToStr(0.0);
       }

      if (PathAddDialogPtr->ShowModal() == mrOk)
       {
        try
         {
          PathLengthValue = StrToFloat(PathAddDialogPtr->PathLengthEdit->Text);
         }
        catch (...)
         {
          WorkPathLengthValuePtr = NULL;
         }

        try
         {
          PathNormSpeedValue = StrToFloat(PathAddDialogPtr->PathNormSpeedEdit->Text);
         }
        catch (...)
         {
          WorkPathNormSpeedValuePtr = NULL;
         }

        ResultFlag
        = TourPathRecordAppend
          (PathFromStopIdStr,PathToStopIdStr,WorkPathLengthValuePtr,WorkPathNormSpeedValuePtr);
       }

      delete (PathAddDialogPtr);
      PathAddDialogPtr = NULL;
     }
   }
  catch (...)
   {
    ResultFlag = false;
   }

  return (ResultFlag);
 }

// Функция получения записи в таблице по ключу
// В случае возникновения ошибки генерируется исключение (Exception)
// В случае нахождения нескольких записей возвращается первая
bool               TourGetRecord
                   (AnsiString                        TableNameStr,
                    TStringList                      *KeyFieldListPtr,
                    TStringList                      *KeyValueListPtr,
                    TStringList                      *UserFieldListPtr,
                    TStringList                      *UserValueListPtr)
 {
  TADOQuery                           *QueryPtr;
  AnsiString                           SQLStr;
  bool                                 ResultFlag;
  int                                  ListIndex;

  ResultFlag = false;

  try
   {
    if ((KeyFieldListPtr->Count  != KeyValueListPtr->Count)  ||
        (KeyFieldListPtr == NULL)  ||
        (KeyValueListPtr == NULL)  ||
        (UserFieldListPtr == NULL) ||
        (UserValueListPtr == NULL) ||
        TableNameStr.IsEmpty())
     {
      Exception(GetTranslatedStr(TourMessageModuleIncorrectFuncArgsErrorMessageStr));
     }

    SQLStr  = "SELECT ";

    for (ListIndex = 0; ListIndex < KeyFieldListPtr->Count;ListIndex++)
     {
      SQLStr += KeyFieldListPtr->Strings[ListIndex];

      if (ListIndex < KeyFieldListPtr->Count - 1)
       {
        SQLStr += ",";
       }
     }

    if (UserFieldListPtr->Count > 0)
     {
      SQLStr += ",";
     }

    for (ListIndex = 0; ListIndex < UserFieldListPtr->Count;ListIndex++)
     {
      SQLStr += UserFieldListPtr->Strings[ListIndex];

      if (ListIndex < UserFieldListPtr->Count - 1)
       {
        SQLStr += ",";
       }
     }

    SQLStr += (" FROM " + TableNameStr + " WHERE ");

    for (ListIndex = 0; ListIndex < KeyValueListPtr->Count;ListIndex++)
     {
      SQLStr += (" ( " + KeyFieldListPtr->Strings[ListIndex]);
      SQLStr += " = ";
      SQLStr += (KeyValueListPtr->Strings[ListIndex] + " ) ");

      if (ListIndex < KeyFieldListPtr->Count - 1)
       {
        SQLStr += " AND ";
       }
     }

    QueryPtr = new TADOQuery(NULL);

    if (QueryPtr != NULL)
     {
      QueryPtr->SQL->Text = SQLStr;
      QueryPtr->Connection = TourDataModule->TourDataBaseConnection;

      QueryPtr->Open();

      if (!QueryPtr->IsEmpty())
       {
        for (ListIndex = 0; ListIndex < UserFieldListPtr->Count;ListIndex++)
         {
          UserValueListPtr
          ->Add(QueryPtr->FieldByName(UserFieldListPtr->Strings[ListIndex])->AsString);
         }
        ResultFlag = true;
       }

      QueryPtr->Close();

      delete (QueryPtr);
      QueryPtr = NULL;
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  return (ResultFlag);
 }

// Функция получения записи в таблице Stop
bool               TourGetStopRecord
                   (AnsiString                        StopIdStr,
                    AnsiString                       *CityZIPStrPtr,
                    AnsiString                       *StopModelStrPtr,
                    AnsiString                       *StopOwnerIdStrPtr,
                    AnsiString                       *StopNameStrPtr)
 {
  bool                                 ResultFlag;
  TStringList                         *KeyFieldListPtr;
  TStringList                         *KeyValueListPtr;
  TStringList                         *UserFieldListPtr;
  TStringList                         *UserValueListPtr;
  unsigned int                         ListIndex;

  ResultFlag = true;
  KeyFieldListPtr  = NULL;
  KeyValueListPtr  = NULL;
  UserFieldListPtr = NULL;
  UserValueListPtr = NULL;

  if (StopIdStr.IsEmpty())
   {
    ResultFlag = false;
   }

  if (ResultFlag)
   {
    KeyFieldListPtr  = new TStringList();
    KeyValueListPtr  = new TStringList();
    UserFieldListPtr = new TStringList();
    UserValueListPtr = new TStringList();

    if ((KeyFieldListPtr  == NULL) ||
        (KeyValueListPtr  == NULL) ||
        (UserFieldListPtr == NULL) ||
        (UserValueListPtr == NULL))
     {
      ResultFlag = false;
     }
   }

  if (ResultFlag)
   {
    AnsiString                         CityZIPStr;
    AnsiString                         StopModelStr;
    AnsiString                         StopOwnerIdStr;
    AnsiString                         StopNameStr;

    KeyFieldListPtr->Add(StopIdFieldNameStr);
    KeyValueListPtr->Add(StopIdStr);

    if (CityZIPStrPtr != NULL)
     {
      UserFieldListPtr->Add(CityZIPFieldNameStr);
     }
    if (StopModelStrPtr != NULL)
     {
      UserFieldListPtr->Add(StopModelFieldNameStr);
     }
    if (StopOwnerIdStrPtr != NULL)
     {
      UserFieldListPtr->Add(StopOwnerIdFieldNameStr);
     }
    if (StopNameStrPtr != NULL)
     {
      UserFieldListPtr->Add(StopNameFieldNameStr);
     }

    if (TourGetRecord(StopTableNameStr,
                      KeyFieldListPtr,
                      KeyValueListPtr,
                      UserFieldListPtr,
                      UserValueListPtr))
     {
      ListIndex = 0;//KeyFieldListPtr->Count;

      if (CityZIPStrPtr != NULL)
       {
        *CityZIPStrPtr = UserValueListPtr->Strings[ListIndex];
        ListIndex++;
       }
      if (StopModelStrPtr != NULL)
       {
        *StopModelStrPtr = UserValueListPtr->Strings[ListIndex];
        ListIndex++;
       }
      if (StopOwnerIdStrPtr != NULL)
       {
        *StopOwnerIdStrPtr = UserValueListPtr->Strings[ListIndex];
        ListIndex++;
       }
      if (StopNameStrPtr != NULL)
       {
        *StopNameStrPtr = UserValueListPtr->Strings[ListIndex];
        ListIndex++;
       }
    }
   }

  if (UserValueListPtr != NULL)
   {
    delete (UserValueListPtr);
    UserValueListPtr = NULL;
   }
  if (UserFieldListPtr != NULL)
   {
    delete (UserFieldListPtr);
    UserFieldListPtr = NULL;
   }
  if (KeyValueListPtr != NULL)
   {
    delete (KeyValueListPtr);
    KeyValueListPtr = NULL;
   }
  if (KeyFieldListPtr != NULL)
   {
    delete (KeyFieldListPtr);
    KeyFieldListPtr = NULL;
   }

  return (ResultFlag);
 }

// Функция получения StopName по StopId в таблице Stop
bool               TourGetStopNameById
                   (AnsiString                        StopIdStr,
                    AnsiString                       *StopNameStrPtr)
 {
  bool                                 ResultFlag;
  AnsiString                           StopNameStr;

  ResultFlag = false;

  if (StopNameStrPtr != NULL)
   {
    ResultFlag = TourGetStopRecord(StopIdStr,NULL,NULL,NULL,&StopNameStr);
   }

  if (ResultFlag)
   {
    *StopNameStrPtr = StopNameStr;
   }

  return (ResultFlag);
 }

#endif

#undef   GetTranslatedStr(Index)

