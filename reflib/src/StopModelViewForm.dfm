inherited TourRefBookStopModelViewForm: TTourRefBookStopModelViewForm
  Caption = '���� ������������ �������'
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
        FieldName = 'stop_model'
      end
      item
        Caption = '������������'
        FieldName = 'stopmodel_name'
      end>
  end
  inherited MainQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' stop_model,'
      ' stopmodel_name'
      'FROM'
      ' stopmodel'
      ' ')
    object MainQueryStopModel_id: TStringField
      DisplayLabel = '���'
      DisplayWidth = 5
      FieldName = 'stop_model'
      Size = 5
    end
    object MainQueryStopModel_name: TStringField
      DisplayLabel = '������������'
      FieldName = 'stopmodel_name'
      Size = 50
    end
  end
end
