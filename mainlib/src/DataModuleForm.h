//---------------------------------------------------------------------------

#ifndef DataModuleFormH
#define DataModuleFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ADODB.hpp>
//---------------------------------------------------------------------------
class TTourDataModule : public TDataModule
{
__published:	// IDE-managed Components
 TADOConnection *TourDataBaseConnection;
private:	// User declarations
public:		// User declarations
  AnsiString                           CurrentClerkIdStr;
  bool                                 DataBaseEditModeFlag;

  //Дата клиента (Асторономическая)
  TDateTime VegaLocalDateTime(void) const;

  __fastcall TTourDataModule(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTourDataModule *TourDataModule;
//---------------------------------------------------------------------------
#endif
