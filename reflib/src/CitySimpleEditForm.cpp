//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CitySimpleEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CitySimpleProcessForm"
#pragma link "VStringStorage"
#pragma link "RxGrdCpt"
#pragma link "VCustomKeyComboBox"
#pragma link "VMemoKeyComboBox"
#pragma resource "*.dfm"
TTourCitySimpleEditForm *TourCitySimpleEditForm;
//---------------------------------------------------------------------------
__fastcall TTourCitySimpleEditForm::TTourCitySimpleEditForm(TComponent* Owner)
        : TTourCitySimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
