//---------------------------------------------------------------------------

#ifndef TripDiagramChangesFormH
#define TripDiagramChangesFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VStringStorage.h"

#include <vector>
#include "TourDataCU.h"
//---------------------------------------------------------------------------
class TTourDiagramChangesForm : public TForm
{
__published:	// IDE-managed Components
        TScrollBox *ScrollBox;
        TButton *OkButton;
        TButton *CancelButton;
        TVStringStorage *VStringStorage;
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:
        TourCachedUpdateDataClass* FChangesList;	// User declarations
 void __fastcall   SetChangesList
                   (TourCachedUpdateDataClass        *value);
 void __fastcall   SetInterval
                   (unsigned int                      value);
 void              FillCheckBoxStorage (void);
 void              AppendChangeToList
                   (unsigned int                      CheckBoxIndex);

 TourCachedUpdateDataClass            *CachedUpdateDataStoragePtr;
 unsigned int                          FInterval;
public:		// User declarations
        __fastcall TTourDiagramChangesForm(TComponent* Owner);

 __property TourCachedUpdateDataClass* ChangesList = { write=SetChangesList };
 __property unsigned int Interval  = { write=SetInterval };
 std::vector<TCheckBox*>               CheckBoxStorage;
};
//---------------------------------------------------------------------------
extern PACKAGE TTourDiagramChangesForm *TourDiagramChangesForm;
//---------------------------------------------------------------------------
#endif
