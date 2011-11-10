//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SimpleTourDataSetViewForm.h"
#include "TourTool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SimpleDataSetViewForm"
#pragma link "VStringStorage"
#pragma link "Placemnt"
#pragma resource "*.dfm"
TTourSimpleTourDataSetViewForm *TourSimpleTourDataSetViewForm;

#define  GetTranslatedStr(Index)  VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourSimpleTourDataSetViewForm::TTourSimpleTourDataSetViewForm(TComponent* Owner)
        : TTourSimpleDataSetViewForm(Owner)
 {
  ColumnToSort = 2;
 }
//---------------------------------------------------------------------------
void __fastcall TTourSimpleTourDataSetViewForm::ListViewColumnClick(
      TObject *Sender, TListColumn *Column)
 {
  if (abs(ColumnToSort) - 1 != Column->Index)
   {
    ColumnToSort = Column->Index + 1;
   }
  else
   {
    ColumnToSort *= -1;
   }

//  ((TCustomListView *)Sender)->CustomSort(NULL,TourListViewColumnToSort);
  ((TCustomListView *)Sender)->AlphaSort();
 }
//---------------------------------------------------------------------------

void __fastcall TTourSimpleTourDataSetViewForm::ListViewCompare(
      TObject *Sender, TListItem *Item1, TListItem *Item2, int Data,
      int &Compare)
 {
  bool                                 InvertFlag;

  InvertFlag = false;

   if (abs(ColumnToSort) <= 1)
   {
    Compare = CompareText(Item1->Caption,Item2->Caption);

    if (ColumnToSort < 0 && !Item1->Caption.IsEmpty() && !Item2->Caption.IsEmpty())
     {
      InvertFlag = true;
     }
   }
  else
   {
    int                                SubItemIndex;

    SubItemIndex = abs(ColumnToSort) - 2;

    if ((Item1->SubItems->Count >= SubItemIndex + 1) &&
        (Item2->SubItems->Count >= SubItemIndex + 1))
     {

      if (SubItemIndex == 0)
       {
        Compare = CompareText(Item1->SubItems->Strings[SubItemIndex],
                              Item2->SubItems->Strings[SubItemIndex]);

        if (ColumnToSort < 0)
         {
          InvertFlag = true;
         }
       }
/*
      else if (SubItemIndex == 1)
       {
        Compare = TripDiagramCompareDouble(Item1->SubItems->Strings[SubItemIndex],
                                           Item2->SubItems->Strings[SubItemIndex]);
        if (TourListViewColumnToSort < 0)
         {
          InvertFlag = true;
         }
       }
      else
       {
        Compare = TripDiagramCompareTime(Item1->SubItems->Strings[SubItemIndex],
                                         Item2->SubItems->Strings[SubItemIndex]);

        if (TourListViewColumnToSort < 0                                          &&
            !Item1->SubItems->Strings[SubItemIndex].IsEmpty() &&
            !Item2->SubItems->Strings[SubItemIndex].IsEmpty())
         {
          InvertFlag = true;
         }
       }
*/       
     }
   }

  if (InvertFlag)
   {
    Compare *= (-1);
   }
 }
//---------------------------------------------------------------------------


void __fastcall TTourSimpleTourDataSetViewForm::FormCloseQuery(
      TObject *Sender, bool &CanClose)
 {
  if (ModalResult == mrOk)
   {
    if (ListView->Selected == NULL)
     {
      CanClose = false;
      TourShowDialogError
      (GetTranslatedStr(TourSimpleTourDataSetViewChooseTourMessageStr).c_str());
      ListView->SetFocus();
     }
    else
     {
      CanClose = true;
     }
   }
  else
   {
    CanClose = true;
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourSimpleTourDataSetViewForm::PanelResize(
      TObject *Sender)
 {
  CancelButton->Left = Panel->Width - CancelButton->Width - Panel->Tag;
  OkButton->Left   = CancelButton->Left - OkButton->Width - Panel->Tag;
 }
//---------------------------------------------------------------------------

