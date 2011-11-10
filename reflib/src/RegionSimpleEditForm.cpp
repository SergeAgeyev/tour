//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RegionSimpleEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RegionSimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRegionSimpleEditForm *TourRegionSimpleEditForm;
//---------------------------------------------------------------------------
__fastcall TTourRegionSimpleEditForm::TTourRegionSimpleEditForm(TComponent* Owner)
        : TTourRegionSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
