//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "RegionProcessForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TableGridProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookRegionProcessForm *TourRefBookRegionProcessForm;

enum TourRefBookRegionProcessStringTypes
 {
  TourRefBookRegionIdStr = TourRefBookProcessStringTypesEnumCount
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookRegionProcessForm::TTourRefBookRegionProcessForm(TComponent* Owner)
 : TTourRefBookTableGridProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourRefBookRegionProcessForm::FormCloseQuery(
      TObject *Sender, bool &CanClose)
 {
  Boolean                              ResultFlag;

  ResultFlag = true;
  CanClose = false;
  FunctionArgUsedSkip(Sender);

  if (ModalResult == mrOk)
   {
    if (RegionIdDBEdit->Text.IsEmpty())
     {
      ResultFlag = false;

      TourShowDialogError
      (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                  + GetTranslatedStr(TourRefBookRegionIdStr)).c_str());

      RegionIdDBEdit->SetFocus();
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

