//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "StopOwnerProcessForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TableGridProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookStopOwnerProcessForm *TourRefBookStopOwnerProcessForm;

enum TourRefBookStopOwnerProcessStringTypes
 {
  TourRefBookStopOwnerStr = TourRefBookProcessStringTypesEnumCount,
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookStopOwnerProcessForm::TTourRefBookStopOwnerProcessForm(TComponent* Owner)
 : TTourRefBookTableGridProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourRefBookStopOwnerProcessForm::FormCloseQuery(
      TObject *Sender, bool &CanClose)
 {
  Boolean                              ResultFlag;

  ResultFlag = true;
  CanClose = false;
  FunctionArgUsedSkip(Sender);

  if (ModalResult == mrOk)
   {
    if (StopOwnerIdDBEdit->Text.IsEmpty())
     {
      ResultFlag = false;

      TourShowDialogError
      (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                  + GetTranslatedStr(TourRefBookStopOwnerStr)).c_str());

      StopOwnerIdDBEdit->SetFocus();
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

