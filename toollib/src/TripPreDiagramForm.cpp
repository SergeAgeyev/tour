//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FieldDef.h"
#include "StdTool.h"
#include "TourTool.h"
#include "DataModuleForm.h"
#include "DataSetViewForm.h"
#include "TripPreDiagramForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TripWizardProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourTripPreDiagramForm *TourTripPreDiagramForm;

enum TourTripPreDiagramStringTypes
 {
  TourTripPreDiagramTripIdCaptionStr = TourTripWizardStringTypesEnumCount,
  TourTripPreDiagramTripNameCaptionStr,
  TourTripPreDiagramTripNotesCaptionStr,
  TourTripPreDiagramInvalidTripMessageStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourTripPreDiagramForm::TTourTripPreDiagramForm(TComponent* Owner)
 : TTourTripWizardProcessForm(Owner)
 {
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

void               TTourTripPreDiagramForm::FillAvailableStrStore
                   (void)
 {
  TADOQuery                           *QueryPtr;

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
      = (ChainStrStore[ChainStrStore.size() - 1]).c_str();

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
      AvailableStrStore
      .push_back((QueryPtr->FieldByName(StopIdFieldNameStr)->AsString).c_str());

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


void               TTourTripPreDiagramForm::FillAvailableListView
                   (void)
 {
  TListItem                           *ListItemPtr;
  TripPreDiagramStringVectorType::iterator
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
      ListItemPtr->Caption = AnsiString(StringVectorIterator->c_str());

      if (GetStopNameByStopId(ListItemPtr->Caption,&StopNameStr))
       {
        ListItemPtr->SubItems->Append(StopNameStr);
       }
     }
   }

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

//---------------------------------------------------------------------------

void               TTourTripPreDiagramForm::FillChainStrStoreByTrip
                   (AnsiString                        TripIdStr)
 {
  int                                  RecordIndex;

  CursorWaitOpen();

  try
   {
    TripStepQuery->Parameters->ParamByName("trip_id_value")->Value = TripIdStr;

    TripStepQuery->Open();

    if (TripStepQuery->Active)
     {
      TripStepQuery->First();

      ChainStrStore.clear();

      if (TripStepQuery->RecordCount > 0)
       {
        for (RecordIndex = 0;
             RecordIndex < TripStepQuery->RecordCount;
             RecordIndex++)
         {
          ChainStrStore
          .push_back((TripStepQuery->FieldByName(StopIdFieldNameStr)->AsString).c_str());

          TripStepQuery->Next();
         }
/*
        TripStepQuery->Last();

        StopChainStrStore
        .push_back((TripStepQuery->FieldByName("path_tostopid")->AsString).c_str());
*/        
       }

      FillChainListViewByStrStore();
      FillAvailableStrStore();
      
      TripStepQuery->Close();
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();
 }

//---------------------------------------------------------------------------

void               TTourTripPreDiagramForm::FillChainListViewByStrStore
                   (void)
 {
  TListItem                           *ListItemPtr;
  TripPreDiagramStringVectorType::iterator
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
      ListItemPtr->Caption = AnsiString(StringVectorIterator->c_str());

      if (GetStopNameByStopId(ListItemPtr->Caption,&StopNameStr))
       {
        ListItemPtr->SubItems->Append(StopNameStr);
       }
     }
   }
 }

//---------------------------------------------------------------------------


void               TTourTripPreDiagramForm::ChainStrStoreAppendItem
                   (AnsiString                        ItemStr)
 {
  ChainStrStore.push_back(ItemStr.c_str());
  ChainListViewAppendItem(ItemStr);
 }

//---------------------------------------------------------------------------

void               TTourTripPreDiagramForm::ChainListViewAppendItem
                   (AnsiString                        ItemStr)
 {
  TListItem                           *ListItemPtr;
  AnsiString                           StopNameStr;

  ListItemPtr = NULL;

  ListItemPtr = ChainListView->Items->Add();

  if (ListItemPtr != NULL)
   {
    ListItemPtr->Caption = ItemStr;

    if (GetStopNameByStopId(ItemStr,&StopNameStr))
     {
      ListItemPtr->SubItems->Append(StopNameStr);
     }
   }
 }

//---------------------------------------------------------------------------

void               TTourTripPreDiagramForm::ChainStrStoreDeleteItem
                   (void)
 {
  if (ChainStrStore.size() > 0)
   {
    ChainStrStore.pop_back();
    ChainListViewDeleteItem();
   }
 }

//---------------------------------------------------------------------------

void               TTourTripPreDiagramForm::ChainListViewDeleteItem
                   (void)
 {
  if (ChainListView->Items->Count > 0)
   {
    ChainListView->Items->Delete(ChainListView->Items->Count - 1);
   }
 }

//---------------------------------------------------------------------------

void __fastcall TTourTripPreDiagramForm::ChainDeleteItemActionExecute(
      TObject *Sender)
 {
  //
  if (ChainListView->Items->Count > 0)
   {
    // Базового пункта нет
//    BasicTripExistFlag = false;

    ChainStrStoreDeleteItem();

    FillAvailableStrStore();
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripPreDiagramForm::AvailableAddActionExecute(
      TObject *Sender)
 {
  //
  if (AvailableListView->Selected != NULL)
   {
    // Базового пункта нет
//    BasicTripExistFlag = false;

    ChainStrStoreAppendItem(AvailableListView->Selected->Caption);

    FillAvailableStrStore();

    AvailableListView->SetFocus();

    if (AvailableListView->Items->Count > 0)
     {
      AvailableListView->Selected = AvailableListView->Items->Item[0];
     }
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripPreDiagramForm::SelectActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);
  
  SelectBasicTrip();
 }

bool               TTourTripPreDiagramForm::SelectBasicTrip
                   (AnsiString                       *BasicTripStrPtr)
 {
  TTourDataSetViewForm                *LookupDataSetViewFormPtr;
  TColumn                             *ColumnPtr;
  bool                                 ResultFlag;

  LookupDataSetViewFormPtr = NULL;
  ColumnPtr = NULL;
  ResultFlag = false;

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
      ColumnPtr->Title->Caption = GetTranslatedStr(TourTripPreDiagramTripNameCaptionStr);
      ColumnPtr = LookupDataSetViewFormPtr->Grid->Columns->Add();
      ColumnPtr->FieldName = TripIdFieldNameStr;
      ColumnPtr->Title->Caption = GetTranslatedStr(TourTripPreDiagramTripIdCaptionStr);
      ColumnPtr = LookupDataSetViewFormPtr->Grid->Columns->Add();
      ColumnPtr->FieldName = TripNotesFieldNameStr;
      ColumnPtr->Title->Caption = GetTranslatedStr(TourTripPreDiagramTripNotesCaptionStr);

      if (LookupDataSetViewFormPtr->ShowModal() == mrOk)
       {
        AnsiString                     TripIdStr;
//        // Базового пункт существует
//        BasicTripExistFlag = true;
        ResultFlag = true;

        TripIdStr
        = LookupDataSetViewFormPtr
          ->DataSource->DataSet->FieldByName(TripIdFieldNameStr)->AsString;

        FillChainStrStoreByTrip(TripIdStr);

        if (BasicTripStrPtr != NULL)
         {
          *BasicTripStrPtr = TripIdStr;
         }
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

  return (ResultFlag);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripPreDiagramForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  FunctionArgUsedSkip(Sender);
/*
  if (!BasicTripExistFlag)
   {
    BasicTripIdStr = "";
   }
*/
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

  Action = caHide;
 }
//---------------------------------------------------------------------------

bool               TTourTripPreDiagramForm::GetStopNameByStopId
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

void __fastcall TTourTripPreDiagramForm::ChainPopupMenuPopup(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  if (ChainStrStore.size() > 0)
   {
    DeleteMenuItem->Enabled = true;
   }
  else
   {
    DeleteMenuItem->Enabled = false;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripPreDiagramForm::AvailablePopupMenuPopup(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  if ((AvailableStrStore.size() > 0) &&
      (AvailableListView->Selected != NULL))
   {
    AddMenuItem->Enabled = true;
   }
  else
   {
    AddMenuItem->Enabled = false;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripPreDiagramForm::FormCloseQuery(TObject *Sender,
      bool &CanClose)
 {
  if (ModalResult == mrOk)
   {
    if (ChainStrStore.size() > 1)
     {
      CanClose = true;
     }
    else
     {
      TourShowDialogError
      (GetTranslatedStr(TourTripPreDiagramInvalidTripMessageStr).c_str());
      CanClose = false;
     }
   }
  else
   {
    CanClose = true;
   }
 }
//---------------------------------------------------------------------------


