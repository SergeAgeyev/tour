//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PathSimpleEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "PathSimpleProcessForm"
#pragma link "VStringStorage"
#pragma link "RxGrdCpt"
#pragma link "VCustomKeyComboBox"
#pragma link "VMemoKeyComboBox"
#pragma resource "*.dfm"
TTourPathSimpleEditForm *TourPathSimpleEditForm;
//---------------------------------------------------------------------------
__fastcall TTourPathSimpleEditForm::TTourPathSimpleEditForm(TComponent* Owner)
        : TTourPathSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
