//---------------------------------------------------------------------------

#ifndef StopProcessFormH
#define StopProcessFormH
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
//---------------------------------------------------------------------------
class TTourRefBookStopProcessForm : public TTourRefBookTableGridProcessForm
{
__published:    // IDE-managed Components
 TLabel *StopIdLabel;
 TLabel *CityZIPLabel;
 TDBEdit *StopIdDBEdit;
 TDBEdit *CityZIPDBEdit;
 TLabel *StopModelLabel;
 TLabel *StopNameLabel;
 TDBEdit *StopNameDBEdit;
 TDBLookupComboBoxExt *StopModelDBLookupComboBoxExt;
 TDataSource *CityDataSource;
 TButton *CityZIPButton;
 TLabel *StopOwnerIdLabel;
 TDBLookupComboBoxExt *StopOwnerIdDBLookupComboBoxExt;
 TDataSource *StopOwnerDataSource;
 TDataSource *StopModelDataSource;
 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
 void __fastcall CityZIPButtonClick(TObject *Sender);
private:        // User declarations
public:         // User declarations
 __fastcall TTourRefBookStopProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookStopProcessForm *TourRefBookStopProcessForm;
//---------------------------------------------------------------------------
#endif
