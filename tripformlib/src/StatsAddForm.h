//---------------------------------------------------------------------------

#ifndef StatsAddFormH
#define StatsAddFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StatsProcessForm.h"
#include "VStringStorage.h"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "DBLookupComboBoxExt.h"
#include "StatsProcessForm.h"
#include <ComCtrls.hpp>
#include <ADODB.hpp>
//---------------------------------------------------------------------------
class TTourStatsAddForm : public TTourStatsProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourStatsAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourStatsAddForm *TourStatsAddForm;
//---------------------------------------------------------------------------
#endif
