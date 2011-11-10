//---------------------------------------------------------------------------

#ifndef TripOwnerSimpleProcessFormH
#define TripOwnerSimpleProcessFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>

enum TourTripOwnerSimpleProcessStringsTypes
 {
  TourTripOwnerSimpleProcessTripOwnerFieldEmptyErrorMessageStr = TourSimpleProcessStringsCount,
  TourTripOwnerSimpleProcessTripOwnerFieldEmptyExceptionMessageStr,
  TourTripOwnerSimpleProcessTripOwnerStringsCount
 };

//---------------------------------------------------------------------------
class TTourTripOwnerSimpleProcessForm : public TTourSimpleProcessForm
{
__published:    // IDE-managed Components
        TLabel *TripOwnerLabel;
        TLabel *TripOwnerNameLabel;
        TEdit *TripOwnerEdit;
        TEdit *TripOwnerNameEdit;
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourTripOwnerSimpleProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripOwnerSimpleProcessForm *TourTripOwnerSimpleProcessForm;
//---------------------------------------------------------------------------
#endif
