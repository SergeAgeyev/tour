inherited TourCitySimpleAddForm: TTourCitySimpleAddForm
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
      'Введите код населенного пункта'
      
        'Поле "Код населенного пункта" является ключевым. Его присутствие' +
        ' обязательно.'
      'Ошибка при добавлении нового региона'
      'Ошибка при создании формы'
      'Данный код населенного пункта уже существует.'
      
        'Поле "Код населенного пункта" является единственным ключевым пол' +
        'ем. Его значение  должно быть уникально.')
  end
end
