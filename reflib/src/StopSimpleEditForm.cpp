//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopSimpleEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "StopSimpleProcessForm"
#pragma link "VStringStorage"
#pragma link "RxGrdCpt"
#pragma link "VCustomKeyComboBox"
#pragma link "VMemoKeyComboBox"
#pragma resource "*.dfm"
TTourStopSimpleEditForm *TourStopSimpleEditForm;
//---------------------------------------------------------------------------
__fastcall TTourStopSimpleEditForm::TTourStopSimpleEditForm(TComponent* Owner)
        : TTourStopSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
