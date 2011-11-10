//---------------------------------------------------------------------------

#ifndef TripOwnerAddFormH
#define TripOwnerAddFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TripOwnerProcessForm.h"
#include "VStringStorage.h"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TTourRefBookTripOwnerAddForm : public TTourRefBookTripOwnerProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookTripOwnerAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookTripOwnerAddForm *TourRefBookTripOwnerAddForm;
//---------------------------------------------------------------------------
#endif
