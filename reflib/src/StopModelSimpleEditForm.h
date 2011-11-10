//---------------------------------------------------------------------------

#ifndef StopModelSimpleEditFormH
#define StopModelSimpleEditFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StopModelSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTourStopModelSimpleEditForm : public TTourStopModelSimpleProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
        __fastcall TTourStopModelSimpleEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourStopModelSimpleEditForm *TourStopModelSimpleEditForm;
//---------------------------------------------------------------------------
#endif
