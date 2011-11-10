//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RegionSimpleProcessForm.h"
#include "TourTool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourRegionSimpleProcessForm *TourRegionSimpleProcessForm;

//---------------------------------------------------------------------------
__fastcall TTourRegionSimpleProcessForm::TTourRegionSimpleProcessForm(TComponent* Owner)
        : TTourSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourRegionSimpleProcessForm::FormCloseQuery(TObject *Sender,
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
      if (RegionIdEdit->Text.IsEmpty())
       {
        ErrorMessageStr
        = GetTranslatedStr(TourRegionSimpleProcessRegionIdFieldEmptyErrorMessageStr);
        ExceptionMessageStr
        = GetTranslatedStr(TourRegionSimpleProcessRegionIdFieldEmptyExceptionMessageStr);
        NoErrorFlag = false;
        RegionIdEdit->SetFocus();
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
