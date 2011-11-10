#ifndef __TourDataDMH__
#define __TourDataDMH__

#include <vector>
#include <string>

#include <TourTime.h>
#include <TourData.h>

typedef struct
 {
  unsigned int     MinuteCount;
 } TourDemoTimeType;

typedef struct
 {
  const char      *ModelStrPtr;
  const char      *DescStrPtr;
  unsigned int     Capacity;
 } TourDemoBusType;

typedef struct
 {
  const char      *IdStrPtr;
  const char      *NameStrPtr;
 } TourDemoStopType;

typedef struct
 {
  const char      *StopIdStrPtr;
  TourDemoTimeType InTime;
  TourDemoTimeType WaitTime;
 } TourDemoStopScheduleType;

typedef struct
 {
  const char       *IdStrPtr;
  const char       *NameStrPtr;
  const char       *BusModelStrPtr;
  unsigned int      StopScheduleIndex;
  unsigned int      StopScheduleSize;
 } TourDemoTourType;

typedef struct
 {
  const char       *FromStopIdStrPtr;
  const char       *ToStopIdStrPtr;
  float             Distance;
 } TourDemoTopologyType;


typedef struct
 {
  const TourDemoBusType               *BusArrayPtr;
  unsigned int                         BusArraySize;

  const TourDemoStopType              *StopArrayPtr;
  unsigned int                         StopArraySize;

  TourDemoStopScheduleType            *StopScheduleArrayPtr;
  unsigned int                         StopScheduleArraySize;

  const TourDemoTourType              *TourArrayPtr;
  unsigned int                         TourArraySize;

  const TourDemoTopologyType          *TopologyArrayPtr;
  unsigned int                         TopologyArraySize;
 } TourDemoDataType;


class TourDemoBusClass : public TourBusClass
 {
  #define          Self                TourDemoBusClass

  public           :

                   Self               (const TourDemoBusType   *BusPtr);
  virtual         ~Self               (void);

  virtual
  std::string      ModelStr           (void) const;

  virtual
  std::string      DescriptionStr     (void) const;

  virtual
  unsigned int     Capacity           (void) const;

  private          :

  const TourDemoBusType               *BusPtr;

  #undef           Self
 };

class TourDemoStopClass : public TourStopClass
 {
  #define          Self                TourDemoStopClass

  public           :

                   Self               (const TourDemoStopType  *StopPtr);
  virtual         ~Self               (void);

  virtual
  std::string      IdStr              (void) const;

  virtual
  std::string      NameStr            (void) const;

  private          :

  const TourDemoStopType              *StopPtr;

  #undef           Self
 };

class TourDemoStopScheduleClass : public TourStopScheduleClass
 {
  #define          Self                TourDemoStopScheduleClass

  public           :

                   Self               (const TourDemoStopScheduleType
                                                               *StopSchedulePtr,
                                       const TourDemoStopType  *StopPtr);

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

  const TourDemoStopScheduleType      *StopSchedulePtr;
  const TourDemoStopType              *StopPtr;
 
  #undef           Self
 };

class TourDemoTourScheduleClass : public TourTourScheduleClass
 {
  #define          Self                TourDemoTourScheduleClass

  public           :

                   Self               (const TourDemoStopScheduleType
                                                          *StopScheduleArrayPtr,
                                       unsigned int        ScheduleStopCount,
                                       const TourDemoStopType
                                                          *StopArrayPtr,
                                       unsigned int        StopArraySize);

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


  const TourDemoStopScheduleType      *StopScheduleArrayPtr;
  unsigned int                         ScheduleStopCount;

  const TourDemoStopType              *StopArrayPtr;
  unsigned int                         StopArraySize;

  #undef           Self
 };

class TourDemoTourClass : public TourTourClass
 {
  #define          Self                TourDemoTourClass

  public           :

                   Self               (const TourDemoTourType  *TourPtr,
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
                                       unsigned int        TopologyArraySize);

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

  const TourDemoTourType              *TourPtr;
  const TourDemoStopScheduleType      *StopScheduleArrayPtr;

  const TourDemoStopType              *StopArrayPtr;
  unsigned int                         StopArraySize;
  const TourDemoBusType               *BusArrayPtr;
  unsigned int                         BusArraySize;
  const TourDemoTopologyType          *TopologyArrayPtr;
  unsigned int                         TopologyArraySize;

  #undef           Self
 };

class TourDemoTourSetClass : public TourTourSetClass
 {
  #define          Self                TourDemoTourSetClass

  public           :

                   Self               (const TourStringVectorClass
                                                          &TourIdStrArray,
                                       const TourDemoDataType
                                                          *DataPtr);

  virtual         ~Self               (void);

  virtual
  unsigned int     Count              (void) const;

  virtual
  TourTourPtrClass Tour               (unsigned int        Index) const;

  private          :

  TourStringVectorClass                TourIdStrArray;
  const TourDemoDataType              *DataPtr;

  #undef           Self
 };

class TourDemoStopSetClass : public TourStopSetClass
 {
  #define          Self                TourDemoStopSetClass

  public           :

                   Self               (const TourDemoStopType
                                                          *StopArrayPtr,
                                       unsigned int        StopArraySize);

  virtual         ~Self               (void);

  virtual
  unsigned int     Count              (void) const;

  virtual
  TourStopPtrClass Stop               (unsigned int        Index) const;

  private          :

  const TourDemoStopType              *StopArrayPtr;
  unsigned int                         StopArraySize;

  #undef           Self
 };

class TourDemoTopologyClass : public TourTopologyClass
 {
  #define          Self                TourDemoTopologyClass

  public           :

                   Self               (const TourDemoTopologyType
                                                          *TopologyArrayPtr,
                                       unsigned int        TopologyArraySize);

  virtual         ~Self               (void);

  virtual bool     DirectLinkExists   (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const;

  virtual float    DirectLinkDistance (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const;

  private          :

  bool             GetDirectLinkIndex (unsigned int       *IndexPtr,
                                       const char         *FromStopIdStrPtr,
                                       const char         *ToStopIdStrPtr) const;

  const TourDemoTopologyType          *TopologyArrayPtr;
  unsigned int                         TopologyArraySize;

  #undef           Self
 };

class TourDemoDataClass : public TourDataClass
 {
  #define          Self                TourDemoDataClass

  public           :
  
                   Self               (const TourDemoDataType
                                                          *DataPtr,
                                       const TourStringVectorClass
                                                          &StopIdStrArray);

  virtual         ~Self               (void);

  virtual
  TourTourSetPtrClass
                   TourSet            (void) const;

  virtual
  TourStopSetPtrClass
                   StopSet            (void) const;

  virtual
  TourTopologyPtrClass
                   Topology           (void) const;

  virtual
  TourTourPtrClass Tour               (const std::string  &TourIdStr) const;

  virtual
  TourStopPtrClass Stop               (const std::string  &StopIdStr) const;

  virtual
  TourBusPtrClass  Bus                (const std::string  &ModelStr) const;

  virtual
  TourTourPtrClass AppendTour         (const std::string  &TourIdStr);

  virtual
  void             DeleteTour         (const std::string  &TourIdStr);

  private          :

  bool             TourIsOnPath       (const TourDemoTourType
                                                          *TourPtr);
  bool             StopIsOnPath       (const char         *StopIdStrPtr);

  const TourDemoDataType              *DataPtr;
  TourStringVectorClass                StopIdStrArray;
  TourStringVectorClass                TourIdStrArray;

  #undef           Self
 };

#endif

