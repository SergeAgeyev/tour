//---------------------------------------------------------------------------
#ifndef TourProtectH
#define TourProtectH

#include <ADOdb.hpp>

typedef struct
 {
  const char      *DBMSNameStrPtr;
  unsigned int     ActiveConnectionLimit;
 } TourProtectInfoType;

extern TourProtectInfoType TourProtectInfoMinimalVersion;

extern bool        TourProtectCheck   (TADOConnection      *ConnectionPtr,
                                       const
                                       TourProtectInfoType *ProtectionInfoPtr);

#endif

