//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "SessionDateForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTourSessionDateForm *TourSessionDateForm = NULL;

//---------------------------------------------------------------------------
__fastcall TTourSessionDateForm::TTourSessionDateForm(TComponent* Owner)
 : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TTourSessionDateForm::TimerTimer(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);
  DateLabel->Caption = Date().FormatString("dd' 'mmmm' 'yyyy (dddd)");
 }
//---------------------------------------------------------------------------

void __fastcall TTourSessionDateForm::FormCloseQuery(TObject *Sender,
      bool &CanClose)
 {
  FunctionArgUsedSkip(Sender);
  Timer->Enabled = false;
 }
//---------------------------------------------------------------------------

void __fastcall TTourSessionDateForm::FormShow(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);
  DateLabel->Caption = Date().FormatString("dd' 'mmmm' 'yyyy (dddd)");
  Timer->Enabled = true;
 }
//---------------------------------------------------------------------------

void __fastcall TTourSessionDateForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  Action = caFree;
  TourSessionDateForm = NULL;
 }
//---------------------------------------------------------------------------

