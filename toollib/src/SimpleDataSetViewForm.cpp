//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SimpleDataSetViewForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SimpleProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourSimpleDataSetViewForm *TourSimpleDataSetViewForm;
//---------------------------------------------------------------------------
__fastcall TTourSimpleDataSetViewForm::TTourSimpleDataSetViewForm(TComponent* Owner)
        : TTourSimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourSimpleDataSetViewForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  Action = caHide;
 }
//---------------------------------------------------------------------------

