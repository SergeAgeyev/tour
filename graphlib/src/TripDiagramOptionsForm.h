//---------------------------------------------------------------------------

#ifndef TripDiagramOptionsFormH
#define TripDiagramOptionsFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TTourTripDiagramOptionsForm : public TForm
 {
  __published:	// IDE-managed Components

  TButton                   *OkButton;
  TButton                   *CancelButton;
  TGroupBox                 *TourVisibilityGroupBox;
  TCheckBox                 *ShowForwardToursCheckBox;
  TCheckBox                 *ShowBackwardToursCheckBox;
  TGroupBox                 *GridVisibilityGroupBox;
  TCheckBox                 *ShowGridCheckBox;
  TGroupBox                 *ScaleGroupBox;
  TEdit                     *BaseSpeedEdit;
  TLabel                    *BaseSpeedLabel;
  TUpDown                   *BaseSpeedUpDown;
  TLabel                    *BaseSpeedAngleLabel;
  TEdit                     *BaseSpeedAngleEdit;
  TUpDown                   *BaseSpeedAngleUpDown;
  TLabel                    *ScaleLabel;
  TGroupBox                 *ColorsGroupBox;
  TLabel                    *GridColorLabel;
  TShape                    *GridColorShape;
  TButton                   *GridColorButton;
  TLabel                    *TourCommonColorLabel;
  TShape                    *TourCommonColorShape;
  TButton                   *TourCommonColorButton;
  TLabel                    *TourSelectedColorLabel;
  TShape                    *TourSelectedColorShape;
  TButton                   *TourSelectedColorButton;
  TCheckBox                 *MonoColorTourModeCheckBox;
  TColorDialog              *SelectColorDialog;
  TComboBox                 *ViewScaleComboBox;
  TCheckBox                 *ShowTourInOutRowCheckBox;

  void __fastcall            FormCloseQuery(TObject *Sender, bool &CanClose);
  void __fastcall            GridColorButtonClick(TObject *Sender);
  void __fastcall            TourCommonColorButtonClick(TObject *Sender);
  void __fastcall            TourSelectedColorButtonClick(TObject *Sender);
  void __fastcall            MonoColorTourModeCheckBoxClick(TObject *Sender);

  private:

  float                      FBaseSpeed;
  unsigned int               FBaseSpeedAngle;
  float                      FViewScale;
  bool                       FShowForwardTours;
  bool                       FShowBackwardTours;
  bool                       FShowTourInOutRow;
  bool                       FShowGrid;
  bool                       FMonoColorTourMode;
  unsigned int               FGridColor;
  unsigned int               FTourCommonColor;
  unsigned int               FTourSelectedColor;

  void __fastcall            SetBaseSpeed(float value);
  float __fastcall           GetBaseSpeed();
  void __fastcall            SetBaseSpeedAngle(unsigned int value);
  unsigned int __fastcall    GetBaseSpeedAngle();
  void __fastcall            SetViewScale(float value);
  float __fastcall           GetViewScale();
  void __fastcall            SetShowForwardTours(bool value);
  bool __fastcall            GetShowForwardTours();
  void __fastcall            SetShowBackwardTours(bool value);
  bool __fastcall            GetShowBackwardTours();
  void __fastcall            SetShowTourInOutRow(bool value);
  bool __fastcall            GetShowTourInOutRow();
  void __fastcall            SetShowGrid(bool value);
  bool __fastcall            GetShowGrid();
  void __fastcall            SetMonoColorTourMode(bool value);
  bool __fastcall            GetMonoColorTourMode();
  void __fastcall            SetGridColor(unsigned int value);
  unsigned int __fastcall    GetGridColor();
  void __fastcall            SetTourCommonColor(unsigned int value);
  unsigned int __fastcall    GetTourCommonColor();
  void __fastcall            SetTourSelectedColor(unsigned int value);
  unsigned int __fastcall    GetTourSelectedColor();	// User declarations

  public:		// User declarations

  __fastcall                 TTourTripDiagramOptionsForm(TComponent* Owner);
  __property float           BaseSpeed          = { read=GetBaseSpeed, write=SetBaseSpeed };
  __property unsigned int    BaseSpeedAngle     = { read=GetBaseSpeedAngle, write=SetBaseSpeedAngle };
  __property float           ViewScale         = { read=GetViewScale, write=SetViewScale };
  __property bool            ShowForwardTours   = { read=GetShowForwardTours, write=SetShowForwardTours, default=true };
  __property bool            ShowBackwardTours  = { read=GetShowBackwardTours, write=SetShowBackwardTours, default=true };
  __property bool            ShowTourInOutRow  = { read=GetShowTourInOutRow, write=SetShowTourInOutRow, default=true };
  __property bool            ShowGrid           = { read=GetShowGrid, write=SetShowGrid, default=true };
  __property bool            MonoColorTourMode  = { read=GetMonoColorTourMode, write=SetMonoColorTourMode };
  __property unsigned int    GridColor  = { read=GetGridColor, write=SetGridColor };
  __property unsigned int    TourCommonColor  = { read=GetTourCommonColor, write=SetTourCommonColor };
  __property unsigned int    TourSelectedColor  = { read=GetTourSelectedColor, write=SetTourSelectedColor };
};
//---------------------------------------------------------------------------
extern PACKAGE TTourTripDiagramOptionsForm *TourTripDiagramOptionsForm;
//---------------------------------------------------------------------------
#endif
