//---------------------------------------------------------------------------

#ifndef TripOwnerSimpleEditFormH
#define TripOwnerSimpleEditFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TripOwnerSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTourTripOwnerSimpleEditForm : public TTourTripOwnerSimpleProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
        __fastcall TTourTripOwnerSimpleEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripOwnerSimpleEditForm *TourTripOwnerSimpleEditForm;
//---------------------------------------------------------------------------
#endif
