//---------------------------------------------------------------------------

#ifndef PathViewFormH
#define PathViewFormH
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
class TTourPathViewForm : public TTourRefBookTableGridViewForm
{
__published:    // IDE-managed Components
 TADOQuery *StopQuery;
 TFloatField *MainQuerypath_normspeed;
 TStringField *MainQueryPath_fromstopid;
 TStringField *MainQueryPath_tostopid;
 TFloatField *MainQuerypath_length;
 TStringField *MainQueryfromstopid_name;
 TStringField *MainQuerytostopid_name;
 void __fastcall NewActionExecute(TObject *Sender);
 void __fastcall EditActionExecute(TObject *Sender);
 void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
 void __fastcall FormCreate(TObject *Sender);
 void __fastcall RefreshActionExecute(TObject *Sender);
private:        // User declarations
public:         // User declarations
 __fastcall TTourPathViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourPathViewForm *TourPathViewForm;
//---------------------------------------------------------------------------
#endif
