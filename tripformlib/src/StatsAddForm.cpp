//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrStats

#include "StatsAddForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "StatsProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma link "StatsProcessForm"
#pragma resource "*.dfm"
TTourStatsAddForm *TourStatsAddForm;
//---------------------------------------------------------------------------
__fastcall TTourStatsAddForm::TTourStatsAddForm(TComponent* Owner)
 : TTourStatsProcessForm(Owner)
{
}
//---------------------------------------------------------------------------

