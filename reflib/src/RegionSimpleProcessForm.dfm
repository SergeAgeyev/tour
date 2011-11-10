inherited TourRegionSimpleProcessForm: TTourRegionSimpleProcessForm
  ClientHeight = 130
  OldCreateOrder = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  inherited Bevel: TBevel
    Height = 81
    Shape = bsBox
    Style = bsRaised
  end
  object RegionIdLabel: TLabel [1]
    Left = 76
    Top = 11
    Width = 19
    Height = 13
    Caption = 'Код'
  end
  object RegionNameLabel: TLabel [2]
    Left = 48
    Top = 42
    Width = 50
    Height = 13
    Caption = 'Название'
  end
  inherited CancelButton: TButton
    Left = 440
    Top = 96
    TabOrder = 3
  end
  inherited OkButton: TButton
    Left = 360
    Top = 96
    TabOrder = 2
  end
  object RegionIdEdit: TEdit [5]
    Left = 104
    Top = 8
    Width = 83
    Height = 21
    MaxLength = 10
    TabOrder = 0
  end
  object RegionNameEdit: TEdit [6]
    Left = 104
    Top = 40
    Width = 403
    Height = 21
    MaxLength = 50
    TabOrder = 1
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Значение не является величиной целого типа'
      'Тип вводимого значения должен быть типа Integer'
      'Значение не является величиной дробного типа'
      'Тип вводимого значения должен быть типа Float'
      'Введите код региона'
      
        'Поле "Код региона" является ключевым. Его присутствие обязательн' +
        'о.')
    Top = 96
  end
end
