//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TripTourCopyDialogForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourTripTourCopyDialogForm *TourTripTourCopyDialogForm;

//---------------------------------------------------------------------------
__fastcall TTourTripTourCopyDialogForm::TTourTripTourCopyDialogForm(TComponent* Owner)
 : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TTourTripTourCopyDialogForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  Action = caHide;
 }
//---------------------------------------------------------------------------

