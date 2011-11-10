object TourTripDiagramOptionsForm: TTourTripDiagramOptionsForm
  Left = 250
  Top = 145
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Настройка графика рейсов'
  ClientHeight = 319
  ClientWidth = 444
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object OkButton: TButton
    Left = 280
    Top = 288
    Width = 75
    Height = 25
    Caption = 'Ok'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelButton: TButton
    Left = 360
    Top = 288
    Width = 75
    Height = 25
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 1
  end
  object TourVisibilityGroupBox: TGroupBox
    Left = 8
    Top = 8
    Width = 209
    Height = 73
    Caption = 'Отображение рейсов'
    TabOrder = 2
    object ShowForwardToursCheckBox: TCheckBox
      Left = 8
      Top = 16
      Width = 169
      Height = 17
      Caption = 'Отображать прямые рейсы'
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
    object ShowBackwardToursCheckBox: TCheckBox
      Left = 8
      Top = 32
      Width = 169
      Height = 17
      Caption = 'Отображать обратные рейсы'
      Checked = True
      State = cbChecked
      TabOrder = 1
    end
    object ShowTourInOutRowCheckBox: TCheckBox
      Left = 8
      Top = 48
      Width = 193
      Height = 17
      Caption = 'Отображать метки входа/выхода'
      Checked = True
      State = cbChecked
      TabOrder = 2
    end
  end
  object GridVisibilityGroupBox: TGroupBox
    Left = 224
    Top = 8
    Width = 209
    Height = 73
    Caption = 'Отображение координатной сетки'
    TabOrder = 3
    object ShowGridCheckBox: TCheckBox
      Left = 8
      Top = 16
      Width = 193
      Height = 17
      Caption = 'Отображать координатную сетку'
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
  end
  object ScaleGroupBox: TGroupBox
    Left = 8
    Top = 88
    Width = 425
    Height = 73
    Caption = 'Масштаб графиков'
    TabOrder = 4
    object BaseSpeedLabel: TLabel
      Left = 8
      Top = 16
      Width = 126
      Height = 13
      Caption = 'Базовая скорость (км/ч)'
      Layout = tlCenter
    end
    object BaseSpeedAngleLabel: TLabel
      Left = 8
      Top = 40
      Width = 150
      Height = 13
      Caption = 'Базовый угол наклона (град.)'
      Layout = tlCenter
    end
    object ScaleLabel: TLabel
      Left = 232
      Top = 16
      Width = 63
      Height = 13
      Caption = 'Масштаб (%)'
      Layout = tlCenter
    end
    object BaseSpeedEdit: TEdit
      Left = 168
      Top = 16
      Width = 25
      Height = 21
      MaxLength = 3
      TabOrder = 0
      Text = '60'
    end
    object BaseSpeedUpDown: TUpDown
      Left = 193
      Top = 16
      Width = 12
      Height = 21
      Associate = BaseSpeedEdit
      Min = 1
      Max = 120
      Position = 60
      TabOrder = 1
      Wrap = False
    end
    object BaseSpeedAngleEdit: TEdit
      Left = 168
      Top = 40
      Width = 25
      Height = 21
      MaxLength = 2
      TabOrder = 2
      Text = '30'
    end
    object BaseSpeedAngleUpDown: TUpDown
      Left = 193
      Top = 40
      Width = 12
      Height = 21
      Associate = BaseSpeedAngleEdit
      Min = 1
      Max = 89
      Position = 30
      TabOrder = 3
      Wrap = False
    end
    object ViewScaleComboBox: TComboBox
      Left = 304
      Top = 16
      Width = 41
      Height = 21
      ItemHeight = 13
      TabOrder = 4
      Text = '100'
      Items.Strings = (
        '25'
        '50'
        '75'
        '100'
        '150'
        '200'
        '500')
    end
  end
  object ColorsGroupBox: TGroupBox
    Left = 8
    Top = 168
    Width = 425
    Height = 113
    Caption = 'Настройка цветов'
    TabOrder = 5
    object GridColorLabel: TLabel
      Left = 8
      Top = 16
      Width = 131
      Height = 13
      Caption = 'Цвет координатной сетки'
      Layout = tlCenter
    end
    object GridColorShape: TShape
      Left = 144
      Top = 16
      Width = 25
      Height = 25
    end
    object TourCommonColorLabel: TLabel
      Left = 8
      Top = 48
      Width = 115
      Height = 13
      Caption = 'Основной цвет рейсов'
      Layout = tlCenter
    end
    object TourCommonColorShape: TShape
      Left = 144
      Top = 48
      Width = 25
      Height = 25
    end
    object TourSelectedColorLabel: TLabel
      Left = 8
      Top = 80
      Width = 122
      Height = 13
      Caption = 'Цвет выбранного рейса'
      Layout = tlCenter
    end
    object TourSelectedColorShape: TShape
      Left = 144
      Top = 80
      Width = 25
      Height = 25
    end
    object GridColorButton: TButton
      Left = 176
      Top = 16
      Width = 75
      Height = 25
      Caption = 'Изменить...'
      TabOrder = 0
      OnClick = GridColorButtonClick
    end
    object TourCommonColorButton: TButton
      Left = 176
      Top = 48
      Width = 75
      Height = 25
      Caption = 'Изменить...'
      TabOrder = 1
      OnClick = TourCommonColorButtonClick
    end
    object TourSelectedColorButton: TButton
      Left = 176
      Top = 80
      Width = 75
      Height = 25
      Caption = 'Изменить...'
      TabOrder = 2
      OnClick = TourSelectedColorButtonClick
    end
    object MonoColorTourModeCheckBox: TCheckBox
      Left = 256
      Top = 48
      Width = 161
      Height = 17
      Caption = 'Одноцветное отображение'
      Checked = True
      State = cbChecked
      TabOrder = 3
      OnClick = MonoColorTourModeCheckBoxClick
    end
  end
  object SelectColorDialog: TColorDialog
    Ctl3D = True
    Left = 8
    Top = 288
  end
end
