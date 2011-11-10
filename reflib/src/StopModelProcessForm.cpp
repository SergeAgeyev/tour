//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "StopModelProcessForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TableGridProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookStopModelProcessForm *TourRefBookStopModelProcessForm;

enum TourRefBookStopModelProcessStringTypes
 {
  TourRefBookStopModelStr = TourRefBookProcessStringTypesEnumCount,
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookStopModelProcessForm::TTourRefBookStopModelProcessForm(TComponent* Owner)
 : TTourRefBookTableGridProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourRefBookStopModelProcessForm::FormCloseQuery(
      TObject *Sender, bool &CanClose)
 {
  Boolean                              ResultFlag;

  ResultFlag = true;
  CanClose = false;
  FunctionArgUsedSkip(Sender);

  if (ModalResult == mrOk)
   {
    if (StopModelDBEdit->Text.IsEmpty())
     {
      ResultFlag = false;

      TourShowDialogError
      (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                  + GetTranslatedStr(TourRefBookStopModelStr)).c_str());

      StopModelDBEdit->SetFocus();
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

