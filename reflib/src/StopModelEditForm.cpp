//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopModelEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "StopModelProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookStopModelEditForm *TourRefBookStopModelEditForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookStopModelEditForm::TTourRefBookStopModelEditForm(TComponent* Owner)
 : TTourRefBookStopModelProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
