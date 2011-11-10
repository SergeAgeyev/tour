//---------------------------------------------------------------------------

#ifndef BusSimpleAddFormH
#define BusSimpleAddFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "BusSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>

enum TourBusSimpleAddStringsTypes
 {
  TourBusSimpleAddBusFieldExistErrorMessageStr = TourBusSimpleProcessBusStringsCount,
  TourBusSimpleAddBusFieldExistExceptionMessageStr
 };

//---------------------------------------------------------------------------
class TTourBusSimpleAddForm : public TTourBusSimpleProcessForm
{
__published:    // IDE-managed Components
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourBusSimpleAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourBusSimpleAddForm *TourBusSimpleAddForm;
//---------------------------------------------------------------------------
#endif
