inherited TourRefBookBusViewForm: TTourRefBookBusViewForm
  Caption = 'Виды транспорта'
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
        Caption = 'Марка'
        FieldName = 'bus_model'
      end
      item
        Caption = 'Описание'
        FieldName = 'bus_desc'
      end
      item
        Caption = 'Вместительность'
        FieldName = 'bus_capacity'
      end
      item
        Caption = 'Скорость'
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
      DisplayLabel = 'Марка'
      FieldName = 'bus_model'
      Size = 15
    end
    object MainQuerybus_desc: TStringField
      DisplayLabel = 'Описание'
      FieldName = 'bus_desc'
      Size = 50
    end
    object MainQuerybus_capacity: TIntegerField
      DisplayLabel = 'Вместительность'
      FieldName = 'bus_capacity'
    end
    object MainQuerybus_speedfactor: TFloatField
      DisplayLabel = 'Скорость'
      FieldName = 'bus_speedfactor'
    end
  end
end
