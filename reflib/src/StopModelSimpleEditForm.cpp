//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopModelSimpleEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "StopModelSimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourStopModelSimpleEditForm *TourStopModelSimpleEditForm;
//---------------------------------------------------------------------------
__fastcall TTourStopModelSimpleEditForm::TTourStopModelSimpleEditForm(TComponent* Owner)
        : TTourStopModelSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
