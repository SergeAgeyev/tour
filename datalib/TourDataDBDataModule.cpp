//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TourDataDBDataModule.h"
#include "DataModuleForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTourDataDBModule *TourDataDBModule;
//---------------------------------------------------------------------------
__fastcall TTourDataDBModule::TTourDataDBModule(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
