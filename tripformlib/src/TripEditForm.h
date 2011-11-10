//---------------------------------------------------------------------------

#ifndef TripEditFormH
#define TripEditFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TripProcessForm.h"
#include "VStringStorage.h"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "DBLookupComboBoxExt.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTourTripEditForm : public TTourTripProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourTripEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripEditForm *TourTripEditForm;
//---------------------------------------------------------------------------
#endif
