#include <string>
#include <vector>

#include <TourTime.h>

#include <TourData.h>
#include <TourDataCU.h>

class TourCachedUpdateStopScheduleClass : public TourStopScheduleClass
 {
  #define          Self                TourCachedUpdateStopScheduleClass

  public           :

                   Self               (TourDataPtrClass   SourceDataPtr,
                                       const std::string &TourIdStr,
                                       unsigned int       StopIndex,
                                       TourStopSchedulePtrClass
                                                          SourceStopSchedulePtr,
                                       TourDataCUModifiedTourStorageClass
                                                         *ModifiedTourStoragePtr);

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

  TourDataCUTourType
                  *PrepareToChange    (void);

  TourDataPtrClass                     SourceDataPtr;
  std::string                          TourIdStr;
  unsigned int                         StopIndex;
  TourStopSchedulePtrClass             SourceStopSchedulePtr;
  TourDataCUModifiedTourStorageClass  *ModifiedTourStoragePtr;
  bool                                 TourModifiedFlag;

  #undef           Self
 };

class TourCachedUpdateTourScheduleClass : public TourTourScheduleClass
 {
  #define          Self                TourCachedUpdateTourScheduleClass

  public           :

                   Self               (TourDataPtrClass   SourceDataPtr,
                                       const std::string &TourIdStr,
                                       TourTourSchedulePtrClass
                                                          SourceTourSchedulePtr,
                                       TourDataCUModifiedTourStorageClass
                                                         *ModifiedTourStoragePtr);

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

  TourDataCUTourType
                  *PrepareToChange    (void);

  bool             IsScheduleModified (void) const;

  TourDataPtrClass                     SourceDataPtr;
  std::string                          TourIdStr;
  TourTourSchedulePtrClass             SourceTourSchedulePtr;
  TourDataCUModifiedTourStorageClass  *ModifiedTourStoragePtr;

  #undef           Self
 };

class TourCachedUpdateTourClass : public TourTourClass
 {
  #define          Self                TourCachedUpdateTourClass

  public           :

                   Self               (TourDataPtrClass    SourceDataPtr,
                                       const std::string  &TourIdStr,
                                       TourTourPtrClass    SourceTourPtr,
                                       TourDataCUModifiedTourStorageClass
                                                          *ModifiedTourStoragePtr);
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

  TourDataPtrClass                     SourceDataPtr;
  std::string                          TourIdStr;
  TourTourPtrClass                     SourceTourPtr;
  TourDataCUModifiedTourStorageClass  *ModifiedTourStoragePtr;

  #undef           Self
 };

#define            Self                TourCachedUpdateStopScheduleClass

                   Self::Self         (TourDataPtrClass   SourceDataPtr,
                                       const std::string &TourIdStr,
                                       unsigned int       StopIndex,
                                       TourStopSchedulePtrClass    
                                                          SourceStopSchedulePtr,
                                       TourDataCUModifiedTourStorageClass
                                                         *ModifiedTourStoragePtr)
 {
  this->SourceDataPtr          = SourceDataPtr;
  this->TourIdStr              = TourIdStr;
  this->StopIndex              = StopIndex;
  this->SourceStopSchedulePtr  = SourceStopSchedulePtr;
  this->ModifiedTourStoragePtr = ModifiedTourStoragePtr;
 }
                   
                   Self::~Self        (void)
 {
 }

TourStopPtrClass   Self::Stop         (void) const
 {
  if (ModifiedTourStoragePtr->IsTourModified(TourIdStr))
   {
    TourDataCUTourType                *TourInfoPtr;

    TourInfoPtr = ModifiedTourStoragePtr->TourInfoPtr(TourIdStr);

    if (TourInfoPtr->ScheduleChangedFlag)
     {
      return(SourceDataPtr->Stop(TourInfoPtr->Schedule[StopIndex].StopIdStr));
     }
    else
     {
      return(SourceStopSchedulePtr->Stop());
     }
   }
  else
   {
    return(SourceStopSchedulePtr->Stop());
   }
 }

TourTimeClass      Self::InTime       (void) const
 {
  if (ModifiedTourStoragePtr->IsTourModified(TourIdStr))
   {
    TourDataCUTourType                *TourInfoPtr;

    TourInfoPtr = ModifiedTourStoragePtr->TourInfoPtr(TourIdStr);

    if (TourInfoPtr->ScheduleChangedFlag)
     {
      return(TourInfoPtr->Schedule[StopIndex].InTime);
     }
    else
     {
      return(SourceStopSchedulePtr->InTime());
     }
   }
  else
   {
    return(SourceStopSchedulePtr->InTime());
   }
 }

TourTimeClass      Self::WaitTime     (void) const
 {
  if (ModifiedTourStoragePtr->IsTourModified(TourIdStr))
   {
    TourDataCUTourType                *TourInfoPtr;

    TourInfoPtr = ModifiedTourStoragePtr->TourInfoPtr(TourIdStr);

    if (TourInfoPtr->ScheduleChangedFlag)
     {
      return(TourInfoPtr->Schedule[StopIndex].WaitTime);
     }
    else
     {
      return(SourceStopSchedulePtr->WaitTime());
     }
   }
  else
   {
    return(SourceStopSchedulePtr->WaitTime());
   }
 }

void               Self::SetInTime    (const TourTimeClass&Time)
 {
  TourDataCUTourType                  *TourInfoPtr;

  TourInfoPtr = PrepareToChange();

  if (StopIndex < TourInfoPtr->Schedule.size())  
   {
    TourInfoPtr->Schedule[StopIndex].InTime = Time;
   }
 }

void               Self::SetWaitTime  (const TourTimeClass&Time)
 {
  TourDataCUTourType                  *TourInfoPtr;

  TourInfoPtr = PrepareToChange();

  if (StopIndex < TourInfoPtr->Schedule.size())
   {
    TourInfoPtr->Schedule[StopIndex].WaitTime = Time;
   }
 }

TourDataCUTourType
                  *Self::PrepareToChange
                                      (void)
 {
  TourDataCUTourType                  *TourInfoPtr;

  if (!ModifiedTourStoragePtr->IsTourModified(TourIdStr))
   {
    ModifiedTourStoragePtr->ModifyTour(TourIdStr);
   }

  TourInfoPtr = ModifiedTourStoragePtr->TourInfoPtr(TourIdStr);

  if (!TourInfoPtr->ScheduleChangedFlag)
   {
    ModifiedTourStoragePtr->ModifyTourSchedule(TourIdStr,SourceDataPtr);
    TourInfoPtr->ScheduleChangedFlag = true;
   }

  return(TourInfoPtr);
 }

#undef             Self


#define            Self                TourCachedUpdateTourScheduleClass

                   Self::Self         (TourDataPtrClass   SourceDataPtr,
                                       const std::string &TourIdStr,
                                       TourTourSchedulePtrClass    
                                                          SourceTourSchedulePtr,
                                       TourDataCUModifiedTourStorageClass
                                                         *ModifiedTourStoragePtr)
 {
  this->SourceDataPtr          = SourceDataPtr;
  this->TourIdStr              = TourIdStr;
  this->SourceTourSchedulePtr  = SourceTourSchedulePtr;
  this->ModifiedTourStoragePtr = ModifiedTourStoragePtr;
 }

                   Self::~Self        (void)
 {
 }

unsigned int       Self::StopCount    (void) const
 {
  if (IsScheduleModified())
   {
    return(ModifiedTourStoragePtr->TourInfoPtr(TourIdStr)->Schedule.size());
   }
  else
   {
    return(SourceTourSchedulePtr->StopCount());
   }
 }

TourStopSchedulePtrClass
                   Self::StopSchedule (unsigned int        StopIndex) const
 {
  if (IsScheduleModified())
   {
    return(TourStopSchedulePtrClass
            (new TourCachedUpdateStopScheduleClass
                  (SourceDataPtr,
                   TourIdStr,
                   StopIndex,
                   TourStopSchedulePtrClass(NULL),
                   ModifiedTourStoragePtr)));
   }
  else
   {
    return(TourStopSchedulePtrClass
            (new TourCachedUpdateStopScheduleClass
                  (SourceDataPtr,
                   TourIdStr,
                   StopIndex,
                   SourceTourSchedulePtr->StopSchedule(StopIndex),
                   ModifiedTourStoragePtr)));
   }
 }

TourStopSchedulePtrClass
                   Self::AppendStopSchedule 
                                      (const std::string  &StopIdStr)
 {
  TourDataCUTourType                  *TourInfoPtr;
  TourDataCUStopScheduleType           StopScheduleInfo;

  TourInfoPtr = PrepareToChange();
  
  StopScheduleInfo.StopIdStr = StopIdStr;
  StopScheduleInfo.InTime    = TourTimeClass();
  StopScheduleInfo.WaitTime  = TourTimeClass();

  TourInfoPtr->Schedule.push_back(StopScheduleInfo);

  return(TourStopSchedulePtrClass
          (new TourCachedUpdateStopScheduleClass
                (SourceDataPtr,
                 TourIdStr,
                 TourInfoPtr->Schedule.size() - 1,
                 TourStopSchedulePtrClass(NULL),
                 ModifiedTourStoragePtr)));
 }

TourStopSchedulePtrClass
                   Self::InsertStopSchedule 
                                      (unsigned int        StopIndex,
                                       const std::string  &StopIdStr)
 {
  TourDataCUTourType                  *TourInfoPtr;
  TourDataCUStopScheduleType           StopScheduleInfo;

  TourInfoPtr = PrepareToChange();

  StopScheduleInfo.StopIdStr = StopIdStr;
  StopScheduleInfo.InTime    = TourTimeClass();
  StopScheduleInfo.WaitTime  = TourTimeClass();

  if (StopIndex < TourInfoPtr->Schedule.size())
   {
    TourInfoPtr->Schedule.insert(TourInfoPtr->Schedule.begin() + StopIndex,
                                 StopScheduleInfo);
                                 
    return(TourStopSchedulePtrClass
            (new TourCachedUpdateStopScheduleClass
                  (SourceDataPtr,
                   TourIdStr,
                   StopIndex,
                   TourStopSchedulePtrClass(NULL),
                   ModifiedTourStoragePtr)));
   }
  else
   {
    TourInfoPtr->Schedule.push_back(StopScheduleInfo);

    return(TourStopSchedulePtrClass
            (new TourCachedUpdateStopScheduleClass
                  (SourceDataPtr,
                   TourIdStr,
                   TourInfoPtr->Schedule.size() - 1,
                   TourStopSchedulePtrClass(NULL),
                   ModifiedTourStoragePtr)));
   }
 }

void               Self::DeleteStopSchedule 
                                      (unsigned int        StopIndex)
 {
  TourDataCUTourType                  *TourInfoPtr;

  TourInfoPtr = PrepareToChange();

  if (StopIndex < TourInfoPtr->Schedule.size())
   {
    TourInfoPtr->Schedule.erase(TourInfoPtr->Schedule.begin() + StopIndex);
   }
 }

bool               Self::IsScheduleModified
                                      (void) const
 {
  TourDataCUTourType                  *TourInfoPtr;
  
  if (ModifiedTourStoragePtr->IsTourModified(TourIdStr))
   {
    TourInfoPtr = ModifiedTourStoragePtr->TourInfoPtr(TourIdStr);

    if (TourInfoPtr->ScheduleChangedFlag)
     {
      return(true);
     }
    else
     {
      return(false);
     }
   }
  else
   {
    return(false);
   } 
 }

TourDataCUTourType
                  *Self::PrepareToChange    (void)
 {
  TourDataCUTourType                  *TourInfoPtr;

  if (!ModifiedTourStoragePtr->IsTourModified(TourIdStr))
   {
    ModifiedTourStoragePtr->ModifyTour(TourIdStr);
   }

  TourInfoPtr = ModifiedTourStoragePtr->TourInfoPtr(TourIdStr);

  if (!TourInfoPtr->ScheduleChangedFlag)
   {
    ModifiedTourStoragePtr->ModifyTourSchedule(TourIdStr,SourceDataPtr);
    TourInfoPtr->ScheduleChangedFlag = true;
   }

  return(TourInfoPtr);
 }

#undef             Self


#define            Self                TourCachedUpdateTourClass

                   Self::Self         (TourDataPtrClass    SourceDataPtr,
                                       const std::string  &TourIdStr,
                                       TourTourPtrClass    SourceTourPtr,
                                       TourDataCUModifiedTourStorageClass
                                                          *ModifiedTourStoragePtr)
 {
  this->SourceDataPtr          = SourceDataPtr;
  this->TourIdStr              = TourIdStr;
  this->SourceTourPtr          = SourceTourPtr;
  this->ModifiedTourStoragePtr = ModifiedTourStoragePtr;
 }

                   Self::~Self        (void)
 {
 }

std::string        Self::IdStr        (void) const
 {
  return(TourIdStr);
 }

std::string        Self::NameStr      (void) const
 {
  if (ModifiedTourStoragePtr->IsTourModified(TourIdStr))
   {
    TourDataCUTourType                *TourInfoPtr;

    TourInfoPtr = ModifiedTourStoragePtr->TourInfoPtr(TourIdStr);

    if (TourInfoPtr->NameChangedFlag)
     {
      return(TourInfoPtr->TourNameStr);
     }
    else
     {
      return(SourceTourPtr->NameStr());
     }
   }
  else
   {
    return(SourceTourPtr->NameStr());
   }
 }

TourTourSchedulePtrClass
                   Self::Schedule     (void) const
 {
  if (ModifiedTourStoragePtr->IsTourModified(TourIdStr))
   {
    return(TourTourSchedulePtrClass
            (new TourCachedUpdateTourScheduleClass
                  (SourceDataPtr,
                   TourIdStr,
                   TourTourSchedulePtrClass(NULL),
                   ModifiedTourStoragePtr)));
   }
  else
   {
    return(TourTourSchedulePtrClass
            (new TourCachedUpdateTourScheduleClass
                  (SourceDataPtr,
                   TourIdStr,
                   SourceTourPtr->Schedule(),
                   ModifiedTourStoragePtr)));
   }
 }

TourBusPtrClass    Self::Bus          (void) const
 {
  if (ModifiedTourStoragePtr->IsTourModified(TourIdStr))
   {
    TourDataCUTourType                *TourInfoPtr;

    TourInfoPtr = ModifiedTourStoragePtr->TourInfoPtr(TourIdStr);

    if (ModifiedTourStoragePtr->IsTourAppended(TourIdStr))
     {
      if (TourInfoPtr->BusModelChangedFlag)
       {
        return(SourceDataPtr->Bus(TourInfoPtr->BusModelStr));
       }
      else
       {
        return(TourBusPtrClass(NULL));
       }
     }
    else
     {
      return(SourceDataPtr->Bus(TourInfoPtr->BusModelStr));
     }
   }
  else
   {
    return(SourceTourPtr->Bus());
   }
 }

float              Self::AverageSpeed (void) const
 {
  if (ModifiedTourStoragePtr->IsTourModified(TourIdStr))
   {
    TourDataCUTourType                *TourInfoPtr;

    TourInfoPtr = ModifiedTourStoragePtr->TourInfoPtr(TourIdStr);

    if (TourInfoPtr->ScheduleChangedFlag)
     {
      TourTopologyPtrClass             TopologyPtr;
      unsigned int                     StopIndex;
      unsigned int                     StopLimit;
      float                            TotalDistance;
      TourTimeClass                    TotalTime;

      TopologyPtr = SourceDataPtr->Topology();

      TotalDistance = 0.0;
      TotalTime     = TourTimeClass(0,0);

      StopLimit     = TourInfoPtr->Schedule.size();

      if (StopLimit > 1)
       {
        StopLimit--;

        for (StopIndex = 0; StopIndex < StopLimit; StopIndex++)
         {
          TourTimeClass                StopInTime;
          TourTimeClass                StopWaitTime;
          TourTimeClass                StopOutTime;
          TourTimeClass                NextStopInTime;

          StopInTime   = TourInfoPtr->Schedule[StopIndex].InTime;
          StopWaitTime = TourInfoPtr->Schedule[StopIndex].WaitTime;

          if (StopWaitTime.IsEmpty())
           {
            StopWaitTime.SetZero();
           }

          StopOutTime    = StopInTime + StopWaitTime;
          NextStopInTime = TourInfoPtr->Schedule[StopIndex + 1].InTime;

          if ((!StopOutTime.IsEmpty()) && (!NextStopInTime.IsEmpty()))
           {
            if (NextStopInTime < StopOutTime)
             {
              NextStopInTime += TourTimeClass(TourTimeHoursPerDay,0);
             }

            TotalTime     += NextStopInTime - StopOutTime;
            TotalDistance += TopologyPtr->DirectLinkDistance
                              (TourInfoPtr->Schedule[StopIndex].StopIdStr,
                               TourInfoPtr->Schedule[StopIndex + 1].StopIdStr);
           }
         }
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
    else
     {
      return(SourceTourPtr->AverageSpeed());
     }
   }
  else
   {
    return(SourceTourPtr->AverageSpeed());
   }
 }

float              Self::TotalDistance(void) const
 {
  if (ModifiedTourStoragePtr->IsTourModified(TourIdStr))
   {
    TourDataCUTourType                *TourInfoPtr;

    TourInfoPtr = ModifiedTourStoragePtr->TourInfoPtr(TourIdStr);

    if (TourInfoPtr->ScheduleChangedFlag)
     {
      TourTopologyPtrClass             TopologyPtr;
      unsigned int                     StopIndex;
      unsigned int                     StopLimit;
      float                            TotalDistance;

      TopologyPtr = SourceDataPtr->Topology();

      TotalDistance = 0.0;
      StopLimit     = TourInfoPtr->Schedule.size();

      if (StopLimit > 1)
       {
        StopLimit--;

        for (StopIndex = 0; StopIndex < StopLimit; StopIndex++)
         {
          TotalDistance += TopologyPtr->DirectLinkDistance
                            (TourInfoPtr->Schedule[StopIndex].StopIdStr,
                             TourInfoPtr->Schedule[StopIndex + 1].StopIdStr);
         }
       }

      return(TotalDistance);
     }
    else
     {
      return(SourceTourPtr->TotalDistance());
     }
   }
  else
   {
    return(SourceTourPtr->TotalDistance());
   }
 }

void               Self::SetName      (const std::string  &NameStr)
 {
  TourDataCUTourType                  *TourInfoPtr;

  if (!ModifiedTourStoragePtr->IsTourModified(TourIdStr))
   {
    ModifiedTourStoragePtr->ModifyTour(TourIdStr);
   }

  TourInfoPtr = ModifiedTourStoragePtr->TourInfoPtr(TourIdStr);

  TourInfoPtr->TourNameStr     = NameStr;
  TourInfoPtr->NameChangedFlag = true;
 }

void               Self::SetBusModel  (const std::string  &ModelStr)
 {
  TourDataCUTourType                  *TourInfoPtr;

  if (!ModifiedTourStoragePtr->IsTourModified(TourIdStr))
   {
    ModifiedTourStoragePtr->ModifyTour(TourIdStr);
   }

  TourInfoPtr = ModifiedTourStoragePtr->TourInfoPtr(TourIdStr);

  TourInfoPtr->BusModelStr         = ModelStr;
  TourInfoPtr->BusModelChangedFlag = true;
 }

#undef             Self


#define            Self                TourDataCUDeletedTourStorageClass

bool               Self::IsTourDeleted(const std::string  &TourIdStr) const
 {
  unsigned int                         TourIndex;

  return(TourIndexById(&TourIndex,TourIdStr));
 }

void               Self::DeleteTour   (const std::string  &TourIdStr)
 {
  if (!IsTourDeleted(TourIdStr))
   {
    DeletedTourArray.push_back(TourIdStr);
   }
 }

void               Self::UnDeleteTour (const std::string  &TourIdStr)
 {
  unsigned int                         TourIndex;

  if (TourIndexById(&TourIndex,TourIdStr))
   {
    DeletedTourArray.erase(DeletedTourArray.begin() + TourIndex);
   }
 }

void               Self::Clear        (void)
 {
  DeletedTourArray.clear();
 }


unsigned int       Self::TourCount    (void) const
 {
  return(DeletedTourArray.size());
 }

std::string        Self::TourIdStr    (unsigned int        TourIndex)
 {
  if (TourIndex < DeletedTourArray.size())
   {
    return(DeletedTourArray[TourIndex]);
   }
  else
   {
    return("");
   }
 }

/*
bool               Self::TourIndexById
                                      (unsigned int       *TourIndexPtr,
                                       const str::string  &TourIdStr) const
 {
  bool                                 FoundFlag;
  unsigned int                         TourIndex;
  unsigned int                         TourLimit;

  FoundFlag = false;
  TourIndex = 0;
  TourLimit = DeletedTourArray.size();

  while ((TourIndex < TourLimit) && (!FoundFlag))
   {
    if (DeletedTourArray[TourIndex] == TourIdStr)
     {
      FoundFlag     = true;
      *TourIndexPtr = TourIndex;
     }
    else
     {
      TourIndex++;
     }
   }

  return(FoundFlag);
 }
*/
#undef             Self

#define            Self                TourDataCUModifiedTourStorageClass

bool               Self::IsTourModified     
                                      (const std::string  &TourIdStr) const
 {
  unsigned int                         TourIndex;

  if (GetTourIndexById(&TourIndex,TourIdStr))
   {
    return(true);
   }
  else
   {
    return(false);
   }
 }

bool               Self::IsTourAppended     
                                      (const std::string  &TourIdStr) const
 {
  unsigned int                         TourIndex;

  if (GetTourIndexById(&TourIndex,TourIdStr))
   {
    if (ModifiedTourArray[TourIndex].AppendedFlag)
     {
      return(true);
     }
    else
     {
      return(false);
     }
   }
  else
   {
    return(false);
   }
 }

unsigned int       Self::TourCount    (void) const
 {
  return(ModifiedTourArray.size());
 }

void               Self::AppendTour   (const std::string  &TourIdStr)
 {
  if (!IsTourModified(TourIdStr))
   {
    TourDataCUTourType                 Tour;

    Tour.TourIdStr           = TourIdStr;
    Tour.TourNameStr         = "";
    Tour.BusModelStr         = "";
    Tour.AppendedFlag        = true;
    Tour.NameChangedFlag     = true;
    Tour.BusModelChangedFlag = false;
    Tour.ScheduleChangedFlag = true;

    ModifiedTourArray.push_back(Tour);
   }
 }

void               Self::ModifyTour   (const std::string  &TourIdStr)
 {
  if (!IsTourModified(TourIdStr))
   {
    TourDataCUTourType                 Tour;

    Tour.TourIdStr           = TourIdStr;
    Tour.TourNameStr         = "";
    Tour.BusModelStr         = "";
    Tour.AppendedFlag        = false;
    Tour.NameChangedFlag     = false;
    Tour.BusModelChangedFlag = false;
    Tour.ScheduleChangedFlag = false;

    ModifiedTourArray.push_back(Tour);
   }
 }

void               Self::ModifyTourSchedule
                                      (const std::string  &TourIdStr,
                                       TourDataPtrClass    SourceDataPtr)
 {
  TourDataCUTourType                  *TourPtr;
  TourTourSchedulePtrClass             SourceTourSchedulePtr;
  TourStopSchedulePtrClass             SourceStopSchedulePtr;
  unsigned int                         StopIndex;
  unsigned int                         StopCount;

  TourPtr               = TourInfoPtr(TourIdStr);
  SourceTourSchedulePtr = SourceDataPtr->Tour(TourIdStr)->Schedule();

  TourPtr->Schedule.clear();

  StopCount = SourceTourSchedulePtr->StopCount();

  for (StopIndex = 0; StopIndex < StopCount; StopIndex++)
   {
    TourDataCUStopScheduleType         StopSchedule;

    SourceStopSchedulePtr  = SourceTourSchedulePtr->StopSchedule(StopIndex);

    StopSchedule.StopIdStr = SourceStopSchedulePtr->Stop()->IdStr();
    StopSchedule.InTime    = SourceStopSchedulePtr->InTime();
    StopSchedule.WaitTime  = SourceStopSchedulePtr->WaitTime();

    TourPtr->Schedule.push_back(StopSchedule);
   }

  TourPtr->ScheduleChangedFlag = true;
 }

void               Self::DeleteTour   (const std::string  &TourIdStr)
 {
  unsigned int                         TourIndex;

  if (GetTourIndexById(&TourIndex,TourIdStr))
   {
    ModifiedTourArray.erase(ModifiedTourArray.begin() + TourIndex);
   }
 }

void               Self::Clear        (void)
 {
  ModifiedTourArray.clear();
 }

TourDataCUTourType
                  *Self::TourInfoPtr  (const std::string  &TourIdStr) const
 {
  unsigned int                         TourIndex;

  if (GetTourIndexById(&TourIndex,TourIdStr))
   {
    return((TourDataCUTourType*)&(ModifiedTourArray[TourIndex]));
   }
  else
   {
    return(NULL);
   }
 }

TourDataCUTourType
                  *Self::TourInfoPtr  (unsigned int        TourIndex) const
 {
  if (TourIndex < ModifiedTourArray.size())
   {
    return((TourDataCUTourType*)&(ModifiedTourArray[TourIndex]));
   }
  else
   {
    return(NULL);
   }
 }

bool               Self::GetTourIndexById
                                      (unsigned int       *TourIndexPtr,
                                       const std::string  &TourIdStr) const
 { 
  bool                                 FoundFlag;
  unsigned int                         TourIndex;
  unsigned int                         TourLimit;

  FoundFlag = false;
  TourIndex = 0;
  TourLimit = ModifiedTourArray.size();

  while ((TourIndex < TourLimit) && (!FoundFlag))
   {
    if (ModifiedTourArray[TourIndex].TourIdStr == TourIdStr)
     {
      FoundFlag     = true;
      *TourIndexPtr = TourIndex;
     }
    else
     {
      TourIndex++;
     }
   }

  return(FoundFlag);
 }

#undef             Self


#define            Self                TourCachedUpdateTourSetClass

                   Self::Self         (TourDataPtrClass   SourceDataPtr,
                                       TourDataCUModifiedTourStorageClass
                                                         *ModifiedTourStoragePtr)
 {
  this->SourceDataPtr          = SourceDataPtr;
  this->ModifiedTourStoragePtr = ModifiedTourStoragePtr;
  ModifiedFlag                 = false;       
 }

                   Self::~Self        (void)
 {
 }

unsigned int       Self::Count        (void) const
 {
  if (!ModifiedFlag)
   {
    return(SourceDataPtr->TourSet()->Count());
   }
  else
   {
    return(TourIdStrArray.size());
   }
 }

TourTourPtrClass   Self::Tour         (unsigned int        Index) const
 {
  std::string                          TourIdStr;

  if (!ModifiedFlag)
   {
    TourIdStr = SourceDataPtr->TourSet()->Tour(Index)->IdStr();
   }
  else
   {
    TourIdStr = TourIdStrArray[Index];
   }

  if (ModifiedTourStoragePtr->IsTourAppended(TourIdStr))
   {
    return(TourTourPtrClass
           (new TourCachedUpdateTourClass(SourceDataPtr,
                                          TourIdStr,
                                          TourTourPtrClass(NULL),
                                          ModifiedTourStoragePtr)));

   }
  else
   {    
    return(TourTourPtrClass
           (new TourCachedUpdateTourClass(SourceDataPtr,
                                          TourIdStr,
                                          SourceDataPtr->Tour(TourIdStr),
                                          ModifiedTourStoragePtr)));
   }
 }

void               Self::TourDeleted  (const std::string  &TourIdStr)
 {
  unsigned int                         TourIndex;
  
  if (!ModifiedFlag)
   {
    LoadSourceTourSet();
    ModifiedFlag = true;
   }

  if (GetTourIndexById(&TourIndex,TourIdStr))
   {
    TourIdStrArray.erase(TourIdStrArray.begin() + TourIndex);
   }
 }

void               Self::TourAppended (const std::string  &TourIdStr)
 {
  if (!ModifiedFlag)
   {
    LoadSourceTourSet();
    ModifiedFlag = true;
   }
  
  TourIdStrArray.push_back(TourIdStr);
 }

void               Self::CancelChanges(void)
 {
  TourIdStrArray.clear();
  ModifiedFlag = false;
 }

void               Self::LoadSourceTourSet  
                                      (void)
 {
  TourTourSetPtrClass                  SourceTourSetPtr;
  unsigned int                         TourIndex;
  unsigned int                         TourCount;

  SourceTourSetPtr = SourceDataPtr->TourSet();
  TourCount        = SourceTourSetPtr->Count();

  for (TourIndex = 0; TourIndex < TourCount; TourIndex++)
   {
    TourIdStrArray.push_back(SourceTourSetPtr->Tour(TourIndex)->IdStr());
   }
 }

bool               Self::GetTourIndexById   
                                      (unsigned int       *TourIndexPtr,
                                       const std::string  &TourIdStr)
 {
  bool                                 FoundFlag;
  unsigned int                         TourIndex;
  unsigned int                         TourLimit;

  FoundFlag = false;
  TourIndex = 0;
  TourLimit = TourIdStrArray.size();

  while ((TourIndex < TourLimit) && (!FoundFlag))
   {
    if (TourIdStrArray[TourIndex] == TourIdStr)
     {
      FoundFlag     = true;
      *TourIndexPtr = TourIndex;
     }
    else
     {
      TourIndex++;
     }
   }

  return(FoundFlag);
 }

#undef             Self


#define            Self                TourCachedUpdateDataClass

                   Self::Self         (TourDataPtrClass    SourceDataPtr):
                   TourSetPtr(NULL)
 {
  this->SourceDataPtr = SourceDataPtr;
  TourSetLowPtr       = new TourCachedUpdateTourSetClass(SourceDataPtr,&ModifiedTourStorage);
  TourSetPtr          = TourTourSetPtrClass(TourSetLowPtr);
 }

                   Self::~Self        (void)
 {
 }

TourTourSetPtrClass
                   Self::TourSet      (void) const
 {
  return(TourSetPtr);
 }

TourStopSetPtrClass
                   Self::StopSet      (void) const
 {
  return(SourceDataPtr->StopSet());
 }

TourTopologyPtrClass
                   Self::Topology     (void) const
 {
  return(SourceDataPtr->Topology());
 }

TourTourPtrClass   Self::Tour         (const std::string  &TourIdStr) const
 {
  if (ModifiedTourStorage.IsTourAppended(TourIdStr))
   {
    return(TourTourPtrClass
           (new TourCachedUpdateTourClass( SourceDataPtr,
                                           TourIdStr,
                                           TourTourPtrClass(NULL),
                                          (TourDataCUModifiedTourStorageClass*)&ModifiedTourStorage)));
   }
  else
   {
    return(TourTourPtrClass
           (new TourCachedUpdateTourClass( SourceDataPtr,
                                           TourIdStr,
                                           SourceDataPtr->Tour(TourIdStr),
                                          (TourDataCUModifiedTourStorageClass*)&ModifiedTourStorage)));
   }
 }

TourStopPtrClass   Self::Stop         (const std::string  &StopIdStr) const
 {
  return(SourceDataPtr->Stop(StopIdStr));
 }

TourBusPtrClass    Self::Bus          (const std::string  &ModelStr) const
 {
  return(SourceDataPtr->Bus(ModelStr));
 }

TourTourPtrClass   Self::AppendTour   (const std::string  &TourIdStr)
 {
  if (DeletedTourStorage.IsTourDeleted(TourIdStr))
   {
    DeletedTourStorage.UnDeleteTour(TourIdStr);
    ModifiedTourStorage.ModifyTour(TourIdStr);
   }
  else
   {
    ModifiedTourStorage.AppendTour(TourIdStr);
   }

  TourSetLowPtr->TourAppended(TourIdStr);

  return(TourTourPtrClass
         (new TourCachedUpdateTourClass( SourceDataPtr,
                                         TourIdStr,
                                         TourTourPtrClass(NULL),
                                        &ModifiedTourStorage)));
 }

void               Self::DeleteTour   (const std::string  &TourIdStr)
 {
  if (ModifiedTourStorage.IsTourAppended(TourIdStr))
   {
    ModifiedTourStorage.DeleteTour(TourIdStr);
    TourSetLowPtr->TourDeleted(TourIdStr);
   }
  else
   {
    if (!DeletedTourStorage.IsTourDeleted(TourIdStr))
     {
      if (ModifiedTourStorage.IsTourModified(TourIdStr))
       {
        ModifiedTourStorage.DeleteTour(TourIdStr);
       }

      DeletedTourStorage.DeleteTour(TourIdStr);
      TourSetLowPtr->TourDeleted(TourIdStr);
     }
   }  
 }

void               Self::Apply        (void)
 {
  unsigned int                         TourIndex;
  unsigned int                         TourCount;
  std::string                          TourIdStr;

  TourCount = DeletedTourStorage.TourCount();

  for (TourIndex = 0; TourIndex < TourCount; TourIndex++)
   {
    TourIdStr = DeletedTourStorage.TourIdStr(TourIndex);

    SourceDataPtr->DeleteTour(TourIdStr);
   }
  
  TourCount = ModifiedTourStorage.TourCount();

  for (TourIndex = 0; TourIndex < TourCount; TourIndex++)
   {
    ApplyTourModifyLow(ModifiedTourStorage.TourInfoPtr(TourIndex));
   }

  Cancel();
 }

void               Self::Cancel       (void)
 {
  DeletedTourStorage.Clear();
  ModifiedTourStorage.Clear();
  TourSetLowPtr->CancelChanges();
 }

void               Self::ApplyTourChanges   
                                      (const std::string  &TourIdStr)
 {
  if      (DeletedTourStorage.IsTourDeleted(TourIdStr))
   {
    SourceDataPtr->DeleteTour(TourIdStr);
    DeletedTourStorage.UnDeleteTour(TourIdStr);
   }
  else if (ModifiedTourStorage.IsTourModified(TourIdStr))
   {
    ApplyTourModifyLow(ModifiedTourStorage.TourInfoPtr(TourIdStr));
    ModifiedTourStorage.DeleteTour(TourIdStr);
   }
 }

unsigned int       Self::ChangesCount (void)
 {
  return(DeletedTourStorage.TourCount() + ModifiedTourStorage.TourCount());
 }

void               Self::GetChangeInfo(unsigned int       *ChangeTypeCodePtr,
                                       std::string        &ChangedTourIdStr,
                                       unsigned int        ChangeIndex)
 {
  if (ChangeIndex < DeletedTourStorage.TourCount())
   {
    *ChangeTypeCodePtr = TourCachedUpdateChangeTypeCodeTourDeleted;
    ChangedTourIdStr   = DeletedTourStorage.TourIdStr(ChangeIndex);
   }
  else
   {
    TourDataCUTourType                *TourInfoPtr;

    TourInfoPtr = ModifiedTourStorage.TourInfoPtr
                   (ChangeIndex - DeletedTourStorage.TourCount());

    ChangedTourIdStr = TourInfoPtr->TourIdStr;

    if (TourInfoPtr->AppendedFlag)
     {
      *ChangeTypeCodePtr = TourCachedUpdateChangeTypeCodeTourAppended;
     }
    else
     {
      *ChangeTypeCodePtr = TourCachedUpdateChangeTypeCodeTourModified;
     }
   }
 }

void               Self::ApplyTourModifyLow
                                      (TourDataCUTourType *TourDataPtr)
 {
  TourTourPtrClass                   TargetTourPtr;
  TourTourSchedulePtrClass           TargetTourSchedulePtr;

  if (TourDataPtr->AppendedFlag)
   {
    TargetTourPtr = SourceDataPtr->AppendTour(TourDataPtr->TourIdStr);
   }
  else
   {
    TargetTourPtr = SourceDataPtr->Tour(TourDataPtr->TourIdStr);
   }

  if (TourDataPtr->NameChangedFlag)
   {
    TargetTourPtr->SetName(TourDataPtr->TourNameStr);
   }
  
  if (TourDataPtr->BusModelChangedFlag)
   {
    TargetTourPtr->SetBusModel(TourDataPtr->BusModelStr);
   }
  
  TargetTourSchedulePtr = TargetTourPtr->Schedule();

  if (TourDataPtr->ScheduleChangedFlag)
   {
    unsigned int                     StopIndex;
    unsigned int                     StopLimit;
    TourStopSchedulePtrClass         TargetStopSchedulePtr;

    StopLimit = TargetTourSchedulePtr->StopCount();

    while (StopLimit > 0)
     {
      StopLimit--;

      TargetTourSchedulePtr->DeleteStopSchedule(StopLimit);
     }

    StopLimit = TourDataPtr->Schedule.size();

    for (StopIndex = 0; StopIndex < StopLimit; StopIndex++)
     {
      TargetStopSchedulePtr = TargetTourSchedulePtr->AppendStopSchedule
                               (TourDataPtr->Schedule[StopIndex].StopIdStr);

      TargetStopSchedulePtr->SetInTime(TourDataPtr->Schedule[StopIndex].InTime);
      TargetStopSchedulePtr->SetWaitTime(TourDataPtr->Schedule[StopIndex].WaitTime);
     }
   }
 }

#undef             Self

