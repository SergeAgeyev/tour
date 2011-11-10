//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RegionSimpleAddForm.h"
#include "TourTool.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RegionSimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourRegionSimpleAddForm *TourRegionSimpleAddForm;
//---------------------------------------------------------------------------
__fastcall TTourRegionSimpleAddForm::TTourRegionSimpleAddForm(TComponent* Owner)
        : TTourRegionSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourRegionSimpleAddForm::FormCloseQuery(TObject *Sender,
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
      if (!RegionIdEdit->Text.IsEmpty())
       {
        if (TourCheckRegionExist(RegionIdEdit->Text))
         {
          ErrorMessageStr
          = GetTranslatedStr(TourRegionSimpleAddRegionFieldExistErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourRegionSimpleAddRegionFieldExistExceptionMessageStr);
          NoErrorFlag = false;
          RegionIdEdit->SetFocus();
         }
       }
     }

    if (NoErrorFlag)
     {
      CanClose = true;

      TTourRegionSimpleProcessForm::FormCloseQuery(Sender,CanClose);
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
