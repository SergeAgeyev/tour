//---------------------------------------------------------------------------

#ifndef CitySimpleProcessFormH
#define CitySimpleProcessFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>
#include "RxGrdCpt.h"
#include "VCustomKeyComboBox.h"
#include "VMemoKeyComboBox.h"

enum TourCitySimpleProcessStringsTypes
 {
  TourCitySimpleProcessCityFieldEmptyErrorMessageStr = TourSimpleProcessStringsCount,
  TourCitySimpleProcessCityFieldEmptyExceptionMessageStr,
  TourCitySimpleProcessAddRegionActionErrorMessageStr,
  TourCitySimpleProcessAddActionExceptionMessageStr,
  TourCitySimpleProcessCityStringsCount
 };

//---------------------------------------------------------------------------
class TTourCitySimpleProcessForm : public TTourSimpleProcessForm
{
__published:    // IDE-managed Components
        TLabel *CityZIPlLabel;
        TLabel *CityNameLabel;
        TLabel *CityPopulationLabel;
        TEdit *CityZIPEdit;
        TEdit *CityNameEdit;
        TEdit *CityPopulationEdit;
        TLabel *RegionIdLabel;
        TVMemoKeyComboBox *CityRegionVMemoKeyComboBox;
        TButton *AddRegionButton;
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall AddRegionButtonClick(TObject *Sender);
private:        // User declarations
public:         // User declarations
        __fastcall TTourCitySimpleProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourCitySimpleProcessForm *TourCitySimpleProcessForm;
//---------------------------------------------------------------------------
#endif
