//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CityAddForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CityProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma resource "*.dfm"
TTourRefBookCityAddForm *TourRefBookCityAddForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookCityAddForm::TTourRefBookCityAddForm(TComponent* Owner)
 : TTourRefBookCityProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
