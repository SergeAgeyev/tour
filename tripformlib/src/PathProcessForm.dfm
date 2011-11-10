inherited TourPathProcessForm: TTourPathProcessForm
  Left = 250
  ClientHeight = 155
  ClientWidth = 483
  OldCreateOrder = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object PathNormSpeedLabel: TLabel [0]
    Left = 18
    Top = 66
    Width = 48
    Height = 13
    Caption = 'Скорость'
  end
  object PathFromStopIdLabel: TLabel [1]
    Left = 16
    Top = 11
    Width = 50
    Height = 13
    Caption = 'Нач.пункт'
  end
  object PathLengthLabel: TLabel [2]
    Left = 303
    Top = 67
    Width = 60
    Height = 13
    Caption = 'Расстояние'
  end
  object PathToStopIdIdLabel: TLabel [3]
    Left = 16
    Top = 39
    Width = 50
    Height = 13
    Caption = 'Кон.пункт'
  end
  inherited CancelButton: TButton
    Left = 402
    Top = 124
    TabOrder = 5
  end
  inherited SaveButton: TButton
    Left = 322
    Top = 124
    TabOrder = 4
  end
  object PathLengthDBEdit: TDBEdit [6]
    Left = 371
    Top = 64
    Width = 104
    Height = 21
    DataField = 'path_length'
    DataSource = FMainQueryDataSource
    TabOrder = 3
  end
  object PathFlowDBEdit: TDBEdit [7]
    Left = 73
    Top = 64
    Width = 104
    Height = 21
    DataField = 'path_normspeed'
    DataSource = FMainQueryDataSource
    TabOrder = 2
  end
  object PathFromStopIdDBLookupComboBoxExt: TDBLookupComboBoxExt [8]
    Left = 73
    Top = 8
    Width = 404
    Height = 21
    DataField = 'path_fromstopid'
    DataSource = FMainQueryDataSource
    KeyField = 'stop_id'
    ListField = 'stop_name;stop_id'
    ListSource = StopDataSource
    TabOrder = 0
  end
  object PathToStopIdDBLookupComboBoxExt: TDBLookupComboBoxExt [9]
    Left = 73
    Top = 36
    Width = 404
    Height = 21
    DataField = 'path_tostopid'
    DataSource = FMainQueryDataSource
    KeyField = 'stop_id'
    ListField = 'stop_name;stop_id'
    ListSource = StopDataSource
    TabOrder = 1
  end
  inherited FMainQueryDataSource: TDataSource
    Left = 3
    Top = 124
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Введите '
      'код начального пункта'
      'код конечного пункта'
      'Некорректное значение нормальной скорости'
      'Некорректное значение расстояния')
    Left = 280
    Top = 121
  end
  object StopDataSource: TDataSource
    Left = 38
    Top = 124
  end
end
