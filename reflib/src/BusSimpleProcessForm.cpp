//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BusSimpleProcessForm.h"
#include "TourTool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourBusSimpleProcessForm *TourBusSimpleProcessForm;

//---------------------------------------------------------------------------
__fastcall TTourBusSimpleProcessForm::TTourBusSimpleProcessForm(TComponent* Owner)
        : TTourSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourBusSimpleProcessForm::FormCloseQuery(TObject *Sender,
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
      if (BusModelEdit->Text.IsEmpty())
       {
        ErrorMessageStr
        = GetTranslatedStr(TourBusSimpleProcessBusFieldEmptyErrorMessageStr);
        ExceptionMessageStr
        = GetTranslatedStr(TourBusSimpleProcessBusFieldEmptyExceptionMessageStr);
        NoErrorFlag = false;
        BusModelEdit->SetFocus();
       }

      if (!BusCapacityEdit->Text.IsEmpty())
       {
        try
         {
          StrToInt(BusCapacityEdit->Text);
         }
        catch (...)
         {
          ErrorMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalIntValueErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalIntValueExceptionMessageStr);
          NoErrorFlag = false;
          BusCapacityEdit->SetFocus();
         }
       }

      if (!BusSpeedFactorEdit->Text.IsEmpty())
       {
        try
         {
          StrToFloat(BusSpeedFactorEdit->Text);
         }
        catch (...)
         {
          ErrorMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalFloatValueErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalFloatValueExceptionMessageStr);
          NoErrorFlag = false;
          BusSpeedFactorEdit->SetFocus();
         }
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
