//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RegionAddForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RegionProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookRegionAddForm *TourRefBookRegionAddForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookRegionAddForm::TTourRefBookRegionAddForm(TComponent* Owner)
 : TTourRefBookRegionProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
