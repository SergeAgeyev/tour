//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "BusViewForm.h"

#if defined(TOUR_LINKBASE_MODE)

  #include "BusAddForm.h"
  #include "BusEditForm.h"

#else

  #include "BusSimpleAddForm.h"
  #include "BusSimpleEditForm.h"

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
TTourRefBookBusViewForm *TourRefBookBusViewForm;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookBusViewForm::TTourRefBookBusViewForm(TComponent* Owner)
 : TTourRefBookTableGridViewForm(Owner)
{
}
//---------------------------------------------------------------------------

#ifdef TOUR_LINKBASE_MODE
///*
void __fastcall TTourRefBookBusViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourRefBookBusAddForm        *TourRefBookBusAddFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookBusAddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookBusAddForm),
                              &TourRefBookBusAddFormPtr);

      if (TourRefBookBusAddFormPtr != NULL)
       {
        TourRefBookBusAddFormPtr->MainQueryDataSet = MainQuery;

        ShowProcessAdd(TourRefBookBusAddFormPtr);

        delete (TourRefBookBusAddFormPtr);
        TourRefBookBusAddFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookBusAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookBusViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourRefBookBusEditForm     *TourRefBookBusEditFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookBusEditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookBusEditForm),
                              &TourRefBookBusEditFormPtr);

      if (TourRefBookBusEditFormPtr != NULL)
       {
        TourRefBookBusEditFormPtr->MainQueryDataSet = MainQuery;

        ShowProcessEdit(TourRefBookBusEditFormPtr);

        delete (TourRefBookBusEditFormPtr);
        TourRefBookBusEditFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookBusEditForm");
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
void __fastcall TTourRefBookBusViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourBusSimpleAddForm               *AddFormPtr;

  FunctionArgUsedSkip(Sender);
  AddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourBusSimpleAddForm),&AddFormPtr);

      if (AddFormPtr != NULL)
       {
        if (AddFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Append();

            MainQuery->FieldByName("bus_model")->AsString
            = AddFormPtr->BusModelEdit->Text;

            if (!AddFormPtr->BusDescEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("bus_desc")->AsString
              = AddFormPtr->BusDescEdit->Text;
             }
            if (!AddFormPtr->BusSpeedFactorEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("bus_speedfactor")->AsString
              = AddFormPtr->BusSpeedFactorEdit->Text;
             }
            if (!AddFormPtr->BusCapacityEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("bus_capacity")->AsString
              = AddFormPtr->BusCapacityEdit->Text;
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
                        + "TTourBusSimpleAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookBusViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourBusSimpleEditForm              *EditFormPtr;

  FunctionArgUsedSkip(Sender);
  EditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourBusSimpleEditForm),&EditFormPtr);

      if (EditFormPtr != NULL)
       {
        EditFormPtr->BusModelEdit->Text
        = MainQuery->FieldByName("bus_model")->AsString;
        EditFormPtr->BusDescEdit->Text
        = MainQuery->FieldByName("bus_desc")->AsString;
        EditFormPtr->BusSpeedFactorEdit->Text
        = MainQuery->FieldByName("bus_speedfactor")->AsString;
        EditFormPtr->BusCapacityEdit->Text
        = MainQuery->FieldByName("bus_capacity")->AsString;

        if (EditFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Edit();

//            MainQuery->FieldByName("bus_model")->AsString
//            = EditFormPtr->BusModelEdit->Text;

            if (!EditFormPtr->BusDescEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("bus_desc")->AsString
              = EditFormPtr->BusDescEdit->Text;
             }
            else
             {
              MainQuery->FieldByName("bus_desc")->Value
              = Variant().ChangeType(varNull);
             }
            if (!EditFormPtr->BusSpeedFactorEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("bus_speedfactor")->AsString
              = EditFormPtr->BusSpeedFactorEdit->Text;
             }
            else
             {
              MainQuery->FieldByName("bus_speedfactor")->Value
              = Variant().ChangeType(varNull);
             }
            if (!EditFormPtr->BusCapacityEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("bus_capacity")->AsString
              = EditFormPtr->BusCapacityEdit->Text;
             }
            else
             {
              MainQuery->FieldByName("bus_capacity")->Value
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
                        + "TTourBusSimpleEditForm");
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
void __fastcall TTourRefBookBusViewForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  TTourRefBookTableGridViewForm::FormClose(Sender,Action);

  TourRefBookBusViewForm = NULL;
 }
//---------------------------------------------------------------------------

#undef   GetTranslatedStr(Index)

