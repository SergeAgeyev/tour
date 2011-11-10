//---------------------------------------------------------------------------

#ifndef TripStepNewMasterFormH
#define TripStepNewMasterFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TripStepWizardForm.h"
#include "VStringStorage.h"
#include <ActnList.hpp>
#include <ADODB.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <Menus.hpp>
#include "DBLookupComboBoxExt.h"
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TTourTripStepNewMasterForm : public TTourTripStepWizardForm
{
__published:	// IDE-managed Components
 TButton *BackButton;
        TLabel *TripIdLabel;
        TDBEdit *TripIdDBEdit;
        TLabel *BusModelLabel;
        TDBLookupComboBoxExt *BusModelDBLookupComboBoxExt;
        TLabel *TripOwnerIdLabel;
        TDBLookupComboBoxExt *TripOwnerIdDBLookupComboBoxExt;
        TLabel *TripNotesLabel;
        TDBEdit *TripNotesDBEdit;
        TDataSource *TripQueryDataSource;
        TDataSource *TripOwnerDataSource;
        TDataSource *BusDataSource;
        TADOQuery *TripOwnerQuery;
        TADOQuery *BusQuery;
        TBevel *Bevel;
        TADOQuery *ExistTripQuery;
        TLabel *TripNameLabel;
        TDBEdit *TripNameDBEdit;
        TWideStringField *TripQuerytrip_id;
        TWideStringField *TripQuerytrip_name;
        TWideStringField *TripQuerytrip_notes;
        void __fastcall NextButtonClick(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
protected:
 virtual TDateTime GetPreliminaryTimeIn(AnsiString FromStopIdStr, AnsiString ToStopIdStr);
 
public:		// User declarations
 __fastcall TTourTripStepNewMasterForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripStepNewMasterForm *TourTripStepNewMasterForm;
//---------------------------------------------------------------------------
#endif
