//---------------------------------------------------------------------------

#ifndef BaseRegulationFormH
#define BaseRegulationFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "VStringStorage.h"
#include <ADODB.hpp>
#include <Db.hpp>

enum TourBaseRegulationStringsTypes
 {
  TourBaseRegulationPathGenerationStr = 0,
  TourBaseRegulationPathGenerationCountStr,
  TourBaseRegulationPathGenerationDirectStr,
  TourBaseRegulationPathGenerationReversStr,
  TourBaseRegulationStringsCount
 };
//---------------------------------------------------------------------------
class TTourBaseRegulationForm : public TForm
{
__published:	// IDE-managed Components
        TRichEdit *RichEdit;
        TButton *CancelButton;
        TVStringStorage *VStringStorage;
        TADOQuery *GenerationReversePathQuery;
        TADOQuery *PathCountQuery;
        TADOQuery *DirectPathCountQuery;
        TButton *OkButton;
        void __fastcall OkButtonClick(TObject *Sender);
private:	// User declarations
        bool Execute (void);
public:		// User declarations
        __fastcall TTourBaseRegulationForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourBaseRegulationForm *TourBaseRegulationForm;
//---------------------------------------------------------------------------
#endif
