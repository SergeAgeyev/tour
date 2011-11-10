//---------------------------------------------------------------------------
#include <stdio.h>
#include <io.h>

#include <vcl.h>
#pragma hdrstop

#include "RepPreViewForm.h"
#include "stdtool.h"
#include "TourTool.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TTourReportPreViewForm *TourReportPreViewForm;

//---------------------------------------------------------------------------
__fastcall TTourReportPreViewForm::TTourReportPreViewForm(TComponent* Owner) : TForm(Owner)
 {
  DefaultFileName = "";
 }
//---------------------------------------------------------------------------
__fastcall TTourReportPreViewForm::~TTourReportPreViewForm(void)
 {
  if (access(TmpFullFileNameStr,00) == 0)
   {
    remove(TmpFullFileNameStr);
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourReportPreViewForm::FormClose(TObject *Sender,TCloseAction &Action)
 {
  FunctionArgUsedSkip(Sender);

  Action = caFree;
 }
//---------------------------------------------------------------------------
void     TTourReportPreViewForm::PreviewReport
         (TQuickRep        *Report,
          AnsiString        Caption,
          AnsiString        DefaultFileName)
 {
  TQRAsciiExportFilter          *ExportFilterPtr;
  char                           TmpPathStr[MAXPATH];

  this->DefaultFileName = DefaultFileName;

  GetTempPath(sizeof(TmpPathStr),TmpPathStr);            // Get Winnows tmp patch
  strcpy(TmpFullFileNameStr,tempnam(TmpPathStr,"TTmp")); // Create unique tmp file name

  ExportFilterPtr = new TQRAsciiExportFilter(TmpFullFileNameStr);

  if (ExportFilterPtr != NULL)
   {
    Report->ExportToFilter(ExportFilterPtr);

    this->Caption = Caption;
    this->RichEdit->Lines->LoadFromFile(TmpFullFileNameStr);
    this->Show();

    delete ExportFilterPtr;
   }
 }
//---------------------------------------------------------------------------
void            TTourReportPreViewForm::PreviewExistReport
                (AnsiString   ReportFullFileNameStr,
                 bool         ShowFileNameFlag)
 {
  AnsiString    MessageStr;

  if (access(ReportFullFileNameStr.c_str(),0) == 0)
   {
    if (ShowFileNameFlag)
     {
      this->Caption = this->Caption + ReportFullFileNameStr;
     }

    this->RichEdit->Lines->LoadFromFile(ReportFullFileNameStr);
    this->Show();
   }
  else
   {
    MessageStr  = "ќшибка доступа к файлу ";
    MessageStr += ReportFullFileNameStr;

    TourShowDialogError(MessageStr.c_str());
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourReportPreViewForm::SaveToolButtonClick(TObject *Sender)
 {
  AnsiString         MessageStr;

  FunctionArgUsedSkip(Sender);

  SaveDialog->FileName = DefaultFileName;

  if (SaveDialog->Execute())
   {
    RichEdit->Lines->SaveToFile(SaveDialog->FileName);

    MessageStr  = "—формирован файл формы ";
    MessageStr += SaveDialog->FileName;

    TourShowDialogInformation(MessageStr.c_str());
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourReportPreViewForm::PrintToolButtonClick(TObject *Sender)
 {
  FunctionArgUsedSkip(Sender);

  if (PrintDialog->Execute())
   {
    RichEdit->Print("");
   }
 }
//---------------------------------------------------------------------------

