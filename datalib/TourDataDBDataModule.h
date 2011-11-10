//---------------------------------------------------------------------------

#ifndef TourDataDBDataModuleH
#define TourDataDBDataModuleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------
class TTourDataDBModule : public TDataModule
{
__published:	// IDE-managed Components
        TADOQuery *StopSetQuery;
        TADOQuery *StopDistanceQuery;
        TADOQuery *TourInfoQuery;
        TADOQuery *StopInfoQuery;
        TADOQuery *TourAverageSpeedQuery;
        TADOQuery *TourScheduleQuery;
        TADOQuery *TourDeleteQuery;
        TADOQuery *TourAppendQuery;
        TADOQuery *TourScheduleDeleteAllQuery;
        TADOQuery *TourScheduleAppendStopQuery;
        TADOQuery *TourScheduleDeleteStopQuery;
        TADOQuery *TourScheduleDecStepNumQuery;
        TADOQuery *TourScheduleUpdateToStopIdQuery;
        TADOQuery *TourScheduleIncStepNumQuery;
        TADOQuery *TourStopScheduleSetInTimeQuery;
        TADOQuery *TourSetQuery;
        TADOQuery *TourStopScheduleSetWaitTimeQuery;
        TADOQuery *TourSetNameQuery;
        TADOQuery *TourTotalDistanceQuery;
        TADOQuery *BusInfoQuery;
        TADOQuery *TourSetBusModelQuery;
private:	// User declarations
public:		// User declarations
        __fastcall TTourDataDBModule(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourDataDBModule *TourDataDBModule;
//---------------------------------------------------------------------------
#endif
