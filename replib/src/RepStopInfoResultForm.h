//---------------------------------------------------------------------------
#ifndef RepStopInfoResultFormH
#define RepStopInfoResultFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <Qrctrls.hpp>
//---------------------------------------------------------------------------
class TTourStopInfoResultForm : public TForm
 {
  __published:	       // IDE-managed Components
  TADOQuery            *ReportQuery;
  TQuickRep            *Report;
  TQRBand              *TitleBand;
  TQRBand              *DetailBand;
  TQRBand              *SummaryBand;
  TQRLabel             *StopIdLabel;
  TQRLabel             *FirstTitleDelimeterLabel;
  TQRLabel             *SecondTitleDelimeterLabel;
  TQRLabel             *SummaryDelimeterLabel;
  TQRLabel             *TripIdFirstLabel;
  TQRLabel             *TripNameFirstLabel;
  TQRLabel             *TripStepInTimeFirstTitleLabel;
  TQRLabel             *TripStepWaitTimeFirstTitleLabel;
  TQRLabel             *TripStepOutTimeFirstTitleLabel;
  TQRLabel             *TripIdSecondLabel;
  TQRLabel             *TripNameSecondLabel;
  TQRLabel             *TripStepInTimeSecondTitleLabel;
  TQRLabel             *TripStepOutTimeSecondTitleLabel;
  TQRLabel             *TripStepWaitTimeSecondTitleLabel;
  TQRLabel             *TripStepOutTimeLabel;
  TQRLabel             *TripStepInTimeLabel;
  TQRLabel             *TripStepWaitTimeLabel;
  TQRDBText            *StopIdDBText;
  TQRDBText            *StopNameDBText;
  TQRDBText            *TripIdDBText;
  TQRDBText            *TripNameDBText;

  void    __fastcall    DetailBandBeforePrint
                        (TQRCustomBand *Sender,
                         bool          &PrintBand);

  private:	        // User declarations
  bool                  OutZeroTripStepWaitTimeFlag;

  public:		// User declarations
           __fastcall   TTourStopInfoResultForm
                        (TComponent    *Owner,
                         bool           OutZeroTripStepWaitTimeFlag);
 };
//---------------------------------------------------------------------------
extern PACKAGE TTourStopInfoResultForm *TourStopInfoResultForm;
//---------------------------------------------------------------------------
#endif
