//---------------------------------------------------------------------------

#ifndef CitySimpleAddFormH
#define CitySimpleAddFormH
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

enum TourCitySimpleAddStringsTypes
 {
  TourCitySimpleAddCityFieldExistErrorMessageStr = TourCitySimpleProcessCityStringsCount,
  TourCitySimpleAddCityFieldExistExceptionMessageStr
 };

//---------------------------------------------------------------------------
class TTourCitySimpleAddForm : public TTourCitySimpleProcessForm
{
__published:    // IDE-managed Components
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourCitySimpleAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourCitySimpleAddForm *TourCitySimpleAddForm;
//---------------------------------------------------------------------------
#endif
