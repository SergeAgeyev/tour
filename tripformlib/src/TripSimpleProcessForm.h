//---------------------------------------------------------------------------

#ifndef TripSimpleProcessFormH
#define TripSimpleProcessFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>
#include "RxGrdCpt.h"
#include "VCustomKeyComboBox.h"
#include "VMemoKeyComboBox.h"

#include <vector>

enum TourTripSimpleProcessStringsTypes
 {
  TourTripSimpleProcessTripFieldEmptyErrorMessageStr = TourSimpleProcessStringsCount,
  TourTripSimpleProcessTripFieldEmptyExceptionMessageStr,
  TourTripSimpleProcessAddBusActionErrorMessageStr,
  TourTripSimpleProcessAddTripOwnerActionErrorMessageStr,
  TourTripSimpleProcessAddActionExceptionMessageStr,
  TourTripSimpleProcessTripStringsCount
 };
/*
typedef struct
 {
  AnsiString IdStr;
  AnsiString NameStr;
 } TourTripSimpleProcessCityRecordLookupType;
*/
//---------------------------------------------------------------------------
class TTourTripSimpleProcessForm : public TTourSimpleProcessForm
{
__published:    // IDE-managed Components
        TLabel *TripLabel;
        TLabel *TripNotesLabel;
        TEdit *TripIdEdit;
        TEdit *TripNotesEdit;
        TLabel *BusModelLabel;
        TVMemoKeyComboBox *BusModelVMemoKeyComboBox;
        TLabel *TripOwnerLabel;
        TVMemoKeyComboBox *TripOwnerVMemoKeyComboBox;
        TLabel *TripNameLabel;
        TEdit *TripNameEdit;
        TButton *AddBusButton;
        TButton *AddTripOwnerButton;
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall AddBusButtonClick(TObject *Sender);
        void __fastcall AddTripOwnerButtonClick(TObject *Sender);
//        void __fastcall CityZIPButtonClick(TObject *Sender);
private:        // User declarations
public:         // User declarations
        __fastcall TTourTripSimpleProcessForm(TComponent* Owner);
/*
        std::vector<TourTripSimpleProcessCityRecordLookupType> CityStorage;
*/
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripSimpleProcessForm *TourTripSimpleProcessForm;
//---------------------------------------------------------------------------
#endif
