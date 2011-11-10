//---------------------------------------------------------------------------

#ifndef PathProcessFormH
#define PathProcessFormH
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
#include "DBLookupComboBoxExt.h"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TTourPathProcessForm : public TTourRefBookTableGridProcessForm
{
__published:    // IDE-managed Components
 TLabel *PathNormSpeedLabel;
 TDBEdit *PathLengthDBEdit;
 TLabel *PathFromStopIdLabel;
 TLabel *PathLengthLabel;
 TDBEdit *PathFlowDBEdit;
 TDBLookupComboBoxExt *PathFromStopIdDBLookupComboBoxExt;
 TLabel *PathToStopIdIdLabel;
 TDBLookupComboBoxExt *PathToStopIdDBLookupComboBoxExt;
 TDataSource *StopDataSource;
 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
 __fastcall TTourPathProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourPathProcessForm *TourPathProcessForm;
//---------------------------------------------------------------------------
#endif
