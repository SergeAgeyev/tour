inherited TourStopOwnerSimpleAddForm: TTourStopOwnerSimpleAddForm
  Caption = 'Новый владельц ост.пункта'
  PixelsPerInch = 96
  TextHeight = 13
  inherited CancelButton: TButton
    Caption = 'Отмена'
  end
  inherited OkButton: TButton
    Caption = 'Сохранить'
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Значение не является величиной целого типа'
      'Тип вводимого значения должен быть типа Integer'
      'Значение не является величиной дробного типа'
      'Тип вводимого значения должен быть типа Float'
      'Введите код владельца ост.пункта'
      
        'Поле "Код владельца ост.пункта" является ключевым. Его присутств' +
        'ие обязательно.'
      'Владельц ост.пункта с таким кодом уже существует.'
      
        'Поле "Код владельца ост.пункта" является единственным ключевым п' +
        'олем. Его значение  должно быть уникально.')
  end
end
