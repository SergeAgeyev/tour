//---------------------------------------------------------------------------

#ifndef StopSimpleEditFormH
#define StopSimpleEditFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StopSimpleProcessForm.h"
#include "VStringStorage.h"
#include <ExtCtrls.hpp>
#include "RxGrdCpt.h"
#include "VCustomKeyComboBox.h"
#include "VMemoKeyComboBox.h"
//---------------------------------------------------------------------------
class TTourStopSimpleEditForm : public TTourStopSimpleProcessForm
{
__published:    // IDE-managed Components
private:        // User declarations
public:         // User declarations
        __fastcall TTourStopSimpleEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourStopSimpleEditForm *TourStopSimpleEditForm;
//---------------------------------------------------------------------------
#endif
