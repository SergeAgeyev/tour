//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "TripOwnerViewForm.h"

#if defined(TOUR_LINKBASE_MODE)

  #include "TripOwnerAddForm.h"
  #include "TripOwnerEditForm.h"

#else

  #include "TripOwnerSimpleAddForm.h"
  #include "TripOwnerSimpleEditForm.h"

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
TTourRefBookTripOwnerViewForm *TourRefBookTripOwnerViewForm;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookTripOwnerViewForm::TTourRefBookTripOwnerViewForm(TComponent* Owner)
 : TTourRefBookTableGridViewForm(Owner)
{
}
//---------------------------------------------------------------------------
#ifdef TOUR_LINKBASE_MODE
///*
void __fastcall TTourRefBookTripOwnerViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourRefBookTripOwnerAddForm        *TourRefBookTripOwnerAddFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookTripOwnerAddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookTripOwnerAddForm),
                              &TourRefBookTripOwnerAddFormPtr);

      if (TourRefBookTripOwnerAddFormPtr != NULL)
       {
        TourRefBookTripOwnerAddFormPtr->MainQueryDataSet = MainQuery;

        ShowProcessAdd(TourRefBookTripOwnerAddFormPtr);

        delete (TourRefBookTripOwnerAddFormPtr);
        TourRefBookTripOwnerAddFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookTripOwnerAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookTripOwnerViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourRefBookTripOwnerEditForm     *TourRefBookTripOwnerEditFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookTripOwnerEditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookTripOwnerEditForm),
                              &TourRefBookTripOwnerEditFormPtr);

      if (TourRefBookTripOwnerEditFormPtr != NULL)
       {
        TourRefBookTripOwnerEditFormPtr->MainQueryDataSet = MainQuery;

        ShowProcessEdit(TourRefBookTripOwnerEditFormPtr);

        delete (TourRefBookTripOwnerEditFormPtr);
        TourRefBookTripOwnerEditFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookTripOwnerEditForm");
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
void __fastcall TTourRefBookTripOwnerViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourTripOwnerSimpleAddForm               *AddFormPtr;

  FunctionArgUsedSkip(Sender);
  AddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourTripOwnerSimpleAddForm),&AddFormPtr);

      if (AddFormPtr != NULL)
       {
        if (AddFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Append();

            MainQuery->FieldByName("tripowner_id")->AsString
            = AddFormPtr->TripOwnerEdit->Text;

            if (!AddFormPtr->TripOwnerNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("tripowner_name")->AsString
              = AddFormPtr->TripOwnerNameEdit->Text;
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
                        + "TTourTripOwnerSimpleAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookTripOwnerViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourTripOwnerSimpleEditForm              *EditFormPtr;

  FunctionArgUsedSkip(Sender);
  EditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourTripOwnerSimpleEditForm),&EditFormPtr);

      if (EditFormPtr != NULL)
       {
        EditFormPtr->TripOwnerEdit->Text
        = MainQuery->FieldByName("tripowner_id")->AsString;
        EditFormPtr->TripOwnerNameEdit->Text
        = MainQuery->FieldByName("tripowner_name")->AsString;

        if (EditFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Edit();

//            MainQuery->FieldByName("tripowner_id")->AsString
//            = EditFormPtr->TripOwnerEdit->Text;

            if (!EditFormPtr->TripOwnerNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("tripowner_name")->AsString
              = EditFormPtr->TripOwnerNameEdit->Text;
             }
            else
             {
              MainQuery->FieldByName("tripowner_name")->Value
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
                        + "TTourTripOwnerSimpleEditForm");
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
void __fastcall TTourRefBookTripOwnerViewForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  TTourRefBookTableGridViewForm::FormClose(Sender,Action);

  TourRefBookTripOwnerViewForm = NULL;
 }
//---------------------------------------------------------------------------

#undef   GetTranslatedStr(Index)       

