//---------------------------------------------------------------------------

#ifndef TripSimpleAddFormH
#define TripSimpleAddFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TripSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>
#include "RxGrdCpt.h"
#include "VCustomKeyComboBox.h"
#include "VMemoKeyComboBox.h"

enum TourTripSimpleAddStringsTypes
 {
  TourTripSimpleAddTripFieldExistErrorMessageStr = TourTripSimpleProcessTripStringsCount,
  TourTripSimpleAddTripFieldExistExceptionMessageStr
 };

//---------------------------------------------------------------------------
class TTourTripSimpleAddForm : public TTourTripSimpleProcessForm
{
__published:    // IDE-managed Components
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourTripSimpleAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripSimpleAddForm *TourTripSimpleAddForm;
//---------------------------------------------------------------------------
#endif
