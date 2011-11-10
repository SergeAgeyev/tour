//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BusSimpleEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BusSimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourBusSimpleEditForm *TourBusSimpleEditForm;
//---------------------------------------------------------------------------
__fastcall TTourBusSimpleEditForm::TTourBusSimpleEditForm(TComponent* Owner)
        : TTourBusSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
