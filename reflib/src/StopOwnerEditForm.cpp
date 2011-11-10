//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StopOwnerEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "StopOwnerProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookStopOwnerEditForm *TourRefBookStopOwnerEditForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookStopOwnerEditForm::TTourRefBookStopOwnerEditForm(TComponent* Owner)
 : TTourRefBookStopOwnerProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
