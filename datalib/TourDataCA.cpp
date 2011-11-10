
#include <string>
#include <vector>

#include <TourTime.h>

#include <TourData.h>
#include <TourDataCA.h>

typedef struct
 {
  std::string      FromStopIdStr;
  std::string      ToStopIdStr;
  bool             ExistsFlag;
  float            Distance;
 } TourCATopologyLinkType;

class TourCAStopClass : public TourStopClass
 {
  #define          Self                TourCAStopClass

  public           :

                   Self               (TourDataPtrClass    SourceDataPtr,
                                       const std::string  &IdStr);

  virtual         ~Self               (void);

  virtual
  std::string      IdStr              (void) const;

  virtual
  std::string      NameStr            (void) const;

  private          :

  TourDataPtrClass                     SourceDataPtr;
  std::string                          StopIdStr;
  mutable bool                         StopNameLoadedFlag;
  mutable std::string                  StopNameStr;

  #undef           Self
 };

class TourCAStopScheduleClass : public TourStopScheduleClass
 {
  #define          Self                TourCAStopScheduleClass

  public           :

                   Self               (TourDataPtrClass    SourceDataPtr,
                                       TourCATourCacheClass
                                                          *TourCachePtr,
                                       TourCATourScheduleCacheClass
                                                          *ScheduleCachePtr,
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

  TourDataPtrClass                     SourceDataPtr;
  TourCATourCacheClass                *TourCachePtr;
  TourCATourScheduleCacheClass        *ScheduleCachePtr;
  std::string                          TourIdStr;
  unsigned int                         StopIndex;

  #undef           Self
 };

class TourCATourScheduleClass : public TourTourScheduleClass
 {
  #define          Self                TourCATourScheduleClass

  public           :

                   Self               (TourDataPtrClass    DataPtr,
                                       TourCATourCacheClass
                                                          *TourCachePtr,
                                       TourCATourScheduleCacheClass
                                                          *ScheduleCachePtr,
                                       const std::string  &TourIdStr);
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

  TourDataPtrClass                     DataPtr;
  TourCATourCacheClass                *TourCachePtr;
  TourCATourScheduleCacheClass        *ScheduleCachePtr;
  std::string                          TourIdStr;

  #undef           Self
 };

class TourCATourClass : public TourTourClass
 {
  #define          Self                TourCATourClass

  public           :

                   Self               (TourTourPtrClass    SourceTourPtr,
                                       TourDataPtrClass    SourceDataPtr,
                                       TourCATourCacheClass
                                                          *TourCachePtr,
                                       TourCATourScheduleCacheClass
                                                          *ScheduleCachePtr);

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

  std::string                          CachedIdStr;
  TourDataPtrClass                     SourceDataPtr;
  TourTourPtrClass                     SourceTourPtr;
  TourCATourCacheClass                *TourCachePtr;
  TourCATourScheduleCacheClass        *ScheduleCachePtr;

  #undef           Self
 };

class TourCATourSetClass : public TourTourSetClass
 {
  #define          Self                TourCATourSetClass

  public           :

                   Self               (TourDataPtrClass    SourceDataPtr,
                                       TourTourSetPtrClass SourceTourSetPtr,
                                       TourCATourCacheClass
                                                          *TourCachePtr,
                                       TourCATourScheduleCacheClass
                                                          *ScheduleCachePtr);

  virtual         ~Self               (void);

  virtual
  unsigned int     Count              (void) const;

  virtual
  TourTourPtrClass Tour               (unsigned int        Index) const;

  private          :

  TourDataPtrClass                     SourceDataPtr;
  TourTourSetPtrClass                  SourceTourSetPtr;
  TourCATourCacheClass                *TourCachePtr;
  TourCATourScheduleCacheClass        *ScheduleCachePtr;

  #undef           Self
 };

class TourCAStopSetClass : public TourStopSetClass
 {
  #define          Self                TourCAStopSetClass

  public           :

                   Self               (TourCacheDataClass *ParentDataPtr,
                                       TourDataPtrClass    SourceDataPtr);

  virtual         ~Self               (void);

  virtual
  unsigned int     Count              (void) const;

  virtual
  TourStopPtrClass Stop               (unsigned int        Index) const;

  private          :

  void             Load               (void);

  bool                                 LoadedFlag;
  TourStringVectorClass                StopIdStrArray;

  TourCacheDataClass                  *ParentDataPtr;
  TourDataPtrClass                     SourceDataPtr;

  #undef           Self
 };

class TourCATopologyClass : public TourTopologyClass
 {
  #define          Self                TourCATopologyClass

  public           :

                   Self               (TourTopologyPtrClass
                                                          SourceTopologyPtr);
  virtual         ~Self               (void);

  virtual bool     DirectLinkExists   (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const;

  virtual float    DirectLinkDistance (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const;

  private          :

  void             GetLinkInfo        (bool               *ExistsFlagPtr,
                                       float              *DistancePtr,
                                       const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const;

  TourTopologyPtrClass                 SourceTopologyPtr;
  mutable std::vector<TourCATopologyLinkType>
                                       LinkArray;

  #undef           Self
 };

#define            Self                TourCATourScheduleCacheClass

                   Self::Self         (TourDataPtrClass    SourceDataPtr)
 {
  this->SourceDataPtr = SourceDataPtr;
 }

TourCATourScheduleType
                  *Self::TourSchedulePtr
                                      (const std::string  &TourIdStr)
 {
  unsigned int                         Index;
  unsigned int                         Limit;
  bool                                 FoundFlag;


  Index     = 0;
  Limit     = TourScheduleArray.size();
  FoundFlag = false;

  while ((Index < Limit) && (!FoundFlag))
   {
    if (TourScheduleArray[Index].TourIdStr == TourIdStr)
     {
      FoundFlag = true;
     }
    else
     {
      Index++;
     }
   }

  if (!FoundFlag)
   {
    TourTourSchedulePtrClass           SchedulePtr;
    unsigned int                       StopIndex;
    unsigned int                       StopLimit;
    TourCATourScheduleType             ScheduleInfo;

    ScheduleInfo.TourIdStr = TourIdStr;

    SchedulePtr = SourceDataPtr->Tour(TourIdStr)->Schedule();
    StopLimit   = SchedulePtr->StopCount();

    for (StopIndex = 0; StopIndex < StopLimit; StopIndex++)
     {
      TourStopSchedulePtrClass         StopSchedulePtr;
      TourCAStopScheduleType           StopScheduleInfo;
      
      StopSchedulePtr = SchedulePtr->StopSchedule(StopIndex);
      
      StopScheduleInfo.StopIdStr = StopSchedulePtr->Stop()->IdStr();
      StopScheduleInfo.InTime    = StopSchedulePtr->InTime();
      StopScheduleInfo.WaitTime  = StopSchedulePtr->WaitTime();
      
      ScheduleInfo.StopScheduleArray.push_back(StopScheduleInfo);
     }
    
    TourScheduleArray.push_back(ScheduleInfo);

    Index = TourScheduleArray.size() - 1;
   }

  return(&(TourScheduleArray[Index]));
 }

#undef             Self

#define            Self                TourCATourCacheClass

                   Self::Self         (TourDataPtrClass    SourceDataPtr)
 {
  this->SourceDataPtr = SourceDataPtr;
 }

std::string        Self::TourNameStr  (const std::string  &TourIdStr) const
 {
  unsigned int                         TourIndex;

  if (!GetTourIndexById(&TourIndex,TourIdStr))
   {
    TourIndex = AppendTour(TourIdStr);
   }

  if (!TourInfoArray[TourIndex].NameLoadedFlag)
   {
    TourInfoArray[TourIndex].NameStr = SourceDataPtr->Tour(TourIdStr)->NameStr();
    TourInfoArray[TourIndex].NameLoadedFlag = true;
   }

  return(TourInfoArray[TourIndex].NameStr);
 }

float              Self::TourAverageSpeed   
                                      (const std::string  &TourIdStr) const
 {
  unsigned int                         TourIndex;

  if (!GetTourIndexById(&TourIndex,TourIdStr))
   {
    TourIndex = AppendTour(TourIdStr);
   }

  if (!TourInfoArray[TourIndex].AverageSpeedLoadedFlag)
   {
    TourInfoArray[TourIndex].AverageSpeed = SourceDataPtr->Tour(TourIdStr)->AverageSpeed();
    TourInfoArray[TourIndex].AverageSpeedLoadedFlag = true;
   }

  return(TourInfoArray[TourIndex].AverageSpeed);
 }

float              Self::TourTotalDistance   
                                      (const std::string  &TourIdStr) const
 {
  unsigned int                         TourIndex;

  if (!GetTourIndexById(&TourIndex,TourIdStr))
   {
    TourIndex = AppendTour(TourIdStr);
   }

  if (!TourInfoArray[TourIndex].TotalDistanceLoadedFlag)
   {
    TourInfoArray[TourIndex].TotalDistance           = SourceDataPtr->Tour(TourIdStr)->TotalDistance();
    TourInfoArray[TourIndex].TotalDistanceLoadedFlag = true;
   }

  return(TourInfoArray[TourIndex].TotalDistance);
 }

void               Self::SetTourName  (const std::string  &TourIdStr,
                                       const std::string  &TourNameStr)
 {
  unsigned int                         TourIndex;

  if (GetTourIndexById(&TourIndex,TourIdStr))
   {
    TourInfoArray[TourIndex].NameStr        = TourNameStr;
    TourInfoArray[TourIndex].NameLoadedFlag = true;
   }
 }

void               Self::ResetAverageSpeed
                                      (const std::string  &TourIdStr)
 {
  unsigned int                         TourIndex;

  if (GetTourIndexById(&TourIndex,TourIdStr))
   {
    TourInfoArray[TourIndex].AverageSpeedLoadedFlag = false;
   }
 }

void               Self::ResetTotalDistance
                                      (const std::string  &TourIdStr)
 {
  unsigned int                         TourIndex;

  if (GetTourIndexById(&TourIndex,TourIdStr))
   {
    TourInfoArray[TourIndex].TotalDistanceLoadedFlag = false;
   }
 }

void               Self::DeleteTour   (const std::string  &TourIdStr)
 {
  unsigned int                         TourIndex;

  if (GetTourIndexById(&TourIndex,TourIdStr))
   {
    TourInfoArray.erase(TourInfoArray.begin() + TourIndex);
   }
 }

bool               Self::GetTourIndexById   
                                      (unsigned int       *TourIndexPtr,
                                       const std::string  &TourIdStr) const
 {
  unsigned int                         Index;
  unsigned int                         Count;
  bool                                 FoundFlag;

  Index     = 0;
  Count     = TourInfoArray.size();
  FoundFlag = false;

  while ((Index < Count) && (!FoundFlag))
   {
    if (TourInfoArray[Index].IdStr == TourIdStr)
     {
      FoundFlag     = true;
      *TourIndexPtr = Index;
     }
    else
     {
      Index++;
     }
   }

  return(FoundFlag);
 }

unsigned int       Self::AppendTour   (const std::string  &TourIdStr)
 {
  unsigned int                         Result;
  TourCATourType                       TourInfo;

  Result = TourInfoArray.size();

  TourInfo.IdStr                   = TourIdStr;
  TourInfo.NameStr                 = "";
  TourInfo.NameLoadedFlag          = false;
  TourInfo.AverageSpeed            = 0.0;
  TourInfo.AverageSpeedLoadedFlag  = false;
  TourInfo.TotalDistance           = 0.0;
  TourInfo.TotalDistanceLoadedFlag = false;

  TourInfoArray.push_back(TourInfo);

  return(Result);
 }

#undef             Self


#define            Self                TourCAStopClass

                   Self::Self         (TourDataPtrClass    SourceDataPtr,
                                       const std::string  &IdStr)
 {
  this->SourceDataPtr = SourceDataPtr;
  StopIdStr           = IdStr;
  StopNameLoadedFlag  = false;
 }

                   Self::~Self        (void)
 {
 }

std::string        Self::IdStr        (void) const
 {
  return(StopIdStr);
 }

std::string        Self::NameStr      (void) const
 {
  if (!StopNameLoadedFlag)
   {
    StopNameStr        = SourceDataPtr->Stop(StopIdStr)->NameStr();
    StopNameLoadedFlag = true;
   }

  return(StopNameStr);
 }

#undef             Self


#define            Self                TourCAStopScheduleClass

                   Self::Self         (TourDataPtrClass    SourceDataPtr,
                                       TourCATourCacheClass
                                                          *TourCachePtr,
                                       TourCATourScheduleCacheClass
                                                          *ScheduleCachePtr,
                                       const std::string  &TourIdStr,
                                       unsigned int        StopIndex)
 {
  this->SourceDataPtr    = SourceDataPtr;
  this->TourCachePtr     = TourCachePtr;
  this->ScheduleCachePtr = ScheduleCachePtr;
  this->TourIdStr        = TourIdStr;
  this->StopIndex        = StopIndex;
 }

                   Self::~Self        (void)
 {
 }

TourStopPtrClass   Self::Stop         (void) const
 {
  return(TourStopPtrClass
          (new TourCAStopClass
                (SourceDataPtr,
                 ScheduleCachePtr->TourSchedulePtr(TourIdStr)
                  ->StopScheduleArray[StopIndex].StopIdStr)));
 }

TourTimeClass      Self::InTime       (void) const
 {
  return(ScheduleCachePtr->TourSchedulePtr(TourIdStr)
          ->StopScheduleArray[StopIndex].InTime);
 }

TourTimeClass      Self::WaitTime     (void) const
 {
  return(ScheduleCachePtr->TourSchedulePtr(TourIdStr)
          ->StopScheduleArray[StopIndex].WaitTime);
 }

void               Self::SetInTime    (const TourTimeClass&Time)
 {
  SourceDataPtr->Tour(TourIdStr)->Schedule()
   ->StopSchedule(StopIndex)->SetInTime(Time);

  ScheduleCachePtr->TourSchedulePtr(TourIdStr)
   ->StopScheduleArray[StopIndex].InTime = Time;

  TourCachePtr->ResetAverageSpeed(TourIdStr);
 }

void               Self::SetWaitTime  (const TourTimeClass&Time)
 {
  SourceDataPtr->Tour(TourIdStr)->Schedule()
   ->StopSchedule(StopIndex)->SetWaitTime(Time);

  ScheduleCachePtr->TourSchedulePtr(TourIdStr)
   ->StopScheduleArray[StopIndex].WaitTime = Time;
   
  TourCachePtr->ResetAverageSpeed(TourIdStr);
 }

#undef             Self


#define            Self                TourCATourScheduleClass

                   Self::Self         (TourDataPtrClass    DataPtr,
                                       TourCATourCacheClass
                                                          *TourCachePtr,
                                       TourCATourScheduleCacheClass
                                                          *ScheduleCachePtr,
                                       const std::string  &TourIdStr)
 {
  this->DataPtr          = DataPtr;
  this->TourCachePtr     = TourCachePtr;
  this->ScheduleCachePtr = ScheduleCachePtr;
  this->TourIdStr        = TourIdStr;
 }

                   Self::~Self        (void)
 {
 }

unsigned int       Self::StopCount    (void) const
 {
  return(ScheduleCachePtr->TourSchedulePtr(TourIdStr)->StopScheduleArray.size());
 }

TourStopSchedulePtrClass
                   Self::StopSchedule (unsigned int        StopIndex) const
 {
  if (StopIndex < StopCount())
   {
    return(TourStopSchedulePtrClass
            (new TourCAStopScheduleClass
                  (DataPtr,TourCachePtr,ScheduleCachePtr,TourIdStr,StopIndex)));
   }
  else
   {
    return(TourStopSchedulePtrClass());
   }
 }

TourStopSchedulePtrClass
                   Self::AppendStopSchedule
                                      (const std::string  &StopIdStr)
 {
  TourTourSchedulePtrClass             SourceTourSchedulePtr;
  TourStopSchedulePtrClass             SourceStopSchedulePtr;
  TourCAStopScheduleType               StopScheduleInfo;
  unsigned int                         StopIndex;
  TourCATourScheduleType              *TourSchedulePtr;

  SourceTourSchedulePtr = DataPtr->Tour(TourIdStr)->Schedule();
  SourceStopSchedulePtr = SourceTourSchedulePtr->AppendStopSchedule(StopIdStr);

  StopScheduleInfo.StopIdStr = StopIdStr;
  StopScheduleInfo.InTime    = TourTimeClass();
  StopScheduleInfo.WaitTime  = TourTimeClass();

  TourSchedulePtr = ScheduleCachePtr->TourSchedulePtr(TourIdStr);

  StopIndex = TourSchedulePtr->StopScheduleArray.size();

  TourSchedulePtr->StopScheduleArray.push_back(StopScheduleInfo);

  TourCachePtr->ResetAverageSpeed(TourIdStr);
  TourCachePtr->ResetTotalDistance(TourIdStr);

  return(TourStopSchedulePtrClass
          (new TourCAStopScheduleClass
                (DataPtr,TourCachePtr,ScheduleCachePtr,TourIdStr,StopIndex)));
 }

TourStopSchedulePtrClass
                   Self::InsertStopSchedule
                                      (unsigned int        StopIndex,
                                       const std::string  &StopIdStr)
 {
  TourTourSchedulePtrClass             SourceTourSchedulePtr;
  TourStopSchedulePtrClass             SourceStopSchedulePtr;
  TourCAStopScheduleType               StopScheduleInfo;
  TourCATourScheduleType              *TourSchedulePtr;

  if (StopIndex < StopCount())
   {
    SourceTourSchedulePtr = DataPtr->Tour(TourIdStr)->Schedule();
    SourceStopSchedulePtr = SourceTourSchedulePtr->InsertStopSchedule(StopIndex,StopIdStr);

    StopScheduleInfo.StopIdStr = StopIdStr;
    StopScheduleInfo.InTime    = TourTimeClass();
    StopScheduleInfo.WaitTime  = TourTimeClass();

    TourSchedulePtr = ScheduleCachePtr->TourSchedulePtr(TourIdStr);

    TourSchedulePtr->StopScheduleArray.insert
     (TourSchedulePtr->StopScheduleArray.begin() + StopIndex,
      StopScheduleInfo);

    TourCachePtr->ResetAverageSpeed(TourIdStr);
    TourCachePtr->ResetTotalDistance(TourIdStr);

    return(TourStopSchedulePtrClass
            (new TourCAStopScheduleClass
                  (DataPtr,TourCachePtr,ScheduleCachePtr,TourIdStr,StopIndex)));
   }
  else
   {
    return(AppendStopSchedule(StopIdStr));
   }
 }

void               Self::DeleteStopSchedule 
                                      (unsigned int        StopIndex)
 {
  TourTourSchedulePtrClass             SourceTourSchedulePtr;
  TourCATourScheduleType              *TourSchedulePtr;

  if (StopIndex < StopCount())
   {
    SourceTourSchedulePtr = DataPtr->Tour(TourIdStr)->Schedule();
    TourSchedulePtr = ScheduleCachePtr->TourSchedulePtr(TourIdStr);

    SourceTourSchedulePtr->DeleteStopSchedule(StopIndex);
    TourSchedulePtr->StopScheduleArray.erase
     (TourSchedulePtr->StopScheduleArray.begin() + StopIndex);
     
    TourCachePtr->ResetAverageSpeed(TourIdStr);
    TourCachePtr->ResetTotalDistance(TourIdStr);
   }
 }

#undef             Self

#define            Self                TourCATourClass

                   Self::Self         (TourTourPtrClass    SourceTourPtr,
                                       TourDataPtrClass    SourceDataPtr,
                                       TourCATourCacheClass
                                                          *TourCachePtr,
                                       TourCATourScheduleCacheClass
                                                          *ScheduleCachePtr)
 {
  this->SourceDataPtr    = SourceDataPtr;
  this->SourceTourPtr    = SourceTourPtr;
  this->TourCachePtr     = TourCachePtr;
  this->ScheduleCachePtr = ScheduleCachePtr;
  CachedIdStr            = SourceTourPtr->IdStr();
 }

                   Self::~Self        (void)
 {
 }

std::string        Self::IdStr        (void) const
 {
  return(CachedIdStr);
 }

std::string        Self::NameStr      (void) const
 {
  return(TourCachePtr->TourNameStr(CachedIdStr));
 }

TourTourSchedulePtrClass
                   Self::Schedule     (void) const
 {
  return(TourTourSchedulePtrClass
          (new TourCATourScheduleClass
                (SourceDataPtr,
                 TourCachePtr,
                 ScheduleCachePtr,
                 CachedIdStr)));
 }

TourBusPtrClass    Self::Bus          (void) const
 {
  return(SourceTourPtr->Bus());
 }

float              Self::AverageSpeed (void) const
 {
  return(TourCachePtr->TourAverageSpeed(CachedIdStr));
 }

float              Self::TotalDistance(void) const
 {
  return(TourCachePtr->TourTotalDistance(CachedIdStr));
 }

void               Self::SetName      (const std::string  &NameStr)
 {
  SourceTourPtr->SetName(NameStr);

  TourCachePtr->SetTourName(CachedIdStr,NameStr);
 }

void               Self::SetBusModel  (const std::string  &ModelStr)
 {
  SourceTourPtr->SetBusModel(ModelStr);
 }

#undef             Self


#define            Self                TourCATourSetClass

                   Self::Self         (TourDataPtrClass    SourceDataPtr,
                                       TourTourSetPtrClass SourceTourSetPtr,
                                       TourCATourCacheClass
                                                          *TourCachePtr,
                                       TourCATourScheduleCacheClass
                                                          *ScheduleCachePtr)
 {
  this->SourceDataPtr    = SourceDataPtr;
  this->SourceTourSetPtr = SourceTourSetPtr;
  this->TourCachePtr     = TourCachePtr;
  this->ScheduleCachePtr = ScheduleCachePtr;
 }

                   Self::~Self        (void)
 {
 }

unsigned int       Self::Count        (void) const
 {
  return(SourceTourSetPtr->Count());
 }

TourTourPtrClass   Self::Tour         (unsigned int        Index) const
 {
  return(TourTourPtrClass
          (new TourCATourClass(SourceTourSetPtr->Tour(Index),
                               SourceDataPtr,
                               TourCachePtr,
                               ScheduleCachePtr)));
 }

#undef             Self


#define            Self                TourCAStopSetClass

                   Self::Self         (TourCacheDataClass *ParentDataPtr,
                                       TourDataPtrClass    SourceDataPtr)
 {
  LoadedFlag = false;

  this->ParentDataPtr = ParentDataPtr;
  this->SourceDataPtr = SourceDataPtr;
 }

                   Self::~Self        (void)
 {
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

  if (Index < Count())
   {
    return(ParentDataPtr->Stop(StopIdStrArray[Index]));
   }
  else
   {
    return(TourStopPtrClass(NULL));
   }
 }

void               Self::Load         (void)
 {
  TourStopSetPtrClass                  StopSetPtr;
  unsigned int                         Index;
  unsigned int                         Limit;

  StopSetPtr = SourceDataPtr->StopSet();

  Limit = StopSetPtr->Count();

  for (Index = 0; Index < Limit; Index++)
   {
    StopIdStrArray.push_back(StopSetPtr->Stop(Index)->IdStr());
   }

  LoadedFlag = true;
 }

#undef             Self


#define            Self                TourCATopologyClass

                   Self::Self         (TourTopologyPtrClass 
                                                          SourceTopologyPtr)
 {
  this->SourceTopologyPtr = SourceTopologyPtr;
 }

                   Self::~Self        (void)
 {
 }

bool               Self::DirectLinkExists   
                                      (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const
 {
  bool                                 ExistsFlag;
  float                                Distance;

  GetLinkInfo(&ExistsFlag,&Distance,FromStopIdStr,ToStopIdStr);

  return(ExistsFlag);
 }

float              Self::DirectLinkDistance 
                                      (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const
 {
  bool                                 ExistsFlag;
  float                                Distance;

  GetLinkInfo(&ExistsFlag,&Distance,FromStopIdStr,ToStopIdStr);

  return(Distance);
 }

void               Self::GetLinkInfo  (bool               *ExistsFlagPtr,
                                       float              *DistancePtr,
                                       const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const
 {
  unsigned int     Index;
  unsigned int     Limit;
  bool             FoundFlag;

  Index     = 0;
  Limit     = LinkArray.size();
  FoundFlag = false;

  while ((Index < Limit) && (!FoundFlag))
   {
    if ((LinkArray[Index].FromStopIdStr == FromStopIdStr) &&
        (LinkArray[Index].ToStopIdStr   == ToStopIdStr))
     {
      FoundFlag = true;
     }
    else
     {
      Index++;
     }
   }

  if (FoundFlag)
   {
    *ExistsFlagPtr = LinkArray[Index].ExistsFlag;
    *DistancePtr   = LinkArray[Index].Distance;
   }
  else
   {
    bool                               ExistsFlag;
    float                              Distance;
    TourCATopologyLinkType             LinkInfo;

    ExistsFlag = SourceTopologyPtr->DirectLinkExists(FromStopIdStr,ToStopIdStr);

    if (ExistsFlag)
     {
      Distance = SourceTopologyPtr->DirectLinkDistance(FromStopIdStr,ToStopIdStr);
     }
    else
     {
      Distance = 0.0;
     }

    LinkInfo.FromStopIdStr = FromStopIdStr;
    LinkInfo.ToStopIdStr   = ToStopIdStr;
    LinkInfo.ExistsFlag    = ExistsFlag;
    LinkInfo.Distance      = Distance;

    LinkArray.push_back(LinkInfo);

    *ExistsFlagPtr = ExistsFlag;
    *DistancePtr   = Distance;
   }
 }

#undef             Self


#define            Self                TourCacheDataClass

                   Self::Self         (TourDataPtrClass    SourceDataPtr)
                   : TourSetPtr(SourceDataPtr->TourSet()),
                     StopSetPtr(new TourCAStopSetClass(this,SourceDataPtr)),
                     TopologyPtr(new TourCATopologyClass(SourceDataPtr->Topology())),
                     TourCache(SourceDataPtr),
                     ScheduleCache(SourceDataPtr)
 {
  this->SourceDataPtr = SourceDataPtr;
 }

                   Self::~Self        (void)
 {
 }

TourTourSetPtrClass
                   Self::TourSet      (void) const
 {
  return(TourTourSetPtrClass
          (new TourCATourSetClass
                (SourceDataPtr,
                 TourSetPtr,
                 (TourCATourCacheClass*)&TourCache,
                 (TourCATourScheduleCacheClass*)&ScheduleCache)));
 }

TourStopSetPtrClass
                   Self::StopSet      (void) const
 {
//  return(SourceDataPtr->StopSet());
  return(StopSetPtr);
 }

TourTopologyPtrClass
                   Self::Topology     (void) const
 {
  return(TopologyPtr);
 }

TourTourPtrClass   Self::Tour         (const std::string  &TourIdStr) const
 {
  return(TourTourPtrClass
          (new TourCATourClass
                ( SourceDataPtr->Tour(TourIdStr),
                  SourceDataPtr,
                 (TourCATourCacheClass*)&TourCache, 
                 (TourCATourScheduleCacheClass*)&ScheduleCache)));
 }

TourStopPtrClass   Self::Stop         (const std::string  &StopIdStr) const
 {
  unsigned int                         StopIndex;
  unsigned int                         StopLimit;
  bool                                 FoundFlag;
  TourStopPtrClass                     Result;

  StopIndex = 0;
  StopLimit = StopCache.size();
  FoundFlag = false;

  while ((StopIndex < StopLimit) && (!FoundFlag))
   {
    if (StopCache[StopIndex]->IdStr() == StopIdStr)
     {
      FoundFlag = true;
      Result    = StopCache[StopIndex];
     }
    else
     {
      StopIndex++;
     }
   }

  if (!FoundFlag)
   {
    Result = TourStopPtrClass(new TourCAStopClass(SourceDataPtr,StopIdStr));
    StopCache.push_back(Result);
   }
  
  return(Result);
 }

TourBusPtrClass    Self::Bus          (const std::string  &ModelStr) const
 {
  return(SourceDataPtr->Bus(ModelStr));
 }

TourTourPtrClass   Self::AppendTour   (const std::string  &TourIdStr)
 {
  TourTourPtrClass                     Result;
  
  Result     = SourceDataPtr->AppendTour(TourIdStr);
  TourSetPtr = SourceDataPtr->TourSet();

  return(Result);
 }

void               Self::DeleteTour   (const std::string  &TourIdStr)
 {
  SourceDataPtr->DeleteTour(TourIdStr);
  TourSetPtr = SourceDataPtr->TourSet();
 }

#undef             Self

