//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopSimpleAddForm.h"
#include "TourTool.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "StopSimpleProcessForm"
#pragma link "VStringStorage"
#pragma link "RxGrdCpt"
#pragma link "VCustomKeyComboBox"
#pragma link "VMemoKeyComboBox"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourStopSimpleAddForm *TourStopSimpleAddForm;
//---------------------------------------------------------------------------
__fastcall TTourStopSimpleAddForm::TTourStopSimpleAddForm(TComponent* Owner)
        : TTourStopSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourStopSimpleAddForm::FormCloseQuery(TObject *Sender,
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
      if (!StopIdEdit->Text.IsEmpty())
       {
        if (TourCheckStopExist(StopIdEdit->Text))
         {
          ErrorMessageStr
          = GetTranslatedStr(TourStopSimpleAddStopFieldExistErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourStopSimpleAddStopFieldExistExceptionMessageStr);
          NoErrorFlag = false;
          StopIdEdit->SetFocus();
         }
       }
     }

    if (NoErrorFlag)
     {
      CanClose = true;

      TTourStopSimpleProcessForm::FormCloseQuery(Sender,CanClose);
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
