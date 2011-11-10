//---------------------------------------------------------------------------

#ifndef LoginFormH
#define LoginFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include "VStringStorage.h"
//---------------------------------------------------------------------------
class TTourLoginForm : public TForm
{
__published:	// IDE-managed Components
 TLabel *UserIDLabel;
 TLabel *PasswordLabel;
 TEdit *UserIDEdit;
 TEdit *PasswordEdit;
 TButton *AcceptButton;
 TButton *ExitButton;
 TVStringStorage *VStringStorage;
 void __fastcall AcceptButtonClick(TObject *Sender);
 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall UserIDEditExit(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
// TADOQuery *LoginQuery;
// Boolean LoginQueryCreate(void);
public:		// User declarations
 __fastcall TTourLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourLoginForm *TourLoginForm;
//---------------------------------------------------------------------------
#endif
