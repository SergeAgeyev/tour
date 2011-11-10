//---------------------------------------------------------------------------

#ifndef StopSelectFormH
#define StopSelectFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Placemnt.h"
#include "RXDBCtrl.h"
#include "TableGridSelectForm.h"
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
class TTourRefBookStopSelectForm : public TTourRefBookTableGridSelectForm
{
__published:    // IDE-managed Components
 TADOQuery *StopOwnerQuery;
 TStringField *MainQuerystop_id;
 TStringField *MainQuerycity_zip;
 TStringField *MainQuerystop_model;
 TStringField *MainQuerystopowner_id;
 TStringField *MainQuerystop_name;
 TADOQuery *StopModelQuery;
 TADOQuery *CityQuery;
 TStringField *MainQuerycity_name;
 TStringField *MainQuerystopmodel_name;
 TStringField *MainQuerystopowner_name;
 void __fastcall FormCreate(TObject *Sender);
 void __fastcall RefreshActionExecute(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookStopSelectForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookStopSelectForm *TourRefBookStopSelectForm;
//---------------------------------------------------------------------------
#endif
