#ifndef __TourDataCAH__
#define __TourDataCAH__

#include <string>
#include <vector>

#include <TourData.h>

typedef struct
 {
  std::string      StopIdStr;
  TourTimeClass    InTime;
  TourTimeClass    WaitTime;
 } TourCAStopScheduleType;

typedef struct
 {
  std::string                          TourIdStr;
  std::vector<TourCAStopScheduleType>  StopScheduleArray;
 } TourCATourScheduleType;

typedef struct
 {
  std::string                          IdStr;
  std::string                          NameStr;
  bool                                 NameLoadedFlag;
  float                                AverageSpeed;
  bool                                 AverageSpeedLoadedFlag;
  float                                TotalDistance;
  bool                                 TotalDistanceLoadedFlag;
 } TourCATourType;

class TourCATourScheduleCacheClass
 {
  #define          Self                TourCATourScheduleCacheClass

  public           :

                   Self               (TourDataPtrClass    SourceDataPtr);

  TourCATourScheduleType
                  *TourSchedulePtr    (const std::string  &TourIdStr);

  private          :

  std::vector<TourCATourScheduleType>  TourScheduleArray;
  TourDataPtrClass                     SourceDataPtr;

  #undef           Self
 };

class TourCATourCacheClass
 {
  #define          Self                TourCATourCacheClass

  public           :

                   Self               (TourDataPtrClass    SourceDataPtr);

  std::string      TourNameStr        (const std::string  &TourIdStr) const;
  float            TourAverageSpeed   (const std::string  &TourIdStr) const;
  float            TourTotalDistance  (const std::string  &TourIdStr) const;

  void             SetTourName        (const std::string  &TourIdStr,
                                       const std::string  &TourNameStr);

  void             ResetAverageSpeed  (const std::string  &TourIdStr);
  void             ResetTotalDistance (const std::string  &TourIdStr);

  void             DeleteTour         (const std::string  &TourIdStr);

  private          :

  bool             GetTourIndexById   (unsigned int       *TourIndexPtr,
                                       const std::string  &TourIdStr) const;

  unsigned int     AppendTour         (const std::string  &TourIdStr);

  TourDataPtrClass                     SourceDataPtr;
  mutable std::vector<TourCATourType>  TourInfoArray;

  #undef           Self
 };

class TourCacheDataClass : public TourDataClass
 {
  #define          Self                TourCacheDataClass

  public           :


                   Self               (TourDataPtrClass    SourceDataPtr);
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

  TourDataPtrClass                          SourceDataPtr;
  TourTourSetPtrClass                       TourSetPtr;
  TourStopSetPtrClass                       StopSetPtr;
  TourTopologyPtrClass                      TopologyPtr;
  TourCATourCacheClass                      TourCache; 
  TourCATourScheduleCacheClass              ScheduleCache;
  mutable std::vector<TourStopPtrClass>     StopCache;

  #undef           Self
 };

#endif

