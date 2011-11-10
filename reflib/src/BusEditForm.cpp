//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BusEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BusProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookBusEditForm *TourRefBookBusEditForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookBusEditForm::TTourRefBookBusEditForm(TComponent* Owner)
 : TTourRefBookBusProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
