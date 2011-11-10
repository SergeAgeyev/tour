inherited TourPathSimpleEditForm: TTourPathSimpleEditForm
  Caption = 'Редактирование информации об участке пути'
  PixelsPerInch = 96
  TextHeight = 13
  inherited CancelButton: TButton
    Caption = 'Отмена'
  end
  inherited OkButton: TButton
    Caption = 'Сохранить'
  end
  inherited SpeedEdit: TEdit
    Enabled = False
  end
end
