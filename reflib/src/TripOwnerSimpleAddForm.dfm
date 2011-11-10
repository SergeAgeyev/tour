inherited TourTripOwnerSimpleAddForm: TTourTripOwnerSimpleAddForm
  Caption = 'Новый перевозчик'
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
      'Введите код перевозчика'
      
        'Поле "Код перевозчика" является ключевым. Его присутствие обязат' +
        'ельно.'
      'Перевозчик с таким кодом уже существует.'
      
        'Поле "Код перевозчика" является единственным ключевым полем. Его' +
        ' значение  должно быть уникально.')
  end
end
