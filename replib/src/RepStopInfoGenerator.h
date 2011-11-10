//---------------------------------------------------------------------------
#ifndef RepStopInfoGeneratorH
#define RepStopInfoGeneratorH

#include <TourData.h>

//---------------------------------------------------------------------------
extern  void  StopInfoReportGenerate
              (AnsiString    StopIdStr,
               AnsiString    StopNameStr                 = "",
               bool          OutZeroTripStepWaitTimeFlag = false);

extern  void  StopInfoReportGenerateDemo
              (TourDataPtrClass   TourDataPtr,
               AnsiString         StopIdStr,
               AnsiString         StopNameStr                 = "",
               bool               OutZeroTripStepWaitTimeFlag = false);
//---------------------------------------------------------------------------
#endif
