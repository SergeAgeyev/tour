//---------------------------------------------------------------------------

#ifndef SimpleTourDataSetViewFormH
#define SimpleTourDataSetViewFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SimpleDataSetViewForm.h"
#include "VStringStorage.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "Placemnt.h"
enum TourSimpleTourDataSetViewStringTypes
 {
  TourSimpleTourDataSetViewChooseTourMessageStr = 0,
  TourSimpleTourDataSetViewEnumCount
 };
//---------------------------------------------------------------------------
class TTourSimpleTourDataSetViewForm : public TTourSimpleDataSetViewForm
{
__published:	// IDE-managed Components
        TFormStorage *FormStorage;
        void __fastcall ListViewColumnClick(TObject *Sender,
          TListColumn *Column);
        void __fastcall ListViewCompare(TObject *Sender, TListItem *Item1,
          TListItem *Item2, int Data, int &Compare);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall PanelResize(TObject *Sender);
private:	// User declarations
 int                                   ColumnToSort;
public:		// User declarations
        __fastcall TTourSimpleTourDataSetViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourSimpleTourDataSetViewForm *TourSimpleTourDataSetViewForm;
//---------------------------------------------------------------------------
#endif
