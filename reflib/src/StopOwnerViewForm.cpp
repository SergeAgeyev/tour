//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "StopOwnerViewForm.h"

#if defined(TOUR_LINKBASE_MODE)

  #include "StopOwnerAddForm.h"
  #include "StopOwnerEditForm.h"

#else

  #include "StopOwnerSimpleAddForm.h"
  #include "StopOwnerSimpleEditForm.h"

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
TTourRefBookStopOwnerViewForm *TourRefBookStopOwnerViewForm;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookStopOwnerViewForm::TTourRefBookStopOwnerViewForm(TComponent* Owner)
 : TTourRefBookTableGridViewForm(Owner)
{
}
//---------------------------------------------------------------------------
#ifdef TOUR_LINKBASE_MODE
///*
void __fastcall TTourRefBookStopOwnerViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourRefBookStopOwnerAddForm        *TourRefBookStopOwnerAddFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookStopOwnerAddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookStopOwnerAddForm),
                              &TourRefBookStopOwnerAddFormPtr);

      if (TourRefBookStopOwnerAddFormPtr != NULL)
       {
        TourRefBookStopOwnerAddFormPtr->MainQueryDataSet = MainQuery;

        ShowProcessAdd(TourRefBookStopOwnerAddFormPtr);

        delete (TourRefBookStopOwnerAddFormPtr);
        TourRefBookStopOwnerAddFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookStopOwnerAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookStopOwnerViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourRefBookStopOwnerEditForm     *TourRefBookStopOwnerEditFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookStopOwnerEditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookStopOwnerEditForm),
                              &TourRefBookStopOwnerEditFormPtr);

      if (TourRefBookStopOwnerEditFormPtr != NULL)
       {
        TourRefBookStopOwnerEditFormPtr->MainQueryDataSet = MainQuery;

        ShowProcessEdit(TourRefBookStopOwnerEditFormPtr);

        delete (TourRefBookStopOwnerEditFormPtr);
        TourRefBookStopOwnerEditFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookStopOwnerEditForm");
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
void __fastcall TTourRefBookStopOwnerViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourStopOwnerSimpleAddForm               *AddFormPtr;

  FunctionArgUsedSkip(Sender);
  AddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourStopOwnerSimpleAddForm),&AddFormPtr);

      if (AddFormPtr != NULL)
       {
        if (AddFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Append();

            MainQuery->FieldByName("stopowner_id")->AsString
            = AddFormPtr->StopOwnerEdit->Text;

            if (!AddFormPtr->StopOwnerNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("stopowner_name")->AsString
              = AddFormPtr->StopOwnerNameEdit->Text;
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
                        + "TTourStopOwnerSimpleAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookStopOwnerViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourStopOwnerSimpleEditForm              *EditFormPtr;

  FunctionArgUsedSkip(Sender);
  EditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourStopOwnerSimpleEditForm),&EditFormPtr);

      if (EditFormPtr != NULL)
       {
        EditFormPtr->StopOwnerEdit->Text
        = MainQuery->FieldByName("stopowner_id")->AsString;
        EditFormPtr->StopOwnerNameEdit->Text
        = MainQuery->FieldByName("stopowner_name")->AsString;

        if (EditFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Edit();

//            MainQuery->FieldByName("stopowner_id")->AsString
//            = EditFormPtr->StopOwnerEdit->Text;

            if (!EditFormPtr->StopOwnerNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("stopowner_name")->AsString
              = EditFormPtr->StopOwnerNameEdit->Text;
             }
            else
             {
              MainQuery->FieldByName("stopowner_name")->Value
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
                        + "TTourStopOwnerSimpleEditForm");
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

void __fastcall TTourRefBookStopOwnerViewForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  TTourRefBookTableGridViewForm::FormClose(Sender,Action);

  TourRefBookStopOwnerViewForm = NULL;
 }
//---------------------------------------------------------------------------

#undef   GetTranslatedStr(Index)

