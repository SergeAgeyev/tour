inherited TourStopOwnerSimpleProcessForm: TTourStopOwnerSimpleProcessForm
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
  object StopOwnerLabel: TLabel [1]
    Left = 22
    Top = 11
    Width = 76
    Height = 13
    Caption = 'Код владельца'
  end
  object StopOwnerNameLabel: TLabel [2]
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
  object StopOwnerEdit: TEdit [5]
    Left = 104
    Top = 8
    Width = 90
    Height = 21
    MaxLength = 15
    TabOrder = 0
  end
  object StopOwnerNameEdit: TEdit [6]
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
      'Введите код владельца ост.пункта'
      
        'Поле "Код владельца ост.пункта" является ключевым. Его присутств' +
        'ие обязательно.')
    Top = 96
  end
end
