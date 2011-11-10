//---------------------------------------------------------------------------

#ifndef TripDiagramFormH
#define TripDiagramFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include "RXDBCtrl.h"
#include "VDBSortGrid.h"
#include "VDBLookupComboBox.h"
#include "Placemnt.h"
#include "VADODataSourceOrdering.h"
#include "VCustomDataSourceOrdering.h"
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include "VStringStorage.h"

#include <vector>
#include <string>
#include <VCanvas.h>

#include "TourDataCU.h"

//#include <TripDiagramData.h>
#include <TourData.h>

//---------------------------------------------------------------------------

#define TripDiagramTourIndexUndefined       (0xFFFFFFFFL)
#define TripDiagramStopIndexUndefined       (0xFFFFFFFFL)
#define TripDiagramTourSpeedUndefined       (-1)
#define TripDiagramTourDinstanceUndefined   (-1)

extern int         TripDiagramCompareDouble
                   (AnsiString                        FirstValueStr,
                    AnsiString                        SecondValueStr);

extern int         TripDiagramCompareTime
                   (AnsiString                        Time1ValueStr,
                    AnsiString                        Time2ValueStr);

extern AnsiString  TripDiagramTimeInMinutesToStr
                   (unsigned int                      Time);

extern unsigned int
                   TripDiagramTimeInStrToMinutes
                   (AnsiString                        TimeStr);

typedef struct
 {
  AnsiString       StopIdStr;
  AnsiString       StopNameStr;
  AnsiString       TripStepInTimeStr;
  AnsiString       TripStepWaitTimeStr;
 } TripDiagramTimeTableItemType;

typedef struct
 {
  float            Distance;
  std::string      StopIdStr;
 } TripDiagramStopDistanceInfoType;

class TripDiagramStopDistanceCacheClass
 {
  #define          Self                TripDiagramStopDistanceCacheClass

  public :

                   Self               (void);

  void             Load               (TourDataPtrClass    SourceDataPtr);

  void             Clear              (void);                 
  float            Distance           (unsigned int        FromStopIndex,
                                       unsigned int        ToStopIndex);                   

  float            DistanceFromFirst  (unsigned int        ToStopIndex);
  float            DistanceToLast     (unsigned int        FromStopIndex);

  float            DistanceFromFirst  (const std::string  &ToStopIdStr);

  private :

  bool             GetStopIndexByIdStr(unsigned int       *StopIndexPtr,
                                       const std::string  &StopIdStr);

  std::vector<TripDiagramStopDistanceInfoType>
                                       DistanceArray; 

  #undef           Self
 };

typedef  std::vector<TripDiagramTimeTableItemType>    TripDiagramTimeTableItemStoreVectorType;

extern unsigned int
                   TripDiagramTourIndexById
                   (TourTourSetPtrClass               TourSetPtr,
                    AnsiString                        TourIdStr);

extern bool        TripDiagramTourIsACopy
                   (TourTourSetPtrClass               TourSetPtr,
                    unsigned int                      TourIndex);

extern bool        TripDiagramTourCopyAttributes
                   (TourTourSetPtrClass               TourSetPtr,
                    unsigned int                      TourIndex,
                    AnsiString                       &TourIdStrRef,
                    AnsiString                       &TourFirstNameStrRef,
                    AnsiString                       &TourSecondNameStrRef);

extern bool        TripDiagramMoveTour
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TDateTime                         DateTimeValue);

extern bool        TripDiagramReflectTour
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr);

extern TourTourPtrClass
                   TripDiagramAppendTour
                   (TourDataPtrClass                  TourDataPtr,
                    AnsiString                        NewTourIdStr);

extern void        TripDiagramFillTour
                   (TourTourPtrClass                  DestTourPtr,
                    TourTourPtrClass                  SrcTourPtr);

extern bool        TripDiagramInvertTour
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr);

extern bool        TripDiagramPrepareToReflectTour
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr);

extern bool        TripDiagramCanReflectTour
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr);

float              TripDiagramTourStepSpeed
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr,
                    unsigned int                      StepIndex);

float              TripDiagramTourStepDistance
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr,
                    unsigned int                      StepIndex);

extern bool        TripDiagramNextStopPreliminaryTimeIn
                   (TourTourSchedulePtrClass          TourSchedulePtr,
                    TourTopologyPtrClass              TopologyPtr,
                    unsigned int                      StopIndex,
                    float                             SpeedValue,
                    unsigned short                   &HoursRef,
                    unsigned short                   &MinutesRef);

class TTourTripDiagramForm;
                    
class TTourTripDiagramCanvasEventHandlerClass : public VCanvasEventHandlerClass
 {
  #define               Self           TTourTripDiagramCanvasEventHandlerClass

  public :

                        Self          (TTourTripDiagramForm
                                                          *FormPtr);

  virtual void          OnClick       (VCanvasHandleType   ItemHandle,
                                       unsigned int        ButtonCode,
                                       int                 PosX,
                                       int                 PosY);

  private :

  TTourTripDiagramForm                *FormPtr;
  
  #undef                Self                                       
 };

typedef struct
 {
  bool                                 VisibleFlag;
  VCanvasColorType                     Color;
  VCanvasPenType                       PenStyle;
 } TripDiagramTourViewType;

class TTourTripDiagramForm : public TForm
{
 friend class           TTourTripDiagramCanvasEventHandlerClass;

 __published:	   // IDE-managed Components

 TScrollBox                                *ChartScrollBox;
 TPanel                                    *EditPanel;
 TFormStorage                              *FormStorage;
 TImageList                                *FakeImageList;
 TPopupMenu                                *ChartPopupMenu;
 TMenuItem                                 *ScalePopupMenuItem;
 TMenuItem                                 *Scale25PrcPopupMenuItem;
 TMenuItem                                 *Scale50PrcPopupMenuItem;
 TMenuItem                                 *Scale75PrcPopupMenuItem;
 TMenuItem                                 *Scale100PrcPopupMenuItem;
 TMenuItem                                 *Scale150PrcPopupMenuItem;
 TMenuItem                                 *Scale200PrcPopupMenuItem;
 TPaintBox                                 *ChartPaintBox;
 TMenuItem                                 *ShowGridPopupMenuItem;
 TMenuItem                                 *ShowForwardToursPopupMenuItem;
 TMenuItem                                 *ShowBackwardToursPopupMenuItem;
 TMenuItem                                 *OptionsDialogPopupMenuItem;
 TListView                                 *TourListView;
 TListView                                 *TimetableListView;
 TMenuItem                                 *MonoColorToursPopupMenuItem;
 TMenuItem                                 *PrintPopupMenuItem;
 TMenuItem                                 *PrintTourInfoPopupMenuItem;
 TMenuItem                                 *PrintStopPopupMenuItem;
 TMenuItem                                 *Scale500PrcPopupMenuItem;
 TMenuItem                                 *PrintDiagramPopupMenuItem;
 TSplitter                                 *GroupToTimetableSplitter;
 TSplitter                                 *HorizSplitter;
 TMenuItem                                 *PrintDiagramFullPopupMenuItem;
 TMenuItem                                 *ScaleFitToHeightPrcPopupMenuItem;
 TPopupMenu                                *TourListViewPopupMenu;
 TMenuItem                                 *TourMoveMenuItem;
 TActionList                               *TourListViewActionList;
 TAction                                   *TourMoveAction;
 TAction                                   *TourInvertAction;
 TAction                                   *TourCopyAction;
 TMenuItem                                 *TourInvertMenuItem;
 TMenuItem                                 *TourCopyMenuItem;
 TVStringStorage                           *VStringStorage;
 TAction                                   *TourDeleteAction;
        TMenuItem *TourDeleteMenuItem;
        TMenuItem *ShowTourInOutRowPopupMenuItem;
        TPanel *InfoPanel;
        TSplitter *TimetableToHintSplitter;
        TPanel *Panel1;
        TLabel *BusModelLabel;
        TLabel *BusModelValueLabel;
        TLabel *BusCapacityLabel;
        TLabel *BusCapacityValueLabel;
        TLabel *TripPathLengthLabel;
        TLabel *TripPathLengthValueLabel;
        TLabel *TripPathTimeLabel;
        TLabel *TripPathTimeValueLabel;
        TPanel *HintPanel;
        TLabel *HintTimeLabel;
        TLabel *HintTimeValueLabel;
        TLabel *HintFromLabel;
        TLabel *HintToLabel;
        TLabel *HintFromValueLabel;
        TLabel *HintToValueLabel;
        TPanel *ButtonsPanel;
        TButton *OkButton;
        TButton *CancelButton;

 void __fastcall   FormClose               (TObject       *Sender,
                                            TCloseAction  &Action);

 void __fastcall   ChartPaintBoxPaint      (TObject       *Sender);

 void __fastcall   FormCreate              (TObject       *Sender);

 void __fastcall   TourListViewSelectItem  (TObject       *Sender,
                                            TListItem     *Item,
                                            bool           Selected);

 void __fastcall TourListViewCustomDrawItem(TCustomListView *Sender,TListItem *Item, TCustomDrawState State, bool &DefaultDraw);
 void __fastcall ChartPaintBoxMouseDown(TObject *Sender,TMouseButton Button, TShiftState Shift, int X, int Y);
 void __fastcall Scale25PrcPopupMenuItemClick(TObject *Sender);
 void __fastcall Scale50PrcPopupMenuItemClick(TObject *Sender);
 void __fastcall Scale75PrcPopupMenuItemClick(TObject *Sender);
 void __fastcall Scale100PrcPopupMenuItemClick(TObject *Sender);
 void __fastcall Scale150PrcPopupMenuItemClick(TObject *Sender);
 void __fastcall Scale200PrcPopupMenuItemClick(TObject *Sender);
 void __fastcall ShowGridPopupMenuItemClick(TObject *Sender);
 void __fastcall ShowForwardToursPopupMenuItemClick(TObject *Sender);
 void __fastcall ShowBackwardToursPopupMenuItemClick(TObject *Sender);
 void __fastcall OptionsDialogPopupMenuItemClick(TObject *Sender);
 void __fastcall ChartPaintBoxMouseMove(TObject *Sender,TShiftState Shift, int X, int Y);
 void __fastcall ChartPaintBoxMouseUp(TObject *Sender,TMouseButton Button, TShiftState Shift, int X, int Y);
 void __fastcall MonoColorToursPopupMenuItemClick(TObject *Sender);
 void __fastcall PrintTourInfoPopupMenuItemClick(TObject *Sender);
 void __fastcall PrintStopPopupMenuItemClick(TObject *Sender);
 void __fastcall Scale500PrcPopupMenuItemClick(TObject *Sender);
 void __fastcall PrintDiagramPopupMenuItemClick(TObject *Sender);
 void __fastcall TourListViewChange(TObject *Sender,
          TListItem *Item, TItemChange Change);
 void __fastcall TourListViewDblClick(TObject *Sender);
 void __fastcall TimetableListViewDblClick(TObject *Sender);
 void __fastcall PrintDiagramFullPopupMenuItemClick(TObject *Sender);
 void __fastcall ScaleFitToHeightPrcPopupMenuItemClick(TObject *Sender);
 void __fastcall ScaleFitToWidthPrcPopupMenuItemClick(TObject *Sender);
 void __fastcall TourListViewColumnClick(TObject *Sender,
          TListColumn *Column);
 void __fastcall TourListViewCompare(TObject *Sender,
          TListItem *Item1, TListItem *Item2, int Data, int &Compare);
 void __fastcall TourMoveActionExecute(TObject *Sender);
 void __fastcall TourInvertActionExecute(TObject *Sender);
 void __fastcall TourCopyActionExecute(TObject *Sender);
 void __fastcall CancelButtonClick(TObject *Sender);
 void __fastcall OkButtonClick(TObject *Sender);
 void __fastcall TourDeleteActionExecute(TObject *Sender);
        void __fastcall ShowTourInOutRowPopupMenuItemClick(
          TObject *Sender);

 private:	   // User declarations

 TTourTripDiagramCanvasEventHandlerClass    CanvasEventHandler;
 unsigned int                               SelectedTourIndex;
 unsigned int                               BaseStopIndex;

 // Notify methods - call them if something changed in diagram state

 void              NotifySelectedTourChanged
                                           (void);
 void              NotifySelectedTourScheduleChanged
                                           (void);
 void              NotifyBaseStopChanged   (void);

 // Chart state methods

 void              SetViewScale            (float          Scale);
 void              ShowForwardTours        (void);
 void              ShowBackwardTours       (void);
 void              HideForwardTours        (void);
 void              HideBackwardTours       (void);

 void              HideTour                (unsigned int   TourIndex);
 void              ShowTour                (unsigned int   TourIndex);

 bool              MoveTour                (unsigned int   TourIndex,
                                            TDateTime      DateTimeValue);

 TourTourPtrClass  DublicateTour           (unsigned int   TourIndex,
                                            AnsiString     NewTourIdStr,
                                            AnsiString     NewTourNameStr);

 bool              IsTourVisible           (unsigned int   TourIndex);
 bool              IsTourForward           (unsigned int   TourIndex);

 // Call this method if any of the tour data has been changed

 void              UpdateChart             (void);

 void              DrawToRow               (int            PosX,
                                            int            PosY,
                                            bool           UpFlag);

 void              DrawFromRow             (int            PosX,
                                            int            PosY,
                                            bool           UpFlag);

 // Loading data from database methods

 void              LoadDBData              (const std::vector<std::string>
                                                          &StopIdStrArray,
                                            const AnsiString
                                                          &BaseTourIdStr);
/*
 void              LoadStopInfoDBData      (TripDiagramStopInfoType
                                                          &TargetStopInfo,
                                            const AnsiString &StopIdStr);
*/
 void              UpdateColorTable        (void);

 void              RecalcTimeScale         (void);
 void              ScrollToTour            (unsigned int   TourIndex);

 VCanvasClass      ChartCanvas;

 // Chart support functions

 int               TimeToPixels            (float          Time);
 int               DistanceToPixels        (float          Distance);

 // Convert metods
 
 // TOFIX: Параметр TourIndex или TourPtr избыточен, пока это необходимо
 // для повышения быстродействия (после реализации кэша необходимо удалить
 // параметр TourPtr)

 // TourListView methods
 bool              TourListViewTourAppend  (unsigned int     TourIndex,
                                            TourTourPtrClass TourPtr);

 bool              FillTourListView        (void);
 void              FreeTourListView        (void);
 void              UpdateTourListBaseOutTime
                   (void);

 TListItem        *TourListViewItemByData  (unsigned int   DataValue);

// bool              FillTourListViewStateFlag;
 int               TourListViewColumnToSort;
 bool              TourListSortLockFlag;

 // TimetableListView methods

 bool              FillTimetableListView   (unsigned int   TourIndex);

 // Tour info metods
 float             TourStepSpeed
                   (TourTourSchedulePtrClass                TourPtr,
                    unsigned int                            StepIndex);
 AnsiString        TourStepSpeedStr
                   (TourTourSchedulePtrClass                TourPtr,
                    unsigned int                            StepIndex);

 float             TourStepDistance
                   (TourTourSchedulePtrClass                TourPtr,
                    unsigned int                            StepIndex);
 AnsiString        TourStepDistanceStr
                   (TourTourSchedulePtrClass                TourPtr,
                    unsigned int                            StepIndex);

 AnsiString        GetTourListTourCaptionStr
                   (TourTourPtrClass                  TourPtr);
 AnsiString        GetTourListTourAverageSpeedStr
                   (TourTourPtrClass                  TourPtr);
 AnsiString        GetTourListTourTotalDistanceStr
                   (TourTourPtrClass                  TourPtr);
 AnsiString        GetTourListTourBaseInTimeStr
                   (TourTourSchedulePtrClass          TourSchedulePtr);
 AnsiString        GetTourListTourBaseOutTimeStr
                   (TourTourSchedulePtrClass          TourSchedulePtr);

 void              ApplyChanges            (void);
 void              CancelChanges           (void);

 // User actions (visualisation)
 bool              TourSelectDialogExec    (void);
 // User actions (functionality)
 bool              TourTimetableDialogExec
                   (unsigned int                      TourIndex);

 bool              TourCopyDialogExec
                   (unsigned int                      TourIndex,
                    TourTourPtrClass                 &TourPtrRef,
                    bool                              InvertTourNameFlag);

 bool              GetTourCopyAttributes
                   (unsigned int                      TourIndex,
                    AnsiString                       &TourIdStrRef,
                    AnsiString                       &TourFirstNameStrRef,
                    AnsiString                       &TourSecondNameStrRef);

 // Chart parameters

 float             TimeBaseScale;     // Pixels/Hour for ViewScale = 1
 float             DistanceBaseScale; // Pixel/Km    for ViewScale = 1
 float             TimeViewScale;     // Scale = 1 is 100% (24 hours fills X axis)
 float             DistanceViewScale; // Scale = 1 is 100% (Max distance fills Y axis)
 float             BaseSpeed;
 unsigned int      BaseSpeedAngle;
 bool              ShowDistanceGridFlag;
 bool              ShowTimeGridFlag;
 bool              ShowForwardToursFlag;
 bool              ShowBackwardToursFlag;
 bool              ShowTourInOutRowsFlag;
 bool              MonoColorTourModeFlag;
 unsigned int      StopNameMaxWidth;
 bool              ZeroWaitTimeCircleModeFlag;

 VCanvasColorType  ChartGridColor;
 VCanvasColorType  ChartCommonTourColor;
 VCanvasColorType  ChartSelectedTourColor;

 // MouseState parameters

 int               LastMousePosX;
 int               LastMousePosY;
 bool              ButtonLeftPressedFlag;

 int               CompareDouble
                   (AnsiString                        FirstValueStr,
                    AnsiString                        SecondValueStr);
 int               CompareTime
                   (AnsiString                        Time1ValueStr,
                    AnsiString                        Time2ValueStr);

 TourDataPtrClass                           DataStoragePtr;
 TourDataPtrClass                           ChartDataStoragePtr;
 TourCachedUpdateDataClass                 *CachedUpdateDataStoragePtr;
 std::vector<TripDiagramTourViewType>       TourViewInfoArray;
 TripDiagramStopDistanceCacheClass          DistanceCache;

 public:	   // User declarations
 bool              InfoPanelUpdate();

 __fastcall        TTourTripDiagramForm    (TComponent    *Owner);
 __fastcall        TTourTripDiagramForm    (TComponent    *Owner,
                                            const std::vector<std::string>
                                                          &StopIdStrArray,
                                            AnsiString     BaseTourIdStr = "");
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripDiagramForm *TourTripDiagramForm;
//---------------------------------------------------------------------------
#endif

