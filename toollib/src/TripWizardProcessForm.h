//---------------------------------------------------------------------------

#ifndef TripWizardProcessFormH
#define TripWizardProcessFormH
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

enum TourTripWizardStringTypes
 {
  TourTripWizardTripSelectCaptionStr = 0,
  TourTripWizardStringTypesEnumCount
 };

//---------------------------------------------------------------------------
class TTourTripWizardProcessForm : public TForm
{
__published:    // IDE-managed Components
 TListView *ChainListView;
 TListView *AvailableListView;
 TButton *CancelButton;
 TButton *NextButton;
 TButton *SelectButton;
 TLabel *ChainLabel;
 TLabel *AvailableLabel;
 TADOQuery *ToAvailableQuery;
 TActionList *ActionList;
 TAction *ChainDeleteItemAction;
 TAction *AvailableAddAction;
 TAction *SelectAction;
 TVStringStorage *VStringStorage;
        TADOQuery *TripQuery;
 TADOQuery *TripStepQuery;
 TADOQuery *StopQuery;
 TADOQuery *FromAvailableQuery;
 TBitBtn *DeleteButton;
 TBitBtn *AddButton;
 TPopupMenu *AvailablePopupMenu;
 TPopupMenu *ChainPopupMenu;
 TMenuItem *DeleteMenuItem;
 TMenuItem *AddMenuItem;
        void __fastcall ChainListViewKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall AvailableListViewKeyDown(TObject *Sender,
          WORD &Key, TShiftState Shift);
        void __fastcall ChainPopupMenuPopup(TObject *Sender);
        void __fastcall AvailablePopupMenuPopup(TObject *Sender);
        void __fastcall AvailableListViewColumnClick(TObject *Sender,
          TListColumn *Column);
        void __fastcall AvailableListViewCompare(TObject *Sender,
          TListItem *Item1, TListItem *Item2, int Data, int &Compare);
        void __fastcall AvailableListViewInsert(TObject *Sender,
          TListItem *Item);

private:        // User declarations
 bool                                  AvailableColumnSortIncreaseFlag;
 int                                   AvailableColumnToSort;
protected:
public:         // User declarations
/*
 AnsiString                            BasicTripIdStr;
 bool                                  BasicTripExistFlag;
*/ 
 __fastcall TTourTripWizardProcessForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripWizardProcessForm *TourTripWizardProcessForm;
//---------------------------------------------------------------------------
#endif
