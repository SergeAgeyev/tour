//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopOwnerAddForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "StopOwnerProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookStopOwnerAddForm *TourRefBookStopOwnerAddForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookStopOwnerAddForm::TTourRefBookStopOwnerAddForm(TComponent* Owner)
 : TTourRefBookStopOwnerProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
