//---------------------------------------------------------------------------

#ifndef ErrorMessageDialogFormH
#define ErrorMessageDialogFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VStringStorage.h"

//---------------------------------------------------------------------------
class TTourErrorMessageDialogForm : public TForm
{
__published:	// IDE-managed Components
 TLabel *ErrorMessageLabel;
 TButton *DetailsButton;
 TMemo *DetailsMemo;
 TVStringStorage *VStringStorage;
 TButton *CloseButton;
 void __fastcall DetailsButtonClick(TObject *Sender);
 void __fastcall FormCreate(TObject *Sender);
 void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
 bool DialogDetailsFlag;
 int StoredFormHeight;
 void UpdateByDetailsFlags();
public:		// User declarations
 __fastcall TTourErrorMessageDialogForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourErrorMessageDialogForm *TourErrorMessageDialogForm;
//---------------------------------------------------------------------------
#endif
