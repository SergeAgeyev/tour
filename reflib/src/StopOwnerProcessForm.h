//---------------------------------------------------------------------------

#ifndef StopOwnerProcessFormH
#define StopOwnerProcessFormH
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
class TTourRefBookStopOwnerProcessForm : public TTourRefBookTableGridProcessForm
{
__published:	// IDE-managed Components
 TLabel *StopOwnerIdLabel;
 TLabel *StopOwnerNameLabel;
 TDBEdit *StopOwnerIdDBEdit;
 TDBEdit *StopOwnerNameDBEdit;
 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
public:		// User declarations
 __fastcall TTourRefBookStopOwnerProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookStopOwnerProcessForm *TourRefBookStopOwnerProcessForm;
//---------------------------------------------------------------------------
#endif
