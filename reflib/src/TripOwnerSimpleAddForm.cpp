//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TripOwnerSimpleAddForm.h"
#include "TourTool.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TripOwnerSimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourTripOwnerSimpleAddForm *TourTripOwnerSimpleAddForm;
//---------------------------------------------------------------------------
__fastcall TTourTripOwnerSimpleAddForm::TTourTripOwnerSimpleAddForm(TComponent* Owner)
        : TTourTripOwnerSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourTripOwnerSimpleAddForm::FormCloseQuery(TObject *Sender,
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
      if (!TripOwnerEdit->Text.IsEmpty())
       {
        if (TourCheckTripOwnerExist(TripOwnerEdit->Text))
         {
          ErrorMessageStr
          = GetTranslatedStr(TourTripOwnerSimpleAddTripOwnerFieldExistErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourTripOwnerSimpleAddTripOwnerFieldExistExceptionMessageStr);
          NoErrorFlag = false;
          TripOwnerEdit->SetFocus();
         }
       }
     }

    if (NoErrorFlag)
     {
      CanClose = true;

      TTourTripOwnerSimpleProcessForm::FormCloseQuery(Sender,CanClose);
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
