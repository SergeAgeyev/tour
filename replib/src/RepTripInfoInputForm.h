//---------------------------------------------------------------------------
#ifndef RepTripInfoInputFormH
#define RepTripInfoInputFormH
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
class TTourRepTripInfoInputForm : public TForm
 {
  __published:	             // IDE-managed Components
  TButton                   *CreateReportButton;
  TButton                   *CancelButton;
  TADOQuery                 *TripQuery;
  TDataSource               *TripDataSource;
  TVADODataSourceOrdering   *TripDataSourceOrdering;
  TVDBSortGrid              *TripGrid;
  TStringField              *TripQueryTrip_Id;
  TStringField              *TripQueryTrip_Name;
  TStringField              *TripQueryBus_Model;

  void   __fastcall          FormCreate                   (TObject     *Sender);
  void   __fastcall          FormDestroy                  (TObject     *Sender);

  void   __fastcall          CreateReportButtonClick      (TObject     *Sender);
  void   __fastcall          TripGridDblClick             (TObject     *Sender);
  void   __fastcall          TripGridKeyDown              (TObject     *Sender,
                                                           WORD        &Key,
                                                           TShiftState  Shift);
  private:	             // User declarations
  public:	             // User declarations
         __fastcall          TTourRepTripInfoInputForm    (TComponent  *Owner);
 };
//---------------------------------------------------------------------------
extern PACKAGE TTourRepTripInfoInputForm *TourRepTripInfoInputForm;
//---------------------------------------------------------------------------
#endif
