//---------------------------------------------------------------------------

#ifndef TripNewMasterFormH
#define TripNewMasterFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBLookupComboBoxExt.h"
#include "TripAddForm.h"
#include "VStringStorage.h"
#include <ADODB.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TTourTripNewMasterForm : public TTourTripAddForm
{
__published:	// IDE-managed Components
 TADOQuery *TripQuery;
 TADOQuery *TripOwnerQuery;
 TADOQuery *BusQuery;
 void __fastcall FormCreate(TObject *Sender);
 void __fastcall SaveButtonClick(TObject *Sender);
 void __fastcall FormDestroy(TObject *Sender);
 void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
 __fastcall TTourTripNewMasterForm(TComponent* Owner);
 AnsiString TripIdStr;
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripNewMasterForm *TourTripNewMasterForm;
//---------------------------------------------------------------------------
#endif
