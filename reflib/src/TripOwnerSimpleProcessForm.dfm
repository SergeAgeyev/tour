inherited TourTripOwnerSimpleProcessForm: TTourTripOwnerSimpleProcessForm
  ClientHeight = 129
  OldCreateOrder = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  inherited Bevel: TBevel
    Height = 81
    Shape = bsBox
    Style = bsRaised
  end
  object TripOwnerLabel: TLabel [1]
    Left = 78
    Top = 11
    Width = 19
    Height = 13
    Caption = 'Код'
  end
  object TripOwnerNameLabel: TLabel [2]
    Left = 48
    Top = 42
    Width = 50
    Height = 13
    Caption = 'Описание'
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
  object TripOwnerEdit: TEdit [5]
    Left = 104
    Top = 8
    Width = 90
    Height = 21
    MaxLength = 15
    TabOrder = 0
  end
  object TripOwnerNameEdit: TEdit [6]
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
      'Введите код перевозчика'
      
        'Поле "Код перевозчика" является ключевым. Его присутствие обязат' +
        'ельно.')
    Top = 96
  end
end
