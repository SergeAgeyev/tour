#ifndef __TourDataDBH__
#define __TourDataDBH__

#include <string>
#include <vector>

#include <TripSmartPtr.h>
#include <TourTime.h>

#include <TourData.h>

class TourDBDataClass : public TourDataClass
 {
  #define          Self                TourDBDataClass

  public           :


                   Self               (const char         *TourSetQueryStrPtr = NULL);
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

  std::string                          TourSetQueryStr;

  #undef           Self
 };

#endif

