//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TripOwnerSimpleProcessForm.h"
#include "TourTool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourTripOwnerSimpleProcessForm *TourTripOwnerSimpleProcessForm;

//---------------------------------------------------------------------------
__fastcall TTourTripOwnerSimpleProcessForm::TTourTripOwnerSimpleProcessForm(TComponent* Owner)
        : TTourSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourTripOwnerSimpleProcessForm::FormCloseQuery(TObject *Sender,
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
      if (TripOwnerEdit->Text.IsEmpty())
       {
        ErrorMessageStr
        = GetTranslatedStr(TourTripOwnerSimpleProcessTripOwnerFieldEmptyErrorMessageStr);
        ExceptionMessageStr
        = GetTranslatedStr(TourTripOwnerSimpleProcessTripOwnerFieldEmptyExceptionMessageStr);
        NoErrorFlag = false;
        TripOwnerEdit->SetFocus();
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
