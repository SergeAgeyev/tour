//---------------------------------------------------------------------------

#ifndef TripOwnerSimpleAddFormH
#define TripOwnerSimpleAddFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TripOwnerSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>

enum TourTripOwnerSimpleAddStringsTypes
 {
  TourTripOwnerSimpleAddTripOwnerFieldExistErrorMessageStr = TourTripOwnerSimpleProcessTripOwnerStringsCount,
  TourTripOwnerSimpleAddTripOwnerFieldExistExceptionMessageStr
 };

//---------------------------------------------------------------------------
class TTourTripOwnerSimpleAddForm : public TTourTripOwnerSimpleProcessForm
{
__published:    // IDE-managed Components
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourTripOwnerSimpleAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripOwnerSimpleAddForm *TourTripOwnerSimpleAddForm;
//---------------------------------------------------------------------------
#endif
