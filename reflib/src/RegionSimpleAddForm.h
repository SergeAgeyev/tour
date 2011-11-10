//---------------------------------------------------------------------------

#ifndef RegionSimpleAddFormH
#define RegionSimpleAddFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RegionSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>

enum TourRegionSimpleAddStringsTypes
 {
  TourRegionSimpleAddRegionFieldExistErrorMessageStr = TourRegionSimpleProcessRegionStringsCount,
  TourRegionSimpleAddRegionFieldExistExceptionMessageStr
 };

//---------------------------------------------------------------------------
class TTourRegionSimpleAddForm : public TTourRegionSimpleProcessForm
{
__published:    // IDE-managed Components
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourRegionSimpleAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRegionSimpleAddForm *TourRegionSimpleAddForm;
//---------------------------------------------------------------------------
#endif
