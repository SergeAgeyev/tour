//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FieldDef.h"
#include "StdTool.h"
#include "TourTool.h"
#include "StopProcessForm.h"
#include "DataSetViewForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TableGridProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma resource "*.dfm"
TTourRefBookStopProcessForm *TourRefBookStopProcessForm;

enum TourRefBookStopProcessStringTypes
 {
  TourRefBookStopIdStr = TourRefBookProcessStringTypesEnumCount,
  TourRefBookCityZIPStr,
  TourRefBookCityZIPCaptionStr,
  TourRefBookCityNameCaptionStr,
  TourRefBookCityNotExistMessageStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookStopProcessForm::TTourRefBookStopProcessForm(TComponent* Owner)
 : TTourRefBookTableGridProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourRefBookStopProcessForm::FormCloseQuery(
      TObject *Sender, bool &CanClose)
 {
  Boolean                              ResultFlag;
  bool                                 LookupComboBoxActiveFlag;
  TDBLookupComboBoxExt                *LookupComboBoxPtr;

  LookupComboBoxActiveFlag = false;
  ResultFlag = true;
  CanClose = false;
  FunctionArgUsedSkip(Sender);
  FunctionArgUsedSkip(LookupComboBoxPtr);

  LookupComboBoxPtr = NULL;
  LookupComboBoxPtr = dynamic_cast<TDBLookupComboBoxExt*>(ActiveControl);

  if (LookupComboBoxPtr != NULL)
   {
    if (LookupComboBoxPtr->ListVisible)
     {
      LookupComboBoxPtr->CloseUp(true);
      LookupComboBoxActiveFlag = true;
     }
   }

  if (!LookupComboBoxActiveFlag)
   {
    if (ModalResult == mrOk)
     {
      if (StopIdDBEdit->Text.IsEmpty())
       {
        ResultFlag = false;

        TourShowDialogError
        (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                    + GetTranslatedStr(TourRefBookStopIdStr)).c_str());

        StopIdDBEdit->SetFocus();
       }

      if (ResultFlag)
       {
        if (CityZIPDBEdit->Text.IsEmpty())
         {
          ResultFlag = false;

          TourShowDialogError
          (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                      + GetTranslatedStr(TourRefBookCityZIPStr)).c_str());

          CityZIPDBEdit->SetFocus();
         }
        else if (!TourCheckCityExist(CityZIPDBEdit->Text))
         {
          ResultFlag = false;
          
          TourShowDialogError
          (GetTranslatedStr(TourRefBookCityNotExistMessageStr).c_str());

          CityZIPDBEdit->SetFocus();
          CityZIPDBEdit->SelectAll();
         }
       }

      if (ResultFlag)
       {
        CanClose = true;
       }
     }
    else
     {
      CanClose = true;
     }
   }
  else
   {
    CanClose = false;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourRefBookStopProcessForm::CityZIPButtonClick(
      TObject *Sender)
 {
  TTourDataSetViewForm                *LookupDataSetViewFormPtr;
  TColumn                             *ColumnPtr;

  FunctionArgUsedSkip(Sender);
  LookupDataSetViewFormPtr = NULL;
  ColumnPtr = NULL;

  LookupDataSetViewFormPtr = new TTourDataSetViewForm(this);

  if (LookupDataSetViewFormPtr != NULL)
   {
    LookupDataSetViewFormPtr->DataSource->DataSet
    = CityDataSource->DataSet;
    LookupDataSetViewFormPtr->DataSourceOrdering->Query
    = dynamic_cast<TADOQuery*>(CityDataSource->DataSet);
    LookupDataSetViewFormPtr->DataSourceOrdering->Active = true;

    ColumnPtr = LookupDataSetViewFormPtr->Grid->Columns->Add();
    ColumnPtr->FieldName = CityZIPFieldNameStr;
    ColumnPtr->Title->Caption = GetTranslatedStr(TourRefBookCityZIPCaptionStr);
    ColumnPtr = LookupDataSetViewFormPtr->Grid->Columns->Add();
    ColumnPtr->FieldName = CityNameFieldNameStr;
    ColumnPtr->Title->Caption = GetTranslatedStr(TourRefBookCityNameCaptionStr);

    if (LookupDataSetViewFormPtr->ShowModal() == mrOk)
     {
      FMainQueryDataSource->DataSet->FieldByName(CityZIPFieldNameStr)->Value
      = LookupDataSetViewFormPtr
        ->DataSource->DataSet->FieldByName(CityZIPFieldNameStr)->Value;
     }

    delete (LookupDataSetViewFormPtr);
    LookupDataSetViewFormPtr = NULL;
   }
 }
//---------------------------------------------------------------------------

#undef   GetTranslatedStr(Index)


