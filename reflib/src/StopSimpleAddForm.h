//---------------------------------------------------------------------------

#ifndef StopSimpleAddFormH
#define StopSimpleAddFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StopSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>
#include "RxGrdCpt.h"
#include "VCustomKeyComboBox.h"
#include "VMemoKeyComboBox.h"

enum TourStopSimpleAddStringsTypes
 {
  TourStopSimpleAddStopFieldExistErrorMessageStr = TourStopSimpleProcessStopStringsCount,
  TourStopSimpleAddStopFieldExistExceptionMessageStr
 };

//---------------------------------------------------------------------------
class TTourStopSimpleAddForm : public TTourStopSimpleProcessForm
{
__published:    // IDE-managed Components
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourStopSimpleAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourStopSimpleAddForm *TourStopSimpleAddForm;
//---------------------------------------------------------------------------
#endif
