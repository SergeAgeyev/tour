//---------------------------------------------------------------------------

#ifndef TripSwitchDialogFormH
#define TripSwitchDialogFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <ActnList.hpp>
#include "VStringStorage.h"
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include "Placemnt.h"

enum TourTripWizardStringTypes
 {
  TourTripWizardTripSelectCaptionStr = 0,
  TourTripWizardStringTypesEnumCount
 };

//---------------------------------------------------------------------------
class TTourTripSwitchDialogForm : public TForm
{
__published:    // IDE-managed Components
        TListView *TourListView;
        TPanel *Panel;
        TVStringStorage *VStringStorage;
        TActionList *ActionList;
        TButton *NextButton;
        TButton *CancelButton;
        TFormStorage *FormStorage;
        void __fastcall TourListViewColumnClick(TObject *Sender,
          TListColumn *Column);
        void __fastcall TourListViewCompare(TObject *Sender,
          TListItem *Item1, TListItem *Item2, int Data, int &Compare);
        void __fastcall TourListViewChange(TObject *Sender,
          TListItem *Item, TItemChange Change);
        void __fastcall TourListViewChanging(TObject *Sender,
          TListItem *Item, TItemChange Change, bool &AllowChange);
        void __fastcall PanelResize(TObject *Sender);

private:        // User declarations

 bool                                  ColumnSortIncreaseFlag;
 int                                   ColumnToSort;

 bool ListItemChangeIgnoreFlag;
 bool ListItemCheckedFlag;
protected:
public:         // User declarations
 __fastcall TTourTripSwitchDialogForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripSwitchDialogForm *TourTripSwitchDialogForm;
//---------------------------------------------------------------------------
#endif
