inherited TourStopOwnerSimpleEditForm: TTourStopOwnerSimpleEditForm
  Caption = 'Редактирование информации о владельце ост.пункта'
  PixelsPerInch = 96
  TextHeight = 13
  inherited CancelButton: TButton
    Caption = 'Отмена'
  end
  inherited OkButton: TButton
    Caption = 'Сохранить'
  end
  inherited StopOwnerEdit: TEdit
    Enabled = False
  end
end
