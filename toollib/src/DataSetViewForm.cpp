//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataSetViewForm.h"
//#include "DataModuleForm.h"
#include "StdTool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RXDBCtrl"
#pragma link "VADODataSourceOrdering"
#pragma link "VCustomDataSourceOrdering"
#pragma link "VDBSortGrid"
#pragma resource "*.dfm"
TTourDataSetViewForm *TourDataSetViewForm;
//---------------------------------------------------------------------------
__fastcall TTourDataSetViewForm::TTourDataSetViewForm(TComponent* Owner)
        : TForm(Owner)
 {
 }
//---------------------------------------------------------------------------

