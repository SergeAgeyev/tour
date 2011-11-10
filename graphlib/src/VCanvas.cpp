
#include <math.h>
#include <vector>
#include <string>
#include <vcl.h>

#include <VCanvas.h>

#define VCanvasFloatMinValue        (0.005)
#define VCanvasSearchPrecisionValue (2)

class VCanvasItemLineClass : public VCanvasItemClass
 {
  public                :

  VCanvasItemLineClass                (int                 StartPosX,
                                       int                 StartPosY,
                                       int                 EndPosX,
                                       int                 EndPosY,
                                       VCanvasColorType    Color,
                                       VCanvasPenType      Pen,
                                       unsigned int        PenWidth);

  virtual void          Draw          (TCanvas            *CanvasPtr);
  virtual void          SetColor      (VCanvasColorType    Color);

  virtual bool          IsPointOver   (int                 PosX,
                                       int                 PosY);

  private               :

  int                                  StartPosX;
  int                                  StartPosY;
  int                                  EndPosX;
  int                                  EndPosY;
  VCanvasColorType                     Color;
  VCanvasPenType                       Pen;
  unsigned int                         PenWidth;
 };

class VCanvasItemCircleClass : public VCanvasItemClass
 {
  public                :

  VCanvasItemCircleClass              (int                 CenterPosX,
                                       int                 CenterPosY,
                                       unsigned int        Radius,
                                       VCanvasColorType    Color,
                                       VCanvasPenType      Pen,
                                       unsigned int        PenWidth);

  virtual void          Draw          (TCanvas            *CanvasPtr);
  virtual void          SetColor      (VCanvasColorType    Color);

  virtual bool          IsPointOver   (int                 PosX,
                                       int                 PosY);

  private               :

  int                                  CenterPosX;
  int                                  CenterPosY;
  unsigned int                         Radius;
  VCanvasColorType                     Color;
  VCanvasPenType                       Pen;
  unsigned int                         PenWidth;
 };

class VCanvasItemTextClass : public VCanvasItemClass
 {
  public                :

  VCanvasItemTextClass                (int                 PosX,
                                       int                 PosY,
                                       unsigned int        AlignMode,
                                       const char         *TextStrPtr,
                                       VCanvasColorType    Color);

  virtual void          Draw          (TCanvas            *CanvasPtr);
  virtual void          SetColor      (VCanvasColorType    Color);

  virtual bool          IsPointOver   (int                 PosX,
                                       int                 PosY);

  private               :

  int                                  PosX;
  int                                  PosY;
  int                                  SizeX;
  int                                  SizeY;
  unsigned int                         AlignMode;
  VCanvasColorType                     Color;
  std::string                          TextStr;
 };

 
#define       Self                     VCanvasEventHandlerClass

void          Self::OnClick           (VCanvasHandleType   ItemHandle,
                                       unsigned int        ButtonCode,
                                       int                 PosX,
                                       int                 PosY)
 {
 }

void          Self::OnDoubleClick     (VCanvasHandleType   ItemHandle,
                                       unsigned int        ButtonCode,
                                       int                 PosX,
                                       int                 PosY)
 {
 }

#undef        Self


#define       Self                     VCanvasItemClass

              Self::~Self             (void)
 {
 }

#undef        Self


#define       Self                     VCanvasItemLineClass
  
              Self::Self              (int                 StartPosX,
                                       int                 StartPosY,
                                       int                 EndPosX,
                                       int                 EndPosY,
                                       VCanvasColorType    Color,
                                       VCanvasPenType      Pen,
                                       unsigned int        PenWidth)
 {
  this->StartPosX = StartPosX;
  this->StartPosY = StartPosY;
  this->EndPosX   = EndPosX;
  this->EndPosY   = EndPosY;
  this->Color     = Color;
  this->Pen       = Pen;
  this->PenWidth  = PenWidth;
 }

void          Self::Draw              (TCanvas            *CanvasPtr)
 {
  CanvasPtr->Pen->Color   = (TColor)Color;
  CanvasPtr->Pen->Style   = (TPenStyle)Pen;
  CanvasPtr->Pen->Width   = PenWidth;

  CanvasPtr->MoveTo(StartPosX,StartPosY);
  CanvasPtr->LineTo(EndPosX,EndPosY);
 }

void          Self::SetColor          (VCanvasColorType    Color)
 {
  this->Color = Color;
 }

bool          Self::IsPointOver       (int                 PosX,
                                       int                 PosY)
 {
  float                                L;
  float                                r;
  float                                s;

  L = sqrt(pow(EndPosX - StartPosX,2) + pow(EndPosY - StartPosY,2));

  if (L > VCanvasFloatMinValue)
   {
    r = ((StartPosY - PosY)*(StartPosY - EndPosY) - 
          (StartPosX - PosX)*(EndPosX - StartPosX)) / pow(L,2);

    s = ((StartPosY - PosY)*(EndPosX - StartPosX) -
          (StartPosX - PosX)*(EndPosY - StartPosY)) / pow(L,2);

    if ((fabs(s * L) < VCanvasSearchPrecisionValue) && (r >= 0) && (r <= 1))
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

#undef        Self


#define       Self                     VCanvasItemCircleClass
  
              Self::Self              (int                 CenterPosX,
                                       int                 CenterPosY,
                                       unsigned int        Radius,
                                       VCanvasColorType    Color,
                                       VCanvasPenType      Pen,
                                       unsigned int        PenWidth)
 {
  this->CenterPosX = CenterPosX;
  this->CenterPosY = CenterPosY;
  this->Radius     = Radius;
  this->Color      = Color;
  this->Pen        = Pen;
  this->PenWidth   = PenWidth;
 }

void          Self::Draw              (TCanvas            *CanvasPtr)
 {
  CanvasPtr->Pen->Color   = (TColor)Color;
  CanvasPtr->Pen->Style   = (TPenStyle)Pen;
  CanvasPtr->Pen->Width   = PenWidth;

  CanvasPtr->Ellipse(CenterPosX - Radius,
                     CenterPosY - Radius,
                     CenterPosX + Radius,
                     CenterPosY + Radius);
 }

void          Self::SetColor          (VCanvasColorType    Color)
 {
  this->Color = Color;
 }

bool          Self::IsPointOver       (int                 PosX,
                                       int                 PosY)
 {
  if (sqrt(pow(CenterPosX - PosX,2) + pow(CenterPosY - PosY,2)) > Radius)
   {
    return(false);
   }
  else
   {
    return(true);
   }
 }

#undef        Self


#define       Self                     VCanvasItemTextClass

              Self::Self              (int                 PosX,
                                       int                 PosY,
                                       unsigned int        AlignMode,
                                       const char         *TextStrPtr,
                                       VCanvasColorType    Color)
 {
  this->PosX      = PosX;
  this->PosY      = PosY;
  SizeX           = 0;
  SizeY           = 0;
  this->Color     = Color;
  this->AlignMode = AlignMode;
  TextStr         = TextStrPtr;
 }

void          Self::Draw              (TCanvas            *CanvasPtr)
 {
  AnsiString                           AnsiTextStr(TextStr.c_str());

  SizeX = CanvasPtr->TextWidth(AnsiTextStr);
  SizeY = CanvasPtr->TextHeight(AnsiTextStr);

  switch (AlignMode)
   {
    case (VCanvasTextAlignModeDownRight)    :
     {
      CanvasPtr->TextOut(PosX - SizeX,PosY - SizeY,AnsiTextStr);
     } break;

    case (VCanvasTextAlignModeDownLeft)     :
     {
      CanvasPtr->TextOut(PosX,PosY - SizeY,AnsiTextStr);
     } break;

    case (VCanvasTextAlignModeUpRight)      :
     {
      CanvasPtr->TextOut(PosX - SizeX,PosY,AnsiTextStr);
     } break;

    default                                 :
     {
      CanvasPtr->TextOut(PosX,PosY,AnsiTextStr);
     }
   }
 }

void          Self::SetColor          (VCanvasColorType    Color)
 {
  this->Color = Color;
 }

bool          Self::IsPointOver       (int                 PosX,
                                       int                 PosY)
 {
  if ((SizeX > 0) && (SizeY > 0))
   {
    if      (AlignMode == VCanvasTextAlignModeDownRight)
     {
      if ((PosX >= (this->PosX - SizeX)) && (PosX < this->PosX) &&
          (PosY >= (this->PosY - SizeY)) && (PosY < this->PosY))
       {
        return(true);
       }
      else
       {
        return(false);
       }
     }
    else if (AlignMode == VCanvasTextAlignModeDownLeft)
     { 
      if ((PosX >= this->PosX) && (PosX < (this->PosX + SizeX)) &&
          (PosY >= (this->PosY - SizeY)) && (PosY < this->PosY))
       {
        return(true);
       }
      else
       {
        return(false);
       }
     }
    else if (AlignMode == VCanvasTextAlignModeUpRight)
     {
      if ((PosX >= (this->PosX - SizeX)) && (PosX < this->PosX) &&
          (PosY >= this->PosY) && (PosY < (this->PosY + SizeY)))
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
      if ((PosX >= this->PosX) && (PosX < (this->PosX + SizeX)) &&
          (PosY >= this->PosY) && (PosY < (this->PosY + SizeY)))
       {
        return(true);
       }
      else
       {
        return(false);
       }
     }
   }
  else
   {
    return(false);
   }
 }

#undef        Self


#define       Self                     VCanvasClass

              Self::Self              (void)
 {
  CanvasPtr            = NULL;
  EventHandlerPtr      = NULL;
  BackgroundColor      = VCanvasColorWhite;
  CurrentColor         = VCanvasColorBlack;
  CurrentPen           = VCanvasPenSolid;
  CurrentPenWidth      = 1;
  CurrentTextAlignMode = VCanvasTextAlignModeUpLeft;
 }

              Self::~Self             (void)
 {
  Clear();
 }

void          Self::Clear             (void)
 {
  int                                  Index;
  int                                  Limit;
  VCanvasItemClass                    *ItemPtr;

  Limit = ItemPtrArray.size();

  for (Index = 0; Index < Limit; Index++)
   {
    ItemPtr = ItemPtrArray[Index];

    if (ItemPtr != NULL)
     {
      delete ItemPtr;
     }
   }

  ItemPtrArray.clear();
  ItemZOrderArray.clear();
 }

VCanvasHandleType     
              Self::AppendItem        (VCanvasItemClass   *ItemPtr)
 {
  VCanvasHandleType                    ItemHandle;

  ItemHandle = ItemPtrArray.size();

  ItemPtrArray.push_back(ItemPtr);
  ItemZOrderArray.push_back(ItemHandle);

  return(ItemHandle);
 }

void          Self::SetCanvas         (TCanvas            *CanvasPtr)
 {
  this->CanvasPtr = CanvasPtr;
 }

void          Self::SetEventHandler   (VCanvasEventHandlerClass
                                                          *EventHandlerPtr)
 {
  this->EventHandlerPtr = EventHandlerPtr;
 }

VCanvasHandleType     
              Self::AppendLine        (int                 StartPosX,
                                       int                 StartPosY,
                                       int                 EndPosX,
                                       int                 EndPosY)
 {
  VCanvasItemLineClass                *LinePtr;

  LinePtr = new VCanvasItemLineClass(StartPosX,
                                     StartPosY,
                                     EndPosX,
                                     EndPosY,
                                     CurrentColor,
                                     CurrentPen,
                                     CurrentPenWidth);

  return(AppendItem(LinePtr));
 }

VCanvasHandleType     
              Self::AppendCircle      (int                 CenterPosX,
                                       int                 CenterPosY,
                                       unsigned int        Radius)
 {
  VCanvasItemCircleClass              *CirclePtr;

  CirclePtr = new VCanvasItemCircleClass(CenterPosX,
                                       CenterPosY,
                                       Radius,
                                       CurrentColor,
                                       CurrentPen,
                                       CurrentPenWidth);

  return(AppendItem(CirclePtr));
 }

VCanvasHandleType  
              Self::AppendText        (int                 PosX,
                                       int                 PosY,
                                       const char         *TextStrPtr)
 {
  VCanvasItemTextClass                *TextPtr;

  TextPtr = new VCanvasItemTextClass(PosX,
                                     PosY,
                                     CurrentTextAlignMode, 
                                     TextStrPtr,
                                     CurrentColor);

  return(AppendItem(TextPtr));
 }

void          Self::DeleteItem        (VCanvasHandleType   ItemHandle)
 {
  unsigned int                         ZOrderIndex;
  
  if (ItemHandle < ItemPtrArray.size())
   {
    if (ItemPtrArray[ItemHandle] != NULL)
     {
      delete ItemPtrArray[ItemHandle];

      ItemPtrArray[ItemHandle] = NULL;
     }
   }

  if (ItemGetZOrderIndex(&ZOrderIndex,ItemHandle))
   {
    ItemZOrderArray.erase(ItemZOrderArray.begin() + ZOrderIndex);
   }
 }

void          Self::ItemSetColor      (VCanvasHandleType   ItemHandle,
                                       VCanvasColorType    Color)
 {
  if (ItemHandle < ItemPtrArray.size())
   {
    if (ItemPtrArray[ItemHandle] != NULL)
     {
      ItemPtrArray[ItemHandle]->SetColor(Color);
     }
   }
 }

void          Self::ItemMove          (VCanvasHandleType   ItemHandle,
                                       int                 OffsetX,
                                       int                 OffsetY)
 {
  // Not ready
 }
 
void          Self::ItemMoveToTop     (VCanvasHandleType   ItemHandle)
 {
  unsigned int                         ZOrderIndex;

  if (ItemGetZOrderIndex(&ZOrderIndex,ItemHandle))
   {
    ItemZOrderArray.erase(ItemZOrderArray.begin() + ZOrderIndex);
    ItemZOrderArray.push_back(ItemHandle);
   }
 }

void          Self::ItemMoveToBottom  (VCanvasHandleType   ItemHandle)
 {
  unsigned int                         ZOrderIndex;

  if (ItemGetZOrderIndex(&ZOrderIndex,ItemHandle))
   {
    ItemZOrderArray.erase(ItemZOrderArray.begin() + ZOrderIndex);
    ItemZOrderArray.insert(ItemZOrderArray.begin(),ItemHandle);
   }
 }

void          Self::SetBackground     (VCanvasColorType    Color)
 {
  BackgroundColor = Color;
 }

void          Self::SetColor          (VCanvasColorType    Color)
 {
  CurrentColor = Color;
 }

void          Self::SetPen            (VCanvasPenType      Pen)
 {
  CurrentPen = Pen;
 }

void          Self::SetPenWidth       (unsigned int        PenWidth)
 {
  if (PenWidth > 0)
   {
    CurrentPenWidth = PenWidth;
   }
  else
   {
    CurrentPenWidth = 1;
   }
 }

void          Self::SetTextAlignMode  (unsigned int        AlignMode)
 {
  CurrentTextAlignMode = AlignMode;
 }

void          Self::SetColorByTag     (VCanvasColorType    Color,
                                       const char         *TagNameStrPtr,
                                       const char         *TagValueStrPtr)
 {
  unsigned int                         Index;
  unsigned int                         Limit;

  Limit = ItemPtrArray.size();

  for (Index = 0; Index < Limit; Index++)
   {
    if (ItemPtrArray[Index] != NULL)
     {
      if (ItemCheckByMask(Index,TagNameStrPtr,TagValueStrPtr))
       {
        ItemPtrArray[Index]->SetColor(Color);
       }
     }
   }
 }

void          Self::MoveToTopByTag    (const char         *TagNameStrPtr,
                                       const char         *TagValueStrPtr)
 {
  unsigned int                         Index;
  unsigned int                         Limit;

  Limit = ItemPtrArray.size();

  for (Index = 0; Index < Limit; Index++)
   {
    if (ItemPtrArray[Index] != NULL)
     {
      if (ItemCheckByMask(Index,TagNameStrPtr,TagValueStrPtr))
       {
        ItemMoveToTop(Index);
       }
     }
   }
 }
 
void          Self::MoveToBottomByTag
                                      (const char         *TagNameStrPtr,
                                       const char         *TagValueStrPtr)
 {
  unsigned int                         Index;
  unsigned int                         Limit;

  Limit = ItemPtrArray.size();

  for (Index = 0; Index < Limit; Index++)
   {
    if (ItemPtrArray[Index] != NULL)
     {
      if (ItemCheckByMask(Index,TagNameStrPtr,TagValueStrPtr))
       {
        ItemMoveToBottom(Index);
       }
     }
   }
 }
 
 
void          Self::ItemAppendTag     (VCanvasHandleType   ItemHandle,
                                       const char         *TagNameStrPtr,
                                       const char         *TagValueStrPtr)
 {
  if (ItemHandle < ItemPtrArray.size())
   {
    if (ItemPtrArray[ItemHandle] != NULL)
     {
      VCanvasItemTagType     Tag;

      Tag.NameStr = TagNameStrPtr;

      if (TagValueStrPtr != NULL)
       {
        Tag.ValueStr = TagValueStrPtr;
       }
      else
       {
        Tag.ValueStr = "";
       }
      
      ItemPtrArray[ItemHandle]->TagArray.push_back(Tag);
     }
   }
 }
  
void          Self::ItemDeleteTag     (VCanvasHandleType   ItemHandle,
                                       const char         *TagNameStrPtr)
 {
  if (ItemHandle < ItemPtrArray.size())
   {
    if (ItemPtrArray[ItemHandle] != NULL)
     {
      unsigned int TagIndex;
      
      if (GetTagIndexByName(&TagIndex,ItemHandle,TagNameStrPtr))
       {
        ItemPtrArray[ItemHandle]->TagArray.erase
         (ItemPtrArray[ItemHandle]->TagArray.begin() + TagIndex);
       }
     }
   }
 }
  
bool          Self::ItemTagPresent    (VCanvasHandleType   ItemHandle,
                                       const char         *TagNameStrPtr) const
 {
  bool                                 PresentFlag;

  PresentFlag = false;

  if (ItemHandle < ItemPtrArray.size())
   {
    if (ItemPtrArray[ItemHandle] != NULL)
     {
      unsigned int TagIndex;
      
      if (GetTagIndexByName(&TagIndex,ItemHandle,TagNameStrPtr))
       {
        PresentFlag = true;
       }
     }
   }

  return(PresentFlag);
 }
  
const char   *Self::ItemTagValueStrPtr(VCanvasHandleType   ItemHandle,
                                       const char         *TagNameStrPtr) const
 {
  const char                          *ValueStrPtr;

  ValueStrPtr = NULL;
  
  if (ItemHandle < ItemPtrArray.size())
   {
    if (ItemPtrArray[ItemHandle] != NULL)
     {
      unsigned int TagIndex;
      
      if (GetTagIndexByName(&TagIndex,ItemHandle,TagNameStrPtr))
       {
        ValueStrPtr = ItemPtrArray[ItemHandle]
                       ->TagArray[TagIndex].ValueStr.c_str();
       }
     }
   }

  return(ValueStrPtr);
 }
 
void          Self::Update            (void)
 {
  int                                  Index; 
  int                                  Limit;
  unsigned int                         ItemHandle; 
  TRect                                ClipRectangle;

  if (CanvasPtr != NULL)
   { 
    ClipRectangle = CanvasPtr->ClipRect;

    CanvasPtr->Pen->Color   = (TColor)BackgroundColor;
    CanvasPtr->Pen->Style   = psSolid;
    CanvasPtr->Brush->Color = (TColor)BackgroundColor;
    CanvasPtr->Brush->Style = bsSolid;

    CanvasPtr->Rectangle(ClipRectangle);

    Limit = ItemZOrderArray.size();

    for (Index = 0; Index < Limit; Index++)
     {
      ItemHandle = ItemZOrderArray[Index];
      
      ItemPtrArray[ItemHandle]->Draw(CanvasPtr);
     }
   }  
 }

bool          Self::GetItemByPos      (VCanvasHandleType  *HandlePtr,
                                       int                 PosX,
                                       int                 PosY) const
 {
  bool                                 FoundFlag;
  unsigned int                         Index; 
  unsigned int                         Limit;

  Index     = 0;
  Limit     = ItemZOrderArray.size();
  FoundFlag = false;
 
  while ((Index < Limit) && (!FoundFlag))
   {
    if (ItemPtrArray[ItemZOrderArray[Limit - Index - 1]]
         ->IsPointOver(PosX,PosY))
     {
      FoundFlag  = true;
      *HandlePtr = ItemZOrderArray[Limit - Index - 1];
     }

    Index++;
   }

  return(FoundFlag);
 }

bool          Self::GetTagIndexByName (unsigned int       *TagIndexPtr,
                                       VCanvasHandleType   ItemHandle,
                                       const char         *TagNameStrPtr) const
 {
  unsigned int                         Index;
  unsigned int                         Limit;
  bool                                 FoundFlag;

  Index     = 0;
  Limit     = ItemPtrArray[ItemHandle]->TagArray.size();
  FoundFlag = false;

  while ((Index < Limit) && (!FoundFlag))
   {
    if (ItemPtrArray[ItemHandle]->TagArray[Index].NameStr == TagNameStrPtr)
     {
      FoundFlag    = true;
      *TagIndexPtr = Index;
     }
    else
     {
      Index++;
     }
   }

  return(FoundFlag);
 }

bool          Self::ItemGetZOrderIndex(unsigned int       *ZOrderIndexPtr,
                                       VCanvasHandleType   ItemHandle) const
 {
  unsigned int                         Index;
  unsigned int                         Limit;
  bool                                 FoundFlag;

  Index     = 0;
  Limit     = ItemZOrderArray.size();
  FoundFlag = false;

  while ((Index < Limit) && (!FoundFlag))
   {
    if (ItemZOrderArray[Index] == ItemHandle)
     {
      FoundFlag       = true;
      *ZOrderIndexPtr = Index;
     }
    else
     {
      Index++;
     }
   }
 
  return(FoundFlag);
 }

bool          Self::ItemCheckByMask   (VCanvasHandleType   ItemHandle,
                                       const char         *TagNameStrPtr,
                                       const char         *TagValueStrPtr) const
 {
  unsigned int                         TagIndex;
  bool                                 CheckPassedFlag;
  
  CheckPassedFlag = false;

  if (GetTagIndexByName(&TagIndex,ItemHandle,TagNameStrPtr))
   {
    if (TagValueStrPtr != NULL)
     {
      if (ItemPtrArray[ItemHandle]->TagArray[TagIndex].ValueStr ==
           TagValueStrPtr)
       {
        CheckPassedFlag = true;
       }
     } 
    else
     {
      CheckPassedFlag = true;
     }
   }

  return(CheckPassedFlag);
 }

void          Self::OnMouseClick      (unsigned int        ButtonCode,
                                       int                 PosX,
                                       int                 PosY)
 {
  VCanvasHandleType                    ItemHandle;

  if (GetItemByPos(&ItemHandle,PosX,PosY))
   {
    if (EventHandlerPtr != NULL)
     {
      EventHandlerPtr->OnClick(ItemHandle,ButtonCode,PosX,PosY);
     }
   }
 }

#undef        Self

