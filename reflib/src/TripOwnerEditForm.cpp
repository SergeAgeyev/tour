//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TripOwnerEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TripOwnerProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookTripOwnerEditForm *TourRefBookTripOwnerEditForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookTripOwnerEditForm::TTourRefBookTripOwnerEditForm(TComponent* Owner)
 : TTourRefBookTripOwnerProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
