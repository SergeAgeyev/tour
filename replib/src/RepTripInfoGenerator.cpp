//---------------------------------------------------------------------------
#include <stdio.h>
#include <io.h>

#include <vector>

#include <vcl.h>
#pragma hdrstop

#include "RepTripInfoGenerator.h"
#include "RepPreViewForm.h"
#include "TourTool.h"
#include "StdTool.h"
#include "MessageModuleForm.h"

#if !defined(TOUR_DEMO_MODE)
 #include "RepTripInfoResultForm.h"
#endif

#pragma package(smart_init)

typedef struct
 {
  std::string      StopNameStr;
  TourTimeClass    TourStepInTime;
  TourTimeClass    TourStepWaitTime;
  float            StopPath;
 } TripInfoReportStopDataType;

typedef std::vector<TripInfoReportStopDataType> TripInfoReportStopDataVectorType;

//---------------------------------------------------------------------------
void        TripInfoReportGenerate(AnsiString   TripIdStr,
                                   AnsiString   TripNameStr)
 {
  #if defined(TOUR_DEMO_MODE)
   {
    FunctionArgUsedSkip(TripIdStr);
    FunctionArgUsedSkip(TripNameStr);

    TourShowDialogInformation(TourMessageModule->VStringStorage->Lines->Strings
                              [TourMessageModuleFuncDemoMessageStr].c_str());
   }
  #else
   {
    TTourTripInfoResultForm      *ResultFormPtr;
    TTourReportPreViewForm       *ReportPreViewFormPtr;
    TCursor                       CurrentCursor;
    AnsiString                    ReportCaption;

    CurrentCursor        = Screen->Cursor;
    ResultFormPtr        = NULL;
    ReportPreViewFormPtr = NULL;

    ResultFormPtr = new TTourTripInfoResultForm(Application);

    if (ResultFormPtr != NULL)
     {
      ResultFormPtr->ReportQuery->Parameters->ParamByName("TripIdValue")->Value    = TripIdStr;
      ResultFormPtr->ReportQuery->Parameters->ParamByName("TripIdAddValue")->Value = TripIdStr;

      try
       {
        Screen->Cursor = crSQLWait;

        ResultFormPtr->ReportQuery->Open();

        Screen->Cursor = CurrentCursor;

        Application->CreateForm(__classid(TTourReportPreViewForm),&ReportPreViewFormPtr);

        if (ReportPreViewFormPtr != NULL)
         {
          if (TripNameStr.IsEmpty())
           {
            ReportCaption = ResultFormPtr->Caption + " " + TripIdStr;
           }
          else
           {
            ReportCaption = ResultFormPtr->Caption + " " + TripNameStr;
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
static bool   TripInfoReportOutReportHeader
              (int                  TargetFileHandle,
               TourTourPtrClass     TourDataPtr)
 {
  bool         ResultFlag;
  std::string  TourIdStr;
  std::string  TourNameStr;
  std::string  BusModelStr;
  std::string  WriteStr;

  /************ Функция выводит заглавие отчета в виде *******************
  Номер рейса Trip_Id Trip_Name
  Автобус Bus_Model
  -------------------------------------------------
      Остановочный     Прибы  Отправ  Стоян Расстоя
          пункт         тие   ление    ка     ние
  -------------------------------------------------
  ************************************************************************/

  ResultFlag = true;

  if (!TourDataPtr.IsNull())
   {
    TourIdStr   = TourDataPtr->IdStr();
    TourNameStr = TourDataPtr->NameStr();
    BusModelStr = TourDataPtr->Bus()->ModelStr();

    if (ResultFlag)
     {
      WriteStr  = "\t";
      WriteStr += "Номер рейса " + TourIdStr + " " + TourNameStr;
      WriteStr += "\n";

      if (FileWrite(TargetFileHandle,WriteStr.c_str(),WriteStr.size()) == -1)
       {
        ResultFlag = false;
       }
     }

    if (ResultFlag)
     {
      WriteStr  = "\t";
      WriteStr += "Автобус " + BusModelStr;
      WriteStr += "\n";

      if (FileWrite(TargetFileHandle,WriteStr.c_str(),WriteStr.size()) == -1)
       {
        ResultFlag = false;
       }
     }

    if (ResultFlag)
     {
      WriteStr  = "\t";
      WriteStr += "-------------------------------------------------";
      WriteStr += "\n";

      if (FileWrite(TargetFileHandle,WriteStr.c_str(),WriteStr.size()) == -1)
       {
        ResultFlag = false;
       }
     }

    if (ResultFlag)
     {
      WriteStr  = "\t";
      WriteStr += "    Остановочный     Прибы  Отправ Стоян  Расстоя";
      WriteStr += "\n";

      if (FileWrite(TargetFileHandle,WriteStr.c_str(),WriteStr.size()) == -1)
       {
        ResultFlag = false;
       }
     }

    if (ResultFlag)
     {
      WriteStr  = "\t";
      WriteStr += "        пункт         тие   ление   ка      ние";
      WriteStr += "\n";

      if (FileWrite(TargetFileHandle,WriteStr.c_str(),WriteStr.size()) == -1)
       {
        ResultFlag = false;
       }
     }

    if (ResultFlag)
     {
      WriteStr  = "\t";
      WriteStr += "-------------------------------------------------";
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
static bool   TripInfoReportOutReportTail(int   TargetFileHandle)
 {
  bool         ResultFlag;
  std::string  WriteStr;

  ResultFlag = true;

  if (ResultFlag)
   {
    WriteStr  = "\t";
    WriteStr += "-------------------------------------------------";
    WriteStr += "\n";

    if (FileWrite(TargetFileHandle,WriteStr.c_str(),WriteStr.size()) == -1)
     {
      ResultFlag = false;
     }
   }

  return(ResultFlag);
 }
//---------------------------------------------------------------------------
static bool   TripInfoReportOutReportBody
              (int                                 TargetFileHandle,
               TripInfoReportStopDataVectorType   *SourceStopDataVectorPtr)
 {
  TripInfoReportStopDataVectorType::iterator       StopDataVectorIterator;
  bool                                             ResultFlag;
  TourTimeClass                                    TourStepOutTime;
  std::string                                      StopNameStr;
  std::string                                      TourStepInTimeStr;
  std::string                                      TourStepOutTimeStr;
  std::string                                      TourStepWaitTimeStr;
  AnsiString                                       StopPathStr;
  std::string                                      WriteStr;

  ResultFlag = true;

  if (!SourceStopDataVectorPtr->empty())
   {
    for (StopDataVectorIterator    = SourceStopDataVectorPtr->begin();
         ((StopDataVectorIterator != SourceStopDataVectorPtr->end()) && (ResultFlag));
         StopDataVectorIterator++)
     {
      StopNameStr = StopDataVectorIterator->StopNameStr;
      StopPathStr = FloatToStr(StopDataVectorIterator->StopPath);

      if (StopDataVectorIterator->TourStepWaitTime.IsEmpty())
       {
        TourStepInTimeStr   = StopDataVectorIterator->TourStepInTime.AsStr();
        TourStepOutTimeStr  = "";
        TourStepWaitTimeStr = "";
       }
      else
       {
        if (StopDataVectorIterator->TourStepWaitTime.IsZero())
         {
          // начальный остановочный пункт
          TourStepInTimeStr   = "";
          TourStepOutTimeStr  = StopDataVectorIterator->TourStepInTime.AsStr();
          TourStepWaitTimeStr = "";
         }
        else
         {
          // промежуточный остановочный пункт
          TourStepOutTime     = StopDataVectorIterator->TourStepInTime
                              + StopDataVectorIterator->TourStepWaitTime;

          TourStepInTimeStr   = StopDataVectorIterator->TourStepInTime.AsStr();
          TourStepWaitTimeStr = StopDataVectorIterator->TourStepWaitTime.AsStr();
          TourStepOutTimeStr  = TourStepOutTime.AsStr();
         }
       }

      StopNameStr        .resize(19,' ');
      TourStepInTimeStr  .resize(5 ,' ');
      TourStepOutTimeStr .resize(5 ,' ');
      TourStepWaitTimeStr.resize(5 ,' ');

      while (StopPathStr.Length() < 7)
       {
        StopPathStr = StopPathStr.Insert(" ",1);
       }

      WriteStr  = "\t";
      WriteStr += StopNameStr         + "  " +
                  TourStepInTimeStr   + "  " +
                  TourStepOutTimeStr  + "  " +
                  TourStepWaitTimeStr + "  " +
                  StopPathStr.c_str();
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
static  void  TripInfoReportTourDataPrepare
              (TripInfoReportStopDataVectorType   *TargetStopDataVectorPtr,
               TourTourPtrClass                    SourceTourPtr,
               TourTopologyPtrClass                TopologyPtr)
 {
  TripInfoReportStopDataType                       StopDataVectorItem;
  TourTourSchedulePtrClass                         TourSchedulePtr;
  TourStopSchedulePtrClass                         StopSchedulePtr;
  std::string                                      FromStopIdStr;
  std::string                                      ToStopIdStr;
  float                                            CurrentStopPath;
  float                                            StopPath;
  unsigned int                                     StopIndex;

  TargetStopDataVectorPtr->clear();

  if (!SourceTourPtr.IsNull())
   {
    TourSchedulePtr = SourceTourPtr->Schedule();
    FromStopIdStr   = "";
    CurrentStopPath = 0;

    for (StopIndex = 0; StopIndex < TourSchedulePtr->StopCount(); StopIndex++)
     {
      StopSchedulePtr = TourSchedulePtr->StopSchedule(StopIndex);
      ToStopIdStr     = StopSchedulePtr->Stop()->IdStr();
      StopPath        = 0;

      if (TopologyPtr->DirectLinkExists(FromStopIdStr,ToStopIdStr))
       {
        StopPath = TopologyPtr->DirectLinkDistance(FromStopIdStr,ToStopIdStr);
       }

      CurrentStopPath += StopPath;
      FromStopIdStr    = ToStopIdStr;

      StopDataVectorItem.StopNameStr      = StopSchedulePtr->Stop()->NameStr();
      StopDataVectorItem.TourStepInTime   = StopSchedulePtr->InTime();
      StopDataVectorItem.TourStepWaitTime = StopSchedulePtr->WaitTime();
      StopDataVectorItem.StopPath         = CurrentStopPath;

      TargetStopDataVectorPtr->push_back(StopDataVectorItem);
     }
   }
 }
//---------------------------------------------------------------------------
extern  void  TripInfoReportGenerateDemo
              (TourDataPtrClass   TourDataPtr,
               AnsiString         TripIdStr,
               AnsiString         TripNameStr)
 {
  #if defined(TOUR_DEMO_MODE)
   {
    char                               TmpFullFileNameStr[MAXPATH];
    char                               TmpPathStr[MAXPATH];
    int                                FileHandle;
    bool                               ResultFlag;
    TTourReportPreViewForm            *ReportPreViewFormPtr;
    AnsiString                         ReportCaption;
    TripInfoReportStopDataVectorType   StopDataVector;

    TripInfoReportTourDataPrepare(&StopDataVector,
                                   TourDataPtr->Tour(TripIdStr.c_str()),
                                   TourDataPtr->Topology());

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
        ResultFlag = TripInfoReportOutReportHeader(FileHandle,TourDataPtr->Tour(TripIdStr.c_str()));
       }

      if (ResultFlag)
       {
        ResultFlag = TripInfoReportOutReportBody(FileHandle,&StopDataVector);
       }

      if (ResultFlag)
       {
        ResultFlag = TripInfoReportOutReportTail(FileHandle);
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
          ReportCaption = "Информация по рейсу ";

          if (TripNameStr.IsEmpty())
           {
            ReportCaption += TripIdStr;
           }
          else
           {
            ReportCaption += TripNameStr;
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
    TripInfoReportGenerate(TripIdStr,TripNameStr);
   }
  #endif
 }
//---------------------------------------------------------------------------

