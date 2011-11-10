//---------------------------------------------------------------------------

#ifndef PathSimpleEditFormH
#define PathSimpleEditFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "PathSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>
#include "RxGrdCpt.h"
#include "VCustomKeyComboBox.h"
#include "VMemoKeyComboBox.h"
//---------------------------------------------------------------------------
class TTourPathSimpleEditForm : public TTourPathSimpleProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
        __fastcall TTourPathSimpleEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourPathSimpleEditForm *TourPathSimpleEditForm;
//---------------------------------------------------------------------------
#endif
