inherited TourRefBookBusProcessForm: TTourRefBookBusProcessForm
  ClientHeight = 149
  ClientWidth = 497
  OldCreateOrder = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object BusModelLabel: TLabel [0]
    Left = 47
    Top = 12
    Width = 33
    Height = 13
    Caption = 'Марка'
  end
  object BusDescLabel: TLabel [1]
    Left = 30
    Top = 38
    Width = 50
    Height = 13
    Caption = 'Описание'
  end
  object BusSpeedFactorLabel: TLabel [2]
    Left = 4
    Top = 67
    Width = 77
    Height = 13
    Caption = 'Коэф.скорости'
  end
  object BusCapacityLabel: TLabel [3]
    Left = 267
    Top = 67
    Width = 90
    Height = 13
    Caption = 'Вместительность'
  end
  inherited CancelButton: TButton
    Left = 416
    Top = 119
    TabOrder = 5
  end
  inherited SaveButton: TButton
    Left = 336
    Top = 119
    TabOrder = 4
  end
  object BusModelDBEdit: TDBEdit [6]
    Left = 87
    Top = 8
    Width = 123
    Height = 21
    DataField = 'bus_model'
    DataSource = FMainQueryDataSource
    MaxLength = 15
    TabOrder = 0
  end
  object BusDescDBEdit: TDBEdit [7]
    Left = 87
    Top = 36
    Width = 403
    Height = 21
    DataField = 'bus_desc'
    DataSource = FMainQueryDataSource
    MaxLength = 50
    TabOrder = 1
  end
  object BusSpeedFactorDBEdit: TDBEdit [8]
    Left = 87
    Top = 64
    Width = 123
    Height = 21
    DataField = 'bus_speedfactor'
    DataSource = FMainQueryDataSource
    TabOrder = 2
  end
  object BusCapacityDBEdit: TDBEdit [9]
    Left = 367
    Top = 64
    Width = 123
    Height = 21
    DataField = 'bus_capacity'
    DataSource = FMainQueryDataSource
    TabOrder = 3
  end
  inherited FMainQueryDataSource: TDataSource
    Left = 7
    Top = 116
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Введите '
      'тип транспорта'
      'Неккоректное значение коэффициента скорости'
      'Неккоректное значение вместительности'
      '')
    Left = 44
    Top = 116
  end
end
