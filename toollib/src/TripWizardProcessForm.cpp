//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TripWizardProcessForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourTripWizardProcessForm *TourTripWizardProcessForm;

//---------------------------------------------------------------------------
__fastcall TTourTripWizardProcessForm::TTourTripWizardProcessForm(TComponent* Owner)
 : TForm(Owner)
 {
  AvailableColumnSortIncreaseFlag = true;
  AvailableColumnToSort = 0;
/*
  BasicTripIdStr = "";
  BasicTripExistFlag = false;
*/  
 }

//---------------------------------------------------------------------------

void __fastcall TTourTripWizardProcessForm::ChainListViewKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
 {
  if (Key == VK_DELETE)
   {
    ChainDeleteItemAction->Execute();
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripWizardProcessForm::AvailableListViewKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
 {
  if (Key == VK_INSERT)
   {
    AvailableAddAction->Execute();
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourTripWizardProcessForm::ChainPopupMenuPopup(
       TObject *Sender)
 {
  if (ChainListView->Items->Count > 0)
   {
    ChainPopupMenu->AutoPopup = true;
   }
  else
   {
    ChainPopupMenu->AutoPopup = false;
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourTripWizardProcessForm::AvailablePopupMenuPopup(
      TObject *Sender)
 {
  //
  if (AvailableListView->Items->Count > 0)
   {
    AvailablePopupMenu->AutoPopup = true;
   }
  else
   {
    AvailablePopupMenu->AutoPopup = false;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripWizardProcessForm::AvailableListViewColumnClick(
      TObject *Sender, TListColumn *Column)
 {
  if (AvailableListView->SortType != stBoth)
   {
    AvailableListView->SortType = stBoth;
   }

  if (AvailableColumnToSort != Column->Index)
   {
    AvailableColumnSortIncreaseFlag = true;
    AvailableColumnToSort = Column->Index;
   }
  else
   {
    AvailableColumnSortIncreaseFlag = !AvailableColumnSortIncreaseFlag;
   }

  ((TCustomListView *)Sender)->AlphaSort();
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripWizardProcessForm::AvailableListViewCompare(
      TObject *Sender, TListItem *Item1, TListItem *Item2, int Data,
      int &Compare)
 {
  if (AvailableColumnToSort == 0)
   {
    Compare = CompareText(Item1->Caption,Item2->Caption);

    if (!AvailableColumnSortIncreaseFlag)
     {
      Compare *= (-1);
     }
   }
  else
   {
    int                                SubItemIndex;

    SubItemIndex = AvailableColumnToSort - 1;

    if ((SubItemIndex < Item1->SubItems->Count) &&
        (SubItemIndex < Item2->SubItems->Count))
     {
      Compare = CompareText
                (Item1->SubItems->Strings[SubItemIndex],
                 Item2->SubItems->Strings[SubItemIndex]);

      if (!AvailableColumnSortIncreaseFlag)
       {
        Compare *= (-1);
       }
     }
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripWizardProcessForm::AvailableListViewInsert(
      TObject *Sender, TListItem *Item)
 {
  if (AvailableListView->SortType != stNone)
   {
    AvailableListView->SortType = stNone;
   }
 }
//---------------------------------------------------------------------------

