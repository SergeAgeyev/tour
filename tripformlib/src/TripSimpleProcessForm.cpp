//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TripSimpleProcessForm.h"
#include "TourTool.h"
#include "SimpleDataSetViewForm.h"
#include "BusSimpleAddForm.h"
#include "TripOwnerAddForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SimpleProcessForm"
#pragma link "VStringStorage"
#pragma link "RxGrdCpt"
#pragma link "VCustomKeyComboBox"
#pragma link "VMemoKeyComboBox"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourTripSimpleProcessForm *TourTripSimpleProcessForm;

//---------------------------------------------------------------------------
__fastcall TTourTripSimpleProcessForm::TTourTripSimpleProcessForm(TComponent* Owner)
        : TTourSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourTripSimpleProcessForm::FormCloseQuery(TObject *Sender,
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
      if (TripIdEdit->Text.IsEmpty())
       {
        ErrorMessageStr
        = GetTranslatedStr(TourTripSimpleProcessTripFieldEmptyErrorMessageStr);
        ExceptionMessageStr
        = GetTranslatedStr(TourTripSimpleProcessTripFieldEmptyExceptionMessageStr);
        NoErrorFlag = false;
        TripIdEdit->SetFocus();
       }
/*
      if (!TripPopulationEdit->Text.IsEmpty())
       {
        try
         {
          StrToInt(TripPopulationEdit->Text);
         }
        catch (...)
         {
          ErrorMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalIntValueErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalIntValueExceptionMessageStr);
          NoErrorFlag = false;
          TripPopulationEdit->SetFocus();
         }
       }

      if (!TripSpeedFactorEdit->Text.IsEmpty())
       {
        try
         {
          StrToFloat(TripSpeedFactorEdit->Text);
         }
        catch (...)
         {
          ErrorMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalFloatValueErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalFloatValueExceptionMessageStr);
          NoErrorFlag = false;
          TripSpeedFactorEdit->SetFocus();
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
/*
void __fastcall TTourTripSimpleProcessForm::CityZIPButtonClick(
      TObject *Sender)
 {
  TTourSimpleDataSetViewForm          *FormPtr;
  //
  FormPtr = new TTourSimpleDataSetViewForm(this);

  if (FormPtr != NULL)
   {
    unsigned int                       ItemIndex;
    unsigned int                       ItemCount;
    TListItem                         *ItemPtr;
    TListColumn                       *ColumnPtr;

    FormPtr->Caption = GetTranslatedStr(TourTripSimpleProcessCityListCaptionStr);
    ItemCount = CityStorage.size();

    ColumnPtr = FormPtr->ListView->Columns->Add();
    if (ColumnPtr != NULL)
     {
      ColumnPtr->Width    = 75;
      ColumnPtr->Caption  = GetTranslatedStr(TourTripSimpleProcessCityIdStr);
     }
    ColumnPtr = FormPtr->ListView->Columns->Add();
    if (ColumnPtr != NULL)
     {
      ColumnPtr->AutoSize = true;
      ColumnPtr->Caption  = GetTranslatedStr(TourTripSimpleProcessCityNameStr);;
     }

    for (ItemIndex = 0; ItemIndex < ItemCount; ItemIndex++)
     {
      ItemPtr = FormPtr->ListView->Items->Add();

      if (ItemPtr != NULL)
       {
        ItemPtr->Caption = CityStorage[ItemIndex].IdStr;
        ItemPtr->SubItems->Append(CityStorage[ItemIndex].NameStr);
       }
     }

    if (FormPtr->ShowModal() == mrOk)
     {
      CityZIPEdit->Text = FormPtr->ListView->Selected->Caption;
     }

    delete (FormPtr);
    FormPtr = NULL;
   }
 }
*/
//---------------------------------------------------------------------------

void __fastcall TTourTripSimpleProcessForm::AddBusButtonClick(
      TObject *Sender)
 {
  TTourBusSimpleAddForm               *FormPtr;
  bool                                 NoErrorFlag;
  AnsiString                           ErrorMessageStr;
  AnsiString                           ExceptionMessageStr;

  FormPtr = NULL;
  NoErrorFlag = true;

  FormPtr = new TTourBusSimpleAddForm(this);

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
    = GetTranslatedStr(TourTripSimpleProcessAddBusActionErrorMessageStr);
    ExceptionMessageStr
    = GetTranslatedStr(TourTripSimpleProcessAddActionExceptionMessageStr);
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

void __fastcall TTourTripSimpleProcessForm::AddTripOwnerButtonClick(
      TObject *Sender)
 {
  TTourRefBookTripOwnerAddForm        *FormPtr;
  bool                                 NoErrorFlag;
  AnsiString                           ErrorMessageStr;
  AnsiString                           ExceptionMessageStr;

  FormPtr = NULL;
  NoErrorFlag = true;

  FormPtr = new TTourRefBookTripOwnerAddForm(this);

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
    = GetTranslatedStr(TourTripSimpleProcessAddTripOwnerActionErrorMessageStr);
    ExceptionMessageStr
    = GetTranslatedStr(TourTripSimpleProcessAddActionExceptionMessageStr);
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

