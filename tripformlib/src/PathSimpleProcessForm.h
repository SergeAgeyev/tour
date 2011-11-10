//---------------------------------------------------------------------------

#ifndef PathSimpleProcessFormH
#define PathSimpleProcessFormH
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

enum TourPathSimpleProcessStringsTypes
 {
  TourPathSimpleProcessBeginPathFieldEmptyErrorMessageStr = TourSimpleProcessStringsCount,
  TourPathSimpleProcessBeginPathFieldEmptyExceptionMessageStr,
  TourPathSimpleProcessEndPathFieldEmptyErrorMessageStr,
  TourPathSimpleProcessEndPathFieldEmptyExceptionMessageStr,
  TourPathSimpleProcessStopNotExistErrorMessageStr,
  TourPathSimpleProcessStopNotExistExceptionMessageStr,
  TourPathSimpleProcessInvalidPathErrorMessageStr,
  TourPathSimpleProcessInvalidPathExceptionMessageStr,
  TourPathSimpleProcessStopListCaptionStr,
  TourPathSimpleProcessStopIdStr,
  TourPathSimpleProcessStopNameStr,
  TourPathSimpleProcessAddCityActionErrorMessageStr,
  TourPathSimpleProcessAddActionExceptionMessageStr,
  TourPathSimpleProcessPathStringsCount
 };

typedef struct
 {
  AnsiString IdStr;
  AnsiString NameStr;
 } TourPathSimpleProcessStopRecordLookupType;

//---------------------------------------------------------------------------
class TTourPathSimpleProcessForm : public TTourSimpleProcessForm
{
__published:    // IDE-managed Components
        TLabel *SpeedLabel;
        TLabel *LengthLabel;
        TLabel *ToStopIdLabel;
        TEdit *SpeedEdit;
        TEdit *LengthEdit;
        TEdit *ToStopIdEdit;
        TButton *ToStopIdButton;
        TLabel *FromStopIdLabel;
        TEdit *FromStopIdEdit;
        TButton *FromStopIdButton;
        TButton *AddCityButton;
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall FromStopIdButtonClick(TObject *Sender);
        void __fastcall ToStopIdButtonClick(TObject *Sender);
        void __fastcall AddCityButtonClick(TObject *Sender);
private:        // User declarations
 AnsiString GetStopId(void);
public:         // User declarations
        __fastcall TTourPathSimpleProcessForm(TComponent* Owner);
        std::vector<TourPathSimpleProcessStopRecordLookupType> StopStorage;
};
//---------------------------------------------------------------------------
extern PACKAGE TTourPathSimpleProcessForm *TourPathSimpleProcessForm;
//---------------------------------------------------------------------------
#endif
