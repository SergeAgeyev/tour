//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CitySimpleProcessForm.h"
#include "TourTool.h"
#include "RegionSimpleAddForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SimpleProcessForm"
#pragma link "VStringStorage"
#pragma link "RxGrdCpt"
#pragma link "VCustomKeyComboBox"
#pragma link "VMemoKeyComboBox"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourCitySimpleProcessForm *TourCitySimpleProcessForm;

//---------------------------------------------------------------------------
__fastcall TTourCitySimpleProcessForm::TTourCitySimpleProcessForm(TComponent* Owner)
        : TTourSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourCitySimpleProcessForm::FormCloseQuery(TObject *Sender,
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
      if (CityZIPEdit->Text.IsEmpty())
       {
        ErrorMessageStr
        = GetTranslatedStr(TourCitySimpleProcessCityFieldEmptyErrorMessageStr);
        ExceptionMessageStr
        = GetTranslatedStr(TourCitySimpleProcessCityFieldEmptyExceptionMessageStr);
        NoErrorFlag = false;
        CityZIPEdit->SetFocus();
       }

     if (NoErrorFlag)
      {
       if (!CityPopulationEdit->Text.IsEmpty())
        {
         try
          {
           StrToInt(CityPopulationEdit->Text);
          }
         catch (...)
          {
           ErrorMessageStr
           = GetTranslatedStr(TourSimpleProcessIllegalIntValueErrorMessageStr);
           ExceptionMessageStr
           = GetTranslatedStr(TourSimpleProcessIllegalIntValueExceptionMessageStr);
           NoErrorFlag = false;
           CityPopulationEdit->SetFocus();
          }
        }
      }
/*
      if (!CitySpeedFactorEdit->Text.IsEmpty())
       {
        try
         {
          StrToFloat(CitySpeedFactorEdit->Text);
         }
        catch (...)
         {
          ErrorMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalFloatValueErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalFloatValueExceptionMessageStr);
          NoErrorFlag = false;
          CitySpeedFactorEdit->SetFocus();
         }
       }
*/
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
void __fastcall TTourCitySimpleProcessForm::AddRegionButtonClick(
      TObject *Sender)
 {
  TTourRegionSimpleAddForm            *FormPtr;
  bool                                 NoErrorFlag;
  AnsiString                           ErrorMessageStr;
  AnsiString                           ExceptionMessageStr;

  FormPtr = NULL;
  NoErrorFlag = true;

  FormPtr = new TTourRegionSimpleAddForm(this);

  if (FormPtr != NULL)
   {
    if (FormPtr->ShowModal() == mrOk)
     {
      // Apply
     }
    else
     {
      // Cancel
     }

    delete (FormPtr);
    FormPtr = NULL;
   }
  else
   {
    ErrorMessageStr
    = GetTranslatedStr(TourCitySimpleProcessAddRegionActionErrorMessageStr);
    ExceptionMessageStr
    = GetTranslatedStr(TourCitySimpleProcessAddActionExceptionMessageStr);
    NoErrorFlag = false;
   }

  if (!NoErrorFlag)
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
//---------------------------------------------------------------------------

