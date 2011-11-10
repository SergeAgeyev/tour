//---------------------------------------------------------------------------
#ifndef RepStopInfoInputFormH
#define RepStopInfoInputFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RXDBCtrl.h"
#include "VADODataSourceOrdering.h"
#include "VCustomDataSourceOrdering.h"
#include "VDBSortGrid.h"
#include <ADODB.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "Placemnt.h"
//---------------------------------------------------------------------------
class TTourRepStopInfoInputForm : public TForm
 {
  __published:	             // IDE-managed Components
  TButton                   *CreateReportButton;
  TButton                   *CancelButton;
  TADOQuery                 *StopQuery;
  TDataSource               *StopDataSource;
  TVADODataSourceOrdering   *StopDataSourceOrdering;
  TVDBSortGrid              *StopGrid;
  TStringField              *StopQueryStop_Id;
  TStringField              *StopQueryStop_Name;

  void   __fastcall          FormCreate                   (TObject     *Sender);
  void   __fastcall          FormDestroy                  (TObject     *Sender);

  void   __fastcall          CreateReportButtonClick      (TObject     *Sender);
  void   __fastcall          StopGridDblClick             (TObject     *Sender);
  void   __fastcall          StopGridKeyDown              (TObject     *Sender,
                                                           WORD        &Key,
                                                           TShiftState  Shift);
  private:	             // User declarations
  public:	             // User declarations
         __fastcall          TTourRepStopInfoInputForm    (TComponent  *Owner);
 };
//---------------------------------------------------------------------------
extern PACKAGE TTourRepStopInfoInputForm *TourRepStopInfoInputForm;
//---------------------------------------------------------------------------
#endif
