//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopModelSimpleAddForm.h"
#include "TourTool.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "StopModelSimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourStopModelSimpleAddForm *TourStopModelSimpleAddForm;
//---------------------------------------------------------------------------
__fastcall TTourStopModelSimpleAddForm::TTourStopModelSimpleAddForm(TComponent* Owner)
        : TTourStopModelSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourStopModelSimpleAddForm::FormCloseQuery(TObject *Sender,
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
      if (!StopModelEdit->Text.IsEmpty())
       {
        if (TourCheckStopModelExist(StopModelEdit->Text))
         {
          ErrorMessageStr
          = GetTranslatedStr(TourStopModelSimpleAddStopModelFieldExistErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourStopModelSimpleAddStopModelFieldExistExceptionMessageStr);
          NoErrorFlag = false;
          StopModelEdit->SetFocus();
         }
       }
     }

    if (NoErrorFlag)
     {
      CanClose = true;

      TTourStopModelSimpleProcessForm::FormCloseQuery(Sender,CanClose);
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
