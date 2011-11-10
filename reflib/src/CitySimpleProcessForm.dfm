inherited TourCitySimpleProcessForm: TTourCitySimpleProcessForm
  ClientHeight = 148
  OldCreateOrder = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  inherited Bevel: TBevel
    Height = 113
    Shape = bsBox
    Style = bsRaised
  end
  object CityZIPlLabel: TLabel [1]
    Left = 78
    Top = 11
    Width = 19
    Height = 13
    Caption = 'Код'
  end
  object CityNameLabel: TLabel [2]
    Left = 48
    Top = 74
    Width = 50
    Height = 13
    Caption = 'Описание'
  end
  object CityPopulationLabel: TLabel [3]
    Left = 310
    Top = 12
    Width = 56
    Height = 13
    Caption = 'Население'
  end
  object RegionIdLabel: TLabel [4]
    Left = 59
    Top = 41
    Width = 36
    Height = 13
    Caption = 'Регион'
  end
  inherited CancelButton: TButton
    Left = 440
    Top = 120
    TabOrder = 6
  end
  inherited OkButton: TButton
    Left = 360
    Top = 120
    TabOrder = 5
  end
  object CityZIPEdit: TEdit [7]
    Left = 104
    Top = 8
    Width = 123
    Height = 21
    MaxLength = 15
    TabOrder = 0
  end
  object CityNameEdit: TEdit [8]
    Left = 104
    Top = 72
    Width = 403
    Height = 21
    MaxLength = 50
    TabOrder = 3
  end
  object CityPopulationEdit: TEdit [9]
    Left = 384
    Top = 8
    Width = 123
    Height = 21
    TabOrder = 1
  end
  object CityRegionVMemoKeyComboBox: TVMemoKeyComboBox [10]
    Left = 104
    Top = 40
    Width = 404
    Height = 21
    FormatString = '[%s] %s'
    EmptyString = '<значение не определено>'
    CanEmpty = True
    TabOrder = 2
    Items = <>
  end
  object AddRegionButton: TButton [11]
    Left = 0
    Top = 120
    Width = 113
    Height = 25
    Caption = 'Новый регион'
    TabOrder = 4
    OnClick = AddRegionButtonClick
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Значение не является величиной целого типа'
      'Тип вводимого значения должен быть типа Integer'
      'Значение не является величиной дробного типа'
      'Тип вводимого значения должен быть типа Float'
      'Введите код населенного пункта'
      
        'Поле "Код населенного пункта" является ключевым. Его присутствие' +
        ' обязательно.'
      'Ошибка при добавлении нового региона'
      'Ошибка при создании формы')
    Top = 120
  end
end
