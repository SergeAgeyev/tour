//---------------------------------------------------------------------------

#ifndef TripStepViewFormH
#define TripStepViewFormH
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
class TTourTripStepViewForm : public TTourRefBookTableGridViewForm
{
__published:    // IDE-managed Components
 TADOQuery *TripQuery;
 TADOQuery *StopQuery;
 TToolButton *Separator4ToolButton;
 TToolButton *ToolButton;
 TAction *TripStepStepAction;
 TMenuItem *TripStepStepMenuItem;
 TStringField *MainQuerytrip_id;
 TIntegerField *MainQuerytripstep_num;
 TStringField *MainQuerystop_id;
 TStringField *MainQuerypath_tostopid;
 TTimeField *MainQuerytripstep_intime;
 TTimeField *MainQuerytripstep_waittime;
 TStringField *MainQuerytrip_notes;
 TStringField *MainQuerystopid_name;
 TStringField *MainQuerypathtostopid_name;
        TStringField *MainQuerytrip_name;
// void __fastcall NewActionExecute(TObject *Sender);
// void __fastcall EditActionExecute(TObject *Sender);
 void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
 void __fastcall FormCreate(TObject *Sender);
 void __fastcall RefreshActionExecute(TObject *Sender);
 void __fastcall TripStepStepActionExecute(TObject *Sender);
private:        // User declarations
public:         // User declarations
 __fastcall TTourTripStepViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripStepViewForm *TourTripStepViewForm;
//---------------------------------------------------------------------------
#endif
