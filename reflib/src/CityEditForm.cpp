//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CityEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CityProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma resource "*.dfm"
TTourRefBookCityEditForm *TourRefBookCityEditForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookCityEditForm::TTourRefBookCityEditForm(TComponent* Owner)
 : TTourRefBookCityProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
