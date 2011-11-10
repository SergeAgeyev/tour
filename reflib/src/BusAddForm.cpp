//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BusAddForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BusProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookBusAddForm *TourRefBookBusAddForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookBusAddForm::TTourRefBookBusAddForm(TComponent* Owner)
 : TTourRefBookBusProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
