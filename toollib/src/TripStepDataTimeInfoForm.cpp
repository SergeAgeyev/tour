//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TripStepDataTimeInfoForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma link "ShortTimePicker"
#pragma resource "*.dfm"
TTourTripStepDataTimeInfoForm *TourTripStepDataTimeInfoForm;

//---------------------------------------------------------------------------
__fastcall TTourTripStepDataTimeInfoForm::TTourTripStepDataTimeInfoForm(TComponent* Owner)
 : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TTourTripStepDataTimeInfoForm::WaitTimeRadioGroupClick(
      TObject *Sender)
 {
  if (WaitTimeRadioGroup->ItemIndex == TourTripStepDataTimeInfoWaitTimeUserWaitCode)
   {
    TimeWaitPicker->Enabled = true;
   }
  else
   {
    TimeWaitPicker->Enabled = false;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripStepDataTimeInfoForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  Action = caHide;
 }
//---------------------------------------------------------------------------

