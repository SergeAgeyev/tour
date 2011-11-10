//---------------------------------------------------------------------------

#ifndef StopOwnerAddFormH
#define StopOwnerAddFormH
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
class TTourRefBookStopOwnerAddForm : public TTourRefBookStopOwnerProcessForm
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
 __fastcall TTourRefBookStopOwnerAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookStopOwnerAddForm *TourRefBookStopOwnerAddForm;
//---------------------------------------------------------------------------
#endif
