//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "StopViewForm.h"

#if defined(TOUR_LINKBASE_MODE)

  #include "StopAddForm.h"
  #include "StopEditForm.h"

#else

  #include "StopSimpleAddForm.h"
  #include "StopSimpleEditForm.h"

#endif

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
TTourRefBookStopViewForm *TourRefBookStopViewForm;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookStopViewForm::TTourRefBookStopViewForm(TComponent* Owner)
 : TTourRefBookTableGridViewForm(Owner)
{
}
//---------------------------------------------------------------------------
#ifdef TOUR_LINKBASE_MODE
///*
void __fastcall TTourRefBookStopViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourRefBookStopAddForm        *TourRefBookStopAddFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookStopAddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookStopAddForm),
                              &TourRefBookStopAddFormPtr);

      if (TourRefBookStopAddFormPtr != NULL)
       {
        TourRefBookStopAddFormPtr->MainQueryDataSet = MainQuery;
        TourRefBookStopAddFormPtr
        ->StopModelDataSource->DataSet = StopModelQuery;
        TourRefBookStopAddFormPtr
        ->StopOwnerDataSource->DataSet = StopOwnerQuery;
        TourRefBookStopAddFormPtr
        ->CityDataSource->DataSet = CityQuery;

        ShowProcessAdd(TourRefBookStopAddFormPtr);

        delete (TourRefBookStopAddFormPtr);
        TourRefBookStopAddFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookStopAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookStopViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourRefBookStopEditForm     *TourRefBookStopEditFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookStopEditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookStopEditForm),
                              &TourRefBookStopEditFormPtr);

      if (TourRefBookStopEditFormPtr != NULL)
       {
        TourRefBookStopEditFormPtr->MainQueryDataSet = MainQuery;
        TourRefBookStopEditFormPtr
        ->StopModelDataSource->DataSet = StopModelQuery;
        TourRefBookStopEditFormPtr
        ->StopOwnerDataSource->DataSet = StopOwnerQuery;
        TourRefBookStopEditFormPtr
        ->CityDataSource->DataSet = CityQuery;

        ShowProcessEdit(TourRefBookStopEditFormPtr);

        delete (TourRefBookStopEditFormPtr);
        TourRefBookStopEditFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookStopEditForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//*/
//---------------------------------------------------------------------------
#else
///*
void __fastcall TTourRefBookStopViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourStopSimpleAddForm               *AddFormPtr;

  FunctionArgUsedSkip(Sender);
  AddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourStopSimpleAddForm),&AddFormPtr);

      if (AddFormPtr != NULL)
       {
        TVMemoKeyComboBoxItem         *ItemPtr;

        CursorWaitOpen();

        ItemPtr = NULL;
        AddFormPtr->StopModelVMemoKeyComboBox->Items->Clear();
        AddFormPtr->StopOwnerVMemoKeyComboBox->Items->Clear();
        AddFormPtr->CityStorage.clear();

        StopModelQuery->First();
        StopOwnerQuery->First();
        CityQuery->First();

        while (!StopModelQuery->Eof)
         {
          ItemPtr = ((TVMemoKeyComboBoxItem*)(AddFormPtr->StopModelVMemoKeyComboBox->Items->Add()));

          if (ItemPtr != NULL)
           {
            ItemPtr->IdStr   = StopModelQuery->FieldByName("stop_model")->AsString;
            ItemPtr->DescStr = StopModelQuery->FieldByName("stopmodel_name")->AsString;
           }

          StopModelQuery->Next();
         }
        while (!StopOwnerQuery->Eof)
         {
          ItemPtr = ((TVMemoKeyComboBoxItem*)(AddFormPtr->StopOwnerVMemoKeyComboBox->Items->Add()));

          if (ItemPtr != NULL)
           {
            ItemPtr->IdStr   = StopOwnerQuery->FieldByName("stopowner_id")->AsString;
            ItemPtr->DescStr = StopOwnerQuery->FieldByName("stopowner_name")->AsString;
           }

          StopOwnerQuery->Next();
         }
        while (!CityQuery->Eof)
         {
          TourStopSimpleProcessCityRecordLookupType        Item;

          Item.IdStr   = CityQuery->FieldByName("city_zip")->AsString;
          Item.NameStr = CityQuery->FieldByName("city_name")->AsString;

          AddFormPtr->CityStorage.push_back(Item);

          CityQuery->Next();
         }

        CursorWaitClose();

        if (AddFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Append();

            MainQuery->FieldByName("stop_id")->AsString
            = AddFormPtr->StopIdEdit->Text;

            if (!AddFormPtr->StopModelVMemoKeyComboBox->KeyValue.IsEmpty())
             {
              MainQuery->FieldByName("stop_model")->AsString
              = AddFormPtr->StopModelVMemoKeyComboBox->KeyValue;
             }
            if (!AddFormPtr->StopOwnerVMemoKeyComboBox->KeyValue.IsEmpty())
             {
              MainQuery->FieldByName("stopowner_id")->AsString
              = AddFormPtr->StopOwnerVMemoKeyComboBox->KeyValue;
             }
            if (!AddFormPtr->StopNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("stop_name")->AsString
              = AddFormPtr->StopNameEdit->Text;
             }
            if (!AddFormPtr->CityZIPEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("city_zip")->AsString
              = AddFormPtr->CityZIPEdit->Text;
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
void __fastcall TTourRefBookStopViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourStopSimpleEditForm              *EditFormPtr;

  FunctionArgUsedSkip(Sender);
  EditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourStopSimpleEditForm),&EditFormPtr);

      if (EditFormPtr != NULL)
       {
        CursorWaitOpen();

        TVMemoKeyComboBoxItem         *ItemPtr;

        ItemPtr = NULL;
        EditFormPtr->StopModelVMemoKeyComboBox->Items->Clear();
        EditFormPtr->StopOwnerVMemoKeyComboBox->Items->Clear();
        EditFormPtr->CityStorage.clear();

        StopModelQuery->First();
        StopOwnerQuery->First();
        CityQuery->First();

        while (!StopModelQuery->Eof)
         {
          ItemPtr = ((TVMemoKeyComboBoxItem*)(EditFormPtr->StopModelVMemoKeyComboBox->Items->Add()));

          if (ItemPtr != NULL)
           {
            ItemPtr->IdStr   = StopModelQuery->FieldByName("stop_model")->AsString;
            ItemPtr->DescStr = StopModelQuery->FieldByName("stopmodel_name")->AsString;
           }

          StopModelQuery->Next();
         }
        while (!StopOwnerQuery->Eof)
         {
          ItemPtr = ((TVMemoKeyComboBoxItem*)(EditFormPtr->StopOwnerVMemoKeyComboBox->Items->Add()));

          if (ItemPtr != NULL)
           {
            ItemPtr->IdStr   = StopOwnerQuery->FieldByName("stopowner_id")->AsString;
            ItemPtr->DescStr = StopOwnerQuery->FieldByName("stopowner_name")->AsString;
           }

          StopOwnerQuery->Next();
         }
        while (!CityQuery->Eof)
         {
          TourStopSimpleProcessCityRecordLookupType        Item;

          Item.IdStr   = CityQuery->FieldByName("city_zip")->AsString;
          Item.NameStr = CityQuery->FieldByName("city_name")->AsString;

          EditFormPtr->CityStorage.push_back(Item);

          CityQuery->Next();
         }

        EditFormPtr->StopIdEdit->Text
        = MainQuery->FieldByName("stop_id")->AsString;
        EditFormPtr->CityZIPEdit->Text
        = MainQuery->FieldByName("city_zip")->AsString;
        EditFormPtr->StopModelVMemoKeyComboBox->KeyValue
        = MainQuery->FieldByName("stop_model")->AsString;
        EditFormPtr->StopOwnerVMemoKeyComboBox->KeyValue
        = MainQuery->FieldByName("stopowner_id")->AsString;
        EditFormPtr->StopNameEdit->Text
        = MainQuery->FieldByName("stop_name")->AsString;

        CursorWaitClose();

        if (EditFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Edit();

//            MainQuery->FieldByName("stop_id")->AsString
//            = EditFormPtr->StopIdEdit->Text;

            if (!EditFormPtr->StopModelVMemoKeyComboBox->KeyValue.IsEmpty())
             {
              MainQuery->FieldByName("stop_model")->AsString
              = EditFormPtr->StopModelVMemoKeyComboBox->KeyValue;
             }
            else
             {
              MainQuery->FieldByName("stop_model")->Value
              = Variant().ChangeType(varNull);
             }
            if (!EditFormPtr->StopOwnerVMemoKeyComboBox->KeyValue.IsEmpty())
             {
              MainQuery->FieldByName("stopowner_id")->AsString
              = EditFormPtr->StopOwnerVMemoKeyComboBox->KeyValue;
             }
            else
             {
              MainQuery->FieldByName("stopowner_id")->Value
              = Variant().ChangeType(varNull);
             }
            if (!EditFormPtr->StopNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("stop_name")->AsString
              = EditFormPtr->StopNameEdit->Text;
             }
            else
             {
              MainQuery->FieldByName("stop_name")->Value
              = Variant().ChangeType(varNull);
             }
            if (!EditFormPtr->CityZIPEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("city_zip")->AsString
              = EditFormPtr->CityZIPEdit->Text;
             }
            else
             {
              MainQuery->FieldByName("city_zip")->Value
              = Variant().ChangeType(varNull);
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
void __fastcall TTourRefBookStopViewForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  try
   {
    StopModelQuery->Close();
    StopOwnerQuery->Close();
    CityQuery->Close();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  TTourRefBookTableGridViewForm::FormClose(Sender,Action);

  TourRefBookStopViewForm = NULL;
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookStopViewForm::FormCreate(TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    StopModelQuery->Open();
    StopOwnerQuery->Open();
    CityQuery->Open();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();

  TTourRefBookTableGridViewForm::FormCreate(Sender);
 }
//---------------------------------------------------------------------------

void __fastcall TTourRefBookStopViewForm::RefreshActionExecute(
      TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    if (StopModelQuery->Active)
     {
      StopModelQuery->Close();
     }
    if (!StopModelQuery->Active)
     {
      StopModelQuery->Open();
     }
    if (StopOwnerQuery->Active)
     {
      StopOwnerQuery->Close();
     }
    if (!StopOwnerQuery->Active)
     {
      StopOwnerQuery->Open();
     }
    if (CityQuery->Active)
     {
      CityQuery->Close();
     }
    if (!CityQuery->Active)
     {
      CityQuery->Open();
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

#undef   GetTranslatedStr(Index)       

