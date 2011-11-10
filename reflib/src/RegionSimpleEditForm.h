//---------------------------------------------------------------------------

#ifndef RegionSimpleEditFormH
#define RegionSimpleEditFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RegionSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTourRegionSimpleEditForm : public TTourRegionSimpleProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
        __fastcall TTourRegionSimpleEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRegionSimpleEditForm *TourRegionSimpleEditForm;
//---------------------------------------------------------------------------
#endif
