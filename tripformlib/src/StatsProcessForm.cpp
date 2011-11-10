//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrStats

#include "FieldDef.h"
#include "StdTool.h"
#include "TourTool.h"
#include "StatsProcessForm.h"
#include "DataSetViewForm.h"
#include "DataModuleForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TableGridProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma resource "*.dfm"
TTourStatsProcessForm *TourStatsProcessForm;

enum TourRefBookStatsProcessStringTypes
 {
  TourRefBookTripIdStr = TourRefBookProcessStringTypesEnumCount,
  TourRefBookStatsFromStopIdStr,
  TourRefBookStatsToStopIdStr,
  TourRefBookTripIdCaptionStr,
  TourRefBookTripNameCaptionStr,
  TourRefBookTripNotesCaptionStr,
  TourRefBookTripNotExistMessageStr,
  TourRefBookStatsInvalidFlowMessageStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourStatsProcessForm::TTourStatsProcessForm(TComponent* Owner)
 : TTourRefBookTableGridProcessForm(Owner)
 {
  TripIdChangedFlag = false;
 }
//---------------------------------------------------------------------------
void __fastcall TTourStatsProcessForm::FormCloseQuery(
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
      if (TripIdDBEdit->Text.IsEmpty())
       {
        ResultFlag = false;

        TourShowDialogError
        (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                    + GetTranslatedStr(TourRefBookTripIdStr)).c_str());

        TripIdDBEdit->SetFocus();
       }
      else if (!TourCheckTripExist(TripIdDBEdit->Text))
       {
        ResultFlag = false;

        TourShowDialogError
        (GetTranslatedStr(TourRefBookTripNotExistMessageStr).c_str());

        TripIdDBEdit->SetFocus();
        TripIdDBEdit->SelectAll();
       }

      if (ResultFlag)
       {
        if (StatsFromStopIdDBLookupComboBoxExt->Field->IsNull)
         {
          ResultFlag = false;

          TourShowDialogError
          (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                      + GetTranslatedStr(TourRefBookStatsFromStopIdStr)).c_str());

          StatsFromStopIdDBLookupComboBoxExt->SetFocus();
         }
       }
      if (ResultFlag)
       {
        if (StatsToStopIdDBLookupComboBoxExt->Field->IsNull)
         {
          ResultFlag = false;

          TourShowDialogError
          (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                      + GetTranslatedStr(TourRefBookStatsToStopIdStr)).c_str());

          StatsToStopIdDBLookupComboBoxExt->SetFocus();
         }
       }
       
      if (ResultFlag)
       {
        try
         {
          if (StrToInt(StatsFlowDBEdit->Text) < 0)
           {
            ResultFlag = false;

            TourShowDialogError
            (AnsiString(GetTranslatedStr
                        (TourRefBookStatsInvalidFlowMessageStr)).c_str());

            StatsFlowDBEdit->SetFocus();
           }
         }
        catch (...)
         {
          ResultFlag = false;

          TourShowDialogError
          (AnsiString(GetTranslatedStr
                      (TourRefBookStatsInvalidFlowMessageStr)).c_str());

          StatsFlowDBEdit->SetFocus();
         }
       }

      if (ResultFlag)
       {
        TDateTime                      WorkDateTime;

        WorkDateTime  = StatsDatePicker->Date.DateString();
        WorkDateTime += StatsTimePicker->Time.TimeString();

        FMainQueryDataSource->DataSet->FieldByName(StatsDateFieldNameStr)->AsString
        = WorkDateTime.DateTimeString();
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

void __fastcall TTourStatsProcessForm::TripIdButtonClick(TObject *Sender)
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
    = TripDataSource->DataSet;
    LookupDataSetViewFormPtr->DataSourceOrdering->Query
    = dynamic_cast<TADOQuery*>(TripDataSource->DataSet);
    LookupDataSetViewFormPtr->DataSourceOrdering->Active = true;

    ColumnPtr = LookupDataSetViewFormPtr->Grid->Columns->Add();
    ColumnPtr->FieldName = TripNameFieldNameStr;
    ColumnPtr->Title->Caption = GetTranslatedStr(TourRefBookTripNameCaptionStr);
    ColumnPtr = LookupDataSetViewFormPtr->Grid->Columns->Add();
    ColumnPtr->FieldName = TripIdFieldNameStr;
    ColumnPtr->Title->Caption = GetTranslatedStr(TourRefBookTripIdCaptionStr);
    ColumnPtr = LookupDataSetViewFormPtr->Grid->Columns->Add();
    ColumnPtr->FieldName = TripNotesFieldNameStr;
    ColumnPtr->Title->Caption = GetTranslatedStr(TourRefBookTripNotesCaptionStr);

    if (LookupDataSetViewFormPtr->ShowModal() == mrOk)
     {
      FMainQueryDataSource->DataSet->FieldByName(TripIdFieldNameStr)->Value
      = LookupDataSetViewFormPtr
        ->DataSource->DataSet->FieldByName(TripIdFieldNameStr)->Value;
     }

    delete (LookupDataSetViewFormPtr);
    LookupDataSetViewFormPtr = NULL; 
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourStatsProcessForm::TripIdDBEditExit(TObject *Sender)
 {
  OnStatsTripIdFieldChanged();
 }
//---------------------------------------------------------------------------

void     TTourStatsProcessForm::OnStatsFromStopIdFieldChanged
         (TField                                     *Field)
 {
  if (Field != NULL)
   {
    CursorWaitOpen();

    try
     {
      if (Field->FieldName == AnsiString(StatsFromStopIdFieldNameStr))
       {
        if (!Field->AsString.IsEmpty())
         {
          if (FromStopQuery->Active)
           {
            FromStopQuery->Close();
           }

          FromStopQuery->Parameters->ParamByName("trip_id_value")->Value
          = TripIdDBEdit->Text;
          FromStopQuery->Parameters->ParamByName("stop_id_value")->Value
          = Field->AsString;

          FromStopQuery->Open();

          StatsToStopIdDBLookupComboBoxExt->ListSource = FromStopDataSource;
         }
        else
         {
          StatsToStopIdDBLookupComboBoxExt->ListSource = NULL;
         }
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }

    CursorWaitClose();
   }
 }

//---------------------------------------------------------------------------

void     TTourStatsProcessForm::OnStatsTripIdFieldChanged
         (void)
 {
  if ((!TripIdDBEdit->Text.IsEmpty()) && (TripIdChangedFlag))
   {
    CursorWaitOpen();

    try
     {
      if (DirectQuery->Active)
       {
        DirectQuery->Close();
       }

      DirectQuery->Parameters->ParamByName("trip_id_value")->Value
      = TripIdDBEdit->Text;

      DirectQuery->Open();

      if (!DirectQuery->IsEmpty())
       {
        StatsFromStopIdDBLookupComboBoxExt->ListSource = DirectDataSource;
       }
      else
       {
        StatsFromStopIdDBLookupComboBoxExt->ListSource = NULL;
       }

      StatsToStopIdDBLookupComboBoxExt->ListSource   = NULL;
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }

    CursorWaitClose();
   }
 }

//---------------------------------------------------------------------------

void __fastcall TTourStatsProcessForm::FMainQueryDataSourceDataChange(
      TObject *Sender, TField *Field)
 {
  OnStatsFromStopIdFieldChanged(Field);

  if (Field != NULL)
   {
    try
     {
      if (Field->FieldName == AnsiString(StatsFromStopIdFieldNameStr))
       {
        FMainQueryDataSource
        ->DataSet->FieldByName(StatsToStopIdFieldNameStr)->Clear();
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourStatsProcessForm::TripIdDBEditChange(TObject *Sender)
 {
  TripIdChangedFlag = true;
 }
//---------------------------------------------------------------------------

void __fastcall TTourStatsProcessForm::TripIdDBEditEnter(TObject *Sender)
 {
  TripIdChangedFlag = false;
 }
//---------------------------------------------------------------------------

#undef   GetTranslatedStr(Index)

