//---------------------------------------------------------------------------

#ifndef TripTourCopyDialogFormH
#define TripTourCopyDialogFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VStringStorage.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>

//---------------------------------------------------------------------------
class TTourTripTourCopyDialogForm : public TForm
{
__published:    // IDE-managed Components
        TButton *OkButton;
 TButton *CancelButton;
 TVStringStorage *VStringStorage;
        TLabel *TripIdLabel;
        TEdit *TripIdEdit;
        TLabel *TripNameLabel;
        TEdit *TripNameEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:        // User declarations
public:         // User declarations
 __fastcall TTourTripTourCopyDialogForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripTourCopyDialogForm *TourTripTourCopyDialogForm;
//---------------------------------------------------------------------------
#endif
