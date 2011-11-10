//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "SessionTimeForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTourSessionTimeForm *TourSessionTimeForm = NULL;

//---------------------------------------------------------------------------
__fastcall TTourSessionTimeForm::TTourSessionTimeForm(TComponent* Owner)
 : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TTourSessionTimeForm::TimerTimer(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);
  TimeLabel->Caption = Time().FormatString("hh':'nn':'ss");
 }
//---------------------------------------------------------------------------

void __fastcall TTourSessionTimeForm::FormCloseQuery(TObject *Sender,
      bool &CanClose)
 {
  FunctionArgUsedSkip(Sender);
  Timer->Enabled = false;
 }
//---------------------------------------------------------------------------

void __fastcall TTourSessionTimeForm::FormShow(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);
  TimeLabel->Caption = Time().FormatString("hh':'nn':'ss");
  Timer->Enabled = true;
 }
//---------------------------------------------------------------------------

void __fastcall TTourSessionTimeForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  Action = caFree;
  TourSessionTimeForm = NULL;
 }
//---------------------------------------------------------------------------

