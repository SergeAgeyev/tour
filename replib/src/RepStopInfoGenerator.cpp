//---------------------------------------------------------------------------
#include <stdio.h>
#include <io.h>

#include <vector>
#include <algorithm>

#include <vcl.h>
#pragma hdrstop

#include "RepStopInfoGenerator.h"
#include "StdTool.h"
#include "RepPreViewForm.h"
#include "TourTool.h"
#include "MessageModuleForm.h"

#if !defined(TOUR_DEMO_MODE)
 #include "RepStopInfoResultForm.h"
#endif

#pragma package(smart_init)

typedef struct
 {
  std::string      TourIdStr;
  std::string      TourNameStr;
  TourTimeClass    TourStepInTime;
  TourTimeClass    TourStepWaitTime;
 } StopInfoReportTourDataType;

typedef std::vector<StopInfoReportTourDataType> StopInfoReportTourDataVectorType;

bool operator < (const StopInfoReportTourDataType &Item1,
                 const StopInfoReportTourDataType &Item2)
 {
  return(Item1.TourStepInTime < Item2.TourStepInTime);
 }

//---------------------------------------------------------------------------
void  StopInfoReportGenerate(AnsiString    StopIdStr,
                             AnsiString    StopNameStr,
                             bool          OutZeroTripStepWaitTimeFlag)
 {
  #if defined(TOUR_DEMO_MODE)
   {
    FunctionArgUsedSkip(StopIdStr);
    FunctionArgUsedSkip(StopNameStr);
    FunctionArgUsedSkip(OutZeroTripStepWaitTimeFlag);

    TourShowDialogInformation(TourMessageModule->VStringStorage->Lines->Strings
                              [TourMessageModuleFuncDemoMessageStr].c_str());
   }
  #else
   {
    TTourStopInfoResultForm      *ResultFormPtr;
    TTourReportPreViewForm       *ReportPreViewFormPtr;
    TCursor                       CurrentCursor;
    AnsiString                    ReportCaption;

    CurrentCursor        = Screen->Cursor;
    ResultFormPtr        = NULL;
    ReportPreViewFormPtr = NULL;

    ResultFormPtr = new TTourStopInfoResultForm(Application,OutZeroTripStepWaitTimeFlag);

    if (ResultFormPtr != NULL)
     {
      ResultFormPtr->ReportQuery->Parameters->ParamByName("StopIdValue")->Value = StopIdStr;

      try
       {
        Screen->Cursor = crSQLWait;

        ResultFormPtr->ReportQuery->Open();

        Screen->Cursor = CurrentCursor;

        Application->CreateForm(__classid(TTourReportPreViewForm),&ReportPreViewFormPtr);

        if (ReportPreViewFormPtr != NULL)
         {
          if (StopNameStr.IsEmpty())
           {
            ReportCaption = ResultFormPtr->Caption + " " + StopIdStr;
           }
          else
           {
            ReportCaption = ResultFormPtr->Caption + " " + StopNameStr;
           }

          ReportPreViewFormPtr->PreviewReport(ResultFormPtr->Report,ReportCaption);
         }
       }
      catch (...)
       {
        Screen->Cursor = CurrentCursor;
        TourShowDialogError("Ошибка выполнения запроса");
       }

      if (ResultFormPtr->ReportQuery->Active)
       {
        ResultFormPtr->ReportQuery->Close();
       }

      delete ResultFormPtr;
     }
   }
  #endif
 }
//---------------------------------------------------------------------------
static bool   StopInfoReportOutReportHeader
              (int                  TargetFileHandle,
               TourStopPtrClass     StopDataPtr)
 {
  bool         ResultFlag;
  std::string  StopIdStr;
  std::string  StopNameStr;
  std::string  WriteStr;

  /************ Функция выводит заглавие отчета в виде *******************
  Остановочный пункт StopIdStr  StopNameStr
  -----------------------------------------------------------
  Номер                Название           Прибы  Отправ Стоян
  рейса                 рейса              тие   ление   ка
  -----------------------------------------------------------
  ************************************************************************/

  ResultFlag = true;

  if (!StopDataPtr.IsNull())
   {
    StopIdStr   = StopDataPtr->IdStr();
    StopNameStr = StopDataPtr->NameStr();

    if (ResultFlag)
     {
      WriteStr  = "\t";
      WriteStr += "Остановочный пункт " + StopIdStr + "  " + StopNameStr;
      WriteStr += "\n";

      if (FileWrite(TargetFileHandle,WriteStr.c_str(),WriteStr.size()) == -1)
       {
        ResultFlag = false;
       }
     }

    if (ResultFlag)
     {
      WriteStr  = "\t";
      WriteStr += "-----------------------------------------------------------";
      WriteStr += "\n";

      if (FileWrite(TargetFileHandle,WriteStr.c_str(),WriteStr.size()) == -1)
       {
        ResultFlag = false;
       }
     }

    if (ResultFlag)
     {
      WriteStr  = "\t";
      WriteStr += "Номер                Название           Прибы  Отправ Стоян";
      WriteStr += "\n";

      if (FileWrite(TargetFileHandle,WriteStr.c_str(),WriteStr.size()) == -1)
       {
        ResultFlag = false;
       }
     }

    if (ResultFlag)
     {
      WriteStr  = "\t";
      WriteStr += "рейса                 рейса              тие   ление   ка";
      WriteStr += "\n";

      if (FileWrite(TargetFileHandle,WriteStr.c_str(),WriteStr.size()) == -1)
       {
        ResultFlag = false;
       }
     }

    if (ResultFlag)
     {
      WriteStr  = "\t";
      WriteStr += "-----------------------------------------------------------";
      WriteStr += "\n";

      if (FileWrite(TargetFileHandle,WriteStr.c_str(),WriteStr.size()) == -1)
       {
        ResultFlag = false;
       }
     }
   }
  else
   {
    ResultFlag = false;
   }

  return(ResultFlag);
 }
//---------------------------------------------------------------------------
static bool   StopInfoReportOutReportTail(int   TargetFileHandle)
 {
  bool         ResultFlag;
  std::string  WriteStr;

  ResultFlag = true;

  if (ResultFlag)
   {
    WriteStr  = "\t";
    WriteStr += "-----------------------------------------------------------";
    WriteStr += "\n";

    if (FileWrite(TargetFileHandle,WriteStr.c_str(),WriteStr.size()) == -1)
     {
      ResultFlag = false;
     }
   }

  return(ResultFlag);
 }
//---------------------------------------------------------------------------
static bool   StopInfoReportOutReportBody
              (int                                 TargetFileHandle,
               StopInfoReportTourDataVectorType   *SourceTourDataVectorPtr)
 {
  StopInfoReportTourDataVectorType::iterator       TourDataVectorIterator;
  bool                                             ResultFlag;
  TourTimeClass                                    TourStepOutTime;
  std::string                                      TourIdStr;
  std::string                                      TourNameStr;
  std::string                                      TourStepInTimeStr;
  std::string                                      TourStepOutTimeStr;
  std::string                                      TourStepWaitTimeStr;
  std::string                                      WriteStr;

  ResultFlag = true;

  if (!SourceTourDataVectorPtr->empty())
   {
    for (TourDataVectorIterator    = SourceTourDataVectorPtr->begin();
         ((TourDataVectorIterator != SourceTourDataVectorPtr->end()) && (ResultFlag));
         TourDataVectorIterator++)
     {
      TourIdStr           = TourDataVectorIterator->TourIdStr;
      TourNameStr         = TourDataVectorIterator->TourNameStr;
      TourStepInTimeStr   = TourDataVectorIterator->TourStepInTime.AsStr();

      if (TourDataVectorIterator->TourStepWaitTime.IsEmpty())
       {
        TourStepWaitTimeStr = "";
        TourStepOutTimeStr  = "";
       }
      else
       {
        TourStepOutTime     = TourDataVectorIterator->TourStepInTime + TourDataVectorIterator->TourStepWaitTime;
        TourStepWaitTimeStr = TourDataVectorIterator->TourStepWaitTime.AsStr();
        TourStepOutTimeStr  = TourStepOutTime.AsStr();
       }

      TourIdStr          .resize(5 ,' ');
      TourNameStr        .resize(31,' ');
      TourStepInTimeStr  .resize(5 ,' ');
      TourStepOutTimeStr .resize(5 ,' ');
      TourStepWaitTimeStr.resize(5 ,' ');

      WriteStr  = "\t";
      WriteStr += TourIdStr          + "  " +
                  TourNameStr        + "  " +
                  TourStepInTimeStr  + "  " +
                  TourStepOutTimeStr + "  " +
                  TourStepWaitTimeStr;
      WriteStr += "\n";

      if (FileWrite(TargetFileHandle,WriteStr.c_str(),WriteStr.size()) == -1)
       {
        ResultFlag = false;
       }
     }
   }

  return(ResultFlag);
 }
//---------------------------------------------------------------------------
static  void  StopInfoReportTourDataPrepare
              (StopInfoReportTourDataVectorType   *TargetTourDataVectorPtr,
               std::string                         SourceStopIdStr,
               TourTourSetPtrClass                 SourceTourSetPtr,
               bool                                OutZeroTripStepWaitTimeFlag)
 {
  StopInfoReportTourDataType                       TourDataVectorItem;
  TourTourPtrClass                                 TourPtr;
  TourTourSchedulePtrClass                         TourSchedulePtr;
  TourStopSchedulePtrClass                         StopSchedulePtr;
  unsigned int                                     TourIndex;
  unsigned int                                     StopIndex;
  bool                                             OutDataFlag;

  TargetTourDataVectorPtr->clear();

  for (TourIndex = 0; TourIndex < SourceTourSetPtr->Count(); TourIndex++)
   {
    TourPtr         = SourceTourSetPtr->Tour(TourIndex);
    TourSchedulePtr = TourPtr->Schedule();

    for (StopIndex = 0; StopIndex < TourSchedulePtr->StopCount(); StopIndex++)
     {
      StopSchedulePtr = TourSchedulePtr->StopSchedule(StopIndex);

      if (StopSchedulePtr->Stop()->IdStr() == SourceStopIdStr)
       {
        OutDataFlag = true;

        if (!OutZeroTripStepWaitTimeFlag)
         {
          if (!StopSchedulePtr->WaitTime().IsEmpty())
           {
            if (StopSchedulePtr->WaitTime().IsZero())
             {
              OutDataFlag = false;
             }
           }
         }

        if (OutDataFlag)
         {
          TourDataVectorItem.TourIdStr        = TourPtr->IdStr();
          TourDataVectorItem.TourNameStr      = TourPtr->NameStr();
          TourDataVectorItem.TourStepInTime   = StopSchedulePtr->InTime();
          TourDataVectorItem.TourStepWaitTime = StopSchedulePtr->WaitTime();

          TargetTourDataVectorPtr->push_back(TourDataVectorItem);
         }
       }
     }
   }

  if (!TargetTourDataVectorPtr->empty())
   {
    std::sort(TargetTourDataVectorPtr->begin(),TargetTourDataVectorPtr->end());
   }
 }
//---------------------------------------------------------------------------
extern  void  StopInfoReportGenerateDemo
              (TourDataPtrClass   TourDataPtr,
               AnsiString         StopIdStr,
               AnsiString         StopNameStr,
               bool               OutZeroTripStepWaitTimeFlag)
 {
  #if defined(TOUR_DEMO_MODE)
   {
    char                               TmpFullFileNameStr[MAXPATH];
    char                               TmpPathStr[MAXPATH];
    int                                FileHandle;
    bool                               ResultFlag;
    TTourReportPreViewForm            *ReportPreViewFormPtr;
    AnsiString                         ReportCaption;
    StopInfoReportTourDataVectorType   TourDataVector;

    StopInfoReportTourDataPrepare(&TourDataVector,
                                   StopIdStr.c_str(),
                                   TourDataPtr->TourSet(),
                                   OutZeroTripStepWaitTimeFlag);

    GetTempPath(sizeof(TmpPathStr),TmpPathStr);            // Get Winnows tmp patch
    strcpy(TmpFullFileNameStr,tempnam(TmpPathStr,"TTmp")); // Create unique tmp file name

    ReportPreViewFormPtr = NULL;
    ResultFlag           = true;
    FileHandle           = FileCreate(TmpFullFileNameStr);

    if (FileHandle == -1)
     {
      ResultFlag = false;
     }
    else
     {
      if (ResultFlag)
       {
        ResultFlag = StopInfoReportOutReportHeader(FileHandle,TourDataPtr->Stop(StopIdStr.c_str()));
       }

      if (ResultFlag)
       {
        ResultFlag = StopInfoReportOutReportBody(FileHandle,&TourDataVector);
       }

      if (ResultFlag)
       {
        ResultFlag = StopInfoReportOutReportTail(FileHandle);
       }

      FileClose(FileHandle);

      if (ResultFlag)
       {
        Application->CreateForm(__classid(TTourReportPreViewForm),&ReportPreViewFormPtr);

        if (ReportPreViewFormPtr == NULL)
         {
          ResultFlag = false;
         }
        else
         {
          ReportCaption = "Станционное расписание по остановочному пункту ";

          if (StopNameStr.IsEmpty())
           {
            ReportCaption += StopIdStr;
           }
          else
           {
            ReportCaption += StopNameStr;
           }

          ReportPreViewFormPtr->Caption = ReportCaption;
          ReportPreViewFormPtr->PreviewExistReport(TmpFullFileNameStr,false);
         }
       }

      DeleteFile(TmpFullFileNameStr);
     }

    if (!ResultFlag)
     {
      TourShowDialogError("Ошибка формирования отчета");
     }
   }
  #else
   {
    FunctionArgUsedSkip(TourDataPtr);
    StopInfoReportGenerate(StopIdStr,StopNameStr,OutZeroTripStepWaitTimeFlag);
   }
  #endif
 }
//---------------------------------------------------------------------------

