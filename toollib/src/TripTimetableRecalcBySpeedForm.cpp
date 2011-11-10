//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "TourConst.h"
#include "TripTimetableRecalcBySpeedForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma resource "*.dfm"

TTourTripTimetableRateSpeedForm *TourTripTimetableRateSpeedForm;

enum TourTripTimeTableStringTypes
 {
  TourTripTimetableRateSpeedEmptyMessageStr = 0,
  TourTripTimetableRateSpeedInvalidMessageStr,
  TourTripTimetableRateSpeedTooSmallMessageStr,
  TourTripTimetableRateSpeedTooBigMessageStr,
  TourTripTimetableRateSpeedStringTypesEnumCount
 };

#define  GetTranslatedStr(Index)  VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourTripTimetableRateSpeedForm::TTourTripTimetableRateSpeedForm(TComponent* Owner)
 : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TTourTripTimetableRateSpeedForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  Action = caHide;
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripTimetableRateSpeedForm::FormCloseQuery(
      TObject *Sender, bool &CanClose)
 {
  float                                FloatValue;

  FloatValue = 0;
  CanClose   = true;

  if (ModalResult == mrOk)
   {
    try
     {
      if (!RateSpeedComboBox->Text.IsEmpty())
       {
        FloatValue = StrToFloat(RateSpeedComboBox->Text);

        if (FloatValue < TourPathMinSpeedValue)
         {
          TourShowDialogError
          (AnsiString(GetTranslatedStr(TourTripTimetableRateSpeedTooSmallMessageStr) +
                      FloatToStr(TourPathMinSpeedValue)).c_str());
          CanClose = false;
         }
        else if (FloatValue > TourPathMaxSpeedValue)
         {
          TourShowDialogError
          (AnsiString(GetTranslatedStr(TourTripTimetableRateSpeedTooBigMessageStr) +
                      FloatToStr(TourPathMaxSpeedValue)).c_str());
          CanClose = false;
         }
       }
      else
       {
        TourShowDialogError
        (GetTranslatedStr(TourTripTimetableRateSpeedEmptyMessageStr).c_str());
        CanClose = false;
       }
     }
    catch (...)
     {
      TourShowDialogError
      (GetTranslatedStr(TourTripTimetableRateSpeedInvalidMessageStr).c_str());
      CanClose = false;
     }

    if (!CanClose)
     {
      RateSpeedComboBox->SetFocus();
     }
   }
 }
//---------------------------------------------------------------------------

