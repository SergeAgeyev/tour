#include <ADOdb.hpp>
#include <TourProtect.h>

static char TourProtectDBMSNamePropertyNameStr[] = "DBMS Name";

TourProtectInfoType 
 TourProtectInfoMinimalVersion =
  {
   "ACCESS",
   0
  };

static bool        GetPropertyIndexByName
                                      (TADOConnection     *ConnectionPtr,
                                       const char         *NameStrPtr,
                                       unsigned int       *IndexPtr)
 {
  unsigned int                         PropertyIndex;
  unsigned int                         PropertyLimit;
  bool                                 FoundFlag;
  AnsiString                           PropertyNameStr;

  PropertyIndex = 0;
  PropertyLimit = ConnectionPtr->Properties->Count;
  FoundFlag     = false;

  while ((!FoundFlag) && (PropertyIndex < PropertyLimit))
   {
    PropertyNameStr = ConnectionPtr->Properties
                       ->Item[Variant((int)PropertyIndex)]->Name;

    if (PropertyNameStr == NameStrPtr)
     {
      FoundFlag = true;
      *IndexPtr = PropertyIndex;
     }
    else
     {
      PropertyIndex++;
     }
   }

  return(FoundFlag);
 }

static bool        GetPropertyValueByName
                                      (TADOConnection     *ConnectionPtr,
                                       const char         *NameStrPtr,
                                       AnsiString         &ValueStr)
 {
  unsigned int                         PropertyIndex;

  if (GetPropertyIndexByName(ConnectionPtr,NameStrPtr,&PropertyIndex))
   {
    ValueStr = ConnectionPtr->Properties
                ->Item[Variant((int)PropertyIndex)]->Value.AsType(varString);

    return(true);
   }
  else
   {
    return(false);
   }
 }


extern bool        TourProtectCheck   (TADOConnection      *ConnectionPtr,
                                       const 
                                       TourProtectInfoType *ProtectionInfoPtr)
 {
  bool                                 ValidFlag;
  AnsiString                           DBMSNameStr;

  ValidFlag = true;

  if (ValidFlag)
   {
    if (ProtectionInfoPtr->DBMSNameStrPtr != NULL)
     {
      if (GetPropertyValueByName
           (ConnectionPtr,
            TourProtectDBMSNamePropertyNameStr,
            DBMSNameStr))
       {
        if (DBMSNameStr != ProtectionInfoPtr->DBMSNameStrPtr)
         {
          ValidFlag = false;
         }
       }
      else
       {
        ValidFlag = false;
       }
     }
   }

  return(ValidFlag);
 }

