//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SimpleProcessForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourSimpleProcessForm *TourSimpleProcessForm;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]
//---------------------------------------------------------------------------
__fastcall TTourSimpleProcessForm::TTourSimpleProcessForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourSimpleProcessForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  Action = caHide;
 }
//---------------------------------------------------------------------------

