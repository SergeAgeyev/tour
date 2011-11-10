//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrTrip

#include "TripEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TripProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma resource "*.dfm"
TTourTripEditForm *TourTripEditForm;
//---------------------------------------------------------------------------
__fastcall TTourTripEditForm::TTourTripEditForm(TComponent* Owner)
 : TTourTripProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
