#ifndef __TourDataH__
#define __TourDataH__

#include <string>
#include <vector>

#include <TripSmartPtr.h>
#include <TourTime.h>

typedef std::vector<std::string>       TourStringVectorClass;

class TourBusClass
 {
  #define          Self                TourBusClass

  public           :

  virtual         ~Self               (void);

  virtual
  std::string      ModelStr           (void) const = 0;

  virtual
  std::string      DescriptionStr     (void) const = 0;

  virtual
  unsigned int     Capacity           (void) const = 0;

  #undef           Self
 };

typedef TripSmartPtrTemplate<TourBusClass> TourBusPtrClass;

class TourStopClass
 {
  #define          Self                TourStopClass

  public           :

  virtual         ~Self               (void);

  virtual
  std::string      IdStr              (void) const = 0;

  virtual
  std::string      NameStr            (void) const = 0;

  #undef           Self
 };

typedef TripSmartPtrTemplate<TourStopClass> TourStopPtrClass;

class TourStopScheduleClass
 {
  #define          Self                TourStopScheduleClass

  public           :

  virtual         ~Self               (void);

  virtual
  TourStopPtrClass Stop               (void) const = 0;

  virtual
  TourTimeClass    InTime             (void) const = 0;
  virtual
  TourTimeClass    WaitTime           (void) const = 0;

  virtual void     SetInTime          (const TourTimeClass&Time) = 0;
  virtual void     SetWaitTime        (const TourTimeClass&Time) = 0;

  #undef           Self
 };

typedef TripSmartPtrTemplate<TourStopScheduleClass> TourStopSchedulePtrClass;

class TourTourScheduleClass
 {
  #define          Self                TourTourScheduleClass

  public           :

  virtual         ~Self               (void);

  virtual
  unsigned int     StopCount          (void) const = 0;

  virtual
  TourStopSchedulePtrClass
                   StopSchedule       (unsigned int        StopIndex) const = 0;

  virtual
  TourStopSchedulePtrClass
                   AppendStopSchedule (const std::string  &StopIdStr) = 0;

  virtual
  TourStopSchedulePtrClass
                   InsertStopSchedule (unsigned int        StopIndex,
                                       const std::string  &StopIdStr) = 0;

  virtual
  void             DeleteStopSchedule (unsigned int        StopIndex) = 0;

  #undef           Self
 };

typedef TripSmartPtrTemplate<TourTourScheduleClass> TourTourSchedulePtrClass;

class TourTourClass
 {
  #define          Self                TourTourClass

  public           :

  virtual         ~Self               (void);

  virtual
  std::string      IdStr              (void) const = 0;

  virtual
  std::string      NameStr            (void) const = 0;

  virtual
  TourTourSchedulePtrClass
                   Schedule           (void) const = 0;

  virtual
  TourBusPtrClass  Bus                (void) const = 0;

  virtual
  float            AverageSpeed       (void) const = 0;

  virtual
  float            TotalDistance      (void) const = 0;

  virtual
  TourTimeClass    TotalTime          (void) const;

  virtual
  void             SetName            (const std::string  &NameStr) = 0;

  virtual
  void             SetBusModel        (const std::string  &ModelStr) = 0;

  #undef           Self
 };

typedef TripSmartPtrTemplate<TourTourClass> TourTourPtrClass;

class TourTourSetClass
 {
  #define          Self                TourTourSetClass

  public           :

  virtual         ~Self               (void);

  virtual
  unsigned int     Count              (void) const = 0;

  virtual
  TourTourPtrClass Tour               (unsigned int        Index) const = 0;

  #undef           Self
 };

typedef TripSmartPtrTemplate<TourTourSetClass> TourTourSetPtrClass;

class TourStopSetClass
 {
  #define          Self                TourStopSetClass

  public           :

  virtual         ~Self               (void);

  virtual
  unsigned int     Count              (void) const = 0;

  virtual
  TourStopPtrClass Stop               (unsigned int        Index) const = 0;

  #undef           Self
 };

typedef TripSmartPtrTemplate<TourStopSetClass> TourStopSetPtrClass;

class TourTopologyClass
 {
  #define          Self                TourTopologyClass

  public           :

  virtual         ~Self               (void);

  virtual bool     DirectLinkExists   (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const = 0;

  virtual float    DirectLinkDistance (const std::string  &FromStopIdStr,
                                       const std::string  &ToStopIdStr) const = 0;

  #undef           Self
 };

typedef TripSmartPtrTemplate<TourTopologyClass> TourTopologyPtrClass;

class TourDataClass
 {
  #define          Self                TourDataClass

  public           :

  virtual         ~Self               (void);

  virtual
  TourTourSetPtrClass
                   TourSet            (void) const = 0;

  virtual
  TourStopSetPtrClass
                   StopSet            (void) const = 0;

  virtual
  TourTopologyPtrClass
                   Topology           (void) const = 0;

  virtual
  TourTourPtrClass Tour               (const std::string  &TourIdStr) const = 0;

  virtual
  TourStopPtrClass Stop               (const std::string  &StopIdStr) const = 0;

  virtual
  TourBusPtrClass  Bus                (const std::string  &ModelStr) const = 0;

  virtual
  TourTourPtrClass AppendTour         (const std::string  &TourIdStr) = 0;

  virtual
  void             DeleteTour         (const std::string  &TourIdStr) = 0;

  #undef           Self
 };

typedef TripSmartPtrTemplate<TourDataClass> TourDataPtrClass;

#endif

