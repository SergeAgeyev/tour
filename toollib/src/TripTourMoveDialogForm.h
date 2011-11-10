//---------------------------------------------------------------------------

#ifndef TripTourMoveDialogFormH
#define TripTourMoveDialogFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VStringStorage.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "ShortTimePicker.h"
#include <Mask.hpp>

//---------------------------------------------------------------------------
class TTourTripTourMoveDialogForm : public TForm
{
__published:    // IDE-managed Components
        TButton *OkButton;
 TButton *CancelButton;
 TVStringStorage *VStringStorage;
        TLabel *TimeStartLabel;
        TCheckBox *TourCopyCheckBox;
        TShortTimePicker *TimeStartPicker;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:        // User declarations
public:         // User declarations
 __fastcall TTourTripTourMoveDialogForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripTourMoveDialogForm *TourTripTourMoveDialogForm;
//---------------------------------------------------------------------------
#endif
