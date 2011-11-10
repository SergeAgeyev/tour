//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "FieldDef.h"
#include "RepTripInfoGenerator.h"
#include "RepTripInfoInputForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RXDBCtrl"
#pragma link "VADODataSourceOrdering"
#pragma link "VCustomDataSourceOrdering"
#pragma link "VDBSortGrid"
#pragma link "Placemnt"
#pragma resource "*.dfm"
TTourRepTripInfoInputForm *TourRepTripInfoInputForm;
//---------------------------------------------------------------------------
__fastcall TTourRepTripInfoInputForm::TTourRepTripInfoInputForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourRepTripInfoInputForm::FormCreate(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  CursorWaitOpen();

  try
   {
    #ifdef TOURDATABASEMODEBDE
     TripDataSourceOrdering->Active = true;
    #endif

    TripQuery->Open();

    if (TripQuery->IsEmpty())
     {
      CreateReportButton->Enabled = false;
     }

    #ifdef TOURDATABASEMODEADO
     TripDataSourceOrdering->Active = true;
    #endif
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();
 }
//---------------------------------------------------------------------------
void __fastcall TTourRepTripInfoInputForm::FormDestroy(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  if (TripQuery->Active)
   {
    TripQuery->Close();
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRepTripInfoInputForm::CreateReportButtonClick(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  if (!TripQuery->IsEmpty())
   {
    TripInfoReportGenerate(TripQuery->FieldByName(TripIdFieldNameStr)->AsString);

    ModalResult = mrOk;
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRepTripInfoInputForm::TripGridDblClick(TObject *Sender)
 {
  CreateReportButtonClick(Sender);
 }
//---------------------------------------------------------------------------
void __fastcall TTourRepTripInfoInputForm::TripGridKeyDown
                (TObject *Sender,WORD &Key, TShiftState Shift)
 {
  FunctionArgUsedSkip(Shift);

  if (Key == VK_RETURN)
   {
    CreateReportButtonClick(Sender);
   }
 }
//---------------------------------------------------------------------------

