//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CitySimpleAddForm.h"
#include "TourTool.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CitySimpleProcessForm"
#pragma link "VStringStorage"
#pragma link "RxGrdCpt"
#pragma link "VCustomKeyComboBox"
#pragma link "VMemoKeyComboBox"
#pragma resource "*.dfm"

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

TTourCitySimpleAddForm *TourCitySimpleAddForm;
//---------------------------------------------------------------------------
__fastcall TTourCitySimpleAddForm::TTourCitySimpleAddForm(TComponent* Owner)
        : TTourCitySimpleProcessForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTourCitySimpleAddForm::FormCloseQuery(TObject *Sender,
      bool &CanClose)
 {
  bool                                 NoErrorFlag;
  AnsiString                           ErrorMessageStr;
  AnsiString                           ExceptionMessageStr;

  NoErrorFlag = true;
  CanClose    = false;

  if (ModalResult == mrOk)
   {
    if (NoErrorFlag)
     {
      if (!CityZIPEdit->Text.IsEmpty())
       {
        if (TourCheckCityExist(CityZIPEdit->Text))
         {
          ErrorMessageStr
          = GetTranslatedStr(TourCitySimpleAddCityFieldExistErrorMessageStr);
          ExceptionMessageStr
          = GetTranslatedStr(TourCitySimpleAddCityFieldExistExceptionMessageStr);
          NoErrorFlag = false;
          CityZIPEdit->SetFocus();
         }
       }
     }

    if (NoErrorFlag)
     {
      CanClose = true;

      TTourCitySimpleProcessForm::FormCloseQuery(Sender,CanClose);
     }
    else
     {
      AnsiString                        *ErrorMessageStrPtr;
      AnsiString                        *ExceptionMessageStrPtr;

      if (!ErrorMessageStr.IsEmpty())
       {
        ErrorMessageStrPtr = &ErrorMessageStr;
       }
      else
       {
        ErrorMessageStrPtr = NULL;
       }

      if (!ExceptionMessageStr.IsEmpty())
       {
        ExceptionMessageStrPtr = &ExceptionMessageStr;
       }
      else
       {
        ExceptionMessageStrPtr = NULL;
       }

      TourShowDialogExceptionStr(ErrorMessageStrPtr,ExceptionMessageStrPtr);
     }
   }
  else
   {
    CanClose = true;
   }
 }
//---------------------------------------------------------------------------
