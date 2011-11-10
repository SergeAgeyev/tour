//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrPath

#include "PathEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "PathProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma link "PathProcessForm"
#pragma resource "*.dfm"
TTourPathEditForm *TourPathEditForm;
//---------------------------------------------------------------------------
__fastcall TTourPathEditForm::TTourPathEditForm(TComponent* Owner)
 : TTourPathProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
