//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "StopModelViewForm.h"

#if defined(TOUR_LINKBASE_MODE)

  #include "StopModelAddForm.h"
  #include "StopModelEditForm.h"

#else

  #include "StopModelSimpleAddForm.h"
  #include "StopModelSimpleEditForm.h"

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
TTourRefBookStopModelViewForm *TourRefBookStopModelViewForm;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookStopModelViewForm::TTourRefBookStopModelViewForm(TComponent* Owner)
 : TTourRefBookTableGridViewForm(Owner)
{
}
//---------------------------------------------------------------------------
#ifdef TOUR_LINKBASE_MODE
///*
void __fastcall TTourRefBookStopModelViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourRefBookStopModelAddForm        *TourRefBookStopModelAddFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookStopModelAddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookStopModelAddForm),
                              &TourRefBookStopModelAddFormPtr);

      if (TourRefBookStopModelAddFormPtr != NULL)
       {
        TourRefBookStopModelAddFormPtr->MainQueryDataSet = MainQuery;

        ShowProcessAdd(TourRefBookStopModelAddFormPtr);

        delete (TourRefBookStopModelAddFormPtr);
        TourRefBookStopModelAddFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookStopModelAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookStopModelViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourRefBookStopModelEditForm     *TourRefBookStopModelEditFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookStopModelEditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookStopModelEditForm),
                              &TourRefBookStopModelEditFormPtr);

      if (TourRefBookStopModelEditFormPtr != NULL)
       {
        TourRefBookStopModelEditFormPtr->MainQueryDataSet = MainQuery;

        ShowProcessEdit(TourRefBookStopModelEditFormPtr);

        delete (TourRefBookStopModelEditFormPtr);
        TourRefBookStopModelEditFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookStopModelEditForm");
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
void __fastcall TTourRefBookStopModelViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourStopModelSimpleAddForm               *AddFormPtr;

  FunctionArgUsedSkip(Sender);
  AddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourStopModelSimpleAddForm),&AddFormPtr);

      if (AddFormPtr != NULL)
       {
        if (AddFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Append();

            MainQuery->FieldByName("stop_model")->AsString
            = AddFormPtr->StopModelEdit->Text;

            if (!AddFormPtr->StopModelNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("stopmodel_name")->AsString
              = AddFormPtr->StopModelNameEdit->Text;
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
                        + "TTourStopModelSimpleAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookStopModelViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourStopModelSimpleEditForm              *EditFormPtr;

  FunctionArgUsedSkip(Sender);
  EditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourStopModelSimpleEditForm),&EditFormPtr);

      if (EditFormPtr != NULL)
       {
        EditFormPtr->StopModelEdit->Text
        = MainQuery->FieldByName("stop_model")->AsString;
        EditFormPtr->StopModelNameEdit->Text
        = MainQuery->FieldByName("stopmodel_name")->AsString;

        if (EditFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Edit();

//            MainQuery->FieldByName("stop_model")->AsString
//            = EditFormPtr->StopModelEdit->Text;

            if (!EditFormPtr->StopModelNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("stopmodel_name")->AsString
              = EditFormPtr->StopModelNameEdit->Text;
             }
            else
             {
              MainQuery->FieldByName("stopmodel_name")->Value
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
                        + "TTourStopModelSimpleEditForm");
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
void __fastcall TTourRefBookStopModelViewForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  TTourRefBookTableGridViewForm::FormClose(Sender,Action);

  TourRefBookStopModelViewForm = NULL;
 }
//---------------------------------------------------------------------------

#undef   GetTranslatedStr(Index)

