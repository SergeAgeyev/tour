//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "StopProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma resource "*.dfm"
TTourRefBookStopEditForm *TourRefBookStopEditForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookStopEditForm::TTourRefBookStopEditForm(TComponent* Owner)
 : TTourRefBookStopProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
