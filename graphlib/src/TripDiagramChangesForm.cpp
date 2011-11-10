//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TripDiagramChangesForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VStringStorage"
#pragma resource "*.dfm"
TTourDiagramChangesForm *TourDiagramChangesForm;

enum TourDiagramChangesStringTypes
 {
  TourDiagramChangesTourStr = 0,
  TourDiagramChangesModifiedStr,
  TourDiagramChangesAppendedStr,
  TourDiagramChangesDeletedStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

#define  DefaultCheckBoxIntervalValue  10

//---------------------------------------------------------------------------
__fastcall TTourDiagramChangesForm::TTourDiagramChangesForm(TComponent* Owner)
        : TForm(Owner)
 {
  FInterval = DefaultCheckBoxIntervalValue;
 }
//---------------------------------------------------------------------------

void __fastcall    TTourDiagramChangesForm::SetChangesList
                   (TourCachedUpdateDataClass        *value)
 {
  if (value != NULL)
   {
    CachedUpdateDataStoragePtr = value;
    FillCheckBoxStorage();
   }
 }

void               TTourDiagramChangesForm::FillCheckBoxStorage
                   (void)
 {
  unsigned int                         CheckBoxIndex;
  unsigned int                         CheckBoxCount;

  CheckBoxCount = CheckBoxStorage.size();

  for (CheckBoxIndex = 0; CheckBoxIndex < CheckBoxCount; CheckBoxIndex++)
   {
    delete (CheckBoxStorage[CheckBoxIndex]);
    CheckBoxStorage[CheckBoxIndex] = NULL;
   }

  CheckBoxStorage.clear();

  CheckBoxCount = CachedUpdateDataStoragePtr->ChangesCount();

  for (CheckBoxIndex = 0; CheckBoxIndex < CheckBoxCount; CheckBoxIndex++)
   {
    AppendChangeToList(CheckBoxIndex);
   }
 }

void               TTourDiagramChangesForm::AppendChangeToList
                   (unsigned int                      CheckBoxIndex)
 {
  TCheckBox                           *CheckBoxPtr;
  unsigned int                         ChangeTypeCode;
  std::string                          ChangedTourIdStr;
  AnsiString                           CheckBoxCaptionStr;

  CheckBoxPtr = new TCheckBox(ScrollBox);

  if (CheckBoxPtr != NULL)
   {
    CheckBoxPtr->Parent = ScrollBox;
    CheckBoxPtr->Width  = ScrollBox->Width - 2 * FInterval;

    CachedUpdateDataStoragePtr
    ->GetChangeInfo(&ChangeTypeCode,ChangedTourIdStr,CheckBoxIndex);

    CheckBoxCaptionStr  = GetTranslatedStr(TourDiagramChangesTourStr);
    CheckBoxCaptionStr += ChangedTourIdStr.c_str();
    CheckBoxCaptionStr += " (";
    CheckBoxCaptionStr += CachedUpdateDataStoragePtr->Tour(ChangedTourIdStr)->NameStr().c_str();
    CheckBoxCaptionStr += ") ";

    if (ChangeTypeCode == TourCachedUpdateChangeTypeCodeTourDeleted)
     {
      CheckBoxCaptionStr += GetTranslatedStr(TourDiagramChangesDeletedStr);
     }
    else if (ChangeTypeCode == TourCachedUpdateChangeTypeCodeTourModified)
     {
      CheckBoxCaptionStr += GetTranslatedStr(TourDiagramChangesModifiedStr);
     }
    else if (ChangeTypeCode == TourCachedUpdateChangeTypeCodeTourAppended)
     {
      CheckBoxCaptionStr += GetTranslatedStr(TourDiagramChangesAppendedStr);
     }

    CheckBoxPtr->Caption = CheckBoxCaptionStr;

    CheckBoxPtr->Left = FInterval;
    CheckBoxPtr->Top  = FInterval;

    if (CheckBoxIndex > 0)
     {
      CheckBoxPtr->Top += CheckBoxStorage[CheckBoxIndex - 1]->Top    +
                          CheckBoxStorage[CheckBoxIndex - 1]->Height;
     }

    CheckBoxPtr->Checked = true;
    CheckBoxPtr->Enabled = true;

    CheckBoxStorage.push_back(CheckBoxPtr);
   }
 }

void __fastcall TTourDiagramChangesForm::FormDestroy(TObject *Sender)
 {
  unsigned int                         CheckBoxIndex;
  unsigned int                         CheckBoxCount;

  CheckBoxCount = CheckBoxStorage.size();

  for (CheckBoxIndex = 0; CheckBoxIndex < CheckBoxCount; CheckBoxIndex++)
   {
    delete (CheckBoxStorage[CheckBoxIndex]);
    CheckBoxStorage[CheckBoxIndex] = NULL;
   }

  CheckBoxStorage.clear();
 }
//---------------------------------------------------------------------------

void __fastcall    TTourDiagramChangesForm::SetInterval
                   (unsigned int                      value)
 {
  FInterval = value;
 }
void __fastcall TTourDiagramChangesForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  Action = caHide;
 }
//---------------------------------------------------------------------------

