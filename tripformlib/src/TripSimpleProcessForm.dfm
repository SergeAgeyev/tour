inherited TourTripSimpleProcessForm: TTourTripSimpleProcessForm
  ClientHeight = 213
  OldCreateOrder = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  inherited Bevel: TBevel
    Height = 177
    Shape = bsBox
    Style = bsRaised
  end
  object TripLabel: TLabel [1]
    Left = 78
    Top = 11
    Width = 19
    Height = 13
    Caption = 'Код'
  end
  object TripNotesLabel: TLabel [2]
    Left = 35
    Top = 146
    Width = 63
    Height = 13
    Caption = 'Примечание'
  end
  object BusModelLabel: TLabel [3]
    Left = 56
    Top = 81
    Width = 41
    Height = 13
    Caption = 'Автобус'
  end
  object TripOwnerLabel: TLabel [4]
    Left = 49
    Top = 113
    Width = 49
    Height = 13
    Caption = 'Владелец'
  end
  object TripNameLabel: TLabel [5]
    Left = 47
    Top = 42
    Width = 50
    Height = 13
    Caption = 'Название'
  end
  inherited CancelButton: TButton
    Left = 440
    Top = 184
    TabOrder = 8
  end
  inherited OkButton: TButton
    Left = 360
    Top = 184
    TabOrder = 7
  end
  object TripIdEdit: TEdit [8]
    Left = 104
    Top = 8
    Width = 123
    Height = 21
    MaxLength = 15
    TabOrder = 0
  end
  object TripNotesEdit: TEdit [9]
    Left = 104
    Top = 144
    Width = 403
    Height = 21
    MaxLength = 50
    TabOrder = 4
  end
  object BusModelVMemoKeyComboBox: TVMemoKeyComboBox [10]
    Left = 104
    Top = 80
    Width = 404
    Height = 21
    FormatString = '[%s] %s'
    EmptyString = '<значение не определено>'
    CanEmpty = True
    TabOrder = 2
    Items = <>
  end
  object TripOwnerVMemoKeyComboBox: TVMemoKeyComboBox [11]
    Left = 104
    Top = 112
    Width = 404
    Height = 21
    FormatString = '[%s] %s'
    EmptyString = '<значение не определено>'
    CanEmpty = True
    TabOrder = 3
    Items = <>
  end
  object TripNameEdit: TEdit [12]
    Left = 104
    Top = 40
    Width = 403
    Height = 21
    MaxLength = 50
    TabOrder = 1
  end
  object AddBusButton: TButton [13]
    Left = 0
    Top = 184
    Width = 105
    Height = 25
    Caption = 'Новый автобус'
    TabOrder = 5
    OnClick = AddBusButtonClick
  end
  object AddTripOwnerButton: TButton [14]
    Left = 112
    Top = 184
    Width = 153
    Height = 25
    Caption = 'Новый владелец рейса'
    TabOrder = 6
    OnClick = AddTripOwnerButtonClick
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Значение не является величиной целого типа'
      'Тип вводимого значения должен быть типа Integer'
      'Значение не является величиной дробного типа'
      'Тип вводимого значения должен быть типа Float'
      'Введите код рейса'
      'Поле "Код рейса" является ключевым. Его присутствие обязательно.'
      'Ошибка при добавлении нового автобуса'
      'Ошибка при добавлении нового владельца рейса'
      'Ошибка при создании формы')
    Top = 184
  end
end
