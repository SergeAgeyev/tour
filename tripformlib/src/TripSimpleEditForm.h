//---------------------------------------------------------------------------

#ifndef TripSimpleEditFormH
#define TripSimpleEditFormH
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
//---------------------------------------------------------------------------
class TTourTripSimpleEditForm : public TTourTripSimpleProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
        __fastcall TTourTripSimpleEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripSimpleEditForm *TourTripSimpleEditForm;
//---------------------------------------------------------------------------
#endif
