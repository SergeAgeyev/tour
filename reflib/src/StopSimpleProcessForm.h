//---------------------------------------------------------------------------

#ifndef StopSimpleProcessFormH
#define StopSimpleProcessFormH
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

enum TourStopSimpleProcessStringsTypes
 {
  TourStopSimpleProcessStopFieldEmptyErrorMessageStr = TourSimpleProcessStringsCount,
  TourStopSimpleProcessStopFieldEmptyExceptionMessageStr,
  TourStopSimpleProcessCityFieldEmptyErrorMessageStr,
  TourStopSimpleProcessCityFieldEmptyExceptionMessageStr,
  TourStopSimpleProcessCityNotExistErrorMessageStr,
  TourStopSimpleProcessCityNotExistExceptionMessageStr,
  TourStopSimpleProcessCityListCaptionStr,
  TourStopSimpleProcessCityIdStr,
  TourStopSimpleProcessCityNameStr,
  TourStopSimpleProcessAddCityActionErrorMessageStr,
  TourStopSimpleProcessAddStopModelActionErrorMessageStr,
  TourStopSimpleProcessAddStopOwnerActionErrorMessageStr,
  TourStopSimpleProcessAddActionExceptionMessageStr,
  TourStopSimpleProcessStopStringsCount
 };

typedef struct
 {
  AnsiString IdStr;
  AnsiString NameStr;
 } TourStopSimpleProcessCityRecordLookupType;

//---------------------------------------------------------------------------
class TTourStopSimpleProcessForm : public TTourSimpleProcessForm
{
__published:    // IDE-managed Components
        TLabel *StopLabel;
        TLabel *StopNameLabel;
        TLabel *CityZIPLabel;
        TEdit *StopIdEdit;
        TEdit *StopNameEdit;
        TEdit *CityZIPEdit;
        TLabel *StopModelLabel;
        TVMemoKeyComboBox *StopModelVMemoKeyComboBox;
        TLabel *StopOwnerLabel;
        TVMemoKeyComboBox *StopOwnerVMemoKeyComboBox;
        TButton *CityZIPButton;
        TButton *AddCityButton;
        TButton *AddStopOwnerButton;
        TButton *AddStopModelButton;
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall CityZIPButtonClick(TObject *Sender);
        void __fastcall AddCityButtonClick(TObject *Sender);
        void __fastcall AddStopOwnerButtonClick(TObject *Sender);
        void __fastcall AddStopModelButtonClick(TObject *Sender);
private:        // User declarations
public:         // User declarations
        __fastcall TTourStopSimpleProcessForm(TComponent* Owner);
        std::vector<TourStopSimpleProcessCityRecordLookupType> CityStorage;
};
//---------------------------------------------------------------------------
extern PACKAGE TTourStopSimpleProcessForm *TourStopSimpleProcessForm;
//---------------------------------------------------------------------------
#endif
