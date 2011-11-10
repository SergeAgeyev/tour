//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TripSimpleAddForm.h"
#include "TourTool.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TripSimpleProcessForm"
#pragma link "VStringStorage"
#pragma link "RxGrdCpt"
#pragma link "VCustomKeyComboBox"
#pragma link "VMemoKeyComboBox"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourTripSimpleAddForm *TourTripSimpleAddForm;
//---------------------------------------------------------------------------
__fastcall TTourTripSimpleAddForm::TTourTripSimpleAddForm(TComponent* Owner)
        : TTourTripSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourTripSimpleAddForm::FormCloseQuery(TObject *Sender,
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
      if (!TripIdEdit->Text.IsEmpty())
       {
        if (TourCheckTripExist(TripIdEdit->Text))
         {
          ErrorMessageStr
          = GetTranslatedStr(TourTripSimpleAddTripFieldExistErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourTripSimpleAddTripFieldExistExceptionMessageStr);
          NoErrorFlag = false;
          TripIdEdit->SetFocus();
         }
       }
     }

    if (NoErrorFlag)
     {
      CanClose = true;

      TTourTripSimpleProcessForm::FormCloseQuery(Sender,CanClose);
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
