//---------------------------------------------------------------------------

#ifndef TripAddFormH
#define TripAddFormH
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
class TTourTripAddForm : public TTourTripProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourTripAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripAddForm *TourTripAddForm;
//---------------------------------------------------------------------------
#endif
