//---------------------------------------------------------------------------

#ifndef RegionProcessFormH
#define RegionProcessFormH
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
//---------------------------------------------------------------------------
class TTourRefBookRegionProcessForm : public TTourRefBookTableGridProcessForm
{
__published:    // IDE-managed Components
 TLabel *RegionIdLabel;
 TLabel *RegionNameLabel;
 TDBEdit *RegionIdDBEdit;
 TDBEdit *RegionNameDBEdit;
 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookRegionProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookRegionProcessForm *TourRefBookRegionProcessForm;
//---------------------------------------------------------------------------
#endif
