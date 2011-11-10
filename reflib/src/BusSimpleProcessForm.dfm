inherited TourBusSimpleProcessForm: TTourBusSimpleProcessForm
  ClientHeight = 151
  OldCreateOrder = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  inherited Bevel: TBevel
    Height = 113
    Shape = bsBox
    Style = bsRaised
  end
  object BusModelLabel: TLabel [1]
    Left = 64
    Top = 11
    Width = 33
    Height = 13
    Caption = 'Марка'
  end
  object BusDescLabel: TLabel [2]
    Left = 48
    Top = 74
    Width = 50
    Height = 13
    Caption = 'Описание'
  end
  object BusSpeedFactorLabel: TLabel [3]
    Left = 252
    Top = 41
    Width = 120
    Height = 13
    Caption = 'Коэффициент скорости'
  end
  object BusCapaBusLabel: TLabel [4]
    Left = 8
    Top = 42
    Width = 90
    Height = 13
    Caption = 'Вместительность'
  end
  inherited CancelButton: TButton
    Left = 440
    Top = 120
    TabOrder = 5
  end
  inherited OkButton: TButton
    Left = 360
    Top = 120
    TabOrder = 4
  end
  object BusModelEdit: TEdit [7]
    Left = 104
    Top = 8
    Width = 123
    Height = 21
    MaxLength = 15
    TabOrder = 0
  end
  object BusDescEdit: TEdit [8]
    Left = 104
    Top = 72
    Width = 403
    Height = 21
    MaxLength = 50
    TabOrder = 3
  end
  object BusSpeedFactorEdit: TEdit [9]
    Left = 384
    Top = 40
    Width = 123
    Height = 21
    TabOrder = 2
  end
  object BusCapacityEdit: TEdit [10]
    Left = 104
    Top = 40
    Width = 123
    Height = 21
    TabOrder = 1
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Значение не является величиной целого типа'
      'Тип вводимого значения должен быть типа Integer'
      'Значение не является величиной дробного типа'
      'Тип вводимого значения должен быть типа Float'
      'Введите модель автобуса'
      
        'Поле "Модель автобуса" является ключевым. Его присутствие обязат' +
        'ельно.')
    Top = 120
  end
end
