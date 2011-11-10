//---------------------------------------------------------------------------

#ifndef StopModelSimpleAddFormH
#define StopModelSimpleAddFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StopModelSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>

enum TourStopModelSimpleAddStringsTypes
 {
  TourStopModelSimpleAddStopModelFieldExistErrorMessageStr = TourStopModelSimpleProcessStopModelStringsCount,
  TourStopModelSimpleAddStopModelFieldExistExceptionMessageStr
 };

//---------------------------------------------------------------------------
class TTourStopModelSimpleAddForm : public TTourStopModelSimpleProcessForm
{
__published:    // IDE-managed Components
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourStopModelSimpleAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourStopModelSimpleAddForm *TourStopModelSimpleAddForm;
//---------------------------------------------------------------------------
#endif
