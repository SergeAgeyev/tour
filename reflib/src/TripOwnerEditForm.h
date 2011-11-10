//---------------------------------------------------------------------------

#ifndef TripOwnerEditFormH
#define TripOwnerEditFormH
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
class TTourRefBookTripOwnerEditForm : public TTourRefBookTripOwnerProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookTripOwnerEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookTripOwnerEditForm *TourRefBookTripOwnerEditForm;
//---------------------------------------------------------------------------
#endif
