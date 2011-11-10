//---------------------------------------------------------------------------

#ifndef TripTimetableInfoFormH
#define TripTimetableInfoFormH
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
class TTourTripTimetableInfoForm : public TForm
{
__published:    // IDE-managed Components
 TButton *SaveButton;
 TButton *CancelButton;
 TVStringStorage *VStringStorage;
        TLabel *InTimeLabel;
        TLabel *TimeOutLabel;
        TLabel *TimeWaitLabel;
        TShortTimePicker *TimeInShortTimePicker;
        TShortTimePicker *TimeWaitShortTimePicker;
        TShortTimePicker *TimeOutShortTimePicker;
        TCheckBox *WaitTimeEmptyCheckBox;
        void __fastcall TimeOutShortTimePickerTimeChange(TObject *Sender);
        void __fastcall TimeWaitShortTimePickerTimeChange(TObject *Sender);
        void __fastcall WaitTimeEmptyCheckBoxClick(TObject *Sender);
        void __fastcall TimeInShortTimePickerTimeChange(TObject *Sender);
private:        // User declarations
public:         // User declarations
 __fastcall TTourTripTimetableInfoForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripTimetableInfoForm *TourTripTimetableInfoForm;
//---------------------------------------------------------------------------
#endif
