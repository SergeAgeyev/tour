inherited TourRefBookBusViewForm: TTourRefBookBusViewForm
  Caption = '���� ����������'
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
        Caption = '�����'
        FieldName = 'bus_model'
      end
      item
        Caption = '��������'
        FieldName = 'bus_desc'
      end
      item
        Caption = '���������������'
        FieldName = 'bus_capacity'
      end
      item
        Caption = '��������'
        FieldName = 'bus_speedfactor'
      end>
  end
  inherited MainQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' bus_model,'
      ' bus_desc,'
      ' bus_capacity,'
      ' bus_speedfactor'
      'FROM'
      ' bus'
      ' ')
    object MainQuerybus_model: TStringField
      DisplayLabel = '�����'
      FieldName = 'bus_model'
      Size = 15
    end
    object MainQuerybus_desc: TStringField
      DisplayLabel = '��������'
      FieldName = 'bus_desc'
      Size = 50
    end
    object MainQuerybus_capacity: TIntegerField
      DisplayLabel = '���������������'
      FieldName = 'bus_capacity'
    end
    object MainQuerybus_speedfactor: TFloatField
      DisplayLabel = '��������'
      FieldName = 'bus_speedfactor'
    end
  end
end
