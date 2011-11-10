//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BaseRegulationForm.h"
#include "DataModuleForm.h"
#include "TourTool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourBaseRegulationForm *TourBaseRegulationForm;
//---------------------------------------------------------------------------
__fastcall TTourBaseRegulationForm::TTourBaseRegulationForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

bool TTourBaseRegulationForm::Execute (void)
 {
  bool                                 ResultFlag;

  ResultFlag = false;

  CursorWaitOpen();

  RichEdit->Lines->Clear();

  try
   {
    unsigned int                       PathCount;
    unsigned int                       DirectPathCount;
    unsigned int                       NewPathCount;

    PathCountQuery->Open();
    DirectPathCountQuery->Open();

    PathCount       = PathCountQuery->FieldByName("Result")->AsInteger;
    DirectPathCount = DirectPathCountQuery->FieldByName("Result")->AsInteger;

    RichEdit->Lines->Add(GetTranslatedStr(TourBaseRegulationPathGenerationStr));
    RichEdit->Lines->Add
    (GetTranslatedStr(TourBaseRegulationPathGenerationCountStr) + IntToStr(PathCount));
    RichEdit->Lines->Add
    (GetTranslatedStr(TourBaseRegulationPathGenerationDirectStr) + IntToStr(DirectPathCount));

    PathCountQuery->Close();

    if (DirectPathCount > 0)
     {
      GenerationReversePathQuery->ExecSQL();
      PathCountQuery->Open();

      NewPathCount = PathCountQuery->FieldByName("Result")->AsInteger;
      RichEdit->Lines->Add
      (GetTranslatedStr(TourBaseRegulationPathGenerationReversStr) + IntToStr(NewPathCount - PathCount));
     }

    ResultFlag = true;
   }
  catch (...)
   {

   }

  if (PathCountQuery->Active)
   {
    PathCountQuery->Close();
   }
  if (DirectPathCountQuery->Active)
   {
    DirectPathCountQuery->Close();
   }

  CursorWaitClose();

  return (ResultFlag);
 }

void __fastcall TTourBaseRegulationForm::OkButtonClick(TObject *Sender)
 {
  OkButton->Enabled     = false;
  CancelButton->Enabled = false;

  if (Execute())
   {
   }
  else
   {
   }

  OkButton->Enabled     = true;
  CancelButton->Enabled = true;
 }
//---------------------------------------------------------------------------

