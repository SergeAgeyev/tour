#include <string>
#include <vector>

#include <TripSmartPtr.h>
#include <TourTime.h>

#include <TourData.h>
#include <TourDataSF.h>

class TourSFTourClass : public TourTourClass
 {
  #define          Self                TourSFTourClass

  public           :

                   Self               (TourTourPtrClass    SourceTourPtr,
                                       const TourStringVectorClass
                                                          *StopIdStrArrayPtr);

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

  TourTourPtrClass                     SourceTourPtr;
  const TourStringVectorClass         *StopIdStrArrayPtr;

  #undef           Self
 };

class TourSFTourSetClass : public TourTourSetClass
 {
  #define          Self                TourSFTourSetClass

  public           :

                   Self               (TourTourSetPtrClass SourceTourSetPtr,
                                       const TourStringVectorClass
                                                          *StopIdStrArrayPtr);

  virtual         ~Self               (void);

  virtual
  unsigned int     Count              (void) const;

  virtual
  TourTourPtrClass Tour               (unsigned int        Index) const;

  private          :

  TourTourSetPtrClass                  SourceTourSetPtr;
  const TourStringVectorClass         *StopIdStrArrayPtr;

  #undef           Self
 };

class TourSFStopSetClass : public TourStopSetClass
 {
  #define          Self                TourSFStopSetClass

  public           :

                   Self               (TourDataPtrClass    SourceDataPtr,
                                       const TourStringVectorClass
                                                          *StopIdStrArrayPtr);

  virtual         ~Self               (void);

  virtual
  unsigned int     Count              (void) const;

  virtual
  TourStopPtrClass Stop               (unsigned int        Index) const;

  private          :

  TourDataPtrClass                     SourceDataPtr;
  const TourStringVectorClass         *StopIdStrArrayPtr;

  #undef           Self
 };

class TourSFTopologyClass : public TourTopologyClass
 {
  #define          Self                TourSFTopologyClass

  public           :

                   Self               (TourDataPtrClass    SourceDataPtr,
                                       const TourStringVectorClass
                                                          *StopIdStrArrayPtr);

  virtual         ~Self               (void);

  virtual bool     DirectLinkExists   (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const;

  virtual float    DirectLinkDistance (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const;

  private          :

  TourDataPtrClass                     SourceDataPtr;
  const TourStringVectorClass         *StopIdStrArrayPtr;

  #undef           Self
 };


#define            Self                TourSFTourScheduleClass

                   Self::Self         (TourTourSchedulePtrClass
                                                           SourceSchedulePtr,
                                       const TourStringVectorClass
                                                          *StopIdStrArrayPtr)
 {
  unsigned int                         SourceStopIndex;
  unsigned int                         SourceStopCount;
  unsigned int                         FilteredIndex;

  this->SourceSchedulePtr = SourceSchedulePtr;
  this->StopIdStrArrayPtr = StopIdStrArrayPtr;

  SourceStopCount = SourceSchedulePtr->StopCount();

  for (SourceStopIndex = 0;
       SourceStopIndex < SourceStopCount;
       SourceStopIndex++)
   {
    std::string                        StopIdStr;
    unsigned int                       TargetStopIndex;
    bool                               FoundFlag;

    StopIdStr = SourceSchedulePtr->StopSchedule(SourceStopIndex)->Stop()->IdStr();

    if (FindStopIndexByIdStr(&TargetStopIndex,StopIdStr))
     {
      StopIndexArray.push_back(SourceStopIndex);
     }
   }
 }

                   Self::~Self        (void)
 {
 }

unsigned int       Self::StopCount    (void) const
 {
  return(StopIndexArray.size());
 }

TourStopSchedulePtrClass
                   Self::StopSchedule (unsigned int        StopIndex) const
 {
  return(SourceSchedulePtr->StopSchedule(StopIndexArray[StopIndex]));
 }

TourStopSchedulePtrClass
                   Self::AppendStopSchedule 
                                      (const std::string  &StopIdStr)
 {
  TourStopSchedulePtrClass             Result;
  unsigned int                         StopIndex;
  unsigned int                         DummyStopIndex;

  StopIndex = SourceSchedulePtr->StopCount();

  Result = SourceSchedulePtr->AppendStopSchedule(StopIdStr);

  if (FindStopIndexByIdStr(&DummyStopIndex,StopIdStr))
   {
    StopIndexArray.push_back(StopIndex);
   }

  return(Result); 
 }

//FIXME: Incorrect implementation - insert works as append

TourStopSchedulePtrClass
                   Self::InsertStopSchedule 
                                      (unsigned int        StopIndex,
                                       const std::string  &StopIdStr)
 {
  return(AppendStopSchedule(StopIdStr));
 }

void               Self::DeleteStopSchedule 
                                      (unsigned int        StopIndex)
 {
  if (StopIndex < StopCount())
   {
    SourceSchedulePtr->DeleteStopSchedule(StopIndexArray[StopIndex]);
   }
 }

bool               Self::FindStopIndexByIdStr
                                      (unsigned int       *StopIndexPtr,
                                       const std::string  &StopIdStr) const
 {
  unsigned int                         StopIndex;
  unsigned int                         StopCount;
  bool                                 FoundFlag;
  
  FoundFlag = false;
  StopIndex = 0;
  StopCount = StopIdStrArrayPtr->size();

  while ((StopIndex < StopCount) && (!FoundFlag))
   {
    if ((*StopIdStrArrayPtr)[StopIndex] == StopIdStr)
     {
      FoundFlag     = true;
      *StopIndexPtr = StopIndex;
     }
    else
     {
      StopIndex++;
     } 
   }

  return(FoundFlag);
 }

bool               Self::IsStopIncome (unsigned int        StopIndex) const
 {
  if (StopIndex < StopIndexArray.size())
   {
    if (StopIndex > 0)
     {
      if (StopIndexArray[StopIndex] == (StopIndexArray[StopIndex - 1] + 1))
       {
        return(false);
       }
      else
       {
        return(true);
       }
     }
    else
     {
      if (StopIndexArray[StopIndex] > 0)
       {
        return(true);
       }
      else
       {
        return(false);
       }
     }
   }
  else
   {
    return(false);
   }
 }
  
bool               Self::IsStopOutcome(unsigned int        StopIndex) const
 {
  unsigned int                         StopCount;

  StopCount = StopIndexArray.size();

  if (StopIndex < StopCount)
   {
    if ((StopIndex + 1) < StopCount)
     {
      if ((StopIndexArray[StopIndex] + 1) == StopIndexArray[StopIndex + 1])
       {
        return(false);
       }
      else
       {
        return(true);
       }
     }
    else
     {
      if ((StopIndexArray[StopIndex] + 1) == SourceSchedulePtr->StopCount())
       {
        return(false);
       }
      else
       {
        return(true);
       }
     }
   }
  else
   {
    return(false);
   }
 }
  
TourStopSchedulePtrClass
                   Self::IncomeStopSchedule
                                      (unsigned int        StopIndex) const
 {
  unsigned int                         SourceStopIndex;

  if (StopIndex < StopIndexArray.size())
   {
    SourceStopIndex = StopIndexArray[StopIndex];

    if ((SourceStopIndex > 0) && 
        (SourceStopIndex < SourceSchedulePtr->StopCount()))
     {
      return(SourceSchedulePtr->StopSchedule(SourceStopIndex - 1));
     }
    else
     {
      return(TourStopSchedulePtrClass(NULL));
     }
   }
  else
   {
    return(TourStopSchedulePtrClass(NULL));
   }
 }

TourStopSchedulePtrClass
                   Self::OutcomeStopSchedule
                                      (unsigned int        StopIndex) const
 {
  unsigned int                         SourceStopIndex;

  if (StopIndex < StopIndexArray.size())
   {
    SourceStopIndex = StopIndexArray[StopIndex];

    if ((SourceStopIndex + 1) < SourceSchedulePtr->StopCount())
     {
      return(SourceSchedulePtr->StopSchedule(SourceStopIndex + 1));
     }
    else
     {
      return(TourStopSchedulePtrClass(NULL));
     }
   }
  else
   {
    return(TourStopSchedulePtrClass(NULL));
   }
 }

#undef             Self


#define            Self                TourSFTourClass

                   Self::Self         (TourTourPtrClass    SourceTourPtr,
                                       const TourStringVectorClass
                                                          *StopIdStrArrayPtr)
 {
  this->SourceTourPtr     = SourceTourPtr;
  this->StopIdStrArrayPtr = StopIdStrArrayPtr;
 }

                   Self::~Self        (void)
 {
 }

std::string        Self::IdStr        (void) const
 {
  return(SourceTourPtr->IdStr());
 }

std::string        Self::NameStr      (void) const
 {
  return(SourceTourPtr->NameStr());
 }

TourTourSchedulePtrClass
                   Self::Schedule     (void) const
 {
  return(TourTourSchedulePtrClass
          (new TourSFTourScheduleClass(SourceTourPtr->Schedule(),
                                       StopIdStrArrayPtr)));
 }

TourBusPtrClass    Self::Bus          (void) const
 {
  return(SourceTourPtr->Bus());
 }

void               Self::SetName      (const std::string  &NameStr)
 {
  SourceTourPtr->SetName(NameStr);
 }

void               Self::SetBusModel  (const std::string  &ModelStr)
 {
  SourceTourPtr->SetBusModel(ModelStr);
 }

// FIXME: Not implemented yet

float              Self::AverageSpeed (void) const
 {
  return(0.0);
 }

// FIXME: Not implemented yet

float              Self::TotalDistance(void) const
 {
  return(0.0);
 }

#undef             Self


#define            Self                TourSFTourSetClass

                   Self::Self         (TourTourSetPtrClass SourceTourSetPtr,
                                       const TourStringVectorClass
                                                          *StopIdStrArrayPtr)
 {
  this->SourceTourSetPtr  = SourceTourSetPtr;
  this->StopIdStrArrayPtr = StopIdStrArrayPtr;
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
  return(TourTourPtrClass(new TourSFTourClass(SourceTourSetPtr->Tour(Index),
                                              StopIdStrArrayPtr)));
 }

#undef             Self


#define            Self                TourSFStopSetClass

                   Self::Self         (TourDataPtrClass    SourceDataPtr,
                                       const TourStringVectorClass
                                                          *StopIdStrArrayPtr)
 {
  this->SourceDataPtr     = SourceDataPtr;
  this->StopIdStrArrayPtr = StopIdStrArrayPtr;
 }

                   Self::~Self        (void)
 {
 }

unsigned int       Self::Count        (void) const
 {
  return(StopIdStrArrayPtr->size());
 }

TourStopPtrClass   Self::Stop         (unsigned int        Index) const
 {
  return(SourceDataPtr->Stop((*StopIdStrArrayPtr)[Index]));
 }

#undef             Self


#define            Self                TourSFTopologyClass

                   Self::Self         (TourDataPtrClass    SourceDataPtr,
                                       const TourStringVectorClass
                                                          *StopIdStrArrayPtr)
 {
  this->SourceDataPtr     = SourceDataPtr;
  this->StopIdStrArrayPtr = StopIdStrArrayPtr;
 }

                   Self::~Self        (void)
 {
 }

bool               Self::DirectLinkExists
                                      (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const
 {
  return(SourceDataPtr->Topology()->DirectLinkExists(FromStopIdStr,ToStopIdStr));
 }

float              Self::DirectLinkDistance 
                                      (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const
 {
  return(SourceDataPtr->Topology()->DirectLinkDistance(FromStopIdStr,ToStopIdStr));
 }

#undef             Self


#define            Self                TourSFDataClass

                   Self::Self         (TourDataPtrClass    SourceDataPtr,
                                       const TourStringVectorClass
                                                          &StopIdStrArray)
 {
  this->SourceDataPtr  = SourceDataPtr;
  this->StopIdStrArray = StopIdStrArray;
 }

                   Self::~Self        (void)
 {
 }

TourTourSetPtrClass
                   Self::TourSet      (void) const
 {
  return(TourTourSetPtrClass
          (new TourSFTourSetClass( SourceDataPtr->TourSet(),
                                  &StopIdStrArray)));
 }

TourStopSetPtrClass
                   Self::StopSet      (void) const
 {
  return(TourStopSetPtrClass
          (new TourSFStopSetClass(SourceDataPtr,&StopIdStrArray)));
 }

TourTopologyPtrClass
                   Self::Topology     (void) const
 {
  return(TourTopologyPtrClass(new TourSFTopologyClass(SourceDataPtr,&StopIdStrArray)));
 }

TourTourPtrClass   Self::Tour         (const std::string  &TourIdStr) const
 {
  return(TourTourPtrClass
          (new TourSFTourClass(SourceDataPtr->Tour(TourIdStr),
                               &StopIdStrArray)));
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
  return(SourceDataPtr->AppendTour(TourIdStr));
 }

void               Self::DeleteTour   (const std::string  &TourIdStr)
 {
  SourceDataPtr->DeleteTour(TourIdStr);
 }

#undef             Self

