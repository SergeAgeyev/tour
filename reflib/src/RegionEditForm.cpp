//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RegionEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RegionProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookRegionEditForm *TourRefBookRegionEditForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookRegionEditForm::TTourRefBookRegionEditForm(TComponent* Owner)
 : TTourRefBookRegionProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
