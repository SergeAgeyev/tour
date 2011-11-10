//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopAddForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "StopProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma resource "*.dfm"
TTourRefBookStopAddForm *TourRefBookStopAddForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookStopAddForm::TTourRefBookStopAddForm(TComponent* Owner)
 : TTourRefBookStopProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
