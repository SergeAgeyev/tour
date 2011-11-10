//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PathSimpleProcessForm.h"
#include "TourTool.h"
#include "SimpleDataSetViewForm.h"
#include "CitySimpleAddForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SimpleProcessForm"
#pragma link "VStringStorage"
#pragma link "RxGrdCpt"
#pragma link "VCustomKeyComboBox"
#pragma link "VMemoKeyComboBox"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourPathSimpleProcessForm *TourPathSimpleProcessForm;

//---------------------------------------------------------------------------
__fastcall TTourPathSimpleProcessForm::TTourPathSimpleProcessForm(TComponent* Owner)
        : TTourSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourPathSimpleProcessForm::FormCloseQuery(TObject *Sender,
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
      if (FromStopIdEdit->Text.IsEmpty())
       {
        ErrorMessageStr
        = GetTranslatedStr(TourPathSimpleProcessBeginPathFieldEmptyErrorMessageStr);
        ExceptionMessageStr
        = GetTranslatedStr(TourPathSimpleProcessBeginPathFieldEmptyExceptionMessageStr);
        NoErrorFlag = false;
        FromStopIdEdit->SetFocus();
       }
     }

    if (NoErrorFlag)
     {
      if (ToStopIdEdit->Text.IsEmpty())
       {
        ErrorMessageStr
        = GetTranslatedStr(TourPathSimpleProcessEndPathFieldEmptyErrorMessageStr);
        ExceptionMessageStr
        = GetTranslatedStr(TourPathSimpleProcessEndPathFieldEmptyExceptionMessageStr);
        NoErrorFlag = false;
        ToStopIdEdit->SetFocus();
       }
     }

    if (NoErrorFlag)
     {
      if (!FromStopIdEdit->Text.IsEmpty())
       {
        if (!TourCheckStopExist(FromStopIdEdit->Text))
         {
          ErrorMessageStr
          = GetTranslatedStr(TourPathSimpleProcessStopNotExistErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourPathSimpleProcessStopNotExistExceptionMessageStr);
          NoErrorFlag = false;
          FromStopIdEdit->SetFocus();
         }
       }
     }

    if (NoErrorFlag)
     {
      if (!ToStopIdEdit->Text.IsEmpty())
       {
        if (!TourCheckStopExist(ToStopIdEdit->Text))
         {
          ErrorMessageStr
          = GetTranslatedStr(TourPathSimpleProcessStopNotExistErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourPathSimpleProcessStopNotExistExceptionMessageStr);
          NoErrorFlag = false;
          ToStopIdEdit->SetFocus();
         }
       }
     }

    if (NoErrorFlag)
     {
      if (ToStopIdEdit->Text == FromStopIdEdit->Text)
       {
        ErrorMessageStr
        = GetTranslatedStr(TourPathSimpleProcessInvalidPathErrorMessageStr);
        ExceptionMessageStr
        = GetTranslatedStr(TourPathSimpleProcessInvalidPathExceptionMessageStr);
        NoErrorFlag = false;
        ToStopIdEdit->SetFocus();
       }
     }

    if (NoErrorFlag)
     {
      if (!SpeedEdit->Text.IsEmpty())
       {
        try
         {
          StrToFloat(SpeedEdit->Text);
         }
        catch (...)
         {
          ErrorMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalFloatValueErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalFloatValueExceptionMessageStr);
          NoErrorFlag = false;
          SpeedEdit->SetFocus();
         }
       }
     }

    if (NoErrorFlag)
     {
      if (!LengthEdit->Text.IsEmpty())
       {
        try
         {
          StrToFloat(LengthEdit->Text);
         }
        catch (...)
         {
          ErrorMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalFloatValueErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourSimpleProcessIllegalFloatValueExceptionMessageStr);
          NoErrorFlag = false;
          LengthEdit->SetFocus();
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
AnsiString TTourPathSimpleProcessForm::GetStopId(void)
 {
  TTourSimpleDataSetViewForm          *FormPtr;
  AnsiString                           ResultStr;
  //
  ResultStr = "";

  FormPtr = new TTourSimpleDataSetViewForm(this);

  if (FormPtr != NULL)
   {
    unsigned int                       ItemIndex;
    unsigned int                       ItemCount;
    TListItem                         *ItemPtr;
    TListColumn                       *ColumnPtr;

    FormPtr->Caption = GetTranslatedStr(TourPathSimpleProcessStopListCaptionStr);
    ItemCount = StopStorage.size();

    ColumnPtr = FormPtr->ListView->Columns->Add();
    if (ColumnPtr != NULL)
     {
      ColumnPtr->Width    = 75;
      ColumnPtr->Caption  = GetTranslatedStr(TourPathSimpleProcessStopIdStr);
     }
    ColumnPtr = FormPtr->ListView->Columns->Add();
    if (ColumnPtr != NULL)
     {
      ColumnPtr->AutoSize = true;
      ColumnPtr->Caption  = GetTranslatedStr(TourPathSimpleProcessStopNameStr);;
     }

    for (ItemIndex = 0; ItemIndex < ItemCount; ItemIndex++)
     {
      ItemPtr = FormPtr->ListView->Items->Add();

      if (ItemPtr != NULL)
       {
        ItemPtr->Caption = StopStorage[ItemIndex].IdStr;
        ItemPtr->SubItems->Append(StopStorage[ItemIndex].NameStr);
       }
     }

    if (FormPtr->ShowModal() == mrOk)
     {
      if (FormPtr->ListView->Selected != NULL)
       {
        ResultStr = FormPtr->ListView->Selected->Caption;
       }
     }

    delete (FormPtr);
    FormPtr = NULL;
   }

  return (ResultStr);
 }

//---------------------------------------------------------------------------

void __fastcall TTourPathSimpleProcessForm::FromStopIdButtonClick(
      TObject *Sender)
 {
  AnsiString                           StopIdStr;

  StopIdStr = GetStopId();

  if (StopIdStr != "")
   {
    FromStopIdEdit->Text = StopIdStr;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourPathSimpleProcessForm::ToStopIdButtonClick(
      TObject *Sender)
 {
  AnsiString                           StopIdStr;

  StopIdStr = GetStopId();

  if (StopIdStr != "")
   {
    ToStopIdEdit->Text = StopIdStr;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourPathSimpleProcessForm::AddCityButtonClick(
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
    = GetTranslatedStr(TourPathSimpleProcessAddCityActionErrorMessageStr);
    ExceptionMessageStr
    = GetTranslatedStr(TourPathSimpleProcessAddActionExceptionMessageStr);
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

