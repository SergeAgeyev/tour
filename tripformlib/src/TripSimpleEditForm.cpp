//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TripSimpleEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TripSimpleProcessForm"
#pragma link "VStringStorage"
#pragma link "RxGrdCpt"
#pragma link "VCustomKeyComboBox"
#pragma link "VMemoKeyComboBox"
#pragma resource "*.dfm"
TTourTripSimpleEditForm *TourTripSimpleEditForm;
//---------------------------------------------------------------------------
__fastcall TTourTripSimpleEditForm::TTourTripSimpleEditForm(TComponent* Owner)
        : TTourTripSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
