inherited TourRegionSimpleAddForm: TTourRegionSimpleAddForm
  Caption = 'Новый регион'
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
      'Введите код региона'
      
        'Поле "Код региона" является ключевым. Его присутствие обязательн' +
        'о.'
      'Регион с таким кодом уже существует.'
      
        'Поле "Код региона" является единственным ключевым полем. Его зна' +
        'чение должно быть уникально.')
  end
end
