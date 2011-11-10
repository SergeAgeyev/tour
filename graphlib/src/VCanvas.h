#ifndef VCanvasH
#define VCanvasH

#include <vector>
#include <vcl.h>

typedef unsigned int VCanvasHandleType; // Canvas item handle
typedef unsigned int VCanvasColorType;  // Canvas color type (0x00RRGGBB)
typedef unsigned int VCanvasPenType;    // Canvas pen style

#define VCanvasColorFromRGB(R,G,B) (((unsigned int)B << 16) | \
                                    ((unsigned int)G << 8)  | \
                                    ((unsigned int)R))

#define VCanvasColorWhite VCanvasColorFromRGB(0xFF,0xFF,0xFF)
#define VCanvasColorBlack VCanvasColorFromRGB(0x00,0x00,0x00)
#define VCanvasColorRed   VCanvasColorFromRGB(0xFF,0x00,0x00)
#define VCanvasColorGreen VCanvasColorFromRGB(0x00,0xFF,0x00)
#define VCanvasColorBlue  VCanvasColorFromRGB(0x00,0x00,0xFF)

#define VCanvasPenSolid (psSolid)
#define VCanvasPenDash  (psDash)
#define VCanvasPenDot   (psDot)

#define VCanvasMouseButtonLeft   (0)
#define VCanvasMouseButtonMiddle (1)
#define VCanvasMouseButtonRight  (2)

enum
 {
  VCanvasTextAlignModeUpLeft   ,
  VCanvasTextAlignModeUpRight  ,
  VCanvasTextAlignModeDownLeft ,
  VCanvasTextAlignModeDownRight
 };

class VCanvasEventHandlerClass
 {
  public :

  virtual void          OnClick       (VCanvasHandleType   ItemHandle,
                                       unsigned int        ButtonCode,
                                       int                 PosX,
                                       int                 PosY);

  virtual void          OnDoubleClick (VCanvasHandleType   ItemHandle,
                                       unsigned int        ButtonCode,
                                       int                 PosX,
                                       int                 PosY);
 };

typedef struct
 {
  std::string      NameStr;
  std::string      ValueStr;
 } VCanvasItemTagType;

class VCanvasItemClass
 {
  friend class VCanvasClass;

  public :

  virtual ~VCanvasItemClass           (void);

  virtual void          Draw          (TCanvas            *CanvasPtr) = 0;
  virtual void          SetColor      (VCanvasColorType    Color) = 0;

  virtual bool          IsPointOver   (int                 PosX,
                                       int                 PosY) = 0;

  private :

  std::vector<VCanvasItemTagType>      TagArray;
 };

class VCanvasClass
 {
  public                :

                        VCanvasClass  (void);
                       ~VCanvasClass  (void);

  void                  SetCanvas     (TCanvas            *CanvasPtr);
  void                  SetEventHandler
                                      (VCanvasEventHandlerClass
                                                          *EventHandlerPtr);

  VCanvasHandleType     AppendLine    (int                 StartPosX,
                                       int                 StartPosY,
                                       int                 EndPosX,
                                       int                 EndPosY);

  VCanvasHandleType     AppendCircle  (int                 CenterPosX,
                                       int                 CenterPosY,
                                       unsigned int        Radius);

  VCanvasHandleType     AppendText    (int                 PosX,
                                       int                 PosY,
                                       const char         *TextStrPtr);

  void                  DeleteItem    (VCanvasHandleType   ItemHandle);

  void                  Clear         (void);

  void                  ItemSetColor  (VCanvasHandleType   ItemHandle,
                                       VCanvasColorType    Color);

  void                  ItemMove      (VCanvasHandleType   ItemHandle,
                                       int                 OffsetX,
                                       int                 OffsetY);
  
  void                  ItemMoveToTop (VCanvasHandleType   ItemHandle);
  void                  ItemMoveToBottom
                                      (VCanvasHandleType   ItemHandle);

  void                  SetColorByTag (VCanvasColorType    Color,
                                       const char         *TagNameStrPtr,
                                       const char         *TagValueStrPtr 
                                                           = NULL);
 
  void                  MoveToTopByTag(const char         *TagNameStrPtr,
                                       const char         *TagValueStrPtr 
                                                           = NULL);
 
  void                  MoveToBottomByTag
                                      (const char         *TagNameStrPtr,
                                       const char         *TagValueStrPtr 
                                                           = NULL);
 
  void                  ItemAppendTag (VCanvasHandleType   ItemHandle,
                                       const char         *TagNameStrPtr,
                                       const char         *TagValueStrPtr 
                                                           = NULL);
  
  void                  ItemDeleteTag (VCanvasHandleType   ItemHandle,
                                       const char         *TagNameStrPtr);
  
  bool                  ItemTagPresent(VCanvasHandleType   ItemHandle,
                                       const char         *TagNameStrPtr) const;
  
  const char           *ItemTagValueStrPtr
                                      (VCanvasHandleType   ItemHandle,
                                       const char         *TagNameStrPtr) const;
  
  void                  SetBackground (VCanvasColorType    Color);
  void                  SetColor      (VCanvasColorType    Color);
  void                  SetPen        (VCanvasPenType      Pen);
  void                  SetPenWidth   (unsigned int        PenWidth);
  void                  SetTextAlignMode
                                      (unsigned int        AlignMode);

  void                  Update        (void);

  void                  OnMouseClick  (unsigned int        ButtonCode,
                                       int                 PosX,
                                       int                 PosY);

  private               :

  VCanvasHandleType     AppendItem    (VCanvasItemClass   *ItemPtr);

  bool                  GetItemByPos  (VCanvasHandleType  *HandlePtr,
                                       int                 PosX,
                                       int                 PosY) const;

  bool                  ItemGetZOrderIndex
                                      (unsigned int       *ZOrderIndexPtr,
                                       VCanvasHandleType   ItemHandle) const;

  bool                  GetTagIndexByName
                                      (unsigned int       *TagIndexPtr,
                                       VCanvasHandleType   ItemHandle,
                                       const char         *TagNameStrPtr) const;
 
  bool                  ItemCheckByMask
                                      (VCanvasHandleType   ItemHandle,
                                       const char         *TagNameStrPtr,
                                       const char         *TagValueStrPtr) const;
  
  VCanvasColorType                     BackgroundColor;
  VCanvasColorType                     CurrentColor;
  VCanvasPenType                       CurrentPen;
  unsigned int                         CurrentPenWidth;
  unsigned int                         CurrentTextAlignMode;
  std::vector<VCanvasItemClass*>       ItemPtrArray;
  std::vector<unsigned int>            ItemZOrderArray;

  TCanvas                             *CanvasPtr;
  VCanvasEventHandlerClass            *EventHandlerPtr;
 };

#endif VCanvasH

