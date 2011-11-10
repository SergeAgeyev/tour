//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <vector>
#include <string>
#include <assert.h>

#include "TourTool.h"
#include "FieldDef.h"
#include <VCanvas.h>
#include "TripDiagramForm.h"
#include "TripDiagramOptionsForm.h"
#include "TripDiagramPrinter.h"
#include "TripSwitchDialogForm.h"
#include "TripTimetableForm.h"
#include "TripTourMoveDialogForm.h"
#include "TripTourCopyDialogForm.h"
#include "TourTime.h"
#include "TourData.h"
#include "MessageModuleForm.h"

#include "RepStopInfoGenerator.h"
#include "RepTripInfoGenerator.h"

#if !defined(TOUR_DEMO_MODE)
 #include "TourDataDB.h"
 #include "DataModuleForm.h"
#else
 #include "TourDataDM.h"
 #include "TourDemoData.h"
#endif

#include "TourDataCA.h"
#include "TourDataSF.h"
#include "MessageModuleForm.h"
#include "TripDiagramChangesForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RXDBCtrl"
#pragma link "VDBSortGrid"
#pragma link "VDBLookupComboBox"
#pragma link "Placemnt"
#pragma link "VADODataSourceOrdering"
#pragma link "VCustomDataSourceOrdering"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourTripDiagramForm *TourTripDiagramForm;

enum TourTripDiagramStringTypes
 {
  TourTripDiagramMoveDialogCaptionStr = 0,
  TourTripDiagramInvertDialogCaptionStr,
  TourTripDiagramCopyDialogCaptionStr,
  TourTripDiagramCancelChangesMessageStr,
  TourTripDiagramApplyCheckedChangesMessageStr,
  TourTripDiagramCancelCheckedChangesMessageStr,
  TourTripDiagramChangesAbsentMessageStr,
  TourTripDiagramConfirmDeleteMessageStr,
  TourTripDiagramChangesSaveOkMessageStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

#define TripDiagramChartBgColor            (clWhite)
#define TripDiagramChartTimeAxisColor      (clBlack)
#define TripDiagramChartDistanceAxisColor  (clBlack)

#define TripDiagramChartGridColor          (VCanvasColorFromRGB(0xE0,0xE0,0xE0))

#define TripDiagramChartMonoColorTourColor         (VCanvasColorFromRGB(0x80,0x80,0x80))
#define TripDiagramChartMonoColorSelectedTourColor (VCanvasColorFromRGB(0x00,0x00,0xFF))

#define TripDiagramChartShowForwardToursFlag  (true)
#define TripDiagramChartShowBackwardToursFlag (false)

#define TripDiagramChartDefaultBaseSpeed      (60.0)
#define TripDiagramChartDefaultBaseSpeedAngle (75)

#define TripDiagramChartDefaultDistanceViewScaleFactor (3.0)
#define TripDiagramChartDefaultTimeViewScaleFactor     (3.0)

#define TripDiagramChartRowSize     (10)
#define TripDiagramChartRowWidth    (3)
#define TripDiagramChartRowLength   (5)

#define TripDiagramHoursPerDay      (24)
#define TripDiagramMinutesPerHour   (60)
#define TripDiagramMinutesPerDay    (TripDiagramHoursPerDay * TripDiagramMinutesPerHour)

#define TripDiagramChartAxisOffsetX (20)
#define TripDiagramChartAxisOffsetY (50)

#define TripDiagramPI               (3.1415926)
#define TripDiagramFullAngleInGrad  (180)
#define TripDiagramGradToRad(Angle) (Angle * TripDiagramPI / 180)

#define DeclaredArraySize(Array) (sizeof(Array) / sizeof(Array[0]))

#define TripDiagramTourListViewIconSize    (10)

#define TripDiagramCanvasWin9XMaxWidth     (32767)
#define TripDiagramCanvasWin9XMaxHeight    (32767)

#define TripDiagramTourCopyTokenStr        "~"
#define TripDiagramBracketDirectSymbolStr  "("
#define TripDiagramBracketInverseSymbolStr ")"

#define TripDiagramFloatMinValue           (0.0005)

#define TripDiagramFloatIsZero(Value)      (fabs(Value) < TripDiagramFloatMinValue)

static
 VCanvasColorType
  TourColorSetArray[] =
   {
    VCanvasColorFromRGB(0xFF,0x00,0x00),
    VCanvasColorFromRGB(0x00,0xFF,0x00),
    VCanvasColorFromRGB(0x00,0x00,0xFF),
    VCanvasColorFromRGB(0xFF,0xFF,0x00),
    VCanvasColorFromRGB(0x00,0xFF,0xFF),
    VCanvasColorFromRGB(0xFF,0x00,0xFF),
    VCanvasColorFromRGB(0x7F,0x00,0x00),
    VCanvasColorFromRGB(0x00,0x7F,0x00),
    VCanvasColorFromRGB(0x00,0x00,0x7F),
    VCanvasColorFromRGB(0x7F,0x7F,0x00),
    VCanvasColorFromRGB(0x00,0x7F,0x7F),
    VCanvasColorFromRGB(0x7F,0x00,0x7F),
    VCanvasColorFromRGB(0xFF,0x7F,0x00),
    VCanvasColorFromRGB(0x7F,0xFF,0x00),
    VCanvasColorFromRGB(0x00,0x7F,0xFF),
    VCanvasColorFromRGB(0x00,0xFF,0x7F),
    VCanvasColorFromRGB(0x7F,0x00,0xFF),
    VCanvasColorFromRGB(0xFF,0x00,0x7F)
   };

static char ChartCanvasTourIndexTagStr[] = "TourIndex";
static char ChartCanvasStopIndexTagStr[] = "StopIndex";

unsigned int       TripDiagramTourIndexById
                   (TourTourSetPtrClass               TourSetPtr,
                    AnsiString                        TourIdStr)
 {
  unsigned int                         TourIndex;
  unsigned int                         TourCount;
  bool                                 FindFlag;

  TourCount = TourSetPtr->Count();
  FindFlag  = false;

  for (TourIndex = 0;(TourIndex < TourCount) && (!FindFlag);TourIndex++)
   {
    if (AnsiString(TourSetPtr->Tour(TourIndex)->IdStr().c_str()) == TourIdStr)
     {
      FindFlag = true;
     }
   }

  if (!FindFlag)
   {
    TourIndex = TripDiagramTourIndexUndefined;
   }
  else
   {
    TourIndex--;
   }

  return (TourIndex);
 }

//---------------------------------------------------------------------------

int                TripDiagramCompareDouble
                   (AnsiString                        FirstValueStr,
                    AnsiString                        SecondValueStr)
 {
  int                                  Compare;
  float                                FirstValue;
  float                                SecondValue;

  try
   {
    FirstValue  = StrToFloat(FirstValueStr);
    SecondValue = StrToFloat(SecondValueStr);

    if (FirstValue > SecondValue)
     {
      Compare = 1;
     }
    else if (FirstValue < SecondValue)
     {
      Compare = -1;
     }
    else
     {
      Compare = 0;
     }
   }
  catch (...)
   {
    Compare = 0;
   }

  return (Compare);
 }

//---------------------------------------------------------------------------

int                TripDiagramCompareTime
                   (AnsiString                        Time1ValueStr,
                    AnsiString                        Time2ValueStr)
 {
  int                                  Compare;
  TDateTime                            Time1Value;
  TDateTime                            Time2Value;

  if (!Time1ValueStr.IsEmpty() && Time2ValueStr.IsEmpty())
   {
    Compare = -1;
   }
  else if (Time1ValueStr.IsEmpty() && !Time2ValueStr.IsEmpty())
   {
    Compare = 1;
   }
  else if (!Time1ValueStr.IsEmpty() && !Time2ValueStr.IsEmpty())
   {
    try
     {
      Time1Value = TDateTime(Time1ValueStr,TDateTime::Time);
      Time2Value = TDateTime(Time2ValueStr,TDateTime::Time);

      if (Time1Value > Time2Value)
       {
        Compare = 1;
       }
      else if (Time1Value < Time2Value)
       {
        Compare = -1;
       }
      else
       {
        Compare = 0;
       }
     }
    catch (...)
     {
      Compare = 0;
     }
   }
  else
   {
    Compare = 0;
   }

  return (Compare);
 }

//---------------------------------------------------------------------------

bool               TripDiagramTourIsACopy
                   (TourTourSetPtrClass               TourSetPtr,
                    unsigned int                      TourIndex)
 {
  bool                                 ResultFlag;
  AnsiString                           TourIdStr;

  ResultFlag   = false;

  TourIdStr = TourSetPtr->Tour(TourIndex)->IdStr().c_str();

  if (TourIdStr.Pos(TripDiagramTourCopyTokenStr) == 1)
   {
    ResultFlag = true;
   }

  return (ResultFlag);
 }

bool               TripDiagramTourCopyAttributes
                   (TourTourSetPtrClass               TourSetPtr,
                    unsigned int                      TourIndex,
                    AnsiString                       &TourIdStrRef,
                    AnsiString                       &TourFirstNameStrRef,
                    AnsiString                       &TourSecondNameStrRef)
 {
  bool                                 ResultFlag;
  int                                  InverseBracketPos;
  unsigned int                         MaxCopyIndex;
  unsigned int                         TourCount;
  unsigned int                         StopCount;
  AnsiString                           TourIdStr;
  AnsiString                           WorkTourIdStr;
  AnsiString                           WorkTourCopyIdStr;
  AnsiString                           MaxCopyStr;
  TourTourPtrClass                     TourPtr(NULL);
  TourTourSchedulePtrClass             TourSchedulePtr(NULL);

  ResultFlag   = false;
  MaxCopyIndex = 1;

  TourPtr         = TourSetPtr->Tour(TourIndex);
  TourSchedulePtr = TourPtr->Schedule();
  TourCount       = TourSetPtr->Count();
  StopCount       = TourSchedulePtr->StopCount();

  TourIdStr   = TourPtr->IdStr().c_str();
  TourFirstNameStrRef
  = TourSchedulePtr->StopSchedule(0)->Stop()->NameStr().c_str();
  TourSecondNameStrRef
  = TourSchedulePtr->StopSchedule(StopCount - 1)->Stop()->NameStr().c_str();

  if (TripDiagramTourIsACopy(TourSetPtr,TourIndex))
   {
    TourIdStr = TourIdStr.SubString(2,TourIdStr.Length() - 1);
   }

  WorkTourIdStr
  = TripDiagramTourCopyTokenStr + TourIdStr + TripDiagramBracketDirectSymbolStr;

  try
   {
    for (TourIndex = 0; TourIndex < TourCount; TourIndex++)
     {
      WorkTourCopyIdStr = TourSetPtr->Tour(TourIndex)->IdStr().c_str();

      if (WorkTourCopyIdStr.Pos(WorkTourIdStr) == 1)
       {
        InverseBracketPos = WorkTourCopyIdStr.Length();

        if (AnsiString
            (WorkTourCopyIdStr[InverseBracketPos]) == TripDiagramBracketInverseSymbolStr)
         {
          MaxCopyStr = WorkTourCopyIdStr.SubString(WorkTourIdStr.Length() + 1,
                                                   InverseBracketPos - WorkTourIdStr.Length() - 1);

          if (StrToInt(MaxCopyStr) > MaxCopyIndex)
           {
            MaxCopyIndex = StrToInt(MaxCopyStr);
           }
         }
       }
     }

    MaxCopyIndex++;

    TourIdStrRef
    = WorkTourIdStr + IntToStr(MaxCopyIndex) + TripDiagramBracketInverseSymbolStr;

    ResultFlag = true;
   }
  catch (...)
   {
    //
   }

  return (ResultFlag);
 }

bool               TripDiagramPrepareToReflectTour
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr)
 {
  bool                                 ResultFlag;
  unsigned int                         StopIndex;
  unsigned int                         StopCount;
  AnsiString                           StopIdStr;
  AnsiString                           NextStopIdStr;

  ResultFlag = true;
  StopIndex  = 0;
  StopCount  = TourSchedulePtr->StopCount();

  while ((StopIndex < (StopCount - 1)) && (ResultFlag))
   {
    StopIdStr = TourSchedulePtr->StopSchedule(StopIndex)->Stop()->IdStr().c_str();
    NextStopIdStr
    = TourSchedulePtr->StopSchedule(StopIndex + 1)->Stop()->IdStr().c_str();

    ResultFlag
    = TopologyPtr->DirectLinkExists(NextStopIdStr.c_str(),StopIdStr.c_str());
//    = TourCheckPathExist(QuotedStr(NextStopIdStr),QuotedStr(StopIdStr));

    if (!ResultFlag)
     {
/*
      ResultFlag
      = TourPathRecordAppendDialog(QuotedStr(NextStopIdStr),QuotedStr(StopIdStr));
*/
      TourShowDialogInformation
      (TourMessageModule->VStringStorage->Lines->Strings
       [TourMessageModuleBaseRegulationMessageStr].c_str());
     }

    if (ResultFlag)
     {
      StopIndex++;
     }
   }

  return (ResultFlag);
 }

bool               TripDiagramMoveTour
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TDateTime                         DateTimeValue)
 {
  TDateTime                            StartDateTime;
  AnsiString                           NewInTimeStr;
  unsigned int                         TourStepIndex;
  unsigned int                         TourStepCount;
  unsigned int                         InTimeValue;
  unsigned int                         NewInTimeValue;
  int                                  ShiftTimeValue;
  bool                                 ResultFlag;
  TourStopSchedulePtrClass             StopSchedulePtr(NULL);

  assert(!TourSchedulePtr.IsNull());

  NewInTimeStr = DateTimeValue.TimeString();

  TourStepIndex = 0;
  ResultFlag    = true;
  TourStepCount = TourSchedulePtr->StopCount();

  // Вычисляем величину сдвига
  InTimeValue = TourSchedulePtr->StopSchedule(TourStepIndex)->InTime();

  NewInTimeValue = TripDiagramTimeInStrToMinutes(NewInTimeStr);

  ShiftTimeValue = NewInTimeValue - InTimeValue;

  if (ShiftTimeValue != 0)
   {
    // Смещаем расписание рейса на величину сдвига
    for (TourStepIndex;
         (TourStepIndex < TourStepCount) && (ResultFlag);
         TourStepIndex++)
     {
      StopSchedulePtr = TourSchedulePtr->StopSchedule(TourStepIndex);

      InTimeValue = StopSchedulePtr->InTime();

      if (((int)InTimeValue) < ((int)-ShiftTimeValue))
       {
        InTimeValue
        = TripDiagramMinutesPerDay + (InTimeValue + ShiftTimeValue);
       }
      else
       {
        InTimeValue += ShiftTimeValue;

        if (InTimeValue >= TripDiagramMinutesPerDay)
         {
          InTimeValue -= TripDiagramMinutesPerDay;
         }
       }

      StopSchedulePtr->SetInTime(TourTimeClass(InTimeValue));
     }
   }
  return (ResultFlag);
 }

bool               TripDiagramCanReflectTour
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr)
 {
  bool                                 ResultFlag;
  unsigned int                         StopIndex;
  unsigned int                         StopCount;
  AnsiString                           StopIdStr;
  AnsiString                           NextStopIdStr;

  ResultFlag = true;
  StopIndex  = 0;
  StopCount  = TourSchedulePtr->StopCount();

  while ((StopIndex < (StopCount - 1)) && (ResultFlag))
   {
    StopIdStr = TourSchedulePtr->StopSchedule(StopIndex)->Stop()->IdStr().c_str();
    NextStopIdStr
    = TourSchedulePtr->StopSchedule(StopIndex + 1)->Stop()->IdStr().c_str();

    ResultFlag
    = TopologyPtr->DirectLinkExists(NextStopIdStr.c_str(),StopIdStr.c_str());
//    = TourCheckPathExist(QuotedStr(NextStopIdStr),QuotedStr(StopIdStr));

    if (ResultFlag)
     {
      StopIndex++;
     }
   }

  return (ResultFlag);
 }

bool               TripDiagramReflectTour
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr)
 {
  unsigned int                     StopIndex;
  unsigned int                     StopNumber;
  unsigned int                     StopCount;
  unsigned int                     StopFromIndex;
  unsigned int                     StopToIndex;
  TDateTime                        InTimeValue;
  bool                             ResultFlag;
  unsigned int                     FromInTimeValue;
  unsigned int                     FromWaitTimeValue;
  unsigned int                     ToInTimeValue;
  unsigned int                     ToWaitTimeValue;
  unsigned int                     NewInTimeValue;
  unsigned int                     StoredNewInTimeValue;
  TourStopSchedulePtrClass         StopSchedulePtr(NULL);
  TourStopSchedulePtrClass         NewStopSchedulePtr(NULL);
  TourStopSchedulePtrClass         ToStopSchedulePtr(NULL);
  TourStopSchedulePtrClass         FromStopSchedulePtr(NULL);
  TourStopPtrClass                 StopPtr(NULL);
  TourTimeClass                    WorkTime;

  // Проверка возможности инвертирования рейса
  // (наличие соответствующей топологии)

  ResultFlag = TripDiagramCanReflectTour(TourSchedulePtr,TopologyPtr);

  if (!ResultFlag)
   {
    if (TourShowDialogYesNo
        (TourMessageModule->VStringStorage->Lines->Strings
         [TourMessageModuleInvertExpectedMoreDataMessageStr].c_str()) == ID_YES)
     {
      ResultFlag = TripDiagramPrepareToReflectTour(TourSchedulePtr,TopologyPtr);
     }
   }

  if (ResultFlag)
   {
    StopCount = TourSchedulePtr->StopCount();
    // Инвертирование порядка следования остановочных пунктов рейса
    for (StopNumber = StopCount; StopNumber > 0; StopNumber--)
     {
      StopIndex       = StopNumber - 1;

      StopSchedulePtr = TourSchedulePtr->StopSchedule(StopIndex);
      StopPtr         = StopSchedulePtr->Stop();

      NewStopSchedulePtr = TourSchedulePtr->AppendStopSchedule(StopPtr->IdStr());

      WorkTime = TourSchedulePtr->StopSchedule(StopIndex)->WaitTime();

      NewStopSchedulePtr->SetWaitTime(WorkTime);

      WorkTime = TourSchedulePtr->StopSchedule(StopIndex)->InTime();

      NewStopSchedulePtr->SetInTime(WorkTime);
     }

    for (StopIndex = 0; StopIndex < StopCount; StopIndex++)
     {
      TourSchedulePtr->DeleteStopSchedule(0);
     }

    StoredNewInTimeValue = TourSchedulePtr->StopSchedule(0)->InTime();

    // Корректировка расписания
    for (StopIndex = 0; StopIndex < StopCount - 1; StopIndex++)
     {
      ToStopSchedulePtr   = TourSchedulePtr->StopSchedule(StopIndex);
      FromStopSchedulePtr = TourSchedulePtr->StopSchedule(StopIndex + 1);

      ToInTimeValue   = ToStopSchedulePtr->InTime();

      WorkTime = ToStopSchedulePtr->WaitTime();

      if (!WorkTime.IsEmpty())
       {
        ToWaitTimeValue = WorkTime;
       }
      else
       {
        ToWaitTimeValue = 0;
       }

      FromInTimeValue   = FromStopSchedulePtr->InTime();

      WorkTime = FromStopSchedulePtr->WaitTime();

      if (!WorkTime.IsEmpty())
       {
        FromWaitTimeValue = WorkTime;
       }
      else
       {
        FromWaitTimeValue = 0;
       }

      NewInTimeValue = StoredNewInTimeValue + ToWaitTimeValue;

      if ((FromInTimeValue + FromWaitTimeValue) < ToInTimeValue)
       {
        NewInTimeValue += (ToInTimeValue - FromInTimeValue - FromWaitTimeValue);
       }
      else
       {
        NewInTimeValue
        += (TripDiagramMinutesPerDay - FromInTimeValue - FromWaitTimeValue) + ToInTimeValue;
       }

      if (NewInTimeValue > TripDiagramMinutesPerDay)
       {
        NewInTimeValue -= TripDiagramMinutesPerDay;
       }

      ToStopSchedulePtr->SetInTime(TourTimeClass(StoredNewInTimeValue));

      StoredNewInTimeValue = NewInTimeValue;
     }

    TourStopSchedulePtrClass           WorkStopSchedulePtr(NULL);
    TourTimeClass                      WorkTime;

    WorkStopSchedulePtr = TourSchedulePtr->StopSchedule(0);

    if (WorkStopSchedulePtr->WaitTime().IsEmpty())
     {
      WorkTime.SetZero();
      WorkStopSchedulePtr->SetWaitTime(WorkTime);
     }

    WorkStopSchedulePtr = TourSchedulePtr->StopSchedule(StopCount - 1);

    WorkStopSchedulePtr->SetInTime(TourTimeClass(StoredNewInTimeValue));
    WorkTime.SetEmpty();
    WorkStopSchedulePtr->SetWaitTime(WorkTime);
   }

  return (ResultFlag);
 }

extern TourTourPtrClass
                   TripDiagramAppendTour
                   (TourDataPtrClass                  TourDataPtr,
                    AnsiString                        NewTourIdStr,
                    AnsiString                        NewTourNameStr)
 {
  TourTourPtrClass                     TourPtr;

  TourPtr = TourDataPtr->AppendTour(std::string(NewTourIdStr.c_str()));

  TourPtr->SetName(NewTourNameStr.c_str());

  return (TourPtr);
 }

extern void        TripDiagramFillTour
                   (TourTourPtrClass                  DestTourPtr,
                    TourTourPtrClass                  SrcTourPtr)
 {
  unsigned int                     StopIndex;
  unsigned int                     StopCount;
  TourTourSchedulePtrClass         DestTourSchedulePtr(NULL);
  TourTourSchedulePtrClass         SrcTourSchedulePtr(NULL);
  TourStopSchedulePtrClass         DestTourStopSchedulePtr(NULL);
  TourStopSchedulePtrClass         SrcTourStopSchedulePtr(NULL);

  DestTourSchedulePtr = DestTourPtr->Schedule();
  SrcTourSchedulePtr  = SrcTourPtr->Schedule();

  DestTourPtr->SetBusModel(SrcTourPtr->Bus()->ModelStr());

  StopCount = DestTourSchedulePtr->StopCount();

  for (StopIndex = 0;StopIndex < StopCount;StopIndex++)
   {
    DestTourSchedulePtr->DeleteStopSchedule(StopIndex);
   }

  StopCount = SrcTourSchedulePtr->StopCount();

  for (StopIndex = 0;StopIndex < StopCount;StopIndex++)
   {
    SrcTourStopSchedulePtr  = SrcTourSchedulePtr->StopSchedule(StopIndex);
    DestTourStopSchedulePtr = DestTourSchedulePtr->AppendStopSchedule
                              (SrcTourStopSchedulePtr->Stop()->IdStr());

    DestTourStopSchedulePtr->SetInTime(SrcTourStopSchedulePtr->InTime());
    DestTourStopSchedulePtr->SetWaitTime(SrcTourStopSchedulePtr->WaitTime());
   }
 }

bool               TripDiagramInvertTour
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr)
 {
  TDateTime                        InTimeValue;
  bool                             ResultFlag;

  InTimeValue
  = TDateTime(TourSchedulePtr->StopSchedule(0)->InTime().AsStr().c_str(),
              TDateTime::Time);

  ResultFlag = TripDiagramReflectTour(TourSchedulePtr,TopologyPtr);

  if (ResultFlag)
   {
    TripDiagramMoveTour(TourSchedulePtr,InTimeValue);
   }

  return (ResultFlag);
 }

AnsiString         TripDiagramTimeInMinutesToStr
                   (unsigned int                      Time)
 {
  AnsiString       Result;

  Result.printf("%02u:%02u",Time / TripDiagramMinutesPerHour,Time % TripDiagramMinutesPerHour);

  return(Result);
 }

unsigned int       TripDiagramTimeInStrToMinutes
                   (AnsiString                        TimeStr)
 {
  unsigned short                       HourValue;
  unsigned short                       MinValue;
  unsigned short                       SecValue;
  unsigned short                       MSecValue;

  TDateTime(TimeStr,TDateTime::Time)
  .DecodeTime(&HourValue,&MinValue,&SecValue,&MSecValue);

  return (HourValue * TripDiagramMinutesPerHour + MinValue);
 }

float              TripDiagramTourStepSpeed
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr,
                    unsigned int                      StepIndex)
 {
  float                                SpeedValue;
  float                                TourDistanceValue;
  unsigned int                         TourWayTimeInMinValue;
  unsigned int                         TourStopInTimeInMinValue;
  unsigned int                         TourStopOutTimeInMinValue;
  TourStopSchedulePtrClass             WorkStopSchedulePtr;
  TourTimeClass                        WorkTime;

  WorkStopSchedulePtr   = TourSchedulePtr->StopSchedule(StepIndex);

  TourStopOutTimeInMinValue = WorkStopSchedulePtr->InTime();

  WorkTime = WorkStopSchedulePtr->WaitTime();

  if (!WorkTime.IsEmpty())
   {
    TourStopOutTimeInMinValue += WorkTime;
   }

  TourStopInTimeInMinValue  = TourSchedulePtr->StopSchedule(StepIndex + 1)->InTime();

  if (TourStopOutTimeInMinValue > TourStopInTimeInMinValue)
   {
    TourWayTimeInMinValue  = TripDiagramMinutesPerDay - TourStopOutTimeInMinValue;
    TourWayTimeInMinValue += TourStopInTimeInMinValue;
   }
  else
   {
    TourWayTimeInMinValue = TourStopInTimeInMinValue - TourStopOutTimeInMinValue;
   }

  TourDistanceValue
  = TopologyPtr->DirectLinkDistance
    (TourSchedulePtr->StopSchedule(StepIndex)->Stop()->IdStr(),
     TourSchedulePtr->StopSchedule(StepIndex + 1)->Stop()->IdStr());

  if (TripDiagramFloatIsZero(TourWayTimeInMinValue))
   {
    SpeedValue  = 0;
   }
  else 
   {
    SpeedValue  = TourDistanceValue / TourWayTimeInMinValue;
   }

  SpeedValue *= TripDiagramMinutesPerHour;

  return (SpeedValue);
 }

float              TripDiagramTourStepDistance
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr,
                    unsigned int                      StepIndex)
 {
  float                                DistanceValue;

  DistanceValue = 0.0;

  if (StepIndex < TourSchedulePtr->StopCount() - 1)
   {
    DistanceValue
    = TopologyPtr->DirectLinkDistance
      (TourSchedulePtr->StopSchedule(StepIndex)->Stop()->IdStr(),
       TourSchedulePtr->StopSchedule(StepIndex + 1)->Stop()->IdStr());
   }

  return (DistanceValue);
 }

bool              TripDiagramNextStopPreliminaryTimeIn
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr,
                    unsigned int                      StopIndex,
                    float                             SpeedValue,
                    unsigned short                   &HoursRef,
                    unsigned short                   &MinutesRef)
 {
  bool                                 ResultFlag;
  float                                HourFloatValue;

  ResultFlag = true;

  TourStopPtrClass                   StopPtr(NULL);
  TourStopPtrClass                   NextStopPtr(NULL);

  StopPtr     = TourSchedulePtr->StopSchedule(StopIndex)->Stop();
  NextStopPtr = TourSchedulePtr->StopSchedule(StopIndex + 1)->Stop();

  if (TopologyPtr->DirectLinkExists(StopPtr->IdStr(),NextStopPtr->IdStr()))
   {
    HourFloatValue
    = TopologyPtr->DirectLinkDistance
      (StopPtr->IdStr(),NextStopPtr->IdStr()) / SpeedValue;
   }
  else
   {
    ResultFlag = false;
   }

  if (ResultFlag)
   {
    HoursRef = HourFloatValue;
    MinutesRef = ceil((HourFloatValue - HoursRef) * TripDiagramMinutesPerHour);

    if (MinutesRef >= TripDiagramMinutesPerHour)
     {
      HoursRef++;
      MinutesRef -= TripDiagramMinutesPerHour;
     }
   }

  return (ResultFlag);
 }

AnsiString   MinuteToTimeStr(unsigned int TimeInMinute)
 {
  Word                       Hour;
  Word                       Minute;
  AnsiString                 TimeStr;
  TDateTime                  DateTime;

  TimeInMinute = TimeInMinute % (TripDiagramHoursPerDay * TripDiagramMinutesPerHour);

  Hour   = TimeInMinute / TripDiagramMinutesPerHour;
  Minute = TimeInMinute - (Hour * TripDiagramMinutesPerHour);

  DateTime = EncodeTime(Hour,Minute,0,0);

  return (DateTime.FormatString("hh:nn"));
 }

TDateTime  LocalDateTimeBeginMonth(void)
 {
  TDateTime                  CurrentDate;
  unsigned short             Year;
  unsigned short             Month;
  unsigned short             Day;

  CurrentDate = TourLocalDateTime();

  CurrentDate.DecodeDate(&Year,&Month,&Day);

  Day = 1;

  return (EncodeDate(Year,Month,Day));
 }


TDateTime  LocalDateTimeEndMonth(void)
 {
  TDateTime                  CurrentDate;
  unsigned short             Year;
  unsigned short             Month;
  unsigned short             Day;

  CurrentDate = TourLocalDateTime();

  CurrentDate.DecodeDate(&Year,&Month,&Day);

  Day = 1;

  CurrentDate = Sysutils::IncMonth(EncodeDate(Year,Month,Day),1);

  return (CurrentDate - 1);
 }


#define            Self                TripDiagramStopDistanceCacheClass

                   Self::Self         (void)
 {
 }                   

void               Self::Load         (TourDataPtrClass    SourceDataPtr)
 {
  TourStopSetPtrClass                  StopSetPtr;
  TourTopologyPtrClass                 TopologyPtr;
  unsigned int                         StopIndex;
  unsigned int                         StopCount;
  TripDiagramStopDistanceInfoType      DistanceInfo;

  StopSetPtr  = SourceDataPtr->StopSet();
  TopologyPtr = SourceDataPtr->Topology();

  StopCount = StopSetPtr->Count();

  if (StopCount > 1)
   {
    for (StopIndex = 0; StopIndex < (StopCount - 1); StopIndex++)
     {
      float                            Distance;

      DistanceInfo.Distance  = TopologyPtr->DirectLinkDistance
                                (StopSetPtr->Stop(StopIndex)->IdStr(),
                                 StopSetPtr->Stop(StopIndex + 1)->IdStr());

      DistanceInfo.StopIdStr = StopSetPtr->Stop(StopIndex)->IdStr();                              

      DistanceArray.push_back(DistanceInfo);             
     }
   } 
 }

void               Self::Clear        (void)
 {
  DistanceArray.clear();
 }
 
float              Self::Distance     (unsigned int        FromStopIndex,
                                       unsigned int        ToStopIndex)
 {
  float                                Result;
  unsigned int                         StopCount;
  unsigned int                         Index;

  Result    = 0.0;
  StopCount = DistanceArray.size() + 1;

  if ((FromStopIndex < StopCount) && (ToStopIndex < StopCount))
   {
    if (FromStopIndex == ToStopIndex)
     {
      Result = 0.0;
     }
    else
     {
      if (FromStopIndex > ToStopIndex)
       {
        unsigned int                   TempIndex;

        TempIndex     = FromStopIndex;
        FromStopIndex = ToStopIndex;
        ToStopIndex   = TempIndex;
       }

      for (Index = FromStopIndex; Index < ToStopIndex; Index++)
       {
        Result += DistanceArray[Index].Distance;
       }
     }
   }

  return(Result);
 }

float              Self::DistanceFromFirst  (unsigned int        ToStopIndex)
 {
  return(Distance(0,ToStopIndex));
 }

float              Self::DistanceToLast     (unsigned int        FromStopIndex)
 {
  unsigned int                               StopCount;

  StopCount = DistanceArray.size() + 1;

  if (StopCount > 1)
   {
    return(Distance(FromStopIndex,StopCount - 1));
   }
  else
   {
    return(0.0);
   }
 }


float              Self::DistanceFromFirst  (const std::string  &ToStopIdStr)
 {
  unsigned int                               StopIndex;

  if (GetStopIndexByIdStr(&StopIndex,ToStopIdStr))
   {
    return(DistanceFromFirst(StopIndex));
   }
  else
   {
    return(0.0);
   }
 }

bool               Self::GetStopIndexByIdStr
                                      (unsigned int       *StopIndexPtr,
                                       const std::string  &StopIdStr)
 {
  bool                                 FoundFlag;
  unsigned int                         StopIndex;
  unsigned int                         StopLimit;

  FoundFlag = false;
  StopIndex = 0;
  StopLimit = DistanceArray.size();

  while ((StopIndex < StopLimit) && (!FoundFlag))
   {
    if (DistanceArray[StopIndex].StopIdStr == StopIdStr)
     {
      FoundFlag     = true;
      *StopIndexPtr = StopIndex; 
     }
    else
     {
      StopIndex++;
     }
   }

  if (!FoundFlag)
   {
    FoundFlag     = true;
    *StopIndexPtr = StopLimit;
   }

  return(FoundFlag);
 }

#undef             Self


TTourTripDiagramCanvasEventHandlerClass::TTourTripDiagramCanvasEventHandlerClass
                                      (TTourTripDiagramForm
                                                          *FormPtr)
 {
  this->FormPtr = FormPtr;
 }

void TTourTripDiagramCanvasEventHandlerClass::OnClick
                                      (VCanvasHandleType   ItemHandle,
                                       unsigned int        ButtonCode,
                                       int                 PosX,
                                       int                 PosY)
 {
  if (ButtonCode == VCanvasMouseButtonLeft)
   {
    if      (FormPtr->ChartCanvas.ItemTagPresent(ItemHandle,ChartCanvasTourIndexTagStr))
     {
      FormPtr->SelectedTourIndex = AnsiString(FormPtr->ChartCanvas.ItemTagValueStrPtr(ItemHandle,ChartCanvasTourIndexTagStr)).ToInt();
      FormPtr->NotifySelectedTourChanged();
     }
    else if (FormPtr->ChartCanvas.ItemTagPresent(ItemHandle,ChartCanvasStopIndexTagStr))
     {
      FormPtr->BaseStopIndex = AnsiString(FormPtr->ChartCanvas.ItemTagValueStrPtr(ItemHandle,ChartCanvasStopIndexTagStr)).ToInt();
      FormPtr->NotifyBaseStopChanged();
     }
   }
 }

//---------------------------------------------------------------------------
__fastcall TTourTripDiagramForm::TTourTripDiagramForm(TComponent* Owner)
        : TForm(Owner),CanvasEventHandler(this)
 {
 }

__fastcall TTourTripDiagramForm::TTourTripDiagramForm    (TComponent    *Owner,
                                                          const std::vector<std::string>
                                                                        &StopIdStrArray,
                                                          AnsiString     BaseTourIdStr)
        : TForm(Owner),CanvasEventHandler(this)
 {
  float                                StopSetDistance;
  unsigned int                         StopIndex;
  unsigned int                         StopCount;
  #if !defined(TOUR_DEMO_MODE)
   {
    time_t                             StartTime;
    time_t                             FinishTime;
    time_t                             ProcessTime;
   }
  #endif

  #if !defined(TOUR_DEMO_MODE)
   {
    StartTime = time(NULL);
   }
  #endif

//  FillTourListViewStateFlag = false;
  SelectedTourIndex         = TripDiagramTourIndexUndefined;
  BaseStopIndex             = 0;

  ShowDistanceGridFlag      = true;
  ShowTimeGridFlag          = true;
  ShowTourInOutRowsFlag     = true;

  MonoColorTourModeFlag      = true;
  ZeroWaitTimeCircleModeFlag = false;

  CachedUpdateDataStoragePtr = NULL;

  ChartGridColor         = TripDiagramChartGridColor;
  ChartCommonTourColor   = TripDiagramChartMonoColorTourColor;
  ChartSelectedTourColor = TripDiagramChartMonoColorSelectedTourColor;

  LoadDBData(StopIdStrArray,BaseTourIdStr);

  StopNameMaxWidth = 0;

  StopCount  = StopIdStrArray.size();

  for (StopIndex = 0; StopIndex < StopCount; StopIndex++)
   {
    unsigned int StopNameWidth;

    StopNameWidth = ChartPaintBox->Canvas->TextWidth(DataStoragePtr->Stop(StopIdStrArray[StopIndex])->NameStr().c_str());

    if (StopNameWidth > StopNameMaxWidth)
     {
      StopNameMaxWidth = StopNameWidth;
     }
   }

  BaseSpeed      = TripDiagramChartDefaultBaseSpeed;
  BaseSpeedAngle = TripDiagramChartDefaultBaseSpeedAngle;

  if (StopCount > 1)
   {
    StopSetDistance = DistanceCache.DistanceToLast(0);

    DistanceBaseScale = (ChartPaintBox->ClientHeight - (2 * TripDiagramChartAxisOffsetY)) / StopSetDistance * TripDiagramChartDefaultDistanceViewScaleFactor;

    ChartPaintBox->ClientHeight = DistanceBaseScale * StopSetDistance + (2 * TripDiagramChartAxisOffsetY);
   }
  else
   {
    DistanceBaseScale = 1.0;
   }

  RecalcTimeScale();

  TimeViewScale     = 1.0;
  DistanceViewScale = 1.0;

  TourListViewColumnToSort = 1;
  TourListSortLockFlag = false;

  if (TripDiagramChartShowForwardToursFlag)
   {
    ShowForwardTours();
   }
  else
   {
    HideForwardTours();
   }

  if (TripDiagramChartShowBackwardToursFlag)
   {
    ShowBackwardTours();
   }
  else
   {
    HideBackwardTours();
   }

  FillTourListView();

  UpdateChart();

  if (SelectedTourIndex != TripDiagramTourIndexUndefined)
   {
    ScrollToTour(SelectedTourIndex);
   }

  ChartScrollBox->HorzScrollBar->Tracking = true;
  ChartScrollBox->VertScrollBar->Tracking = true;

  HintTimeValueLabel->Caption = "";
  HintFromValueLabel->Caption = "";
  HintToValueLabel->Caption   = "";

  ChartCanvas.SetEventHandler(&CanvasEventHandler);

  LastMousePosX         = 0;
  LastMousePosY         = 0;
  ButtonLeftPressedFlag = false;

  #if !defined(TOUR_DEMO_MODE)
   {
    FinishTime  = time(NULL);
    ProcessTime = FinishTime - StartTime;

    Application->MessageBox(AnsiString(AnsiString("Total seconds: ") + AnsiString(ProcessTime)).c_str(),"Process time",MB_OK);
   } 
  #endif
 }

void            TTourTripDiagramForm::RecalcTimeScale
                                               (void)
 {
  TimeBaseScale = BaseSpeed * DistanceBaseScale /
                   tan(TripDiagramGradToRad(BaseSpeedAngle)) *
                    TripDiagramChartDefaultTimeViewScaleFactor;

  ChartPaintBox->ClientWidth = TimeBaseScale * TripDiagramHoursPerDay +
                                (2 * TripDiagramChartAxisOffsetX + StopNameMaxWidth);
 }

void            TTourTripDiagramForm::DrawToRow(int        PosX,
                                                int        PosY,
                                                bool       UpFlag)
 {
  if (UpFlag)
   {
    ChartCanvas.AppendLine(PosX,
                           PosY + TripDiagramChartRowSize,
                           PosX,
                           PosY);

    ChartCanvas.AppendLine(PosX - TripDiagramChartRowWidth,
                           PosY + TripDiagramChartRowLength,
                           PosX,
                           PosY);

    ChartCanvas.AppendLine(PosX + TripDiagramChartRowWidth,
                           PosY + TripDiagramChartRowLength,
                           PosX,
                           PosY);
   }
  else
   {
    ChartCanvas.AppendLine(PosX,
                           PosY - TripDiagramChartRowSize,
                           PosX,
                           PosY);

    ChartCanvas.AppendLine(PosX - TripDiagramChartRowWidth,
                           PosY - TripDiagramChartRowLength,
                           PosX,
                           PosY);

    ChartCanvas.AppendLine(PosX + TripDiagramChartRowWidth,
                           PosY - TripDiagramChartRowLength,
                           PosX,
                           PosY);
   }
 }

void            TTourTripDiagramForm::DrawFromRow
                                               (int        PosX,
                                                int        PosY,
                                                bool       UpFlag)
 {
  if (UpFlag)
   {
    ChartCanvas.AppendLine(PosX,
                           PosY,
                           PosX,
                           PosY - TripDiagramChartRowSize);

    ChartCanvas.AppendLine(PosX - TripDiagramChartRowWidth,
                           PosY - TripDiagramChartRowSize + TripDiagramChartRowLength,
                           PosX,
                           PosY - TripDiagramChartRowSize);

    ChartCanvas.AppendLine(PosX + TripDiagramChartRowWidth,
                           PosY - TripDiagramChartRowSize + TripDiagramChartRowLength,
                           PosX,
                           PosY - TripDiagramChartRowSize);
   }
  else
   {
    ChartCanvas.AppendLine(PosX,
                           PosY,
                           PosX,
                           PosY + TripDiagramChartRowSize);

    ChartCanvas.AppendLine(PosX - TripDiagramChartRowWidth,
                           PosY + TripDiagramChartRowSize - TripDiagramChartRowLength,
                           PosX,
                           PosY + TripDiagramChartRowSize);

    ChartCanvas.AppendLine(PosX + TripDiagramChartRowWidth,
                           PosY + TripDiagramChartRowSize - TripDiagramChartRowLength,
                           PosX,
                           PosY + TripDiagramChartRowSize);
   }
 }

void            TTourTripDiagramForm::UpdateChart
                                               (void)
 {
  VCanvasHandleType                             ItemHandle;
  TourStopSetPtrClass                           StopSetPtr;
  TourTourSetPtrClass                           TourSetPtr;
  int                                           LastStopDistanceInPixels;
  int                                           BaseStopDistanceInPixels;
  unsigned int                                  StopIndex;
  unsigned int                                  StopCount;
  unsigned int                                  TourIndex;
  unsigned int                                  TourCount;

  StopSetPtr = ChartDataStoragePtr->StopSet();
  TourSetPtr = ChartDataStoragePtr->TourSet();

  ChartCanvas.Clear();

  ChartCanvas.SetCanvas    (ChartPaintBox->Canvas);
  ChartCanvas.SetBackground(TripDiagramChartBgColor);

  // Draw distance axis

  ChartCanvas.SetPen(VCanvasPenSolid);
  ChartCanvas.SetPenWidth(1);
  ChartCanvas.SetColor(TripDiagramChartDistanceAxisColor);

  ChartCanvas.AppendLine
   (TripDiagramChartAxisOffsetX + StopNameMaxWidth,
    DistanceToPixels(0),
    TripDiagramChartAxisOffsetX + StopNameMaxWidth,
    DistanceToPixels(DistanceCache.DistanceToLast(0)));

  ChartCanvas.SetTextAlignMode(VCanvasTextAlignModeDownRight);

  StopCount = StopSetPtr->Count();

  for (StopIndex = 0;StopIndex < StopCount;StopIndex++)
   {
    int                                StopDistanceInPixels;

    StopDistanceInPixels =
     DistanceToPixels(DistanceCache.DistanceFromFirst(StopIndex));

    ChartCanvas.AppendLine(TripDiagramChartAxisOffsetX + StopNameMaxWidth - 5,
                           StopDistanceInPixels,
                           TripDiagramChartAxisOffsetX + StopNameMaxWidth,
                           StopDistanceInPixels);

    ItemHandle =
     ChartCanvas.AppendText(TripDiagramChartAxisOffsetX + StopNameMaxWidth - 5,
                            StopDistanceInPixels - 5,
                            StopSetPtr->Stop(StopIndex)->NameStr().c_str());

    ChartCanvas.ItemAppendTag(ItemHandle,ChartCanvasStopIndexTagStr,AnsiString(StopIndex).c_str());

    if (ShowDistanceGridFlag)
     {
      ChartCanvas.SetColor(ChartGridColor);
      ChartCanvas.SetPen  (VCanvasPenDot);

      ItemHandle =
       ChartCanvas.AppendLine
        (TripDiagramChartAxisOffsetX + StopNameMaxWidth,
         StopDistanceInPixels,
         TripDiagramChartAxisOffsetX + StopNameMaxWidth + TripDiagramHoursPerDay * TimeBaseScale * TimeViewScale,
         StopDistanceInPixels);

      ChartCanvas.ItemAppendTag(ItemHandle,ChartCanvasStopIndexTagStr,AnsiString(StopIndex).c_str());

      ChartCanvas.SetPen(VCanvasPenSolid);
      ChartCanvas.SetColor(TripDiagramChartDistanceAxisColor);
     }
   }

  // Draw time axis

  LastStopDistanceInPixels =
   DistanceToPixels(DistanceCache.DistanceToLast(0));
  BaseStopDistanceInPixels =
   DistanceToPixels(DistanceCache.DistanceFromFirst(BaseStopIndex));

  ChartCanvas.SetColor(TripDiagramChartTimeAxisColor);

  ItemHandle =
   ChartCanvas.AppendLine
    (TripDiagramChartAxisOffsetX + StopNameMaxWidth,
     BaseStopDistanceInPixels,
     TripDiagramChartAxisOffsetX + StopNameMaxWidth + TripDiagramHoursPerDay * TimeBaseScale * TimeViewScale,
     BaseStopDistanceInPixels);

  ChartCanvas.ItemMoveToTop(ItemHandle);

  ChartCanvas.SetTextAlignMode(VCanvasTextAlignModeUpLeft);

  for (unsigned int Hour = 0; Hour <= TripDiagramHoursPerDay; Hour += 2)
   {
    AnsiString     HourStr(Hour);

    HourStr += ":00";

    ItemHandle =
     ChartCanvas.AppendLine(TimeToPixels(Hour),
                            BaseStopDistanceInPixels - 5,
                            TimeToPixels(Hour),
                            BaseStopDistanceInPixels + 6);

    ChartCanvas.ItemMoveToTop(ItemHandle);

    ItemHandle =
     ChartCanvas.AppendText(TimeToPixels(Hour) - ChartPaintBox->Canvas->TextWidth(HourStr) / 2,
                            BaseStopDistanceInPixels + 10,
                            HourStr.c_str());

    ChartCanvas.ItemMoveToTop(ItemHandle);

    if (ShowTimeGridFlag)
     {
      if (Hour > 0) // don't draw on axis
       {
        ChartCanvas.SetColor(ChartGridColor);
        ChartCanvas.SetPen  (VCanvasPenDot);

        ItemHandle =
         ChartCanvas.AppendLine
          (TimeToPixels(Hour),
           DistanceToPixels(0),
           TimeToPixels(Hour),
           LastStopDistanceInPixels);

        ChartCanvas.ItemMoveToBottom(ItemHandle);

        ChartCanvas.SetColor(TripDiagramChartTimeAxisColor);
        ChartCanvas.SetPen(VCanvasPenSolid);
       }
     }
   }

  // Draw tours data

  TourCount = TourSetPtr->Count();

  for (TourIndex = 0; TourIndex < TourCount; TourIndex++)
   {
    bool                               ForwardTourFlag;
    TourTourSchedulePtrClass           TourSchedulePtr;
    TourSFTourScheduleClass           *TourScheduleLowPtr;

    TourSchedulePtr    = TourSetPtr->Tour(TourIndex)->Schedule();
    TourScheduleLowPtr = (TourSFTourScheduleClass*)TourSchedulePtr.operator->();
    ForwardTourFlag    = IsTourForward(TourIndex);

    if (TourViewInfoArray[TourIndex].VisibleFlag)
     {
      TourStopSchedulePtrClass CurrStopSchedulePtr;
      TourStopSchedulePtrClass PrevStopSchedulePtr;

      if (!MonoColorTourModeFlag)
       {
        if (TourIndex == SelectedTourIndex)
         {
          ChartCanvas.SetPenWidth(3);
         }
        else
         {
          ChartCanvas.SetPenWidth(1);
         }
       }

      ChartCanvas.SetColor(TourViewInfoArray[TourIndex].Color);
      ChartCanvas.SetPen(TourViewInfoArray[TourIndex].PenStyle);

      StopIndex = 0;
      StopCount = TourSchedulePtr->StopCount();

      while (StopIndex < StopCount)
       {
        float                               StopDistance;
        float                               PrevStopDistance;
        TourTimeClass                       StopInTime;
        TourTimeClass                       StopWaitTime;
        TourTimeClass                       PrevStopOutTime;

        if (StopIndex > 0)
         {
          PrevStopSchedulePtr = CurrStopSchedulePtr;
         }

        CurrStopSchedulePtr = TourSchedulePtr->StopSchedule(StopIndex);

        StopDistance = DistanceCache.DistanceFromFirst(CurrStopSchedulePtr->Stop()->IdStr());
        StopInTime   = CurrStopSchedulePtr->InTime();
        StopWaitTime = CurrStopSchedulePtr->WaitTime();

        if (StopWaitTime.IsEmpty())
         {
          StopWaitTime.SetZero();
         }

        if (ShowTourInOutRowsFlag)
         {
          if      (TourScheduleLowPtr->IsStopIncome(StopIndex))
           {
            if (ForwardTourFlag)
             {
              DrawToRow(TimeToPixels((float)StopInTime / (float)TripDiagramMinutesPerHour),
                        DistanceToPixels(StopDistance),
                        true);
             }
            else
             {
              DrawToRow(TimeToPixels((float)StopInTime / (float)TripDiagramMinutesPerHour),
                        DistanceToPixels(StopDistance),
                        false);
             }
           }

          if (TourScheduleLowPtr->IsStopOutcome(StopIndex))
           {
            if (ForwardTourFlag)
             {
              DrawFromRow(TimeToPixels((float)(StopInTime + StopWaitTime) / (float)TripDiagramMinutesPerHour),
                          DistanceToPixels(StopDistance),
                          true);
             }
            else
             {
              DrawFromRow(TimeToPixels((float)(StopInTime + StopWaitTime) / (float)TripDiagramMinutesPerHour),
                          DistanceToPixels(StopDistance),
                          false);
             }
           }
         }

        if (StopIndex > 0)
         {
          if (PrevStopSchedulePtr->WaitTime().IsEmpty())
           {
            PrevStopOutTime  =  PrevStopSchedulePtr->InTime();
           }
          else
           { 
            PrevStopOutTime  =  PrevStopSchedulePtr->InTime()+ PrevStopSchedulePtr->WaitTime();
           } 

          if (PrevStopOutTime > TourTimeClass(TourTimeHoursPerDay,0))
           {
            PrevStopOutTime -= TourTimeClass(TourTimeHoursPerDay,0);
           }

          PrevStopDistance = DistanceCache.DistanceFromFirst(PrevStopSchedulePtr->Stop()->IdStr());

          if (PrevStopOutTime > StopInTime)
           {
            float MidNightDistance;

            MidNightDistance =
             PrevStopDistance +
              (StopDistance - PrevStopDistance) /
                (StopInTime + TourTimeClass(TourTimeHoursPerDay,0) - PrevStopOutTime) *
                  (TourTimeClass(TourTimeHoursPerDay,0) - PrevStopOutTime);

            ItemHandle = ChartCanvas.AppendLine
                          (TimeToPixels((float)(PrevStopOutTime) / (float)TripDiagramMinutesPerHour),
                           DistanceToPixels(PrevStopDistance),
                           TimeToPixels(TripDiagramHoursPerDay),
                           DistanceToPixels(MidNightDistance));

            ChartCanvas.ItemAppendTag(ItemHandle,ChartCanvasTourIndexTagStr,AnsiString(TourIndex).c_str());

            ItemHandle = ChartCanvas.AppendLine
                          (TimeToPixels(0),
                           DistanceToPixels(MidNightDistance),
                           TimeToPixels((float)(StopInTime) / (float)TripDiagramMinutesPerHour),
                           DistanceToPixels(StopDistance));

            ChartCanvas.ItemAppendTag(ItemHandle,ChartCanvasTourIndexTagStr,AnsiString(TourIndex).c_str());
           }
          else
           {
            ItemHandle = ChartCanvas.AppendLine
                          (TimeToPixels((float)(PrevStopOutTime) / (float)TripDiagramMinutesPerHour),
                           DistanceToPixels(PrevStopDistance),
                           TimeToPixels((float)(StopInTime) / (float)TripDiagramMinutesPerHour),
                           DistanceToPixels(StopDistance));

            ChartCanvas.ItemAppendTag(ItemHandle,ChartCanvasTourIndexTagStr,AnsiString(TourIndex).c_str());
           }
         }

        if ((!StopWaitTime.IsEmpty()) && (!StopWaitTime.IsZero()))
         {
          if ((StopInTime + StopWaitTime) > TourTimeClass(TourTimeHoursPerDay,0))
           {
            ItemHandle = ChartCanvas.AppendLine
                          (TimeToPixels((float)(StopInTime) / (float)TripDiagramMinutesPerHour),
                           DistanceToPixels(StopDistance),
                           TimeToPixels(TripDiagramHoursPerDay),
                           DistanceToPixels(StopDistance));

            ChartCanvas.ItemAppendTag(ItemHandle,ChartCanvasTourIndexTagStr,AnsiString(TourIndex).c_str());

            ItemHandle = ChartCanvas.AppendLine
                          (TimeToPixels(0),
                           DistanceToPixels(StopDistance),
                           TimeToPixels((float)(StopInTime + StopWaitTime - TourTimeClass(TourTimeHoursPerDay,0)) / (float)TripDiagramMinutesPerHour),
                           DistanceToPixels(StopDistance));

            ChartCanvas.ItemAppendTag(ItemHandle,ChartCanvasTourIndexTagStr,AnsiString(TourIndex).c_str());
           }
          else
           {
            ItemHandle = ChartCanvas.AppendLine
                          (TimeToPixels((float)(StopInTime) / (float)TripDiagramMinutesPerHour),
                           DistanceToPixels(StopDistance),
                           TimeToPixels((float)(StopInTime + StopWaitTime) / (float)TripDiagramMinutesPerHour),
                           DistanceToPixels(StopDistance));

            ChartCanvas.ItemAppendTag(ItemHandle,ChartCanvasTourIndexTagStr,AnsiString(TourIndex).c_str());
           }
         }
        else
         {
          ChartCanvas.SetPen(VCanvasPenSolid);

          if (!MonoColorTourModeFlag)
           {
            ChartCanvas.SetPenWidth(1);
           }

          if (ZeroWaitTimeCircleModeFlag)
           {
            ItemHandle = ChartCanvas.AppendCircle
                          (TimeToPixels((float)StopInTime / (float)TripDiagramMinutesPerHour),
                           DistanceToPixels(StopDistance),
                           3);
           }
          else
           {
            ItemHandle = ChartCanvas.AppendLine
                          (TimeToPixels((float)StopInTime / (float)TripDiagramMinutesPerHour) - 3,
                           DistanceToPixels(StopDistance),
                           TimeToPixels((float)StopInTime / (float)TripDiagramMinutesPerHour) + 3,
                           DistanceToPixels(StopDistance));
           }

          ChartCanvas.ItemAppendTag(ItemHandle,ChartCanvasTourIndexTagStr,AnsiString(TourIndex).c_str());

          ChartCanvas.SetPen(TourViewInfoArray[TourIndex].PenStyle);

          if (!MonoColorTourModeFlag)
           {
            if (TourIndex == SelectedTourIndex)
             {
              ChartCanvas.SetPenWidth(3);
             }
            else
             {
              ChartCanvas.SetPenWidth(1);
             }
           }
         }

        StopIndex++;
       }
     }
   }

  ChartCanvas.SetPenWidth(1);

  if (SelectedTourIndex != TripDiagramTourIndexUndefined)
   {
    ChartCanvas.MoveToTopByTag(ChartCanvasTourIndexTagStr,AnsiString(SelectedTourIndex).c_str());
   }

  ChartCanvas.Update();
 }

void            TTourTripDiagramForm::LoadDBData
                                               (const std::vector<std::string>
                                                          &StopIdStrArray,
                                                const AnsiString &BaseTourIdStr)
 {
  unsigned int                                  StopIndex;
  unsigned int                                  StopLimit;
  unsigned int                                  TourIndex;
  unsigned int                                  TourLimit;
  AnsiString                                    TourSetQueryStr;
  TourTourSetPtrClass                           TourSetPtr;

  #if !defined(TOUR_DEMO_MODE)
   {
    TourSetQueryStr = "SELECT Trip_Id "
                      "FROM Trip "
                      "WHERE 1 < (SELECT COUNT(*) "
                                 "FROM TripStep "
                                 "WHERE TripStep.Trip_Id = Trip.Trip_Id AND "
                                       "TripStep.Stop_Id IN(";

    StopLimit = StopIdStrArray.size();

    for (StopIndex = 0; StopIndex < StopLimit; StopIndex++)
     {
      if (StopIndex > 0)
       {
        TourSetQueryStr += ",'";
       }
      else
       {
        TourSetQueryStr += "'";
       }

      TourSetQueryStr += StopIdStrArray[StopIndex].c_str();
      TourSetQueryStr += "'";
     }

    TourSetQueryStr += "))";

    CachedUpdateDataStoragePtr
    = new TourCachedUpdateDataClass
          (new TourCacheDataClass(TourDataPtrClass
                                  (new TourDBDataClass(TourSetQueryStr.c_str()))));
   }
  #else
   {
    CachedUpdateDataStoragePtr
    = new TourCachedUpdateDataClass
          (new TourCacheDataClass(TourDataPtrClass
                                  (new TourDemoDataClass(&TourDemoData,StopIdStrArray))));
   }
  #endif

  DataStoragePtr      = TourDataPtrClass(CachedUpdateDataStoragePtr);
  ChartDataStoragePtr = TourDataPtrClass(new TourSFDataClass(DataStoragePtr,StopIdStrArray));

  DistanceCache.Load(ChartDataStoragePtr);

  TourSetPtr = ChartDataStoragePtr->TourSet();
  TourLimit  = TourSetPtr->Count();

  for (TourIndex = 0; TourIndex < TourLimit; TourIndex++)
   {
    TripDiagramTourViewType            TourViewInfo;

    TourViewInfo.VisibleFlag = true;
    TourViewInfo.Color       = ChartCommonTourColor;
    TourViewInfo.PenStyle    = VCanvasPenSolid;

    TourViewInfoArray.push_back(TourViewInfo);

    if (BaseTourIdStr == TourSetPtr->Tour(TourIndex)->IdStr().c_str())
     {
      SelectedTourIndex = TourIndex;
     }
   }

  UpdateColorTable();
 }


void TTourTripDiagramForm::UpdateColorTable (void)
 {
  unsigned int                     TourIndex;
  unsigned int                     TourLimit;

  TourLimit = DataStoragePtr->TourSet()->Count();

  for (TourIndex = 0; TourIndex < TourLimit; TourIndex++)
   {
    if (MonoColorTourModeFlag)
     {
      if (TourIndex == SelectedTourIndex)
       {
        TourViewInfoArray[TourIndex].Color = ChartSelectedTourColor;
       }
      else
       {
        TourViewInfoArray[TourIndex].Color = ChartCommonTourColor;
       }
     }
    else
     {
      TourViewInfoArray[TourIndex].Color = TourColorSetArray[TourIndex % DeclaredArraySize(TourColorSetArray)];;
     }
   }
 }

//---------------------------------------------------------------------------
void __fastcall TTourTripDiagramForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  FreeTourListView();

  Action              = caFree;
  TourTripDiagramForm = NULL;
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::ChartPaintBoxPaint(TObject *Sender)
 {
  ChartCanvas.Update();
 }

//---------------------------------------------------------------------------

int TTourTripDiagramForm::TimeToPixels    (float          Time)
 {
  return(TripDiagramChartAxisOffsetX + StopNameMaxWidth + Time * TimeBaseScale * TimeViewScale);
 }
//---------------------------------------------------------------------------
int TTourTripDiagramForm::DistanceToPixels(float          Distance)
 {
  return(ChartPaintBox->ClientHeight - TripDiagramChartAxisOffsetY
          -  Distance * DistanceBaseScale * DistanceViewScale);
 }
//---------------------------------------------------------------------------
void __fastcall TTourTripDiagramForm::FormCreate(TObject *Sender)
 {
  NotifySelectedTourChanged();

  #if !defined(TOUR_DEMO_MODE)
   {
    if (TourDataModule->DataBaseEditModeFlag)
     {
      OkButton->Enabled = true;
      OkButton->Visible = true;
     }
    else
     {
      OkButton->Enabled = false;
      OkButton->Visible = false;
     }
   }
  #else
   {
    OkButton->Enabled = true;
    OkButton->Visible = true;
   }
  #endif
 }
//---------------------------------------------------------------------------
bool               TTourTripDiagramForm::TourListViewTourAppend
                   (unsigned int                 TourIndex,
                    TourTourPtrClass             TourPtr)
 {
  bool                                 ResultFlag;
  TListItem                           *ItemPtr;
  int                                 *ItemIndexPtr;
  TourTourSchedulePtrClass             TourSchedulePtr;

  ResultFlag = true;

//  ShowTour(TourIndex);

//  TourListView->Items->BeginUpdate();

  ItemPtr = TourListView->Items->Add();

  if (ItemPtr)
   {
    TourSchedulePtr  = TourPtr->Schedule();
    ItemPtr->Caption = GetTourListTourBaseOutTimeStr(TourSchedulePtr);//TourIndex);
    ItemPtr->Checked = TourViewInfoArray[TourIndex].VisibleFlag;
    ItemPtr->SubItems->Add(GetTourListTourCaptionStr(TourPtr));//CaptionStr);

    ItemPtr->SubItems->Add(GetTourListTourAverageSpeedStr(TourPtr));//FormatFloat("0.0",TourPtr->AverageSpeed()));
    ItemPtr->SubItems->Add(TourSchedulePtr->StopSchedule(0)->InTime().AsStr().c_str());
    ItemPtr->SubItems->Add
    (TourSchedulePtr
     ->StopSchedule(TourSchedulePtr->StopCount() - 1)->InTime().AsStr().c_str());

    // Каждый элемент списка в диалоге имеет связанный объект с информацией о
    // порядковом номере соответствуюцего ему элемента в хранилище рейсов

    ItemIndexPtr = new int(TourIndex);

    if (ItemIndexPtr != NULL)
     {
      ItemPtr->Data = ItemIndexPtr;
     }
    else
     {
      ResultFlag = false;
     }
   }
  else
   {
    ResultFlag = false;
   }

//  TourListView->Items->EndUpdate();

  return (ResultFlag);
 }

//---------------------------------------------------------------------------

bool TTourTripDiagramForm::FillTourListView()
 {
  bool                                 ResultFlag;
  unsigned int                         TourCounter;
  TourTourSetPtrClass                  TourSetPtr;

  ResultFlag           = true;
  TourListSortLockFlag = true;
//  FillTourListViewStateFlag = true;

  TourListView->Items->BeginUpdate();

  TourListView->Items->Clear();
  FreeTourListView();

  TourSetPtr = DataStoragePtr->TourSet();

  for (TourCounter = 0; TourCounter < TourSetPtr->Count() && ResultFlag; TourCounter++)
   {
    ResultFlag = TourListViewTourAppend(TourCounter,TourSetPtr->Tour(TourCounter));
   }

  TourListSortLockFlag = false;

  if (ResultFlag)
   {
    TourListView->AlphaSort();

    if (TourListView->Items->Count > 0)
     {
      TourListView->Selected = TourListViewItemByData(SelectedTourIndex);

      if (TourListView->Selected == NULL)
       {
        TourListView->Selected = TourListView->Items->Item[0];
       }

      TourListView->Selected->MakeVisible(false);
     }
   }
//  FillTourListViewStateFlag = false;

  TourListView->Items->EndUpdate();

  return (ResultFlag);
 }

//---------------------------------------------------------------------------

void               TTourTripDiagramForm::UpdateTourListBaseOutTime
                   (void)
 {
  TListItem                           *ListItemPtr;
  unsigned int                        *ItemIndexPtr;
  unsigned int                         TourIndex;
  unsigned int                         TourCount;
  TourTourSetPtrClass                  TourSetPtr;

  CursorWaitOpen();

  TourSetPtr = DataStoragePtr->TourSet();
  TourCount  = TourSetPtr->Count();

  TourListView->Items->BeginUpdate();

  TourListSortLockFlag = true;

  for (TourIndex = 0; TourIndex < TourCount; TourIndex++)
   {
    ListItemPtr = TourListView->Items->Item[TourIndex];

    ItemIndexPtr = ((unsigned int*)(ListItemPtr->Data));

    if (ItemIndexPtr != NULL)
     {
      ListItemPtr->Caption
      = GetTourListTourBaseOutTimeStr(TourSetPtr->Tour(*ItemIndexPtr)->Schedule());
     }
   }

  TourListSortLockFlag = false;

  TourListView->AlphaSort();

  if (TourListView->Selected != NULL)
   {
    TourListView->Selected->MakeVisible(false);
   }

  TourListView->Items->EndUpdate();

  CursorWaitClose();
 }

//---------------------------------------------------------------------------

bool               TTourTripDiagramForm::FillTimetableListView
                   (unsigned int                      TourIndex)
 {
  //расписание && комбобоксы для выбора периода статистики
  unsigned int                         TourStopCount;
  unsigned int                         TourStopCounter;
  TListItem                           *ItemPtr;
  bool                                 ResultFlag;
  TourTourPtrClass                     TourPtr;
  TourTourSchedulePtrClass             TourSchedulePtr;
  TourStopSchedulePtrClass             StopSchedulePtr;

  TourPtr         = DataStoragePtr->TourSet()->Tour(TourIndex);
  TourSchedulePtr = TourPtr->Schedule();

  ResultFlag = true;

  TimetableListView->Items->BeginUpdate();

  TimetableListView->Items->Clear();
  TourStopCount = TourSchedulePtr->StopCount();

  for (TourStopCounter = 0;
       (TourStopCounter < TourStopCount) && (ResultFlag);
       TourStopCounter++)
   {
    ItemPtr = TimetableListView->Items->Add();

    if (ItemPtr)
     {
      StopSchedulePtr = TourSchedulePtr->StopSchedule(TourStopCounter);

      ItemPtr->Caption = StopSchedulePtr->Stop()->NameStr().c_str();

      ItemPtr->SubItems->Add(StopSchedulePtr->InTime().AsStr().c_str());

      ItemPtr->SubItems->Add(TourTimeClass(StopSchedulePtr->InTime() + StopSchedulePtr->WaitTime()).AsStr().c_str());
      ItemPtr->SubItems->Add(StopSchedulePtr->WaitTime().AsStr().c_str());

      if (TourStopCounter < TourStopCount - 1)
       {
        ItemPtr->SubItems->Add
  //      (TourPtr->TotalDistance());
        (TourStepSpeedStr(TourSchedulePtr,TourStopCounter));

        ItemPtr->SubItems->Add(TourStepDistanceStr(TourSchedulePtr,TourStopCounter));
       }
     }
    else
     {
      ResultFlag = false;
     }
   }

  TimetableListView->Items->EndUpdate();

  return (ResultFlag);
 }

TListItem      *TTourTripDiagramForm::TourListViewItemByData
                (unsigned int          DataValue)
 {
  unsigned int                         TourCounter;
  bool                                 FindFlag;
  TListItem                           *ListItemPtr;

  // Удаляем объекты из списка рейсов
  ListItemPtr  = NULL;
  FindFlag     = false;

  for (TourCounter = 0;
       (TourCounter < TourListView->Items->Count) && (!FindFlag);
       TourCounter++)
   {
    ListItemPtr  = TourListView->Items->Item[TourCounter];

    if (ListItemPtr != NULL)
     {
      unsigned int                    *ItemIndexPtr;

      ItemIndexPtr = ((unsigned int*)(ListItemPtr->Data));

      if (ItemIndexPtr != NULL)
       {
        if ((*ItemIndexPtr) == DataValue)
         {
          FindFlag = true;
         }
       }
     }
   }

  if (!FindFlag)
   {
    ListItemPtr = NULL;
   }

  return (ListItemPtr);
 }

void            TTourTripDiagramForm::FreeTourListView
                (void)
 {
  unsigned int                         TourCounter;
//  TSortType                            StoredSortType;

  TourListView->Items->BeginUpdate();

  TourListSortLockFlag = true;

//  StoredSortType = TourListView->SortType;
//  TourListView->SortType = stNone;

  // Удаляем объекты из списка рейсов

  for (TourCounter = 0; TourCounter < TourListView->Items->Count; TourCounter++)
   {
    unsigned int                      *ItemIndexPtr;
    
    ItemIndexPtr
     = ((unsigned int*)(TourListView->Items->Item[TourCounter]->Data));

    if (ItemIndexPtr != NULL)
     {
      delete (ItemIndexPtr);
      TourListView->Items->Item[TourCounter]->Data = NULL;
     }
   }

  TourListSortLockFlag = false;

  TourListView->Items->EndUpdate();
//  TourListView->SortType = StoredSortType;
 }

void __fastcall TTourTripDiagramForm::TourListViewSelectItem(
      TObject *Sender, TListItem *Item, bool Selected)
 {
  if (Selected)
   {
    unsigned int                       TourIndex;
    bool                               TourChangedFlag;

    if (Item->Data != NULL)
     {
      TourIndex = *((unsigned int*)(Item->Data));

      if (TourIndex != SelectedTourIndex)
       {
        TourChangedFlag = true;
       }
      else
       {
        TourChangedFlag = false;
       }

      if (TourChangedFlag)
       {
        // Point tour in diagram
        // Refresh tour info
        // Refresh tourstep info
        SelectedTourIndex = TourIndex;

        NotifySelectedTourChanged();

        if ((TourChangedFlag) && (TourViewInfoArray[SelectedTourIndex].VisibleFlag))
         {
          ScrollToTour(SelectedTourIndex);
         }
       }
     }
   }
 }
//---------------------------------------------------------------------------
bool              TTourTripDiagramForm::InfoPanelUpdate()
 {
  return (FillTourListView());
 }

//---------------------------------------------------------------------------

AnsiString         TTourTripDiagramForm::GetTourListTourCaptionStr
                   (TourTourPtrClass                  TourPtr)
 {
  AnsiString                           ResultStr;

  ResultStr  = TourPtr->NameStr().c_str();
  ResultStr += " - [";
  ResultStr += TourPtr->IdStr().c_str();
  ResultStr += "]";

  return (ResultStr);
 }

AnsiString         TTourTripDiagramForm::GetTourListTourTotalDistanceStr
                   (TourTourPtrClass                  TourPtr)
 {
  AnsiString                           ResultStr;

  ResultStr = FormatFloat("0.0",TourPtr->TotalDistance());

  return (ResultStr);
 }

AnsiString         TTourTripDiagramForm::GetTourListTourAverageSpeedStr
                   (TourTourPtrClass                  TourPtr)
 {
  AnsiString                           ResultStr;

  ResultStr = FormatFloat("0.0",TourPtr->AverageSpeed());

  return (ResultStr);
 }

AnsiString         TTourTripDiagramForm::GetTourListTourBaseInTimeStr
                   (TourTourSchedulePtrClass          TourSchedulePtr)
 {
  AnsiString                           ResultStr;
  std::string                          BaseStopIdStr;
  unsigned int                         StopCount;
  unsigned int                         StopIndex;
  TourStopSchedulePtrClass             StopSchedulePtr;
  bool                                 FindFlag;

  ResultStr = "";

  BaseStopIdStr
  = ChartDataStoragePtr->StopSet()->Stop(BaseStopIndex)->IdStr();

  FindFlag        = false;
  StopCount       = TourSchedulePtr->StopCount();

  for (StopIndex = 0; (StopIndex < StopCount) && (!FindFlag); StopIndex++)
   {
    StopSchedulePtr = TourSchedulePtr->StopSchedule(StopIndex);

    if (StopSchedulePtr->Stop()->IdStr() == BaseStopIdStr)
     {
      FindFlag  = true;
      ResultStr = StopSchedulePtr->InTime().AsStr().c_str();
     }
   }

  return (ResultStr);
 }

AnsiString         TTourTripDiagramForm::GetTourListTourBaseOutTimeStr
                   (TourTourSchedulePtrClass          TourSchedulePtr)
 {
  AnsiString                           ResultStr;
  std::string                          BaseStopIdStr;
  unsigned int                         StopCount;
  unsigned int                         StopIndex;
  TourStopSchedulePtrClass             StopSchedulePtr;
  bool                                 FindFlag;

  ResultStr = "";

  BaseStopIdStr
  = ChartDataStoragePtr->StopSet()->Stop(BaseStopIndex)->IdStr();

  FindFlag        = false;
  StopCount       = TourSchedulePtr->StopCount();

  for (StopIndex = 0; (StopIndex < StopCount) && (!FindFlag); StopIndex++)
   {
    StopSchedulePtr = TourSchedulePtr->StopSchedule(StopIndex);

    if (StopSchedulePtr->Stop()->IdStr() == BaseStopIdStr)
     {
      FindFlag  = true;

      if (StopSchedulePtr->WaitTime().IsEmpty())
       {
        ResultStr = "";
       }
      else
       {
        ResultStr = (StopSchedulePtr->InTime() + StopSchedulePtr->WaitTime()).AsStr().c_str();
       }
//      ResultStr = StopSchedulePtr->InTime().AsStr().c_str();
     }
   }

  return (ResultStr);
 }

//---------------------------------------------------------------------------

void               TTourTripDiagramForm::NotifySelectedTourScheduleChanged
                   (void)
 {
  TourTourPtrClass                     TourPtr;
  TourBusPtrClass                      BusPtr;
  AnsiString                           CaptionStr;

  CursorWaitOpen();

  if (*((unsigned int*)(TourListView->Selected->Data)) != SelectedTourIndex)
   {
    TourListView->Selected = TourListViewItemByData(SelectedTourIndex);
    TourListView->Selected->MakeVisible(false);
   }

  UpdateColorTable();
  UpdateChart();

  TourPtr = DataStoragePtr->TourSet()->Tour(SelectedTourIndex);
  BusPtr  = TourPtr->Bus();

  TourListView->Selected->SubItems->Strings[0] = GetTourListTourCaptionStr(TourPtr);//TourPtr->NameStr().c_str();
  TourListView->Selected->SubItems->Strings[1] = GetTourListTourAverageSpeedStr(TourPtr);//AnsiString(TourPtr->AverageSpeed());

  if (!BusPtr.IsNull())
   {
    BusModelValueLabel->Caption = BusPtr->ModelStr().c_str();

    BusCapacityValueLabel->Caption = AnsiString(BusPtr->Capacity());
   }
  else
   {
    BusModelValueLabel->Caption    = "";
    BusCapacityValueLabel->Caption = "";
   }

  TripPathLengthValueLabel->Caption = GetTourListTourTotalDistanceStr(TourPtr);//->TotalDistance());
  TripPathTimeValueLabel->Caption   = TourPtr->TotalTime().AsStr().c_str();

  FillTimetableListView(SelectedTourIndex);

  CursorWaitClose();
 }

void               TTourTripDiagramForm::NotifySelectedTourChanged
                   (void)
 {
  TourTourPtrClass                     TourPtr;
  TourTourSchedulePtrClass             TourSchedulePtr;
  TourBusPtrClass                      BusPtr;
  AnsiString                           CaptionStr;

  CursorWaitOpen();

  if (*((unsigned int*)(TourListView->Selected->Data)) != SelectedTourIndex)
   {
    TourListView->Selected = TourListViewItemByData(SelectedTourIndex);
    TourListView->Selected->MakeVisible(false);
   }

  UpdateColorTable();
  UpdateChart();

  TourPtr         = DataStoragePtr->TourSet()->Tour(SelectedTourIndex);
  TourSchedulePtr = TourPtr->Schedule();
  BusPtr          = TourPtr->Bus();
/*
  TourListView->Selected->Checked = TourViewInfoArray[SelectedTourIndex].VisibleFlag;

  TourListView->Selected->Caption
  = GetTourListTourBaseOutTimeStr(TourSchedulePtr);
  TourListView->Selected->SubItems->Strings[0] = GetTourListTourCaptionStr(TourPtr);
  TourListView->Selected->SubItems->Strings[1] = GetTourListTourAverageSpeedStr(TourPtr);
  TourListView->Selected->SubItems->Strings[2]
  = TourSchedulePtr->StopSchedule(0)->InTime().AsStr().c_str();
  TourListView->Selected->SubItems->Strings[3]
  = TourSchedulePtr
    ->StopSchedule(TourSchedulePtr->StopCount() - 1)->InTime().AsStr().c_str();
*/
  if (!BusPtr.IsNull())
   {
    BusModelValueLabel->Caption = BusPtr->ModelStr().c_str();

    BusCapacityValueLabel->Caption = AnsiString(BusPtr->Capacity());

    if (BusCapacityValueLabel->Caption == "0")
     {
      BusCapacityValueLabel->Caption = "";
     }
   }
  else
   {
    BusModelValueLabel->Caption    = "";
    BusCapacityValueLabel->Caption = "";
   }

  TripPathLengthValueLabel->Caption = GetTourListTourTotalDistanceStr(TourPtr);//->TotalDistance());
  TripPathTimeValueLabel->Caption   = TourPtr->TotalTime().AsStr().c_str();

  FillTimetableListView(SelectedTourIndex);

  CursorWaitClose();
 }
//---------------------------------------------------------------------------

void              TTourTripDiagramForm::NotifyBaseStopChanged
                                                       (void)
 {
  UpdateChart();

  UpdateTourListBaseOutTime();
 }

void __fastcall TTourTripDiagramForm::TourListViewCustomDrawItem(
      TCustomListView *Sender, TListItem *Item, TCustomDrawState State,
      bool &DefaultDraw)
 {
  TRect                                 IconRect;
  TColor                                StoredBrushColor;
  TColor                                StoredPenColor;
  int                                   RectWidth;
  int                                   RectHeight;
  TColor                                ItemColor;

  IconRect = Item->DisplayRect(drIcon);

  RectWidth  = IconRect.Width();
  RectHeight = IconRect.Height();

  IconRect.Left   += (RectWidth - TripDiagramTourListViewIconSize) / 2 - 1;
  IconRect.Top    += (RectHeight - TripDiagramTourListViewIconSize) / 2 ;
  IconRect.Right  = IconRect.Left + TripDiagramTourListViewIconSize;
  IconRect.Bottom = IconRect.Top  + TripDiagramTourListViewIconSize;

  StoredBrushColor = TourListView->Canvas->Brush->Color;
  StoredPenColor   = TourListView->Canvas->Pen->Color;

  TourListView->Canvas->Brush->Color = clWindow;//White;
  TourListView->Canvas->Pen->Color   = clWindow;//White;
//  TourListView->Canvas->FillRect(Item->DisplayRect(drBounds));
  TourListView->Canvas->FillRect(Item->DisplayRect(drSelectBounds));

//  ItemColor = TourData.TourDrawColor(Item->Index);
  if (Item->Data != NULL)
   {
    ItemColor = TourViewInfoArray[*((unsigned int*)(Item->Data))].Color;

    TourListView->Canvas->Brush->Color = ItemColor;
    TourListView->Canvas->Pen->Color   = ItemColor;
    TourListView->Canvas->FillRect(IconRect);
   }

  TourListView->Canvas->Brush->Color = StoredBrushColor;
  TourListView->Canvas->Pen->Color   = StoredPenColor;
 }
//-----------------------------`----------------------------------------------

void __fastcall TTourTripDiagramForm::ChartPaintBoxMouseDown(
      TObject *Sender, TMouseButton Button, TShiftState Shift, int X,
      int Y)
 {
  unsigned int     ButtonCode;

  if      (Button == mbRight)
   {
    ButtonCode = VCanvasMouseButtonRight;
   }
  else if (Button == mbMiddle)
   {
    ButtonCode = VCanvasMouseButtonMiddle;
   }
  else
   {
    ButtonCode            = VCanvasMouseButtonLeft;
    ButtonLeftPressedFlag = true;
   }

  ChartCanvas.OnMouseClick(ButtonCode,X,Y);

  LastMousePosX         = X;
  LastMousePosY         = Y;
 }

void TTourTripDiagramForm::SetViewScale(float          Scale)
 {
  if (Scale > 0.0)
   {
    int   PaintBoxClientHeight;
    int   PaintBoxClientWidth;
    int   VertPaintBoxOffset;
    float HorzScrollBarPositionFactor;
    float LastStopDistance;

    LastStopDistance = DistanceCache.DistanceToLast(0);

    if (ChartScrollBox->HorzScrollBar->Visible)
     {
      HorzScrollBarPositionFactor = ((float)(ChartScrollBox->HorzScrollBar->Position)) /
                                     ((float)(ChartScrollBox->HorzScrollBar->Range));
     }
    else
     {
      HorzScrollBarPositionFactor = 0.5;
     }

    VertPaintBoxOffset = ChartScrollBox->VertScrollBar->Position / DistanceViewScale;

    PaintBoxClientHeight = LastStopDistance * DistanceBaseScale * Scale + (2 * TripDiagramChartAxisOffsetY);
    PaintBoxClientWidth  = TripDiagramHoursPerDay * TimeBaseScale * Scale + (2 * TripDiagramChartAxisOffsetX + StopNameMaxWidth);

    if (Win32Platform != VER_PLATFORM_WIN32_NT)
     {
      if (PaintBoxClientWidth > TripDiagramCanvasWin9XMaxWidth)
       {
        PaintBoxClientWidth = TripDiagramCanvasWin9XMaxWidth;
        Scale = ((float)(PaintBoxClientWidth - (2 * TripDiagramChartAxisOffsetX + StopNameMaxWidth))) / ((float)TripDiagramHoursPerDay * TimeBaseScale);
        PaintBoxClientHeight = LastStopDistance * DistanceBaseScale * Scale + (2 * TripDiagramChartAxisOffsetY);
       }

      if (PaintBoxClientHeight > TripDiagramCanvasWin9XMaxHeight)
       {
        PaintBoxClientHeight = TripDiagramCanvasWin9XMaxHeight;
        Scale = ((float)(PaintBoxClientHeight - (2 * TripDiagramChartAxisOffsetY))) / ((float)(LastStopDistance * DistanceBaseScale));
        PaintBoxClientWidth  = TripDiagramHoursPerDay * TimeBaseScale * Scale + (2 * TripDiagramChartAxisOffsetX + StopNameMaxWidth);
       }
     }

    ChartPaintBox->ClientHeight = PaintBoxClientHeight;
    ChartPaintBox->ClientWidth  = PaintBoxClientWidth;

    if (ChartScrollBox->HorzScrollBar->Visible)
     {
      ChartScrollBox->HorzScrollBar->Position = ((float)(ChartScrollBox->HorzScrollBar->Range)) * HorzScrollBarPositionFactor;
     }

    if (ChartScrollBox->VertScrollBar->Visible)
     {
      ChartScrollBox->VertScrollBar->Position = ((float)(VertPaintBoxOffset)) * Scale;
     }

    DistanceViewScale = Scale;
    TimeViewScale     = Scale;
   }

  if (Scale == 0.25)
   {
    Scale25PrcPopupMenuItem->Checked = true;
   }
  else
   {
    Scale25PrcPopupMenuItem->Checked = false;
   }

  if (Scale == 0.5)
   {
    Scale50PrcPopupMenuItem->Checked = true;
   }
  else
   {
    Scale50PrcPopupMenuItem->Checked = false;
   }

  if (Scale == 0.75)
   {
    Scale75PrcPopupMenuItem->Checked = true;
   }
  else
   {
    Scale75PrcPopupMenuItem->Checked = false;
   }

  if (Scale == 1.0)
   {
    Scale100PrcPopupMenuItem->Checked = true;
   }
  else
   {
    Scale100PrcPopupMenuItem->Checked = false;
   }

  if (Scale == 1.5)
   {
    Scale150PrcPopupMenuItem->Checked = true;
   }
  else
   {
    Scale150PrcPopupMenuItem->Checked = false;
   }

  if (Scale == 2.0)
   {
    Scale200PrcPopupMenuItem->Checked = true;
   }
  else
   {
    Scale200PrcPopupMenuItem->Checked = false;
   }

  if (Scale == 5.0)
   {
    Scale500PrcPopupMenuItem->Checked = true;
   }
  else
   {
    Scale500PrcPopupMenuItem->Checked = false;
   }

  UpdateChart();
 }

void __fastcall TTourTripDiagramForm::Scale25PrcPopupMenuItemClick(
      TObject *Sender)
 {
  SetViewScale(0.25);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::Scale50PrcPopupMenuItemClick(
      TObject *Sender)
 {
  SetViewScale(0.5);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::Scale75PrcPopupMenuItemClick(
      TObject *Sender)
 {
  SetViewScale(0.75);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::Scale100PrcPopupMenuItemClick(
      TObject *Sender)
 {
  SetViewScale(1.0);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::Scale150PrcPopupMenuItemClick(
      TObject *Sender)
 {
  SetViewScale(1.5);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::Scale200PrcPopupMenuItemClick(
      TObject *Sender)
 {
  SetViewScale(2.0);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::Scale500PrcPopupMenuItemClick(
      TObject *Sender)
 {
  SetViewScale(5.0);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::ScaleFitToHeightPrcPopupMenuItemClick(
      TObject *Sender)
 {
  float ViewScale;

  ViewScale = ((float)(ChartScrollBox->ClientHeight - (2 * TripDiagramChartAxisOffsetY))) / ((float)(DistanceCache.DistanceToLast(0) * DistanceBaseScale));

  SetViewScale(ViewScale);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::ScaleFitToWidthPrcPopupMenuItemClick(
      TObject *Sender)
 {
  float ViewScale;

  ViewScale = ((float)(ChartScrollBox->ClientWidth - (2 * TripDiagramChartAxisOffsetX + StopNameMaxWidth))) / ((float)TripDiagramHoursPerDay * TimeBaseScale);

  SetViewScale(ViewScale);
 }
//---------------------------------------------------------------------------


void __fastcall TTourTripDiagramForm::ShowGridPopupMenuItemClick(
      TObject *Sender)
 {
  if (ShowGridPopupMenuItem->Checked)
   {
    ShowGridPopupMenuItem->Checked = false;
    ShowDistanceGridFlag           = false;
    ShowTimeGridFlag               = false;
   }
  else
   {
    ShowGridPopupMenuItem->Checked = true;
    ShowDistanceGridFlag           = true;
    ShowTimeGridFlag               = true;
   }

  UpdateChart();
 }
//---------------------------------------------------------------------------

void            TTourTripDiagramForm::ShowForwardTours    (void)
 {
  unsigned int                                             TourIndex;
  unsigned int                                             TourCount;
  TourTourSetPtrClass                                      TourSetPtr;

  TourSetPtr = DataStoragePtr->TourSet();
  TourCount  = TourSetPtr->Count();

  TourListView->Items->BeginUpdate();

  for (TourIndex = 0; TourIndex < TourCount; TourIndex++)
   {
    if (IsTourForward(TourIndex))
     {
      TourViewInfoArray[TourIndex].VisibleFlag = true;

      if (TourIndex < TourListView->Items->Count)
       {
        TListItem                     *ListItemPtr;

        ListItemPtr = TourListViewItemByData(TourIndex);

        if (ListItemPtr != NULL)
         {
          if (!ListItemPtr->Checked)
           {
            ListItemPtr->Checked = true;
           }
         }  
       }
     }
   }
   
  TourListView->Items->EndUpdate();

  ShowForwardToursFlag                   = true;
  ShowForwardToursPopupMenuItem->Checked = true;
 }

void            TTourTripDiagramForm::ShowBackwardTours   (void)
 {
  unsigned int                                             TourIndex;
  unsigned int                                             TourCount;
  TourTourSetPtrClass                                      TourSetPtr;

  TourSetPtr = DataStoragePtr->TourSet();
  TourCount  = TourSetPtr->Count();

  TourListView->Items->BeginUpdate();

  for (TourIndex = 0; TourIndex < TourCount; TourIndex++)
   {
    if (!IsTourForward(TourIndex))
     {
      TourViewInfoArray[TourIndex].VisibleFlag = true;

      if (TourIndex < TourListView->Items->Count)
       {
        TListItem                     *ListItemPtr;

        ListItemPtr = TourListViewItemByData(TourIndex);

        if (ListItemPtr != NULL)
         {
          if (!ListItemPtr->Checked)
           {
            ListItemPtr->Checked = true;
           }
         }  
       }
     }
   }

  TourListView->Items->EndUpdate();

  ShowBackwardToursFlag                   = true;
  ShowBackwardToursPopupMenuItem->Checked = true;
 }

void            TTourTripDiagramForm::HideForwardTours    (void)
 {
  unsigned int                                             TourIndex;
  unsigned int                                             TourCount;
  TourTourSetPtrClass                                      TourSetPtr;

  TourSetPtr = DataStoragePtr->TourSet();
  TourCount  = TourSetPtr->Count();

  TourListView->Items->BeginUpdate();

  for (TourIndex = 0; TourIndex < TourCount; TourIndex++)
   {
    if (IsTourForward(TourIndex))
     {
      TourViewInfoArray[TourIndex].VisibleFlag = false;

      if (TourIndex < TourListView->Items->Count)
       {
        TListItem                     *ListItemPtr;

        ListItemPtr = TourListViewItemByData(TourIndex);

        if (ListItemPtr != NULL)
         {
          if (ListItemPtr->Checked)
           {
            ListItemPtr->Checked = false;
           }
         }  
       }
     }
   }

  TourListView->Items->EndUpdate();

  ShowForwardToursFlag                   = false;
  ShowForwardToursPopupMenuItem->Checked = false;
 }

void            TTourTripDiagramForm::HideBackwardTours   (void)
 {
  unsigned int                                             TourIndex;
  unsigned int                                             TourCount;
  TourTourSetPtrClass                                      TourSetPtr;

  TourSetPtr = DataStoragePtr->TourSet();
  TourCount  = TourSetPtr->Count();

  TourListView->Items->BeginUpdate();

  for (TourIndex = 0; TourIndex < TourCount; TourIndex++)
   {
    if (!IsTourForward(TourIndex))
     {
      TourViewInfoArray[TourIndex].VisibleFlag = false;

      if (TourIndex < TourListView->Items->Count)
       {
        TListItem                     *ListItemPtr;

        ListItemPtr = TourListViewItemByData(TourIndex);

        if (ListItemPtr != NULL)
         {
          if (ListItemPtr->Checked)
           {
            ListItemPtr->Checked = false;
           }
         }  
       }
     }
   }

  TourListView->Items->EndUpdate();

  ShowBackwardToursFlag                   = false;
  ShowBackwardToursPopupMenuItem->Checked = false;
 }

void __fastcall TTourTripDiagramForm::ShowForwardToursPopupMenuItemClick(
      TObject *Sender)
 {
  if (ShowForwardToursFlag)
   {
    HideForwardTours();
   }
  else
   {
    ShowForwardTours();
   }

  UpdateChart();
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::ShowBackwardToursPopupMenuItemClick(
      TObject *Sender)
 {
  if (ShowBackwardToursFlag)
   {
    HideBackwardTours();
   }
  else
   {
    ShowBackwardTours();
   }

  UpdateChart();
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::OptionsDialogPopupMenuItemClick(
      TObject *Sender)
 {
  TTourTripDiagramOptionsForm         *OptionsDialogPtr;

  OptionsDialogPtr = new TTourTripDiagramOptionsForm(this);

  if (OptionsDialogPtr != NULL)
   {
    OptionsDialogPtr->ShowForwardTours  = ShowForwardToursFlag;
    OptionsDialogPtr->ShowBackwardTours = ShowBackwardToursFlag;
    OptionsDialogPtr->ShowTourInOutRow  = ShowTourInOutRowsFlag;
    OptionsDialogPtr->ShowGrid          = ShowDistanceGridFlag;
    OptionsDialogPtr->BaseSpeed         = BaseSpeed;
    OptionsDialogPtr->BaseSpeedAngle    = BaseSpeedAngle;
    OptionsDialogPtr->ViewScale         = DistanceViewScale;
    OptionsDialogPtr->MonoColorTourMode = MonoColorTourModeFlag;
    OptionsDialogPtr->GridColor         = ChartGridColor;
    OptionsDialogPtr->TourSelectedColor = ChartSelectedTourColor;
    OptionsDialogPtr->TourCommonColor   = ChartCommonTourColor;

    if (OptionsDialogPtr->ShowModal() == mrOk)
     {
      if (OptionsDialogPtr->ShowForwardTours != ShowForwardToursFlag)
       {
        if (OptionsDialogPtr->ShowForwardTours)
         {
          ShowForwardTours();
         }
        else
         {
          HideForwardTours();
         }
       }

      if (OptionsDialogPtr->ShowBackwardTours != ShowBackwardToursFlag)
       {
        if (OptionsDialogPtr->ShowBackwardTours)
         {
          ShowBackwardTours();
         }
        else
         {
          HideBackwardTours();
         }
       }

      ShowTourInOutRowsFlag                  = OptionsDialogPtr->ShowTourInOutRow;
      ShowTourInOutRowPopupMenuItem->Checked = ShowTourInOutRowsFlag;

      if (OptionsDialogPtr->ShowGrid != ShowDistanceGridFlag)
       {
        if (OptionsDialogPtr->ShowGrid)
         {
          ShowGridPopupMenuItem->Checked = true;
          ShowDistanceGridFlag           = true;
          ShowTimeGridFlag               = true;
         }
        else
         {
          ShowGridPopupMenuItem->Checked = false;
          ShowDistanceGridFlag           = false;
          ShowTimeGridFlag               = false;
         }
       }

      if (OptionsDialogPtr->MonoColorTourMode != MonoColorTourModeFlag)
       {
        MonoColorTourModeFlag                = OptionsDialogPtr->MonoColorTourMode;
        MonoColorToursPopupMenuItem->Checked = MonoColorTourModeFlag;
       }

      if (OptionsDialogPtr->GridColor != ChartGridColor)
       {
        ChartGridColor = OptionsDialogPtr->GridColor;
       }

      if (OptionsDialogPtr->TourCommonColor != ChartCommonTourColor)
       {
        ChartCommonTourColor = OptionsDialogPtr->TourCommonColor;
       }

      if (OptionsDialogPtr->TourSelectedColor != ChartSelectedTourColor)
       {
        ChartSelectedTourColor = OptionsDialogPtr->TourSelectedColor;
       }

      if ((OptionsDialogPtr->BaseSpeed      != BaseSpeed) ||
          (OptionsDialogPtr->BaseSpeedAngle != BaseSpeedAngle))
       {
        BaseSpeed      = OptionsDialogPtr->BaseSpeed;
        BaseSpeedAngle = OptionsDialogPtr->BaseSpeedAngle;

        RecalcTimeScale();
       }

      if (OptionsDialogPtr->ViewScale != DistanceViewScale)
       {
        SetViewScale(OptionsDialogPtr->ViewScale);
       }

      UpdateColorTable();
      InfoPanelUpdate();
      UpdateChart();
     }

    delete OptionsDialogPtr;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::ChartPaintBoxMouseMove(
      TObject *Sender, TShiftState Shift, int X, int Y)
 {
  int                                  MouseTime;
  float                                MouseDistance;
  unsigned int                         StopCount;
  TourStopSetPtrClass                  StopSetPtr;

  if (ButtonLeftPressedFlag)
   {
    if      ((X != LastMousePosX) && (ChartScrollBox->HorzScrollBar->Visible))
     {
      int    DeltaX;
      int    ScrollXPosition;
      int    ScrollXRange;
      TPoint MousePos;

      DeltaX          = X - LastMousePosX;
      ScrollXPosition = ChartScrollBox->HorzScrollBar->Position;
      ScrollXRange    = ChartScrollBox->HorzScrollBar->Range;

      ScrollXPosition -= DeltaX * (((float)ChartPaintBox->ClientWidth) / ((float)(ScrollXRange)));

      ChartScrollBox->HorzScrollBar->Position = ScrollXPosition;
     }
   }

  LastMousePosX = X;
  LastMousePosY = Y;

  // Get time by mouse X pos

  MouseTime = (LastMousePosX - (TripDiagramChartAxisOffsetX + StopNameMaxWidth)) * TripDiagramMinutesPerHour /
                (TimeBaseScale * TimeViewScale);

  if ((MouseTime < 0) || (MouseTime > TripDiagramMinutesPerDay))
   {
    HintTimeValueLabel->Caption = "";
   }
  else
   {
    HintTimeValueLabel->Caption = TripDiagramTimeInMinutesToStr(MouseTime);
   }

  // Get distance position by mouse Y pos

  StopSetPtr    = ChartDataStoragePtr->StopSet();
  StopCount     = StopSetPtr->Count();
  MouseDistance = ((float)(ChartPaintBox->ClientHeight - TripDiagramChartAxisOffsetY - LastMousePosY)) /
                    (DistanceBaseScale * DistanceViewScale);

  if (StopCount > 0)
   {
    if ((MouseDistance < 0) ||
        (MouseDistance > DistanceCache.DistanceToLast(0)))
     {
      HintFromValueLabel->Caption = "";
      HintToValueLabel->Caption = "";
     }
    else
     {
      bool         FoundFlag;
      unsigned int StopIndex;

      FoundFlag = false;
      StopIndex = 1;

      while ((StopIndex < StopCount) && (!FoundFlag))
       {
        if (DistanceCache.DistanceFromFirst(StopIndex) > MouseDistance)
         {
          FoundFlag = true;
         }
        else
         {
          StopIndex++;
         }
       }

      if (!FoundFlag)
       {
        HintFromValueLabel->Caption = "";
        HintToValueLabel->Caption = "";
       }
      else
       {
        HintFromValueLabel->Caption = AnsiString(StopSetPtr->Stop(StopIndex - 1)->NameStr().c_str()) +
                                       AnsiString().sprintf("(%.1f)",MouseDistance - DistanceCache.DistanceFromFirst(StopIndex - 1));
        HintToValueLabel->Caption   = AnsiString(StopSetPtr->Stop(StopIndex)->NameStr().c_str()) +
                                       AnsiString().sprintf("(%.1f)",DistanceCache.DistanceFromFirst(StopIndex) - MouseDistance);
       }
     }
   }  
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::ChartPaintBoxMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
 {
  if (Button == mbLeft)
   {
    ButtonLeftPressedFlag = false;
   }

  LastMousePosX = X;
  LastMousePosY = Y;
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::MonoColorToursPopupMenuItemClick(
      TObject *Sender)
 {
  MonoColorTourModeFlag                = !MonoColorTourModeFlag;
  MonoColorToursPopupMenuItem->Checked = MonoColorTourModeFlag;

  UpdateColorTable();
  UpdateChart();
  InfoPanelUpdate();
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::PrintTourInfoPopupMenuItemClick(
      TObject *Sender)
 {
  if (SelectedTourIndex != TripDiagramTourIndexUndefined)
   {
    TourTourPtrClass  SelectedTourPtr;

    SelectedTourPtr = DataStoragePtr->TourSet()->Tour(SelectedTourIndex);

    #if defined(TOUR_DEMO_MODE)
     {
      TripInfoReportGenerateDemo(DataStoragePtr,
                                 SelectedTourPtr->IdStr().c_str(),
                                 SelectedTourPtr->NameStr().c_str());
     }
    #else
     {
      TripInfoReportGenerate(SelectedTourPtr->IdStr().c_str(),
                             SelectedTourPtr->NameStr().c_str());
     }
    #endif
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourTripDiagramForm::PrintStopPopupMenuItemClick(TObject *Sender)
 {
  TourStopPtrClass                     BaseStopPtr;

  BaseStopPtr = ChartDataStoragePtr->StopSet()->Stop(BaseStopIndex);

  #if defined(TOUR_DEMO_MODE)
   {
    StopInfoReportGenerateDemo(DataStoragePtr,
                               BaseStopPtr->IdStr().c_str(),
                               BaseStopPtr->NameStr().c_str(),
                               true);
   }
  #else
   {
    StopInfoReportGenerate(BaseStopPtr->IdStr().c_str(),
                           BaseStopPtr->NameStr().c_str(),
                           true);
   }
  #endif
 }
//---------------------------------------------------------------------------

void TTourTripDiagramForm::HideTour(unsigned int   TourIndex)
 {
  TourViewInfoArray[TourIndex].VisibleFlag = false;
 }

void TTourTripDiagramForm::ShowTour(unsigned int   TourIndex)
 {
  TourViewInfoArray[TourIndex].VisibleFlag = true;
 }

bool TTourTripDiagramForm::IsTourVisible(unsigned int   TourIndex)
 {
  return(TourViewInfoArray[TourIndex].VisibleFlag);
 }

bool TTourTripDiagramForm::IsTourForward(unsigned int   TourIndex)
 {
  TourTourPtrClass                       TourPtr;
  TourTourSchedulePtrClass               TourSchedulePtr;
  TourStopSchedulePtrClass               FirstStopSchedulePtr;
  TourStopSchedulePtrClass               SecondStopSchedulePtr;
  float                                  FirstStopDistance;
  float                                  SecondStopDistance;

  TourPtr         = ChartDataStoragePtr->TourSet()->Tour(TourIndex);
  TourSchedulePtr = TourPtr->Schedule();

  if (TourSchedulePtr->StopCount() > 1)
   {
    FirstStopSchedulePtr  = TourSchedulePtr->StopSchedule(0);
    SecondStopSchedulePtr = TourSchedulePtr->StopSchedule(1);

    FirstStopDistance  = DistanceCache.DistanceFromFirst(FirstStopSchedulePtr->Stop()->IdStr());
    SecondStopDistance = DistanceCache.DistanceFromFirst(SecondStopSchedulePtr->Stop()->IdStr());

    if (FirstStopDistance < SecondStopDistance)
     {
      return(true);
     }
    else
     {
      return(false);
     }
   }
  else
   {
    return(true);
   }
 }

void __fastcall TTourTripDiagramForm::PrintDiagramPopupMenuItemClick(
      TObject *Sender)
 {
  TripDiagramPrint(ChartPaintBox->Canvas);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::TourListViewChange(TObject *Sender,
      TListItem *Item, TItemChange Change)
 {
  unsigned int               TourIndex;

  if (!TourListSortLockFlag)
//  if (!FillTourListViewStateFlag)
   {
    if (Change == ctState)
     {
      if (Item->Data != NULL)
       {
        TourIndex = *((unsigned int*)(Item->Data));

        if (Item->Checked)
         {
          if (!TourViewInfoArray[TourIndex].VisibleFlag)
           {
            TourViewInfoArray[TourIndex].VisibleFlag = true;
            UpdateChart();
           }
         }
        else
         {
          if (TourViewInfoArray[TourIndex].VisibleFlag)
           {
            TourViewInfoArray[TourIndex].VisibleFlag = false;
            UpdateChart();
           }
         }
       }
     }
   }  
 }

//---------------------------------------------------------------------------

float              TTourTripDiagramForm::TourStepSpeed
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    unsigned int                      StepIndex)
 {
  return (TripDiagramTourStepSpeed(TourSchedulePtr,DataStoragePtr->Topology(),StepIndex));
 }

//---------------------------------------------------------------------------

AnsiString         TTourTripDiagramForm::TourStepSpeedStr
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    unsigned int                      StepIndex)
 {
  float                                SpeedValue;
  AnsiString                           SpeedStr;

  SpeedValue = TourStepSpeed(TourSchedulePtr,StepIndex);

  SpeedStr = FormatFloat("0.0",SpeedValue);

  return (SpeedStr);
 }

//---------------------------------------------------------------------------

float              TTourTripDiagramForm::TourStepDistance
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    unsigned int                      StepIndex)
 {
  return (TripDiagramTourStepDistance(TourSchedulePtr,DataStoragePtr->Topology(),StepIndex));
 }

//---------------------------------------------------------------------------

AnsiString         TTourTripDiagramForm::TourStepDistanceStr
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    unsigned int                      StepIndex)
 {
  float                                DistanceValue;
  AnsiString                           DistanceStr;

  DistanceValue = TourStepDistance(TourSchedulePtr,StepIndex);

  DistanceStr = FormatFloat("0.0",DistanceValue);

  return (DistanceStr);
 }

//---------------------------------------------------------------------------

bool               TTourTripDiagramForm::TourSelectDialogExec
                   (void)
 {
  bool                                 ResultFlag;
  unsigned int                         TourCounter;
  unsigned int                         TourCount;
  unsigned int                        *ItemIndexPtr;
  TListItem                           *ItemPtr;
  TTourTripSwitchDialogForm           *TripSelectDialogPtr;
  TourTourSetPtrClass                  TourSetPtr;
  TourTourPtrClass                     TourPtr;
  TourTourSchedulePtrClass             TourSchedulePtr;

  ResultFlag   = true;
  TourSetPtr = DataStoragePtr->TourSet();

  TripSelectDialogPtr = new TTourTripSwitchDialogForm(this);

  if (TripSelectDialogPtr != NULL)
   {
    TripSelectDialogPtr->TourListView->Items->BeginUpdate();

    TripSelectDialogPtr->TourListView->Items->Clear();

    TourCount = TourSetPtr->Count();

    for (TourCounter = 0; TourCounter < TourCount && ResultFlag; TourCounter++)
     {
      ItemPtr = TripSelectDialogPtr->TourListView->Items->Add();

      if (ItemPtr)
       {
        TourPtr = TourSetPtr->Tour(TourCounter);
        TourSchedulePtr  = TourPtr->Schedule();

        ItemPtr->Caption = GetTourListTourBaseOutTimeStr(TourSchedulePtr);
        ItemPtr->Checked = TourViewInfoArray[TourCounter].VisibleFlag;
//        ItemPtr->SubItems->Add(GetTourListTourCaptionStr(TourPtr));
        ItemPtr->SubItems->Add(TourPtr->NameStr().c_str());
        ItemPtr->SubItems->Add(TourPtr->IdStr().c_str());

        ItemPtr->SubItems->Add(TourSchedulePtr->StopSchedule(0)->InTime().AsStr().c_str());
        ItemPtr->SubItems->Add
        (TourSchedulePtr
         ->StopSchedule(TourSchedulePtr->StopCount() - 1)->InTime().AsStr().c_str());
        ItemPtr->SubItems->Add(GetTourListTourTotalDistanceStr(TourPtr));
        ItemPtr->SubItems->Add(GetTourListTourAverageSpeedStr(TourPtr));
/*
        ItemPtr->Checked = TourViewInfoArray[TourCounter].VisibleFlag;;
        ItemPtr->Caption = TourPtr->NameStr().c_str();
        ItemPtr->SubItems->Add(TourPtr->IdStr().c_str());
        ItemPtr->SubItems->Add(FormatFloat("0.0",TourPtr->TotalDistance()));
        ItemPtr->SubItems->Add(FormatFloat("0.0",TourPtr->AverageSpeed()));
*/
        // Каждый элемент списка в диалоге имеет связанный объект с информацией о
        // порядковом номере соответствуюцего ему элементу списка

        ItemIndexPtr = new unsigned int(TourCounter);

        if (ItemIndexPtr != NULL)
         {
          ItemPtr->Data = ItemIndexPtr;
         }
        else
         {
          ResultFlag = false;
         }
       }
      else
       {
        ResultFlag = false;
       }
     }

    TripSelectDialogPtr->TourListView->Items->EndUpdate();

    if (ResultFlag)
     {
      if (TripSelectDialogPtr->ShowModal() == mrOk)
       {
        unsigned int                   SelectedItemIndex;
        bool                           FindSelectedFlag;

        FindSelectedFlag = false;

        TourListView->Items->BeginUpdate();

        // Обновляем информацию в списке рейсов
        for (TourCounter = 0; TourCounter < TourCount; TourCounter++)
         {
          ItemIndexPtr
          = ((unsigned int*)TripSelectDialogPtr->TourListView->Items->Item[TourCounter]->Data);

          if (!FindSelectedFlag)
           {
            if (TripSelectDialogPtr->TourListView->Items->Item[TourCounter]->Selected)
             {
              SelectedItemIndex = (*ItemIndexPtr);
              FindSelectedFlag  = true;
             }
           }

          ItemPtr = TourListViewItemByData(*ItemIndexPtr);

          if (ItemPtr != NULL)
           {
            ItemPtr->Checked
            = TripSelectDialogPtr->TourListView->Items->Item[TourCounter]->Checked;
           }
         }

        TourListView->Items->EndUpdate();

        if (FindSelectedFlag)
         {
          SelectedTourIndex = SelectedItemIndex;
          ItemPtr = TourListViewItemByData(SelectedTourIndex);

          if (ItemPtr != NULL)
           {
            TourListView->Selected = ItemPtr;
           }
          NotifySelectedTourChanged();
         }
       }
     }

    TripSelectDialogPtr->TourListView->Items->BeginUpdate();
    // Удаляем объекты из списка в диалоге выбора рейсов

    for (TourCounter = 0; TourCounter < TourListView->Items->Count; TourCounter++)
     {
      ItemIndexPtr
      = ((unsigned int*)(TripSelectDialogPtr->TourListView->Items->Item[TourCounter]->Data));

      if (ItemIndexPtr != NULL)
       {
        delete (ItemIndexPtr);
        TripSelectDialogPtr->TourListView->Items->Item[TourCounter]->Data = NULL;
       }
     }

    TripSelectDialogPtr->TourListView->Items->EndUpdate();

    delete (TripSelectDialogPtr);
   }
  else
   {
    ResultFlag = false;
   }

  return (ResultFlag);
 }

void __fastcall TTourTripDiagramForm::TourListViewDblClick(TObject *Sender)
 {
  TourSelectDialogExec();
 }

//---------------------------------------------------------------------------

bool               TTourTripDiagramForm::MoveTour
                   (unsigned int                      TourIndex,
                    TDateTime                         DateTimeValue)
 {
  return (TripDiagramMoveTour
          (DataStoragePtr->TourSet()->Tour(TourIndex)->Schedule(),DateTimeValue));
 }

//---------------------------------------------------------------------------

TourTourPtrClass   TTourTripDiagramForm::DublicateTour
                   (unsigned int                      TourIndex,
                    AnsiString                        NewTourIdStr,
                    AnsiString                        NewTourNameStr)
 {
  TourTourPtrClass                     SrcTourPtr(NULL);
  TourTourPtrClass                     TourCopyPtr(NULL);

  SrcTourPtr = DataStoragePtr->TourSet()->Tour(TourIndex);

  TourCopyPtr = TripDiagramAppendTour(DataStoragePtr,NewTourIdStr,NewTourNameStr);

  TripDiagramFillTour(TourCopyPtr,SrcTourPtr);

  return (TourCopyPtr);
 }

//---------------------------------------------------------------------------

bool               TTourTripDiagramForm::TourTimetableDialogExec
                   (unsigned int                      TourIndex)
 {
  bool                                 ResultFlag;
  TListItem                           *ItemPtr;
  TTourTripTimeTableDialogForm        *TripTimetableDialogPtr;
  TourTourPtrClass                     TourPtr;
  TourCachedUpdateDataClass           *LocalDataStorageLowPtr;
  TourDataPtrClass                     LocalDataStoragePtr;

  TripTimetableDialogPtr = new TTourTripTimeTableDialogForm(this);

  if (TripTimetableDialogPtr != NULL)
   {
    AnsiString                         CaptionStr;

    TourPtr = DataStoragePtr->TourSet()->Tour(TourIndex);

    CaptionStr  = TripTimetableDialogPtr
                  ->VStringStorage->Lines->Strings[TourTripTimeTableCaptionStr];
    CaptionStr += TourPtr->IdStr().c_str();
    CaptionStr += " ";
    CaptionStr += TourPtr->NameStr().c_str();

    TripTimetableDialogPtr->Caption = CaptionStr;

    LocalDataStorageLowPtr = new TourCachedUpdateDataClass(DataStoragePtr);
    LocalDataStoragePtr    = TourDataPtrClass(LocalDataStorageLowPtr);

    ResultFlag = TripTimetableDialogPtr->Init(TourIndex,LocalDataStoragePtr);

    if (ResultFlag)
     {
      if (TripTimetableDialogPtr->ShowModal() == mrOk)
       {
        LocalDataStorageLowPtr->Apply();
//        FillTimetableListView(TourIndex);// - !!!!
        NotifySelectedTourChanged();
       }
      else
       {
        LocalDataStorageLowPtr->Cancel();
       }
     }

    delete (TripTimetableDialogPtr);
   }
  else
   {
    ResultFlag = false;
   }

  return (ResultFlag);
 }

//---------------------------------------------------------------------------
bool               TTourTripDiagramForm::GetTourCopyAttributes
                   (unsigned int                      TourIndex,
                    AnsiString                       &TourIdStrRef,
                    AnsiString                       &TourFirstNameStrRef,
                    AnsiString                       &TourSecondNameStrRef)
 {
  return (TripDiagramTourCopyAttributes(DataStoragePtr->TourSet(),
                                        TourIndex,
                                        TourIdStrRef,
                                        TourFirstNameStrRef,
                                        TourSecondNameStrRef));
 }

//---------------------------------------------------------------------------

bool               TTourTripDiagramForm::TourCopyDialogExec
                   (unsigned int                      TourIndex,
                    TourTourPtrClass                 &TourPtrRef,
                    bool                              InvertTourNameFlag)
 {
  bool                             ResultFlag;
  TTourTripTourCopyDialogForm     *TourCopyDialogFormPtr;
  AnsiString                       TripIdStr;
  AnsiString                       TripNameStr;
  AnsiString                       TripNameFirstStr;
  AnsiString                       TripNameSecondStr;

  ResultFlag = GetTourCopyAttributes
               (TourIndex,TripIdStr,TripNameFirstStr,TripNameSecondStr);

  if (ResultFlag)
   {
    TourCopyDialogFormPtr = new TTourTripTourCopyDialogForm(this);

    if (TourCopyDialogFormPtr != NULL)
     {
      TourCopyDialogFormPtr->TripIdEdit->Text   = TripIdStr;

      if (InvertTourNameFlag)
       {
        TripNameStr = TripNameSecondStr + " - " + TripNameFirstStr;
       }
      else
       {
        TripNameStr = TripNameFirstStr + " - " + TripNameSecondStr;
       }

      TourCopyDialogFormPtr->TripNameEdit->Text = TripNameStr;

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
     }
    else
     {
      ResultFlag = false;
     }
   }

  if (ResultFlag)
   {
    TourPtrRef = DublicateTour(TourIndex,TripIdStr,TripNameStr);
   }
   
  return (ResultFlag);
 }

//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::TimetableListViewDblClick(
      TObject *Sender)
 {
  TourTimetableDialogExec(SelectedTourIndex);
 }
 
//---------------------------------------------------------------------------

void TTourTripDiagramForm::ScrollToTour            (unsigned int   TourIndex)
 {
  TourTourSetPtrClass                               TourSetPtr;

  TourSetPtr = ChartDataStoragePtr->TourSet();

  if (TourIndex < TourSetPtr->Count())
   {
    TourTourSchedulePtrClass                        TourSchedulePtr;
    TourStopSchedulePtrClass                        FirstStopSchedulePtr;
    int                                             FirstStopTimePos;
    int                                             FirstStopDistancePos;

    TourSchedulePtr      = TourSetPtr->Tour(TourIndex)->Schedule();

    if (TourSchedulePtr->StopCount() > 0)
     {
      FirstStopSchedulePtr = TourSchedulePtr->StopSchedule(0);

      FirstStopTimePos     = TimeToPixels((float)(FirstStopSchedulePtr->InTime()) / (float)TripDiagramMinutesPerHour);
/*
      FirstStopDistancePos = DistanceToPixels(TripDiagramTourStopDistance
                                               (ChartDataStoragePtr,
                                                ChartDataStoragePtr->StopSet(),
                                                FirstStopSchedulePtr->Stop()->IdStr()));
*/

      FirstStopDistancePos = DistanceToPixels(DistanceCache.DistanceFromFirst
                                               (FirstStopSchedulePtr->Stop()->IdStr()));

      if (ChartScrollBox->HorzScrollBar->Visible)
       {
        ChartScrollBox->HorzScrollBar->Position = ((float)(FirstStopTimePos)) / ((float)(ChartPaintBox->ClientWidth)) * ChartScrollBox->HorzScrollBar->Range;
       }

      if (ChartScrollBox->VertScrollBar->Visible)
       {
        ChartScrollBox->VertScrollBar->Position = ((float)(FirstStopDistancePos)) / ((float)(ChartPaintBox->ClientHeight)) * ChartScrollBox->VertScrollBar->Range;
       }
     }
   }
 }

void __fastcall TTourTripDiagramForm::PrintDiagramFullPopupMenuItemClick(
      TObject *Sender)
 {
  TRect PrintRectangle;

  PrintRectangle = ChartPaintBox->ClientRect;

  TripDiagramPrint(ChartPaintBox->Canvas,&PrintRectangle);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::TourListViewColumnClick(
      TObject *Sender, TListColumn *Column)
 {
  if (abs(TourListViewColumnToSort) - 1 != Column->Index)
   {
    TourListViewColumnToSort = Column->Index + 1;
   }
  else
   {
    TourListViewColumnToSort *= -1;
   }

//  ((TCustomListView *)Sender)->CustomSort(NULL,TourListViewColumnToSort);
  TourListView->AlphaSort();

  if (TourListView->Selected != NULL)
   {
    TourListView->Selected->MakeVisible(false);
   }
 }

void __fastcall TTourTripDiagramForm::TourListViewCompare(TObject *Sender,
      TListItem *Item1, TListItem *Item2, int Data, int &Compare)
 {
  bool                                 InvertFlag;

  if (!TourListSortLockFlag)
   {
    InvertFlag = false;

    if (abs(TourListViewColumnToSort) <= 1)
     {
      Compare = TripDiagramCompareTime(Item1->Caption,Item2->Caption);

      if (TourListViewColumnToSort < 0 && !Item1->Caption.IsEmpty() && !Item2->Caption.IsEmpty())
       {
        InvertFlag = true;
       }
     }
    else
     {
      int                                SubItemIndex;

      SubItemIndex = abs(TourListViewColumnToSort) - 2;

      if ((Item1->SubItems->Count >= SubItemIndex + 1) &&
          (Item2->SubItems->Count >= SubItemIndex + 1))
       {

        if (SubItemIndex == 0)
         {
          Compare = CompareText(Item1->SubItems->Strings[SubItemIndex],
                                Item2->SubItems->Strings[SubItemIndex]);

          if (TourListViewColumnToSort < 0)
           {
            InvertFlag = true;
           }
         }
        else if (SubItemIndex == 1)
         {
          Compare = TripDiagramCompareDouble(Item1->SubItems->Strings[SubItemIndex],
                                             Item2->SubItems->Strings[SubItemIndex]);
          if (TourListViewColumnToSort < 0)
           {
            InvertFlag = true;
           }
         }
        else
         {
          Compare = TripDiagramCompareTime(Item1->SubItems->Strings[SubItemIndex],
                                           Item2->SubItems->Strings[SubItemIndex]);

          if (TourListViewColumnToSort < 0                                          &&
              !Item1->SubItems->Strings[SubItemIndex].IsEmpty() &&
              !Item2->SubItems->Strings[SubItemIndex].IsEmpty())
           {
            InvertFlag = true;
           }
         }
       }
     }

    if (InvertFlag)
     {
      Compare *= (-1);
     }
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::TourMoveActionExecute(
      TObject *Sender)
 {
  if ((TourListView->Selected != NULL) && (TourListView->Selected->Data != NULL))
   {
    TTourTripTourMoveDialogForm     *TourMoveDialogPtr;
    unsigned int                     TourIndex;
    TDateTime                        InTimeValue;
    bool                             ResultFlag;
    bool                             IsCopyFlag;

    TourIndex         = *((unsigned int*)(TourListView->Selected->Data));
    ResultFlag        = false;

    try
     {
      InTimeValue
      = TDateTime
        (DataStoragePtr
         ->TourSet()
           ->Tour(TourIndex)->Schedule()->StopSchedule(0)->InTime().AsStr().c_str(),
         TDateTime::Time);

      TourMoveDialogPtr = new TTourTripTourMoveDialogForm(this);

      if (TourMoveDialogPtr != NULL)
       {
        TourMoveDialogPtr->Caption
        = GetTranslatedStr(TourTripDiagramMoveDialogCaptionStr);
        TourMoveDialogPtr->TimeStartPicker->Time = InTimeValue;
        ResultFlag = true;
       }

      if (ResultFlag)
       {
        if (TourMoveDialogPtr->ShowModal() == mrOk)
         {
          InTimeValue = TourMoveDialogPtr->TimeStartPicker->Time;

          if (TourMoveDialogPtr->TourCopyCheckBox->Checked)
           {
            TourTourPtrClass             TourCopyPtr;

            ResultFlag = TourCopyDialogExec(TourIndex,TourCopyPtr,false);

            if (ResultFlag)
             {
              TourIndex
              = TripDiagramTourIndexById
                (DataStoragePtr->TourSet(),TourCopyPtr->IdStr().c_str());

              TourViewInfoArray[TourIndex].VisibleFlag = true;

              ResultFlag = TourListViewTourAppend(TourIndex,TourCopyPtr);
             }
           }

          if (ResultFlag)
           {
            if (SelectedTourIndex != TourIndex)
             {
              SelectedTourIndex = TourIndex;
             }

            MoveTour(TourIndex,InTimeValue);

            NotifySelectedTourChanged();

            FillTimetableListView(TourIndex);
           }
         }
        else
         {
          ResultFlag = false;
         }

        delete TourMoveDialogPtr;
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }

//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::TourInvertActionExecute(
      TObject *Sender)
 {
  if ((TourListView->Selected != NULL) && (TourListView->Selected->Data != NULL))
   {
    unsigned int                     TourIndex;
    TTourTripTourMoveDialogForm     *TourMoveDialogPtr;
    TourTourSchedulePtrClass         TourSchedulePtr;
    bool                             ResultFlag;

    TourIndex = *((unsigned int*)(TourListView->Selected->Data));

    TourSchedulePtr = DataStoragePtr->TourSet()->Tour(TourIndex)->Schedule();

    ResultFlag = TripDiagramCanReflectTour(TourSchedulePtr,DataStoragePtr->Topology());

    if (!ResultFlag)
     {
      if (TourShowDialogYesNo
          (TourMessageModule->VStringStorage->Lines->Strings
           [TourMessageModuleInvertExpectedMoreDataMessageStr].c_str()) == ID_YES)
       {
        ResultFlag = TripDiagramPrepareToReflectTour(TourSchedulePtr,DataStoragePtr->Topology());
       }
     }

    if (ResultFlag)
     {
      TourMoveDialogPtr = NULL;

      TourMoveDialogPtr = new TTourTripTourMoveDialogForm(this);

      if (TourMoveDialogPtr != NULL)
       {
        try
         {
          TourMoveDialogPtr->Caption
          = GetTranslatedStr(TourTripDiagramInvertDialogCaptionStr);
          TourMoveDialogPtr->TimeStartPicker->Time
          = TDateTime(TourSchedulePtr->StopSchedule(0)->InTime().AsStr().c_str(),
                      TDateTime::Time);
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
            TDateTime                DateTimeValue;

            DateTimeValue = TourMoveDialogPtr->TimeStartPicker->Time;

            if (TourMoveDialogPtr->TourCopyCheckBox->Checked)
             {
              TourTourPtrClass       TourCopyPtr(NULL);

              ResultFlag = TourCopyDialogExec(TourIndex,TourCopyPtr,true);

              if (ResultFlag)
               {
                TourIndex
                = TripDiagramTourIndexById
                  (DataStoragePtr->TourSet(),TourCopyPtr->IdStr().c_str());

                TourViewInfoArray[TourIndex].VisibleFlag = true;

                ResultFlag = TourListViewTourAppend(TourIndex,TourCopyPtr);
               }
             }

            if (ResultFlag)
             {
              if (SelectedTourIndex != TourIndex)
               {
                SelectedTourIndex = TourIndex;
                TourSchedulePtr = DataStoragePtr->TourSet()->Tour(TourIndex)->Schedule();
               }

              ResultFlag = TripDiagramInvertTour(TourSchedulePtr,DataStoragePtr->Topology());
             }

            if (ResultFlag)
             {
              MoveTour(SelectedTourIndex,DateTimeValue);

              NotifySelectedTourChanged();

              FillTimetableListView(SelectedTourIndex);
             }
           }
         }

        delete (TourMoveDialogPtr);
        TourMoveDialogPtr = NULL;
       }
     }
   }
 }

//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::TourCopyActionExecute(
      TObject *Sender)
 {
  if ((TourListView->Selected != NULL) && (TourListView->Selected->Data != NULL))
   {
    unsigned int                     TourIndex;
    TTourTripTourMoveDialogForm     *TourMoveDialogPtr;
    bool                             ResultFlag;

    TourIndex = *((unsigned int*)(TourListView->Selected->Data));

    ResultFlag = false;
    TourMoveDialogPtr = NULL;

    TourMoveDialogPtr = new TTourTripTourMoveDialogForm(this);

    if (TourMoveDialogPtr != NULL)
     {
      try
       {
        TourMoveDialogPtr->Caption
        = GetTranslatedStr(TourTripDiagramCopyDialogCaptionStr);
        TourMoveDialogPtr->TimeStartPicker->Time
        = TDateTime
          (DataStoragePtr
           ->TourSet()
             ->Tour(TourIndex)->Schedule()->StopSchedule(0)->InTime().AsStr().c_str(),
           TDateTime::Time);
        TourMoveDialogPtr->TourCopyCheckBox->Visible = false;
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
          TourTourPtrClass           TourCopyPtr;

          ResultFlag = TourCopyDialogExec(TourIndex,TourCopyPtr,false);

          if (ResultFlag)
           {
            SelectedTourIndex
            = TripDiagramTourIndexById
              (DataStoragePtr->TourSet(),TourCopyPtr->IdStr().c_str());

            MoveTour(SelectedTourIndex,TourMoveDialogPtr->TimeStartPicker->Time);

            TourViewInfoArray[SelectedTourIndex].VisibleFlag = true;

            ResultFlag = TourListViewTourAppend(SelectedTourIndex,TourCopyPtr);

            if (ResultFlag)
             {
              NotifySelectedTourChanged();

              FillTimetableListView(SelectedTourIndex);
             }
           }
         }
       }

      delete (TourMoveDialogPtr);
      TourMoveDialogPtr = NULL;
     }
   }
 }
//---------------------------------------------------------------------------


void __fastcall TTourTripDiagramForm::CancelButtonClick(TObject *Sender)
 {
  bool                                 CancelFlag;

  CancelFlag = false;

  if (CachedUpdateDataStoragePtr != NULL)
   {
    if (CachedUpdateDataStoragePtr->ChangesCount() > 0)
     {
      if (TourShowDialogYesNoDef
          (GetTranslatedStr(TourTripDiagramCancelChangesMessageStr).c_str()) == ID_YES)
       {
        CancelFlag = true;
       }
      else
       {
        TTourDiagramChangesForm        *ChangesFormPtr;

        ChangesFormPtr = new TTourDiagramChangesForm(this);

        if (ChangesFormPtr != NULL)
         {
          ChangesFormPtr->Caption
          = GetTranslatedStr(TourTripDiagramCancelCheckedChangesMessageStr);
          ChangesFormPtr->ChangesList = CachedUpdateDataStoragePtr;
          ChangesFormPtr->ScrollBox->Enabled = false;

          if (ChangesFormPtr->ShowModal() == mrOk)
           {
            CancelFlag = true;
           }

          delete ChangesFormPtr;
         }
       }
     }
    else
     {
      TourShowDialogInformation(GetTranslatedStr(TourTripDiagramChangesAbsentMessageStr).c_str());
     }
   }

  if (CancelFlag)
   {
    CancelChanges();
   }
 }

//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::OkButtonClick(TObject *Sender)
 {
//  bool                                 ApplyFlag;
  unsigned int                         ChangesCount;
  unsigned int                         ChangesIndex;

//  ApplyFlag = false;

  #if !defined(TOUR_DEMO_MODE)
  if ((CachedUpdateDataStoragePtr != NULL) &&
      (TourDataModule->DataBaseEditModeFlag))
  #else
  if (CachedUpdateDataStoragePtr != NULL)
  #endif
   {
    ChangesCount = CachedUpdateDataStoragePtr->ChangesCount();

    if (ChangesCount > 0)
     {
      TTourDiagramChangesForm        *ChangesFormPtr;

      CursorWaitOpen();
      
      ChangesFormPtr = new TTourDiagramChangesForm(this);

      if (ChangesFormPtr != NULL)
       {
        ChangesFormPtr->Caption
        = GetTranslatedStr(TourTripDiagramApplyCheckedChangesMessageStr);
        ChangesFormPtr->ChangesList = CachedUpdateDataStoragePtr;

        if (ChangesFormPtr->ShowModal() == mrOk)

        #if !defined(TOUR_DEMO_MODE)
         {
          unsigned int                 ChangeTypeCode;
          std::string                  ChangedTourIdStr;
          vector<std::string>          TourListStore;

          TourListStore.clear();

          for (ChangesIndex = 0;ChangesIndex < ChangesCount;ChangesIndex++)
           {
            if (ChangesFormPtr->CheckBoxStorage[ChangesIndex]->Checked)
             {
              CachedUpdateDataStoragePtr
              ->GetChangeInfo(&ChangeTypeCode,ChangedTourIdStr,ChangesIndex);

              TourListStore.push_back(ChangedTourIdStr);
             }
           }

          ChangesCount = TourListStore.size();

          for (ChangesIndex = 0;ChangesIndex < ChangesCount;ChangesIndex++)
           {
            CachedUpdateDataStoragePtr
            ->ApplyTourChanges(TourListStore[ChangesIndex]);
           }

          TourShowDialogInformation(GetTranslatedStr(TourTripDiagramChangesSaveOkMessageStr).c_str());

          FillTourListView();
          NotifySelectedTourScheduleChanged();
          UpdateColorTable();
          UpdateChart();
//          ApplyFlag = true;
         }
        #else
         {
          TourShowDialogInformation
          (TourMessageModule->VStringStorage->Lines->Strings
           [TourMessageModuleFuncDemoMessageStr].c_str());
         }
        #endif

        delete (ChangesFormPtr);
       }
      CursorWaitClose();
     }
    else
     {
      TourShowDialogInformation(GetTranslatedStr(TourTripDiagramChangesAbsentMessageStr).c_str());
     }
   }
/*
  if (ApplyFlag)
   {
    ApplyChanges();
   }
*/
 }
//---------------------------------------------------------------------------

void               TTourTripDiagramForm::ApplyChanges
                   (void)
 {
  if (CachedUpdateDataStoragePtr != NULL)
   {
    CachedUpdateDataStoragePtr->Apply();
    FillTourListView();
    NotifySelectedTourScheduleChanged();
    UpdateColorTable();
    UpdateChart();
   }
 }

void               TTourTripDiagramForm::CancelChanges
                   (void)
 {
  if (CachedUpdateDataStoragePtr != NULL)
   {
    CachedUpdateDataStoragePtr->Cancel();
    FillTourListView();
    NotifySelectedTourScheduleChanged();
    UpdateColorTable();
    UpdateChart();
   }
 }

void __fastcall TTourTripDiagramForm::TourDeleteActionExecute(
      TObject *Sender)
 {
  if ((TourListView->Selected != NULL) && (TourListView->Selected->Data != NULL))
   {
    if (TourShowDialogYesNoDef
        (GetTranslatedStr(TourTripDiagramConfirmDeleteMessageStr).c_str()) == ID_YES)
     {
      unsigned int                    *ItemIndexPtr;
      unsigned int                     TourIndex;
      unsigned int                     DeleteTourIndex;
      unsigned int                     NewSelectedIndex;
      bool                             ResultFlag;

      ItemIndexPtr = ((unsigned int*)(TourListView->Selected->Data));

      if (ItemIndexPtr != NULL)
       {
        TourIndex = *ItemIndexPtr;
        DeleteTourIndex = TourListView->Selected->Index;

        if (DeleteTourIndex > 0)
         {
          NewSelectedIndex
          = *((unsigned int*)(TourListView->Items->Item[DeleteTourIndex - 1]->Data));
         }
        else
         {
          NewSelectedIndex
          = *((unsigned int*)(TourListView->Items->Item[1]->Data));;
         }

        delete (ItemIndexPtr);
        TourListView->Selected->Data = NULL;

        TourListView->Items->Delete(DeleteTourIndex);

        CachedUpdateDataStoragePtr
        ->DeleteTour
          (CachedUpdateDataStoragePtr->TourSet()->Tour(TourIndex)->IdStr());

        SelectedTourIndex = NewSelectedIndex;
        TourListView->Selected = TourListViewItemByData(SelectedTourIndex);

        NotifySelectedTourChanged();

        FillTimetableListView(SelectedTourIndex);
       }
     }
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramForm::ShowTourInOutRowPopupMenuItemClick(
      TObject *Sender)
 {
  ShowTourInOutRowsFlag                  = !ShowTourInOutRowsFlag;
  ShowTourInOutRowPopupMenuItem->Checked = ShowTourInOutRowsFlag;

  UpdateChart();
 }
//---------------------------------------------------------------------------

