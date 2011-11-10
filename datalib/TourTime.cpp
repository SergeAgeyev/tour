#include <TourTime.H>

#include <stdio.h>
#include <string>

#define TourTimeValueUndefined        (0x7FFFFFFFL)

#define            Self                TourTimeClass

                   Self::Self         (void)
 {
  SetEmpty();
 }

                   Self::Self         (const Self         &Time)
 {
  MinuteCount = Time.MinuteCount;
 }

                   Self::Self         (int                 Hours,
                                       int                 Minutes)
 {
  MinuteCount = Hours * TourTimeMinutesPerHour + Minutes;
 }

                   Self::Self         (int                 Minutes)
 {
  MinuteCount = Minutes;
 }

Self              &Self::operator =   (const Self         &Time)
 {
  MinuteCount = Time.MinuteCount;

  return(*this);
 }


Self              &Self::operator+=   (const Self        &Time)
 {
  if ((!IsEmpty()) && (!Time.IsEmpty()))
   {
    MinuteCount += Time.MinuteCount;
   } 

  return(*this);
 }

Self              &Self::operator-=   (const Self        &Time)
 {
  if ((!IsEmpty()) && (!Time.IsEmpty()))
   {
    MinuteCount -= Time.MinuteCount;
   } 

  return(*this);
 }

                   Self::operator int (void) const
 {
  return(MinuteCount);
 }                   

bool               Self::IsEmpty      (void) const
 {
  if (MinuteCount == TourTimeValueUndefined)
   {
    return(true);
   }
  else
   {
    return(false);
   }
 }

bool               Self::IsZero       (void) const
 {
  if (!IsEmpty())
   {
    if (MinuteCount == 0)
     {
      return(true);
     }
    else
     {
      return(false);
     }
   }
  else
   {
    return(false);
   }
 }

int                Self::Hours        (void) const
 {
  return(MinuteCount / TourTimeMinutesPerHour);
 }

int                Self::Minutes      (void) const
 {
  return(MinuteCount % TourTimeMinutesPerHour);
 }

void               Self::SetEmpty     (void)
 {
  MinuteCount = TourTimeValueUndefined;
 }

void               Self::SetZero      (void)
 {
  MinuteCount = 0;
 }

void               Self::Set          (int                 Hours,
                                       int                 Minutes)
 {
  MinuteCount = Hours * TourTimeMinutesPerHour + Minutes;
 }

std::string        Self::AsStr        (void) const
 {
  if (!IsEmpty())
   {
    char           BufferStr[5 + 1];

    sprintf(BufferStr,"%02d:%02d",Hours(),Minutes());
/*
    std::ostringstream                 Result;

    Result << std::setw(2) << std::setfill('0') << Hours() << ':' << std::setw(2) << Minutes();

    return(Result.str());
*/

    return(std::string(BufferStr));
   }
  else
   {
    return(std::string(""));
   }
 }

extern Self        operator+          (const Self         &FirstTime,
                                       const Self         &SecondTime)
 {
  if ((!FirstTime.IsEmpty()) && (!SecondTime.IsEmpty()))
   {
    return(Self(FirstTime.MinuteCount + SecondTime.MinuteCount));
   }
  else
   {
    return(Self());
   }
 }

extern Self        operator-          (const Self         &FirstTime,
                                       const Self         &SecondTime)
 {
  if ((!FirstTime.IsEmpty()) && (!SecondTime.IsEmpty()))
   {
    return(Self(FirstTime.MinuteCount - SecondTime.MinuteCount));
   }
  else
   {
    return(Self());
   }
 }

extern bool        operator==         (const Self         &FirstTime,
                                       const Self         &SecondTime)
 {
  return(FirstTime.MinuteCount == SecondTime.MinuteCount);
 }

extern bool        operator!=         (const Self         &FirstTime,
                                       const Self         &SecondTime)
 {
  return(FirstTime.MinuteCount != SecondTime.MinuteCount);
 }

extern bool        operator<          (const Self         &FirstTime,
                                       const Self         &SecondTime)
 {
  if      (SecondTime.IsEmpty())
   {
    return(false);
   }
  else if (FirstTime.IsEmpty())
   {
    return(true);
   }
  else
   { 
    return(FirstTime.MinuteCount < SecondTime.MinuteCount);
   } 
 }

extern bool        operator>          (const Self         &FirstTime,
                                       const Self         &SecondTime)
 {
  if      (FirstTime.IsEmpty())
   {
    return(false);
   }
  else if (SecondTime.IsEmpty())
   {
    return(true);
   }
  else
   {
    return(FirstTime.MinuteCount > SecondTime.MinuteCount);
   }
 }

extern bool        operator>=         (const Self         &FirstTime,
                                       const Self         &SecondTime)
 {
  return((FirstTime == SecondTime) || (FirstTime > SecondTime));
 }

extern bool        operator<=         (const Self         &FirstTime,
                                       const Self         &SecondTime)
 {
  return((FirstTime == SecondTime) || (FirstTime < SecondTime));
 }

#undef             Self

