inherited TourRefBookRegionViewForm: TTourRefBookRegionViewForm
  Caption = '�������'
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
        Caption = '���'
        FieldName = 'region_id'
      end
      item
        Caption = '������������'
        FieldName = 'region_name'
      end>
  end
  inherited MainQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' region_id,'
      ' region_name'
      'FROM'
      ' region'
      ' ')
    object MainQueryRegion_id: TStringField
      DisplayLabel = '���'
      FieldName = 'region_id'
      Size = 10
    end
    object MainQueryRegion_name: TStringField
      DisplayLabel = '������������'
      FieldName = 'region_name'
      Size = 50
    end
  end
end
