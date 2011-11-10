inherited TourTripSimpleAddForm: TTourTripSimpleAddForm
  Caption = 'Новый населенный пункт'
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
      'Введите код рейса'
      'Поле "Код рейса" является ключевым. Его присутствие обязательно.'
      'Ошибка при добавлении нового автобуса'
      'Ошибка при добавлении нового владельца рейса'
      'Ошибка при создании формы'
      'Данный код рейса уже существует.'
      
        'Поле "Код рейса" является единственным ключевым полем. Его значе' +
        'ние  должно быть уникально.')
  end
end
