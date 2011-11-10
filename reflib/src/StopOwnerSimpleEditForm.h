//---------------------------------------------------------------------------

#ifndef StopOwnerSimpleEditFormH
#define StopOwnerSimpleEditFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StopOwnerSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTourStopOwnerSimpleEditForm : public TTourStopOwnerSimpleProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
        __fastcall TTourStopOwnerSimpleEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourStopOwnerSimpleEditForm *TourStopOwnerSimpleEditForm;
//---------------------------------------------------------------------------
#endif
