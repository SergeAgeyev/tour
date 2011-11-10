//---------------------------------------------------------------------------

#ifndef TableGridProcessFormH
#define TableGridProcessFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include "VStringStorage.h"

enum TourRefBookProcessStringTypes
 {
  TourRefBookInputFieldMessageStr = 0,
  TourRefBookProcessStringTypesEnumCount
 };

//---------------------------------------------------------------------------
class TTourRefBookTableGridProcessForm : public TForm
{
__published:	// IDE-managed Components
 TDataSource *FMainQueryDataSource;
 TButton *CancelButton;
 TButton *SaveButton;
 TVStringStorage *VStringStorage;
private:
 void __fastcall SetMainQueryDataSet(TDataSet* value);	// User declarations
public:		// User declarations
 __fastcall TTourRefBookTableGridProcessForm(TComponent* Owner);
 __property TDataSet* MainQueryDataSet  = { write=SetMainQueryDataSet };
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookTableGridProcessForm *TourRefBookTableGridProcessForm;
//---------------------------------------------------------------------------
#endif
