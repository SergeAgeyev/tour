//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrTrip

#include "StdTool.h"
#include "TourTool.h"
#include "TripProcessForm.h"
#include "DataSetViewForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TableGridProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma resource "*.dfm"
TTourTripProcessForm *TourTripProcessForm;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourTripProcessForm::TTourTripProcessForm(TComponent* Owner)
 : TTourRefBookTableGridProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourTripProcessForm::FormCloseQuery(
      TObject *Sender, bool &CanClose)
 {
  Boolean                              ResultFlag;
  bool                                 LookupComboBoxActiveFlag;
  TDBLookupComboBoxExt                *LookupComboBoxPtr;

  LookupComboBoxActiveFlag = false;
  ResultFlag = true;
  CanClose = false;
  FunctionArgUsedSkip(Sender);
  FunctionArgUsedSkip(LookupComboBoxPtr);

  LookupComboBoxPtr = NULL;
  LookupComboBoxPtr = dynamic_cast<TDBLookupComboBoxExt*>(ActiveControl);

  if (LookupComboBoxPtr != NULL)
   {
    if (LookupComboBoxPtr->ListVisible)
     {
      LookupComboBoxPtr->CloseUp(true);
      LookupComboBoxActiveFlag = true;
     }
   }

  if (!LookupComboBoxActiveFlag)
   {
    if (ModalResult == mrOk)
     {
      if (TripIdDBEdit->Text.IsEmpty())
       {
        ResultFlag = false;

        TourShowDialogError
        (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                    + GetTranslatedStr(TourRefBookTripIdStr)).c_str());

        TripIdDBEdit->SetFocus();
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
  else
   {
    CanClose = false;
   }
 }
//---------------------------------------------------------------------------

#undef   GetTranslatedStr(Index)

