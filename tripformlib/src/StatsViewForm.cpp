//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrStats

#include "FieldDef.h"
#include "StdTool.h"
#include "StatsViewForm.h"
#include "StatsAddForm.h"
#include "StatsEditForm.h"
#include "TourTool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Placemnt"
#pragma link "RXDBCtrl"
#pragma link "TableGridViewForm"
#pragma link "VADODataSourceOrdering"
#pragma link "VCustomDataSourceOrdering"
#pragma link "VDBGridFilterDialog"
#pragma link "VDBSortGrid"
#pragma link "VStringStorage"
#pragma link "VCustomDBGridFilterDialog"
#pragma resource "*.dfm"
TTourStatsViewForm *TourStatsViewForm;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourStatsViewForm::TTourStatsViewForm(TComponent* Owner)
 : TTourRefBookTableGridViewForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourStatsViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourStatsAddForm        *TourStatsAddFormPtr;

  FunctionArgUsedSkip(Sender);
  TourStatsAddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourStatsAddForm),
                              &TourStatsAddFormPtr);

      if (TourStatsAddFormPtr != NULL)
       {
        TourStatsAddFormPtr->MainQueryDataSet = MainQuery;
        TourStatsAddFormPtr->TripDataSource->DataSet = TripQuery;
        TourStatsAddFormPtr->StopDataSource->DataSet = StopQuery;
        TourStatsAddFormPtr->StatsDatePicker->DateTime = TourLocalDateTime();
        TourStatsAddFormPtr->StatsTimePicker->DateTime = TourLocalDateTime();

        ShowProcessAdd(TourStatsAddFormPtr);

        delete (TourStatsAddFormPtr);
        TourStatsAddFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourStatsAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourStatsViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourStatsEditForm     *TourStatsEditFormPtr;

  FunctionArgUsedSkip(Sender);
  TourStatsEditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourStatsEditForm),
                              &TourStatsEditFormPtr);

      if (TourStatsEditFormPtr != NULL)
       {
        TDateTime                      WorkDateTime;

        WorkDateTime = MainQuery->FieldByName(StatsDateFieldNameStr)->AsDateTime;

        TourStatsEditFormPtr->MainQueryDataSet = MainQuery;
        TourStatsEditFormPtr->TripDataSource->DataSet = TripQuery;
        TourStatsEditFormPtr->StopDataSource->DataSet = StopQuery;
        TourStatsEditFormPtr->StatsDatePicker->DateTime = WorkDateTime;
        TourStatsEditFormPtr->StatsTimePicker->DateTime = WorkDateTime;

        TourStatsEditFormPtr->OnStatsTripIdFieldChanged();
        TourStatsEditFormPtr
        ->OnStatsFromStopIdFieldChanged
          (MainQuery->FieldByName(StatsFromStopIdFieldNameStr));

        ShowProcessEdit(TourStatsEditFormPtr);

        delete (TourStatsEditFormPtr);
        TourStatsEditFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourStatsEditForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourStatsViewForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  try
   {
    TripQuery->Close();
    StopQuery->Close();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  TTourRefBookTableGridViewForm::FormClose(Sender,Action);

  TourStatsViewForm = NULL;
 }
//---------------------------------------------------------------------------
void __fastcall TTourStatsViewForm::FormCreate(TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    TripQuery->Open();
    StopQuery->Open();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();

  TTourRefBookTableGridViewForm::FormCreate(Sender);
 }
//---------------------------------------------------------------------------

void __fastcall TTourStatsViewForm::RefreshActionExecute(
      TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    if (TripQuery->Active)
     {
      TripQuery->Close();
     }
    if (!TripQuery->Active)
     {
      TripQuery->Open();
     }
    if (StopQuery->Active)
     {
      StopQuery->Close();
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

  TTourRefBookTableGridViewForm::RefreshActionExecute(Sender);
 }
//---------------------------------------------------------------------------

#undef   GetTranslatedStr(Index)

