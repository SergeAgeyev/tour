//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StdTool.h"
#include "TourTool.h"
#include "RegionViewForm.h"

#if defined(TOUR_LINKBASE_MODE)

  #include "RegionAddForm.h"
  #include "RegionEditForm.h"

#else

  #include "RegionSimpleAddForm.h"
  #include "RegionSimpleEditForm.h"

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
TTourRefBookRegionViewForm *TourRefBookRegionViewForm;

#define  GetTranslatedStr(Index)       VStringStorage->Lines->Strings[Index]

//---------------------------------------------------------------------------
__fastcall TTourRefBookRegionViewForm::TTourRefBookRegionViewForm(TComponent* Owner)
 : TTourRefBookTableGridViewForm(Owner)
{
}
//---------------------------------------------------------------------------
#ifdef TOUR_LINKBASE_MODE
///*
void __fastcall TTourRefBookRegionViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourRefBookRegionAddForm        *TourRefBookRegionAddFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookRegionAddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookRegionAddForm),
                              &TourRefBookRegionAddFormPtr);

      if (TourRefBookRegionAddFormPtr != NULL)
       {
        TourRefBookRegionAddFormPtr->MainQueryDataSet = MainQuery;

        ShowProcessAdd(TourRefBookRegionAddFormPtr);

        delete (TourRefBookRegionAddFormPtr);
        TourRefBookRegionAddFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookRegionAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookRegionViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourRefBookRegionEditForm     *TourRefBookRegionEditFormPtr;

  FunctionArgUsedSkip(Sender);
  TourRefBookRegionEditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRefBookRegionEditForm),
                              &TourRefBookRegionEditFormPtr);

      if (TourRefBookRegionEditFormPtr != NULL)
       {
        TourRefBookRegionEditFormPtr->MainQueryDataSet = MainQuery;

        ShowProcessEdit(TourRefBookRegionEditFormPtr);

        delete (TourRefBookRegionEditFormPtr);
        TourRefBookRegionEditFormPtr = NULL;
       }
      else
       {
        throw Exception(GetTranslatedStr(TourRefBookCreateObjectErrorMessageStr)
                        + "TTourRefBookRegionEditForm");
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
void __fastcall TTourRefBookRegionViewForm::NewActionExecute(
      TObject *Sender)
 {
  TTourRegionSimpleAddForm            *AddFormPtr;

  FunctionArgUsedSkip(Sender);
  AddFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRegionSimpleAddForm),&AddFormPtr);

      if (AddFormPtr != NULL)
       {
        if (AddFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Append();

            MainQuery->FieldByName("region_id")->AsString
            = AddFormPtr->RegionIdEdit->Text;

            if (!AddFormPtr->RegionNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("region_name")->AsString
              = AddFormPtr->RegionNameEdit->Text;
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
                        + "TTourRegionSimpleAddForm");
       }
     }
    catch (Exception &exception)
     {
      TourShowDialogException(NULL,&exception);
     }
   }
 }
//---------------------------------------------------------------------------
void __fastcall TTourRefBookRegionViewForm::EditActionExecute(
      TObject *Sender)
 {
  TTourRegionSimpleEditForm           *EditFormPtr;

  FunctionArgUsedSkip(Sender);
  EditFormPtr = NULL;

  if (!EditLocked)
   {
    try
     {
      Application->CreateForm(__classid(TTourRegionSimpleEditForm),&EditFormPtr);

      if (EditFormPtr != NULL)
       {
        EditFormPtr->RegionIdEdit->Text
        = MainQuery->FieldByName("region_id")->AsString;
        EditFormPtr->RegionNameEdit->Text
        = MainQuery->FieldByName("region_name")->AsString;

        if (EditFormPtr->ShowModal() == mrOk)
         {
          CursorWaitOpen();

          try
           {
            MainQuery->Edit();

//            MainQuery->FieldByName("region_id")->AsString
//            = EditFormPtr->RegionIdEdit->Text;
            if (!EditFormPtr->RegionNameEdit->Text.IsEmpty())
             {
              MainQuery->FieldByName("region_name")->AsString
              = EditFormPtr->RegionNameEdit->Text;
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
                        + "TTourRegionSimpleEditForm");
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
void __fastcall TTourRefBookRegionViewForm::FormClose(TObject *Sender,
      TCloseAction &Action)
 {
  TTourRefBookTableGridViewForm::FormClose(Sender,Action);

  TourRefBookRegionViewForm = NULL;
 }
//---------------------------------------------------------------------------
#undef   GetTranslatedStr(Index)

