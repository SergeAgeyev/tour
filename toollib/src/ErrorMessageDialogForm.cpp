//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ErrorMessageDialogForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourErrorMessageDialogForm *TourErrorMessageDialogForm;

enum TourErrorMessageDialogStringTypes
 {
  TourErrorDialogInternalErrorStr = 0,
  TourErrorDialogDetailsCaptionStr,
  TourErrorDialogNonDetailsCaptionStr
 };

static bool ErrorMessageDialogDetailsFlag = false;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]
//---------------------------------------------------------------------------
__fastcall TTourErrorMessageDialogForm::TTourErrorMessageDialogForm(TComponent* Owner)
 : TForm(Owner)
 {
  DialogDetailsFlag = ErrorMessageDialogDetailsFlag;
 }
//---------------------------------------------------------------------------
void __fastcall TTourErrorMessageDialogForm::DetailsButtonClick(
      TObject *Sender)
 {
  DialogDetailsFlag = !DialogDetailsFlag;
  
  UpdateByDetailsFlags();
 }
//---------------------------------------------------------------------------

void __fastcall TTourErrorMessageDialogForm::FormCreate(TObject *Sender)
 {
  StoredFormHeight = this->ClientHeight;
  UpdateByDetailsFlags();
 }

//---------------------------------------------------------------------------
void __fastcall TTourErrorMessageDialogForm::FormDestroy(TObject *Sender)
 {
  ErrorMessageDialogDetailsFlag = DialogDetailsFlag;
 }
//---------------------------------------------------------------------------

void     TTourErrorMessageDialogForm::UpdateByDetailsFlags
         (void)
 {
  DetailsMemo->Visible = DialogDetailsFlag;

  if (!DialogDetailsFlag)
   {
    this->ClientHeight = DetailsMemo->Top - 1;
    DetailsButton->Caption = GetTranslatedStr(TourErrorDialogDetailsCaptionStr);
   }
  else
   {
    this->ClientHeight = StoredFormHeight;
    DetailsButton->Caption = GetTranslatedStr(TourErrorDialogNonDetailsCaptionStr);
   }
 }

#undef  GetTranslatedStr(Index)




