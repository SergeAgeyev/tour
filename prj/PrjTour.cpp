//---------------------------------------------------------------------------

#include <vcl.h>
#include "Apputils.h"
#include "TourTool.h"
#include "MainFrame.h"
#include "LoginForm.h"
#include "DataModuleForm.h"

#pragma hdrstop
USERES("PrjTour.res");
USEFORM("..\mainlib\src\MainFrame.cpp", TourMainFrame);
USEFORM("..\mainlib\src\DataModuleForm.cpp", TourDataModule); /* TDataModule: File Type */
USEFORM("..\mainlib\src\LoginForm.cpp", TourLoginForm);
USEFORM("..\reflib\src\TableGridProcessForm.cpp", TourRefBookTableGridProcessForm);
USEFORM("..\reflib\src\TableGridViewForm.cpp", TourRefBookTableGridViewForm);
USEFORM("..\reflib\src\StopOwnerViewForm.cpp", TourRefBookStopOwnerViewForm);
USEFORM("..\reflib\src\StopOwnerProcessForm.cpp", TourRefBookStopOwnerProcessForm);
USEFORM("..\reflib\src\StopOwnerAddForm.cpp", TourRefBookStopOwnerAddForm);
USEFORM("..\reflib\src\StopOwnerEditForm.cpp", TourRefBookStopOwnerEditForm);
USEFORM("..\reflib\src\StopModelProcessForm.cpp", TourRefBookStopModelProcessForm);
USEFORM("..\reflib\src\StopModelViewForm.cpp", TourRefBookStopModelViewForm);
USEFORM("..\reflib\src\StopModelAddForm.cpp", TourRefBookStopModelAddForm);
USEFORM("..\reflib\src\StopModelEditForm.cpp", TourRefBookStopModelEditForm);
USEFORM("..\reflib\src\TripOwnerViewForm.cpp", TourRefBookTripOwnerViewForm);
USEFORM("..\reflib\src\TripOwnerProcessForm.cpp", TourRefBookTripOwnerProcessForm);
USEFORM("..\reflib\src\TripOwnerAddForm.cpp", TourRefBookTripOwnerAddForm);
USEFORM("..\reflib\src\TripOwnerEditForm.cpp", TourRefBookTripOwnerEditForm);
USEFORM("..\reflib\src\RegionViewForm.cpp", TourRefBookRegionViewForm);
USEFORM("..\reflib\src\RegionProcessForm.cpp", TourRefBookRegionProcessForm);
USEFORM("..\reflib\src\RegionEditForm.cpp", TourRefBookRegionEditForm);
USEFORM("..\reflib\src\RegionAddForm.cpp", TourRefBookRegionAddForm);
USEFORM("..\reflib\src\BusViewForm.cpp", TourRefBookBusViewForm);
USEFORM("..\reflib\src\BusProcessForm.cpp", TourRefBookBusProcessForm);
USEFORM("..\reflib\src\BusEditForm.cpp", TourRefBookBusEditForm);
USEFORM("..\reflib\src\BusAddForm.cpp", TourRefBookBusAddForm);
USEFORM("..\reflib\src\CityViewForm.cpp", TourRefBookCityViewForm);
USEFORM("..\reflib\src\CityProcessForm.cpp", TourRefBookCityProcessForm);
USEFORM("..\reflib\src\CityAddForm.cpp", TourRefBookCityAddForm);
USEFORM("..\reflib\src\CityEditForm.cpp", TourRefBookCityEditForm);
USEFORM("..\reflib\src\StopViewForm.cpp", TourRefBookStopViewForm);
USEFORM("..\reflib\src\StopProcessForm.cpp", TourRefBookStopProcessForm);
USEFORM("..\reflib\src\StopEditForm.cpp", TourRefBookStopEditForm);
USEFORM("..\reflib\src\StopAddForm.cpp", TourRefBookStopAddForm);
USEFORM("..\graphlib\src\TripDiagramForm.cpp", TourTripDiagramForm);
USEFORM("..\tripformlib\src\TripViewForm.cpp", TourTripViewForm);
USEFORM("..\tripformlib\src\TripProcessForm.cpp", TourTripProcessForm);
USEFORM("..\tripformlib\src\TripEditForm.cpp", TourTripEditForm);
USEFORM("..\tripformlib\src\TripAddForm.cpp", TourTripAddForm);
USEFORM("..\tripformlib\src\StatsViewForm.cpp", TourStatsViewForm);
USEFORM("..\tripformlib\src\StatsEditForm.cpp", TourStatsEditForm);
USEFORM("..\tripformlib\src\StatsAddForm.cpp", TourStatsAddForm);
USEFORM("..\tripformlib\src\StatsProcessForm.cpp", TourStatsProcessForm);
USEFORM("..\tripformlib\src\PathViewForm.cpp", TourPathViewForm);
USEFORM("..\tripformlib\src\PathProcessForm.cpp", TourPathProcessForm);
USEFORM("..\tripformlib\src\PathEditForm.cpp", TourPathEditForm);
USEFORM("..\tripformlib\src\PathAddForm.cpp", TourPathAddForm);
USELIB("..\_lib\RxLib\lib\Rxdb5.lib");
USELIB("..\_lib\RxLib\lib\Dclrxbd5.lib");
USELIB("..\_lib\RxLib\lib\Dclrxdb5.lib");
USELIB("..\_lib\RxLib\lib\Rxbde5.lib");
USELIB("..\_lib\RxLib\lib\Rxctl5.lib");
USELIB("..\_lib\RxLib\lib\Dclrx5.lib");
USEFORM("..\mainlib\src\AboutForm.cpp", TourAboutForm);
USEFORM("..\toollib\src\SessionDateForm.cpp", TourSessionDateForm);
USEFORM("..\toollib\src\SessionTimeForm.cpp", TourSessionTimeForm);
USEUNIT("..\toollib\src\TourTool.cpp");
USEFORM("..\toollib\src\DataSetViewForm.cpp", TourDataSetViewForm);
USEUNIT("..\graphlib\src\VCanvas.cpp");
USEFORM("..\toollib\src\TripWizardProcessForm.cpp", TourTripWizardProcessForm);
USEFORM("..\toollib\src\TripPreDiagramForm.cpp", TourTripPreDiagramForm);
USEFORM("..\tripformlib\src\TripStepWizardForm.cpp", TourTripStepWizardForm);
USEFORM("..\toollib\src\TripStepDataTimeInfoForm.cpp", TourTripStepDataTimeInfoForm);
USEUNIT("..\mainlib\src\FieldDef.cpp");
USEFORM("..\tripformlib\src\TripStepViewForm.cpp", TourTripStepViewForm);
USEFORM("..\toollib\src\TripNewMasterForm.cpp", TourTripNewMasterForm);
USEFORM("..\toollib\src\TripStepNewMasterForm.cpp", TourTripStepNewMasterForm);
USEFORM("..\toollib\src\ErrorMessageDialogForm.cpp", TourErrorMessageDialogForm);
USEFORM("..\mainlib\src\MessageModuleForm.cpp", TourMessageModule); /* TDataModule: File Type */
USEFORM("..\graphlib\src\TripDiagramOptionsForm.cpp", TourTripDiagramOptionsForm);
USEFORM("..\replib\src\RepPreViewForm.cpp", TourReportPreViewForm);
USEFORM("..\replib\src\RepTripInfoResultForm.cpp", TourTripInfoResultForm);
USEUNIT("..\replib\src\RepTripInfoGenerator.cpp");
USEUNIT("..\replib\src\RepStopInfoGenerator.cpp");
USEFORM("..\replib\src\RepStopInfoResultForm.cpp", TourStopInfoResultForm);
USEUNIT("..\graphlib\src\TripDiagramPrinter.cpp");
USEFORM("..\toollib\src\TripSwitchDialogForm.cpp", TourTripSwitchDialogForm);
USEFORM("..\toollib\src\TripTimetableForm.cpp", TourTripTimeTableDialogForm);
USEFORM("..\toollib\src\TripTimetableInfoForm.cpp", TourTripTimetableInfoForm);
USEFORM("..\toollib\src\TripTimetableRecalcBySpeedForm.cpp", TourTripTimetableRateSpeedForm);
USEFORM("..\toollib\src\TripTourMoveDialogForm.cpp", TourTripTourMoveDialogForm);
USEFORM("..\toollib\src\TripTourCopyDialogForm.cpp", TourTripTourCopyDialogForm);
USEFORM("..\toollib\src\PathMasterProcessForm.cpp", TourPathMasterProcessForm);
USEFORM("..\datalib\TourDataDBDataModule.cpp", TourDataDBModule); /* TDataModule: File Type */
USEUNIT("..\datalib\TourTime.cpp");
USEUNIT("..\datalib\TourData.cpp");
USEUNIT("..\datalib\TourDataDB.cpp");
USEUNIT("..\datalib\TourDataSF.cpp");
USEUNIT("..\datalib\TourDataCA.cpp");
USEUNIT("..\datalib\TourDataCU.cpp");
USEFORM("..\reflib\src\TableGridSelectForm.cpp", TourRefBookTableGridSelectForm);
USEFORM("..\reflib\src\StopSelectForm.cpp", TourRefBookStopSelectForm);
USEFORM("..\graphlib\src\TripDiagramChangesForm.cpp", TourDiagramChangesForm);
USEFORM("..\reflib\src\SimpleProcessForm.cpp", TourSimpleProcessForm);
USEFORM("..\reflib\src\BusSimpleProcessForm.cpp", TourBusSimpleProcessForm);
USEFORM("..\reflib\src\BusSimpleAddForm.cpp", TourBusSimpleAddForm);
USEFORM("..\reflib\src\BusSimpleEditForm.cpp", TourBusSimpleEditForm);
USEFORM("..\reflib\src\CitySimpleProcessForm.cpp", TourCitySimpleProcessForm);
USEFORM("..\reflib\src\CitySimpleAddForm.cpp", TourCitySimpleAddForm);
USEFORM("..\reflib\src\CitySimpleEditForm.cpp", TourCitySimpleEditForm);
USEFORM("..\reflib\src\RegionSimpleProcessForm.cpp", TourRegionSimpleProcessForm);
USEFORM("..\reflib\src\RegionSimpleAddForm.cpp", TourRegionSimpleAddForm);
USEFORM("..\reflib\src\RegionSimpleEditForm.cpp", TourRegionSimpleEditForm);
USEFORM("..\reflib\src\StopModelSimpleProcessForm.cpp", TourStopModelSimpleProcessForm);
USEFORM("..\reflib\src\StopModelSimpleAddForm.cpp", TourStopModelSimpleAddForm);
USEFORM("..\reflib\src\StopModelSimpleEditForm.cpp", TourStopModelSimpleEditForm);
USEFORM("..\reflib\src\TripOwnerSimpleProcessForm.cpp", TourTripOwnerSimpleProcessForm);
USEFORM("..\reflib\src\TripOwnerSimpleAddForm.cpp", TourTripOwnerSimpleAddForm);
USEFORM("..\reflib\src\TripOwnerSimpleEditForm.cpp", TourTripOwnerSimpleEditForm);
USEFORM("..\reflib\src\StopOwnerSimpleProcessForm.cpp", TourStopOwnerSimpleProcessForm);
USEFORM("..\reflib\src\StopOwnerSimpleAddForm.cpp", TourStopOwnerSimpleAddForm);
USEFORM("..\reflib\src\StopOwnerSimpleEditForm.cpp", TourStopOwnerSimpleEditForm);
USEFORM("..\replib\src\RepStopInfoInputForm.cpp", TourRepStopInfoInputForm);
USEFORM("..\replib\src\RepTripInfoInputForm.cpp", TourRepTripInfoInputForm);
USEUNIT("..\toollib\src\TourProtect.cpp");
USEFORM("..\toollib\src\SimpleDataSetViewForm.cpp", TourSimpleDataSetViewForm);
USEFORM("..\toollib\src\BaseRegulationForm.cpp", TourBaseRegulationForm);
USEFORM("..\reflib\src\StopSimpleProcessForm.cpp", TourStopSimpleProcessForm);
USEFORM("..\reflib\src\StopSimpleAddForm.cpp", TourStopSimpleAddForm);
USEFORM("..\reflib\src\StopSimpleEditForm.cpp", TourStopSimpleEditForm);
USEFORM("..\tripformlib\src\PathSimpleProcessForm.cpp", TourPathSimpleProcessForm);
USEFORM("..\tripformlib\src\PathSimpleAddForm.cpp", TourPathSimpleAddForm);
USEFORM("..\tripformlib\src\PathSimpleEditForm.cpp", TourPathSimpleEditForm);
USEFORM("..\tripformlib\src\TripSimpleProcessForm.cpp", TourTripSimpleProcessForm);
USEFORM("..\tripformlib\src\TripSimpleAddForm.cpp", TourTripSimpleAddForm);
USEFORM("..\tripformlib\src\TripSimpleEditForm.cpp", TourTripSimpleEditForm);
USEFORM("..\toollib\src\SimpleStopDataSetViewForm.cpp", TourSimpleStopDataSetViewForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
 {
        TourDataModule = NULL;
        TourMainFrame  = NULL;
        TourLoginForm  = NULL;
        TourMessageModule = NULL;

        try
         {
          Application->Initialize();
          Application->Title = "Tour";
          Application->CreateForm(__classid(TTourMainFrame), &TourMainFrame);
                 Application->CreateForm(__classid(TTourLoginForm), &TourLoginForm);
                 OnGetDefaultIniName = TourDefaultIniNameStr;

          TourMainFrame->Show();

          if (TourLoginForm->ShowModal() == mrOk)
           {
            if (TourLoginForm != NULL)
             {
              delete (TourLoginForm);
              TourLoginForm = NULL;
             }

            TourMainFrame->DoFlightDiagramActionExecute(NULL);

            Application->Run();
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
