//---------------------------------------------------------------------------

#ifndef PathEditFormH
#define PathEditFormH
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
class TTourPathEditForm : public TTourPathProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourPathEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourPathEditForm *TourPathEditForm;
//---------------------------------------------------------------------------
#endif
