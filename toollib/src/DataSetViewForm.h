//---------------------------------------------------------------------------

#ifndef DataSetViewFormH
#define DataSetViewFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "RXDBCtrl.h"
#include "VADODataSourceOrdering.h"
#include "VCustomDataSourceOrdering.h"
#include "VDBSortGrid.h"
//---------------------------------------------------------------------------
class TTourDataSetViewForm : public TForm
{
__published:    // IDE-managed Components
        TButton *OkButton;
        TButton *CancelButton;
        TDataSource *DataSource;
 TVDBSortGrid *Grid;
 TVADODataSourceOrdering *DataSourceOrdering;
private:        // User declarations
public:         // User declarations
        __fastcall TTourDataSetViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourDataSetViewForm *TourDataSetViewForm;
//---------------------------------------------------------------------------
#endif
