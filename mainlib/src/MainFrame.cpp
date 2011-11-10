//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FieldDef.h"
#include "StdTool.h"
#include "TourTool.h"
#include "MainFrame.h"

#if !defined(TOUR_DEMO_MODE)

  #include "StopOwnerViewForm.h"
  #include "StopModelViewForm.h"
  #include "TripOwnerViewForm.h"
  #include "RegionViewForm.h"
  #include "BusViewForm.h"
  #include "CityViewForm.h"
  #include "StopViewForm.h"
  #include "TripViewForm.h"
  #include "StatsViewForm.h"
  #include "PathViewForm.h"
  #include "TripStepViewForm.h"
  #include "DataModuleForm.h"
  #include "BaseRegulationForm.h"
  #include "RepStopInfoInputForm.h"
  #include "RepTripInfoInputForm.h"
  #include "TripStepNewMasterForm.h"
  #include "TripPreDiagramForm.h"

#endif

//  #include "TripNewMasterForm.h"
//#include "SessionDateForm.h"
//#include "SessionTimeForm.h"

#include "TripDiagramForm.h"
#include "AboutForm.h"
#include "TourData.h"
#include "TourDataDM.h"
#include "TourDemoData.h"
#include "SimpleTourDataSetViewForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourMainFrame *TourMainFrame;

enum TourMainFrameStringTypes
 {
  TourMainFrameNotEnoughMemoryErrorStr = 0,
  TourMainFrameFunctionExecuteFailErrorStr,
  TourMainFrameTripNewMasterQuestionStr,
  TourMainFrameApplicationExitQuestionStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourMainFrame::TTourMainFrame(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------

void TTourMainFrame::MDIChildFormView(System::TMetaClass* InstanceClassPtr, TForm ** FormPtrPtr)
 {
  try
   {
    if ((*FormPtrPtr) == NULL)
     {
      Application->CreateForm(InstanceClassPtr,
                              FormPtrPtr);
     }
    else
     {
      (*FormPtrPtr)->BringToFront();
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }
 }

//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::SessionExitActionExecute(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  Close();
 }

void __fastcall TTourMainFrame::HelpAboutActionExecute(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  try
   {
    Application->CreateForm(__classid(TTourAboutForm),
                            &TourAboutForm);

    TourAboutForm->ShowModal();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::ObjectsTransportationsFlightsActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    MDIChildFormView(__classid(TTourTripViewForm),(TForm**)&TourTripViewForm);
   }
  #endif
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::ObjectsTopologyPopulatedPointsActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    MDIChildFormView(__classid(TTourRefBookCityViewForm),(TForm**)&TourRefBookCityViewForm);
   }
  #endif
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::SetupStopPointTypesActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    MDIChildFormView(__classid(TTourRefBookStopModelViewForm),
                     (TForm**)&TourRefBookStopModelViewForm);
   }
  #endif
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::ObjectsTranportationsFlightTimetableActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    MDIChildFormView(__classid(TTourRefBookStopModelViewForm),
                     (TForm**)&TourRefBookStopModelViewForm);
   }
  #endif
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::SetupTransportTypesActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    MDIChildFormView(__classid(TTourRefBookBusViewForm),
                     (TForm**)&TourRefBookBusViewForm);
   }
  #endif
 }
//---------------------------------------------------------------------------


void __fastcall TTourMainFrame::SessionCurrentDateActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);
/*
  try
   {
    if (TourSessionDateForm == NULL)
     {
      Application->CreateForm(__classid(TTourSessionDateForm),
                              &TourSessionDateForm);

      if (TourSessionDateForm != NULL)
       {
        TourSessionDateForm->Show();
       }
     }
    else
     {
      TourSessionDateForm->BringToFront();
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }
*/
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::SessionCurrentTimeActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);
/*
  try
   {
    if (TourSessionTimeForm == NULL)
     {
      Application->CreateForm(__classid(TTourSessionTimeForm),
                              &TourSessionTimeForm);

      if (TourSessionTimeForm != NULL)
       {
        TourSessionTimeForm->Show();
       }
     }
    else
     {
      TourSessionTimeForm->BringToFront();
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }
*/   
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::DoFlightDataNewActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    TTourTripStepNewMasterForm          *TripStepNewMasterFormPtr;
    bool                                 ResultFlag;
    bool                                 LoopExitFlag;
    int                                  ModalResult;

    TripStepNewMasterFormPtr = NULL;
    ResultFlag = true;
    LoopExitFlag = false;

    if (TourDataModule->DataBaseEditModeFlag)
     {
      if (ResultFlag)
       {
        try
         {
          Application->CreateForm(__classid(TTourTripStepNewMasterForm),
                                  &TripStepNewMasterFormPtr);

          if (TripStepNewMasterFormPtr == NULL)
           {
            Exception(GetTranslatedStr(TourMainFrameNotEnoughMemoryErrorStr)
                      + "TTourTripStepNewMasterForm");
            ResultFlag = false;
           }
          else
           {
            //
           }
         }
        catch (Exception &exception)
         {
          TourShowDialogException(NULL,&exception);
          ResultFlag = false;
         }
       }

      if (ResultFlag)
       {
        // Циклический ввод нескольких рейсов
        do
         {
          CursorWaitOpen();

          // Новая запись в таблице trip
          try
           {
            TripStepNewMasterFormPtr->ExistTripQuery->Append();
           }
          catch (Exception &exception)
           {
            TourShowDialogException(NULL,&exception);
            ResultFlag = false;
           }

          CursorWaitClose();

            if (ResultFlag)
             {
    //          TripStepNewMasterFormPtr->Caption
    //          = TripStepNewMasterFormCaption + TripNewMasterFormPtr->TripIdStr;

              ModalResult = TripStepNewMasterFormPtr->ShowModal();
             }

          if (ResultFlag)
           {
            if (ModalResult == mrOk)
             {
              CursorWaitOpen();

              try
               {
                TourDataModule->TourDataBaseConnection->BeginTrans();
                TripStepNewMasterFormPtr->ExistTripQuery->Post();
                if (TripStepNewMasterFormPtr
                    ->UpdateTripStepTableLow
                      (TripStepNewMasterFormPtr
                       ->ExistTripQuery->FieldByName(TripIdFieldNameStr)->AsString))
                 {
                  TourDataModule->TourDataBaseConnection->CommitTrans();
                 }
                else
                 {
                  Exception(GetTranslatedStr(TourMainFrameFunctionExecuteFailErrorStr) +
                            "TripStepNewMasterFormPtr->UpdateTripStepTable()");
                  ResultFlag = false;
                 }
               }
              catch (Exception &exception)
               {
                TourDataModule->TourDataBaseConnection->RollbackTrans();
                ResultFlag = false;
                TourShowDialogException(NULL,&exception);
               }

              CursorWaitClose();
             }
            else if (ModalResult == mrCancel)
             {
              ResultFlag = false;
             }
           }

          if (ResultFlag)
           {
            // Запрос на продолжение ввода рейсов
            if (TourShowDialogYesNo
                  (GetTranslatedStr
                   (TourMainFrameTripNewMasterQuestionStr).c_str()) == IDNO)
             {
              LoopExitFlag = true;
             }
            else
             {
              // Для ввода нового рейса необходимо очистить хранилице маршрута
              // в диалоге выбора маршрута
  //            TripStepNewMasterFormPtr->ChainStrStore.clear();
              TripStepNewMasterFormPtr->Clear();
             }
           }
         }
        while ((!LoopExitFlag) && (ResultFlag));
       }

      // В случае ошибки откат добавления записи в таблицу trip
      if (!ResultFlag)
       {
        CursorWaitOpen();

        try
         {
          if (TripStepNewMasterFormPtr->ExistTripQuery->State == dsInsert)
           {
            TripStepNewMasterFormPtr->ExistTripQuery->Cancel();
           }
         }
        catch (Exception &exception)
         {
          TourShowDialogException(NULL,&exception);
         }

        CursorWaitClose();
       }

      // Освобождение памяти
      if (TripStepNewMasterFormPtr != NULL)
       {
        delete (TripStepNewMasterFormPtr);
        TripStepNewMasterFormPtr = NULL;
       }
     }
   }
  #endif
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::ObjectsTopologyRegionsActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    MDIChildFormView(__classid(TTourRefBookRegionViewForm),
                     (TForm**)&TourRefBookRegionViewForm);
   }
  #endif
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::ObjectsTopologyStopPointsActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    MDIChildFormView(__classid(TTourRefBookStopViewForm),
                     (TForm**)&TourRefBookStopViewForm);
   }
  #endif
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::DoFlightDiagramActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    Application->CreateForm(__classid(TTourTripPreDiagramForm),
                            &TourTripPreDiagramForm);

    if (TourTripPreDiagramForm != NULL)
     {
      AnsiString                         BasicTripIdStr;
      //TourTripPreDiagramForm->SelectBasicTrip()//ActionExecute(Sender);

      if (TourTripPreDiagramForm->SelectBasicTrip(&BasicTripIdStr))//TourTripPreDiagramForm->BasicTripExistFlag)
       {
        try
         {
          TourTripDiagramForm =
          new TTourTripDiagramForm(this,TourTripPreDiagramForm->ChainStrStore,/*TourTripPreDiagramForm->*/BasicTripIdStr);
/*
          TourTripDiagramForm =
          new TTourTripDiagramForm(this,TourTripPreDiagramForm->ChainStrStore);
*/
         }
        catch (Exception &exception)
         {
          TourShowDialogException(NULL,&exception);
         }
       }
     }
  //    delete (TourTripPreDiagramForm);
  //    TourTripPreDiagramForm = NULL;
   }
  #else
   {
    TourDemoDataClass                 *DemoDataPtr;
    TourStringVectorClass              StopIdStorage;
    AnsiString                         BaseStopIdStr;
    TourStringVectorClass              StringStorage;

    try
     {
      DemoDataPtr = new TourDemoDataClass(&TourDemoData,StopIdStorage);

      if (DemoDataPtr != NULL)
       {
        TourTourSetPtrClass              TourSetPtr;
        TTourSimpleTourDataSetViewForm  *FormPtr;
        //
        TourSetPtr = DemoDataPtr->TourSet();
        FormPtr = new TTourSimpleTourDataSetViewForm(this);

        if (FormPtr != NULL)
         {
          unsigned int                       ItemIndex;
          unsigned int                       ItemCount;
          TListItem                         *ItemPtr;
          TListColumn                       *ColumnPtr;
/*
          FormPtr->Caption = "Tour";//GetTranslatedStr(TourTripSimpleProcessCityListCaptionStr);
*/
          ItemCount = TourSetPtr->Count();
/*
          ColumnPtr = FormPtr->ListView->Columns->Add();
          if (ColumnPtr != NULL)
           {
            ColumnPtr->Width    = 75;
            ColumnPtr->Caption  = "Id";//GetTranslatedStr(TourTripSimpleProcessCityIdStr);
           }
          ColumnPtr = FormPtr->ListView->Columns->Add();
          if (ColumnPtr != NULL)
           {
            ColumnPtr->AutoSize = true;
            ColumnPtr->Caption  = "Name";//GetTranslatedStr(TourTripSimpleProcessCityNameStr);;
           }
*/
          for (ItemIndex = 0; ItemIndex < ItemCount; ItemIndex++)
           {
            ItemPtr = FormPtr->ListView->Items->Add();

            if (ItemPtr != NULL)
             {
              ItemPtr->Caption = TourSetPtr->Tour(ItemIndex)->IdStr().c_str();
              ItemPtr->SubItems->Append(TourSetPtr->Tour(ItemIndex)->NameStr().c_str());
             }
           }

          if (FormPtr->ShowModal() == mrOk)
           {
            TourTourSchedulePtrClass   SchedulePtr;
            TourStopSchedulePtrClass   StopSchedulePtr;

            BaseStopIdStr = FormPtr->ListView->Selected->Caption;

            SchedulePtr = DemoDataPtr->Tour(BaseStopIdStr.c_str())->Schedule();
            ItemCount   = SchedulePtr->StopCount();

            StringStorage.clear();

            for (ItemIndex = 0; ItemIndex < ItemCount; ItemIndex++)
             {
              StopSchedulePtr = SchedulePtr->StopSchedule(ItemIndex);
              StringStorage.push_back(StopSchedulePtr->Stop()->IdStr());
             }

            TourTripDiagramForm =
            new TTourTripDiagramForm(this,StringStorage,BaseStopIdStr);
           }

          delete (FormPtr);
         }
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
  #endif
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::ObjectsTopologyWayAreasActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    MDIChildFormView(__classid(TTourPathViewForm),
                     (TForm**)&TourPathViewForm);
   }
  #endif
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::ObjectsTransportationsTransportStatisticsActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    MDIChildFormView(__classid(TTourStatsViewForm),
                     (TForm**)&TourStatsViewForm);
   }
  #endif
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::ObjectsStopPointOwnersActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    MDIChildFormView(__classid(TTourRefBookStopOwnerViewForm),
                     (TForm**)&TourRefBookStopOwnerViewForm);
   }
  #endif
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::ObjectsTransportersActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    MDIChildFormView(__classid(TTourRefBookTripOwnerViewForm),
                     (TForm**)&TourRefBookTripOwnerViewForm);
   }
  #endif
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::StatusBarResize(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  StatusBar->Panels->Items[0]->Width
  = StatusBar->Width
    - StatusBar->Panels->Items[1]->Width
    - StatusBar->Panels->Items[2]->Width;
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::ClockTimerTimer(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  StatusBar->Panels->Items[2]->Text = Time().FormatString("hh':'nn':'ss");
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::DataTimerTimer(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  StatusBar->Panels->Items[1]->Text = Date().FormatString("dd' 'mmmm' 'yyyy (dddd)");
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::DisplayHint(TObject *Sender)
 {
  StatusBar->Panels->Items[0]->Text = GetLongHint(Application->Hint);
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::FormCreate(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  Application->OnHint = DisplayHint;
  ClockTimer->Enabled = true;
  DataTimer->Enabled  = true;

  #if defined(TOUR_DEMO_MODE)
   {
    DoFlightDiagramWizardMenuItem->Enabled = false;
    ReportsMenuItem->Enabled               = false;
    DataBaseMenuItem->Enabled              = false;
   }
  #endif
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::FormShow(TObject *Sender)
 {
  DataTimerTimer(Sender);
  ClockTimerTimer(Sender);
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  if (TourShowDialogYesNo
      (GetTranslatedStr(TourMainFrameApplicationExitQuestionStr).c_str()) == IDYES)
   {
    Action = caFree;
   }
  else
   {
    Action = caNone;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourMainFrame::DoFlightDiagramWizardActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    TTourTripDiagramForm                *TourTripDiagramFormPtr;

    FunctionArgUsedSkip(Sender);
    TourTripDiagramFormPtr = NULL;

    Application->CreateForm(__classid(TTourTripPreDiagramForm),
                            &TourTripPreDiagramForm);

    if (TourTripPreDiagramForm != NULL)
     {
      if (TourTripPreDiagramForm->ShowModal() == mrOk)
       {
        try
         {
          TourTripDiagramFormPtr =
          new TTourTripDiagramForm(this,TourTripPreDiagramForm->ChainStrStore);//,TourTripPreDiagramForm->BasicTripIdStr);
  /*
          TourTripDiagramForm =
          new TTourTripDiagramForm(this,TourTripPreDiagramForm->ChainStrStore);
  */
         }
        catch (Exception &exception)
         {
          TourShowDialogException(NULL,&exception);
         }
       }

      delete (TourTripPreDiagramForm);
      TourTripPreDiagramForm = NULL;
     }
   }
  #endif
 }
//---------------------------------------------------------------------------
void __fastcall TTourMainFrame::ReportsStopInfoMenuItemClick(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    try
     {
      Application->CreateForm(__classid(TTourRepStopInfoInputForm),&TourRepStopInfoInputForm);
      TourRepStopInfoInputForm->ShowModal();
      TourRepStopInfoInputForm->Release();
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
  #endif
 }
//---------------------------------------------------------------------------
void __fastcall TTourMainFrame::ReportsTripInfoMenuItemClick(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    try
     {
      Application->CreateForm(__classid(TTourRepTripInfoInputForm),&TourRepTripInfoInputForm);
      TourRepTripInfoInputForm->ShowModal();
      TourRepTripInfoInputForm->Release();
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
  #endif
 }
//---------------------------------------------------------------------------


void __fastcall TTourMainFrame::BaseRegulationActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  #if !defined(TOUR_DEMO_MODE)
   {
    TTourBaseRegulationForm              *FormPtr;
    //
    FormPtr = NULL;

    FormPtr = new TTourBaseRegulationForm(this);

    if (FormPtr != NULL)
     {
      FormPtr->ShowModal();

      delete (FormPtr);
      FormPtr = NULL;
     }
   }
  #endif
 }
//---------------------------------------------------------------------------

