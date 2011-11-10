inherited TourRegionSimpleEditForm: TTourRegionSimpleEditForm
  Caption = 'Редактирование информации о регионе'
  PixelsPerInch = 96
  TextHeight = 13
  inherited CancelButton: TButton
    Caption = 'Отмена'
  end
  inherited OkButton: TButton
    Caption = 'Сохранить'
  end
  inherited RegionIdEdit: TEdit
    Enabled = False
  end
end
