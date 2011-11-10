//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TourTool.h"
#include "TripNewMasterForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBLookupComboBoxExt"
#pragma link "TripAddForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourTripNewMasterForm *TourTripNewMasterForm;

enum TourTripNewMasterStringTypes
 {
  TourTripNewMasterTripIdExistMessageStr = TourRefBookTripProcessStringTypesEnumCount
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourTripNewMasterForm::TTourTripNewMasterForm(TComponent* Owner)
 : TTourTripAddForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourTripNewMasterForm::FormCreate(TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    TripQuery->Open();
    TripOwnerQuery->Open();
    BusQuery->Open();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();
 }
//---------------------------------------------------------------------------
void __fastcall TTourTripNewMasterForm::SaveButtonClick(TObject *Sender)
 {
  if (!TripIdDBEdit->Text.IsEmpty())
   {
    if (TourCheckTripExist(QuotedStr(TripIdDBEdit->Text)))
     {
      TourShowDialogError
      (GetTranslatedStr(TourTripNewMasterTripIdExistMessageStr).c_str());

      TripIdDBEdit->SetFocus();
      TripIdDBEdit->SelectAll();
     }
    else
     {
      TripIdStr = TripIdDBEdit->Text;
      ModalResult = mrOk;
     }
   }
  else
   {
    TourShowDialogError
    (AnsiString
     (GetTranslatedStr(TourRefBookInputFieldMessageStr) +
      GetTranslatedStr(TourRefBookTripIdStr)).c_str());

    TripIdDBEdit->SetFocus();
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripNewMasterForm::FormDestroy(TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    if (TripQuery->Active)
     {
      TripQuery->Close();
     }
    if (TripOwnerQuery->Active)
     {
      TripOwnerQuery->Close();
     }
    if (BusQuery->Active)
     {
      BusQuery->Close();
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripNewMasterForm::FormShow(TObject *Sender)
 {
  TripIdDBEdit->SetFocus();
 }
//---------------------------------------------------------------------------


#undef   GetTranslatedStr(Index)
