//---------------------------------------------------------------------------

#ifndef RegionSimpleProcessFormH
#define RegionSimpleProcessFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>

enum TourRegionSimpleProcessStringsTypes
 {
  TourRegionSimpleProcessRegionIdFieldEmptyErrorMessageStr = TourSimpleProcessStringsCount,
  TourRegionSimpleProcessRegionIdFieldEmptyExceptionMessageStr,
  TourRegionSimpleProcessRegionStringsCount
 };

//---------------------------------------------------------------------------
class TTourRegionSimpleProcessForm : public TTourSimpleProcessForm
{
__published:    // IDE-managed Components
        TLabel *RegionIdLabel;
        TLabel *RegionNameLabel;
        TEdit *RegionIdEdit;
        TEdit *RegionNameEdit;
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourRegionSimpleProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRegionSimpleProcessForm *TourRegionSimpleProcessForm;
//---------------------------------------------------------------------------
#endif
