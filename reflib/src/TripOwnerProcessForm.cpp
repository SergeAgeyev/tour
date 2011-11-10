//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "StdTool.h"
#include "TourTool.h"
#include "TripOwnerProcessForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TableGridProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookTripOwnerProcessForm *TourRefBookTripOwnerProcessForm;

enum TourRefBookTripProcessStringTypes
 {
  TourRefBookTripOwnerIdStr = TourRefBookProcessStringTypesEnumCount
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookTripOwnerProcessForm::TTourRefBookTripOwnerProcessForm(TComponent* Owner)
 : TTourRefBookTableGridProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourRefBookTripOwnerProcessForm::FormCloseQuery(
      TObject *Sender, bool &CanClose)
 {
  Boolean                              ResultFlag;

  ResultFlag = true;
  CanClose = false;
  FunctionArgUsedSkip(Sender);

  if (ModalResult == mrOk)
   {
    if (TripOwnerDBEdit->Text.IsEmpty())
     {
      ResultFlag = false;

      TourShowDialogError
      (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                  + GetTranslatedStr(TourRefBookTripOwnerIdStr)).c_str());

      TripOwnerDBEdit->SetFocus();
     }

    if (ResultFlag)
     {
      CanClose = true;
     }
   }
  else
   {
    CanClose = true;
   }
 }
//---------------------------------------------------------------------------

#undef   GetTranslatedStr(Index)

