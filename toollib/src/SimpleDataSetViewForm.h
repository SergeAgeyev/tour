//---------------------------------------------------------------------------

#ifndef SimpleDataSetViewFormH
#define SimpleDataSetViewFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SimpleProcessForm.h"
#include "VStringStorage.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTourSimpleDataSetViewForm : public TTourSimpleProcessForm
{
__published:	// IDE-managed Components
        TListView *ListView;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TTourSimpleDataSetViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourSimpleDataSetViewForm *TourSimpleDataSetViewForm;
//---------------------------------------------------------------------------
#endif
