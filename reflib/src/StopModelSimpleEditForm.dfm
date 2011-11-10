inherited TourStopModelSimpleEditForm: TTourStopModelSimpleEditForm
  Caption = 'Редактирование информации о модели остановочного пункта'
  PixelsPerInch = 96
  TextHeight = 13
  inherited CancelButton: TButton
    Caption = 'Отмена'
  end
  inherited OkButton: TButton
    Caption = 'Сохранить'
  end
  inherited StopModelEdit: TEdit
    Enabled = False
  end
end
