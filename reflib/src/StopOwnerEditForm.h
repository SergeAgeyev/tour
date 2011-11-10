//---------------------------------------------------------------------------

#ifndef StopOwnerEditFormH
#define StopOwnerEditFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StopOwnerProcessForm.h"
#include "VStringStorage.h"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TTourRefBookStopOwnerEditForm : public TTourRefBookStopOwnerProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookStopOwnerEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookStopOwnerEditForm *TourRefBookStopOwnerEditForm;
//---------------------------------------------------------------------------
#endif
