//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MessageModuleForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourMessageModule *TourMessageModule;
//---------------------------------------------------------------------------
__fastcall TTourMessageModule::TTourMessageModule(TComponent* Owner)
 : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
