//---------------------------------------------------------------------------

#ifndef StopAddFormH
#define StopAddFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StopProcessForm.h"
#include "VStringStorage.h"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "DBLookupComboBoxExt.h"
//---------------------------------------------------------------------------
class TTourRefBookStopAddForm : public TTourRefBookStopProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookStopAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookStopAddForm *TourRefBookStopAddForm;
//---------------------------------------------------------------------------
#endif
