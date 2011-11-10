//---------------------------------------------------------------------------
#ifndef RepTripInfoResultFormH
#define RepTripInfoResultFormH
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
class TTourTripInfoResultForm : public TForm
 {
  __published:	     // IDE-managed Components
  TADOQuery          *ReportQuery;
  TQuickRep          *Report;
  TQRBand            *TitleBand;
  TQRBand            *DetailBand;
  TQRBand            *SummaryBand;
  TQRLabel           *TripIdLabel;
  TQRLabel           *BasModelLabel;
  TQRLabel           *FirstTitleDelimeterLabel;
  TQRLabel           *SecondTitleDelimeterLabel;
  TQRLabel           *StopIdFirstLabel;
  TQRLabel           *TripStepInTimeFirstTitleLabel;
  TQRLabel           *TripStepWaitTimeFirstTitleLabel;
  TQRLabel           *TripStepOutTimeFirstTitleLabel;
  TQRLabel           *SummaryDelimeterLabel;
  TQRLabel           *TripStepInTimeLabel;
  TQRLabel           *TripStepWaitTimeLabel;
  TQRLabel           *TripStepOutTimeLabel;
  TQRLabel           *PathLengthFirstTitleLabel;
  TQRLabel           *StopIdSecondLabel;
  TQRLabel           *TripStepInTimeSecondTitleLabel;
  TQRLabel           *TripStepOutTimeSecondTitleLabel;
  TQRLabel           *TripStepWaitTimeSecondTitleLabel;
  TQRLabel           *PathLengthSecondTitleLabel;
  TQRLabel           *PathLengthLabel;
  TQRDBText          *BusModelDBText;
  TQRDBText          *TripIdDBText;
  TQRDBText          *StopIdDBText;
  TQRDBText          *TripNameDBText;

  void   __fastcall   DetailBandBeforePrint  (TQRCustomBand *Sender,bool &PrintBand);
  void   __fastcall   DetailBandAfterPrint   (TQRCustomBand *Sender,bool BandPrinted);

  private:	      // User declarations
  int                 PathLength;

  public:	      // User declarations
         __fastcall   TTourTripInfoResultForm(TComponent* Owner);
 };
//---------------------------------------------------------------------------
extern PACKAGE TTourTripInfoResultForm *TourTripInfoResultForm;
//---------------------------------------------------------------------------
#endif
