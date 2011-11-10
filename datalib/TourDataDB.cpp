
#include <string>
#include <vector>

#include <TripSmartPtr.h>
#include <TourTime.h>

#include <TourDataDBDataModule.h>

#include <TourData.h>
#include <TourDataDB.h>

#include "DataModuleForm.h"

static
TourTimeClass      TourDBDateTimeToTime(TDateTime          SourceTime)
 {
  unsigned short   Hours;
  unsigned short   Minutes;
  unsigned short   Seconds;
  unsigned short   MilliSeconds;

  SourceTime.DecodeTime(&Hours,&Minutes,&Seconds,&MilliSeconds);

  return(TourTimeClass(Hours,Minutes));
 }

static
TDateTime          TourTimeToDBDateTime(TourTimeClass      SourceTime)
 {
  return(TDateTime(2002,12,30) + TDateTime(SourceTime.Hours(),SourceTime.Minutes(),0,0));
 }

class TourDBBusClass : public TourBusClass
 {
  #define          Self                TourDBBusClass

  public           :

                   Self               (const std::string  &BusModelStr);
  virtual         ~Self               (void);

  virtual
  std::string      ModelStr           (void) const;

  virtual
  std::string      DescriptionStr     (void) const;

  virtual
  unsigned int     Capacity           (void) const;

  private          :

  void             Load               (void);
  
  bool                                 LoadedFlag;
  std::string                          BusModelStr;
  std::string                          BusDescStr;
  unsigned int                         BusCapacity;

  #undef           Self
 };

class TourDBStopClass : public TourStopClass
 {
  #define          Self                TourDBStopClass

  public           :

                   Self               (const std::string  &StopIdStr);
  virtual         ~Self               (void);

  virtual
  std::string      IdStr              (void) const;

  virtual
  std::string      NameStr            (void) const;

  private          :

  void             Load               (void);

  bool                                 LoadedFlag;
  std::string                          StopIdStr;
  std::string                          StopNameStr;

  #undef           Self
 };

typedef struct
 {
  std::string                          StopIdStr;
  TourTimeClass                        InTime;
  TourTimeClass                        WaitTime;
 } TourDBStopScheduleType;

class TourDBTourScheduleClass;

class TourDBStopScheduleClass : public TourStopScheduleClass
 {
  #define          Self                TourDBStopScheduleClass

  public           :

                   Self               (TourDBTourScheduleClass
                                                          *TourSchedulePtr,
                                       const std::string  &TourIdStr,
                                       unsigned int        StopIndex);

  virtual         ~Self               (void);

  virtual
  TourStopPtrClass Stop               (void) const;

  virtual
  TourTimeClass    InTime             (void) const;
  virtual
  TourTimeClass    WaitTime           (void) const;

  virtual void     SetInTime          (const TourTimeClass&Time);
  virtual void     SetWaitTime        (const TourTimeClass&Time);

  private          :

  TourDBTourScheduleClass             *TourSchedulePtr;
  std::string                          TourIdStr;
  unsigned int                         StopIndex;

  #undef           Self
 };

class TourDBTourScheduleClass : public TourTourScheduleClass
 {
  #define          Self                TourDBTourScheduleClass

  friend class                         TourDBStopScheduleClass;

  public           :

                   Self               (const std::string  &TourIdStr);
  virtual         ~Self               (void);

  virtual
  unsigned int     StopCount          (void) const;

  virtual
  TourStopSchedulePtrClass
                   StopSchedule       (unsigned int        StopIndex) const;

  virtual
  TourStopSchedulePtrClass
                   AppendStopSchedule (const std::string  &StopIdStr);

  virtual
  TourStopSchedulePtrClass
                   InsertStopSchedule (unsigned int        StopIndex,
                                       const std::string  &StopIdStr);

  virtual
  void             DeleteStopSchedule (unsigned int        StopIndex);

  private          :

  void             Load               (void);

  bool                                 LoadedFlag;
  std::string                          TourIdStr;
  std::vector<TourDBStopScheduleType>  StopScheduleArray;

  #undef           Self
 };

class TourDBTourClass : public TourTourClass
 {
  #define          Self                TourDBTourClass

  public           :

                   Self               (const std::string  &TourIdStr);
  virtual         ~Self               (void);

  virtual
  std::string      IdStr              (void) const;

  virtual
  std::string      NameStr            (void) const;

  virtual
  TourTourSchedulePtrClass
                   Schedule           (void) const;

  virtual
  TourBusPtrClass  Bus                (void) const;

  virtual
  float            AverageSpeed       (void) const;

  virtual
  float            TotalDistance      (void) const;

  virtual
  void             SetName            (const std::string  &NameStr);

  virtual
  void             SetBusModel        (const std::string  &ModelStr);

  private          :

  void             Load               (void);

  bool                                 LoadedFlag;
  std::string                          TourIdStr;
  std::string                          TourNameStr;
  std::string                          BusModelStr;

  #undef           Self
 };

class TourDBTourSetClass : public TourTourSetClass
 {
  #define          Self                TourDBTourSetClass

  public           :

                   Self               (const char         *TourSetQueryStrPtr = NULL);
  virtual         ~Self               (void);

  virtual
  unsigned int     Count              (void) const;

  virtual
  TourTourPtrClass Tour               (unsigned int        Index) const;

  private          :

  void             Load               (void);

  std::string                          TourSetQueryStr;
  bool                                 LoadedFlag;
  TourStringVectorClass                TourIdStrArray;

  #undef           Self
 };

class TourDBStopSetClass : public TourStopSetClass
 {
  #define          Self                TourDBStopSetClass

  public           :

                   Self               (void);
  virtual         ~Self               (void);

  virtual
  unsigned int     Count              (void) const;

  virtual
  TourStopPtrClass Stop               (unsigned int        Index) const;

  private          :

  void             Load               (void);
 
  bool                                 LoadedFlag;
  TourStringVectorClass                StopIdStrArray;

  #undef           Self
 };

class TourDBTopologyClass : public TourTopologyClass
 {
  #define          Self                TourDBTopologyClass

  public           :

  virtual         ~Self               (void);

  virtual bool     DirectLinkExists   (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const;

  virtual float    DirectLinkDistance (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const;

  private          :

  void             GetLinkInfo        (bool               *LinkExistsFlagPtr,
                                       float              *LinkDistancePtr,
                                       const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const;

  #undef           Self
 };


#define            Self                TourDBBusClass

                   Self::Self         (const std::string  &BusModelStr)
 {
  this->BusModelStr = BusModelStr;
  BusDescStr        = "";
  BusCapacity       = 0;
  LoadedFlag        = false; 
 }
                     
                   Self::~Self        (void)
 {
 }                    

std::string        Self::ModelStr     (void) const
 {
  return(BusModelStr);
 }

std::string        Self::DescriptionStr
                                      (void) const
 {
  if (!LoadedFlag)
   {
    Load();
   }

  return(BusDescStr);
 }

unsigned int       Self::Capacity     (void) const
 {
  if (!LoadedFlag)
   {
    Load();
   }

  return(BusCapacity);
 }

void               Self::Load         (void)
 {
  try
   {
    TourDataDBModule->BusInfoQuery->Parameters->ParamByName("BusModel")->Value = BusModelStr.c_str();
    TourDataDBModule->BusInfoQuery->Open();
    TourDataDBModule->BusInfoQuery->First();

    if (!TourDataDBModule->BusInfoQuery->Eof)
     {
      AnsiString                       BusDescAnsiStr;

      if (TourDataDBModule->BusInfoQuery->FieldValues["Bus_Desc"].IsNull())
       {
        BusDescStr     = "";
       }
      else
       {
        BusDescAnsiStr = TourDataDBModule->BusInfoQuery->FieldValues["Bus_Desc"];
        BusDescStr     = BusDescAnsiStr.c_str();
       }

      if (TourDataDBModule->BusInfoQuery->FieldValues["Bus_Capacity"].IsNull())
       {
        BusCapacity = 0;
       }
      else
       { 
        BusCapacity = TourDataDBModule->BusInfoQuery->FieldValues["Bus_Capacity"];
       }  
     }

    TourDataDBModule->BusInfoQuery->Close();
   }
  catch (...)
   {
   }

  LoadedFlag = true;
 }

#undef             Self


#define            Self                TourDBStopClass

                   Self::Self         (const std::string  &StopIdStr)
 {
  LoadedFlag      = false;
  this->StopIdStr = StopIdStr;
  StopNameStr     = "";
 }

                   Self::~Self        (void)
 {
 }

void               Self::Load         (void)
 {
  try
   {
    TourDataDBModule->StopInfoQuery->Parameters->ParamByName("StopId")->Value = StopIdStr.c_str();
    TourDataDBModule->StopInfoQuery->Open();
    TourDataDBModule->StopInfoQuery->First();

    if (!TourDataDBModule->StopInfoQuery->Eof)
     {
      AnsiString                       StopNameAnsiStr;

      StopNameAnsiStr = TourDataDBModule->StopInfoQuery->FieldValues["Stop_Name"];
      StopNameStr     = StopNameAnsiStr.c_str();
     }

    TourDataDBModule->StopInfoQuery->Close();
   }
  catch (...)
   {
   }  

  LoadedFlag = true;
 }

std::string        Self::IdStr        (void) const
 {
  return(StopIdStr);
 }

std::string        Self::NameStr      (void) const
 {
  if (!LoadedFlag)
   {
    Load();
   }

  return(StopNameStr);
 }

#undef             Self


#define            Self                TourDBStopScheduleClass

                   Self::Self         (TourDBTourScheduleClass
                                                          *TourSchedulePtr,
                                       const std::string  &TourIdStr,
                                       unsigned int        StopIndex)
 {
  this->TourIdStr       = TourIdStr;
  this->StopIndex       = StopIndex;
  this->TourSchedulePtr = TourSchedulePtr;
 }

                   Self::~Self        (void)
 {
 }
 
TourStopPtrClass   Self::Stop         (void) const
 {
  return(TourStopPtrClass(new TourDBStopClass(TourSchedulePtr->StopScheduleArray[StopIndex].StopIdStr)));
 }

TourTimeClass      Self::InTime       (void) const
 {
  return(TourSchedulePtr->StopScheduleArray[StopIndex].InTime);
 }

TourTimeClass      Self::WaitTime     (void) const
 {
  return(TourSchedulePtr->StopScheduleArray[StopIndex].WaitTime);
 }

void               Self::SetInTime    (const TourTimeClass&Time)
 {
  AnsiString                           QueryStr;

  QueryStr = "UPDATE TripStep SET TripStep_InTime = ";

  if (Time.IsEmpty())
   {
    QueryStr += "NULL";
   }
  else
   {
    QueryStr += AnsiString("'") + Time.AsStr().c_str() + "'";
   }

  QueryStr += AnsiString(" WHERE Trip_Id = '") + TourIdStr.c_str() + "' AND TripStep_Num = " + AnsiString(StopIndex);

  TourDataDBModule->TourStopScheduleSetInTimeQuery->SQL->Clear();
  TourDataDBModule->TourStopScheduleSetInTimeQuery->SQL->Add(QueryStr);

  TourDataDBModule->TourStopScheduleSetInTimeQuery->ExecSQL();

  TourSchedulePtr->StopScheduleArray[StopIndex].InTime = Time;
 }

void               Self::SetWaitTime  (const TourTimeClass&Time)
 {
  AnsiString                           QueryStr;

  QueryStr = "UPDATE TripStep SET TripStep_WaitTime = ";

  if (Time.IsEmpty())
   {
    QueryStr += "NULL";
   }
  else
   {
    QueryStr += AnsiString("'") + Time.AsStr().c_str() + "'";
   }
   
  QueryStr += AnsiString(" WHERE Trip_Id = '") + TourIdStr.c_str() + "' AND TripStep_Num = " + AnsiString(StopIndex);

  TourDataDBModule->TourStopScheduleSetWaitTimeQuery->SQL->Clear();
  TourDataDBModule->TourStopScheduleSetWaitTimeQuery->SQL->Add(QueryStr);

  TourDataDBModule->TourStopScheduleSetWaitTimeQuery->ExecSQL();

  TourSchedulePtr->StopScheduleArray[StopIndex].WaitTime = Time;
 }

#undef             Self


#define            Self                TourDBTourScheduleClass

                   Self::Self         (const std::string  &TourIdStr)
 {
  LoadedFlag      = false;
  this->TourIdStr = TourIdStr;
 }

                   Self::~Self        (void)
 {
 }

void               Self::Load         (void)
 {
  StopScheduleArray.clear();

  try
   {
    TourDataDBModule->TourScheduleQuery->Parameters->ParamByName("TripId")->Value = TourIdStr.c_str();
    TourDataDBModule->TourScheduleQuery->Open();
    TourDataDBModule->TourScheduleQuery->First();

    while (!TourDataDBModule->TourScheduleQuery->Eof)
     {
      TourDBStopScheduleType           StopSchedule;
      TDateTime                        InTime;
      TDateTime                        WaitTime;
      AnsiString                       StopIdAnsiStr;

      StopIdAnsiStr          = TourDataDBModule->TourScheduleQuery->FieldValues["Stop_Id"];
      StopSchedule.StopIdStr = StopIdAnsiStr.c_str();

      if (TourDataDBModule->TourScheduleQuery->FieldValues["TripStep_InTime"].IsNull())
       {
        StopSchedule.InTime.SetEmpty();
       }
      else
       {
        InTime              = TDateTime(TourDataDBModule->TourScheduleQuery->FieldValues["TripStep_InTime"]);
        StopSchedule.InTime = TourDBDateTimeToTime(InTime);
       }

      if (TourDataDBModule->TourScheduleQuery->FieldValues["TripStep_WaitTime"].IsNull())
       {
        StopSchedule.WaitTime.SetEmpty();
       }
      else
       {
        WaitTime               = TDateTime(TourDataDBModule->TourScheduleQuery->FieldValues["TripStep_WaitTime"]);
        StopSchedule.WaitTime  = TourDBDateTimeToTime(WaitTime);
       }

      StopScheduleArray.push_back(StopSchedule);

      TourDataDBModule->TourScheduleQuery->Next();
     }

    TourDataDBModule->TourScheduleQuery->Close();
   }
  catch (...)
   {
   }

  LoadedFlag = true;
 }

unsigned int       Self::StopCount    (void) const
 {
  if (!LoadedFlag)
   {
    Load();
   }

  return(StopScheduleArray.size());
 }

TourStopSchedulePtrClass
                   Self::StopSchedule (unsigned int        StopIndex) const
 {
  if (!LoadedFlag)
   {
    Load();
   }

  return(TourStopSchedulePtrClass(new TourDBStopScheduleClass((TourDBTourScheduleClass*)this,TourIdStr,StopIndex)));
 }

TourStopSchedulePtrClass
                   Self::AppendStopSchedule
                                      (const std::string  &StopIdStr)
 {
  TourDBStopScheduleType               StopSchedule;

  if (!LoadedFlag)
   {
    Load();
   }

  try
   {
    TourDataModule->TourDataBaseConnection->BeginTrans();

    TourDataDBModule->TourScheduleAppendStopQuery->Parameters->ParamByName("TripId")->Value  = TourIdStr.c_str();
    TourDataDBModule->TourScheduleAppendStopQuery->Parameters->ParamByName("StepNum")->Value = StopScheduleArray.size();
    TourDataDBModule->TourScheduleAppendStopQuery->Parameters->ParamByName("StopId")->Value  = StopIdStr.c_str();
    TourDataDBModule->TourScheduleAppendStopQuery->Parameters->ParamByName("ToStopId")->Value.ChangeType(varNull);
    TourDataDBModule->TourScheduleAppendStopQuery->ExecSQL();

    if (StopScheduleArray.size() > 0)
     {
      TourDataDBModule->TourScheduleUpdateToStopIdQuery->Parameters->ParamByName("StopId")->Value  = StopIdStr.c_str();
      TourDataDBModule->TourScheduleUpdateToStopIdQuery->Parameters->ParamByName("TripId")->Value  = TourIdStr.c_str();
      TourDataDBModule->TourScheduleUpdateToStopIdQuery->Parameters->ParamByName("StepNum")->Value = StopScheduleArray.size() - 1;
      TourDataDBModule->TourScheduleUpdateToStopIdQuery->ExecSQL();
     }

    StopSchedule.StopIdStr = StopIdStr;
    StopSchedule.InTime    = TourTimeClass();
    StopSchedule.WaitTime  = TourTimeClass();

    StopScheduleArray.push_back(StopSchedule);
    
    TourDataModule->TourDataBaseConnection->CommitTrans();
   }
  catch(...)
   {
    TourDataModule->TourDataBaseConnection->RollbackTrans();
    
    throw;
   }

  return(TourStopSchedulePtrClass(new TourDBStopScheduleClass((TourDBTourScheduleClass*)this,TourIdStr,StopScheduleArray.size() - 1)));
 }

TourStopSchedulePtrClass
                   Self::InsertStopSchedule
                                      (unsigned int        StopIndex,
                                       const std::string  &StopIdStr)
 {
  TourDBStopScheduleType               StopSchedule;
  
  if (!LoadedFlag)
   {
    Load();
   }

  if (StopIndex < StopScheduleArray.size())
   {
    try
     {
      TourDataModule->TourDataBaseConnection->BeginTrans();

      TourDataDBModule->TourScheduleIncStepNumQuery->Parameters->ParamByName("TripId")->Value   = TourIdStr.c_str();
      TourDataDBModule->TourScheduleIncStepNumQuery->Parameters->ParamByName("StepNum")->Value  = StopIndex;
      TourDataDBModule->TourScheduleIncStepNumQuery->ExecSQL();

      TourDataDBModule->TourScheduleAppendStopQuery->Parameters->ParamByName("TripId")->Value   = TourIdStr.c_str();
      TourDataDBModule->TourScheduleAppendStopQuery->Parameters->ParamByName("StepNum")->Value  = StopIndex;
      TourDataDBModule->TourScheduleAppendStopQuery->Parameters->ParamByName("StopId")->Value   = StopIdStr.c_str();
      TourDataDBModule->TourScheduleAppendStopQuery->Parameters->ParamByName("ToStopId")->Value = StopScheduleArray[StopIndex].StopIdStr.c_str();
      TourDataDBModule->TourScheduleAppendStopQuery->ExecSQL();

      if (StopIndex > 0)
       {
        TourDataDBModule->TourScheduleUpdateToStopIdQuery->Parameters->ParamByName("StopId")->Value  = StopIdStr.c_str();
        TourDataDBModule->TourScheduleUpdateToStopIdQuery->Parameters->ParamByName("TripId")->Value  = TourIdStr.c_str();
        TourDataDBModule->TourScheduleUpdateToStopIdQuery->Parameters->ParamByName("StepNum")->Value = StopIndex - 1;
        TourDataDBModule->TourScheduleUpdateToStopIdQuery->ExecSQL();
       }

      StopSchedule.StopIdStr = StopIdStr;
      StopSchedule.InTime    = TourTimeClass();
      StopSchedule.WaitTime  = TourTimeClass();

      StopScheduleArray.insert(StopScheduleArray.begin() + StopIndex,StopSchedule);

      TourDataModule->TourDataBaseConnection->CommitTrans();
     }
    catch(...)
     {
      TourDataModule->TourDataBaseConnection->RollbackTrans();

      throw;
     }

    return(TourStopSchedulePtrClass(new TourDBStopScheduleClass((TourDBTourScheduleClass*)this,TourIdStr,StopIndex)));
   }
  else
   {
    return(AppendStopSchedule(StopIdStr));
   }
 }


void               Self::DeleteStopSchedule
                                      (unsigned int        StopIndex)
 {
  if (!LoadedFlag)
   {
    Load();
   }

  if (StopIndex < StopScheduleArray.size())
   {
    try
     {
      TourDataModule->TourDataBaseConnection->BeginTrans();

      TourDataDBModule->TourScheduleDeleteStopQuery->Parameters->ParamByName("TripId")->Value  = TourIdStr.c_str();
      TourDataDBModule->TourScheduleDeleteStopQuery->Parameters->ParamByName("StepNum")->Value = StopIndex;

      TourDataDBModule->TourScheduleDeleteStopQuery->ExecSQL();

      if (StopIndex < (StopScheduleArray.size() - 1))
       {
        TourDataDBModule->TourScheduleDecStepNumQuery->Parameters->ParamByName("TripId")->Value  = TourIdStr.c_str();
        TourDataDBModule->TourScheduleDecStepNumQuery->Parameters->ParamByName("StepNum")->Value = StopIndex;
        TourDataDBModule->TourScheduleDecStepNumQuery->ExecSQL();
       }

      if (StopIndex > 0)
       {
        if (StopIndex < (StopScheduleArray.size() - 1))
         {
          TourDataDBModule->TourScheduleUpdateToStopIdQuery->Parameters->ParamByName("StopId")->Value = StopScheduleArray[StopIndex + 1].StopIdStr.c_str();
         }
        else
         {
          TourDataDBModule->TourScheduleUpdateToStopIdQuery->Parameters->ParamByName("StopId")->Value.ChangeType(varNull);
         }

        TourDataDBModule->TourScheduleUpdateToStopIdQuery->Parameters->ParamByName("TripId")->Value  = TourIdStr.c_str();
        TourDataDBModule->TourScheduleUpdateToStopIdQuery->Parameters->ParamByName("StepNum")->Value = StopIndex - 1;
        TourDataDBModule->TourScheduleUpdateToStopIdQuery->ExecSQL();
       }

      StopScheduleArray.erase(StopScheduleArray.begin() + StopIndex);

      TourDataModule->TourDataBaseConnection->CommitTrans();
     }
    catch(...)
     {
      TourDataModule->TourDataBaseConnection->RollbackTrans();

      throw;
     }
   }
 }

#undef             Self


#define            Self                TourDBTourClass

                   Self::Self         (const std::string  &TourIdStr)
 {
  LoadedFlag      = false;
  this->TourIdStr = TourIdStr;
  TourNameStr     = "";
  BusModelStr     = "";
 }

                   Self::~Self        (void)
 {
 }

void               Self::Load         (void)
 {
  try
   {
    TourDataDBModule->TourInfoQuery->Parameters->ParamByName("TripId")->Value = TourIdStr.c_str();
    TourDataDBModule->TourInfoQuery->Open();
    TourDataDBModule->TourInfoQuery->First();

    if (!TourDataDBModule->TourInfoQuery->Eof)
     {
      AnsiString                       TourNameAnsiStr;
      AnsiString                       BusModelAnsiStr;

      if (TourDataDBModule->TourInfoQuery->FieldValues["Trip_Name"].IsNull())
       {
        TourNameStr     = "";
       }
      else
       {
        TourNameAnsiStr = TourDataDBModule->TourInfoQuery->FieldValues["Trip_Name"];
        TourNameStr     = TourNameAnsiStr.c_str();
       }

      if (TourDataDBModule->TourInfoQuery->FieldValues["Bus_Model"].IsNull())
       {
        BusModelStr = "";
       }
      else
       {
        BusModelAnsiStr = TourDataDBModule->TourInfoQuery->FieldValues["Bus_Model"];
        BusModelStr     = BusModelAnsiStr.c_str(); 
       }
     }

    TourDataDBModule->TourInfoQuery->Close();
   }
  catch (...)
   {
   }  

  LoadedFlag = true;
 }

std::string        Self::IdStr        (void) const
 {
  return(TourIdStr);
 }

std::string        Self::NameStr      (void) const
 {
  if (!LoadedFlag)
   {
    Load();
   }

  return(TourNameStr);
 }

TourTourSchedulePtrClass
                   Self::Schedule     (void) const
 {
  return(TourTourSchedulePtrClass(new TourDBTourScheduleClass(TourIdStr)));
 }

TourBusPtrClass    Self::Bus          (void) const
 {
  if (!LoadedFlag)
   {
    Load();
   }

  return(TourBusPtrClass(new TourDBBusClass(BusModelStr)));
 }

float              Self::AverageSpeed (void) const
 {
  float                                AverageSpeed;
  float                                TotalDistance;
  TourTimeClass                        TotalTime(0,0);

  TotalDistance = 0.0;

  try
   {
    TourDataDBModule->TourAverageSpeedQuery->Parameters->ParamByName("TripId")->Value = TourIdStr.c_str();
    TourDataDBModule->TourAverageSpeedQuery->Open();
    TourDataDBModule->TourAverageSpeedQuery->First();

    if (!TourDataDBModule->TourAverageSpeedQuery->Eof)
     {
      TDateTime                        DBTime;
      TourTimeClass                    CurrInTime;
      TourTimeClass                    CurrWaitTime;
      TourTimeClass                    NextInTime;
      float                            Distance;

      if (TourDataDBModule->TourAverageSpeedQuery->FieldValues["CurrInTime"].IsNull())
       {
        CurrInTime.SetEmpty();
       }
      else
       {
        DBTime     = TDateTime(TourDataDBModule->TourAverageSpeedQuery->FieldValues["CurrInTime"]);
        CurrInTime = TourDBDateTimeToTime(DBTime);
       }

      if (TourDataDBModule->TourAverageSpeedQuery->FieldValues["CurrWaitTime"].IsNull())
       {
        CurrWaitTime.SetEmpty();
       }
      else
       {
        DBTime       = TDateTime(TourDataDBModule->TourAverageSpeedQuery->FieldValues["CurrWaitTime"]);
        CurrWaitTime = TourDBDateTimeToTime(DBTime);
       }

      if (TourDataDBModule->TourAverageSpeedQuery->FieldValues["NextInTime"].IsNull())
       {
        NextInTime.SetEmpty();
       }
      else
       {
        DBTime     = TDateTime(TourDataDBModule->TourAverageSpeedQuery->FieldValues["NextInTime"]);
        NextInTime = TourDBDateTimeToTime(DBTime);
       }

      Distance = TourDataDBModule->TourAverageSpeedQuery->FieldValues["PathLength"];

      if (CurrInTime.IsEmpty() || NextInTime.IsEmpty())
       {
       }
      else
       {
        TourTimeClass                  CurrOutTime;

        if (CurrWaitTime.IsEmpty())
         {
          CurrWaitTime.SetZero();
         }

        CurrOutTime = CurrInTime + CurrWaitTime;

        if (NextInTime < CurrOutTime)
         {
          NextInTime += TourTimeClass(TourTimeHoursPerDay,0);
         }

        TotalTime     += NextInTime - CurrOutTime;
        TotalDistance += Distance;
       }
     }

    TourDataDBModule->TourAverageSpeedQuery->Close();
   }
  catch (...)
   {
   }

  if (!TotalTime.IsZero())
   {
    return(TotalDistance / ((float)TotalTime / (float)TourTimeMinutesPerHour));
   }
  else
   {
    return(0.0);
   }
 }

float              Self::TotalDistance(void) const
 {
  float                                Result;

  Result = 0.0; 

  try
   {
    TourDataDBModule->TourTotalDistanceQuery->Parameters->ParamByName("TripId")->Value = TourIdStr.c_str();
    TourDataDBModule->TourTotalDistanceQuery->Open();
    TourDataDBModule->TourTotalDistanceQuery->First();

    if (!TourDataDBModule->TourTotalDistanceQuery->Eof)
     {
      Result = TourDataDBModule->TourTotalDistanceQuery->Fields->Fields[0]->AsFloat; 
     }

    TourDataDBModule->TourTotalDistanceQuery->Close();
   }
  catch (...)
   {
    Result = 0.0;
   }

  return(Result);
 }

void               Self::SetName      (const std::string  &NameStr)
 {
  TourDataDBModule->TourSetNameQuery->Parameters->ParamByName("TripName")->Value = NameStr.c_str();
  TourDataDBModule->TourSetNameQuery->Parameters->ParamByName("TripId")->Value   = TourIdStr.c_str();
  TourDataDBModule->TourSetNameQuery->ExecSQL();

  /* Now we can't count that all info is loaded - we know just name but not bus */

/*
  LoadedFlag  = true;
*/

  TourNameStr = NameStr;
 }

void               Self::SetBusModel  (const std::string  &ModelStr)
 {
  TourDataDBModule->TourSetBusModelQuery->Parameters->ParamByName("BusModel")->Value = ModelStr.c_str();
  TourDataDBModule->TourSetBusModelQuery->Parameters->ParamByName("TripId")->Value   = TourIdStr.c_str();
  TourDataDBModule->TourSetBusModelQuery->ExecSQL();
 }

#undef             Self


#define            Self                TourDBTourSetClass

                   Self::Self         (const char         *TourSetQueryStrPtr)
 {
  if (TourSetQueryStrPtr != NULL)
   {
    TourSetQueryStr = TourSetQueryStrPtr;
   }
  else
   {
    TourSetQueryStr = "";
   }

  LoadedFlag = false;
 }

                   Self::~Self        (void)
 {
 }

void               Self::Load         (void)
 {
  try
   {
    TourDataDBModule->TourSetQuery->SQL->Clear();

    if (TourSetQueryStr == "")
     {
      TourDataDBModule->TourSetQuery->SQL->Add("SELECT Trip_Id FROM Trip");
     }
    else
     {
      TourDataDBModule->TourSetQuery->SQL->Add(TourSetQueryStr.c_str());
     }

    TourDataDBModule->TourSetQuery->Open();
    TourDataDBModule->TourSetQuery->First();

    while (!TourDataDBModule->TourSetQuery->Eof)
     {
      AnsiString                       TourIdStr;

      TourIdStr = TourDataDBModule->TourSetQuery->FieldValues["Trip_Id"];

      TourIdStrArray.push_back(std::string(TourIdStr.c_str()));

      TourDataDBModule->TourSetQuery->Next();
     }

    TourDataDBModule->TourSetQuery->Close();
   }
  catch (...)
   {
   }   

  LoadedFlag = true;
 }

unsigned int       Self::Count        (void) const
 {
  if (!LoadedFlag)
   {
    Load();
   }

  return(TourIdStrArray.size());
 }

TourTourPtrClass   Self::Tour         (unsigned int        Index) const
 {
  if (!LoadedFlag)
   {
    Load();
   }

  return(TourTourPtrClass(new TourDBTourClass(TourIdStrArray[Index])));
 }

#undef             Self


#define            Self                TourDBStopSetClass

                   Self::Self         (void)
 {
  LoadedFlag = false;
 }

                   Self::~Self        (void)
 {
 }

void               Self::Load         (void)
 {
  try
   {
    TourDataDBModule->StopSetQuery->Open();
    TourDataDBModule->StopSetQuery->First();

    while (!TourDataDBModule->StopSetQuery->Eof)
     {
      AnsiString                       StopIdStr;

      StopIdStr = TourDataDBModule->StopSetQuery->FieldValues["Stop_Id"];

      StopIdStrArray.push_back(std::string(StopIdStr.c_str()));

      TourDataDBModule->StopSetQuery->Next();
     }

    TourDataDBModule->StopSetQuery->Close();
   }
  catch (...)
   {
   }

  LoadedFlag = true;
 }

unsigned int       Self::Count        (void) const
 {
  if (!LoadedFlag)
   {
    Load();
   }

  return(StopIdStrArray.size());
 }

TourStopPtrClass   Self::Stop         (unsigned int        Index) const
 {
  if (!LoadedFlag)
   {
    Load();
   }

  return(TourStopPtrClass(new TourDBStopClass(StopIdStrArray[Index])));
 }

#undef             Self


#define            Self                TourDBTopologyClass

                   Self::~Self        (void)
 {
 }

void               Self::GetLinkInfo  (bool               *LinkExistsFlagPtr,
                                       float              *LinkDistancePtr,
                                       const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const
 {
  *LinkExistsFlagPtr = false;
  *LinkDistancePtr   = 0;

  try
   {
    TourDataDBModule->StopDistanceQuery->Parameters->ParamByName("FromStopId")->Value = FromStopIdStr.c_str();
    TourDataDBModule->StopDistanceQuery->Parameters->ParamByName("ToStopId")->Value   = ToStopIdStr.c_str();
    TourDataDBModule->StopDistanceQuery->Open();
    TourDataDBModule->StopDistanceQuery->First();

    if (!TourDataDBModule->StopDistanceQuery->Eof)
     {
      *LinkExistsFlagPtr = true;
      *LinkDistancePtr   = TourDataDBModule->StopDistanceQuery->FieldValues["Path_Length"];
     }

    TourDataDBModule->StopDistanceQuery->Close();
   }
  catch (...)
   {
   }
 }

bool               Self::DirectLinkExists
                                      (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const
 {
  bool                                 LinkExistsFlag;
  float                                LinkDistance;

  GetLinkInfo(&LinkExistsFlag,&LinkDistance,FromStopIdStr,ToStopIdStr);

  if (!LinkExistsFlag)
   {
    GetLinkInfo(&LinkExistsFlag,&LinkDistance,ToStopIdStr,FromStopIdStr);
   }

  return(LinkExistsFlag);
 }

float              Self::DirectLinkDistance
                                      (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const
 {
  bool                                 LinkExistsFlag;
  float                                LinkDistance;

  GetLinkInfo(&LinkExistsFlag,&LinkDistance,FromStopIdStr,ToStopIdStr);

  if (LinkExistsFlag)
   {
    return(LinkDistance);
   }
  else
   {
    GetLinkInfo(&LinkExistsFlag,&LinkDistance,ToStopIdStr,FromStopIdStr);

    if (LinkExistsFlag)
     {
      return(LinkDistance);
     }
    else
     {
      return(0);
     }
   } 
 }

#undef             Self


#define            Self                TourDBDataClass

                   Self::Self         (const char         *TourSetQueryStrPtr)
 {
  if (TourSetQueryStrPtr != NULL)
   {
    TourSetQueryStr = TourSetQueryStrPtr;
   }
  else
   {
    TourSetQueryStr = "";
   }
 }

                   Self::~Self        (void)
 {
 }
  
TourTourSetPtrClass
                   Self::TourSet      (void) const
 {
  return(TourTourSetPtrClass(new TourDBTourSetClass(TourSetQueryStr.c_str())));
 }
 
TourStopSetPtrClass
                   Self::StopSet      (void) const
 {
  return(TourStopSetPtrClass(new TourDBStopSetClass()));
 }

TourTopologyPtrClass
                   Self::Topology     (void) const
 {
  return(TourTopologyPtrClass(new TourDBTopologyClass()));
 }

TourTourPtrClass   Self::Tour         (const std::string  &TourIdStr) const
 {
  return(TourTourPtrClass(new TourDBTourClass(TourIdStr)));
 }

TourStopPtrClass   Self::Stop         (const std::string  &StopIdStr) const
 {
  return(TourStopPtrClass(new TourDBStopClass(StopIdStr)));
 }

TourBusPtrClass    Self::Bus          (const std::string  &ModelStr) const
 {
  return(TourBusPtrClass(new TourDBBusClass(ModelStr)));
 }

TourTourPtrClass   Self::AppendTour   (const std::string  &TourIdStr)
 {
  TourDataDBModule->TourAppendQuery->Parameters->ParamByName("TripId")->Value = TourIdStr.c_str();
  TourDataDBModule->TourAppendQuery->ExecSQL();
  
  return(TourTourPtrClass(new TourDBTourClass(TourIdStr)));
 }

void               Self::DeleteTour   (const std::string  &TourIdStr)
 {
  try
   {
    TourDataModule->TourDataBaseConnection->BeginTrans();
    TourDataDBModule->TourScheduleDeleteAllQuery->Parameters->ParamByName("TripId")->Value = TourIdStr.c_str();
    TourDataDBModule->TourScheduleDeleteAllQuery->ExecSQL();
    TourDataDBModule->TourDeleteQuery->Parameters->ParamByName("TripId")->Value = TourIdStr.c_str();
    TourDataDBModule->TourDeleteQuery->ExecSQL();
    TourDataModule->TourDataBaseConnection->CommitTrans();
   }
  catch (...)
   {
    TourDataModule->TourDataBaseConnection->RollbackTrans();

    throw;
   }
 }

#undef             Self

