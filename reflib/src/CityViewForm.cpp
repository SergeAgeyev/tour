//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "CityViewForm.h"

#if defined(TOUR_LINKBASE_MODE)

  #include "CityAddForm.h"
  #include "CityEditForm.h"

#else

  #include "CitySimpleAddForm.h"
  #include "CitySimpleEditForm.h"

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
TTourRefBookCityViewForm *TourRefBookCityViewForm;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookCityViewForm::TTourRefBookCityViewForm(TComponent* Owner)
 : TTourRefBookTableGridViewForm(Owner)
{
}
//---------------------------------------------------------------------------
#ifdef TOUR_LINKBASE_MODE
///*
void __fastcall TTourRefBookCityViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourRefBookCityAddForm        *TourRefBookCityAddFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookCityAddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookCityAddForm),
                              &TourRefBookCityAddFormPtr);

      if (TourRefBookCityAddFormPtr != NULL)
       {
        TourRefBookCityAddFormPtr->MainQueryDataSet = MainQuery;
        TourRefBookCityAddFormPtr
        ->RegionDataSource->DataSet = RegionQuery;

        ShowProcessAdd(TourRefBookCityAddFormPtr);

        delete (TourRefBookCityAddFormPtr);
        TourRefBookCityAddFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookCityAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookCityViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourRefBookCityEditForm     *TourRefBookCityEditFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookCityEditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookCityEditForm),
                              &TourRefBookCityEditFormPtr);

      if (TourRefBookCityEditFormPtr != NULL)
       {
        TourRefBookCityEditFormPtr->MainQueryDataSet = MainQuery;
        TourRefBookCityEditFormPtr
        ->RegionDataSource->DataSet = RegionQuery;

        ShowProcessEdit(TourRefBookCityEditFormPtr);

        delete (TourRefBookCityEditFormPtr);
        TourRefBookCityEditFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookCityEditForm");
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
//---------------------------------------------------------------------------
///*
void __fastcall TTourRefBookCityViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourCitySimpleAddForm               *AddFormPtr;

  FunctionArgUsedSkip(Sender);
  AddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourCitySimpleAddForm),&AddFormPtr);

      if (AddFormPtr != NULL)
       {
        TVMemoKeyComboBoxItem         *ItemPtr;

        ItemPtr = NULL;
        AddFormPtr->CityRegionVMemoKeyComboBox->Items->Clear();

        RegionQuery->First();

        while (!RegionQuery->Eof)
         {
          ItemPtr = ((TVMemoKeyComboBoxItem*)(AddFormPtr->CityRegionVMemoKeyComboBox->Items->Add()));

          if (ItemPtr != NULL)
           {
            ItemPtr->IdStr   = RegionQuery->FieldByName("region_id")->AsString;
            ItemPtr->DescStr = RegionQuery->FieldByName("region_name")->AsString;
           }

          RegionQuery->Next();
         }

        if (AddFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Append();

            MainQuery->FieldByName("city_zip")->AsString
            = AddFormPtr->CityZIPEdit->Text;

            if (!AddFormPtr->CityRegionVMemoKeyComboBox->KeyValue.IsEmpty())
             {
              MainQuery->FieldByName("region_id")->AsString
              = AddFormPtr->CityRegionVMemoKeyComboBox->KeyValue;
             }
            if (!AddFormPtr->CityNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("city_name")->AsString
              = AddFormPtr->CityNameEdit->Text;
             }
            if (!AddFormPtr->CityPopulationEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("city_population")->AsInteger
              = StrToInt(AddFormPtr->CityPopulationEdit->Text);
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
void __fastcall TTourRefBookCityViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourCitySimpleEditForm              *EditFormPtr;

  FunctionArgUsedSkip(Sender);
  EditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourCitySimpleEditForm),&EditFormPtr);

      if (EditFormPtr != NULL)
       {
        TVMemoKeyComboBoxItem         *ItemPtr;

        ItemPtr = NULL;
        EditFormPtr->CityRegionVMemoKeyComboBox->Items->Clear();

        RegionQuery->First();

        while (!RegionQuery->Eof)
         {
          ItemPtr = ((TVMemoKeyComboBoxItem*)(EditFormPtr->CityRegionVMemoKeyComboBox->Items->Add()));

          if (ItemPtr != NULL)
           {
            ItemPtr->IdStr   = RegionQuery->FieldByName("region_id")->AsString;
            ItemPtr->DescStr = RegionQuery->FieldByName("region_name")->AsString;
           }

          RegionQuery->Next();
         }

        EditFormPtr->CityZIPEdit->Text
        = MainQuery->FieldByName("city_zip")->AsString;
        EditFormPtr->CityRegionVMemoKeyComboBox->KeyValue
        = MainQuery->FieldByName("region_id")->AsString;
        EditFormPtr->CityNameEdit->Text
        = MainQuery->FieldByName("city_name")->AsString;
        EditFormPtr->CityPopulationEdit->Text
        = MainQuery->FieldByName("city_population")->AsString;

        if (EditFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Edit();

//            MainQuery->FieldByName("city_zip")->AsString
//            = EditFormPtr->CityZIPEdit->Text;

            if (!EditFormPtr->CityRegionVMemoKeyComboBox->KeyValue.IsEmpty())
             {
              MainQuery->FieldByName("region_id")->AsString
              = EditFormPtr->CityRegionVMemoKeyComboBox->KeyValue;
             }
            else
             {
              MainQuery->FieldByName("region_id")->Value
              = Variant().ChangeType(varNull);
             }
            if (!EditFormPtr->CityNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("city_name")->AsString
              = EditFormPtr->CityNameEdit->Text;
             }
            else
             {
              MainQuery->FieldByName("city_name")->Value
              = Variant().ChangeType(varNull);
             }
            if (!EditFormPtr->CityPopulationEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("city_population")->AsInteger
              = StrToInt(EditFormPtr->CityPopulationEdit->Text);
             }
            else
             {
              MainQuery->FieldByName("city_population")->Value
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
void __fastcall TTourRefBookCityViewForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  try
   {
    RegionQuery->Close();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  TTourRefBookTableGridViewForm::FormClose(Sender,Action);

  TourRefBookCityViewForm = NULL;
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookCityViewForm::FormCreate(TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    RegionQuery->Open();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();

  TTourRefBookTableGridViewForm::FormCreate(Sender);
 }
//---------------------------------------------------------------------------

void __fastcall TTourRefBookCityViewForm::RefreshActionExecute(
      TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    if (RegionQuery->Active)
     {
      RegionQuery->Close();
     }

    if (!RegionQuery->Active)
     {
      RegionQuery->Open();
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

