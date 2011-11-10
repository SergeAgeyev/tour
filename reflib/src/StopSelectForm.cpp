//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "StopSelectForm.h"
#include "StopAddForm.h"
#include "StopEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Placemnt"
#pragma link "RXDBCtrl"
#pragma link "TableGridSelectForm"
#pragma link "VADODataSourceOrdering"
#pragma link "VCustomDataSourceOrdering"
#pragma link "VDBGridFilterDialog"
#pragma link "VDBSortGrid"
#pragma link "VStringStorage"
#pragma link "VCustomDBGridFilterDialog"
#pragma resource "*.dfm"
TTourRefBookStopSelectForm *TourRefBookStopSelectForm;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookStopSelectForm::TTourRefBookStopSelectForm(TComponent* Owner)
 : TTourRefBookTableGridSelectForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourRefBookStopSelectForm::FormCreate(TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    StopModelQuery->Open();
    StopOwnerQuery->Open();
    CityQuery->Open();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();

  TTourRefBookTableGridSelectForm::FormCreate(Sender);
 }
//---------------------------------------------------------------------------

void __fastcall TTourRefBookStopSelectForm::RefreshActionExecute(
      TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    if (StopModelQuery->Active)
     {
      StopModelQuery->Close();
     }
    if (!StopModelQuery->Active)
     {
      StopModelQuery->Open();
     }
    if (StopOwnerQuery->Active)
     {
      StopOwnerQuery->Close();
     }
    if (!StopOwnerQuery->Active)
     {
      StopOwnerQuery->Open();
     }
    if (CityQuery->Active)
     {
      CityQuery->Close();
     }
    if (!CityQuery->Active)
     {
      CityQuery->Open();
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();

  TTourRefBookTableGridSelectForm::RefreshActionExecute(Sender);
 }

void __fastcall TTourRefBookStopSelectForm::FormDestroy(TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    StopModelQuery->Close();
    StopOwnerQuery->Close();
    CityQuery->Close();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();

  TTourRefBookTableGridSelectForm::FormDestroy(Sender);
 }
//---------------------------------------------------------------------------


