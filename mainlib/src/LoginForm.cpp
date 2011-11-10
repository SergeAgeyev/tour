//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LoginForm.h"
#include "StdTool.h"
#include "TourTool.h"
#include "MessageModuleForm.h"
#include "TourProtect.h"
//#include "MainFrame.h"
//#include "FieldDef.h"
//#include "VegaFunc.h"

#if !defined(TOUR_DEMO_MODE)

  #include "DataModuleForm.h"
  #include "TourDataDBDataModule.h"

#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma resource "*.dfm"

#define TourDefaultDatabaseNameStr "tour"

TTourLoginForm *TourLoginForm;


enum TourLoginStringTypes
 {
  TourLoginInputClerkNameMessageStr = 0,
  TourLoginDataBaseAlreadyOpenMessageStr,
  TourLoginDataCannotOpenDatabaseMessageStr,
  TourLoginDataCannotOpenDatabaseExceptionStr,
  TourLoginProtectMessageStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourLoginForm::TTourLoginForm(TComponent* Owner)
 : TForm(Owner)
 {
//  LoginQuery = NULL;
 }
//---------------------------------------------------------------------------


void __fastcall TTourLoginForm::AcceptButtonClick(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    WideString                           BufferWideString;
    AnsiString                           DataSourceNameStr;

    #if defined(TOURDATABASEMODEADO)
      WideString                         TemporaryWideString;
    #elif defined(TOURDATABASEMODEBDE)
      WideString                         UserNameWideString;
      WideString                         PasswordWideString;
    #endif

    BufferWideString = "";

    UserIDEdit->Text = UserIDEdit->Text.Trim();

    if (UserIDEdit->Text.IsEmpty())
     {
      UserIDEdit->Text = TourDefaultDatabaseNameStr;
     }

    Screen->Cursor = crHourGlass;
    try
     {
      if (TourDataModule == NULL)
       {
        Application->CreateForm(__classid(TTourDataModule), &TourDataModule);
        Application->CreateForm(__classid(TTourDataDBModule), &TourDataDBModule);
       }

      if (TourMessageModule == NULL)
       {
        Application->CreateForm(__classid(TTourMessageModule), &TourMessageModule);
       }

      if (TourGetCommandLineParameter(&DataSourceNameStr,
                                      &TourDataModule->DataBaseEditModeFlag))
       {
        if (DataSourceNameStr.IsEmpty())
         {
          DataSourceNameStr = TourDefaultDatabaseNameStr;
         }
       }
      else
       {
        TourDataModule->DataBaseEditModeFlag = false;
        DataSourceNameStr = TourDefaultDatabaseNameStr;
       }

      #if defined(TOURDATABASEMODEADO)
       {
        TemporaryWideString
        = WideString("Provider=MSDASQL.1;Persist Security Info=False;Data Source=");
        TemporaryWideString += WideString(DataSourceNameStr);
       }
      #elif defined(TOURDATABASEMODEBDE)
       {
        TourDataModule->AliasName = DataSourceNameStr;
       }
      #endif
  /*
      if (TourFunc == NULL)
       {
        Application->CreateForm(__classid(TTourFunc), &TourFunc);
       }
  */
      //Запретить ввод пустого имени пользователя
  //    if (!UserIDEdit->Text.IsEmpty())
  //     {

      #if defined(TOURDATABASEMODEADO)
       {
        TemporaryWideString += WideString(";User ID=");
        TemporaryWideString += WideString(UserIDEdit->Text);

        if (!PasswordEdit->Text.IsEmpty())
         {
          TemporaryWideString += WideString(";Password=");
          TemporaryWideString += WideString(PasswordEdit->Text);
         }

        TemporaryWideString += WideString(";");
       }
      #elif defined(TOURDATABASEMODEBDE)
       {
        UserNameWideString = "";
        PasswordWideString = "";

        UserNameWideString += WideString("USER NAME=");
        UserNameWideString += WideString(UserIDEdit->Text);

        if (!PasswordEdit->Text.IsEmpty())
         {
          PasswordWideString += WideString("PASSWORD=");
          PasswordWideString += WideString(PasswordEdit->Text);
         }
       }
      #endif

      //Если база данных открыта, закрыть
      if (TourDataModule->TourDataBaseConnection->Connected)
       {
        try
         {
          TourDataModule->TourDataBaseConnection->Close();
         }
        catch (Exception &exception)
         {
          Screen->Cursor = crDefault;

          TourShowDialogException(NULL,&exception);
         }
       }
      // Если база закрыта, меняем строку соединения
      if (!TourDataModule->TourDataBaseConnection->Connected)
       {
        #if defined(TOURDATABASEMODEADO)
         {
          TourDataModule
          ->TourDataBaseConnection->ConnectionString = TemporaryWideString;
         }
        #elif defined(TOURDATABASEMODEBDE)
         {
          TourDataModule->TourDataBaseConnection->Params->Clear();
          TourDataModule->TourDataBaseConnection->Params->Add(UserNameWideString);
          TourDataModule->TourDataBaseConnection->Params->Add(PasswordWideString);
         }
        #endif
       }

      Screen->Cursor = crDefault;
      ModalResult = mrOk;
  //     }
  /*
      else
       {
        ModalResult = mrOk;

        Screen->Cursor = crDefault;
        TourShowDialogError
        (AnsiString(GetTranslatedStr(TourLoginInputClerkNameMessageStr)).c_str());
       }
  */
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
    Screen->Cursor = crDefault;
   }
  #endif
 }

//---------------------------------------------------------------------------


void __fastcall TTourLoginForm::FormCloseQuery(TObject *Sender,
      bool &CanClose)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    CanClose = false;

    if (ModalResult == mrOk)
     {
      CursorWaitOpen();

      // База данных должна быть закрыта.
      if (!TourDataModule->TourDataBaseConnection->Connected)
       {
        try
         {
          TourDataModule->TourDataBaseConnection->Open();
  /*
          // Создаем и инициализируем запрос корректности логина
          if (!LoginQueryCreate())
           {
            throw Exception("Ошибка создания экземпляра TQuery (LoginQuery)");
           }

          LoginQuery->Open();
  */
  //        Screen->Cursor = crDefault;
  /*
          // Если пользователь не зарегистрирован в базе, закрываем базу
          if (LoginQuery->IsEmpty())
           {
            TourShowDialogError("Неизвестный пользователь");

            try
             {
              TourDataModule->TourDataBaseConnection->Close();
             }
            catch (Exception &exception)
             {
              TourShowDialogException(NULL,&exception);
             }
           }
          // Если зпользователь зарегистрирован в базе, сохраняем его UserId
          else
           {
  */
            TourDataModule->CurrentClerkIdStr = UserIDEdit->Text;
  /*
            TourDataModule->CurrentBranchIdStr
            = LoginQuery->FieldByName(BranchIdFieldNameStr)->AsString;
  */

            if (TourProtectCheck(TourDataModule->TourDataBaseConnection,
                                 &TourProtectInfoMinimalVersion))
             {
              ModalResult = mrOk;
             }
            else
             {
              TourShowDialogError(GetTranslatedStr(TourLoginProtectMessageStr).c_str());
              ModalResult = mrCancel;
             }

            CanClose = true;
  /*
           }

          LoginQuery->Close();

          delete (LoginQuery);
  */
         }
        catch (Exception &exception)
         {
          AnsiString                         ExceptionStr;

          ExceptionStr = exception.Message;

          exception.Message  = GetTranslatedStr(TourLoginDataCannotOpenDatabaseExceptionStr);
          exception.Message += "\n";
          exception.Message += ExceptionStr;

          TourShowDialogException
          (&(GetTranslatedStr(TourLoginDataCannotOpenDatabaseMessageStr)),
           &exception);
         }
       }
      else
       {
        Application
        ->MessageBox
          (AnsiString(GetTranslatedStr(TourLoginDataBaseAlreadyOpenMessageStr)).c_str(),
           "ASSERT",
           MB_OK);

        CanClose = true;
       }
      CursorWaitClose();
     }
    else
     {
      CanClose = true;
     }
   }
  #else
   {
    CanClose = true;
   }
  #endif
 }

//---------------------------------------------------------------------------

/*
Boolean TTourLoginForm::LoginQueryCreate(void)
 {
  AnsiString                           SQLQueryStr;
  Boolean                              ResultFlag;

  ResultFlag = true;

  SQLQueryStr = "select ";
  SQLQueryStr += ClerkIdFieldNameStr;
  SQLQueryStr += ",";
  SQLQueryStr += BranchIdFieldNameStr;
  SQLQueryStr += " from ";
  SQLQueryStr += ClerkTableNameStr;
  SQLQueryStr += " where ";
  SQLQueryStr += ClerkTableNameStr;
  SQLQueryStr += ".";
  SQLQueryStr += ClerkIdFieldNameStr;
  SQLQueryStr += " = ";

  SQLQueryStr += "\'";
  SQLQueryStr += UserIDEdit->Text;
  SQLQueryStr += "\'";

  LoginQuery = new TADOQuery(this);

  if (LoginQuery != NULL)
   {
    LoginQuery->Connection = TourDataModule->TourDataBaseConnection;

    LoginQuery->SQL->Add(SQLQueryStr);
   }
  else
   {
    ResultFlag = false;
   }

  return (ResultFlag);
 }
*/

void __fastcall TTourLoginForm::UserIDEditExit(TObject *Sender)
 {
  UserIDEdit->Text = UserIDEdit->Text.Trim();

  if (UserIDEdit->Text.IsEmpty())
   {
    UserIDEdit->Text = TourDefaultDatabaseNameStr;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourLoginForm::FormCreate(TObject *Sender)
 {
  //
  UserIDEdit->Text = TourDefaultDatabaseNameStr;
 }
//---------------------------------------------------------------------------
#undef   GetTranslatedStr(Index)




