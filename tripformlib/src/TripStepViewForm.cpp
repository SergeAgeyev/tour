//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrTripStep

#include "FieldDef.h"
#include "StdTool.h"
#include "TourTool.h"
#include "TripStepViewForm.h"
//#include "TripStepAddForm.h"
//#include "TripStepEditForm.h"
#include "TripStepWizardForm.h"
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
TTourTripStepViewForm *TourTripStepViewForm;

enum TourTripStepStringTypes
 {
  TourTripStepNoSelectItemStr = TourRefBookViewStringTypesEnumCount,
  TourTripStepStepByTripStepIdCaptionStr,
  TourTripStepRecordTripStepWizardHintStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourTripStepViewForm::TTourTripStepViewForm(TComponent* Owner)
 : TTourRefBookTableGridViewForm(Owner)
 {
 }
//---------------------------------------------------------------------------
/*
void __fastcall TTourTripStepViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourTripStepAddForm        *TourTripStepAddFormPtr;

  FunctionArgUsedSkip(Sender);
  TourTripStepAddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourTripStepAddForm),
                              &TourTripStepAddFormPtr);

      if (TourTripStepAddFormPtr != NULL)
       {
        TourTripStepAddFormPtr->MainQueryDataSet = MainQuery;
        TourTripStepAddFormPtr
        ->BusDataSource->DataSet = BusQuery;
        TourTripStepAddFormPtr
        ->TripStepOwnerDataSource->DataSet = TripStepOwnerQuery;

        ShowProcessAdd(TourTripStepAddFormPtr);

        delete (TourTripStepAddFormPtr);
        TourTripStepAddFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourTripStepAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourTripStepViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourTripStepEditForm     *TourTripStepEditFormPtr;

  FunctionArgUsedSkip(Sender);
  TourTripStepEditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourTripStepEditForm),
                              &TourTripStepEditFormPtr);

      if (TourTripStepEditFormPtr != NULL)
       {
        TourTripStepEditFormPtr->MainQueryDataSet = MainQuery;
        TourTripStepEditFormPtr
        ->BusDataSource->DataSet = BusQuery;
        TourTripStepEditFormPtr
        ->TripStepOwnerDataSource->DataSet = TripStepOwnerQuery;

        ShowProcessEdit(TourTripStepEditFormPtr);

        delete (TourTripStepEditFormPtr);
        TourTripStepEditFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourTripStepEditForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
*/
//---------------------------------------------------------------------------
void __fastcall TTourTripStepViewForm::FormClose(TObject *Sender,
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

  TourTripStepViewForm = NULL;
 }
//---------------------------------------------------------------------------
void __fastcall TTourTripStepViewForm::FormCreate(TObject *Sender)
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

  EditLocked = true;

  AfterMainTableOpenStatusBarHintStr
  += GetTranslatedStr(TourTripStepRecordTripStepWizardHintStr);

  MainStatusBar->Panels->Items[0]->Text = AfterMainTableOpenStatusBarHintStr;
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripStepViewForm::RefreshActionExecute(
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

void __fastcall TTourTripStepViewForm::TripStepStepActionExecute(TObject *Sender)
 {
  TTourTripStepWizardForm             *TripStepWizardFormPtr;
  AnsiString                           TripIdStr;

  FunctionArgUsedSkip(Sender);
  TripStepWizardFormPtr = NULL;
  TripIdStr = "";

  try
   {
    Application->CreateForm(__classid(TTourTripStepWizardForm),
                            &TripStepWizardFormPtr);

    if (TripStepWizardFormPtr != NULL)
     {
      TripIdStr = MainQuery->FieldByName(TripIdFieldNameStr)->AsString;

      if (!TripIdStr.IsEmpty())
       {
        TripStepWizardFormPtr->Caption
        = GetTranslatedStr(TourTripStepStepByTripStepIdCaptionStr) +
          TripIdStr +
          " [" + MainQuery->FieldByName(TripNameFieldNameStr)->AsString + "]";

        TripStepWizardFormPtr->CurrentTripId/*Str*/ = TripIdStr;
//        TripStepWizardFormPtr->FillChainStrStoreByTrip(TripIdStr);

        if (TripStepWizardFormPtr->ShowModal() == mrOk)
         {
          TripStepWizardFormPtr->UpdateTripStepTable(TripIdStr);
          RefreshActionExecute(Sender);
         }
       }
      else
       {
        TourShowDialogError
        ((GetTranslatedStr(TourTripStepNoSelectItemStr)).c_str());
       }

      delete (TripStepWizardFormPtr);
      TripStepWizardFormPtr = NULL;
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }
 }
//---------------------------------------------------------------------------

#undef   GetTranslatedStr(Index)



