//---------------------------------------------------------------------------

#ifndef StopModelSimpleProcessFormH
#define StopModelSimpleProcessFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>

enum TourStopModelSimpleProcessStringsTypes
 {
  TourStopModelSimpleProcessStopModelFieldEmptyErrorMessageStr = TourSimpleProcessStringsCount,
  TourStopModelSimpleProcessStopModelFieldEmptyExceptionMessageStr,
  TourStopModelSimpleProcessStopModelStringsCount
 };

//---------------------------------------------------------------------------
class TTourStopModelSimpleProcessForm : public TTourSimpleProcessForm
{
__published:    // IDE-managed Components
        TLabel *StopModelLabel;
        TLabel *StopModelNameLabel;
        TEdit *StopModelEdit;
        TEdit *StopModelNameEdit;
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
        __fastcall TTourStopModelSimpleProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourStopModelSimpleProcessForm *TourStopModelSimpleProcessForm;
//---------------------------------------------------------------------------
#endif
