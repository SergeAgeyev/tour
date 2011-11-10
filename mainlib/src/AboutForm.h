//---------------------------------------------------------------------------

#ifndef AboutFormH
#define AboutFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TTourAboutForm : public TForm
{
__published:    // IDE-managed Components
 TLabel *TourLabel;
 TImage *AboutImage;
 TButton *CloseButton;
 TLabel *AboutDescLabel;
 TLabel *CopyrightLabel;
        TLabel *VersionLabel;
 void __fastcall CloseButtonClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:        // User declarations
public:         // User declarations
 __fastcall TTourAboutForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourAboutForm *TourAboutForm;
//---------------------------------------------------------------------------
#endif
