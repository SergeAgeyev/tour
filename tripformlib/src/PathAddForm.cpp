//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrPath

#include "PathAddForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "PathProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma link "PathProcessForm"
#pragma resource "*.dfm"
TTourPathAddForm *TourPathAddForm;
//---------------------------------------------------------------------------
__fastcall TTourPathAddForm::TTourPathAddForm(TComponent* Owner)
 : TTourPathProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
