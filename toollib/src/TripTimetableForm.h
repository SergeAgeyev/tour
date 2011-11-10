//---------------------------------------------------------------------------

#ifndef TripTimetableFormH
#define TripTimetableFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <ActnList.hpp>
#include "VStringStorage.h"
#include <Buttons.hpp>
#include <Menus.hpp>
#include "TripDiagramForm.h"
#include "TourData.h"
#include <ExtCtrls.hpp>
#include "Placemnt.h"

#include <string>
#include <vector>

#define TourTripTimeTableUndefineTourIndex      (-1)

using namespace std;

enum TourTripTimeTableStringTypes
 {
  TourTripTimeTableCaptionStr = 0,
  TourTripTimeTableTripSelectCaptionStr,
  TourTripTimeTableMoveDialogCaptionStr,
  TourTripTimeTableInvertDialogCaptionStr,
  TourTripTimeTableCopyDialogCaptionStr,
  TourTripTimeTableInvalidTimeValueMessageStr,
  TourTripTimeTableStringTypesEnumCount
 };

//---------------------------------------------------------------------------
class TTourTripTimeTableDialogForm : public TForm
{
__published:    // IDE-managed Components
 TListView *ChainListView;
 TPopupMenu *ChainPopupMenu;
        TMenuItem *ChangeInfoMenuItem;
        TMenuItem *UpdateBySpeedMenuItem;
        TMenuItem *MoveMenuItem;
        TMenuItem *InvertMenuItem;
        TMenuItem *N1;
        TMenuItem *DeleteStopMenuItem;
        TMenuItem *AppendStopMenuItem;
        TMenuItem *InsertStopMenuItem;
        TPanel *Panel;
        TVStringStorage *VStringStorage;
        TActionList *ActionList;
        TAction *ChangeInfoAction;
        TAction *UpdateBySpeedAction;
        TAction *MoveAction;
        TAction *InvertAction;
        TAction *CopyAction;
        TAction *DeleteStopAction;
        TAction *InsertStopAction;
        TAction *AppendStopAction;
        TButton *NextButton;
        TButton *CancelButton;
        TFormStorage *FormStorage;
        void __fastcall ChangeInfoActionExecute(TObject *Sender);
        void __fastcall UpdateBySpeedActionExecute(TObject *Sender);
        void __fastcall ChainPopupMenuPopup(TObject *Sender);
        void __fastcall MoveActionExecute(TObject *Sender);
        void __fastcall InvertActionExecute(TObject *Sender);
        void __fastcall DeleteStopActionExecute(TObject *Sender);
        void __fastcall AppendStopActionExecute(TObject *Sender);
        void __fastcall InsertStopActionExecute(TObject *Sender);
        void __fastcall PanelResize(TObject *Sender);
//        void __fastcall CopyActionExecute(TObject *Sender);

private:        // User declarations
 bool              FillChainListView   (void);

 bool              GetNextStopPreliminaryTimeIn
                   (unsigned int                      StopIndex,
                    float                             SpeedValue,
                    TourTimeClass                    &PreliminaryTimeInRef);
//                    TDateTime                        &PreliminaryTimeInRef);

protected:
/*
 TripDiagramTimeTableItemStoreVectorType
                                      *ChainStrStorePtr;
 TripDiagramRouteDataClass            *RouteDataPtr;
 TripDiagramTourDataClass             *TourDataPtr;
*/
 int                                   TourIndex;
 TourDataPtrClass                      DataStoragePtr;
 TourStopSetPtrClass                   StopSetPtr;
 TourTourSetPtrClass                   TourSetPtr;
 TourTourPtrClass                      TourPtr;
 TourTourSchedulePtrClass              TourSchedulePtr;
 TourTopologyPtrClass                  TopologyPtr;
public:         // User declarations

 vector<int>                          *TourCopyStoragePtr;

 virtual bool      Init
                   (int                               TourIndex,
                    TourDataPtrClass                  DataStoragePtr);//,
//                    TourTourSetPtrClass               TourSetPtr,
//                    TourTopologyPtrClass              TopologyPtr);
/*
                    TripDiagramTimeTableItemStoreVectorType
                                                     *ChainStrStorePtr,
                    TripDiagramTourDataClass         *TourDataPtr,
                    TripDiagramRouteDataClass        *RouteDataPtr,
                    vector<int>                      *TourCopyStoragePtr);
*/
 __fastcall        TTourTripTimeTableDialogForm
                   (TComponent                       *Owner);
 __fastcall        TTourTripTimeTableDialogForm
                   (TComponent                       *Owner,
                    int                               TourIndex,
                    TourDataPtrClass                  DataStoragePtr);//,
//                    TourTourSetPtrClass               TourSetPtr,
//                    TourTopologyPtrClass              TopologyPtr);
/*
                    TripDiagramTimeTableItemStoreVectorType
                                                     *ChainStrStorePtr,
                    TripDiagramTourDataClass         *TourDataPtr,
                    TripDiagramRouteDataClass        *RouteDataPtr,
                    vector<int>                      *TourCopyStoragePtr);
*/
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripTimeTableDialogForm *TourTripTimeTableDialogForm;
//---------------------------------------------------------------------------
#endif
