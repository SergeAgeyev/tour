//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BusSimpleAddForm.h"
#include "TourTool.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BusSimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourBusSimpleAddForm *TourBusSimpleAddForm;
//---------------------------------------------------------------------------
__fastcall TTourBusSimpleAddForm::TTourBusSimpleAddForm(TComponent* Owner)
        : TTourBusSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourBusSimpleAddForm::FormCloseQuery(TObject *Sender,
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
      if (!BusModelEdit->Text.IsEmpty())
       {
        if (TourCheckBusExist(BusModelEdit->Text))
         {
          ErrorMessageStr
          = GetTranslatedStr(TourBusSimpleAddBusFieldExistErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourBusSimpleAddBusFieldExistExceptionMessageStr);
          NoErrorFlag = false;
          BusModelEdit->SetFocus();
         }
       }
     }

    if (NoErrorFlag)
     {
      CanClose = true;

      TTourBusSimpleProcessForm::FormCloseQuery(Sender,CanClose);
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
