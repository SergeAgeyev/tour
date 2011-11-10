//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "CityProcessForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TableGridProcessForm"
#pragma link "VStringStorage"
#pragma link "DBLookupComboBoxExt"
#pragma resource "*.dfm"
TTourRefBookCityProcessForm *TourRefBookCityProcessForm;

enum TourRefBookCityProcessStringTypes
 {
  TourRefBookCityZIPStr = TourRefBookProcessStringTypesEnumCount,
  TourRefBookCityInvalidPopulationMessageStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookCityProcessForm::TTourRefBookCityProcessForm(TComponent* Owner)
 : TTourRefBookTableGridProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourRefBookCityProcessForm::FormCloseQuery(
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
      if (CityZIPDBEdit->Text.IsEmpty())
       {
        ResultFlag = false;

        TourShowDialogError
        (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                    + GetTranslatedStr(TourRefBookCityZIPStr)).c_str());

        CityZIPDBEdit->SetFocus();
       }

      if (ResultFlag)
       {
        if (!CityPopulationDBEdit->Text.IsEmpty())
         {
          try
           {
            if (StrToInt(CityPopulationDBEdit->Text) < 0)
             {
              ResultFlag = false;

              TourShowDialogError
              (AnsiString(GetTranslatedStr
                          (TourRefBookCityInvalidPopulationMessageStr)).c_str());

              CityPopulationDBEdit->SetFocus();
             }
           }
          catch (...)
           {
            ResultFlag = false;

            TourShowDialogError
            (AnsiString(GetTranslatedStr
                        (TourRefBookCityInvalidPopulationMessageStr)).c_str());

            CityPopulationDBEdit->SetFocus();
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

