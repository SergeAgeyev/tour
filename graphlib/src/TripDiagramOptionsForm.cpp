//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TripDiagramOptionsForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTourTripDiagramOptionsForm *TourTripDiagramOptionsForm;

#define TourTripDiagramOptionsMinBaseSpeed      (1)
#define TourTripDiagramOptionsMaxBaseSpeed      (120)

#define TourTripDiagramOptionsMinBaseSpeedAngle (1)
#define TourTripDiagramOptionsMaxBaseSpeedAngle (89)

#define TourTripDiagramOptionsMinViewScale      (1)
#define TourTripDiagramOptionsMaxViewScale      (999)


static void TTourTripDiagramOptionsShowErrorMessage(const char *MessageStrPtr)
 {
  TMsgDlgButtons Buttons;

  Buttons << mbOK;

  MessageDlg(MessageStrPtr,mtError,Buttons,0);
 }

//---------------------------------------------------------------------------
__fastcall TTourTripDiagramOptionsForm::TTourTripDiagramOptionsForm(TComponent* Owner)
        : TForm(Owner)
 {
  FViewScale         = 1.0;
  FShowForwardTours  = true;
  FShowBackwardTours = true;
  FShowGrid          = true;
  FMonoColorTourMode = true;
  FGridColor         = 0xFFFFFF;
  FTourCommonColor   = 0xFFFFFF;
  FTourSelectedColor = 0xFFFFFF;
 }
//---------------------------------------------------------------------------
void __fastcall TTourTripDiagramOptionsForm::FormCloseQuery(
      TObject *Sender, bool &CanClose)
 {
  bool                                 ValidFlag;

  ValidFlag = true;

  if (ModalResult == mrOk)
   {
    if (ValidFlag)
     {
      try
       {
        FBaseSpeed = BaseSpeedEdit->Text.ToDouble();

        if ((FBaseSpeed < TourTripDiagramOptionsMinBaseSpeed) ||
            (FBaseSpeed > TourTripDiagramOptionsMaxBaseSpeed))
         {
          ValidFlag = false;

          TTourTripDiagramOptionsShowErrorMessage("Значение базовой скорости выходит за пределы допустимого диапазона");

          BaseSpeedEdit->SetFocus();
         }
       }
      catch (...)
       {
        ValidFlag = false;

        TTourTripDiagramOptionsShowErrorMessage("Неверное значение базовой скорости");

        BaseSpeedEdit->SetFocus();
       }
     }

    if (ValidFlag)
     {
      try
       {
        FBaseSpeedAngle = BaseSpeedAngleEdit->Text.ToInt();

        if ((FBaseSpeedAngle < TourTripDiagramOptionsMinBaseSpeedAngle) ||
            (FBaseSpeedAngle > TourTripDiagramOptionsMaxBaseSpeedAngle))
         {
          ValidFlag = false;

          TTourTripDiagramOptionsShowErrorMessage("Значение базового угла наклона выходит за пределы допустимого диапазона");

          BaseSpeedAngleEdit->SetFocus();
         }
       }
      catch (...)
       {
        ValidFlag = false;

        TTourTripDiagramOptionsShowErrorMessage("Неверное значение базового угла наклона");

        BaseSpeedAngleEdit->SetFocus();
       }
     }

    if (ValidFlag)
     {
      try
       {
        int TempViewScale;

        TempViewScale = ViewScaleComboBox->Text.ToInt();

        if ((TempViewScale < TourTripDiagramOptionsMinViewScale) ||
            (TempViewScale > TourTripDiagramOptionsMaxViewScale))
         {
          ValidFlag = false;

          TTourTripDiagramOptionsShowErrorMessage("Значение масштаба выходит за пределы допустимого диапазона");

          ViewScaleComboBox->SetFocus();
         }
        else
         {
          FViewScale = ((float)TempViewScale) / 100.0;
         }
       }
      catch (...)
       {
        ValidFlag = false;

        TTourTripDiagramOptionsShowErrorMessage("Неверное значение масштаба");

        ViewScaleComboBox->SetFocus();
       }
     }

    if (ValidFlag)
     {
      FShowGrid          = ShowGridCheckBox->Checked;
      FShowForwardTours  = ShowForwardToursCheckBox->Checked;
      FShowBackwardTours = ShowBackwardToursCheckBox->Checked;
      FShowTourInOutRow  = ShowTourInOutRowCheckBox->Checked;
     }
   }

  CanClose = ValidFlag;
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramOptionsForm::SetBaseSpeed(float value)
 {
  if (FBaseSpeed != value)
   {
    FBaseSpeed = value;

    BaseSpeedUpDown->Position = (int)(value);
   }
 }

float __fastcall TTourTripDiagramOptionsForm::GetBaseSpeed()
 {
  return FBaseSpeed;
 }

void __fastcall TTourTripDiagramOptionsForm::SetBaseSpeedAngle(unsigned int value)
 {
  if (FBaseSpeedAngle != value)
   {
    FBaseSpeedAngle = value;

    BaseSpeedAngleUpDown->Position = (int)(value);
   }
 }

unsigned int __fastcall TTourTripDiagramOptionsForm::GetBaseSpeedAngle()
 {
  return FBaseSpeedAngle;
 }

void __fastcall TTourTripDiagramOptionsForm::SetViewScale(float value)
 {
  if (FViewScale != value)
   {
    FViewScale = value;

    ViewScaleComboBox->Text = AnsiString((int)(value * 100));
   }
 }

float __fastcall TTourTripDiagramOptionsForm::GetViewScale()
 {
  return FViewScale;
 }

void __fastcall TTourTripDiagramOptionsForm::SetShowForwardTours(bool value)
 {
  if (FShowForwardTours != value)
   {
    FShowForwardTours                 = value;
    ShowForwardToursCheckBox->Checked = value;
   }
 }

bool __fastcall TTourTripDiagramOptionsForm::GetShowForwardTours()
 {
  return FShowForwardTours;
 }

void __fastcall TTourTripDiagramOptionsForm::SetShowBackwardTours(bool value)
 {
  if (FShowBackwardTours != value)
   {
    FShowBackwardTours                 = value;
    ShowBackwardToursCheckBox->Checked = value;
   }
 }

bool __fastcall TTourTripDiagramOptionsForm::GetShowBackwardTours()
 {
  return FShowBackwardTours;
 }

void __fastcall TTourTripDiagramOptionsForm::SetShowTourInOutRow(bool value)
 {
  FShowTourInOutRow                 = value;
  ShowTourInOutRowCheckBox->Checked = value;
 }

bool __fastcall TTourTripDiagramOptionsForm::GetShowTourInOutRow()
 {
  return FShowTourInOutRow;
 }

void __fastcall TTourTripDiagramOptionsForm::SetShowGrid(bool value)
 {
  if (FShowGrid != value)
   {
    FShowGrid                 = value;
    ShowGridCheckBox->Checked = value;
   }
 }

bool __fastcall TTourTripDiagramOptionsForm::GetShowGrid()
 {
  return FShowGrid;
 }

void __fastcall TTourTripDiagramOptionsForm::SetMonoColorTourMode(bool value)
 {
//  FMonoColorTourMode                 = value;

  if (value != MonoColorTourModeCheckBox->Checked)
   {
    MonoColorTourModeCheckBox->Checked = !value;
   } 
//  TourCommonColorButton->Enabled     = value;
//  TourSelectedColorButton->Enabled   = value;
 }

bool __fastcall TTourTripDiagramOptionsForm::GetMonoColorTourMode()
 {
  return FMonoColorTourMode;
 }

void __fastcall TTourTripDiagramOptionsForm::SetGridColor(unsigned int value)
 {
  FGridColor                   = value;
  GridColorShape->Brush->Color = value;
  GridColorShape->Pen->Color   = value;
 }

unsigned int __fastcall TTourTripDiagramOptionsForm::GetGridColor()
 {
  return FGridColor;
 }

void __fastcall TTourTripDiagramOptionsForm::GridColorButtonClick(
      TObject *Sender)
 {
  SelectColorDialog->Color = FGridColor;

  if (SelectColorDialog->Execute())
   {
    GridColor = SelectColorDialog->Color;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramOptionsForm::SetTourCommonColor(unsigned int value)
 {
  FTourCommonColor                   = value;
  TourCommonColorShape->Brush->Color = value;
  TourCommonColorShape->Pen->Color   = value;
 }

unsigned int __fastcall TTourTripDiagramOptionsForm::GetTourCommonColor()
 {
  return FTourCommonColor;
 }

void __fastcall TTourTripDiagramOptionsForm::SetTourSelectedColor(unsigned int value)
 {
  FTourSelectedColor                   = value;
  TourSelectedColorShape->Brush->Color = value;
  TourSelectedColorShape->Pen->Color   = value;
 }

unsigned int __fastcall TTourTripDiagramOptionsForm::GetTourSelectedColor()
 {
  return FTourSelectedColor;
 }

void __fastcall TTourTripDiagramOptionsForm::TourCommonColorButtonClick(
      TObject *Sender)
 {
  SelectColorDialog->Color = FTourCommonColor;

  if (SelectColorDialog->Execute())
   {
    TourCommonColor = SelectColorDialog->Color;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramOptionsForm::TourSelectedColorButtonClick(
      TObject *Sender)
 {
  SelectColorDialog->Color = FTourSelectedColor;

  if (SelectColorDialog->Execute())
   {
    TourSelectedColor = SelectColorDialog->Color;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripDiagramOptionsForm::MonoColorTourModeCheckBoxClick(
      TObject *Sender)
 {
  FMonoColorTourMode                 = !FMonoColorTourMode;
  TourCommonColorButton->Enabled     = FMonoColorTourMode;
  TourSelectedColorButton->Enabled   = FMonoColorTourMode;
 }
//---------------------------------------------------------------------------

