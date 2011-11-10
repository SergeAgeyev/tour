//---------------------------------------------------------------------------

#ifndef BusProcessFormH
#define BusProcessFormH
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
//---------------------------------------------------------------------------
class TTourRefBookBusProcessForm : public TTourRefBookTableGridProcessForm
{
__published:    // IDE-managed Components
 TLabel *BusModelLabel;
 TLabel *BusDescLabel;
 TDBEdit *BusModelDBEdit;
 TDBEdit *BusDescDBEdit;
 TLabel *BusSpeedFactorLabel;
 TLabel *BusCapacityLabel;
 TDBEdit *BusSpeedFactorDBEdit;
 TDBEdit *BusCapacityDBEdit;
 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookBusProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookBusProcessForm *TourRefBookBusProcessForm;
//---------------------------------------------------------------------------
#endif
