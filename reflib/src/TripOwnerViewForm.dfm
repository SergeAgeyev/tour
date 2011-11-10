inherited TourRefBookTripOwnerViewForm: TTourRefBookTripOwnerViewForm
  Caption = 'Перевозчики'
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited ToolBar: TToolBar
    Visible = True
  end
  inherited ActionList: TActionList
    inherited NewAction: TAction
      OnExecute = NewActionExecute
    end
    inherited EditAction: TAction
      OnExecute = EditActionExecute
    end
  end
  inherited MainDBGridFilterDialog: TVDBGridFilterDialog
    Fields = <
      item
        Caption = 'Код'
        FieldName = 'tripowner_id'
      end
      item
        Caption = 'Наименование'
        FieldName = 'tripowner_name'
      end>
  end
  inherited MainQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' tripowner_id,'
      ' tripowner_name'
      'FROM'
      ' tripowner'
      ' ')
    object MainQueryTripOwner_id: TStringField
      DisplayLabel = 'Код'
      FieldName = 'tripowner_id'
      Size = 10
    end
    object MainQueryTripOwner_name: TStringField
      DisplayLabel = 'Наименование'
      FieldName = 'tripowner_name'
      Size = 50
    end
  end
end
