#ifndef __TourTimeH__
#define __TourTimeH__

#include <string>

#define TourTimeHoursPerDay           (24)
#define TourTimeMinutesPerHour        (60)

class TourTimeClass
 {
  #define          Self                TourTimeClass

  public           :

                   Self               (void);
                   Self               (const Self         &Time);

                   Self               (int                 Hours,
                                       int                 Minutes);

                   Self               (int                 Minutes);

  Self            &operator=          (const Self         &Time);

  Self            &operator+=         (const Self         &Time);
  Self            &operator-=         (const Self         &Time);

                   operator int       (void) const;     

  friend Self      operator+          (const Self         &FirstTime,
                                       const Self         &SecondTime);

  friend Self      operator-          (const Self         &FirstTime,
                                       const Self         &SecondTime);

  friend bool      operator==         (const Self         &FirstTime,
                                       const Self         &SecondTime);

  friend bool      operator!=         (const Self         &FirstTime,
                                       const Self         &SecondTime);

  friend bool      operator<          (const Self         &FirstTime,
                                       const Self         &SecondTime);

  friend bool      operator>          (const Self         &FirstTime,
                                       const Self         &SecondTime);

  friend bool      operator>=         (const Self         &FirstTime,
                                       const Self         &SecondTime);

  friend bool      operator<=         (const Self         &FirstTime,
                                       const Self         &SecondTime);

  bool             IsEmpty            (void) const;
  bool             IsZero             (void) const;

  int              Hours              (void) const;
  int              Minutes            (void) const;

  void             SetEmpty           (void);
  void             SetZero            (void);

  void             Set                (int                 Hours,
                                       int                 Minutes);

  std::string      AsStr              (void) const;

  private          :

  int                                  MinuteCount;

  #undef           Self
 };

#define            Self                TourTimeClass

extern Self        operator+          (const Self         &FirstTime,
                                       const Self         &SecondTime);

extern Self        operator-          (const Self         &FirstTime,
                                       const Self         &SecondTime);

extern bool        operator==         (const Self         &FirstTime,
                                       const Self         &SecondTime);

extern bool        operator!=         (const Self         &FirstTime,
                                       const Self         &SecondTime);

extern bool        operator<          (const Self         &FirstTime,
                                       const Self         &SecondTime);

extern bool        operator>          (const Self         &FirstTime,
                                       const Self         &SecondTime);

extern bool        operator>=         (const Self         &FirstTime,
                                       const Self         &SecondTime);

extern bool        operator<=         (const Self         &FirstTime,
                                       const Self         &SecondTime);

#undef             Self

#endif

