//---------------------------------------------------------------------------

#ifndef TripOwnerProcessFormH
#define TripOwnerProcessFormH
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
class TTourRefBookTripOwnerProcessForm : public TTourRefBookTableGridProcessForm
{
__published:    // IDE-managed Components
 TLabel *TripOwnerIdLabel;
 TLabel *TripOwnerNameLabel;
 TDBEdit *TripOwnerDBEdit;
 TDBEdit *TripOwnerNameDBEdit;
 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookTripOwnerProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookTripOwnerProcessForm *TourRefBookTripOwnerProcessForm;
//---------------------------------------------------------------------------
#endif
