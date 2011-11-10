//---------------------------------------------------------------------------

#ifndef TripPreDiagramFormH
#define TripPreDiagramFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TripWizardProcessForm.h"
#include "VStringStorage.h"
#include <ActnList.hpp>
#include <ADODB.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <Menus.hpp>

#include <string>
#include <vector>

using namespace std;

typedef  vector<string>      TripPreDiagramStringVectorType;

//---------------------------------------------------------------------------
class TTourTripPreDiagramForm : public TTourTripWizardProcessForm
{
__published:	// IDE-managed Components
 void __fastcall ChainDeleteItemActionExecute(TObject *Sender);
 void __fastcall AvailableAddActionExecute(TObject *Sender);
 void __fastcall SelectActionExecute(TObject *Sender);
 void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
 void __fastcall ChainPopupMenuPopup(TObject *Sender);
 void __fastcall AvailablePopupMenuPopup(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
protected:	// User declarations
 virtual void FillAvailableStrStore(void);
 virtual void FillAvailableListView(void);
 virtual void FillChainListViewByStrStore(void);
 virtual void ChainStrStoreAppendItem(AnsiString ItemStr);
 virtual void ChainListViewAppendItem(AnsiString ItemStr);
 virtual void ChainStrStoreDeleteItem(void);
 virtual void ChainListViewDeleteItem(void);

 bool GetStopNameByStopId(AnsiString StopIdStr,AnsiString *StopNameStrPtr);

 TripPreDiagramStringVectorType AvailableStrStore;

public:		// User declarations
 __fastcall TTourTripPreDiagramForm(TComponent* Owner);
 TripPreDiagramStringVectorType ChainStrStore;
 virtual void FillChainStrStoreByTrip(AnsiString TripIdStr);
 bool SelectBasicTrip (AnsiString *BasicTripStrPtr = NULL);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripPreDiagramForm *TourTripPreDiagramForm;
//---------------------------------------------------------------------------
#endif
