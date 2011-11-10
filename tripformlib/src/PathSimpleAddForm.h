//---------------------------------------------------------------------------

#ifndef PathSimpleAddFormH
#define PathSimpleAddFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "PathSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>
#include "RxGrdCpt.h"
#include "VCustomKeyComboBox.h"
#include "VMemoKeyComboBox.h"

enum TourPathSimpleAddStringsTypes
 {
  TourPathSimpleAddPathFieldExistErrorMessageStr = TourPathSimpleProcessPathStringsCount,
  TourPathSimpleAddPathFieldExistExceptionMessageStr
 };

//---------------------------------------------------------------------------
class TTourPathSimpleAddForm : public TTourPathSimpleProcessForm
{
__published:    // IDE-managed Components
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourPathSimpleAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourPathSimpleAddForm *TourPathSimpleAddForm;
//---------------------------------------------------------------------------
#endif
