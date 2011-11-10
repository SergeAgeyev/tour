//---------------------------------------------------------------------------

#ifndef TripStepDataTimeInfoFormH
#define TripStepDataTimeInfoFormH
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

enum TourTripStepDataTimeInfoWaitTimeCodesType
 {
  TourTripStepDataTimeInfoWaitTimeNoEntryCode = 0,
  TourTripStepDataTimeInfoWaitTimeNoStopCode,
  TourTripStepDataTimeInfoWaitTime5MinWaitCode,
  TourTripStepDataTimeInfoWaitTimeUserWaitCode,
  TourTripStepDataTimeInfoWaitTime10MinWaitCode,
  TourTripStepDataTimeInfoWaitTime15MinWaitCode,
  TourTripStepDataTimeInfoWaitTime20MinWaitCode,
  TourTripStepDataTimeInfoWaitTimeCodeCount
 };

//---------------------------------------------------------------------------
class TTourTripStepDataTimeInfoForm : public TForm
{
__published:	// IDE-managed Components
 TButton *SaveButton;
 TButton *CancelButton;
 TVStringStorage *VStringStorage;
        TRadioGroup *WaitTimeRadioGroup;
        TLabel *InTimeLabel;
        TShortTimePicker *TimeInPicker;
        TShortTimePicker *TimeWaitPicker;
        void __fastcall WaitTimeRadioGroupClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
 __fastcall TTourTripStepDataTimeInfoForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripStepDataTimeInfoForm *TourTripStepDataTimeInfoForm;
//---------------------------------------------------------------------------
#endif
