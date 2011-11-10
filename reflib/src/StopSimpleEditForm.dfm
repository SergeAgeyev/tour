inherited TourStopSimpleEditForm: TTourStopSimpleEditForm
  Caption = 'Редактирование информации о населенном пункте'
  PixelsPerInch = 96
  TextHeight = 13
  inherited CancelButton: TButton
    Caption = 'Отмена'
  end
  inherited OkButton: TButton
    Caption = 'Сохранить'
  end
  inherited StopIdEdit: TEdit
    Enabled = False
  end
end
