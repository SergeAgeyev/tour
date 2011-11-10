inherited TourTripOwnerSimpleEditForm: TTourTripOwnerSimpleEditForm
  Caption = 'Редактирование информации о перевозчике'
  PixelsPerInch = 96
  TextHeight = 13
  inherited CancelButton: TButton
    Caption = 'Отмена'
  end
  inherited OkButton: TButton
    Caption = 'Сохранить'
  end
  inherited TripOwnerEdit: TEdit
    Enabled = False
  end
end
