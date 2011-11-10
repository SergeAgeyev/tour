//---------------------------------------------------------------------------

#ifndef StopModelAddFormH
#define StopModelAddFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StopModelProcessForm.h"
#include "VStringStorage.h"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TTourRefBookStopModelAddForm : public TTourRefBookStopModelProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookStopModelAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookStopModelAddForm *TourRefBookStopModelAddForm;
//---------------------------------------------------------------------------
#endif
