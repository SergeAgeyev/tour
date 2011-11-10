#ifndef __TourDataSFH__
#define __TourDataSFH__

#include <string>

#include <TourData.h>

class TourSFTourScheduleClass : public TourTourScheduleClass
 {
  #define          Self                TourSFTourScheduleClass

  public           :

                   Self               (TourTourSchedulePtrClass    
                                                           SourceSchedulePtr,
                                       const TourStringVectorClass
                                                          *StopIdStrArrayPtr);

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

  virtual
  bool             IsStopIncome       (unsigned int        StopIndex) const;
  
  virtual
  bool             IsStopOutcome      (unsigned int        StopIndex) const;
  
  virtual
  TourStopSchedulePtrClass
                   IncomeStopSchedule (unsigned int        StopIndex) const;

  virtual
  TourStopSchedulePtrClass
                   OutcomeStopSchedule(unsigned int        StopIndex) const;

  private          :

  bool             FindStopIndexByIdStr
                                      (unsigned int       *StopIndexPtr,
                                       const std::string  &StopIdStr) const;

  TourTourSchedulePtrClass             SourceSchedulePtr;
  const TourStringVectorClass         *StopIdStrArrayPtr;
  std::vector<unsigned int>            StopIndexArray;

  #undef           Self
 };

class TourSFDataClass : public TourDataClass
 {
  #define          Self                TourSFDataClass

  public           :

                   Self               (TourDataPtrClass    SourceDataPtr,
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

  TourDataPtrClass                     SourceDataPtr;
  TourStringVectorClass                StopIdStrArray;

  #undef           Self
 };

#endif

