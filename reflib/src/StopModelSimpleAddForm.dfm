inherited TourStopModelSimpleAddForm: TTourStopModelSimpleAddForm
  Caption = 'Новая модель остановочного пункта'
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
      'Введите модель остановочного пункта'
      
        'Поле "Модель ост.пункта" является ключевым. Его присутствие обяз' +
        'ательно.'
      'Данная модель ост.пункта уже существует.'
      
        'Поле "Модель ост.пункта" является единственным ключевым полем. Е' +
        'го значение  должно быть уникально.')
  end
end
