//---------------------------------------------------------------------------

#ifndef StatsEditFormH
#define StatsEditFormH
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
class TTourStatsEditForm : public TTourStatsProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourStatsEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourStatsEditForm *TourStatsEditForm;
//---------------------------------------------------------------------------
#endif
