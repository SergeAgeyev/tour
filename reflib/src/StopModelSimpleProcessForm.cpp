//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopModelSimpleProcessForm.h"
#include "TourTool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourStopModelSimpleProcessForm *TourStopModelSimpleProcessForm;

//---------------------------------------------------------------------------
__fastcall TTourStopModelSimpleProcessForm::TTourStopModelSimpleProcessForm(TComponent* Owner)
        : TTourSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourStopModelSimpleProcessForm::FormCloseQuery(TObject *Sender,
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
      if (StopModelEdit->Text.IsEmpty())
       {
        ErrorMessageStr
        = GetTranslatedStr(TourStopModelSimpleProcessStopModelFieldEmptyErrorMessageStr);
        ExceptionMessageStr
        = GetTranslatedStr(TourStopModelSimpleProcessStopModelFieldEmptyExceptionMessageStr);
        NoErrorFlag = false;
        StopModelEdit->SetFocus();
       }
     }

    if (NoErrorFlag)
     {
      CanClose = true;
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
