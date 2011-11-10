//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrPath

#include "StdTool.h"
#include "PathViewForm.h"

#if defined(TOUR_LINKBASE_MODE)

  #include "PathAddForm.h"
  #include "PathEditForm.h"

#else

  #include "PathSimpleAddForm.h"
  #include "PathSimpleEditForm.h"

#endif

#include "TourTool.h"
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
TTourPathViewForm *TourPathViewForm;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourPathViewForm::TTourPathViewForm(TComponent* Owner)
 : TTourRefBookTableGridViewForm(Owner)
{
}
//---------------------------------------------------------------------------
#ifdef TOUR_LINKBASE_MODE
///*
void __fastcall TTourPathViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourPathAddForm        *TourPathAddFormPtr;

  FunctionArgUsedSkip(Sender);
  TourPathAddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourPathAddForm),
                              &TourPathAddFormPtr);

      if (TourPathAddFormPtr != NULL)
       {
        TourPathAddFormPtr->MainQueryDataSet = MainQuery;
        TourPathAddFormPtr->StopDataSource->DataSet = StopQuery;

        ShowProcessAdd(TourPathAddFormPtr);

        delete (TourPathAddFormPtr);
        TourPathAddFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourPathAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourPathViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourPathEditForm     *TourPathEditFormPtr;

  FunctionArgUsedSkip(Sender);
  TourPathEditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourPathEditForm),
                              &TourPathEditFormPtr);

      if (TourPathEditFormPtr != NULL)
       {
        TDateTime                      WorkDateTime;

        TourPathEditFormPtr->MainQueryDataSet = MainQuery;
        TourPathEditFormPtr->StopDataSource->DataSet = StopQuery;

        ShowProcessEdit(TourPathEditFormPtr);

        delete (TourPathEditFormPtr);
        TourPathEditFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourPathEditForm");
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
void __fastcall TTourPathViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourPathSimpleAddForm               *AddFormPtr;

  FunctionArgUsedSkip(Sender);
  AddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourPathSimpleAddForm),&AddFormPtr);

      if (AddFormPtr != NULL)
       {
        CursorWaitOpen();

        AddFormPtr->StopStorage.clear();

        StopQuery->First();

        while (!StopQuery->Eof)
         {
          TourPathSimpleProcessStopRecordLookupType        Item;

          Item.IdStr   = StopQuery->FieldByName("stop_id")->AsString;
          Item.NameStr = StopQuery->FieldByName("stop_name")->AsString;

          AddFormPtr->StopStorage.push_back(Item);

          StopQuery->Next();
         }

        CursorWaitClose();

        if (AddFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Append();

            MainQuery->FieldByName("path_fromstopid")->AsString
            = AddFormPtr->FromStopIdEdit->Text;
            MainQuery->FieldByName("path_tostopid")->AsString
            = AddFormPtr->ToStopIdEdit->Text;

            if (!AddFormPtr->SpeedEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("path_normspeed")->AsFloat
              = StrToFloat(AddFormPtr->SpeedEdit->Text);
             }
            if (!AddFormPtr->LengthEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("path_length")->AsFloat
              = StrToFloat(AddFormPtr->LengthEdit->Text);
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
                        + "TTourPathSimpleAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourPathViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourPathSimpleEditForm              *EditFormPtr;

  FunctionArgUsedSkip(Sender);
  EditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourPathSimpleEditForm),&EditFormPtr);

      if (EditFormPtr != NULL)
       {
        CursorWaitOpen();

        EditFormPtr->StopStorage.clear();

        StopQuery->First();

        while (!StopQuery->Eof)
         {
          TourPathSimpleProcessStopRecordLookupType        Item;

          Item.IdStr   = StopQuery->FieldByName("stop_id")->AsString;
          Item.NameStr = StopQuery->FieldByName("stop_name")->AsString;

          EditFormPtr->StopStorage.push_back(Item);

          StopQuery->Next();
         }

        EditFormPtr->FromStopIdEdit->Text
        = MainQuery->FieldByName("path_fromstopid")->AsString;
        EditFormPtr->ToStopIdEdit->Text
        = MainQuery->FieldByName("path_tostopid")->AsString;
        EditFormPtr->SpeedEdit->Text
        = MainQuery->FieldByName("path_normspeed")->AsString;
        EditFormPtr->LengthEdit->Text
        = MainQuery->FieldByName("path_length")->AsString;

        CursorWaitClose();

        if (EditFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Edit();

            MainQuery->FieldByName("path_fromstopid")->AsString
            = EditFormPtr->FromStopIdEdit->Text;
            MainQuery->FieldByName("path_tostopid")->AsString
            = EditFormPtr->ToStopIdEdit->Text;

            if (!EditFormPtr->SpeedEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("path_normspeed")->AsFloat
              = StrToFloat(EditFormPtr->SpeedEdit->Text);
             }
            else
             {
              MainQuery->FieldByName("path_normspeed")->Value
              = Variant().ChangeType(varNull);
             }
            if (!EditFormPtr->LengthEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("path_length")->AsFloat
              = StrToFloat(EditFormPtr->LengthEdit->Text);
             }
            else
             {
              MainQuery->FieldByName("path_length")->Value
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
void __fastcall TTourPathViewForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  try
   {
    StopQuery->Close();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  TTourRefBookTableGridViewForm::FormClose(Sender,Action);

  TourPathViewForm = NULL;
 }
//---------------------------------------------------------------------------
void __fastcall TTourPathViewForm::FormCreate(TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    StopQuery->Open();
   }
  catch (Exception &exception)
   {
    TourShowDialogException(NULL,&exception);
   }

  CursorWaitClose();

  TTourRefBookTableGridViewForm::FormCreate(Sender);
 }
//---------------------------------------------------------------------------

void __fastcall TTourPathViewForm::RefreshActionExecute(
      TObject *Sender)
 {
  CursorWaitOpen();

  try
   {
    if (StopQuery->Active)
     {
      StopQuery->Close();
     }
    if (!StopQuery->Active)
     {
      StopQuery->Open();
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

