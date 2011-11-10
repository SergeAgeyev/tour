//---------------------------------------------------------------------------

#ifndef CitySimpleEditFormH
#define CitySimpleEditFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CitySimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>
#include "RxGrdCpt.h"
#include "VCustomKeyComboBox.h"
#include "VMemoKeyComboBox.h"
//---------------------------------------------------------------------------
class TTourCitySimpleEditForm : public TTourCitySimpleProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
        __fastcall TTourCitySimpleEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourCitySimpleEditForm *TourCitySimpleEditForm;
//---------------------------------------------------------------------------
#endif
