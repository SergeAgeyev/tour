#include <string.h>

#include <vector>
#include <string>

#include <TourData.h>
#include <TourDataDM.h>

static bool        TourDemoGetStopPtrById
                                      (const TourDemoStopType**StopPtrPtr,
                                       const char              *IdStrPtr,
                                       const TourDemoStopType  *StopArrayPtr,
                                       unsigned int             StopArraySize)
 {
  unsigned int                         StopIndex;
  bool                                 FoundFlag;

  StopIndex = 0;
  FoundFlag = false;

  while ((StopIndex < StopArraySize) && (!FoundFlag))
   {
    if (!strcmp(IdStrPtr,StopArrayPtr[StopIndex].IdStrPtr))
     {
      FoundFlag   = true;
      *StopPtrPtr = &(StopArrayPtr[StopIndex]);
     }
    else
     {
      StopIndex++;
     }
   }

  return(FoundFlag);
 }

static bool        TourDemoGetBusPtrById
                                      (const TourDemoBusType  **BusPtrPtr,
                                       const char              *ModelStrPtr,
                                       const TourDemoBusType   *BusArrayPtr,
                                       unsigned int             BusArraySize)
 {
  unsigned int                         BusIndex;
  bool                                 FoundFlag;

  BusIndex  = 0;
  FoundFlag = false;

  while ((BusIndex < BusArraySize) && (!FoundFlag))
   {
    if (!strcmp(ModelStrPtr,BusArrayPtr[BusIndex].ModelStrPtr))
     {
      FoundFlag  = true;
      *BusPtrPtr = &(BusArrayPtr[BusIndex]);
     }
    else
     {
      BusIndex++;
     }
   }

  return(FoundFlag);
 }

static bool        TourDemoGetTourPtrById
                                      (const TourDemoTourType **TourPtrPtr,
                                       const char              *IdStrPtr,
                                       const TourDemoTourType  *TourArrayPtr,
                                       unsigned int             TourArraySize)
 {
  unsigned int                         TourIndex;
  bool                                 FoundFlag;

  TourIndex = 0;
  FoundFlag = false;

  while ((TourIndex < TourArraySize) && (!FoundFlag))
   {
    if (!strcmp(IdStrPtr,TourArrayPtr[TourIndex].IdStrPtr))
     {
      FoundFlag   = true;
      *TourPtrPtr = &(TourArrayPtr[TourIndex]);
     }
    else
     {
      TourIndex++;
     }
   }

  return(FoundFlag);
 }

static bool        TourDemoGetDirectLinkIndex
                                      (unsigned int            *IndexPtr,
                                       const char              *FromStopIdStrPtr,
                                       const char              *ToStopIdStrPtr,
                                       const TourDemoTopologyType
                                                               *TopologyArrayPtr,
                                       unsigned int             TopologyArraySize)
 {
  unsigned int                         Index;
  bool                                 FoundFlag;

  Index     = 0;
  FoundFlag = false;

  while ((Index < TopologyArraySize) && (!FoundFlag))
   {
    if ((!strcmp(TopologyArrayPtr[Index].FromStopIdStrPtr,FromStopIdStrPtr)) &&
        (!strcmp(TopologyArrayPtr[Index].ToStopIdStrPtr,ToStopIdStrPtr)))
     {
      *IndexPtr = Index;
      FoundFlag = true;
     }
    else
     {
      Index++;
     }
   }

  return(FoundFlag);
 }

#define            Self                TourDemoBusClass

                   Self::Self         (const TourDemoBusType   *BusPtr)
 {
  this->BusPtr = BusPtr;
 }

                   Self::~Self        (void)
 {
 }

std::string        Self::ModelStr     (void) const
 {
  return(BusPtr->ModelStrPtr);
 }

std::string        Self::DescriptionStr
                                      (void) const
 {
  return(BusPtr->DescStrPtr);
 }

unsigned int       Self::Capacity     (void) const
 {
  return(BusPtr->Capacity);
 }

#undef             Self


#define            Self                TourDemoStopClass

                   Self::Self         (const TourDemoStopType  *StopPtr)
 {
  this->StopPtr = StopPtr;
 }
 
                   Self::~Self        (void)
 {
 }

std::string        Self::IdStr        (void) const
 {
  return(StopPtr->IdStrPtr);
 }

std::string        Self::NameStr      (void) const
 {
  return(StopPtr->NameStrPtr);
 }

#undef             Self


#define            Self                TourDemoStopScheduleClass

                   Self::Self         (const TourDemoStopScheduleType
                                                               *StopSchedulePtr,
                                       const TourDemoStopType  *StopPtr)
 {
  this->StopSchedulePtr = StopSchedulePtr;
  this->StopPtr         = StopPtr;
 }

                   Self::~Self        (void)
 {
 }

TourStopPtrClass   Self::Stop         (void) const
 {
  return(TourStopPtrClass(new TourDemoStopClass(StopPtr)));
 }

TourTimeClass      Self::InTime       (void) const
 {
  return(TourTimeClass(StopSchedulePtr->InTime.MinuteCount));
 }

TourTimeClass      Self::WaitTime     (void) const
 {
  return(TourTimeClass(StopSchedulePtr->WaitTime.MinuteCount));
 }

void               Self::SetInTime    (const TourTimeClass&Time)
 {
  // Not available
 }

void               Self::SetWaitTime  (const TourTimeClass&Time)
 {
  // Not available
 }

#undef             Self


#define            Self                TourDemoTourScheduleClass

                   Self::Self         (const TourDemoStopScheduleType
                                                          *StopScheduleArrayPtr,
                                       unsigned int        StopCount,
                                       const TourDemoStopType
                                                          *StopArrayPtr,
                                       unsigned int        StopArraySize)
 {
  this->StopScheduleArrayPtr = StopScheduleArrayPtr;
  this->ScheduleStopCount    = StopCount;
  this->StopArrayPtr         = StopArrayPtr;
  this->StopArraySize        = StopArraySize;
 }

                   Self::~Self        (void)
 {
 }

unsigned int       Self::StopCount    (void) const
 {
  return(ScheduleStopCount);
 }

TourStopSchedulePtrClass
                   Self::StopSchedule (unsigned int        StopIndex) const
 {
  const TourDemoStopType              *StopPtr;

  if (TourDemoGetStopPtrById
       (&StopPtr,
        StopScheduleArrayPtr[StopIndex].StopIdStrPtr,
        StopArrayPtr,
        StopArraySize))
   {
    return(TourStopSchedulePtrClass
            (new TourDemoStopScheduleClass
                  (&(StopScheduleArrayPtr[StopIndex]),StopPtr)));
   }
  else
   {
    return(TourStopSchedulePtrClass(NULL));
   }
 }

TourStopSchedulePtrClass
                   Self::AppendStopSchedule
                                      (const std::string  &StopIdStr)
 {
  // Not available

  return(TourStopSchedulePtrClass(NULL));
 }

TourStopSchedulePtrClass
                   Self::InsertStopSchedule
                                      (unsigned int        StopIndex,
                                       const std::string  &StopIdStr)
 {
  // Not available

  return(TourStopSchedulePtrClass(NULL));
 }

void               Self::DeleteStopSchedule
                                      (unsigned int        StopIndex)
 {
  // Not available
 }

#undef             Self


#define            Self                TourDemoTourClass

                   Self::Self         (const TourDemoTourType  *TourPtr,
                                       const TourDemoStopScheduleType
                                                               *StopScheduleArrayPtr,
                                       const TourDemoStopType
                                                          *StopArrayPtr,
                                       unsigned int        StopArraySize,
                                       const TourDemoBusType
                                                          *BusArrayPtr,
                                       unsigned int        BusArraySize,
                                       const TourDemoTopologyType
                                                          *TopologyArrayPtr,
                                       unsigned int        TopologyArraySize)
 {
  this->TourPtr              = TourPtr;
  this->StopScheduleArrayPtr = StopScheduleArrayPtr;
  this->StopArrayPtr         = StopArrayPtr;
  this->StopArraySize        = StopArraySize;
  this->BusArrayPtr          = BusArrayPtr;
  this->BusArraySize         = BusArraySize;
  this->TopologyArrayPtr     = TopologyArrayPtr;
  this->TopologyArraySize    = TopologyArraySize;
 }

                   Self::~Self        (void)
 {
 }


std::string        Self::IdStr        (void) const
 {
  return(TourPtr->IdStrPtr);
 }


std::string        Self::NameStr      (void) const
 {
  return(TourPtr->NameStrPtr);
 }

TourTourSchedulePtrClass
                   Self::Schedule     (void) const
 {
  return(TourTourSchedulePtrClass
          (new TourDemoTourScheduleClass
                (&(StopScheduleArrayPtr[TourPtr->StopScheduleIndex]),
                 TourPtr->StopScheduleSize,
                 StopArrayPtr,
                 StopArraySize)));
 }

TourBusPtrClass    Self::Bus          (void) const
 {
  const TourDemoBusType               *BusPtr;

  if (TourDemoGetBusPtrById
       (&BusPtr,
         TourPtr->BusModelStrPtr,
         BusArrayPtr,
         BusArraySize))
   {
    return(TourBusPtrClass(new TourDemoBusClass(BusPtr)));
   }
  else
   {
    return(TourBusPtrClass(NULL));
   }
 }

float              Self::AverageSpeed (void) const
 {
  unsigned int                     StopIndex;
  unsigned int                     StopLimit;
  float                            TotalDistance;
  TourTimeClass                    TotalTime;

  TotalDistance = 0.0;
  TotalTime     = TourTimeClass(0,0);

  StopIndex     = TourPtr->StopScheduleIndex;
  StopLimit     = TourPtr->StopScheduleIndex + TourPtr->StopScheduleSize - 1;

  for (; StopIndex < StopLimit; StopIndex++)
   {
    TourTimeClass                StopInTime;
    TourTimeClass                StopWaitTime;
    TourTimeClass                StopOutTime;
    TourTimeClass                NextStopInTime;
    unsigned int                 LinkIndex;

    StopInTime   = TourTimeClass(StopScheduleArrayPtr[StopIndex].InTime.MinuteCount);
    StopWaitTime = TourTimeClass(StopScheduleArrayPtr[StopIndex].WaitTime.MinuteCount);

    if (StopWaitTime.IsEmpty())
     {
      StopWaitTime.SetZero();
     }

    StopOutTime    = StopInTime + StopWaitTime;
    NextStopInTime = TourTimeClass(StopScheduleArrayPtr[StopIndex + 1].InTime.MinuteCount);

    if ((!StopOutTime.IsEmpty()) && (!NextStopInTime.IsEmpty()))
     {
      if (NextStopInTime < StopOutTime)
       {
        NextStopInTime += TourTimeClass(TourTimeHoursPerDay,0);
       }

      if (TourDemoGetDirectLinkIndex(&LinkIndex,
                                      StopScheduleArrayPtr[StopIndex].StopIdStrPtr,
                                      StopScheduleArrayPtr[StopIndex + 1].StopIdStrPtr,
                                      TopologyArrayPtr,
                                      TopologyArraySize))
       {
        TotalTime     += NextStopInTime - StopOutTime;
        TotalDistance += TopologyArrayPtr[LinkIndex].Distance;
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

float              Self::TotalDistance(void) const
 {
  if (TourPtr->StopScheduleSize > 1)
   {
    unsigned int                       StopIndex;
    float                              Distance;

    Distance = 0.0;
    
    for (StopIndex = TourPtr->StopScheduleIndex;
         StopIndex < TourPtr->StopScheduleIndex + TourPtr->StopScheduleSize - 1;
         StopIndex++)
     {
      unsigned int                     LinkIndex;

      if (TourDemoGetDirectLinkIndex(&LinkIndex,
                                      StopScheduleArrayPtr[StopIndex].StopIdStrPtr,
                                      StopScheduleArrayPtr[StopIndex + 1].StopIdStrPtr,
                                      TopologyArrayPtr,
                                      TopologyArraySize))
       {
        Distance += TopologyArrayPtr[LinkIndex].Distance;
       }
     }

    return(Distance);
   }
  else
   {
    return(0.0);
   }
 }

void               Self::SetName      (const std::string  &NameStr)
 {
  // Not available
 }

void               Self::SetBusModel  (const std::string  &ModelStr)
 {
  // Not available
 }

#undef             Self


#define            Self                TourDemoTourSetClass

                   Self::Self         (const TourStringVectorClass
                                                          &TourIdStrArray,
                                       const TourDemoDataType
                                                          *DataPtr)
 {
  this->TourIdStrArray = TourIdStrArray;
  this->DataPtr        = DataPtr;
 }

                   Self::~Self        (void)
 {
 }

unsigned int       Self::Count        (void) const
 {
  return(TourIdStrArray.size());
 }

TourTourPtrClass   Self::Tour         (unsigned int        Index) const
 {
  const TourDemoTourType              *TourPtr;

  if (TourDemoGetTourPtrById
       (&TourPtr,
         TourIdStrArray[Index].c_str(),
         DataPtr->TourArrayPtr,
         DataPtr->TourArraySize))
   {
    return(TourTourPtrClass
            (new TourDemoTourClass
                  (TourPtr,
                   DataPtr->StopScheduleArrayPtr,
                   DataPtr->StopArrayPtr,
                   DataPtr->StopArraySize,
                   DataPtr->BusArrayPtr,
                   DataPtr->BusArraySize,
                   DataPtr->TopologyArrayPtr,
                   DataPtr->TopologyArraySize)));
   }
  else
   {
    return(TourTourPtrClass(NULL));
   }
 }

#undef             Self


#define            Self                TourDemoStopSetClass

                   Self::Self         (const TourDemoStopType
                                                          *StopArrayPtr,
                                       unsigned int        StopArraySize)
 {
  this->StopArrayPtr  = StopArrayPtr;
  this->StopArraySize = StopArraySize;
 }

                   Self::~Self        (void)
 {
 }

unsigned int       Self::Count        (void) const
 {
  return(StopArraySize);
 }

TourStopPtrClass   Self::Stop         (unsigned int        Index) const
 {
  return(TourStopPtrClass(new TourDemoStopClass(&(StopArrayPtr[Index]))));
 }

#undef             Self


#define            Self                TourDemoTopologyClass

                   Self::Self         (const TourDemoTopologyType
                                                          *TopologyArrayPtr,
                                       unsigned int        TopologyArraySize)
 {
  this->TopologyArrayPtr  = TopologyArrayPtr;
  this->TopologyArraySize = TopologyArraySize;
 }

                   Self::~Self        (void)
 {
 }

bool               Self::DirectLinkExists
                                      (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const
 {
  unsigned int                         Index;

  return(GetDirectLinkIndex(&Index,FromStopIdStr.c_str(),ToStopIdStr.c_str()));
 }

float              Self::DirectLinkDistance
                                      (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const
 {
  unsigned int                         Index;

  if (GetDirectLinkIndex(&Index,FromStopIdStr.c_str(),ToStopIdStr.c_str()))
   {
    return(TopologyArrayPtr[Index].Distance);
   }
  else
   {
    return(0.0);
   }
 }

bool               Self::GetDirectLinkIndex
                                      (unsigned int       *IndexPtr,
                                       const char         *FromStopIdStrPtr,
                                       const char         *ToStopIdStrPtr) const
 {
  return(TourDemoGetDirectLinkIndex
          (IndexPtr,
           FromStopIdStrPtr,
           ToStopIdStrPtr,
           TopologyArrayPtr,
           TopologyArraySize));
 }

#undef             Self


#define            Self                TourDemoDataClass

                   Self::Self         (const TourDemoDataType
                                                          *DataPtr,
                                       const TourStringVectorClass
                                                          &StopIdStrArray)
 {
  unsigned int                         TourIndex;

  this->DataPtr        = DataPtr;
  this->StopIdStrArray = StopIdStrArray;

  if (StopIdStrArray.size() > 0)
   {
    for (TourIndex = 0;
         TourIndex < DataPtr->TourArraySize;
         TourIndex++)
     {
      if (TourIsOnPath(&(DataPtr->TourArrayPtr[TourIndex])))
       {
        TourIdStrArray.push_back(DataPtr->TourArrayPtr[TourIndex].IdStrPtr);
       }
     }
   }
  else
   {
    for (TourIndex = 0;
         TourIndex < DataPtr->TourArraySize;
         TourIndex++)
     {
      TourIdStrArray.push_back(DataPtr->TourArrayPtr[TourIndex].IdStrPtr);
     }
   }
 }

                   Self::~Self        (void)
 {
 }

TourTourSetPtrClass
                   Self::TourSet      (void) const
 {
  return(TourTourSetPtrClass(new TourDemoTourSetClass(TourIdStrArray,DataPtr)));
 }

TourStopSetPtrClass
                   Self::StopSet      (void) const
 {
  return(TourStopSetPtrClass
          (new TourDemoStopSetClass
                (DataPtr->StopArrayPtr,
                 DataPtr->StopArraySize)));
 }

TourTopologyPtrClass
                   Self::Topology     (void) const
 {
  return(TourTopologyPtrClass
          (new TourDemoTopologyClass
                (DataPtr->TopologyArrayPtr,
                 DataPtr->TopologyArraySize)));
 }

TourTourPtrClass   Self::Tour         (const std::string  &TourIdStr) const
 {
  const TourDemoTourType              *TourPtr;

  if (TourDemoGetTourPtrById
       (&TourPtr,
         TourIdStr.c_str(),
         DataPtr->TourArrayPtr,
         DataPtr->TourArraySize))
   {
    return(TourTourPtrClass
            (new TourDemoTourClass
                   (TourPtr,
                    DataPtr->StopScheduleArrayPtr,
                    DataPtr->StopArrayPtr,
                    DataPtr->StopArraySize,
                    DataPtr->BusArrayPtr,
                    DataPtr->BusArraySize,
                    DataPtr->TopologyArrayPtr,
                    DataPtr->TopologyArraySize)));
   }
  else
   {
    return(TourTourPtrClass(NULL));
   }
 }

TourStopPtrClass   Self::Stop         (const std::string  &StopIdStr) const
 {
  const TourDemoStopType              *StopPtr;

  if (TourDemoGetStopPtrById
       (&StopPtr,
         StopIdStr.c_str(),
         DataPtr->StopArrayPtr,
         DataPtr->StopArraySize))
   {
    return(TourStopPtrClass(new TourDemoStopClass(StopPtr)));
   }
  else
   {
    return(TourStopPtrClass(NULL));
   }
 }

TourBusPtrClass    Self::Bus          (const std::string  &ModelStr) const
 {
  const TourDemoBusType               *BusPtr;
  
  if (TourDemoGetBusPtrById
       (&BusPtr,
        ModelStr.c_str(),
        DataPtr->BusArrayPtr,
        DataPtr->BusArraySize))
   {
    return(TourBusPtrClass(new TourDemoBusClass(BusPtr)));
   }
  else
   {
    return(TourBusPtrClass(NULL));
   }
 }

TourTourPtrClass   Self::AppendTour   (const std::string  &TourIdStr)
 {
  // Not available

  return(TourTourPtrClass(NULL));
 }

void               Self::DeleteTour   (const std::string  &TourIdStr)
 {
  // Not available
 }

bool               Self::TourIsOnPath (const TourDemoTourType
                                                          *TourPtr)
 {
  unsigned int                         StopScheduleIndex;
  unsigned int                         StopScheduleLimit;
  unsigned int                         StopCount;

  StopScheduleIndex = TourPtr->StopScheduleIndex;
  StopScheduleLimit = StopScheduleIndex + TourPtr->StopScheduleSize;
  StopCount         = 0;

  while ((StopScheduleIndex < StopScheduleLimit) && (StopCount < 2))
   {
    if (StopIsOnPath
        (DataPtr->StopScheduleArrayPtr[StopScheduleIndex].StopIdStrPtr))
     {
      StopCount++;
     }

    StopScheduleIndex++;
   }

  if (StopCount < 2)
   {
    return(false);
   }
  else
   {
    return(true);
   }
 }

bool               Self::StopIsOnPath (const char         *StopIdStrPtr)
 {
  unsigned int                         StopIndex;
  bool                                 FoundFlag;
  
  StopIndex = 0;
  FoundFlag = false;

  while ((StopIndex < StopIdStrArray.size()) && (!FoundFlag))
   {
    if (!strcmp(StopIdStrArray[StopIndex].c_str(),StopIdStrPtr))
     {
      FoundFlag = true;
     }
    else
     {
      StopIndex++;
     }
   }

  return(FoundFlag);
 }

#undef             Self

