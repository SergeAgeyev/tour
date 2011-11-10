//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PathSimpleAddForm.h"
#include "TourTool.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "PathSimpleProcessForm"
#pragma link "VStringStorage"
#pragma link "RxGrdCpt"
#pragma link "VCustomKeyComboBox"
#pragma link "VMemoKeyComboBox"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourPathSimpleAddForm *TourPathSimpleAddForm;
//---------------------------------------------------------------------------
__fastcall TTourPathSimpleAddForm::TTourPathSimpleAddForm(TComponent* Owner)
        : TTourPathSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourPathSimpleAddForm::FormCloseQuery(TObject *Sender,
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
      if (!FromStopIdEdit->Text.IsEmpty() && !ToStopIdEdit->Text.IsEmpty())
       {
        if (TourCheckPathExist(FromStopIdEdit->Text,ToStopIdEdit->Text))
         {
          ErrorMessageStr
          = GetTranslatedStr(TourPathSimpleAddPathFieldExistErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourPathSimpleAddPathFieldExistExceptionMessageStr);
          NoErrorFlag = false;
          FromStopIdEdit->SetFocus();
         }
       }
     }

    if (NoErrorFlag)
     {
      CanClose = true;

      TTourPathSimpleProcessForm::FormCloseQuery(Sender,CanClose);
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
