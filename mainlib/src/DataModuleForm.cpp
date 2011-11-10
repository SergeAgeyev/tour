//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataModuleForm.h"
#include "LoginForm.h"
//#include "FieldDef.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTourDataModule *TourDataModule;
//---------------------------------------------------------------------------
__fastcall TTourDataModule::TTourDataModule(TComponent* Owner)
        : TDataModule(Owner)
 {
  CurrentClerkIdStr    = "";
  DataBaseEditModeFlag = false;
 }
//---------------------------------------------------------------------------
TDateTime TTourDataModule::VegaLocalDateTime(void) const
 {
  return(TDateTime::CurrentDate());
 }

