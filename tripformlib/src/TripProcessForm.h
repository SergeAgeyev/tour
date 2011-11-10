//---------------------------------------------------------------------------

#ifndef TripProcessFormH
#define TripProcessFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TableGridProcessForm.h"
#include "VStringStorage.h"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "DBLookupComboBoxExt.h"
#include <ExtCtrls.hpp>

enum TourRefBookTripProcessStringTypes
 {
  TourRefBookTripIdStr = TourRefBookProcessStringTypesEnumCount,
  TourRefBookTripProcessStringTypesEnumCount
 };
 
//---------------------------------------------------------------------------
class TTourTripProcessForm : public TTourRefBookTableGridProcessForm
{
__published:    // IDE-managed Components
 TLabel *TripIdLabel;
 TDBEdit *TripIdDBEdit;
 TLabel *BusModelLabel;
 TLabel *TripNotesLabel;
 TDBEdit *TripNotesDBEdit;
 TDBLookupComboBoxExt *BusModelDBLookupComboBoxExt;
 TLabel *TripOwnerIdLabel;
 TDBLookupComboBoxExt *TripOwnerIdDBLookupComboBoxExt;
 TDataSource *TripOwnerDataSource;
 TDataSource *BusDataSource;
        TLabel *TripNameLabel;
        TDBEdit *TripNameDBEdit;
        TBevel *Bevel;
 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
 __fastcall TTourTripProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripProcessForm *TourTripProcessForm;
//---------------------------------------------------------------------------
#endif
