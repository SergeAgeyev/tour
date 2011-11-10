//---------------------------------------------------------------------------

#ifndef TripTimetableRecalcBySpeedFormH
#define TripTimetableRecalcBySpeedFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VStringStorage.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>

//---------------------------------------------------------------------------
class TTourTripTimetableRateSpeedForm : public TForm
{
__published:    // IDE-managed Components
 TButton *SaveButton;
 TButton *CancelButton;
 TVStringStorage *VStringStorage;
        TLabel *RateSpeedLabel;
        TComboBox *RateSpeedComboBox;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:        // User declarations
public:         // User declarations
 __fastcall TTourTripTimetableRateSpeedForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripTimetableRateSpeedForm *TourTripTimetableRateSpeedForm;
//---------------------------------------------------------------------------
#endif
