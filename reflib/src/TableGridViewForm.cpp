//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "TableGridViewForm.h"
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
TTourRefBookTableGridViewForm *TourRefBookTableGridViewForm;

enum
 {
  ToolBarPopupMenuSignButtonIndex  = 0,
  ToolBarPopupMenuIconButtonIndex
 };
 
#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookTableGridViewForm::TTourRefBookTableGridViewForm(TComponent* Owner)
 : TForm(Owner)
 {
  FilterOffCaptionStr = Caption;
  FilterOnCaptionStr = FilterOffCaptionStr + GetTranslatedStr(TourRefBookFilterOffCaptionStr);
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookTableGridViewForm::FormCreate(TObject *Sender)
 {
  EditLocked = !TourDataModule->DataBaseEditModeFlag;

  FunctionArgUsedSkip(Sender);
  AfterMainTableOpenStatusBarHintStr =  GetTranslatedStr(TourRefBookUpDownKeyHintStr);
  AfterMainTableOpenStatusBarHintStr += GetTranslatedStr(TourRefBookFilterOnHintStr);
  AfterMainTableOpenStatusBarHintStr += GetTranslatedStr(TourRefBookFilterOffHintStr);

  if (!EditLocked)
   {
    AfterMainTableOpenStatusBarHintStr += GetTranslatedStr(TourRefBookRecordNewHintStr);
    AfterMainTableOpenStatusBarHintStr += GetTranslatedStr(TourRefBookRecordDeleteHintStr);
    AfterMainTableOpenStatusBarHintStr += GetTranslatedStr(TourRefBookRecordEditHintStr);
   }

  AfterMainTableOpenStatusBarHintStr += GetTranslatedStr(TourRefBookRecordRefreshHintStr);
  AfterMainTableOpenStatusBarHintStr += GetTranslatedStr(TourRefBookStatusBarSeparatorCharStr);

  MainStatusBar->Panels->Items[0]->Text = AfterMainTableOpenStatusBarHintStr;

 }

//---------------------------------------------------------------------------
void __fastcall TTourRefBookTableGridViewForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  FunctionArgUsedSkip(Sender);

  if (!EditLocked)
   {
    if (MainDataSource->DataSet->State == dsEdit ||
        MainDataSource->DataSet->State == dsInsert)
     {
      try
       {
        MainQuery->Post();
       }
      catch (Exception &exception)
       {
        MainQuery->Cancel();
        TourShowDialogException(NULL,&exception);
       }
     }
   }

  MainQuery->Close();

  Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TTourRefBookTableGridViewForm::FormResize(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  MainStatusBar->Panels->Items[0]->Width = Width;
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookTableGridViewForm::FilterCreateActionExecute(
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

void __fastcall TTourRefBookTableGridViewForm::FilterDropActionExecute(
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

void __fastcall TTourRefBookTableGridViewForm::DeleteActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  if (!EditLocked)
   {
    if (!MainQuery->IsEmpty())
     {
      if (TourShowDialogYesNo
          (GetTranslatedStr(TourRefBookRecordDeleteQuestionStr).c_str()) == IDYES)
       {
        try
         {
          MainQuery->Delete();
         }
        catch (Exception &exception)
         {
          TourShowDialogExceptionStr
          (&(GetTranslatedStr(TourRefBookTableDeleteErrorMessageStr)),
           &(AnsiString(GetTranslatedStr(TourRefBookTableDeleteExceptionMessageStr) +
                        "\n\nMessage : " +
                        exception.Message)));
         }
       }
     }
   }
 }
//---------------------------------------------------------------------------


void __fastcall TTourRefBookTableGridViewForm::MainTablePostError(
      TDataSet *DataSet, EDatabaseError *E, TDataAction &Action)
 {
  TBookmark                             BookMarkPtr;

  if (!EditLocked)
   {
    TourShowDialogExceptionStr
    (&(GetTranslatedStr(TourRefBookTablePostErrorMessageStr)),
     &(AnsiString(GetTranslatedStr(TourRefBookTablePostExceptionMessageStr)   +
                  "\n"                                                        +
                  GetTranslatedStr(TourRefBookTableDeleteExceptionMessageStr) +
                  "\n\nMessage : "                                            +
                  E->Message)));

    Action = daAbort;
    FunctionArgUsedSkip(E);

    BookMarkPtr = DataSet->GetBookmark();

    CursorWaitOpen();

    try
     {
      DataSet->Close();
      DataSet->Open();

      DataSet->GotoBookmark(BookMarkPtr);

      if (!DataSet->BookmarkValid(BookMarkPtr))
       {
        DataSet->Last();
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }

    DataSet->FreeBookmark(BookMarkPtr);

    CursorWaitClose();
   }
 }
//---------------------------------------------------------------------------
void TTourRefBookTableGridViewForm::ShowProcessAdd(TForm* ProcessFormPtr)
 {
  TBookmark                            SavePlace;
  bool                                 NoErrorFlag;

  SavePlace = MainQuery->GetBookmark();
  NoErrorFlag = false;

  if (!EditLocked)
   {
    while (!NoErrorFlag)
     {
      MainQuery->Append();

      if (ProcessFormPtr->ShowModal() == mrOk)
       {
        try
         {
          MainQuery->Post();
          NoErrorFlag = true;
         }
        catch (Exception &exception)
         {
          NoErrorFlag = false;
         }
       }
      else
       {
        MainQuery->Cancel();
        MainQuery->GotoBookmark(SavePlace);
        NoErrorFlag = true;
       }
     }
   }

  MainQuery->FreeBookmark(SavePlace);
 }

void TTourRefBookTableGridViewForm::ShowProcessEdit(TForm* ProcessFormPtr)
 {
  bool                                 NoErrorFlag;

  NoErrorFlag = false;

  if (!EditLocked)
   {
    while (!NoErrorFlag)
     {
      MainQuery->Edit();

      if (ProcessFormPtr->ShowModal() == mrOk)
       {
        try
         {
          MainQuery->Post();
          NoErrorFlag = true;
         }
        catch (Exception &exception)
         {
          NoErrorFlag = false;
         }
       }
      else
       {
        MainQuery->Cancel();
        NoErrorFlag = true;
       }
     }
   }
 }

void __fastcall TTourRefBookTableGridViewForm::SetEditLocked(bool value)
 {
  FEditLocked = value;

  NewToolButton->Enabled = !FEditLocked;
  EditToolButton->Enabled = !FEditLocked;
  DeleteToolButton->Enabled = !FEditLocked;

  PopupMenu->AutoPopup = !FEditLocked;
 }

bool __fastcall TTourRefBookTableGridViewForm::GetEditLocked()
 {
  return FEditLocked;
 }

void __fastcall TTourRefBookTableGridViewForm::RefreshActionExecute(
      TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  CursorWaitOpen();

  try
   {
    if (MainQuery->Active)
     {
      MainQuery->Close();
     }
    if (!MainQuery->Active)
     {
      #ifdef TOURCARDDATABASEMODEBDE
       DataSourceOrdering->Active = true;
      #endif

      MainQuery->Open();

      #ifdef TOURCARDDATABASEMODEADO
       DataSourceOrdering->Active = true;
      #endif
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookTableGridViewForm::MainDBGridKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
 {
  TShiftState                        EmptyShiftState;

  FunctionArgUsedSkip(Sender);

  EmptyShiftState.Clear();

  if (Shift == EmptyShiftState)
   {
    if (!EditLocked)
     {
      if (Key == VK_RETURN)
       {
        ActionList->Actions[2]->Execute();
        Key = VK_NONAME;
       }
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
void __fastcall TTourRefBookTableGridViewForm::FormStorageRestorePlacement(
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

void __fastcall TTourRefBookTableGridViewForm::ButtonIconClick(
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

void __fastcall TTourRefBookTableGridViewForm::ButtonTextClick(
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

#undef   GetTranslatedStr(Index)

//---------------------------------------------------------------------------


