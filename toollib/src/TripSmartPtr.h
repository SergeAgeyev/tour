#ifndef TripSmartPtrH
#define TripSmartPtrH

#include<stdlib.h>
#include<assert.h>

template<class BaseClass> class TripSmartPtrRefTemplate
 {
  public :

                   TripSmartPtrRefTemplate (BaseClass     *BaseClassPtr)
   {
    this->BaseClassPtr = BaseClassPtr;
    RefCount           = 1;
   }

                  ~TripSmartPtrRefTemplate (void)
   {
    if (BaseClassPtr != NULL)
     {
      delete BaseClassPtr;
     }
   }

  void             AddRef                  (void)
   {
    RefCount++;
   }

  void             DelRef                  (void)
   {
    assert(RefCount > 0);

    if (RefCount > 0)
     {
      RefCount--;
     }
   }

  bool             HasRef                  (void) const
   {
    if (RefCount > 0)
     {
      return(true);
     }
    else
     {
      return(false);
     }
   }

  BaseClass       *Ptr                     (void) const
   {
    return(BaseClassPtr);
   }

  private :

  BaseClass                                *BaseClassPtr;
  unsigned int                              RefCount;
 };

template<class BaseClass> class TripSmartPtrTemplate
 {
  typedef TripSmartPtrRefTemplate<BaseClass>               TripSmartPtrRefClass;
  typedef TripSmartPtrTemplate<BaseClass>                  TripSmartPtrClass;

  public :

                   TripSmartPtrTemplate    (void)
   {
    RefClassPtr = NULL;
   }

                   TripSmartPtrTemplate    (BaseClass     *BaseClassPtr)
   {
    if (BaseClassPtr != NULL)
     {
      RefClassPtr = new TripSmartPtrRefClass(BaseClassPtr);
     }
    else
     {
      RefClassPtr = NULL;
     }
   }

                   TripSmartPtrTemplate    (const TripSmartPtrClass
                                                          &SourceRef)
   {
    RefClassPtr = SourceRef.RefClassPtr;

    if (RefClassPtr != NULL)
     {
      RefClassPtr->AddRef();
     }
   }

                  ~TripSmartPtrTemplate    (void)
   {
    if (RefClassPtr != NULL)
     {
      RefClassPtr->DelRef();

      if (!RefClassPtr->HasRef())
       {
        delete RefClassPtr;
       }
     }
   }

  TripSmartPtrClass
                  &operator=               (const TripSmartPtrClass
                                                          &SourceRef)
   {
    if (SourceRef.RefClassPtr != RefClassPtr)
     {
      if (RefClassPtr != NULL)
       {
        RefClassPtr->DelRef();

        if (!RefClassPtr->HasRef())
         {
          delete RefClassPtr;
         }
       }

      RefClassPtr = SourceRef.RefClassPtr;

      if (RefClassPtr != NULL)
       {
        RefClassPtr->AddRef();
       }
     }

    return(*this);
   }

  BaseClass       *operator->              (void)
   {
    assert(RefClassPtr != NULL);

    return(RefClassPtr->Ptr());
   }

  BaseClass       *operator->              (void) const
   {
    assert(RefClassPtr != NULL);

    return(RefClassPtr->Ptr());
   }

  bool             IsNull                  (void) const
   {
    if (RefClassPtr != NULL)
     {
      return(false);
     }
    else
     {
      return(true);
     }
   }

  private :

  TripSmartPtrRefClass                     *RefClassPtr;
 };

#endif

