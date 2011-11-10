//---------------------------------------------------------------------------

#ifndef StopEditFormH
#define StopEditFormH
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
class TTourRefBookStopEditForm : public TTourRefBookStopProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookStopEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookStopEditForm *TourRefBookStopEditForm;
//---------------------------------------------------------------------------
#endif
