//---------------------------------------------------------------------------

#ifndef SimpleProcessFormH
#define SimpleProcessFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VStringStorage.h"
#include <ExtCtrls.hpp>

enum TourSimpleProcessStringsTypes
 {
  TourSimpleProcessIllegalIntValueErrorMessageStr = 0,
  TourSimpleProcessIllegalIntValueExceptionMessageStr,
  TourSimpleProcessIllegalFloatValueErrorMessageStr,
  TourSimpleProcessIllegalFloatValueExceptionMessageStr,
  TourSimpleProcessStringsCount
 };

//---------------------------------------------------------------------------
class TTourSimpleProcessForm : public TForm
{
__published:	// IDE-managed Components
        TBevel *Bevel;
        TPanel *Panel;
        TVStringStorage *VStringStorage;
        TButton *OkButton;
        TButton *CancelButton;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TTourSimpleProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourSimpleProcessForm *TourSimpleProcessForm;
//---------------------------------------------------------------------------
#endif
