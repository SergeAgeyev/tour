//---------------------------------------------------------------------------

#ifndef CityAddFormH
#define CityAddFormH
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
class TTourRefBookCityAddForm : public TTourRefBookCityProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookCityAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookCityAddForm *TourRefBookCityAddForm;
//---------------------------------------------------------------------------
#endif
