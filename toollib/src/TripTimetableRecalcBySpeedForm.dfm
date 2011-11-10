object TourTripTimetableRateSpeedForm: TTourTripTimetableRateSpeedForm
  Left = 192
  Top = 107
  BorderStyle = bsDialog
  Caption = 'Расчетные скорость от '
  ClientHeight = 97
  ClientWidth = 329
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object RateSpeedLabel: TLabel
    Left = 8
    Top = 12
    Width = 136
    Height = 13
    Caption = 'Расчетная скорость [км/ч]'
  end
  object SaveButton: TButton
    Left = 170
    Top = 69
    Width = 75
    Height = 25
    Caption = 'Пересчитать'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object CancelButton: TButton
    Left = 250
    Top = 69
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 2
  end
  object RateSpeedComboBox: TComboBox
    Left = 256
    Top = 8
    Width = 70
    Height = 21
    ItemHeight = 13
    Sorted = True
    TabOrder = 0
    Text = '60'
    Items.Strings = (
      '60'
      '70'
      '80')
  end
  object VStringStorage: TVStringStorage
    Lines.Strings = (
      'Введите значение расчетной скорости'
      'Неккоректное значение расчетной скорости'
      'Значение расчетной скорости не может быть меньше '
      'Значение расчетной скорости не может быть больше  ')
    Left = 85
    Top = 66
  end
end
