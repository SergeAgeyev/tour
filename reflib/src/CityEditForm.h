//---------------------------------------------------------------------------

#ifndef CityEditFormH
#define CityEditFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CityProcessForm.h"
#include "VStringStorage.h"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "DBLookupComboBoxExt.h"
//---------------------------------------------------------------------------
class TTourRefBookCityEditForm : public TTourRefBookCityProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookCityEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookCityEditForm *TourRefBookCityEditForm;
//---------------------------------------------------------------------------
#endif
