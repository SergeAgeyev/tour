//---------------------------------------------------------------------------
#ifndef RepPreViewFormH
#define RepPreViewFormH
//---------------------------------------------------------------------------
#include <dir.h>

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <QRExport.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TTourReportPreViewForm : public TForm
 {
  __published  :
  TToolBar           *ToolBar;
  TToolButton        *SaveToolButton;
  TImageList         *ImageList;
  TToolButton        *ToolButton1;
  TToolButton        *PrintToolButton;
  TPrintDialog       *PrintDialog;
  TRichEdit          *RichEdit;
  TSaveDialog        *SaveDialog;

  void  __fastcall    FormClose           (TObject *Sender, TCloseAction &Action);
  void  __fastcall    SaveToolButtonClick (TObject *Sender);
  void  __fastcall    PrintToolButtonClick(TObject *Sender);

  private      :
  char                TmpFullFileNameStr[MAXPATH];
  AnsiString          DefaultFileName;

  public       :
        __fastcall    TTourReportPreViewForm  (TComponent* Owner);
        __fastcall   ~TTourReportPreViewForm  (void);

  void                 PreviewReport      (TQuickRep  *Report,
                                           AnsiString  Caption,
                                           AnsiString  DefaultFileName = "");

  void                 PreviewExistReport (AnsiString  ReportFullFileNameStr,
                                           bool        ShowFileNameFlag = true);
 };
//---------------------------------------------------------------------------
extern PACKAGE TTourReportPreViewForm *TourReportPreViewForm;
//---------------------------------------------------------------------------
#endif
