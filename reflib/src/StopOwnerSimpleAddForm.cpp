//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopOwnerSimpleAddForm.h"
#include "TourTool.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "StopOwnerSimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourStopOwnerSimpleAddForm *TourStopOwnerSimpleAddForm;
//---------------------------------------------------------------------------
__fastcall TTourStopOwnerSimpleAddForm::TTourStopOwnerSimpleAddForm(TComponent* Owner)
        : TTourStopOwnerSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourStopOwnerSimpleAddForm::FormCloseQuery(TObject *Sender,
      bool &CanClose)
 {
  bool                                 NoErrorFlag;
  AnsiString                           ErrorMessageStr;
  AnsiString                           ExceptionMessageStr;

  NoErrorFlag = true;
  CanClose    = false;

  if (ModalResult == mrOk)
   {
    if (NoErrorFlag)
     {
      if (!StopOwnerEdit->Text.IsEmpty())
       {
        if (TourCheckStopOwnerExist(StopOwnerEdit->Text))
         {
          ErrorMessageStr
          = GetTranslatedStr(TourStopOwnerSimpleAddStopOwnerFieldExistErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourStopOwnerSimpleAddStopOwnerFieldExistExceptionMessageStr);
          NoErrorFlag = false;
          StopOwnerEdit->SetFocus();
         }
       }
     }

    if (NoErrorFlag)
     {
      CanClose = true;

      TTourStopOwnerSimpleProcessForm::FormCloseQuery(Sender,CanClose);
     }
    else
     {
      AnsiString                        *ErrorMessageStrPtr;
      AnsiString                        *ExceptionMessageStrPtr;

      if (!ErrorMessageStr.IsEmpty())
       {
        ErrorMessageStrPtr = &ErrorMessageStr;
       }
      else
       {
        ErrorMessageStrPtr = NULL;
       }

      if (!ExceptionMessageStr.IsEmpty())
       {
        ExceptionMessageStrPtr = &ExceptionMessageStr;
       }
      else
       {
        ExceptionMessageStrPtr = NULL;
       }

      TourShowDialogExceptionStr(ErrorMessageStrPtr,ExceptionMessageStrPtr);
     }
   }
  else
   {
    CanClose = true;
   }
 }
//---------------------------------------------------------------------------
