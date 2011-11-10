//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TripOwnerSimpleEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TripOwnerSimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourTripOwnerSimpleEditForm *TourTripOwnerSimpleEditForm;
//---------------------------------------------------------------------------
__fastcall TTourTripOwnerSimpleEditForm::TTourTripOwnerSimpleEditForm(TComponent* Owner)
        : TTourTripOwnerSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
