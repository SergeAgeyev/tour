inherited TourBusSimpleAddForm: TTourBusSimpleAddForm
  Caption = 'Новый автобус'
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
      'Введите модель автобуса'
      
        'Поле "Модель автобуса" является ключевым. Его присутствие обязат' +
        'ельно.'
      'Данная модель автобуса уже существует.'
      
        'Поле "Модель автобуса" является единственным ключевым полем. Его' +
        ' значение  должно быть уникально.')
  end
end
