//---------------------------------------------------------------------------

#include <vcl.h>
#include "Apputils.h"
#include "TourTool.h"
#include "MainFrame.h"
#include "LoginForm.h"

#pragma hdrstop
USERES("PrjTourDemo.res");
USEFORM("..\mainlib\src\LoginForm.cpp", TourLoginForm);
USEFORM("..\graphlib\src\TripDiagramForm.cpp", TourTripDiagramForm);
USELIB("..\_lib\RxLib\lib\Rxdb5.lib");
USELIB("..\_lib\RxLib\lib\Dclrxbd5.lib");
USELIB("..\_lib\RxLib\lib\Dclrxdb5.lib");
USELIB("..\_lib\RxLib\lib\Rxbde5.lib");
USELIB("..\_lib\RxLib\lib\Rxctl5.lib");
USELIB("..\_lib\RxLib\lib\Dclrx5.lib");
USEFORM("..\mainlib\src\AboutForm.cpp", TourAboutForm);
USEUNIT("..\toollib\src\TourTool.cpp");
USEUNIT("..\graphlib\src\VCanvas.cpp");
USEFORM("..\toollib\src\TripStepDataTimeInfoForm.cpp", TourTripStepDataTimeInfoForm);
USEUNIT("..\mainlib\src\FieldDef.cpp");
USEFORM("..\toollib\src\ErrorMessageDialogForm.cpp", TourErrorMessageDialogForm);
USEFORM("..\mainlib\src\MessageModuleForm.cpp", TourMessageModule); /* TDataModule: File Type */
USEFORM("..\graphlib\src\TripDiagramOptionsForm.cpp", TourTripDiagramOptionsForm);
USEUNIT("..\graphlib\src\TripDiagramPrinter.cpp");
USEFORM("..\toollib\src\TripSwitchDialogForm.cpp", TourTripSwitchDialogForm);
USEFORM("..\toollib\src\TripTimetableForm.cpp", TourTripTimeTableDialogForm);
USEFORM("..\toollib\src\TripTimetableInfoForm.cpp", TourTripTimetableInfoForm);
USEFORM("..\toollib\src\TripTimetableRecalcBySpeedForm.cpp", TourTripTimetableRateSpeedForm);
USEFORM("..\toollib\src\TripTourMoveDialogForm.cpp", TourTripTourMoveDialogForm);
USEFORM("..\toollib\src\TripTourCopyDialogForm.cpp", TourTripTourCopyDialogForm);
USEUNIT("..\datalib\TourTime.cpp");
USEUNIT("..\datalib\TourData.cpp");
USEUNIT("..\datalib\TourDataSF.cpp");
USEUNIT("..\datalib\TourDataCA.cpp");
USEUNIT("..\datalib\TourDataCU.cpp");
USEFORM("..\graphlib\src\TripDiagramChangesForm.cpp", TourDiagramChangesForm);
USEFORM("..\reflib\src\SimpleProcessForm.cpp", TourSimpleProcessForm);
USEUNIT("..\toollib\src\TourProtect.cpp");
USEFORM("..\toollib\src\SimpleDataSetViewForm.cpp", TourSimpleDataSetViewForm);
USEUNIT("..\datalib\TourDataDM.cpp");
USEUNIT("..\datalib\TourDemoData.cpp");
USEFORM("..\mainlib\src\MainFrame.cpp", TourMainFrame);
USEFORM("..\toollib\src\SimpleTourDataSetViewForm.cpp", TourSimpleTourDataSetViewForm);
USEUNIT("..\replib\src\RepStopInfoGenerator.cpp");
USEFORM("..\replib\src\RepPreViewForm.cpp", TourReportPreViewForm);
USEUNIT("..\replib\src\RepTripInfoGenerator.cpp");
USEFORM("..\toollib\src\SimpleStopDataSetViewForm.cpp", TourSimpleStopDataSetViewForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
 {
//        TourDataModule = NULL;
        TourMainFrame  = NULL;
        TourLoginForm  = NULL;
        TourMessageModule = NULL;

        try
         {
          Application->Initialize();
          Application->Title = "Tour";
                 Application->CreateForm(__classid(TTourMainFrame), &TourMainFrame);
                 Application->CreateForm(__classid(TTourMessageModule), &TourMessageModule);
                 OnGetDefaultIniName = TourDefaultIniNameStr;

          TourMainFrame->Show();
/*
          if (TourLoginForm->ShowModal() == mrOk)
           {
            if (TourLoginForm != NULL)
             {
              delete (TourLoginForm);
              TourLoginForm = NULL;
             }
*/
            TourMainFrame->DoFlightDiagramActionExecute(NULL);

            Application->Run();
/*
           }
          if (TourDataModule != NULL)
           {
            if (TourDataModule->TourDataBaseConnection->Connected)
             {
              TourDataModule->TourDataBaseConnection->Close();
             }
            delete (TourDataModule);
            TourDataModule = NULL;
           }

          if (TourLoginForm != NULL)
           {
            delete (TourLoginForm);
            TourLoginForm = NULL;
           }
*/
          if (TourMainFrame != NULL)
           {
            delete (TourMainFrame);
            TourMainFrame = NULL;
           }
         }
        catch (Exception &exception)
         {
          TourShowDialogException(NULL,&exception);
         }
        return 0;
 }
//---------------------------------------------------------------------------
