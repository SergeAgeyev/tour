//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <math.h>

#include "FieldDef.h"
#include "StdTool.h"
#include "TourTool.h"
#include "DataModuleForm.h"
#include "DataSetViewForm.h"
#include "TripStepWizardForm.h"
#include "TripStepDataTimeInfoForm.h"
#include "TourConst.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TripWizardProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourTripStepWizardForm *TourTripStepWizardForm;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]
#define  TripStepWizardMinutesInHour   60
#define  TripStepWizardDotSymbolStr    "."
#define  TripStepWizardEqualSymbolStr  "="

static char  *(TourTripStepWizardDataTimeInfoWaitCodesArray[])
               = {"","0","5","","10","15","20"};

//---------------------------------------------------------------------------
__fastcall TTourTripStepWizardForm::TTourTripStepWizardForm(TComponent* Owner)
 : TTourTripWizardProcessForm(Owner)
 {
//  CurrentTripIdStr = "";

  CursorWaitOpen();

  try
   {
    if (!StopQuery->Active)
     {
      FromAvailableQuery->Open();
     }
    if (!StopQuery->Active)
     {
      StopQuery->Open();
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();

  FillAvailableStrStore();
 }
//---------------------------------------------------------------------------

void               TTourTripStepWizardForm::FillAvailableStrStore
                   (void)
 {
  TADOQuery                           *QueryPtr;
  TripStepWizardItemType               StrStoreItem;

  QueryPtr = NULL;

  CursorWaitOpen();

  try
   {
    if (ChainStrStore.size() > 0)
     {
      QueryPtr = ToAvailableQuery;

      if (QueryPtr->Active)
       {
        QueryPtr->Close();
       }

      QueryPtr->Parameters->ParamByName("fromstop_id")->Value
      = ChainStrStore[ChainStrStore.size() - 1].StopIdStr;

      QueryPtr->Open();
     }
    else
     {
      QueryPtr = FromAvailableQuery;
     }

    QueryPtr->First();

    AvailableStrStore.clear();

    for (int RecordIndex = 0;
         RecordIndex < QueryPtr->RecordCount;
         RecordIndex++)
     {
      StrStoreItem.StopIdStr = QueryPtr->FieldByName(StopIdFieldNameStr)->AsString;

      AvailableStrStore.push_back(StrStoreItem);

      QueryPtr->Next();
     }
    FillAvailableListView();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();
 }
//---------------------------------------------------------------------------

void               TTourTripStepWizardForm::FillAvailableListView
                   (void)
 {
  TListItem                           *ListItemPtr;
  TripStepWizardItemStoreVectorType::iterator
                                       StringVectorIterator;
  AnsiString                           StopNameStr;

  AvailableListView->Items->Clear();

  for (StringVectorIterator = AvailableStrStore.begin();
       StringVectorIterator != AvailableStrStore.end();
       StringVectorIterator++)
   {
    ListItemPtr = AvailableListView->Items->Add();

    if (ListItemPtr != NULL)
     {
      ListItemPtr->Caption = StringVectorIterator->StopIdStr;

      if (GetStopNameByStopId(ListItemPtr->Caption,&StopNameStr))
       {
        ListItemPtr->SubItems->Append(StopNameStr);
       }
     }
   }

  if (TourDataModule->DataBaseEditModeFlag)
   {
    if (AvailableStrStore.size() > 0)
     {
      AddButton->Visible = true;
     }
    else
     {
      AddButton->Visible = false;
     }

    if (ChainStrStore.size() > 0)
     {
      DeleteButton->Visible = true;
     }
    else
     {
      DeleteButton->Visible = false;
     }
   }
 }

//---------------------------------------------------------------------------

bool               TTourTripStepWizardForm::FillChainStrStoreByTrip
                   (AnsiString                        TripIdStr)
 {
  int                                  RecordIndex;
  TripStepWizardItemType               StrStoreItem;
  bool                                 ResultFlag;

  ResultFlag = true;

  CursorWaitOpen();

  try
   {
//    this->CurrentTripIdStr = TripIdStr;

    TripStepQuery->Parameters->ParamByName("trip_id_value")->Value = TripIdStr;

    TripStepQuery->Open();

    if (TripStepQuery->Active)
     {
      TripStepQuery->First();

      ChainStrStore.clear();

      if (TripStepQuery->RecordCount > 0)
       {
        for (RecordIndex = 0;
             ((RecordIndex < TripStepQuery->RecordCount) && (ResultFlag));
             RecordIndex++)
         {
          StrStoreItem.StopIdStr
          = TripStepQuery->FieldByName(StopIdFieldNameStr)->AsString;

          if (GetTripStepInfoByStepNum
              ( /*Current*/TripIdStr,
                RecordIndex,
               &StrStoreItem.TripStepInTimeStr,
               &StrStoreItem.TripStepWaitTimeStr))
           {
            ChainStrStore.push_back(StrStoreItem);

            TripStepQuery->Next();
           }
          else
           {
            ResultFlag = false;
           }
         }

//        TripStepQuery->Last();
//
//        StopChainStrStore
//        .push_back((TripStepQuery->FieldByName("path_tostopid")->AsString).c_str());

       }

      if (ResultFlag)
       {
        FillChainListViewByStrStore();
        FillAvailableStrStore();
       }

      TripStepQuery->Close();
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
    ResultFlag = false;
   }

  CursorWaitClose();

  return (ResultFlag);
 }

//---------------------------------------------------------------------------

void               TTourTripStepWizardForm::FillChainListViewByStrStore
                   (void)
 {
  TListItem                           *ListItemPtr;
  TripStepWizardItemStoreVectorType::iterator
                                       StringVectorIterator;
  AnsiString                           StopNameStr;

  ChainListView->Items->Clear();

  for (StringVectorIterator = ChainStrStore.begin();
       StringVectorIterator != ChainStrStore.end();
       StringVectorIterator++)
   {
    ListItemPtr = ChainListView->Items->Add();

    if (ListItemPtr != NULL)
     {
      ListItemPtr->Caption = StringVectorIterator->StopIdStr;

      if (GetStopNameByStopId(ListItemPtr->Caption,&StopNameStr))
       {
        ListItemPtr->SubItems->Append(StopNameStr);
        ListItemPtr->SubItems->Append(StringVectorIterator->TripStepInTimeStr);
        ListItemPtr->SubItems->Append(StringVectorIterator->TripStepWaitTimeStr);
       }
     }
   }
 }

//---------------------------------------------------------------------------


bool               TTourTripStepWizardForm::ChainStrStoreAppendItem
                   (TripStepWizardItemType            Item)
 {
  bool                                 ResultFlag;

  ResultFlag = true;

  if (ResultFlag)
   {
    ChainStrStore.push_back(Item);
    ChainListViewAppendItem(Item);
   }

  return (ResultFlag);
 }

//---------------------------------------------------------------------------

void               TTourTripStepWizardForm::ChainListViewAppendItem
                   (TripStepWizardItemType            Item)
 {
  TListItem                           *ListItemPtr;
  AnsiString                           StopNameStr;

  ListItemPtr = NULL;

  ListItemPtr = ChainListView->Items->Add();

  if (ListItemPtr != NULL)
   {
    ListItemPtr->Caption = Item.StopIdStr;

    if (GetStopNameByStopId(Item.StopIdStr,&StopNameStr))
     {
      ListItemPtr->SubItems->Append(StopNameStr);
      ListItemPtr->SubItems->Append(Item.TripStepInTimeStr);
      ListItemPtr->SubItems->Append(Item.TripStepWaitTimeStr);
     }
   }
 }

//---------------------------------------------------------------------------

void               TTourTripStepWizardForm::ChainStrStoreDeleteItem
                   (void)
 {
  if (ChainStrStore.size() > 0)
   {
    ChainStrStore.pop_back();
    ChainListViewDeleteItem();
   }
 }

//---------------------------------------------------------------------------

void               TTourTripStepWizardForm::ChainListViewDeleteItem
                   (void)
 {
  if (ChainListView->Items->Count > 0)
   {
    ChainListView->Items->Delete(ChainListView->Items->Count - 1);
   }
 }

//---------------------------------------------------------------------------

void __fastcall TTourTripStepWizardForm::ChainDeleteItemActionExecute(
      TObject *Sender)
 {
  if (ChainListView->Items->Count > 0)
   {
    // Базового пункта нет
/*
    BasicTripExistFlag = false;
*/
    ChainStrStoreDeleteItem();

    FillAvailableStrStore();
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripStepWizardForm::AvailableAddActionExecute(
      TObject *Sender)
 {
  TripStepWizardItemType               StrStoreItem;
  TTourTripStepDataTimeInfoForm       *InfoDialogPtr;
  TDateTime                            PreliminaryTime;

  FunctionArgUsedSkip(Sender);
  InfoDialogPtr = NULL;

  if (TourDataModule->DataBaseEditModeFlag)
   {
    try
     {
      Application->CreateForm(__classid(TTourTripStepDataTimeInfoForm),
                              &InfoDialogPtr);

      if (InfoDialogPtr != NULL)
       {
        if (AvailableListView->Selected != NULL)
         {
          StrStoreItem.StopIdStr = AvailableListView->Selected->Caption;

          // Предварительный расчет времени прибытия

          if (!ChainStrStore.empty())
           {
            PreliminaryTime
            = TDateTime((ChainStrStore.back()).TripStepInTimeStr,TDateTime::Time);

            if (!(ChainStrStore.back()).TripStepWaitTimeStr.IsEmpty())
             {
              PreliminaryTime +=
              TDateTime((ChainStrStore.back()).TripStepWaitTimeStr,TDateTime::Time);
             }

            PreliminaryTime
            += GetPreliminaryTimeIn
               (AnsiString((ChainStrStore.back()).StopIdStr),StrStoreItem.StopIdStr);
            InfoDialogPtr->TimeInPicker->/*Date*/Time = PreliminaryTime;
           }

          if (InfoDialogPtr->ShowModal() == mrOk)
           {
            // Базового пункта нет
/*
            BasicTripExistFlag = false;
*/
            // Занесение информации о времени прибытия и стоянки
            StrStoreItem.TripStepInTimeStr
            = InfoDialogPtr->TimeInPicker->/*Date*/Time.TimeString();

            if (InfoDialogPtr->WaitTimeRadioGroup->ItemIndex ==
                TourTripStepDataTimeInfoWaitTimeNoEntryCode)
             {
              StrStoreItem.TripStepWaitTimeStr = "";
             }
            else if (InfoDialogPtr->WaitTimeRadioGroup->ItemIndex ==
                     TourTripStepDataTimeInfoWaitTimeUserWaitCode)
             {
              StrStoreItem.TripStepWaitTimeStr
              = InfoDialogPtr->TimeWaitPicker->/*Date*/Time.TimeString();
             }
            else
             {
              StrStoreItem.TripStepWaitTimeStr
              = DateTimeInfoWaitValueByCode
                (InfoDialogPtr->WaitTimeRadioGroup->ItemIndex);
             }

            // Добавление пункта в маршрут
            ChainStrStoreAppendItem(StrStoreItem);

            FillAvailableStrStore();
           }

          AvailableListView->SetFocus();

          if (AvailableListView->Items->Count > 0)
           {
            AvailableListView->Selected = AvailableListView->Items->Item[0];
           }

          delete (InfoDialogPtr);
          InfoDialogPtr = NULL;
         }
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripStepWizardForm::SelectActionExecute(
      TObject *Sender)
 {
  TTourDataSetViewForm                *LookupDataSetViewFormPtr;
  TColumn                             *ColumnPtr;

  FunctionArgUsedSkip(Sender);
  LookupDataSetViewFormPtr = NULL;
  ColumnPtr = NULL;

  CursorWaitOpen();

  try
   {
    if (!TripQuery->Active)
     {
      TripQuery->Open();
     }

    LookupDataSetViewFormPtr = new TTourDataSetViewForm(this);

    if (LookupDataSetViewFormPtr != NULL)
     {
      LookupDataSetViewFormPtr->Caption
      = GetTranslatedStr(TourTripWizardTripSelectCaptionStr);
      LookupDataSetViewFormPtr->DataSource->DataSet        = TripQuery;
      LookupDataSetViewFormPtr->DataSourceOrdering->Query  = TripQuery;
      LookupDataSetViewFormPtr->DataSourceOrdering->Active = true;

      ColumnPtr = LookupDataSetViewFormPtr->Grid->Columns->Add();
      ColumnPtr->FieldName = TripNameFieldNameStr;
      ColumnPtr->Title->Caption = GetTranslatedStr(TourTripStepWizardTripNameCaptionStr);
      ColumnPtr = LookupDataSetViewFormPtr->Grid->Columns->Add();
      ColumnPtr->FieldName = TripIdFieldNameStr;
      ColumnPtr->Title->Caption = GetTranslatedStr(TourTripStepWizardTripIdCaptionStr);
      ColumnPtr = LookupDataSetViewFormPtr->Grid->Columns->Add();
      ColumnPtr->FieldName = TripNotesFieldNameStr;
      ColumnPtr->Title->Caption = GetTranslatedStr(TourTripStepWizardTripNotesCaptionStr);

      if (LookupDataSetViewFormPtr->ShowModal() == mrOk)
       {
        // Базовый пункт существует
/*
        BasicTripExistFlag = true;
*/
        AnsiString                     TripIdStr;

        TripIdStr
        = LookupDataSetViewFormPtr
          ->DataSource->DataSet->FieldByName(TripIdFieldNameStr)->AsString;
        FillChainStrStoreByTrip(TripIdStr);

       }

      delete (LookupDataSetViewFormPtr);
      LookupDataSetViewFormPtr = NULL; 
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();
 }
//---------------------------------------------------------------------------

bool               TTourTripStepWizardForm::GetStopNameByStopId
                   (AnsiString                        StopIdStr,
                    AnsiString                       *StopNameStrPtr)
 {

  bool                                 ResultFlag;
  TLocateOptions                       LocateOptions;

  LocateOptions.Clear();
  LocateOptions << loCaseInsensitive;
  ResultFlag = false;

  if (StopQuery->Active)
   {
    if (StopQuery->Locate(StopIdFieldNameStr,Variant(StopIdStr),LocateOptions))
     {
      *StopNameStrPtr = StopQuery->FieldByName(StopNameFieldNameStr)->AsString;

      ResultFlag = true;
     }
   }

  return (ResultFlag);
 }
//---------------------------------------------------------------------------

bool               TTourTripStepWizardForm::GetTripStepInfoByStepNum
                   (AnsiString                        TripIdStr,
                    AnsiString                        StepNumStr,
                    AnsiString                       *StepInTimeStrPtr,
                    AnsiString                       *StepWaitTimeStrPtr)
 {
  bool                                 ResultFlag;
  TLocateOptions                       LocateOptions;

  LocateOptions.Clear();
  LocateOptions << loCaseInsensitive;
  ResultFlag = false;

  CursorWaitOpen();

  try
   {
    if (TripStepInfoQuery->Active)
     {
      TripStepInfoQuery->Close();
     }

    TripStepInfoQuery->Parameters->ParamByName("trip_id_value")->Value
    = /*this->Current*/TripIdStr;
    TripStepInfoQuery->Parameters->ParamByName("tripstep_num_value")->Value
    = StrToInt(StepNumStr);

    TripStepInfoQuery->Open();

    if (!TripStepInfoQuery->FieldByName(TripStepInTimeFieldNameStr)->IsNull)
     {
      *StepInTimeStrPtr
      = TripStepInfoQuery->FieldByName(TripStepInTimeFieldNameStr)->AsDateTime.TimeString();
     }
    else
     {
      *StepInTimeStrPtr = "";
     }

    if (!TripStepInfoQuery->FieldByName(TripStepWaitTimeFieldNameStr)->IsNull)
     {
      *StepWaitTimeStrPtr
      = TripStepInfoQuery->FieldByName(TripStepWaitTimeFieldNameStr)->AsDateTime.TimeString();
     }
    else
     {
      *StepWaitTimeStrPtr = "";
     }

    TripStepInfoQuery->Close();

    ResultFlag = true;
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
    ResultFlag = false;
   }

  CursorWaitClose();

  return (ResultFlag);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripStepWizardForm::ChainPopupMenuPopup(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  if (ChainStrStore.size() > 0)
   {
    DeleteMenuItem->Enabled = true;

    if (ChainListView->Selected != NULL)
     {
      ChangeMenuItem->Enabled = true;
     }
    else
     {
      ChangeMenuItem->Enabled = false;
     }
   }
  else
   {
    DeleteMenuItem->Enabled = false;
    ChangeMenuItem->Enabled = false;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripStepWizardForm::AvailablePopupMenuPopup(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  if ((AvailableStrStore.size() > 0) &&
      (AvailableListView->Selected != NULL))
   {
    AddMenuItem->Enabled    = true;
   }
  else
   {
    AddMenuItem->Enabled    = false;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripStepWizardForm::TripStepEditActionExecute(
      TObject *Sender)
 {
  TTourTripStepDataTimeInfoForm       *InfoDialogPtr;
  AnsiString                           WaitTimeStr;

  FunctionArgUsedSkip(Sender);
  InfoDialogPtr = NULL;

  if (TourDataModule->DataBaseEditModeFlag)
   {
    try
     {
      Application->CreateForm(__classid(TTourTripStepDataTimeInfoForm),
                              &InfoDialogPtr);

      if (InfoDialogPtr != NULL)
       {
        if (ChainListView->Selected != NULL)
         {
          InfoDialogPtr->TimeInPicker->Time
          = TDateTime(ChainListView->Selected->SubItems->Strings[1],TDateTime::Time);

          InfoDialogPtr->WaitTimeRadioGroup->ItemIndex
          = DateTimeInfoWaitCodeByValue
            (ChainListView->Selected->SubItems->Strings[2].c_str());

          if (InfoDialogPtr->WaitTimeRadioGroup->ItemIndex ==
              TourTripStepDataTimeInfoWaitTimeUserWaitCode)
           {
            InfoDialogPtr->TimeWaitPicker->Time
            = TDateTime(ChainListView->Selected->SubItems->Strings[2],TDateTime::Time);
           }

          if (InfoDialogPtr->ShowModal() == mrOk)
           {
            ChainStrStore[ChainListView->Selected->Index].TripStepInTimeStr
            = InfoDialogPtr->TimeInPicker->/*Date*/Time.TimeString();
            ChainListView->Selected->SubItems->Strings[1]
            = InfoDialogPtr->TimeInPicker->/*Date*/Time.TimeString();

            if (InfoDialogPtr->WaitTimeRadioGroup->ItemIndex ==
                TourTripStepDataTimeInfoWaitTimeNoEntryCode)
             {
              ChainStrStore[ChainListView->Selected->Index].TripStepWaitTimeStr = "";
              ChainListView->Selected->SubItems->Strings[2] = "";
             }
            else if (InfoDialogPtr->WaitTimeRadioGroup->ItemIndex ==
                     TourTripStepDataTimeInfoWaitTimeUserWaitCode)
             {
              ChainStrStore[ChainListView->Selected->Index].TripStepWaitTimeStr
              = InfoDialogPtr->TimeWaitPicker->/*Date*/Time.TimeString();
              ChainListView->Selected->SubItems->Strings[2]
              = InfoDialogPtr->TimeWaitPicker->/*Date*/Time.TimeString();
             }
            else
             {
              ChainStrStore[ChainListView->Selected->Index].TripStepWaitTimeStr
              = DateTimeInfoWaitValueByCode
                (InfoDialogPtr->WaitTimeRadioGroup->ItemIndex);
              ChainListView->Selected->SubItems->Strings[2]
              = DateTimeInfoWaitValueByCode
                (InfoDialogPtr->WaitTimeRadioGroup->ItemIndex);
             }
           }
         }
/*
        BasicTripExistFlag = false;
*/
        delete (InfoDialogPtr);
        InfoDialogPtr = NULL;
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripStepWizardForm::SaveActionExecute(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  UpdateTripStepTable(CurrentTripIdStr,&ChainStrStore);
  //
 }
//---------------------------------------------------------------------------

bool               TTourTripStepWizardForm::UpdateTripStepTable
                   (AnsiString                        TripIdStr,
                    TripStepWizardItemStoreVectorType
                                                     *TripStepStrStorePtr)
 {
  bool                                 ResultFlag;
  TripStepWizardItemStoreVectorType::iterator
                                       StringVectorIterator;
  int                                  TripStepNum;
  AnsiString                           PathToStopId;
//  AnsiString                           FirstStopNameStr;
//  AnsiString                           LastStopNameStr;

  ResultFlag = true;
  TripStepNum = 0;
//  FirstStopNameStr = "";
//  LastStopNameStr  = "";

  CursorWaitOpen();
  TourDataModule->TourDataBaseConnection->BeginTrans();

  try
   {
    // Удаление старого расписания
    TripStepClearQuery->Parameters->ParamByName("trip_id_value")->Value = TripIdStr;

    TripStepClearQuery->ExecSQL();

    // Ввод нового расписания
    TripStepQuery->Parameters->ParamByName("trip_id_value")->Value = TripIdStr;


    TripStepQuery->Open();

    if (TripStepQuery->Active)
     {
      try
       {
        TripStepQuery->Edit();

        StringVectorIterator = TripStepStrStorePtr->begin();

        for (StringVectorIterator;
             StringVectorIterator != TripStepStrStorePtr->end();
             StringVectorIterator++)
         {
          StringVectorIterator++;
          if (StringVectorIterator != TripStepStrStorePtr->end())
           {
            PathToStopId = StringVectorIterator->StopIdStr;
           }
          else
           {
            PathToStopId = "";
           }

          StringVectorIterator--;

          TripStepQuery->Append();

          TripStepQuery->FieldByName(TripIdFieldNameStr)->AsString = TripIdStr;
          TripStepQuery->FieldByName(TripStepNumFieldNameStr)->AsInteger = TripStepNum;
          TripStepQuery->FieldByName(StopIdFieldNameStr)->AsString
          = StringVectorIterator->StopIdStr;

          if (!PathToStopId.IsEmpty())
           {
            TripStepQuery->FieldByName(PathToStopIdFieldNameStr)->AsString = PathToStopId;
           }
          if (!StringVectorIterator->TripStepInTimeStr.IsEmpty())
           {
            TripStepQuery->FieldByName(TripStepInTimeFieldNameStr)->AsDateTime
            = TDateTime(StringVectorIterator->TripStepInTimeStr,TDateTime::Time);
           }
          if (!StringVectorIterator->TripStepWaitTimeStr.IsEmpty())
           {
            TripStepQuery->FieldByName(TripStepWaitTimeFieldNameStr)->AsDateTime
            = TDateTime(StringVectorIterator->TripStepWaitTimeStr,TDateTime::Time);
           }

          TripStepNum++;
         }

        if (TripStepQuery->Modified)
         {
          TripStepQuery->Post();
         }
        TourDataModule->TourDataBaseConnection->CommitTrans();
       }
      catch (Exception &exception)
       {
//        TourShowDialogException(NULL,&exception);
//        ResultFlag = false;
        TripStepQuery->Cancel();
        throw exception;
       }
     }
    else
     {
      TourDataModule->TourDataBaseConnection->RollbackTrans();
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
    TourDataModule->TourDataBaseConnection->RollbackTrans();
    ResultFlag = false;
   }

  if (TripStepQuery->Active)
   {
    TripStepQuery->Close();
   }

  CursorWaitClose();

  return (ResultFlag);
 }

bool               TTourTripStepWizardForm::UpdateTripStepTableLow
                   (AnsiString                        TripIdStr,
                    TripStepWizardItemStoreVectorType
                                                     *TripStepStrStorePtr)
 {
  bool                                 ResultFlag;
  TripStepWizardItemStoreVectorType::iterator
                                       StringVectorIterator;
  int                                  TripStepNum;
  AnsiString                           PathToStopId;
//  AnsiString                           FirstStopNameStr;
//  AnsiString                           LastStopNameStr;

  ResultFlag = true;
  TripStepNum = 0;
//  FirstStopNameStr = "";
//  LastStopNameStr  = "";

  CursorWaitOpen();

  try
   {
    // Удаление старого расписания
    TripStepClearQuery->Parameters->ParamByName("trip_id_value")->Value = TripIdStr;

    TripStepClearQuery->ExecSQL();

    // Ввод нового расписания
    TripStepQuery->Parameters->ParamByName("trip_id_value")->Value = TripIdStr;


    TripStepQuery->Open();

    if (TripStepQuery->Active)
     {
      try
       {
        TripStepQuery->Edit();

        StringVectorIterator = TripStepStrStorePtr->begin();

        for (StringVectorIterator;
             StringVectorIterator != TripStepStrStorePtr->end();
             StringVectorIterator++)
         {
          StringVectorIterator++;
          if (StringVectorIterator != TripStepStrStorePtr->end())
           {
            PathToStopId = StringVectorIterator->StopIdStr;
           }
          else
           {
            PathToStopId = "";
           }

          StringVectorIterator--;

          TripStepQuery->Append();

          TripStepQuery->FieldByName(TripIdFieldNameStr)->AsString = TripIdStr;
          TripStepQuery->FieldByName(TripStepNumFieldNameStr)->AsInteger = TripStepNum;
          TripStepQuery->FieldByName(StopIdFieldNameStr)->AsString
          = StringVectorIterator->StopIdStr;

          if (!PathToStopId.IsEmpty())
           {
            TripStepQuery->FieldByName(PathToStopIdFieldNameStr)->AsString = PathToStopId;
           }
          if (!StringVectorIterator->TripStepInTimeStr.IsEmpty())
           {
            TripStepQuery->FieldByName(TripStepInTimeFieldNameStr)->AsDateTime
            = TDateTime(StringVectorIterator->TripStepInTimeStr,TDateTime::Time);
           }
          if (!StringVectorIterator->TripStepWaitTimeStr.IsEmpty())
           {
            TripStepQuery->FieldByName(TripStepWaitTimeFieldNameStr)->AsDateTime
            = TDateTime(StringVectorIterator->TripStepWaitTimeStr,TDateTime::Time);
           }

          TripStepNum++;
         }

        if (TripStepQuery->Modified)
         {
          TripStepQuery->Post();
         }
       }
      catch (Exception &exception)
       {
//        TourShowDialogException(NULL,&exception);
//        ResultFlag = false;
        TripStepQuery->Cancel();
        throw exception;
       }
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
    ResultFlag = false;
   }

  if (TripStepQuery->Active)
   {
    TripStepQuery->Close();
   }

  CursorWaitClose();

  return (ResultFlag);
 }

//---------------------------------------------------------------------------

bool TTourTripStepWizardForm::UpdateTripStepTable(void)
 {
  return (UpdateTripStepTable(CurrentTripIdStr,&ChainStrStore));
 }

//---------------------------------------------------------------------------

bool TTourTripStepWizardForm::UpdateTripStepTableLow(void)
 {
  return (UpdateTripStepTableLow(CurrentTripIdStr,&ChainStrStore));
 }

//---------------------------------------------------------------------------

bool TTourTripStepWizardForm::UpdateTripStepTable(AnsiString TripIdStr)
 {
  return (UpdateTripStepTable(TripIdStr,&ChainStrStore));
 }
//---------------------------------------------------------------------------

bool TTourTripStepWizardForm::UpdateTripStepTableLow(AnsiString TripIdStr)
 {
  return (UpdateTripStepTableLow(TripIdStr,&ChainStrStore));
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripStepWizardForm::FormDestroy(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  try
   {
    if (TripQuery->Active)
     {
      TripQuery->Close();
     }
    if (FromAvailableQuery->Active)
     {
      FromAvailableQuery->Close();
     }
    if (StopQuery->Active)
     {
      StopQuery->Close();
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripStepWizardForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
/*
  if (!BasicTripExistFlag)
   {
    BasicTripIdStr = "";
   }
*/
  Action = caHide;
 }
//---------------------------------------------------------------------------

int                TTourTripStepWizardForm::DateTimeInfoWaitCodeByValue
                   (char                             *ValueStrPtr)
 {
  int                                  Result;
  unsigned short                       MinuteValue;
  unsigned short                       HourValue;
  unsigned short                       SecValue;
  unsigned short                       MSecValue;
  TDateTime                            WorkTime;
  AnsiString                           MinuteValueStr;

  if (strlen(ValueStrPtr) > 0)
   {
    WorkTime = TDateTime(AnsiString(ValueStrPtr),TDateTime::Time);
    WorkTime.DecodeTime(&HourValue,&MinuteValue,&SecValue,&MSecValue);

    if ((HourValue == 0) && (SecValue == 0))
     {
      MinuteValueStr = IntToStr(MinuteValue);

      if (!strcmp(TourTripStepWizardDataTimeInfoWaitCodesArray
                  [TourTripStepDataTimeInfoWaitTimeNoStopCode],
                  MinuteValueStr.c_str()))
       {
        Result = TourTripStepDataTimeInfoWaitTimeNoStopCode;
       }
      else if (!strcmp(TourTripStepWizardDataTimeInfoWaitCodesArray
                       [TourTripStepDataTimeInfoWaitTime5MinWaitCode],
                       MinuteValueStr.c_str()))
       {
        Result = TourTripStepDataTimeInfoWaitTime5MinWaitCode;
       }
      else if (!strcmp(TourTripStepWizardDataTimeInfoWaitCodesArray
                       [TourTripStepDataTimeInfoWaitTime10MinWaitCode],
                       MinuteValueStr.c_str()))
       {
        Result = TourTripStepDataTimeInfoWaitTime10MinWaitCode;
       }
      else if (!strcmp(TourTripStepWizardDataTimeInfoWaitCodesArray
                       [TourTripStepDataTimeInfoWaitTime15MinWaitCode],
                       MinuteValueStr.c_str()))
       {
        Result = TourTripStepDataTimeInfoWaitTime15MinWaitCode;
       }
      else if (!strcmp(TourTripStepWizardDataTimeInfoWaitCodesArray
                       [TourTripStepDataTimeInfoWaitTime20MinWaitCode],
                       MinuteValueStr.c_str()))
       {
        Result = TourTripStepDataTimeInfoWaitTime20MinWaitCode;
       }
      else
       {
        Result = TourTripStepDataTimeInfoWaitTimeUserWaitCode;
       }
     }
    else
     {
      Result = TourTripStepDataTimeInfoWaitTimeUserWaitCode;
     }
   }
  else
   {
    Result = TourTripStepDataTimeInfoWaitTimeNoEntryCode;
   }

  return (Result);
 }

//---------------------------------------------------------------------------

AnsiString         TTourTripStepWizardForm::DateTimeInfoWaitValueByCode
                   (int                               Code)
 {
  TDateTime                            WaitTime;
  AnsiString                           WaitTimeStr;

  WaitTimeStr = TourTripStepWizardDataTimeInfoWaitCodesArray[Code];
  WaitTime    = TDateTime(0,StrToInt(WaitTimeStr),0,0);

  return (WaitTime.TimeString());
 }
//---------------------------------------------------------------------------

TDateTime          TTourTripStepWizardForm::GetPreliminaryTimeIn
                   (AnsiString                        FromStopIdStr,
                    AnsiString                        ToStopIdStr)
 {
  TDateTime                            ResultTime;
  unsigned short                       HourValue;
  unsigned short                       MinValue;
  unsigned short                       SecValue;
  unsigned short                       MSecValue;
  float                                NormSpeedValue;
  float                                SpeedFactorValue;
  float                                HourFloatValue;
  bool                                 BusModelExistFlag;
  TADOQuery                           *QueryPtr;

  HourValue = 0;
  MinValue  = 0;
  SecValue  = 0;
  MSecValue = 0;
  NormSpeedValue   = TourPathNormSpeedDefaultValue;
  SpeedFactorValue = TourBusSpeedFactorDefaultValue;
  QueryPtr = NULL;

  try
   {
    BusModelExistFlag = BusModelExist(CurrentTripIdStr);

    if (BusModelExistFlag)
     {
      QueryPtr = TimeInInfoQuery;
     }
    else
     {
      QueryPtr = TimeInInfoSimpleQuery;
     }

    if (QueryPtr->Active)
     {
      QueryPtr->Close();
     }

    QueryPtr->Parameters->ParamByName("trip_id_value")->Value
    = CurrentTripIdStr;
    QueryPtr->Parameters->ParamByName("from_stopid_value")->Value
    = FromStopIdStr;
    QueryPtr->Parameters->ParamByName("to_stopid_value")->Value
    = ToStopIdStr;

    QueryPtr->Open();

    if (!QueryPtr->IsEmpty())
     {
      if (!QueryPtr->FieldByName(PathNormSpeedFieldNameStr)->IsNull)
       {
        NormSpeedValue
        = QueryPtr->FieldByName(PathNormSpeedFieldNameStr)->AsFloat;
       }

      if (BusModelExistFlag)
       {
        if (!QueryPtr->FieldByName(BusSpeedFactorFieldNameStr)->IsNull)
         {
          SpeedFactorValue
          = QueryPtr->FieldByName(BusSpeedFactorFieldNameStr)->AsFloat;
         }
       }

      HourFloatValue
      = QueryPtr->FieldByName(PathLengthFieldNameStr)->AsFloat /
        (NormSpeedValue * SpeedFactorValue);
      HourValue = HourFloatValue;
      MinValue = ceil((HourFloatValue - HourValue) * TripStepWizardMinutesInHour);

      ResultTime = TDateTime(HourValue,MinValue,SecValue,MSecValue);

      QueryPtr->Close();
     }
    else
     {
      QueryPtr->Close();
      throw Exception("TimeInInfoQuery record set is empty");
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  return (ResultTime);
 }

//---------------------------------------------------------------------------

void __fastcall TTourTripStepWizardForm::FormCreate(TObject *Sender)
 {
  if (TourDataModule->DataBaseEditModeFlag)
   {
    DeleteButton->Visible = true;
    AddButton->Visible    = true;
    NextButton->Visible   = true;

    ChainPopupMenu->AutoPopup     = true;
    AvailablePopupMenu->AutoPopup = true;

    AvailableListView->OnKeyDown  = AvailableListViewKeyDown;
    ChainListView->OnKeyDown      = ChainListViewKeyDown;
   }
  else
   {
    DeleteButton->Visible = false;
    AddButton->Visible    = false;
    NextButton->Visible   = false;

    ChainPopupMenu->AutoPopup     = false;
    AvailablePopupMenu->AutoPopup = false;

    AvailableListView->OnKeyDown  = NULL;
    ChainListView->OnKeyDown      = NULL;
   }
 }

void TTourTripStepWizardForm::Clear(void)
 {
  ChainStrStore.clear();
  FillChainListViewByStrStore();
  FillAvailableStrStore();
 }
//---------------------------------------------------------------------------

bool               TTourTripStepWizardForm::BusModelExist
                   (AnsiString                        TripIdStr)
 {
  bool                                 ResultFlag;
  TADOQuery                           *QueryPtr;
  AnsiString                           SQLStr;

  ResultFlag = false;
  QueryPtr   = NULL;
  SQLStr     = "";

  try
   {
    QueryPtr = new TADOQuery(NULL);

    if (QueryPtr != NULL)
     {
      if (QueryPtr->Active)
       {
        QueryPtr->Close();
       }

      QueryPtr->Connection = TourDataModule->TourDataBaseConnection;

      SQLStr  = "SELECT ";
      SQLStr += BusModelFieldNameStr;
      SQLStr += " FROM ";
      SQLStr += TripTableNameStr;
      SQLStr += " WHERE ";
      SQLStr += TripTableNameStr;
      SQLStr += TripStepWizardDotSymbolStr;
      SQLStr += TripIdFieldNameStr;
      SQLStr += TripStepWizardEqualSymbolStr;
      SQLStr += QuotedStr(TripIdStr);

      QueryPtr->SQL->Text = SQLStr;

      QueryPtr->Open();

      if (!QueryPtr->FieldByName(BusModelFieldNameStr)->IsNull)
       {
        ResultFlag = true;
       }

      delete (QueryPtr);
      QueryPtr = NULL;
     }
    else
     {
      Exception("Can't allocate memory");
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  return (ResultFlag);
 }

void __fastcall    TTourTripStepWizardForm::SetBaseTripId
                   (AnsiString                        value)
 {
//  CurrentTripIdStr = value;

  FillChainStrStoreByTrip(value);
 }
/*
AnsiString __fastcall TTourTripStepWizardForm::GetBaseTripIdStr()
 {
  return CurrentTripIdStr;
 }
*/

void __fastcall    TTourTripStepWizardForm::SetCurrentTripId
                   (AnsiString                        value)
 {
  CurrentTripIdStr = value;

  FillChainStrStoreByTrip(value);
 }

AnsiString __fastcall
                   TTourTripStepWizardForm::GetCurrentTripId
                   (void)
 {
  return CurrentTripIdStr;
 }

