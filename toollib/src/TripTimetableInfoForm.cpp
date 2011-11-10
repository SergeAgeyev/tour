//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TripTimetableInfoForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma link "ShortTimePicker"
#pragma resource "*.dfm"
TTourTripTimetableInfoForm *TourTripTimetableInfoForm;

//---------------------------------------------------------------------------
__fastcall TTourTripTimetableInfoForm::TTourTripTimetableInfoForm(TComponent* Owner)
 : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TTourTripTimetableInfoForm::TimeOutShortTimePickerTimeChange(
      TObject *Sender)
 {
  TDateTime                            WorkTime(0,0,0,0);
  unsigned short                       HourValue;
  unsigned short                       MinValue;
  unsigned short                       SecValue;
  unsigned short                       MSecValue;
  //
  if (TimeOutShortTimePicker->Time >= TimeInShortTimePicker->Time)
   {
    WorkTime = TimeOutShortTimePicker->Time - TimeInShortTimePicker->Time;
   }
  else
   {
    WorkTime  = TimeOutShortTimePicker->Time;

    TimeInShortTimePicker->Time.DecodeTime(&HourValue,&MinValue,&SecValue,&MSecValue);

    HourValue = 23 - HourValue;

    MinValue = 60 - MinValue;

    if (MinValue == 60)
     {
      MinValue = 0;
      HourValue++;
     }

    WorkTime += TDateTime(HourValue,MinValue,SecValue,MSecValue);
   }

  if (TimeWaitShortTimePicker->Time != WorkTime)
   {
    TimeWaitShortTimePicker->Time = WorkTime;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripTimetableInfoForm::TimeWaitShortTimePickerTimeChange(
      TObject *Sender)
 {
  TDateTime                            WorkTime(0,0,0,0);
  //
  WorkTime = TimeWaitShortTimePicker->Time + TimeInShortTimePicker->Time;

  if (TimeOutShortTimePicker->Time != WorkTime)
   {
    TimeOutShortTimePicker->Time = WorkTime;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripTimetableInfoForm::WaitTimeEmptyCheckBoxClick(
      TObject *Sender)
 {
  if (WaitTimeEmptyCheckBox->Checked)
   {
    TimeOutShortTimePicker->Enabled  = true;
    TimeWaitShortTimePicker->Enabled = true;
/*
    TimeInShortTimePicker->OnTimeChange   = TimeInShortTimePickerTimeChange;
    TimeOutShortTimePicker->OnTimeChange  = TimeOutShortTimePickerTimeChange;
    TimeWaitShortTimePicker->OnTimeChange = TimeWaitShortTimePickerTimeChange;
*/
   }
  else
   {
    TimeOutShortTimePicker->Enabled  = false;
    TimeWaitShortTimePicker->Enabled = false;
/*
    TimeInShortTimePicker->OnTimeChange   = NULL;
    TimeOutShortTimePicker->OnTimeChange  = NULL;
    TimeWaitShortTimePicker->OnTimeChange = NULL;

    TimeOutShortTimePicker->Time  = TDateTime(0,0,0,0);
    TimeWaitShortTimePicker->Time = TDateTime(0,0,0,0);
*/    
   }

 }
//---------------------------------------------------------------------------

void __fastcall TTourTripTimetableInfoForm::TimeInShortTimePickerTimeChange(
      TObject *Sender)
 {
  TDateTime                            WorkTime(0,0,0,0);
  //
  if (WaitTimeEmptyCheckBox->Checked)
   {
    WorkTime = TimeWaitShortTimePicker->Time + TimeInShortTimePicker->Time;

    if (TimeOutShortTimePicker->Time != WorkTime)
     {
      TimeOutShortTimePicker->Time = WorkTime;
     }
   }
 }
//---------------------------------------------------------------------------

