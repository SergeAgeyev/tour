//---------------------------------------------------------------------------

#ifndef SessionTimeFormH
#define SessionTimeFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTourSessionTimeForm : public TForm
{
__published:    // IDE-managed Components
 TLabel *TimeLabel;
 TTimer *Timer;
 void __fastcall TimerTimer(TObject *Sender);
 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
 void __fastcall FormShow(TObject *Sender);
 void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:        // User declarations
public:         // User declarations
 __fastcall TTourSessionTimeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourSessionTimeForm *TourSessionTimeForm;
//---------------------------------------------------------------------------
#endif
