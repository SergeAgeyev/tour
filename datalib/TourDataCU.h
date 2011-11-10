#ifndef __TourDataCUH__
#define __TourDataCUH__

#include <string>
#include <vector>

#include <TourData.h>

typedef struct
 {
  std::string      StopIdStr;
  TourTimeClass    InTime;
  TourTimeClass    WaitTime;
 } TourDataCUStopScheduleType;

typedef std::vector<TourDataCUStopScheduleType>  TourDataCUTourSheduleType;

typedef struct
 {
  std::string                          TourIdStr;
  std::string                          TourNameStr;
  std::string                          BusModelStr;
  TourDataCUTourSheduleType            Schedule;
  bool                                 AppendedFlag;
  bool                                 NameChangedFlag;
  bool                                 BusModelChangedFlag;
  bool                                 ScheduleChangedFlag;
 } TourDataCUTourType;

class TourDataCUDeletedTourStorageClass
 {
  public           :

  bool             IsTourDeleted      (const std::string  &TourIdStr) const;
  void             DeleteTour         (const std::string  &TourIdStr);
  void             UnDeleteTour       (const std::string  &TourIdStr);
  void             Clear              (void);

  unsigned int     TourCount          (void) const;
  std::string      TourIdStr          (unsigned int        TourIndex);

  private          :

  bool             TourIndexById      (unsigned int       *TourIndexPtr,
                                       const std::string  &TourIdStr) const
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
   };

  TourStringVectorClass                DeletedTourArray;
 };

class TourDataCUModifiedTourStorageClass
 {
  public           :

  bool             IsTourModified     (const std::string  &TourIdStr) const;
  bool             IsTourAppended     (const std::string  &TourIdStr) const;

  unsigned int     TourCount          (void) const;

  void             AppendTour         (const std::string  &TourIdStr);
  void             ModifyTour         (const std::string  &TourIdStr);
  void             DeleteTour         (const std::string  &TourIdStr);
  void             Clear              (void);

  void             ModifyTourSchedule (const std::string  &TourIdStr,
                                       TourDataPtrClass    SourceDataPtr);

  TourDataCUTourType
                  *TourInfoPtr        (const std::string  &TourIdStr) const;

  TourDataCUTourType
                  *TourInfoPtr        (unsigned int        TourIndex) const;

  private          :

  bool             GetTourIndexById   (unsigned int       *TourIndexPtr,
                                       const std::string  &TourIdStr) const;

  std::vector<TourDataCUTourType>      ModifiedTourArray;
 };

class TourCachedUpdateTourSetClass : public TourTourSetClass
 {
  #define          Self                TourCachedUpdateTourSetClass

  public           :

                   Self               (TourDataPtrClass   SourceDataPtr,
                                       TourDataCUModifiedTourStorageClass
                                                         *ModifiedTourStoragePtr);
  virtual         ~Self               (void);

  virtual
  unsigned int     Count              (void) const;

  virtual
  TourTourPtrClass Tour               (unsigned int        Index) const;

  void             TourDeleted        (const std::string  &TourIdStr);
  void             TourAppended       (const std::string  &TourIdStr);
  void             CancelChanges      (void);

  private          :

  void             LoadSourceTourSet  (void);

  bool             GetTourIndexById   (unsigned int       *TourIndexPtr,
                                       const std::string  &TourIdStr);

  TourDataPtrClass                     SourceDataPtr;
  bool                                 ModifiedFlag;
  TourStringVectorClass                TourIdStrArray;
  TourDataCUModifiedTourStorageClass  *ModifiedTourStoragePtr;

  #undef           Self
 };

enum
 {
  TourCachedUpdateChangeTypeCodeTourDeleted,
  TourCachedUpdateChangeTypeCodeTourModified,
  TourCachedUpdateChangeTypeCodeTourAppended
 };

class TourCachedUpdateDataClass : public TourDataClass
 {
  #define          Self                TourCachedUpdateDataClass

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

  void             Apply              (void);
  void             Cancel             (void);

  void             ApplyTourChanges   (const std::string  &TourIdStr);

  unsigned int     ChangesCount       (void);
  void             GetChangeInfo      (unsigned int       *ChangeTypeCodePtr,
                                       std::string        &ChangedTourIdStr,
                                       unsigned int        ChangeIndex);

  private          :

  void             ApplyTourModifyLow (TourDataCUTourType *TourDataPtr);

  TourDataPtrClass                     SourceDataPtr;
  TourTourSetPtrClass                  TourSetPtr;
  TourCachedUpdateTourSetClass        *TourSetLowPtr;

  TourDataCUDeletedTourStorageClass    DeletedTourStorage;
  TourDataCUModifiedTourStorageClass   ModifiedTourStorage;
  
  #undef           Self
 };

#endif

