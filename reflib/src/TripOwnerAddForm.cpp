//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TripOwnerAddForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TripOwnerProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookTripOwnerAddForm *TourRefBookTripOwnerAddForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookTripOwnerAddForm::TTourRefBookTripOwnerAddForm(TComponent* Owner)
 : TTourRefBookTripOwnerProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
