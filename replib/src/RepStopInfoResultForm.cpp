//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "RepStopInfoResultForm.h"
#include "stdtool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTourStopInfoResultForm *TourStopInfoResultForm;

static AnsiString   OutDateTimeFormatStr = "hh:nn";

//---------------------------------------------------------------------------
__fastcall TTourStopInfoResultForm::TTourStopInfoResultForm
           (TComponent* Owner, bool OutZeroTripStepWaitTimeFlag) : TForm(Owner)
 {
  this->OutZeroTripStepWaitTimeFlag = OutZeroTripStepWaitTimeFlag;
 }
//---------------------------------------------------------------------------
void __fastcall TTourStopInfoResultForm::DetailBandBeforePrint
                (TQRCustomBand          *Sender,
                  bool                  &PrintBand)
 {
  TDateTime    OutDateTime;
  TDateTime    CompareDateTime(0,0,0,0);

  FunctionArgUsedSkip(Sender);

  PrintBand = true;

  if (!OutZeroTripStepWaitTimeFlag)
   {
    if (!ReportQuery->FieldByName("tripstep_waittime")->IsNull)
     {
      OutDateTime = ReportQuery->FieldByName("tripstep_waittime")->AsDateTime;

      if (OutDateTime.TimeString() == CompareDateTime.TimeString())
       {
        PrintBand = false;
       }
     }
   }

  if (PrintBand)
   {
    OutDateTime = ReportQuery->FieldByName("tripstep_intime")->AsDateTime;
    TripStepInTimeLabel->Caption = OutDateTime.FormatString(OutDateTimeFormatStr);

    if (ReportQuery->FieldByName("tripstep_waittime")->IsNull)
     {
      TripStepOutTimeLabel->Caption  = "";
      TripStepWaitTimeLabel->Caption = "";
     }
    else
     {
      OutDateTime = ReportQuery->FieldByName("tripstep_waittime")->AsDateTime;
      TripStepWaitTimeLabel->Caption = OutDateTime.FormatString(OutDateTimeFormatStr);

      OutDateTime = ReportQuery->FieldByName("tripstep_intime")->AsDateTime
                  + ReportQuery->FieldByName("tripstep_waittime")->AsDateTime;

      TripStepOutTimeLabel->Caption = OutDateTime.FormatString(OutDateTimeFormatStr);
     }
   }
 }
//---------------------------------------------------------------------------

