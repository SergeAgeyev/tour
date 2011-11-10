//---------------------------------------------------------------------------
#ifndef RepTripInfoGeneratorH
#define RepTripInfoGeneratorH

#include <TourData.h>
//---------------------------------------------------------------------------
extern  void  TripInfoReportGenerate
              (AnsiString         TripIdStr,
               AnsiString         TripNameStr = "");

extern  void  TripInfoReportGenerateDemo
              (TourDataPtrClass   TourDataPtr,
               AnsiString         TripIdStr,
               AnsiString         TripNameStr = "");
//---------------------------------------------------------------------------
#endif
