//---------------------------------------------------------------------------

#ifndef StatsProcessFormH
#define StatsProcessFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TableGridProcessForm.h"
#include "VStringStorage.h"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "DBLookupComboBoxExt.h"
#include <ComCtrls.hpp>
#include <ADODB.hpp>
//---------------------------------------------------------------------------
class TTourStatsProcessForm : public TTourRefBookTableGridProcessForm
{
__published:    // IDE-managed Components
 TLabel *TripIdLabel;
 TDBEdit *TripIdDBEdit;
 TLabel *StatsFromStopIdLabel;
 TLabel *StatsFlowLabel;
 TDBEdit *StatsFlowDBEdit;
 TDBLookupComboBoxExt *StatsFromStopIdDBLookupComboBoxExt;
 TLabel *StatsToStopIdIdLabel;
 TDBLookupComboBoxExt *StatsToStopIdDBLookupComboBoxExt;
 TDataSource *TripDataSource;
 TDataSource *StopDataSource;
 TButton *TripIdButton;
 TDateTimePicker *StatsDatePicker;
 TLabel *StatsDateLabel;
 TDateTimePicker *StatsTimePicker;
 TLabel *StatsTimeLabel;
 TADOQuery *DirectQuery;
 TDataSource *DirectDataSource;
        TADOQuery *FromStopQuery;
        TDataSource *FromStopDataSource;
 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
 void __fastcall TripIdButtonClick(TObject *Sender);
 void __fastcall TripIdDBEditExit(TObject *Sender);
        void __fastcall FMainQueryDataSourceDataChange(TObject *Sender,
          TField *Field);
        void __fastcall TripIdDBEditChange(TObject *Sender);
        void __fastcall TripIdDBEditEnter(TObject *Sender);
private:        // User declarations
 bool TripIdChangedFlag;
protected:
public:         // User declarations
 __fastcall TTourStatsProcessForm(TComponent* Owner);
 void OnStatsFromStopIdFieldChanged(TField *Field);
 void OnStatsTripIdFieldChanged(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourStatsProcessForm *TourStatsProcessForm;
//---------------------------------------------------------------------------
#endif
