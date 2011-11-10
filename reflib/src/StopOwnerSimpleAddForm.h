//---------------------------------------------------------------------------

#ifndef StopOwnerSimpleAddFormH
#define StopOwnerSimpleAddFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StopOwnerSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>

enum TourStopOwnerSimpleAddStringsTypes
 {
  TourStopOwnerSimpleAddStopOwnerFieldExistErrorMessageStr = TourStopOwnerSimpleProcessStopOwnerStringsCount,
  TourStopOwnerSimpleAddStopOwnerFieldExistExceptionMessageStr
 };

//---------------------------------------------------------------------------
class TTourStopOwnerSimpleAddForm : public TTourStopOwnerSimpleProcessForm
{
__published:    // IDE-managed Components
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourStopOwnerSimpleAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourStopOwnerSimpleAddForm *TourStopOwnerSimpleAddForm;
//---------------------------------------------------------------------------
#endif
