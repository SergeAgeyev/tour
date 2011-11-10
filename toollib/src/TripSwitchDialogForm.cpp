//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TripSwitchDialogForm.h"
#include "TripDiagramForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma link "Placemnt"
#pragma resource "*.dfm"
TTourTripSwitchDialogForm *TourTripSwitchDialogForm;
//---------------------------------------------------------------------------
__fastcall TTourTripSwitchDialogForm::TTourTripSwitchDialogForm(TComponent* Owner)
 : TForm(Owner)
 {
  ColumnSortIncreaseFlag   = true;
  ColumnToSort             = 1;
  ListItemChangeIgnoreFlag = false;
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripSwitchDialogForm::TourListViewColumnClick(
      TObject *Sender, TListColumn *Column)
 {
  if (ColumnToSort - 1 != Column->Index)
   {
    ColumnToSort = Column->Index + 1;
   }
  else
   {
    ColumnSortIncreaseFlag = !ColumnSortIncreaseFlag;
   }

  ((TCustomListView *)Sender)->AlphaSort();
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripSwitchDialogForm::TourListViewCompare(
      TObject *Sender, TListItem *Item1, TListItem *Item2, int Data,
      int &Compare)
 {
  bool                                 InvertFlag;

  InvertFlag = false;

  if (ColumnToSort == 1)
   {
    Compare = TripDiagramCompareTime(Item1->Caption,Item2->Caption);

    if (!ColumnSortIncreaseFlag && !Item1->Caption.IsEmpty() && !Item2->Caption.IsEmpty())
     {
      InvertFlag = true;
     }
   }
  else
   {
    int                                SubItemIndex;

    SubItemIndex = ColumnToSort - 2;

    if (SubItemIndex == 0 || SubItemIndex == 1)
     {
      Compare = CompareText(Item1->SubItems->Strings[SubItemIndex],
                            Item2->SubItems->Strings[SubItemIndex]);

      if (!ColumnSortIncreaseFlag)
       {
        InvertFlag = true;
       }
     }
    else if (SubItemIndex == 2 || SubItemIndex == 3)
     {
      Compare = TripDiagramCompareTime(Item1->SubItems->Strings[SubItemIndex],
                                       Item2->SubItems->Strings[SubItemIndex]);

      if (!ColumnSortIncreaseFlag                           &&
          !Item1->SubItems->Strings[SubItemIndex].IsEmpty() &&
          !Item2->SubItems->Strings[SubItemIndex].IsEmpty())
       {
        InvertFlag = true;
       }
     }
    else if (SubItemIndex == 4 || SubItemIndex == 5)
     {
      Compare = TripDiagramCompareDouble(Item1->SubItems->Strings[SubItemIndex],
                                         Item2->SubItems->Strings[SubItemIndex]);
      if (!ColumnSortIncreaseFlag)
       {
        InvertFlag = true;
       }
     }
    else
     {
      Compare = TripDiagramCompareTime(Item1->SubItems->Strings[SubItemIndex],
                                       Item2->SubItems->Strings[SubItemIndex]);

      if (!ColumnSortIncreaseFlag                           &&
          !Item1->SubItems->Strings[SubItemIndex].IsEmpty() &&
          !Item2->SubItems->Strings[SubItemIndex].IsEmpty())
       {
        InvertFlag = true;
       }
     }
   }

  if (InvertFlag)
   {
    Compare *= (-1);
   }
 }
//---------------------------------------------------------------------------


void __fastcall TTourTripSwitchDialogForm::TourListViewChange(
      TObject *Sender, TListItem *Item, TItemChange Change)
 {
  unsigned int                         TourIndex;
  TItemStates                          SelState;
  TListItem                           *ItemPtr;
  int                                 ItemSelCount;
  int                                 ItemSelIndex;

  if ((!ListItemChangeIgnoreFlag) &&
      (Change == ctState)         &&
      (ListItemCheckedFlag != Item->Checked))
   {
    SelState << isSelected;
    ItemSelIndex = 0;

    ItemSelCount = TourListView->SelCount;

    if (ItemSelCount > 1)
     {
      ListItemChangeIgnoreFlag = true;

      ItemPtr = TourListView->Items->Item[0];

      if ((ItemPtr->Selected) && (ItemPtr != Item))
       {
        ItemPtr->Checked = Item->Checked;
       }

      while ((ItemPtr != NULL) && (ItemSelIndex < ItemSelCount))
       {
        ItemPtr = TourListView->GetNextItem(ItemPtr,sdAll,SelState);

        if (ItemPtr != NULL)
         {
          ItemPtr->Checked = Item->Checked;
         }
       }
     }

    ListItemChangeIgnoreFlag = false;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripSwitchDialogForm::TourListViewChanging(
      TObject *Sender, TListItem *Item, TItemChange Change,
      bool &AllowChange)
 {
  if (Change == ctState)
   {
    ListItemCheckedFlag = Item->Checked;
   }

  AllowChange = true;
 }
//---------------------------------------------------------------------------


void __fastcall TTourTripSwitchDialogForm::PanelResize(TObject *Sender)
 {
  CancelButton->Left = Panel->Width - CancelButton->Width - Panel->Tag;
  NextButton->Left   = CancelButton->Left - NextButton->Width - Panel->Tag;
 }
//---------------------------------------------------------------------------

