//---------------------------------------------------------------------------

#ifndef RegionViewFormH
#define RegionViewFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Placemnt.h"
#include "RXDBCtrl.h"
#include "TableGridViewForm.h"
#include "VADODataSourceOrdering.h"
#include "VCustomDataSourceOrdering.h"
#include "VDBGridFilterDialog.h"
#include "VDBSortGrid.h"
#include "VStringStorage.h"
#include <ActnList.hpp>
#include <ADODB.hpp>
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include "VCustomDBGridFilterDialog.h"
//---------------------------------------------------------------------------
class TTourRefBookRegionViewForm : public TTourRefBookTableGridViewForm
{
__published:    // IDE-managed Components
 TStringField *MainQueryRegion_id;
 TStringField *MainQueryRegion_name;
 void __fastcall NewActionExecute(TObject *Sender);
 void __fastcall EditActionExecute(TObject *Sender);
 void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookRegionViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookRegionViewForm *TourRefBookRegionViewForm;
//---------------------------------------------------------------------------
#endif
