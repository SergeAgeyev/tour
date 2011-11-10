//---------------------------------------------------------------------------

#ifndef BusSimpleEditFormH
#define BusSimpleEditFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "BusSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTourBusSimpleEditForm : public TTourBusSimpleProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
        __fastcall TTourBusSimpleEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourBusSimpleEditForm *TourBusSimpleEditForm;
//---------------------------------------------------------------------------
#endif
