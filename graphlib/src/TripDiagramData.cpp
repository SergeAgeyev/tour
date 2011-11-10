/* дюммши лндскэ ъбкъеряъ сярюпебьхл х асдер сдюкем б якедсчыху бепяхъу */

#error Obsolete module used

#include <vector>
#include <string>

#include <VCanvas.h>

#include <TripDiagramData.h>

using namespace std;

// Data storage definitions

unsigned int  TripDiagramRouteDataClass::StopCount    (void) const
 {
  return(StopInfoArray.size());
 }

const char   *TripDiagramRouteDataClass::StopNameStrPtr
                                      (unsigned int        StopIndex) const
 {
  if (StopIndex < StopInfoArray.size())
   {
    return(StopInfoArray[StopIndex].NameStr.c_str());
   }
  else
   {
    return("");
   }
 }

const char   *TripDiagramRouteDataClass::StopIdStrPtr
                                      (unsigned int        StopIndex) const
 {
  if (StopIndex < StopInfoArray.size())
   {
    return(StopInfoArray[StopIndex].IdStr.c_str());
   }
  else
   {
    return("");
   }
 }

float         TripDiagramRouteDataClass::StopDistance
                                      (unsigned int        FromStopIndex,
                                       unsigned int        ToStopIndex) const
 {
  float Result;

  Result = 0.0;

  if ((FromStopIndex < StopCount()) && (ToStopIndex < StopCount()))
   {
    if (FromStopIndex > ToStopIndex)
     {
      float TempIndex;

      TempIndex     = FromStopIndex;
      FromStopIndex = ToStopIndex;
      ToStopIndex   = TempIndex;
     }

    for (unsigned int Index = FromStopIndex; Index < ToStopIndex; Index++)
     {
      Result += PathInfoArray[Index].Distance;
     }
   }  

  return(Result);
 }


unsigned int  TripDiagramTourDataClass::TourCount
                                      (void) const
 {
  return(TourInfoArray.size());
 }


const char   *TripDiagramTourDataClass::TourIdStrPtr
                                      (unsigned int TourIndex) const
 {
  if (TourIndex < TourInfoArray.size())
   {
    return(TourInfoArray[TourIndex].TripIdStr.c_str());
   }
  else
   {
    return("");
   }
 }


const char   *TripDiagramTourDataClass::TourNameStrPtr
                                      (unsigned int TourIndex) const
 {
  if (TourIndex < TourInfoArray.size())
   {
    return(TourInfoArray[TourIndex].TripNameStr.c_str());
   }
  else
   {
    return("");
   }
 }

unsigned int  TripDiagramTourDataClass::TourStopCount
                                      (unsigned int        TourIndex) const
 {
  if (TourIndex < TourInfoArray.size())
   {
    return(TourInfoArray[TourIndex].StopInfoArray.size());
   }
  else
   {
    return(0);
   }
 }


unsigned int  TripDiagramTourDataClass::TourRouteStopIndex
                                      (unsigned int        TourIndex,
                                       unsigned int        StopIndex) const
 {
  if (TourIndex < TourInfoArray.size())
   {
    return(TourInfoArray[TourIndex].StopInfoArray[StopIndex].StopIndex);
   }
  else
   {
    return(0);
   }
 }


unsigned int  TripDiagramTourDataClass::TourStopInTime
                                      (unsigned int        TourIndex,
                                       unsigned int        StopIndex) const
 {
  if (TourIndex < TourInfoArray.size())
   {
    return(TourInfoArray[TourIndex].StopInfoArray[StopIndex].InTime);
   }
  else
   {
    return(0);
   }
 }

unsigned int  TripDiagramTourDataClass::TourStopWaitTime
                                      (unsigned int        TourIndex,
                                       unsigned int        StopIndex) const
 {
  if (TourIndex < TourInfoArray.size())
   {
    return(TourInfoArray[TourIndex].StopInfoArray[StopIndex].WaitTime);
   }
  else
   {
    return(0);
   }
 }

bool          TripDiagramTourDataClass::SetTourStopInTime
                                      (unsigned int        TourIndex,
                                       unsigned int        StopIndex,
                                       unsigned int        InTimeValue)
 {
  bool                                 ResultFlag;

  ResultFlag = true;

  if ((TourIndex < TourInfoArray.size()) &&
      (StopIndex < TourInfoArray[TourIndex].StopInfoArray.size()))
   {
    TourInfoArray[TourIndex].StopInfoArray[StopIndex].InTime = InTimeValue;
   }
  else
   {
    ResultFlag = false;
   }

  return (ResultFlag);
 }

bool          TripDiagramTourDataClass::SetTourStopWaitTime
                                      (unsigned int        TourIndex,
                                       unsigned int        StopIndex,
                                       unsigned int        WaitTimeValue)
 {
  bool                                 ResultFlag;

  ResultFlag = true;

  if ((TourIndex < TourInfoArray.size()) &&
      (StopIndex < TourInfoArray[TourIndex].StopInfoArray.size()))
   {
    TourInfoArray[TourIndex].StopInfoArray[StopIndex].WaitTime = WaitTimeValue;
   }
  else
   {
    ResultFlag = false;
   }

  return (ResultFlag);
 }

void             TripDiagramTourDataClass::TourDelete
                                      (unsigned int     TourIndex)
 {
  TourInfoArray.erase(TourInfoArray.begin() + TourIndex);
 }

bool             TripDiagramTourDataClass::IsTourForward
                                      (unsigned int     TourIndex) const
 {
  bool                                 ForwardFlag;

  ForwardFlag = true;

  if (TourStopCount(TourIndex) > 1)
   {
    if (TourRouteStopIndex(TourIndex,0) > TourRouteStopIndex(TourIndex,1))
     {
      ForwardFlag = false;
     }
   }

  return(ForwardFlag);
 }


VCanvasColorType TripDiagramTourDataClass::TourDrawColor
                                      (unsigned int        TourIndex) const
 {
  if (TourIndex < TourInfoArray.size())
   {
    return(TourViewArray[TourIndex].Color);
   }
  else
   {
    return(VCanvasColorBlack);
   }
 }


VCanvasPenType   TripDiagramTourDataClass::TourDrawStyle
                                      (unsigned int        TourIndex) const
 {
  if (TourIndex < TourInfoArray.size())
   {
    return(TourViewArray[TourIndex].PenStyle);
   }
  else
   {
    return(VCanvasPenSolid);
   }
 }


bool             TripDiagramTourDataClass::TourVisible
                                      (unsigned int        TourIndex) const
 {
  if (TourIndex < TourInfoArray.size())
   {
    return(TourViewArray[TourIndex].VisibleFlag);
   }
  else
   {
    return(false);
   }
 }


void             TripDiagramTourDataClass::TourSetColor
                                         (unsigned int     TourIndex,
                                          VCanvasColorType Color)
 {
  if (TourIndex < TourInfoArray.size())
   {
    TourViewArray[TourIndex].Color = Color;
   }
 }
 
void             TripDiagramTourDataClass::TourSetPenStyle
                                         (unsigned int     TourIndex,
                                          VCanvasPenType   PenStyle)
 {
  if (TourIndex < TourInfoArray.size())
   {
    TourViewArray[TourIndex].PenStyle = PenStyle;
   }
 }

void             TripDiagramTourDataClass::TourSetVisible
                                         (unsigned int     TourIndex,
                                          bool             VisibleFlag)
 {
  if (TourIndex < TourInfoArray.size())
   {
    TourViewArray[TourIndex].VisibleFlag = VisibleFlag;
   }
 }


// Specialization of base classes

class TripDiagramStopScheduleStorageClass : public TripDiagramStopScheduleClass
 {
  public :

  TripDiagramStopScheduleStorageClass      (const char    *IdStrPtr,
                                            const char    *NameStrPtr,
                                            unsigned int   InTime,
                                            unsigned int   WaitTime)
  : IdStr(IdStrPtr),NameStr(NameStrPtr),InTimeValue(InTime),WaitTimeValue(WaitTime)
   {
   }

  virtual const char        *IdStrPtr      (void) const
   {
    return(IdStr.c_str());
   }
  
  virtual const char        *NameStrPtr    (void) const
   {
    return(NameStr.c_str());
   }
  
  virtual unsigned int       InTime        (void) const
   {
    return(InTimeValue);
   }

  virtual unsigned int       WaitTime      (void) const
   {
    return(WaitTimeValue);
   }

  private :

  string                     IdStr;
  string                     NameStr;
  unsigned int               InTimeValue;
  unsigned int               WaitTimeValue;
 };

class TripDiagramTourScheduleStorageClass : public TripDiagramTourScheduleClass
 {
  public :

  TripDiagramTourScheduleStorageClass      (const TripDiagramTourDataClass
                                                        *TourDataPtr,
                                            const TripDiagramRouteDataClass
                                                        *RouteDataPtr,
                                            unsigned int TourIndex);

  virtual unsigned int       StopCount     (void) const;
  virtual TripDiagramStopSchedulePtrClass
                             Stop          (unsigned int Index) const;

  private :

  const TripDiagramTourDataClass      *TourDataPtr;
  const TripDiagramRouteDataClass     *RouteDataPtr;
  unsigned int                         TourIndex;
 };

class TripDiagramTourStorageClass : public TripDiagramTourClass
 {
  public :

  TripDiagramTourStorageClass                   (const TripDiagramTourDataClass
                                                                  *TourDataPtr,
                                                 const TripDiagramRouteDataClass
                                                                  *RouteDataPtr,
                                                 unsigned int      TourIndex);
  virtual const char                  *IdStrPtr  (void) const;
  virtual const char                  *NameStrPtr(void) const;
  virtual const char                  *BusModelStrPtr
                                                (void) const;

  virtual
  TripDiagramTourSchedulePtrClass      Schedule (void) const;

  private :

  const TripDiagramTourDataClass      *TourDataPtr;
  const TripDiagramRouteDataClass     *RouteDataPtr;
  unsigned int                         TourIndex;
 };

#define            Self                TripDiagramTourScheduleStorageClass

                   Self::Self              (const TripDiagramTourDataClass
                                                        *TourDataPtr,
                                            const TripDiagramRouteDataClass
                                                        *RouteDataPtr,
                                            unsigned int TourIndex)
 {
  this->TourDataPtr  = TourDataPtr;
  this->RouteDataPtr = RouteDataPtr;
  this->TourIndex    = TourIndex;
 }

unsigned int       Self::StopCount     (void) const
 {
  return(TourDataPtr->TourStopCount(TourIndex));
 }

TripDiagramStopSchedulePtrClass
                   Self::Stop          (unsigned int Index) const
 {
  return(TripDiagramStopSchedulePtrClass
         (new TripDiagramStopScheduleStorageClass
          (RouteDataPtr->StopIdStrPtr
            (TourDataPtr->TourRouteStopIndex(TourIndex,Index)),
           RouteDataPtr->StopNameStrPtr
            (TourDataPtr->TourRouteStopIndex(TourIndex,Index)),
           TourDataPtr->TourStopInTime(TourIndex,Index),
           TourDataPtr->TourStopWaitTime(TourIndex,Index))));
 }

#undef             Self


#define            Self                TripDiagramTourStorageClass

                   Self::Self                   (const TripDiagramTourDataClass
                                                                  *TourDataPtr,
                                                 const TripDiagramRouteDataClass
                                                                  *RouteDataPtr,
                                                 unsigned int      TourIndex)
 {
  this->TourDataPtr  = TourDataPtr;
  this->RouteDataPtr = RouteDataPtr;
  this->TourIndex    = TourIndex;
 }

const char        *Self::IdStrPtr               (void) const
 {
  return(TourDataPtr->TourIdStrPtr(TourIndex));
 }

const char        *Self::NameStrPtr             (void) const
 {
  return(TourDataPtr->TourNameStrPtr(TourIndex));
 }

const char        *Self::BusModelStrPtr         (void) const
 {
  return("");
 }

TripDiagramTourSchedulePtrClass     
                   Self::Schedule               (void) const
 {
  return(TripDiagramTourSchedulePtrClass
          (new TripDiagramTourScheduleStorageClass(TourDataPtr,RouteDataPtr,TourIndex)));
 }

#undef             Self


#define            Self                TripDiagramSubTourArrayStorageClass
  
                   Self::Self         (const TripDiagramTourDataClass
                                                          *TourDataPtr,
                                       const TripDiagramRouteDataClass
                                                          *RouteDataPtr)
 {
  this->TourDataPtr  = TourDataPtr;
  this->RouteDataPtr = RouteDataPtr;
 }

void               Self::SetStopArray (const vector<string>      
                                                          &StopIdStrArray)
 {
 }

unsigned int       Self::Count        (void) const
 {
  return(TourDataPtr->TourCount());
 }

TripDiagramTourPtrClass      
                   Self::operator[]   (unsigned int Index) const
 {
  return(TripDiagramTourPtrClass
          (new TripDiagramTourStorageClass(TourDataPtr,RouteDataPtr,Index)));
 }

#undef             Self


