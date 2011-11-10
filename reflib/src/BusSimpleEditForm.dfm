inherited TourBusSimpleEditForm: TTourBusSimpleEditForm
  Caption = 'Редактирование информации об автобусе'
  PixelsPerInch = 96
  TextHeight = 13
  inherited CancelButton: TButton
    Caption = 'Отмена'
  end
  inherited OkButton: TButton
    Caption = 'Сохранить'
  end
  inherited BusModelEdit: TEdit
    Enabled = False
  end
end
