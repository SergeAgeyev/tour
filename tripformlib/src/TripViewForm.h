//---------------------------------------------------------------------------

#ifndef TripViewFormH
#define TripViewFormH
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
class TTourTripViewForm : public TTourRefBookTableGridViewForm
{
__published:    // IDE-managed Components
 TADOQuery *TripOwnerQuery;
 TADOQuery *BusQuery;
 TStringField *MainQuerytrip_id;
 TStringField *MainQuerybus_model;
 TStringField *MainQuerytripowner_id;
 TStringField *MainQuerytrip_notes;
 TStringField *MainQuerytripowner_name;
 TStringField *MainQuerybus_desc;
 TToolButton *Separator4ToolButton;
 TToolButton *ToolButton;
 TAction *TripStepAction;
 TMenuItem *TripStepMenuItem;
        TWideStringField *MainQuerytrip_name;
 void __fastcall NewActionExecute(TObject *Sender);
 void __fastcall EditActionExecute(TObject *Sender);
 void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
 void __fastcall FormCreate(TObject *Sender);
 void __fastcall RefreshActionExecute(TObject *Sender);
 void __fastcall TripStepActionExecute(TObject *Sender);
private:        // User declarations
public:         // User declarations
 __fastcall TTourTripViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripViewForm *TourTripViewForm;
//---------------------------------------------------------------------------
#endif
