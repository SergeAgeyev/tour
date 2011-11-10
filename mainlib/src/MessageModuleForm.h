//---------------------------------------------------------------------------

#ifndef MessageModuleFormH
#define MessageModuleFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VStringStorage.h"

enum TourMessageModuleStringTypes
 {
  TourMessageModuleIncorrectFuncArgsErrorMessageStr = 0,
  TourMessageModuleInvertExpectedMoreDataMessageStr,
  TourMessageModuleFuncDemoMessageStr,
  TourMessageModuleBaseRegulationMessageStr
 };
//---------------------------------------------------------------------------
class TTourMessageModule : public TDataModule
{
__published:	// IDE-managed Components
 TVStringStorage *VStringStorage;
private:	// User declarations
public:		// User declarations
 __fastcall TTourMessageModule(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourMessageModule *TourMessageModule;
//---------------------------------------------------------------------------
#endif
