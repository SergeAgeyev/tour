//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TripTourMoveDialogForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma link "ShortTimePicker"
#pragma resource "*.dfm"
TTourTripTourMoveDialogForm *TourTripTourMoveDialogForm;

//---------------------------------------------------------------------------
__fastcall TTourTripTourMoveDialogForm::TTourTripTourMoveDialogForm(TComponent* Owner)
 : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TTourTripTourMoveDialogForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  Action = caHide;
 }
//---------------------------------------------------------------------------

