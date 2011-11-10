//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrStats

#include "StatsEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "StatsProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma link "StatsProcessForm"
#pragma resource "*.dfm"
TTourStatsEditForm *TourStatsEditForm;
//---------------------------------------------------------------------------
__fastcall TTourStatsEditForm::TTourStatsEditForm(TComponent* Owner)
 : TTourStatsProcessForm(Owner)
{
}
//---------------------------------------------------------------------------

