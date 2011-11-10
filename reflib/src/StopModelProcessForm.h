//---------------------------------------------------------------------------

#ifndef StopModelProcessFormH
#define StopModelProcessFormH
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
class TTourRefBookStopModelProcessForm : public TTourRefBookTableGridProcessForm
{
__published:    // IDE-managed Components
 TLabel *StopModelIdLabel;
 TLabel *StopModelNameLabel;
 TDBEdit *StopModelDBEdit;
 TDBEdit *StopModelNameDBEdit;
 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookStopModelProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookStopModelProcessForm *TourRefBookStopModelProcessForm;
//---------------------------------------------------------------------------
#endif
