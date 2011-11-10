//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "TableGridSelectForm.h"
#include "DataModuleForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VDBGridFilterDialog"
#pragma link "Placemnt"
#pragma link "VADODataSourceOrdering"
#pragma link "VCustomDataSourceOrdering"
#pragma link "RXDBCtrl"
#pragma link "VDBSortGrid"
#pragma link "VStringStorage"
#pragma link "VCustomDBGridFilterDialog"
#pragma resource "*.dfm"
TTourRefBookTableGridSelectForm *TourRefBookTableGridSelectForm;

enum
 {
  ToolBarPopupMenuSignButtonIndex  = 0,
  ToolBarPopupMenuIconButtonIndex
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookTableGridSelectForm::TTourRefBookTableGridSelectForm(TComponent* Owner)
 : TForm(Owner)
 {
  FilterOffCaptionStr = Caption;
  FilterOnCaptionStr = FilterOffCaptionStr + GetTranslatedStr(TourRefBookSelectFilterOffCaptionStr);
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookTableGridSelectForm::FormCreate(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);
  AfterMainTableOpenStatusBarHintStr =  GetTranslatedStr(TourRefBookSelectUpDownKeyHintStr);
  AfterMainTableOpenStatusBarHintStr += GetTranslatedStr(TourRefBookSelectFilterOnHintStr);
  AfterMainTableOpenStatusBarHintStr += GetTranslatedStr(TourRefBookSelectFilterOffHintStr);

  AfterMainTableOpenStatusBarHintStr += GetTranslatedStr(TourRefBookSelectRecordRefreshHintStr);
  AfterMainTableOpenStatusBarHintStr += GetTranslatedStr(TourRefBookSelectStatusBarSeparatorCharStr);

  MainStatusBar->Panels->Items[0]->Text = AfterMainTableOpenStatusBarHintStr;
 }

//---------------------------------------------------------------------------
void __fastcall TTourRefBookTableGridSelectForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  FunctionArgUsedSkip(Sender);

  Action = caHide;
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookTableGridSelectForm::FormResize(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  MainStatusBar->Panels->Items[0]->Width = Width;
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookTableGridSelectForm::FilterCreateActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  if (MainDBGridFilterDialog->Execute())
   {
    if (MainDBGridFilterDialog->Active)
     {
      DropFilterToolButton->Enabled = true;
      Caption = FilterOnCaptionStr;
     }
    else
     {
      DropFilterToolButton->Enabled = false;
      Caption = FilterOffCaptionStr;
     }
   }
 }
//---------------------------------------------------------------------------

void __fastcall TTourRefBookTableGridSelectForm::FilterDropActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  MainDBGridFilterDialog->ClearFilter();

  if (MainDBGridFilterDialog->Active)
   {
    DropFilterToolButton->Enabled = true;
    Caption = FilterOnCaptionStr;
   }
  else
   {
    DropFilterToolButton->Enabled = false;
    Caption = FilterOffCaptionStr;
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookTableGridSelectForm::MainDBGridKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
 {
  TShiftState                        EmptyShiftState;

  FunctionArgUsedSkip(Sender);

  EmptyShiftState.Clear();

  if (Shift == EmptyShiftState)
   {
    if (Key == VK_RETURN)
     {
      Key = VK_NONAME;
      TourRefBookTableGridSelectForm->Close();//ActionList->Actions[2]->Execute();
     }
   }
  else if (Shift.Contains(ssCtrl))
   {
    if (Key == VK_DELETE)
     {
      Key = VK_NONAME;
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookTableGridSelectForm::FormStorageRestorePlacement(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  if (ToolBarPopupMenu->Items->Items[ToolBarPopupMenuSignButtonIndex]->Checked)
   {
    ToolBar->ShowCaptions = true;
   }
  else
   {
    ToolBar->ShowCaptions = false;
   }

  if (ToolBarPopupMenu->Items->Items[ToolBarPopupMenuIconButtonIndex]->Checked)
   {
    ToolBar->DisabledImages = InactiveToolBarImageList;

    if (ToolBarPopupMenu->Items->Items[ToolBarPopupMenuSignButtonIndex]->Checked)
     {
      ToolBar->HotImages = ToolBarImageList;
      ToolBar->Images = InactiveToolBarImageList;
     }
    else
     {
      ToolBar->ButtonHeight = 0;
      ToolBar->ButtonWidth = 0;
      ToolBar->Images = ToolBarImageList;
      ToolBar->HotImages = NULL;
     }
   }
  else
   {
    ToolBar->Images = NULL;
    ToolBar->HotImages = NULL;
    ToolBar->DisabledImages = NULL;
    ToolBar->ButtonHeight = 0;
    ToolBar->ButtonWidth = 0;

    ToolBarPopupMenu->Items->Items[ToolBarPopupMenuSignButtonIndex]->Enabled = false;

    if (!ToolBarPopupMenu->Items->Items[ToolBarPopupMenuSignButtonIndex]->Checked)
     {
      ToolBar->ShowCaptions = true;
      ToolBarPopupMenu->Items->Items[ToolBarPopupMenuSignButtonIndex]->Checked = true;
     }
   }

  CursorWaitOpen();

  try
   {
    #ifdef TOURDATABASEMODEBDE
     DataSourceOrdering->Active = true;
    #endif

    MainQuery->Open();

    #ifdef TOURDATABASEMODEADO
     DataSourceOrdering->Active = true;
    #endif
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();
 }
//---------------------------------------------------------------------------

void __fastcall TTourRefBookTableGridSelectForm::ButtonIconClick(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  if (ToolBar->Images == NULL)
   {
    ToolBar->Images = InactiveToolBarImageList;
    ToolBar->HotImages = ToolBarImageList;
    ToolBar->DisabledImages = InactiveToolBarImageList;
    ToolBarPopupMenu->Items->Items[ToolBarPopupMenuSignButtonIndex]->Enabled = true;
   }
  else
   {
    ToolBar->Images = NULL;
    ToolBar->HotImages = NULL;
    ToolBar->DisabledImages = NULL;
    ToolBar->ShowCaptions = true;
    ToolBarPopupMenu->Items->Items[ToolBarPopupMenuSignButtonIndex]->Checked = true;
    ToolBarPopupMenu->Items->Items[ToolBarPopupMenuSignButtonIndex]->Enabled = false;
    ToolBar->ButtonHeight = 0;
   }

  ToolBarPopupMenu->Items->Items[ToolBarPopupMenuIconButtonIndex]->Checked =
   !ToolBarPopupMenu->Items->Items[ToolBarPopupMenuIconButtonIndex]->Checked;
 }
//---------------------------------------------------------------------------

void __fastcall TTourRefBookTableGridSelectForm::ButtonTextClick(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  ToolBar->ShowCaptions = !ToolBar->ShowCaptions;

  if(ToolBar->ShowCaptions == false)
   {
    ToolBar->ButtonHeight = 0;
    ToolBar->ButtonWidth = 0;
    ToolBar->Images = ToolBarImageList;
    ToolBar->HotImages = NULL;
    ToolBar->DisabledImages = InactiveToolBarImageList;
   }
  else
   {
    ToolBar->DisabledImages = InactiveToolBarImageList;
    ToolBar->HotImages = ToolBarImageList;
    ToolBar->Images = InactiveToolBarImageList;
   }

  ToolBarPopupMenu->Items->Items[ToolBarPopupMenuSignButtonIndex]->Checked =
    !ToolBarPopupMenu->Items->Items[ToolBarPopupMenuSignButtonIndex]->Checked;
 }
//---------------------------------------------------------------------------

void __fastcall TTourRefBookTableGridSelectForm::FormDestroy(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  MainQuery->Close();
 }
//---------------------------------------------------------------------------


void __fastcall TTourRefBookTableGridSelectForm::RefreshActionExecute(
      TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    if (MainQuery->Active)
     {
      MainQuery->Close();
     }
    if (!MainQuery->Active)
     {
      MainQuery->Open();
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();
 }
//---------------------------------------------------------------------------

