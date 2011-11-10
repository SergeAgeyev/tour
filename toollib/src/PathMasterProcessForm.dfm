object TourPathMasterProcessForm: TTourPathMasterProcessForm
  Left = 235
  Top = 160
  BorderStyle = bsDialog
  Caption = 'Новый участок пути'
  ClientHeight = 156
  ClientWidth = 483
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
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PathNormSpeedLabel: TLabel
    Left = 18
    Top = 66
    Width = 48
    Height = 13
    Caption = 'Скорость'
  end
  object PathFromStopIdLabel: TLabel
    Left = 16
    Top = 11
    Width = 50
    Height = 13
    Caption = 'Нач.пункт'
  end
  object PathLengthLabel: TLabel
    Left = 279
    Top = 67
    Width = 60
    Height = 13
    Caption = 'Расстояние'
  end
  object PathToStopIdIdLabel: TLabel
    Left = 16
    Top = 39
    Width = 50
    Height = 13
    Caption = 'Кон.пункт'
  end
  object CancelButton: TButton
    Left = 402
    Top = 124
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 7
  end
  object SaveButton: TButton
    Left = 322
    Top = 124
    Width = 75
    Height = 25
    Caption = 'Сохранить'
    Default = True
    ModalResult = 1
    TabOrder = 6
  end
  object PathNormSpeedEdit: TEdit
    Left = 72
    Top = 64
    Width = 105
    Height = 21
    TabOrder = 4
  end
  object PathLengthEdit: TEdit
    Left = 344
    Top = 64
    Width = 105
    Height = 21
    TabOrder = 5
  end
  object StopFromEdit: TEdit
    Left = 72
    Top = 8
    Width = 377
    Height = 21
    Enabled = False
    TabOrder = 0
  end
  object StopFromButton: TButton
    Left = 452
    Top = 8
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 1
    OnClick = StopFromButtonClick
  end
  object StopToEdit: TEdit
    Left = 72
    Top = 37
    Width = 377
    Height = 21
    Enabled = False
    TabOrder = 2
  end
  object StopToButton: TButton
    Left = 452
    Top = 37
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 3
    OnClick = StopToButtonClick
  end
  object VStringStorage: TVStringStorage
    Lines.Strings = (
      'Введите '
      'код начального пункта'
      'код конечного пункта'
      'Начального пункта не существует'
      'Конечного пункта не существует'
      'Некорректное значение нормальной скорости'
      'Некорректное значение расстояния'
      'Код'
      'Название')
    Left = 280
    Top = 121
  end
  object StopDataSource: TDataSource
    DataSet = StopQuery
    Left = 38
    Top = 124
  end
  object StopQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' stop_id,'
      ' stop_name'
      'FROM'
      ' stop')
    Left = 5
    Top = 124
  end
end
