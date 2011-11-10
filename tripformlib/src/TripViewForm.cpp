//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrTrip

#include "StdTool.h"
#include "TourTool.h"
#include "FieldDef.h"
#include "TripViewForm.h"

#if defined(TOUR_LINKBASE_MODE)

  #include "TripAddForm.h"
  #include "TripEditForm.h"

#else

  #include "TripSimpleAddForm.h"
  #include "TripSimpleEditForm.h"

#endif

#include "TripStepWizardForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Placemnt"
#pragma link "RXDBCtrl"
#pragma link "TableGridViewForm"
#pragma link "VADODataSourceOrdering"
#pragma link "VCustomDataSourceOrdering"
#pragma link "VDBGridFilterDialog"
#pragma link "VDBSortGrid"
#pragma link "VStringStorage"
#pragma link "VCustomDBGridFilterDialog"
#pragma resource "*.dfm"
TTourTripViewForm *TourTripViewForm;

enum TourTripStringTypes
 {
  TourTripNoSelectItemStr = TourRefBookViewStringTypesEnumCount,
  TourTripStepByTripIdCaptionStr,
  TourTripRecordTripStepWizardHintStr
 };

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourTripViewForm::TTourTripViewForm(TComponent* Owner)
 : TTourRefBookTableGridViewForm(Owner)
 {
 }
//---------------------------------------------------------------------------
#ifdef TOUR_LINKBASE_MODE
///*
void __fastcall TTourTripViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourTripAddForm        *TourTripAddFormPtr;

  FunctionArgUsedSkip(Sender);
  TourTripAddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourTripAddForm),
                              &TourTripAddFormPtr);

      if (TourTripAddFormPtr != NULL)
       {
        TourTripAddFormPtr->MainQueryDataSet = MainQuery;
        TourTripAddFormPtr
        ->BusDataSource->DataSet = BusQuery;
        TourTripAddFormPtr
        ->TripOwnerDataSource->DataSet = TripOwnerQuery;

        ShowProcessAdd(TourTripAddFormPtr);

        delete (TourTripAddFormPtr);
        TourTripAddFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourTripAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourTripViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourTripEditForm     *TourTripEditFormPtr;

  FunctionArgUsedSkip(Sender);
  TourTripEditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourTripEditForm),
                              &TourTripEditFormPtr);

      if (TourTripEditFormPtr != NULL)
       {
        TourTripEditFormPtr->MainQueryDataSet = MainQuery;
        TourTripEditFormPtr
        ->BusDataSource->DataSet = BusQuery;
        TourTripEditFormPtr
        ->TripOwnerDataSource->DataSet = TripOwnerQuery;

        ShowProcessEdit(TourTripEditFormPtr);

        delete (TourTripEditFormPtr);
        TourTripEditFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourTripEditForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//*/
#else
///*
void __fastcall TTourTripViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourTripSimpleAddForm               *AddFormPtr;

  FunctionArgUsedSkip(Sender);
  AddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourTripSimpleAddForm),&AddFormPtr);

      if (AddFormPtr != NULL)
       {
        TVMemoKeyComboBoxItem         *ItemPtr;

        ItemPtr = NULL;
        AddFormPtr->BusModelVMemoKeyComboBox->Items->Clear();
        AddFormPtr->TripOwnerVMemoKeyComboBox->Items->Clear();

        BusQuery->First();
        TripOwnerQuery->First();

        while (!BusQuery->Eof)
         {
          ItemPtr = ((TVMemoKeyComboBoxItem*)(AddFormPtr->BusModelVMemoKeyComboBox->Items->Add()));

          if (ItemPtr != NULL)
           {
            ItemPtr->IdStr   = BusQuery->FieldByName("bus_model")->AsString;
            ItemPtr->DescStr = BusQuery->FieldByName("bus_desc")->AsString;
           }

          BusQuery->Next();
         }
        while (!TripOwnerQuery->Eof)
         {
          ItemPtr = ((TVMemoKeyComboBoxItem*)(AddFormPtr->TripOwnerVMemoKeyComboBox->Items->Add()));

          if (ItemPtr != NULL)
           {
            ItemPtr->IdStr   = TripOwnerQuery->FieldByName("tripowner_id")->AsString;
            ItemPtr->DescStr = TripOwnerQuery->FieldByName("tripowner_name")->AsString;
           }

          TripOwnerQuery->Next();
         }

        if (AddFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Append();

            MainQuery->FieldByName("trip_id")->AsString
            = AddFormPtr->TripIdEdit->Text;

            if (!AddFormPtr->BusModelVMemoKeyComboBox->KeyValue.IsEmpty())
             {
              MainQuery->FieldByName("bus_model")->AsString
              = AddFormPtr->BusModelVMemoKeyComboBox->KeyValue;
             }
            if (!AddFormPtr->TripOwnerVMemoKeyComboBox->KeyValue.IsEmpty())
             {
              MainQuery->FieldByName("tripowner_id")->AsString
              = AddFormPtr->TripOwnerVMemoKeyComboBox->KeyValue;
             }
            if (!AddFormPtr->TripNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("trip_name")->AsString
              = AddFormPtr->TripNameEdit->Text;
             }
            if (!AddFormPtr->TripNotesEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("trip_notes")->AsString
              = AddFormPtr->TripNotesEdit->Text;
             }

            MainQuery->Post();
           }
          catch (...)
           {
            MainQuery->Cancel();
           }
          CursorWaitClose();
         }

        delete (AddFormPtr);
        AddFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourCitySimpleAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourTripViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourTripSimpleEditForm              *EditFormPtr;

  FunctionArgUsedSkip(Sender);
  EditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourTripSimpleEditForm),&EditFormPtr);

      if (EditFormPtr != NULL)
       {
        TVMemoKeyComboBoxItem         *ItemPtr;

        ItemPtr = NULL;
        EditFormPtr->BusModelVMemoKeyComboBox->Items->Clear();
        EditFormPtr->TripOwnerVMemoKeyComboBox->Items->Clear();

        BusQuery->First();
        TripOwnerQuery->First();

        while (!BusQuery->Eof)
         {
          ItemPtr = ((TVMemoKeyComboBoxItem*)(EditFormPtr->BusModelVMemoKeyComboBox->Items->Add()));

          if (ItemPtr != NULL)
           {
            ItemPtr->IdStr   = BusQuery->FieldByName("bus_model")->AsString;
            ItemPtr->DescStr = BusQuery->FieldByName("bus_desc")->AsString;
           }

          BusQuery->Next();
         }
        while (!TripOwnerQuery->Eof)
         {
          ItemPtr = ((TVMemoKeyComboBoxItem*)(EditFormPtr->TripOwnerVMemoKeyComboBox->Items->Add()));

          if (ItemPtr != NULL)
           {
            ItemPtr->IdStr   = TripOwnerQuery->FieldByName("tripowner_id")->AsString;
            ItemPtr->DescStr = TripOwnerQuery->FieldByName("tripowner_name")->AsString;
           }

          TripOwnerQuery->Next();
         }

        EditFormPtr->TripIdEdit->Text
        = MainQuery->FieldByName("trip_id")->AsString;
        EditFormPtr->BusModelVMemoKeyComboBox->KeyValue
        = MainQuery->FieldByName("bus_model")->AsString;
        EditFormPtr->TripOwnerVMemoKeyComboBox->KeyValue
        = MainQuery->FieldByName("tripowner_id")->AsString;
        EditFormPtr->TripNameEdit->Text
        = MainQuery->FieldByName("trip_name")->AsString;
        EditFormPtr->TripNotesEdit->Text
        = MainQuery->FieldByName("trip_notes")->AsString;

        if (EditFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Edit();

//            MainQuery->FieldByName("trip_id")->AsString
//            = EditFormPtr->TripIdEdit->Text;

            if (!EditFormPtr->BusModelVMemoKeyComboBox->KeyValue.IsEmpty())
             {
              MainQuery->FieldByName("bus_model")->AsString
              = EditFormPtr->BusModelVMemoKeyComboBox->KeyValue;
             }
            if (!EditFormPtr->TripOwnerVMemoKeyComboBox->KeyValue.IsEmpty())
             {
              MainQuery->FieldByName("tripowner_id")->AsString
              = EditFormPtr->TripOwnerVMemoKeyComboBox->KeyValue;
             }
            if (!EditFormPtr->TripNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("trip_name")->AsString
              = EditFormPtr->TripNameEdit->Text;
             }
            if (!EditFormPtr->TripNotesEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("trip_notes")->AsString
              = EditFormPtr->TripNotesEdit->Text;
             }

            MainQuery->Post();
           }
          catch (...)
           {
            MainQuery->Cancel();
           }
          CursorWaitClose();
         }

        delete (EditFormPtr);
        EditFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourCitySimpleEditForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//*/
#endif
//---------------------------------------------------------------------------
void __fastcall TTourTripViewForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  try
   {
    BusQuery->Close();
    TripOwnerQuery->Close();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  TTourRefBookTableGridViewForm::FormClose(Sender,Action);

  TourTripViewForm = NULL;
 }
//---------------------------------------------------------------------------
void __fastcall TTourTripViewForm::FormCreate(TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    BusQuery->Open();
    TripOwnerQuery->Open();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();

  TTourRefBookTableGridViewForm::FormCreate(Sender);

  AfterMainTableOpenStatusBarHintStr
  += GetTranslatedStr(TourTripRecordTripStepWizardHintStr);

  MainStatusBar->Panels->Items[0]->Text = AfterMainTableOpenStatusBarHintStr;
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripViewForm::RefreshActionExecute(
      TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    if (BusQuery->Active)
     {
      BusQuery->Close();
     }
    if (!BusQuery->Active)
     {
      BusQuery->Open();
     }
    if (TripOwnerQuery->Active)
     {
      TripOwnerQuery->Close();
     }
    if (!TripOwnerQuery->Active)
     {
      TripOwnerQuery->Open();
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();

  TTourRefBookTableGridViewForm::RefreshActionExecute(Sender);
 }
//---------------------------------------------------------------------------

void __fastcall TTourTripViewForm::TripStepActionExecute(TObject *Sender)
 {
  TTourTripStepWizardForm             *TripStepWizardFormPtr;
  AnsiString                           TripIdStr;

  FunctionArgUsedSkip(Sender);
  TripStepWizardFormPtr = NULL;
  TripIdStr = "";

  try
   {
    Application->CreateForm(__classid(TTourTripStepWizardForm),
                            &TripStepWizardFormPtr);

    if (TripStepWizardFormPtr != NULL)
     {
      TripIdStr = MainQuery->FieldByName(TripIdFieldNameStr)->AsString;

      if (!TripIdStr.IsEmpty())
       {
        TripStepWizardFormPtr->Caption
        = GetTranslatedStr(TourTripStepByTripIdCaptionStr) +
          TripIdStr +
          " [" + MainQuery->FieldByName(TripNameFieldNameStr)->AsString + "]";
/*
        TripStepWizardFormPtr->CurrentTripIdStr = TripIdStr;
        TripStepWizardFormPtr->FillChainStrStoreByTrip(TripIdStr);
*/
        TripStepWizardFormPtr->CurrentTripId = TripIdStr;
//        TripStepWizardFormPtr->BaseTripIdStr    = TripIdStr;

        if (TripStepWizardFormPtr->ShowModal() == mrOk)
         {
          TripStepWizardFormPtr->UpdateTripStepTable(TripIdStr);
          RefreshActionExecute(Sender);
         }
       }
      else
       {
        TourShowDialogError
        ((GetTranslatedStr(TourTripNoSelectItemStr)).c_str());
       }

      delete (TripStepWizardFormPtr);
      TripStepWizardFormPtr = NULL;
     }
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }
  //
 }
//---------------------------------------------------------------------------

#undef   GetTranslatedStr(Index)


