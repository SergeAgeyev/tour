//---------------------------------------------------------------------------

#ifndef BusSimpleProcessFormH
#define BusSimpleProcessFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>

enum TourBusSimpleProcessStringsTypes
 {
  TourBusSimpleProcessBusFieldEmptyErrorMessageStr = TourSimpleProcessStringsCount,
  TourBusSimpleProcessBusFieldEmptyExceptionMessageStr,
  TourBusSimpleProcessBusStringsCount
 };

//---------------------------------------------------------------------------
class TTourBusSimpleProcessForm : public TTourSimpleProcessForm
{
__published:    // IDE-managed Components
        TLabel *BusModelLabel;
        TLabel *BusDescLabel;
        TLabel *BusSpeedFactorLabel;
        TLabel *BusCapaBusLabel;
        TEdit *BusModelEdit;
        TEdit *BusDescEdit;
        TEdit *BusSpeedFactorEdit;
        TEdit *BusCapacityEdit;
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourBusSimpleProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourBusSimpleProcessForm *TourBusSimpleProcessForm;
//---------------------------------------------------------------------------
#endif
