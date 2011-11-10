//---------------------------------------------------------------------------

#ifndef PathAddFormH
#define PathAddFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "PathProcessForm.h"
#include "VStringStorage.h"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "DBLookupComboBoxExt.h"
#include "PathProcessForm.h"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TTourPathAddForm : public TTourPathProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourPathAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourPathAddForm *TourPathAddForm;
//---------------------------------------------------------------------------
#endif
