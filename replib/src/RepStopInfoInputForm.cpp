//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "FieldDef.h"
#include "RepStopInfoGenerator.h"
#include "RepStopInfoInputForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RXDBCtrl"
#pragma link "VADODataSourceOrdering"
#pragma link "VCustomDataSourceOrdering"
#pragma link "VDBSortGrid"
#pragma link "Placemnt"
#pragma resource "*.dfm"
TTourRepStopInfoInputForm *TourRepStopInfoInputForm;
//---------------------------------------------------------------------------
__fastcall TTourRepStopInfoInputForm::TTourRepStopInfoInputForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourRepStopInfoInputForm::FormCreate(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  CursorWaitOpen();

  try
   {
    #ifdef TOURDATABASEMODEBDE
     StopDataSourceOrdering->Active = true;
    #endif

    StopQuery->Open();

    if (StopQuery->IsEmpty())
     {
      CreateReportButton->Enabled = false;
     }

    #ifdef TOURDATABASEMODEADO
     StopDataSourceOrdering->Active = true;
    #endif
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();
 }
//---------------------------------------------------------------------------
void __fastcall TTourRepStopInfoInputForm::FormDestroy(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  if (StopQuery->Active)
   {
    StopQuery->Close();
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRepStopInfoInputForm::CreateReportButtonClick(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  if (!StopQuery->IsEmpty())
   {
    StopInfoReportGenerate(StopQuery->FieldByName(StopIdFieldNameStr)->AsString);

    ModalResult = mrOk;
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRepStopInfoInputForm::StopGridDblClick(TObject *Sender)
 {
  CreateReportButtonClick(Sender);
 }
//---------------------------------------------------------------------------
void __fastcall TTourRepStopInfoInputForm::StopGridKeyDown
                (TObject *Sender,WORD &Key, TShiftState Shift)
 {
  FunctionArgUsedSkip(Shift);

  if (Key == VK_RETURN)
   {
    CreateReportButtonClick(Sender);
   }
 }
//---------------------------------------------------------------------------

