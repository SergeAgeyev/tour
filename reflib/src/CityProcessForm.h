//---------------------------------------------------------------------------

#ifndef CityProcessFormH
#define CityProcessFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TableGridProcessForm.h"
#include "VStringStorage.h"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "DBLookupComboBoxExt.h"
//---------------------------------------------------------------------------
class TTourRefBookCityProcessForm : public TTourRefBookTableGridProcessForm
{
__published:    // IDE-managed Components
 TLabel *CityZIPLabel;
 TLabel *CityNameLabel;
 TDBEdit *CityZIPDBEdit;
 TDBEdit *CityNameDBEdit;
 TLabel *RegionIdLabel;
 TLabel *CityPopulationLabel;
 TDBEdit *CityPopulationDBEdit;
 TDBLookupComboBoxExt *RegionIdDBLookupComboBoxExt;
 TDataSource *RegionDataSource;
 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookCityProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookCityProcessForm *TourRefBookCityProcessForm;
//---------------------------------------------------------------------------
#endif
