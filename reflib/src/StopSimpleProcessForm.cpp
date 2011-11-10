//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopSimpleProcessForm.h"
#include "TourTool.h"
#include "SimpleDataSetViewForm.h"
#include "CitySimpleAddForm.h"
#include "StopModelSimpleAddForm.h"
#include "StopOwnerSimpleAddForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SimpleProcessForm"
#pragma link "VStringStorage"
#pragma link "RxGrdCpt"
#pragma link "VCustomKeyComboBox"
#pragma link "VMemoKeyComboBox"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourStopSimpleProcessForm *TourStopSimpleProcessForm;

//---------------------------------------------------------------------------
__fastcall TTourStopSimpleProcessForm::TTourStopSimpleProcessForm(TComponent* Owner)
        : TTourSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourStopSimpleProcessForm::FormCloseQuery(TObject *Sender,
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
      if (StopIdEdit->Text.IsEmpty())
       {
        ErrorMessageStr
        = GetTranslatedStr(TourStopSimpleProcessStopFieldEmptyErrorMessageStr);
        ExceptionMessageStr
        = GetTranslatedStr(TourStopSimpleProcessStopFieldEmptyExceptionMessageStr);
        NoErrorFlag = false;
        StopIdEdit->SetFocus();
       }

     if (NoErrorFlag)
      {
       if (CityZIPEdit->Text.IsEmpty())
        {
         ErrorMessageStr
         = GetTranslatedStr(TourStopSimpleProcessCityFieldEmptyErrorMessageStr);
         ExceptionMessageStr
         = GetTranslatedStr(TourStopSimpleProcessCityFieldEmptyExceptionMessageStr);
         NoErrorFlag = false;
         CityZIPEdit->SetFocus();
        }
       else
        {
         if (!TourCheckCityExist(CityZIPEdit->Text))
          {
           ErrorMessageStr
           = GetTranslatedStr(TourStopSimpleProcessCityNotExistErrorMessageStr);
           ExceptionMessageStr
           = GetTranslatedStr(TourStopSimpleProcessCityNotExistExceptionMessageStr);
           NoErrorFlag = false;
           CityZIPEdit->SetFocus();
          }
        }
      }

/*
      if (!StopPopulationEdit->Text.IsEmpty())
       {
        try
         {
          StrToInt(StopPopulationEdit->Text);
         }
        catch (...)
         {
          ErrorMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalIntValueErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalIntValueExceptionMessageStr);
          NoErrorFlag = false;
          StopPopulationEdit->SetFocus();
         }
       }

      if (!StopSpeedFactorEdit->Text.IsEmpty())
       {
        try
         {
          StrToFloat(StopSpeedFactorEdit->Text);
         }
        catch (...)
         {
          ErrorMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalFloatValueErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalFloatValueExceptionMessageStr);
          NoErrorFlag = false;
          StopSpeedFactorEdit->SetFocus();
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
void __fastcall TTourStopSimpleProcessForm::CityZIPButtonClick(
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

    FormPtr->Caption = GetTranslatedStr(TourStopSimpleProcessCityListCaptionStr);
    ItemCount = CityStorage.size();

    ColumnPtr = FormPtr->ListView->Columns->Add();
    if (ColumnPtr != NULL)
     {
      ColumnPtr->Width    = 75;
      ColumnPtr->Caption  = GetTranslatedStr(TourStopSimpleProcessCityIdStr);
     }
    ColumnPtr = FormPtr->ListView->Columns->Add();
    if (ColumnPtr != NULL)
     {
      ColumnPtr->AutoSize = true;
      ColumnPtr->Caption  = GetTranslatedStr(TourStopSimpleProcessCityNameStr);;
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
//---------------------------------------------------------------------------

void __fastcall TTourStopSimpleProcessForm::AddCityButtonClick(
      TObject *Sender)
 {
  TTourCitySimpleAddForm              *FormPtr;
  bool                                 NoErrorFlag;
  AnsiString                           ErrorMessageStr;
  AnsiString                           ExceptionMessageStr;

  FormPtr = NULL;
  NoErrorFlag = true;

  FormPtr = new TTourCitySimpleAddForm(this);

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
    = GetTranslatedStr(TourStopSimpleProcessAddCityActionErrorMessageStr);
    ExceptionMessageStr
    = GetTranslatedStr(TourStopSimpleProcessAddActionExceptionMessageStr);
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

void __fastcall TTourStopSimpleProcessForm::AddStopOwnerButtonClick(
      TObject *Sender)
 {
  TTourStopOwnerSimpleAddForm         *FormPtr;
  bool                                 NoErrorFlag;
  AnsiString                           ErrorMessageStr;
  AnsiString                           ExceptionMessageStr;

  FormPtr = NULL;
  NoErrorFlag = true;

  FormPtr = new TTourStopOwnerSimpleAddForm(this);

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
    = GetTranslatedStr(TourStopSimpleProcessAddStopOwnerActionErrorMessageStr);
    ExceptionMessageStr
    = GetTranslatedStr(TourStopSimpleProcessAddActionExceptionMessageStr);
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

void __fastcall TTourStopSimpleProcessForm::AddStopModelButtonClick(
      TObject *Sender)
 {
  TTourStopModelSimpleAddForm         *FormPtr;
  bool                                 NoErrorFlag;
  AnsiString                           ErrorMessageStr;
  AnsiString                           ExceptionMessageStr;

  FormPtr = NULL;
  NoErrorFlag = true;

  FormPtr = new TTourStopModelSimpleAddForm(this);

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
    = GetTranslatedStr(TourStopSimpleProcessAddStopOwnerActionErrorMessageStr);
    ExceptionMessageStr
    = GetTranslatedStr(TourStopSimpleProcessAddActionExceptionMessageStr);
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

