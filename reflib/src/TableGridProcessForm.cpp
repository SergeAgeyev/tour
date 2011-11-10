//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TableGridProcessForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookTableGridProcessForm *TourRefBookTableGridProcessForm;
//---------------------------------------------------------------------------
__fastcall TTourRefBookTableGridProcessForm::TTourRefBookTableGridProcessForm(TComponent* Owner)
 : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TTourRefBookTableGridProcessForm::SetMainQueryDataSet(TDataSet* value)
 {
  FMainQueryDataSource->DataSet = value;
 }
