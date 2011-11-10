//---------------------------------------------------------------------------

#ifndef TableGridViewFormH
#define TableGridViewFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include "VDBGridFilterDialog.h"
#include "Placemnt.h"
#include "VADODataSourceOrdering.h"
#include "VCustomDataSourceOrdering.h"
#include "RXDBCtrl.h"
#include "VDBSortGrid.h"
#include "VStringStorage.h"
#include "VCustomDBGridFilterDialog.h"

enum TourRefBookViewStringTypes
 {
  TourRefBookStatusBarSeparatorCharStr = 0,
  TourRefBookEscapeKeyHintStr,
  TourRefBookUpDownKeyHintStr,
  TourRefBookSpaceKeyHintStr,
  TourRefBookFilterOnHintStr,
  TourRefBookFilterOffHintStr,
  TourRefBookRecordEditHintStr,
  TourRefBookRecordNewHintStr,
  TourRefBookRecordDeleteHintStr,
  TourRefBookRecordRefreshHintStr,
  TourRefBookFilterOffCaptionStr,
  TourRefBookCreateObjectErrorMessageStr,
  TourRefBookRecordDeleteQuestionStr,
  TourRefBookTablePostErrorMessageStr,
  TourRefBookTablePostExceptionMessageStr,
  TourRefBookTableDeleteErrorMessageStr,
  TourRefBookTableDeleteExceptionMessageStr,
  TourRefBookViewStringTypesEnumCount
 };
//---------------------------------------------------------------------------
class TTourRefBookTableGridViewForm : public TForm
{
__published:    // IDE-managed Components
 TDataSource *MainDataSource;
 TStatusBar *MainStatusBar;
 TToolBar *ToolBar;
 TToolButton *NewToolButton;
 TToolButton *DeleteToolButton;
 TToolButton *Separator1ToolButton;
 TToolButton *ViewToolButton;
 TToolButton *EditToolButton;
 TToolButton *Separator2ToolButton;
 TToolButton *FilterToolButton;
 TToolButton *DropFilterToolButton;
 TImageList *ToolBarImageList;
 TImageList *InactiveToolBarImageList;
 TPopupMenu *PopupMenu;
 TMenuItem *NewMenuItem;
 TMenuItem *DeleteMenuItem;
 TMenuItem *EditMenuItem;
 TActionList *ActionList;
 TAction *NewAction;
 TAction *DeleteAction;
 TAction *EditAction;
 TVDBGridFilterDialog *MainDBGridFilterDialog;
 TAction *FilterCreateAction;
 TAction *FilterDropAction;
 TToolButton *Separator3ToolButton;
 TToolButton *RefreshToolButton;
 TAction *RefreshAction;
 TADOQuery *MainQuery;
        TFormStorage *FormStorage;
        TVADODataSourceOrdering *DataSourceOrdering;
        TVDBSortGrid *MainDBGrid;
 TVStringStorage *VStringStorage;
 TPopupMenu *ToolBarPopupMenu;
 TMenuItem *ButtonText;
 TMenuItem *ButtonIcon;
 void __fastcall FormCreate(TObject *Sender);
 void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
 void __fastcall FormResize(TObject *Sender);
 void __fastcall FilterCreateActionExecute(TObject *Sender);
 void __fastcall FilterDropActionExecute(TObject *Sender);
 void __fastcall DeleteActionExecute(TObject *Sender);
        void __fastcall MainTablePostError(TDataSet *DataSet,
          EDatabaseError *E, TDataAction &Action);
 void __fastcall RefreshActionExecute(TObject *Sender);
        void __fastcall MainDBGridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormStorageRestorePlacement(TObject *Sender);
 void __fastcall ButtonIconClick(TObject *Sender);
 void __fastcall ButtonTextClick(TObject *Sender);
private:
 bool FEditLocked;
 void __fastcall SetEditLocked(bool value);
 bool __fastcall GetEditLocked();
protected:
 AnsiString                            AfterMainTableOpenStatusBarHintStr;
 void ShowProcessAdd(TForm* ProcessFormPtr);
 void ShowProcessEdit(TForm* ProcessFormPtr);
public:         // User declarations
 AnsiString                            FilterOnCaptionStr;
 AnsiString                            FilterOffCaptionStr;
 __fastcall TTourRefBookTableGridViewForm(TComponent* Owner);
 __property bool EditLocked  = { read=GetEditLocked, write=SetEditLocked };
};
//---------------------------------------------------------------------------
extern PACKAGE TTourRefBookTableGridViewForm *TourRefBookTableGridViewForm;
//---------------------------------------------------------------------------
#endif
