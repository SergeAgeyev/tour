//---------------------------------------------------------------------------

#ifndef StopOwnerSimpleProcessFormH
#define StopOwnerSimpleProcessFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>

enum TourStopOwnerSimpleProcessStringsTypes
 {
  TourStopOwnerSimpleProcessStopOwnerFieldEmptyErrorMessageStr = TourSimpleProcessStringsCount,
  TourStopOwnerSimpleProcessStopOwnerFieldEmptyExceptionMessageStr,
  TourStopOwnerSimpleProcessStopOwnerStringsCount
 };

//---------------------------------------------------------------------------
class TTourStopOwnerSimpleProcessForm : public TTourSimpleProcessForm
{
__published:    // IDE-managed Components
        TLabel *StopOwnerLabel;
        TLabel *StopOwnerNameLabel;
        TEdit *StopOwnerEdit;
        TEdit *StopOwnerNameEdit;
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourStopOwnerSimpleProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourStopOwnerSimpleProcessForm *TourStopOwnerSimpleProcessForm;
//---------------------------------------------------------------------------
#endif
