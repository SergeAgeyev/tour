inherited TourRefBookStopOwnerViewForm: TTourRefBookStopOwnerViewForm
  Caption = '��������� ������������ �������'
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
        FieldName = 'stopowner_id'
      end
      item
        Caption = '������������'
        FieldName = 'stopowner_name'
      end>
  end
  inherited MainQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' stopowner_id,'
      ' stopowner_name'
      'FROM'
      ' stopowner'
      ' ')
    object MainQuerystopowner_id: TStringField
      DisplayLabel = '���'
      FieldName = 'stopowner_id'
      Size = 10
    end
    object MainQuerystopowner_name: TStringField
      DisplayLabel = '������������'
      FieldName = 'stopowner_name'
      Size = 50
    end
  end
end
