//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "RepTripInfoResultForm.h"
#include "stdtool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TTourTripInfoResultForm *TourTripInfoResultForm;

static AnsiString   OutDateTimeFormatStr = "hh:nn";

//---------------------------------------------------------------------------
__fastcall TTourTripInfoResultForm::TTourTripInfoResultForm(TComponent* Owner) : TForm(Owner)
 {
  PathLength = 0;
 }
//---------------------------------------------------------------------------
void __fastcall TTourTripInfoResultForm::DetailBandBeforePrint
                (TQRCustomBand *Sender, bool &PrintBand)
 {
  TDateTime    OutDateTime;
  TDateTime    CompareDateTime(0,0,0,0);

  FunctionArgUsedSkip(Sender);

  PrintBand = true;

  if (ReportQuery->FieldByName("tripstep_waittime")->IsNull)
   {
    TripStepOutTimeLabel->Caption  = "";
    TripStepWaitTimeLabel->Caption = "";

    OutDateTime = ReportQuery->FieldByName("tripstep_intime")->AsDateTime;
    TripStepInTimeLabel->Caption = OutDateTime.FormatString(OutDateTimeFormatStr);
   }
  else
   {
    OutDateTime = ReportQuery->FieldByName("tripstep_waittime")->AsDateTime;

    if (OutDateTime.TimeString() == CompareDateTime.TimeString())
     {
      // начальный остановочный пункт
      TripStepInTimeLabel->Caption   = "";
      TripStepWaitTimeLabel->Caption = "";

      OutDateTime = ReportQuery->FieldByName("tripstep_intime")->AsDateTime;
      TripStepOutTimeLabel->Caption = OutDateTime.FormatString(OutDateTimeFormatStr);
     }
    else
     {
      // промежуточный остановочный пункт
      OutDateTime = ReportQuery->FieldByName("tripstep_intime")->AsDateTime;
      TripStepInTimeLabel->Caption = OutDateTime.FormatString(OutDateTimeFormatStr);

      OutDateTime = ReportQuery->FieldByName("tripstep_waittime")->AsDateTime;
      TripStepWaitTimeLabel->Caption = OutDateTime.FormatString(OutDateTimeFormatStr);

      OutDateTime = ReportQuery->FieldByName("tripstep_intime")->AsDateTime
                  + ReportQuery->FieldByName("tripstep_waittime")->AsDateTime;

      TripStepOutTimeLabel->Caption = OutDateTime.FormatString(OutDateTimeFormatStr);
     }
   }

  PathLengthLabel->Caption = IntToStr(PathLength);
 }
//---------------------------------------------------------------------------
void __fastcall TTourTripInfoResultForm::DetailBandAfterPrint
                (TQRCustomBand *Sender, bool BandPrinted)
 {
  FunctionArgUsedSkip(Sender);
  FunctionArgUsedSkip(BandPrinted);

  PathLength += ReportQuery->FieldByName("path_length")->AsInteger;
 }
//---------------------------------------------------------------------------


