#ifndef TripDiagramDataH
#define TripDiagramDataH

/* ƒ¿ÕÕ€… ÃŒƒ”À‹ ﬂ¬Àﬂ≈“—ﬂ ”—“¿–≈¬ÿ»Ã » ¡”ƒ≈“ ”ƒ¿À≈Õ ¬ —À≈ƒ”ﬁŸ»’ ¬≈–—»ﬂ’ */

#error Obsolete module used

#include <vector>
#include <string>

#include <TripSmartPtr.h>

// Base abstract classes definition

class TripDiagramStopClass
 {
  public :

  virtual const char        *IdStrPtr      (void) const = 0;
  virtual const char        *NameStrPtr    (void) const = 0;
 };

typedef 
 TripSmartPtrTemplate<TripDiagramStopClass> 
  TripDiagramStopPtrClass;

class TripDiagramStopScheduleClass : public TripDiagramStopClass
 {
  public :

  virtual unsigned int       InTime        (void) const = 0;
  virtual unsigned int       WaitTime      (void) const = 0;
 };

typedef 
 TripSmartPtrTemplate<TripDiagramStopScheduleClass> 
  TripDiagramStopSchedulePtrClass;

class TripDiagramTourScheduleClass
 {
  public :

  virtual unsigned int       StopCount     (void) const = 0;
  virtual TripDiagramStopSchedulePtrClass
                             Stop          (unsigned int Index) const = 0;
 };

typedef 
 TripSmartPtrTemplate<TripDiagramTourScheduleClass> 
  TripDiagramTourSchedulePtrClass;

class TripDiagramTourClass
 {
  public :

  virtual const char                 *IdStrPtr  (void) const = 0;
  virtual const char                 *NameStrPtr(void) const = 0;
  virtual const char                 *BusModelStrPtr 
                                                (void) const = 0;

  virtual 
  TripDiagramTourSchedulePtrClass     Schedule  (void) const = 0;
 };

typedef TripSmartPtrTemplate<TripDiagramTourClass> TripDiagramTourPtrClass;

class TripDiagramStopArrayClass
 {
  public :

  virtual unsigned int                Count     (void) const = 0;
  virtual TripDiagramStopPtrClass     operator[](unsigned int Index) const = 0;
 };

class TripDiagramTourArrayClass
 {
  public :

  virtual unsigned int                Count     (void) const = 0;
  virtual TripDiagramTourPtrClass     operator[](unsigned int Index) const = 0;
 };

// Data storage definitions

using namespace std;

typedef struct
 {
  string           IdStr;
  string           NameStr;
 } TripDiagramStopInfoType;

typedef struct
 {
  float            Distance;
 } TripDiagramPathInfoType;

class TripDiagramRouteDataClass
 {
  friend class          TTourTripDiagramForm;

  public :

  virtual unsigned int  StopCount     (void) const;
  virtual const char   *StopIdStrPtr  (unsigned int StopIndex) const;
  virtual const char   *StopNameStrPtr(unsigned int StopIndex) const;
  virtual float         StopDistance  (unsigned int FromStopIndex,
                                       unsigned int ToStopIndex) const;

  vector<TripDiagramStopInfoType>      StopInfoArray;
  vector<TripDiagramPathInfoType>      PathInfoArray;
 };

typedef struct
 {
  unsigned int                         StopIndex;
  unsigned int                         InTime;
  unsigned int                         WaitTime;
 } TripDiagramTourStopType;

typedef struct
 {
  string                               TripIdStr;
  string                               TripNameStr;
  vector<TripDiagramTourStopType>      StopInfoArray;
 } TripDiagramTourInfoType;

typedef struct
 {
  bool                                 VisibleFlag;
  VCanvasColorType                     Color;
  VCanvasPenType                       PenStyle;
 } TripDiagramTourViewType;

class TripDiagramTourDataClass
 {
  friend class          TTourTripDiagramForm;

  public :

  virtual unsigned int  TourCount        (void) const;

  virtual const char   *TourIdStrPtr     (unsigned int TourIndex) const;
  virtual const char   *TourNameStrPtr   (unsigned int TourIndex) const;
  virtual unsigned int  TourStopCount    (unsigned int TourIndex) const;
  virtual unsigned int  TourRouteStopIndex
                                         (unsigned int TourIndex,
                                          unsigned int StopIndex) const;

  virtual unsigned int  TourStopInTime   (unsigned int TourIndex,
                                          unsigned int StopIndex) const;

  virtual unsigned int  TourStopWaitTime (unsigned int TourIndex,
                                          unsigned int StopIndex) const;
  virtual bool          SetTourStopInTime(unsigned int TourIndex,
                                          unsigned int StopIndex,
                                          unsigned int InTimeValue);
  virtual bool          SetTourStopWaitTime
                                         (unsigned int TourIndex,
                                          unsigned int StopIndex,
                                          unsigned int WaitTimeValue);

  virtual bool          IsTourForward    (unsigned int     TourIndex) const;

  virtual VCanvasColorType
                        TourDrawColor    (unsigned int     TourIndex) const;
  virtual VCanvasPenType
                        TourDrawStyle    (unsigned int     TourIndex) const;

  virtual bool          TourVisible      (unsigned int     TourIndex) const;

  virtual void          TourSetColor     (unsigned int     TourIndex,
                                          VCanvasColorType Color);

  virtual void          TourSetPenStyle  (unsigned int     TourIndex,
                                          VCanvasPenType   PenStyle);

  virtual void          TourSetVisible   (unsigned int     TourIndex,
                                          bool             VisibleFlag);

  virtual void          TourDelete       (unsigned int     TourIndex); 

  vector<TripDiagramTourInfoType>         TourInfoArray;
  vector<TripDiagramTourViewType>         TourViewArray;
  
  private :

 };

// Specialization of base classes

class TripDiagramSubTourArrayStorageClass
 {
  public :
  
  TripDiagramSubTourArrayStorageClass (const TripDiagramTourDataClass
                                                          *TourDataPtr,
                                       const TripDiagramRouteDataClass
                                                          *RouteDataPtr);

  void                                 SetStopArray(const vector<string>      
                                                          &StopIdStrArray);

  virtual unsigned int                 Count     (void) const;
  virtual TripDiagramTourPtrClass      operator[](unsigned int Index) const;

  private :

  const TripDiagramTourDataClass      *TourDataPtr;
  const TripDiagramRouteDataClass     *RouteDataPtr;
 };

#endif

