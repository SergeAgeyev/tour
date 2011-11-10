//---------------------------------------------------------------------------

#ifndef MainFrameH
#define MainFrameH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ActnList.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <StdActns.hpp>
#include <ExtCtrls.hpp>
#include "VStringStorage.h"
//---------------------------------------------------------------------------
class TTourMainFrame : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu;
 TMenuItem *SessionMenuItem;
 TMenuItem *SessionExitMenuItem;
        TStatusBar *StatusBar;
 TMenuItem *SessionCurrentDateMenuItem;
 TMenuItem *SessionCurrentTimeMenuItem;
 TMenuItem *SessionSeparatorMenuItem;
 TMenuItem *SetupMenuItem;
 TMenuItem *SetupStopPointTypesMenuItem;
 TMenuItem *SetupTransportTypesMenuItem;
        TMenuItem *DataBaseMenuItem;
 TMenuItem *ObjectsTopologyMenuItem;
 TMenuItem *ObjectsTransportationsMenuItem;
 TMenuItem *ObjectsStopPointOwnersMenuItem;
 TMenuItem *ObjectsTransportersMenuItem;
 TMenuItem *DoMenuItem;
 TMenuItem *ReportsMenuItem;
 TMenuItem *HelpMenuItem;
 TMenuItem *HelpUserGuideMenuItem;
 TMenuItem *HelpAboutMenuItem;
 TMenuItem *HelpSeparatorMenuItem;
        TActionList *ActionList;
        TAction *SessionExitAction;
 TMenuItem *WindowMenuItem;
 TMenuItem *WindowCascadeMenuItem;
 TMenuItem *WindowTileHorzMenuItem;
 TMenuItem *WindowTileVertMenuItem;
 TWindowCascade *WindowCascadeAction;
 TWindowTileHorizontal *WindowTileHorzAction;
 TWindowTileVertical *WindowTileVertAction;
 TMenuItem *WindowArrangeMenuItem;
 TMenuItem *WindowMinimizeAllMenuItem;
 TWindowMinimizeAll *WindowMinimizeAllAction;
 TWindowArrange *WindowArrangeAction;
 TMenuItem *DoFlightDataNewMenuItem;
 TTimer *ClockTimer;
 TTimer *DataTimer;
 TMenuItem *ObjectsPopulatedPointsMenuItem;
 TMenuItem *ObjectsRegionsMenuItem;
 TMenuItem *ObjectsStopPointsMenuItem;
 TMenuItem *ObjectsWayAreasMenuItem;
 TMenuItem *ObjectsFlightsMenuItem;
 TMenuItem *ObjectsFlightTimetableMenuItem;
 TMenuItem *ObjectsTransportStatisticsMenuItem;
 TMenuItem *DoFlightDiagramMenuItem;
 TVStringStorage *VStringStorage;
        TAction *DoFlightDiagramWizardAction;
        TMenuItem *DoFlightDiagramWizardMenuItem;
        TMenuItem *ReportsStopInfoMenuItem;
        TMenuItem *ReportsTripInfoMenuItem;
        TAction *BaseRegulationAction;
        TMenuItem *N2;
        void __fastcall SessionExitActionExecute(TObject *Sender);
 void __fastcall HelpAboutActionExecute(TObject *Sender);
 void __fastcall ObjectsTransportationsFlightsActionExecute(
          TObject *Sender);
 void __fastcall ObjectsTopologyPopulatedPointsActionExecute(
          TObject *Sender);
 void __fastcall SetupStopPointTypesActionExecute(TObject *Sender);
 void __fastcall ObjectsTranportationsFlightTimetableActionExecute(
          TObject *Sender);
 void __fastcall SetupTransportTypesActionExecute(TObject *Sender);
 void __fastcall SessionCurrentDateActionExecute(TObject *Sender);
 void __fastcall SessionCurrentTimeActionExecute(TObject *Sender);
 void __fastcall DoFlightDataNewActionExecute(TObject *Sender);
 void __fastcall ObjectsTopologyRegionsActionExecute(TObject *Sender);
 void __fastcall ObjectsTopologyStopPointsActionExecute(TObject *Sender);
 void __fastcall DoFlightDiagramActionExecute(TObject *Sender);
 void __fastcall ObjectsTopologyWayAreasActionExecute(TObject *Sender);
 void __fastcall ObjectsTransportationsTransportStatisticsActionExecute(
          TObject *Sender);
 void __fastcall ObjectsStopPointOwnersActionExecute(TObject *Sender);
 void __fastcall ObjectsTransportersActionExecute(TObject *Sender);
 void __fastcall StatusBarResize(TObject *Sender);
 void __fastcall ClockTimerTimer(TObject *Sender);
 void __fastcall DataTimerTimer(TObject *Sender);
 void __fastcall FormCreate(TObject *Sender);
 void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall DoFlightDiagramWizardActionExecute(
          TObject *Sender);
        void __fastcall ReportsStopInfoMenuItemClick(TObject *Sender);
        void __fastcall ReportsTripInfoMenuItemClick(TObject *Sender);
        void __fastcall BaseRegulationActionExecute(TObject *Sender);
private:
public:		// User declarations
        __fastcall TTourMainFrame(TComponent* Owner);

 void MDIChildFormView(System::TMetaClass* InstanceClass,TForm ** FormPtr);
 void __fastcall TTourMainFrame::DisplayHint(TObject *Sender);
/*
 void RefreshUserInterfaceConfig(void);
 void MDIChildFilteredFormView(System::TMetaClass* InstanceClass,
                               System::TMetaClass* FilterFormInstanceClass,
                               TForm ** FormPtr);
*/
protected:
};
//---------------------------------------------------------------------------
extern PACKAGE TTourMainFrame *TourMainFrame;
//---------------------------------------------------------------------------
#endif
