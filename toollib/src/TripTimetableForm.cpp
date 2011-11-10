//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FieldDef.h"
#include "TripTimetableForm.h"
#include "TourTool.h"
#include "TripTimetableInfoForm.h"
#include "TripTimetableRecalcBySpeedForm.h"
#include "DataModuleForm.h"
#include "TripTourMoveDialogForm.h"
#include "TripTourCopyDialogForm.h"
#include "StopSelectForm.h"
#include "MessageModuleForm.h"
#include "SimpleStopDataSetViewForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma link "Placemnt"
#pragma resource "*.dfm"

#define  TripTimeTableHoursPerDay     (24)
#define  TripTimeTableMinutesPerHour  (60)
#define  TripTimeTableMinutesPerDay   (TripTimeTableHoursPerDay * TripTimeTableMinutesPerHour)

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourTripTimeTableDialogForm *TourTripTimeTableDialogForm;

//---------------------------------------------------------------------------
__fastcall TTourTripTimeTableDialogForm::TTourTripTimeTableDialogForm(TComponent* Owner)
 : TForm(Owner),DataStoragePtr(NULL),TourSetPtr(NULL),TourPtr(NULL),TourSchedulePtr(NULL)
 {
  TourIndex = TourTripTimeTableUndefineTourIndex;
 }

//---------------------------------------------------------------------------
__fastcall         TTourTripTimeTableDialogForm::TTourTripTimeTableDialogForm
                   (TComponent                       *Owner,
                    int                               TourIndex,
                    TourDataPtrClass                  DataStoragePtr)//,
//                    TourTourSetPtrClass               TourSetPtr,
//                    TourTopologyPtrClass              TopologyPtr)
                   : TForm(Owner),DataStoragePtr(NULL),TourSetPtr(NULL),
                     TourPtr(NULL),TourSchedulePtr(NULL),TopologyPtr(NULL)
 {
  Init(TourIndex,DataStoragePtr);//,TourSetPtr,TopologyPtr);
 }

//---------------------------------------------------------------------------

bool               TTourTripTimeTableDialogForm::Init
                   (int                               TourIndex,
                    TourDataPtrClass                  DataStoragePtr)//,
//                    TourTourSetPtrClass               TourSetPtr,
//                    TourTopologyPtrClass              TopologyPtr)
 {
  bool                                 ResultFlag;

  this->TourIndex = TourIndex;
  this->DataStoragePtr = DataStoragePtr;

  TourSetPtr  = DataStoragePtr->TourSet();//TourSetPtr;
  StopSetPtr  = DataStoragePtr->StopSet();//TourSetPtr;
  TopologyPtr = DataStoragePtr->Topology();//TopologyPtr;
  TourPtr = TourSetPtr->Tour(TourIndex);
  TourSchedulePtr = TourPtr->Schedule();

  ResultFlag = FillChainListView();

  return (ResultFlag);
 }

//---------------------------------------------------------------------------

bool               TTourTripTimeTableDialogForm::FillChainListView
                   (void)
 {
  TListItem                           *ListItemPtr;
  AnsiString                           StopNameStr;
  TDateTime                            InTimeValue;
  TDateTime                            OutTimeValue;
  TDateTime                            WaitTimeValue;
  unsigned int                         StopCount;
  unsigned int                         StopIndex;
  bool                                 ResultFlag;
  TourStopSchedulePtrClass             StopSchedulePtr(NULL);
  TourStopPtrClass                     StopPtr(NULL);

  ResultFlag = true;

  ChainListView->Items->BeginUpdate();

  ChainListView->Items->Clear();
  StopCount = TourSchedulePtr->StopCount();

  for (StopIndex = 0; (StopIndex < StopCount) && (ResultFlag); StopIndex++)
   {
    ListItemPtr = ChainListView->Items->Add();
    StopSchedulePtr = TourSchedulePtr->StopSchedule(StopIndex);

    if (ListItemPtr != NULL)
     {
      StopPtr = StopSchedulePtr->Stop();

      ListItemPtr->Caption = StopPtr->NameStr().c_str();

      ListItemPtr->SubItems->Append(StopPtr->IdStr().c_str());
      ListItemPtr->SubItems->Append(StopSchedulePtr->InTime().AsStr().c_str());
      ListItemPtr->SubItems->Append
      ((StopSchedulePtr->InTime() + StopSchedulePtr->WaitTime()).AsStr().c_str());
      ListItemPtr->SubItems->Append(StopSchedulePtr->WaitTime().AsStr().c_str());

      if (StopIndex < StopCount - 1)
       {
        ListItemPtr->SubItems->Add
        (FormatFloat
         ("0.0",
          TripDiagramTourStepSpeed(TourSchedulePtr,TopologyPtr,StopIndex)));
//        (TourStepSpeedStr(TourSchedulePtr,StopIndex));

        ListItemPtr->SubItems->Add
        (FormatFloat
         ("0.0",
          TripDiagramTourStepDistance(TourSchedulePtr,TopologyPtr,StopIndex)));
//        (TourStepDistanceStr(TourSchedulePtr,StopIndex));
       }
     }
    else
     {
      ResultFlag = false;
     }
   }

  ChainListView->Items->EndUpdate();

  return (ResultFlag);
 }

void __fastcall TTourTripTimeTableDialogForm::ChangeInfoActionExecute(
      TObject *Sender)
 {
  TTourTripTimetableInfoForm          *TimetableInfoFormPtr;
  //
  if (ChainListView->Selected != NULL)
   {
    TimetableInfoFormPtr = NULL;

    TimetableInfoFormPtr = new TTourTripTimetableInfoForm(this);

    if (TimetableInfoFormPtr != NULL)
     {
      TourStopSchedulePtrClass         StopSchedulePtr(NULL);
      AnsiString                       WorkDateTimeStr;

      TimetableInfoFormPtr->Caption = ChainListView->Selected->Caption;

      StopSchedulePtr = TourSchedulePtr->StopSchedule(ChainListView->Selected->Index);

      TimetableInfoFormPtr->TimeInShortTimePicker->Time
      = TDateTime(StopSchedulePtr->InTime().AsStr().c_str(),TDateTime::Time);

      WorkDateTimeStr = StopSchedulePtr->WaitTime().AsStr().c_str();

      TimetableInfoFormPtr->WaitTimeEmptyCheckBox->Checked = !WorkDateTimeStr.IsEmpty();

      if (TimetableInfoFormPtr->WaitTimeEmptyCheckBox->Checked)
       {
        TimetableInfoFormPtr->TimeWaitShortTimePicker->Time
        = TDateTime(WorkDateTimeStr,TDateTime::Time);

        WorkDateTimeStr// = ChainListView->Selected->SubItems->Strings[2];
        = (StopSchedulePtr->InTime() + StopSchedulePtr->WaitTime()).AsStr().c_str();

        TimetableInfoFormPtr->TimeOutShortTimePicker->Time
        = TDateTime(WorkDateTimeStr,TDateTime::Time);
       }
      else
       {
        TimetableInfoFormPtr->TimeWaitShortTimePicker->Time = TDateTime(0,0,0,0);
        TimetableInfoFormPtr->TimeOutShortTimePicker->Time  = TDateTime(0,0,0,0);
       }

      if (TimetableInfoFormPtr->ShowModal() == mrOk)
       {
        unsigned short                 Hours;
        unsigned short                 Minutes;
        unsigned short                 Sec;
        unsigned short                 MSec;
        TDateTime                      InTime;
        TDateTime                      WaitTime;

        //Обновление расписания
        InTime = TimetableInfoFormPtr->TimeInShortTimePicker->Time;

        ChainListView->Selected->SubItems->Strings[1]
        = TourTimeStrByDateTime(InTime);

        StopSchedulePtr
        ->SetInTime(TourTimeClass(TripDiagramTimeInStrToMinutes(InTime)));

        if (TimetableInfoFormPtr->WaitTimeEmptyCheckBox->Checked)
         {
          WaitTime = TimetableInfoFormPtr->TimeWaitShortTimePicker->Time;

          ChainListView->Selected->SubItems->Strings[2]
          = TourTimeStrByDateTime(TimetableInfoFormPtr->TimeOutShortTimePicker->Time);
          ChainListView->Selected->SubItems->Strings[3]
          = TourTimeStrByDateTime(WaitTime);

          StopSchedulePtr->SetWaitTime
          (TourTimeClass(TourTimeClass(TripDiagramTimeInStrToMinutes(WaitTime))));
         }
        else
         {
          ChainListView->Selected->SubItems->Strings[2] = "";
          ChainListView->Selected->SubItems->Strings[3] = "";
          StopSchedulePtr->SetWaitTime(TourTimeClass());
         }

        if (ChainListView->Selected->Index > 0)
         {
          ChainListView->Items->Item[ChainListView->Selected->Index - 1]->SubItems->Strings[4]
          = FormatFloat
            ("0.0",
             TripDiagramTourStepSpeed(TourSchedulePtr,TopologyPtr,ChainListView->Selected->Index - 1));
         }

        if (ChainListView->Selected->Index < ChainListView->Items->Count - 1)
         {
          ChainListView->Selected->SubItems->Strings[4]
          = FormatFloat
            ("0.0",
             TripDiagramTourStepSpeed(TourSchedulePtr,TopologyPtr,ChainListView->Selected->Index));
         }
/*
        (*ChainStrStorePtr)[ChainListView->Selected->Index].TripStepInTimeStr
        = ChainListView->Selected->SubItems->Strings[1];
        (*ChainStrStorePtr)[ChainListView->Selected->Index].TripStepWaitTimeStr
        = ChainListView->Selected->SubItems->Strings[3];
*/
       }

      delete (TimetableInfoFormPtr);
      TimetableInfoFormPtr = NULL;
     }
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripTimeTableDialogForm::UpdateBySpeedActionExecute(
      TObject *Sender)
 {
  TTourTripTimetableRateSpeedForm     *RecalcBySpeedFormPtr;
  AnsiString                           CaptionStr;
  TourTimeClass                        PreliminaryTime;
  bool                                 ResultFlag;
  //
  ResultFlag = true;

  ChainListView->Items->BeginUpdate();

  if (ChainListView->Selected != NULL)
   {
    RecalcBySpeedFormPtr = NULL;

    RecalcBySpeedFormPtr = new TTourTripTimetableRateSpeedForm(this);

    if (RecalcBySpeedFormPtr != NULL)
     {
      CaptionStr  = RecalcBySpeedFormPtr->Caption;
      CaptionStr += ChainListView->Selected->Caption;

      RecalcBySpeedFormPtr->Caption = CaptionStr;

      if (RecalcBySpeedFormPtr->ShowModal() == mrOk)
       {
        float                          SpeedValue;
        unsigned int                   ItemIndex;
        unsigned int                   StopCount;
        TourTimeClass                  WorkTime;
        TourStopSchedulePtrClass       StopSchedulePtr(NULL);

        StopCount  = TourSchedulePtr->StopCount();
        SpeedValue = StrToFloat(RecalcBySpeedFormPtr->RateSpeedComboBox->Text);
        //Обновление расписания

        ItemIndex = ChainListView->Selected->Index + 1;
        // Время отправления из предыдущего пункта

        StopSchedulePtr = TourSchedulePtr->StopSchedule(ItemIndex - 1);

        if (!StopSchedulePtr->WaitTime().IsEmpty())
         {
          PreliminaryTime
          = (StopSchedulePtr->InTime() + StopSchedulePtr->WaitTime());//.AsStr().c_str();
         }
        else
         {
          PreliminaryTime = StopSchedulePtr->InTime();
         }

        for (ItemIndex; (ItemIndex < StopCount) && (ResultFlag); ItemIndex++)
         {
          // Расчет времени прибытия в следующий пункт
          ResultFlag
          = GetNextStopPreliminaryTimeIn(ItemIndex - 1,SpeedValue,WorkTime);

          if (ResultFlag)
           {
            PreliminaryTime += WorkTime;

            TourSchedulePtr->StopSchedule(ItemIndex)->SetInTime(PreliminaryTime);

            ChainListView->Items->Item[ItemIndex]->SubItems->Strings[1] = PreliminaryTime.AsStr().c_str();

            // Время отправления из следующего пункта

            StopSchedulePtr = TourSchedulePtr->StopSchedule(ItemIndex);

            WorkTime = StopSchedulePtr->WaitTime();

            if (!WorkTime.IsEmpty())
             {
              PreliminaryTime += WorkTime;

              ChainListView->Items->Item[ItemIndex]->SubItems->Strings[2]
              = PreliminaryTime.AsStr().c_str();
             }
           }

          if (ItemIndex < StopCount)
           {
            ChainListView->Items->Item[ItemIndex - 1]->SubItems->Strings[4]
            = FormatFloat
              ("0.0",
               TripDiagramTourStepSpeed(TourSchedulePtr,TopologyPtr,ItemIndex - 1));
           }
         }
       }

      delete (RecalcBySpeedFormPtr);
      RecalcBySpeedFormPtr = NULL;
     }
    else
     {
      ResultFlag = false;
     }
   }

  ChainListView->Items->EndUpdate();
 }
//---------------------------------------------------------------------------

bool               TTourTripTimeTableDialogForm::GetNextStopPreliminaryTimeIn
                   (unsigned int                      StopIndex,
                    float                             SpeedValue,
                    TourTimeClass                    &PreliminaryTimeInRef)
 {
  unsigned short                       HourValue;
  unsigned short                       MinValue;
  bool                                 ResultFlag;

  ResultFlag
  = TripDiagramNextStopPreliminaryTimeIn
    (TourSchedulePtr,TopologyPtr,StopIndex,SpeedValue,HourValue,MinValue);

  if (ResultFlag)
   {
    if (HourValue >= TripTimeTableHoursPerDay)
     {
      AnsiString                       WarningStr;

      WarningStr  = GetTranslatedStr(TourTripTimeTableInvalidTimeValueMessageStr);
      WarningStr += TourSchedulePtr->StopSchedule(StopIndex)->Stop()->NameStr().c_str();
      WarningStr += "-";
      WarningStr += TourSchedulePtr->StopSchedule(StopIndex + 1)->Stop()->NameStr().c_str();
      WarningStr += ".";

      TourShowDialogWarning(WarningStr.c_str());

      HourValue %= TripTimeTableHoursPerDay;
     }

    PreliminaryTimeInRef = TourTimeClass(HourValue,MinValue);
   }

  return (ResultFlag);
 }

void __fastcall TTourTripTimeTableDialogForm::ChainPopupMenuPopup(
      TObject *Sender)
 {
  ChangeInfoMenuItem->Enabled    = false;
  UpdateBySpeedMenuItem->Enabled = false;
  DeleteStopMenuItem->Enabled    = false;
  InsertStopMenuItem->Enabled    = false;

  if (ChainListView->Items->Count > 0)
   {
    if (ChainListView->Selected != NULL)
     {
      ChangeInfoMenuItem->Enabled    = true;
      UpdateBySpeedMenuItem->Enabled = true;
      DeleteStopMenuItem->Enabled    = true;
      InsertStopMenuItem->Enabled    = true;
     }
   }
 }

//---------------------------------------------------------------------------

void __fastcall TTourTripTimeTableDialogForm::MoveActionExecute(
      TObject *Sender)
 {
  bool                                 ResultFlag;
  TTourTripTourMoveDialogForm         *TourMoveDialogPtr;
  TDateTime                            DateTimeValue;

  ResultFlag = true;
  TourMoveDialogPtr = NULL;
  DateTimeValue = TDateTime(TourSchedulePtr->StopSchedule(0)->InTime().AsStr().c_str(),
                            TDateTime::DateTime);

  TourMoveDialogPtr = new TTourTripTourMoveDialogForm(this);

  if (TourMoveDialogPtr != NULL)
   {
    try
     {
      TourMoveDialogPtr->Caption
      = GetTranslatedStr(TourTripTimeTableMoveDialogCaptionStr);
      TourMoveDialogPtr->TourCopyCheckBox->Visible = false;
      TourMoveDialogPtr->TimeStartPicker->Time = DateTimeValue;
     }
    catch (Exception &exception)
     {
      ResultFlag = false;
      TourShowDialogException(NULL,&exception);
     }

    if (ResultFlag)
     {
      if (TourMoveDialogPtr->ShowModal() == mrOk)
       {
        DateTimeValue = TourMoveDialogPtr->TimeStartPicker->Time;

        TripDiagramMoveTour(TourSchedulePtr,DateTimeValue);

        FillChainListView();
       }
     }

    delete (TourMoveDialogPtr);
    TourMoveDialogPtr = NULL;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripTimeTableDialogForm::InvertActionExecute(
      TObject *Sender)
 {

  TTourTripTourMoveDialogForm         *TourMoveDialogPtr;
  bool                                 ResultFlag;
  TDateTime                            DateTimeValue;

  ResultFlag = false;
  TourMoveDialogPtr = NULL;

  TourMoveDialogPtr = new TTourTripTourMoveDialogForm(this);

  if (TourMoveDialogPtr != NULL)
   {
    DateTimeValue = TDateTime(TourSchedulePtr->StopSchedule(0)->InTime().AsStr().c_str(),
                              TDateTime::DateTime);
    try
     {
      TourMoveDialogPtr->Caption
      = GetTranslatedStr(TourTripTimeTableInvertDialogCaptionStr);
      TourMoveDialogPtr->TourCopyCheckBox->Visible = false;
      TourMoveDialogPtr->TimeStartPicker->Time = DateTimeValue;
      ResultFlag = true;
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }

    if (ResultFlag)
     {
      if (TourMoveDialogPtr->ShowModal() == mrOk)
       {
        DateTimeValue = TourMoveDialogPtr->TimeStartPicker->Time;

        ResultFlag = TripDiagramInvertTour(TourSchedulePtr,DataStoragePtr->Topology());

        if (ResultFlag)
         {
          TripDiagramMoveTour(TourSchedulePtr,DateTimeValue);
          FillChainListView();
         }
       }
     }

    delete (TourMoveDialogPtr);
    TourMoveDialogPtr = NULL;
   }
 }
//---------------------------------------------------------------------------
/*

void __fastcall TTourTripTimeTableDialogForm::CopyActionExecute(
      TObject *Sender)
 {
  TTourTripTourMoveDialogForm         *TourMoveDialogPtr;
  bool                                 ResultFlag;
  TDateTime                            DateTimeValue;

  ResultFlag = false;
  TourMoveDialogPtr = NULL;

  TourShowDialogInformation("Сохранить изменения в текущем рейсе?");

  TourMoveDialogPtr = new TTourTripTourMoveDialogForm(this);

  if (TourMoveDialogPtr != NULL)
   {
    DateTimeValue = TDateTime(TourSchedulePtr->StopSchedule(0)->InTime().AsStr().c_str(),
                              TDateTime::DateTime);
    try
     {
      TourMoveDialogPtr->Caption
      = GetTranslatedStr(TourTripTimeTableCopyDialogCaptionStr);
      TourMoveDialogPtr->TourCopyCheckBox->Visible = false;
      TourMoveDialogPtr->TimeStartPicker->DateTime = DateTimeValue;
      ResultFlag = true;
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }

    if (ResultFlag)
     {
      if (TourMoveDialogPtr->ShowModal() == mrOk)
       {
        TTourTripTourCopyDialogForm   *TourCopyDialogFormPtr;
        AnsiString                     TripIdStr;
        AnsiString                     TripNameStr;
        AnsiString                     TripFirstNameStr;
        AnsiString                     TripSecondNameStr;

        ResultFlag = TripDiagramTourCopyAttributes
                     (TourSetPtr,TourIndex,TripIdStr,TripFirstNameStr,TripSecondNameStr);

        if (ResultFlag)
         {
          TourCopyDialogFormPtr = NULL;

          TourCopyDialogFormPtr = new TTourTripTourCopyDialogForm(this);

          if (TourCopyDialogFormPtr != NULL)
           {
    //      TourCopyDialogFormPtr->Caption
    //      = GetTranslatedStr(TourTripDiagramCopyDialogCaptionStr);

            TourCopyDialogFormPtr->TripIdEdit->Text   = TripIdStr;
            TourCopyDialogFormPtr->TripNameEdit->Text
            = TripFirstNameStr + "-" + TripSecondNameStr;

            if (TourCopyDialogFormPtr->ShowModal() == mrOk)
             {
              TripIdStr = TourCopyDialogFormPtr->TripIdEdit->Text;
              TripNameStr = TourCopyDialogFormPtr->TripNameEdit->Text;
             }
            else
             {
              ResultFlag = false;
             }

            delete (TourCopyDialogFormPtr);
            TourCopyDialogFormPtr = NULL;
           }
          else
           {
            ResultFlag = false;
           }

          if (ResultFlag)
           {
            TourTourPtrClass                     SrcTourPtr(NULL);
            TourTourPtrClass                     TourCopyPtr(NULL);

            SrcTourPtr = DataStoragePtr->TourSet()->Tour(TourIndex);

            TourCopyPtr = TripDiagramAppendTour(DataStoragePtr,TripIdStr);

  //          UpdateTour();

            TripDiagramFillTour(TourCopyPtr,SrcTourPtr);

            TripDiagramMoveTour(TourCopyPtr->Schedule(),DateTimeValue);

            FillChainListView();
           }
         }
       }
     }
    delete (TourMoveDialogPtr);
    TourMoveDialogPtr = NULL;
   }
 }
*/
//---------------------------------------------------------------------------

void __fastcall TTourTripTimeTableDialogForm::DeleteStopActionExecute(
      TObject *Sender)
 {
/*
  #if !defined(TOUR_DEMO_MODE)
*/  
   {
    if (ChainListView->Selected != NULL)
     {
      unsigned int                       StopCount;
      unsigned int                       StopIndex;

      StopCount = TourSchedulePtr->StopCount();
      StopIndex = ChainListView->Selected->Index;

      if ((StopIndex == 0) || (StopIndex == StopCount - 1))
       {
        TourSchedulePtr->DeleteStopSchedule(StopIndex);//StopSchedule();
        FillChainListView();
       }
      else
       {
        TourStopPtrClass                 FromStopPtr;
        TourStopPtrClass                 ToStopPtr;
  //      std::string                      FromStopIdStr;
  //      std::string                      ToStopIdStr;

        FromStopPtr = TourSchedulePtr->StopSchedule(StopIndex - 1)->Stop();
        ToStopPtr   = TourSchedulePtr->StopSchedule(StopIndex + 1)->Stop();
  //      FromStopIdStr = TourSchedulePtr->StopSchedule(StopIndex - 1)->Stop()->IdStr();
  //      ToStopIdStr   = TourSchedulePtr->StopSchedule(StopIndex + 1)->Stop()->IdStr();

         if (TopologyPtr->DirectLinkExists(FromStopPtr->IdStr(),ToStopPtr->IdStr()))
  //      if (DirectLinkExists(FromStopIdStr,ToStopIdStr))
         {
          TourSchedulePtr->DeleteStopSchedule(StopIndex);//StopSchedule();
          FillChainListView();
         }
        else
         {
          TourShowDialogError("Отсутствует топология");
         }
       }
     }
   }
/*
  #else
   {
    TourShowDialogInformation
    (TourMessageModule->VStringStorage->Lines->Strings
     [TourMessageModuleFuncDemoMessageStr].c_str());
   }
  #endif
*/
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripTimeTableDialogForm::AppendStopActionExecute(
      TObject *Sender)
 {
/*
  #if !defined(TOUR_DEMO_MODE)
*/  
   {
/*
    TTourRefBookStopSelectForm          *StopSelectDialogPtr;

    StopSelectDialogPtr = NULL;

    try
     {
      StopSelectDialogPtr = new TTourRefBookStopSelectForm(this);

      if (StopSelectDialogPtr != NULL)
       {
        if (StopSelectDialogPtr->ShowModal() == mrOk)
         {
          TourSchedulePtr
          ->AppendStopSchedule
            (StopSelectDialogPtr->MainQuery->FieldByName("stop_id")->AsString.c_str());
          FillChainListView();
         }

        delete (StopSelectDialogPtr);
       }
     }
    catch (...)
     {
      //
     }
*/     
    TTourSimpleStopDataSetViewForm    *StopSelectDialogPtr;

    StopSelectDialogPtr = NULL;

    try
     {
      StopSelectDialogPtr = new TTourSimpleStopDataSetViewForm(this);

      if (StopSelectDialogPtr != NULL)
       {
        unsigned int                   StopCount;
        unsigned int                   StopIndex;
        bool                           ResultFlag;
        TListItem                     *ListItemPtr;
        TourStopPtrClass               StopPtr(NULL);

        ResultFlag = true;
        StopSelectDialogPtr->ListView->Items->Clear();
        StopCount = TourSetPtr->Count();

        for (StopIndex = 0; (StopIndex < StopCount) && (ResultFlag); StopIndex++)
         {
          ListItemPtr = StopSelectDialogPtr->ListView->Items->Add();
          StopPtr = StopSetPtr->Stop(StopIndex);

          if (ListItemPtr != NULL)
           {
            ListItemPtr->Caption = StopPtr->IdStr().c_str();

            ListItemPtr->SubItems->Append(StopPtr->NameStr().c_str());
           }
          else
           {
            ResultFlag = false;
           }
         }

        if (StopSelectDialogPtr->ShowModal() == mrOk)
         {
          TourStopSchedulePtrClass     StopSchedulePtr;

          StopSchedulePtr
          = TourSchedulePtr
            ->AppendStopSchedule(StopSelectDialogPtr->ListView->Selected->Caption.c_str());
          StopSchedulePtr->SetInTime(TourTimeClass(0));

          FillChainListView();

          ChainListView->Selected = ChainListView->Items->Item[ChainListView->Items->Count - 1];

          ChangeInfoActionExecute(Sender);
         }

        delete (StopSelectDialogPtr);
       }
     }
    catch (...)
     {
      //
     }
   }
/*
  #else
   {
    TourShowDialogInformation
    (TourMessageModule->VStringStorage->Lines->Strings
     [TourMessageModuleFuncDemoMessageStr].c_str());
   }
  #endif
*/  
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripTimeTableDialogForm::InsertStopActionExecute(
      TObject *Sender)
 {
/*
  #if !defined(TOUR_DEMO_MODE)
*/
   {
    if (ChainListView->Selected != NULL)
     {
/*
      TTourRefBookStopSelectForm        *StopSelectDialogPtr;
      unsigned int                       StopIndex;

      StopIndex = ChainListView->Selected->Index;
      StopSelectDialogPtr = NULL;

      try
       {
        StopSelectDialogPtr = new TTourRefBookStopSelectForm(this);

        if (StopSelectDialogPtr != NULL)
         {
          if (StopSelectDialogPtr->ShowModal() == mrOk)
           {
            bool                         CanInsertStopFlag;
            std::string                  FromStopIdStr;
            std::string                  ToStopIdStr;
            std::string                  InsertStopIdStr;
            std::string                  InsertStopNameStr;

            InsertStopIdStr
            = StopSelectDialogPtr->MainQuery->FieldByName("stop_id")->AsString.c_str();

            if (StopIndex == 0)
             {
              FromStopIdStr = InsertStopIdStr;
              ToStopIdStr   = TourSchedulePtr->StopSchedule(0)->Stop()->IdStr();

              CanInsertStopFlag = TopologyPtr->DirectLinkExists(FromStopIdStr,ToStopIdStr);
             }
            else
             {
              FromStopIdStr = TourSchedulePtr->StopSchedule(StopIndex - 1)->Stop()->IdStr();
              ToStopIdStr   = InsertStopIdStr;

              CanInsertStopFlag = TopologyPtr->DirectLinkExists(FromStopIdStr,ToStopIdStr);

              if (CanInsertStopFlag)
               {
                FromStopIdStr = InsertStopIdStr;
                ToStopIdStr   = TourSchedulePtr->StopSchedule(StopIndex)->Stop()->IdStr();

                CanInsertStopFlag = TopologyPtr->DirectLinkExists(FromStopIdStr,ToStopIdStr);
               }
             }

            if (CanInsertStopFlag)
             {
              TourStopSchedulePtrClass   StopSchedulePtr;

              StopSchedulePtr = TourSchedulePtr->InsertStopSchedule(StopIndex,InsertStopIdStr);
              // StopSchedulePtr->SetName(InsertStopNameStr);

              StopSchedulePtr->SetInTime(TourTimeClass(0));
              StopSchedulePtr->SetWaitTime(TourTimeClass());

              FillChainListView();

              ChainListView->Selected = ChainListView->Items->Item[StopIndex];

              ChangeInfoActionExecute(Sender);
             }
            else
             {
              TourShowDialogError("Отсутствует топология");
             }
           }
*/
      TTourSimpleStopDataSetViewForm  *StopSelectDialogPtr;
      unsigned int                     SelStopIndex;

      SelStopIndex = ChainListView->Selected->Index;
      StopSelectDialogPtr = NULL;

      try
       {
        StopSelectDialogPtr = new TTourSimpleStopDataSetViewForm(this);

        if (StopSelectDialogPtr != NULL)
         {
          unsigned int                 StopCount;
          unsigned int                 StopIndex;
          bool                         ResultFlag;
          TListItem                   *ListItemPtr;
          TourStopPtrClass             StopPtr(NULL);

          ResultFlag = true;
          StopSelectDialogPtr->ListView->Items->Clear();
          StopCount = TourSetPtr->Count();

          for (StopIndex = 0; (StopIndex < StopCount) && (ResultFlag); StopIndex++)
           {
            ListItemPtr = StopSelectDialogPtr->ListView->Items->Add();
            StopPtr = StopSetPtr->Stop(StopIndex);

            if (ListItemPtr != NULL)
             {
              ListItemPtr->Caption = StopPtr->IdStr().c_str();

              ListItemPtr->SubItems->Append(StopPtr->NameStr().c_str());
             }
            else
             {
              ResultFlag = false;
             }
           }

          if (StopSelectDialogPtr->ShowModal() == mrOk)
           {
            bool                         CanInsertStopFlag;
            std::string                  FromStopIdStr;
            std::string                  ToStopIdStr;
            std::string                  InsertStopIdStr;
            std::string                  InsertStopNameStr;

            InsertStopIdStr
            = StopSelectDialogPtr->ListView->Selected->Caption.c_str();

            if (SelStopIndex == 0)
             {
              FromStopIdStr = InsertStopIdStr;
              ToStopIdStr   = TourSchedulePtr->StopSchedule(0)->Stop()->IdStr();

              CanInsertStopFlag = TopologyPtr->DirectLinkExists(FromStopIdStr,ToStopIdStr);
             }
            else
             {
              FromStopIdStr = TourSchedulePtr->StopSchedule(SelStopIndex - 1)->Stop()->IdStr();
              ToStopIdStr   = InsertStopIdStr;

              CanInsertStopFlag = TopologyPtr->DirectLinkExists(FromStopIdStr,ToStopIdStr);

              if (CanInsertStopFlag)
               {
                FromStopIdStr = InsertStopIdStr;
                ToStopIdStr   = TourSchedulePtr->StopSchedule(SelStopIndex)->Stop()->IdStr();

                CanInsertStopFlag = TopologyPtr->DirectLinkExists(FromStopIdStr,ToStopIdStr);
               }
             }

            if (CanInsertStopFlag)
             {
              TourStopSchedulePtrClass   StopSchedulePtr;

              StopSchedulePtr = TourSchedulePtr->InsertStopSchedule(SelStopIndex,InsertStopIdStr);
              // StopSchedulePtr->SetName(InsertStopNameStr);

              StopSchedulePtr->SetInTime(TourTimeClass(0));
              StopSchedulePtr->SetWaitTime(TourTimeClass());

              FillChainListView();

              ChainListView->Selected = ChainListView->Items->Item[SelStopIndex];

              ChangeInfoActionExecute(Sender);
             }
            else
             {
              TourShowDialogError("Отсутствует топология");
             }
           }

          delete (StopSelectDialogPtr);
         }
       }
      catch (...)
       {
        //
       }
     }
   }
/*
  #else
   {
    TourShowDialogInformation
    (TourMessageModule->VStringStorage->Lines->Strings
     [TourMessageModuleFuncDemoMessageStr].c_str());
   }
  #endif
*/
 }
//---------------------------------------------------------------------------


void __fastcall TTourTripTimeTableDialogForm::PanelResize(TObject *Sender)
 {
  //
  CancelButton->Left = Panel->Width - CancelButton->Width - Panel->Tag;
  NextButton->Left   = CancelButton->Left - NextButton->Width - Panel->Tag;
 }
//---------------------------------------------------------------------------

