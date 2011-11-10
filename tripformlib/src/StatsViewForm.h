//---------------------------------------------------------------------------

#ifndef StatsViewFormH
#define StatsViewFormH
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
class TTourStatsViewForm : public TTourRefBookTableGridViewForm
{
__published:    // IDE-managed Components
 TADOQuery *TripQuery;
 TADOQuery *StopQuery;
 TStringField *MainQuerytrip_id;
 TDateTimeField *MainQuerystats_date;
 TStringField *MainQuerystats_fromstopid;
 TStringField *MainQuerystats_tostopid;
 TIntegerField *MainQuerystats_flow;
 TStringField *MainQuerytrip_notes;
 TStringField *MainQueryfromstopid_name;
 TStringField *MainQuerytostopid_name;
        TStringField *MainQuerytrip_name;
 void __fastcall NewActionExecute(TObject *Sender);
 void __fastcall EditActionExecute(TObject *Sender);
 void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
 void __fastcall FormCreate(TObject *Sender);
 void __fastcall RefreshActionExecute(TObject *Sender);
private:        // User declarations
public:         // User declarations
 __fastcall TTourStatsViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourStatsViewForm *TourStatsViewForm;
//---------------------------------------------------------------------------
#endif
