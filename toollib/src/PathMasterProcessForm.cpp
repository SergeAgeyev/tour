//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FieldDef.h"
#include "StdTool.h"
#include "TourTool.h"
#include "PathMasterProcessForm.h"
#include "DataSetViewForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VDBLookupComboBox"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourPathMasterProcessForm *TourPathMasterProcessForm;

enum TourPathMasterProcessStringTypes
 {
  TourPathMasterProcessInputFieldMessageStr = 0,
  TourPathMasterProcessPathFromStopIdStr,
  TourPathMasterProcessPathToStopIdStr,
  TourPathMasterProcessInvalidStopFromMessageStr,
  TourPathMasterProcessInvalidStopToMessageStr,
  TourPathMasterProcessPathInvalidNormSpeedMessageStr,
  TourPathMasterProcessPathInvalidLengthMessageStr,
  TourPathMasterProcessStopIdCaptionStr,
  TourPathMasterProcessStopNameCaptionStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourPathMasterProcessForm::TTourPathMasterProcessForm(TComponent* Owner)
        : TForm(Owner)
 {
  FStopSelectMode = true;
 }

//---------------------------------------------------------------------------
void __fastcall TTourPathMasterProcessForm::FormCreate(TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    if (StopQuery->Active)
     {
      StopQuery->Close();
     }
    if (!StopQuery->Active)
     {
      StopQuery->Open();
     }
   }
  catch (...)
   {
    //
   }

  CursorWaitClose();
 }
//---------------------------------------------------------------------------
void __fastcall TTourPathMasterProcessForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  CursorWaitOpen();

  try
   {
    if (StopQuery->Active)
     {
      StopQuery->Close();
     }
   }
  catch (...)
   {
    //
   }

  CursorWaitClose();

  Action = caHide;
 }
//---------------------------------------------------------------------------
void __fastcall TTourPathMasterProcessForm::FormCloseQuery(TObject *Sender,
      bool &CanClose)
 {
  bool                                 ResultFlag;

  ResultFlag = true;
  CanClose = false;
  FunctionArgUsedSkip(Sender);

  if (ModalResult == mrOk)
   {
    if (StopFromIdStr.IsEmpty())
     {
      ResultFlag = false;

      TourShowDialogError
      (AnsiString(GetTranslatedStr(TourPathMasterProcessInputFieldMessageStr)
                  + GetTranslatedStr(TourPathMasterProcessPathFromStopIdStr)).c_str());

      StopFromButton->SetFocus();
     }
    else if (!TourCheckStopExist(StopFromIdStr))
     {
      ResultFlag = false;

      TourShowDialogError
      (AnsiString
       (GetTranslatedStr(TourPathMasterProcessInvalidStopFromMessageStr)).c_str());
      StopFromButton->SetFocus();
     }

    if (ResultFlag)
     {
      if (StopToIdStr.IsEmpty())
       {
        ResultFlag = false;

        TourShowDialogError
        (AnsiString(GetTranslatedStr(TourPathMasterProcessInputFieldMessageStr)
                    + GetTranslatedStr(TourPathMasterProcessPathToStopIdStr)).c_str());

        StopToButton->SetFocus();
       }
      else if (!TourCheckStopExist(StopToIdStr))
       {
        ResultFlag = false;

        TourShowDialogError
        (AnsiString
         (GetTranslatedStr(TourPathMasterProcessInvalidStopToMessageStr)).c_str());
        StopToButton->SetFocus();
       }
     }

    if (ResultFlag)
     {
      if (!PathNormSpeedEdit->Text.IsEmpty())
       {
        try
         {
          if (StrToFloat(PathNormSpeedEdit->Text) < 0)
           {
            ResultFlag = false;

            TourShowDialogError
            (AnsiString(GetTranslatedStr
                        (TourPathMasterProcessPathInvalidNormSpeedMessageStr)).c_str());

            PathNormSpeedEdit->SetFocus();
           }
         }
        catch (...)
         {
          ResultFlag = false;

          TourShowDialogError
          (AnsiString(GetTranslatedStr
                      (TourPathMasterProcessPathInvalidNormSpeedMessageStr)).c_str());

          PathNormSpeedEdit->SetFocus();
         }
       }
     }

    if (ResultFlag)
     {
      if (!PathLengthEdit->Text.IsEmpty())
       {
        try
         {
          if (StrToFloat(PathLengthEdit->Text) < 0)
           {
            ResultFlag = false;

            TourShowDialogError
            (AnsiString(GetTranslatedStr
                        (TourPathMasterProcessPathInvalidLengthMessageStr)).c_str());

            PathLengthEdit->SetFocus();
           }
         }
        catch (...)
         {
          ResultFlag = false;

          TourShowDialogError
          (AnsiString(GetTranslatedStr
                      (TourPathMasterProcessPathInvalidLengthMessageStr)).c_str());

          PathLengthEdit->SetFocus();
         }
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
//---------------------------------------------------------------------------
bool               TTourPathMasterProcessForm::StopSelectDialog
                   (AnsiString                       *StopIdStrPtr,
                    AnsiString                       *StopNameStrPtr)
 {
  TTourDataSetViewForm                *LookupDataSetViewFormPtr;
  TColumn                             *ColumnPtr;
  bool                                 ResultFlag;

  LookupDataSetViewFormPtr = NULL;
  ColumnPtr = NULL;
  ResultFlag = false;

  LookupDataSetViewFormPtr = new TTourDataSetViewForm(this);

  if (LookupDataSetViewFormPtr != NULL)
   {
    LookupDataSetViewFormPtr->DataSource->DataSet
    = StopDataSource->DataSet;
    LookupDataSetViewFormPtr->DataSourceOrdering->Query
    = dynamic_cast<TADOQuery*>(StopDataSource->DataSet);
    LookupDataSetViewFormPtr->DataSourceOrdering->Active = true;

    ColumnPtr = LookupDataSetViewFormPtr->Grid->Columns->Add();
    ColumnPtr->FieldName = StopIdFieldNameStr;
    ColumnPtr->Title->Caption
    = GetTranslatedStr(TourPathMasterProcessStopIdCaptionStr);
    ColumnPtr = LookupDataSetViewFormPtr->Grid->Columns->Add();
    ColumnPtr->FieldName = StopNameFieldNameStr;
    ColumnPtr->Title->Caption
    = GetTranslatedStr(TourPathMasterProcessStopNameCaptionStr);

    if (LookupDataSetViewFormPtr->ShowModal() == mrOk)
     {
      *StopIdStrPtr
      = LookupDataSetViewFormPtr
        ->DataSource->DataSet->FieldByName(StopIdFieldNameStr)->Value;
      *StopNameStrPtr
      = LookupDataSetViewFormPtr
        ->DataSource->DataSet->FieldByName(StopNameFieldNameStr)->Value;
      ResultFlag = true;
     }

    delete (LookupDataSetViewFormPtr);
    LookupDataSetViewFormPtr = NULL;
   }
  return (ResultFlag);
 }
//---------------------------------------------------------------------------

void __fastcall TTourPathMasterProcessForm::StopFromButtonClick(
      TObject *Sender)
 {
  AnsiString                           StopIdStr;
  AnsiString                           StopNameStr;

  if (StopSelectDialog(&StopIdStr,&StopNameStr))
   {
    StopFromIdStr      = StopIdStr;
    StopFromEdit->Text = StopNameStr;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourPathMasterProcessForm::StopToButtonClick(TObject *Sender)
 {
  AnsiString                           StopIdStr;
  AnsiString                           StopNameStr;

  if (StopSelectDialog(&StopIdStr,&StopNameStr))
   {
    StopToIdStr      = StopIdStr;
    StopToEdit->Text = StopNameStr;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourPathMasterProcessForm::SetStopIdFrom(AnsiString value)
 {
  if (value != StopFromIdStr)
   {
    AnsiString                         StopName;

    StopFromIdStr = value;

    if (!TourGetStopNameById(value,&StopName))
     {
      StopName = "";
     }
    StopFromEdit->Text = StopName;
   }
 }

AnsiString __fastcall TTourPathMasterProcessForm::GetStopIdFrom()
 {
  return StopFromIdStr;
 }

void __fastcall TTourPathMasterProcessForm::SetStopIdTo(AnsiString value)
 {
  if (value != StopToIdStr)
   {
    AnsiString                         StopName;

    StopToIdStr = value;

    if (!TourGetStopNameById(value,&StopName))
     {
      StopName = "";
     }

    StopToEdit->Text = StopName;
   }
 }

AnsiString __fastcall TTourPathMasterProcessForm::GetStopIdTo()
 {
  return StopToIdStr;
 }

void __fastcall TTourPathMasterProcessForm::SetStopSelectMode(bool value)
 {
  if (FStopSelectMode != value)
   {
    FStopSelectMode = value;

    StopFromButton->Visible = FStopSelectMode;
    StopToButton->Visible   = FStopSelectMode;
//    StopFromEdit->Enabled   = FStopSelectMode;
//    StopToEdit->Enabled     = FStopSelectMode;
   }
 }

bool __fastcall TTourPathMasterProcessForm::GetStopSelectMode()
 {
  return FStopSelectMode;
 }
