//---------------------------------------------------------------------------

#ifndef PathMasterProcessFormH
#define PathMasterProcessFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VDBLookupComboBox.h"
#include "VStringStorage.h"
#include <ADODB.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TTourPathMasterProcessForm : public TForm
{
__published:	// IDE-managed Components
        TButton *CancelButton;
        TButton *SaveButton;
        TVStringStorage *VStringStorage;
        TLabel *PathNormSpeedLabel;
        TLabel *PathFromStopIdLabel;
        TLabel *PathLengthLabel;
        TLabel *PathToStopIdIdLabel;
        TDataSource *StopDataSource;
        TADOQuery *StopQuery;
        TEdit *PathNormSpeedEdit;
        TEdit *PathLengthEdit;
        TEdit *StopFromEdit;
        TButton *StopFromButton;
        TEdit *StopToEdit;
        TButton *StopToButton;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall StopFromButtonClick(TObject *Sender);
        void __fastcall StopToButtonClick(TObject *Sender);
private:
        bool FStopSelectMode;	// User declarations
 bool              StopSelectDialog
                   (AnsiString                       *StopIdStrPtr,
                    AnsiString                       *StopNameStrPtr);
        void __fastcall SetStopIdFrom(AnsiString value);
        AnsiString __fastcall GetStopIdFrom();
        void __fastcall SetStopIdTo(AnsiString value);
        AnsiString __fastcall GetStopIdTo();
        void __fastcall SetStopSelectMode(bool value);
        bool __fastcall GetStopSelectMode();
protected:
 AnsiString                            StopFromIdStr;
 AnsiString                            StopToIdStr;
public:		// User declarations
        __fastcall TTourPathMasterProcessForm(TComponent* Owner);
        __property AnsiString StopIdFrom  = { read=GetStopIdFrom, write=SetStopIdFrom };
        __property AnsiString StopIdTo  = { read=GetStopIdTo, write=SetStopIdTo };
        __property bool StopSelectMode  = { read=GetStopSelectMode, write=SetStopSelectMode };
};
//---------------------------------------------------------------------------
extern PACKAGE TTourPathMasterProcessForm *TourPathMasterProcessForm;
//---------------------------------------------------------------------------
#endif
