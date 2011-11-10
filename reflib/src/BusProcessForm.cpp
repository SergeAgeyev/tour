//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "BusProcessForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TableGridProcessForm"
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourRefBookBusProcessForm *TourRefBookBusProcessForm;

enum TourRefBookBusProcessStringTypes
 {
  TourRefBookBusModelStr = TourRefBookProcessStringTypesEnumCount,
  TourRefBookBusModelInvalidSpeedFactorMessageStr,
  TourRefBookBusModelInvalidCapacityMessageStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookBusProcessForm::TTourRefBookBusProcessForm(TComponent* Owner)
 : TTourRefBookTableGridProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourRefBookBusProcessForm::FormCloseQuery(TObject *Sender,
      bool &CanClose)
 {
  Boolean                              ResultFlag;

  ResultFlag = true;
  CanClose = false;
  FunctionArgUsedSkip(Sender);

  if (ModalResult == mrOk)
   {
    if (BusModelDBEdit->Text.IsEmpty())
     {
      ResultFlag = false;

      TourShowDialogError
      (AnsiString(GetTranslatedStr(TourRefBookInputFieldMessageStr)
                  + GetTranslatedStr(TourRefBookBusModelStr)).c_str());

      BusModelDBEdit->SetFocus();
     }

    if (ResultFlag)
     {
      if (!BusSpeedFactorDBEdit->Text.IsEmpty())
       {
        try
         {
          if (StrToFloat(BusSpeedFactorDBEdit->Text) < 0)
           {
            ResultFlag = false;

            TourShowDialogError
            (AnsiString(GetTranslatedStr
                        (TourRefBookBusModelInvalidSpeedFactorMessageStr)).c_str());

            BusSpeedFactorDBEdit->SetFocus();
           }
         }
        catch (...)
         {
          ResultFlag = false;

          TourShowDialogError
          (AnsiString(GetTranslatedStr
                      (TourRefBookBusModelInvalidSpeedFactorMessageStr)).c_str());

          BusSpeedFactorDBEdit->SetFocus();
         }
       }
     }

    if (ResultFlag)
     {
      if (!BusCapacityDBEdit->Text.IsEmpty())
       {
        try
         {
          if (StrToInt(BusCapacityDBEdit->Text) < 0)
           {
            ResultFlag = false;

            TourShowDialogError
            (AnsiString(GetTranslatedStr
                        (TourRefBookBusModelInvalidCapacityMessageStr)).c_str());

            BusCapacityDBEdit->SetFocus();
           }
         }
        catch (...)
         {
          ResultFlag = false;

          TourShowDialogError
          (AnsiString(GetTranslatedStr
                      (TourRefBookBusModelInvalidCapacityMessageStr)).c_str());

          BusCapacityDBEdit->SetFocus();
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

//---------------------------------------------------------------------------

#undef   GetTranslatedStr(Index)

