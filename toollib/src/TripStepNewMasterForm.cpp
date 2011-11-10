//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <math.h>

#include "FieldDef.h"
#include "TourTool.h"
#include "TourConst.h"
#include "TripStepNewMasterForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TripStepWizardForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma resource "*.dfm"
TTourTripStepNewMasterForm *TourTripStepNewMasterForm;

enum TourTripStepNewMasterStringTypes
 {
  TourTripStepNewMasterInputFieldMessageStr  = TourTripStepWizardStringTypesEnumCount,
  TourTripStepNewMasterTripIdStr,
  TourTripStepNewMasterTripIdExistMessageStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]
#define  TripStepWizardMinutesInHour   60

//---------------------------------------------------------------------------
__fastcall TTourTripStepNewMasterForm::TTourTripStepNewMasterForm(TComponent* Owner)
 : TTourTripStepWizardForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourTripStepNewMasterForm::NextButtonClick(
      TObject *Sender)
 {
  if (!TripIdDBEdit->Text.IsEmpty())
   {
    if (TourCheckTripExist(QuotedStr(TripIdDBEdit->Text)))
     {
      TourShowDialogError
      (GetTranslatedStr(TourTripStepNewMasterTripIdExistMessageStr).c_str());

      TripIdDBEdit->SetFocus();
      TripIdDBEdit->SelectAll();
     }
    else
     {
      ModalResult = mrOk;
     }
   }
  else
   {
    TourShowDialogError
    (AnsiString
     (GetTranslatedStr(TourTripStepNewMasterInputFieldMessageStr) +
      GetTranslatedStr(TourTripStepNewMasterTripIdStr)).c_str());

    TripIdDBEdit->SetFocus();
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripStepNewMasterForm::FormDestroy(TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    if (ExistTripQuery->Active)
     {
      ExistTripQuery->Close();
     }
    if (TripOwnerQuery->Active)
     {
      TripOwnerQuery->Close();
     }
    if (BusQuery->Active)
     {
      BusQuery->Close();
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();

  TTourTripStepWizardForm::FormDestroy(Sender);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripStepNewMasterForm::FormCreate(TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    ExistTripQuery->Open();
    TripOwnerQuery->Open();
    BusQuery->Open();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();
 }
//---------------------------------------------------------------------------

TDateTime          TTourTripStepNewMasterForm::GetPreliminaryTimeIn
                   (AnsiString                        FromStopIdStr,
                    AnsiString                        ToStopIdStr)
 {
  TDateTime                            ResultTime;
  unsigned short                       HourValue;
  unsigned short                       MinValue;
  unsigned short                       SecValue;
  unsigned short                       MSecValue;
  float                                NormSpeedValue;
  float                                SpeedFactorValue;
  float                                HourFloatValue;

  HourValue = 0;
  MinValue  = 0;
  SecValue  = 0;
  MSecValue = 0;
  NormSpeedValue   = TourPathNormSpeedDefaultValue;
  SpeedFactorValue = TourBusSpeedFactorDefaultValue;

  try
   {
    if (TimeInInfoQuery->Active)
     {
      TimeInInfoQuery->Close();
     }

    TimeInInfoQuery->Parameters->ParamByName("from_stopid_value")->Value
    = FromStopIdStr;
    TimeInInfoQuery->Parameters->ParamByName("to_stopid_value")->Value
    = ToStopIdStr;

    TimeInInfoQuery->Open();

    if (!TimeInInfoQuery->IsEmpty())
     {
      if (!TimeInInfoQuery->FieldByName(PathNormSpeedFieldNameStr)->IsNull)
       {
        NormSpeedValue
        = TimeInInfoQuery->FieldByName(PathNormSpeedFieldNameStr)->AsFloat;
       }
      if (!BusModelDBLookupComboBoxExt->Field->IsNull)
       {
        if (!BusQuery->FieldByName(BusSpeedFactorFieldNameStr)->IsNull)
         {
          SpeedFactorValue
          = BusQuery->FieldByName(BusSpeedFactorFieldNameStr)->AsFloat;
         }
       }

      HourFloatValue
      = TimeInInfoQuery->FieldByName(PathLengthFieldNameStr)->AsFloat /
        (NormSpeedValue * SpeedFactorValue);
      HourValue = HourFloatValue;
      MinValue = ceil((HourFloatValue - HourValue) * TripStepWizardMinutesInHour);

      ResultTime = TDateTime(HourValue,MinValue,SecValue,MSecValue);

      TimeInInfoQuery->Close();
     }
    else
     {
      TimeInInfoQuery->Close();
      throw Exception("TimeInInfoQuery record set is empty");
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  return (ResultTime);
 }

//---------------------------------------------------------------------------

#undef  GetTranslatedStr(Index)





