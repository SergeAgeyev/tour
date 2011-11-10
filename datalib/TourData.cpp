#include <TourData.h>

#define            Self                TourBusClass

                   Self::~Self        (void)
 {
 }

#undef             Self


#define            Self                TourStopClass

                   Self::~Self        (void)
 {
 }

#undef             Self

#define            Self                TourStopScheduleClass

                   Self::~Self        (void)
 {
 }

#undef             Self

#define            Self                TourTourScheduleClass

                   Self::~Self        (void)
 {
 }

#undef             Self

#define            Self                TourTourClass

                   Self::~Self        (void)
 {
 }

TourTimeClass      Self::TotalTime    (void) const
 {
  TourTimeClass                        Result;
  TourTimeClass                        WaitTime;
  TourTimeClass                        OutTime;
  TourTimeClass                        InTime;
  TourTourSchedulePtrClass             TourSchedulePtr;
  unsigned int                         StopCount;
  TourStopSchedulePtrClass             FirstStopSchedulePtr;
  TourStopSchedulePtrClass             LastStopSchedulePtr;

  Result.SetZero();

  TourSchedulePtr = Schedule();
  StopCount       = TourSchedulePtr->StopCount();

  if (StopCount > 1)
   {
    FirstStopSchedulePtr = TourSchedulePtr->StopSchedule(0);
    LastStopSchedulePtr  = TourSchedulePtr->StopSchedule(StopCount - 1);

    WaitTime = FirstStopSchedulePtr->WaitTime();

    if (WaitTime.IsEmpty())
     {
      WaitTime.SetZero();
     }

    OutTime = FirstStopSchedulePtr->InTime() + WaitTime;

    if (!OutTime.IsEmpty())
     {
      InTime = LastStopSchedulePtr->InTime();

      if (!InTime.IsEmpty())
       {
        if (InTime < OutTime)
         {
          InTime += TourTimeClass(TourTimeHoursPerDay,0);
         }

        Result = InTime - OutTime;
       }
     }
   }

  return(Result);
 }

#undef             Self

#define            Self                TourTourSetClass

                   Self::~Self        (void)
 {
 }

#undef             Self

#define            Self                TourStopSetClass

                   Self::~Self        (void)
 {
 }

#undef             Self

#define            Self                TourTopologyClass

                   Self::~Self        (void)
 {
 }

#undef             Self

#define            Self                TourDataClass

                   Self::~Self        (void)
 {
 }

#undef             Self

