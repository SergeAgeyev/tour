//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopOwnerSimpleEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "StopOwnerSimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourStopOwnerSimpleEditForm *TourStopOwnerSimpleEditForm;
//---------------------------------------------------------------------------
__fastcall TTourStopOwnerSimpleEditForm::TTourStopOwnerSimpleEditForm(TComponent* Owner)
        : TTourStopOwnerSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
