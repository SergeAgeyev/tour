//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrPath

#include "StdTool.h"
#include "TourTool.h"
#include "PathProcessForm.h"
#include "DataSetViewForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TableGridProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma resource "*.dfm"
TTourPathProcessForm *TourPathProcessForm;

enum TourRefBookPathProcessStringTypes
 {
  TourRefBookPathFromStopIdStr = TourRefBookProcessStringTypesEnumCount,
  TourRefBookPathToStopIdStr,
  TourRefBookPathInvalidNormSpeedMessageStr,
  TourRefBookPathInvalidLengthMessageStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourPathProcessForm::TTourPathProcessForm(TComponent* Owner)
 : TTourRefBookTableGridProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourPathProcessForm::FormCloseQuery(
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
      if (PathFromStopIdDBLookupComboBoxExt->Field->IsNull)
       {
        ResultFlag = false;

        TourShowDialogError
        (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                    + GetTranslatedStr(TourRefBookPathFromStopIdStr)).c_str());

        PathFromStopIdDBLookupComboBoxExt->SetFocus();
       }
      if (ResultFlag)
       {
        if (PathToStopIdDBLookupComboBoxExt->Field->IsNull)
         {
          ResultFlag = false;

          TourShowDialogError
          (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                      + GetTranslatedStr(TourRefBookPathToStopIdStr)).c_str());

          PathToStopIdDBLookupComboBoxExt->SetFocus();
         }
       }

      if (ResultFlag)
       {
        if (!PathFlowDBEdit->Text.IsEmpty())
         {
          try
           {
            if (StrToFloat(PathFlowDBEdit->Text) < 0)
             {
              ResultFlag = false;

              TourShowDialogError
              (AnsiString(GetTranslatedStr
                          (TourRefBookPathInvalidNormSpeedMessageStr)).c_str());

              PathFlowDBEdit->SetFocus();
             }
           }
          catch (...)
           {
            ResultFlag = false;

            TourShowDialogError
            (AnsiString(GetTranslatedStr
                        (TourRefBookPathInvalidNormSpeedMessageStr)).c_str());

            PathFlowDBEdit->SetFocus();
           }
         }
       }

      if (ResultFlag)
       {
        if (!PathLengthDBEdit->Text.IsEmpty())
         {
          try
           {
            if (StrToFloat(PathLengthDBEdit->Text) < 0)
             {
              ResultFlag = false;

              TourShowDialogError
              (AnsiString(GetTranslatedStr
                          (TourRefBookPathInvalidLengthMessageStr)).c_str());

              PathLengthDBEdit->SetFocus();
             }
           }
          catch (...)
           {
            ResultFlag = false;

            TourShowDialogError
            (AnsiString(GetTranslatedStr
                        (TourRefBookPathInvalidLengthMessageStr)).c_str());

            PathLengthDBEdit->SetFocus();
           }
         }
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


