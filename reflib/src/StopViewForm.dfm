inherited TourRefBookStopViewForm: TTourRefBookStopViewForm
  Caption = 'Остановочные пункты'
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
        Caption = 'Код ост.пункта'
        FieldName = 'stop_id'
      end
      item
        Caption = 'Код насел.пункта'
        FieldName = 'city_zip'
      end
      item
        Caption = 'Код владельца ост.пункта'
        FieldName = 'stopowner_id'
      end
      item
        Caption = 'Тип ост.пункта'
        FieldName = 'stop_model'
      end
      item
        Caption = 'Название ост.пункта'
        FieldName = 'stop_name'
      end>
  end
  inherited MainQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' stop_id,'
      ' city_zip,'
      ' stop_model,'
      ' stopowner_id,'
      ' stop_name'
      'FROM'
      ' stop'
      ' ')
    object MainQuerystop_id: TStringField
      DisplayLabel = 'Код ост.пункта'
      FieldName = 'stop_id'
      Size = 10
    end
    object MainQuerystop_name: TStringField
      DisplayLabel = 'Название ост.пункта'
      FieldName = 'stop_name'
      Size = 50
    end
    object MainQuerycity_zip: TStringField
      DisplayLabel = 'Код насел.пункта'
      FieldName = 'city_zip'
      Size = 10
    end
    object MainQuerycity_name: TStringField
      DisplayLabel = 'Название насел.пункта'
      FieldKind = fkLookup
      FieldName = 'city_name'
      LookupDataSet = CityQuery
      LookupKeyFields = 'city_zip'
      LookupResultField = 'city_name'
      KeyFields = 'city_zip'
      Size = 50
      Lookup = True
    end
    object MainQuerystop_model: TStringField
      DisplayLabel = 'Тип ост.пункта'
      FieldName = 'stop_model'
      Size = 5
    end
    object MainQuerystopmodel_name: TStringField
      DisplayLabel = 'Название типа ост.пункта'
      FieldKind = fkLookup
      FieldName = 'stopmodel_name'
      LookupDataSet = StopModelQuery
      LookupKeyFields = 'stop_model'
      LookupResultField = 'stopmodel_name'
      KeyFields = 'stop_model'
      Size = 50
      Lookup = True
    end
    object MainQuerystopowner_id: TStringField
      DisplayLabel = 'Код владельца ост.пункта'
      FieldName = 'stopowner_id'
      Size = 10
    end
    object MainQuerystopowner_name: TStringField
      DisplayLabel = 'Имя владельца ост.пункта'
      FieldKind = fkLookup
      FieldName = 'stopowner_name'
      LookupDataSet = StopOwnerQuery
      LookupKeyFields = 'stopowner_id'
      LookupResultField = 'stopowner_name'
      KeyFields = 'stopowner_id'
      Size = 50
      Lookup = True
    end
  end
  object StopOwnerQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' stopowner_id,'
      ' stopowner_name'
      'FROM'
      ' stopowner')
    Left = 64
    Top = 296
  end
  object StopModelQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' stop_model,'
      ' stopmodel_name'
      'FROM'
      ' stopmodel')
    Left = 96
    Top = 296
  end
  object CityQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' city_zip,'
      ' city_name'
      'FROM'
      ' city')
    Left = 128
    Top = 296
  end
end
