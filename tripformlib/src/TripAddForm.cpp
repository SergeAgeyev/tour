//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrTrip

#include "TripAddForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TripProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma resource "*.dfm"
TTourTripAddForm *TourTripAddForm;
//---------------------------------------------------------------------------
__fastcall TTourTripAddForm::TTourTripAddForm(TComponent* Owner)
 : TTourTripProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
