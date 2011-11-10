//---------------------------------------------------------------------------

#ifndef SessionDateFormH
#define SessionDateFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTourSessionDateForm : public TForm
{
__published:	// IDE-managed Components
 TLabel *DateLabel;
 TTimer *Timer;
 void __fastcall TimerTimer(TObject *Sender);
 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
 void __fastcall FormShow(TObject *Sender);
 void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
 __fastcall TTourSessionDateForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourSessionDateForm *TourSessionDateForm;
//---------------------------------------------------------------------------
#endif
