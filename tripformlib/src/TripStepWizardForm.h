//---------------------------------------------------------------------------

#ifndef TripStepWizardFormH
#define TripStepWizardFormH
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

typedef struct
 {
  AnsiString       StopIdStr;
  AnsiString       TripStepInTimeStr;
  AnsiString       TripStepWaitTimeStr;
 } TripStepWizardItemType;

typedef  vector<TripStepWizardItemType>     TripStepWizardItemStoreVectorType;

enum TourTripStepWizardStringTypes
 {
  TourTripStepWizardTripIdCaptionStr = TourTripWizardStringTypesEnumCount,
  TourTripStepWizardTripNameCaptionStr,
  TourTripStepWizardTripNotesCaptionStr,
  TourTripStepWizardStringTypesEnumCount
 };

//---------------------------------------------------------------------------
class TTourTripStepWizardForm : public TTourTripWizardProcessForm
{
__published:	// IDE-managed Components
 TAction *TripStepEditAction;
 TADOQuery *TripStepInfoQuery;
 TAction *SaveAction;
        TADOQuery *TimeInInfoQuery;
        TMenuItem *ChangeMenuItem;
        TADOQuery *TimeInInfoSimpleQuery;
        TADOQuery *TripStepClearQuery;
 void __fastcall ChainDeleteItemActionExecute(TObject *Sender);
 void __fastcall AvailableAddActionExecute(TObject *Sender);
 void __fastcall SelectActionExecute(TObject *Sender);
 void __fastcall ChainPopupMenuPopup(TObject *Sender);
 void __fastcall AvailablePopupMenuPopup(TObject *Sender);
 void __fastcall TripStepEditActionExecute(TObject *Sender);
 void __fastcall SaveActionExecute(TObject *Sender);
 void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
protected:	// User declarations
 virtual void FillAvailableStrStore(void);
 virtual void FillAvailableListView(void);
 virtual void FillChainListViewByStrStore(void);
 virtual bool ChainStrStoreAppendItem(TripStepWizardItemType Item);
 virtual void ChainListViewAppendItem(TripStepWizardItemType Item);
 virtual void ChainStrStoreDeleteItem(void);
 virtual void ChainListViewDeleteItem(void);
 virtual TDateTime GetPreliminaryTimeIn
                   (AnsiString                        FromStopIdStr,
                    AnsiString                        ToStopIdStr);

 bool              GetStopNameByStopId
                   (AnsiString                        StopIdStr,
                    AnsiString                       *StopNameStrPtr);
 bool              GetTripStepInfoByStepNum
                   (AnsiString                        TripIdStr,
                    AnsiString                        StepNumStr,
                    AnsiString                       *StepInTimeStrPtr,
                    AnsiString                       *StepWaitTimeStrPtr);

 TripStepWizardItemStoreVectorType     AvailableStrStore;
private:
 int               DateTimeInfoWaitCodeByValue
                   (char                             *ValueStrPtr);
 AnsiString        DateTimeInfoWaitValueByCode
                   (int                               Code);
 bool              BusModelExist
                   (AnsiString                        TripIdStr);

 AnsiString                           CurrentTripIdStr;

 void __fastcall   SetBaseTripId
                   (AnsiString                        value);
/*
 AnsiString __fastcall
                   GetBaseTripIdStr                  (void);
*/
 void __fastcall   SetCurrentTripId
                   (AnsiString                        value);
 AnsiString __fastcall
                   GetCurrentTripId                  (void);

public:		// User declarations
 __fastcall        TTourTripStepWizardForm
                   (TComponent                       *Owner);

 TripStepWizardItemStoreVectorType    ChainStrStore;

 virtual bool      FillChainStrStoreByTrip
                   (AnsiString                        TripIdStr);
 // Обновление содержимого таблицы tripstep
 // TripIdStr - номер рейса
 // TripStepStrStorePtr - последовательность пунктов маршрута
 // c использованием транзакции
 bool              UpdateTripStepTable
                   (AnsiString                        TripIdStr,
                    TripStepWizardItemStoreVectorType
                                                     *TripStepStrStorePtr);
 // -"- без использования транзакции
 bool              UpdateTripStepTableLow
                   (AnsiString                        TripIdStr,
                    TripStepWizardItemStoreVectorType
                                                     *TripStepStrStorePtr);
 // последовательность пунктов маршрута берется из ChainStrStore;
 // c использованием транзакции
 bool              UpdateTripStepTable
                   (AnsiString                        TripIdStr);
 // -"- без использования транзакции
 bool              UpdateTripStepTableLow
                   (AnsiString                        TripIdStr);
 // номер рейса берется из CurrentTripIdStr
 // последовательность пунктов маршрута берется из ChainStrStore;
 // c использованием транзакции
 bool              UpdateTripStepTable (void);
 // -"- без использования транзакции
 bool              UpdateTripStepTableLow
                   (void);

 void              Clear               (void);

 __property AnsiString
                   BaseTripId  = {/* read=GetBaseTripIdStr, */write=SetBaseTripId };
 __property AnsiString
                   CurrentTripId  = { read=GetCurrentTripId, write=SetCurrentTripId };
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripStepWizardForm *TourTripStepWizardForm;
//---------------------------------------------------------------------------
#endif
