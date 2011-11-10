inherited TourPathViewForm: TTourPathViewForm
  Caption = 'Участки пути'
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
        Caption = 'Код нач.пункта'
        FieldName = 'path_fromstopid'
      end
      item
        Caption = 'Код кон.пункта'
        FieldName = 'path_tostopid'
      end
      item
        Caption = 'Расстояние'
        FieldName = 'path_length'
      end
      item
        Caption = 'Норм.скорость'
        FieldName = 'path_normspeed'
      end>
  end
  inherited MainQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' path_fromstopid,'
      ' path_tostopid,'
      ' path_length,'
      ' path_normspeed'
      'FROM'
      ' paths'
      ' ')
    object MainQueryPath_fromstopid: TStringField
      DisplayLabel = 'Код нач.пункта'
      FieldName = 'path_fromstopid'
      Size = 10
    end
    object MainQueryfromstopid_name: TStringField
      DisplayLabel = 'Начальный пункт'
      FieldKind = fkLookup
      FieldName = 'fromstopid_name'
      LookupDataSet = StopQuery
      LookupKeyFields = 'stop_id'
      LookupResultField = 'stop_name'
      KeyFields = 'path_fromstopid'
      Size = 50
      Lookup = True
    end
    object MainQueryPath_tostopid: TStringField
      DisplayLabel = 'Код кон.пункта'
      FieldName = 'path_tostopid'
      Size = 10
    end
    object MainQuerytostopid_name: TStringField
      DisplayLabel = 'Конечный пункт'
      FieldKind = fkLookup
      FieldName = 'tostopid_name'
      LookupDataSet = StopQuery
      LookupKeyFields = 'stop_id'
      LookupResultField = 'stop_name'
      KeyFields = 'Path_tostopid'
      Size = 50
      Lookup = True
    end
    object MainQuerypath_length: TFloatField
      DisplayLabel = 'Расстояние'
      FieldName = 'path_length'
    end
    object MainQuerypath_normspeed: TFloatField
      DisplayLabel = 'Норм.скорость'
      FieldName = 'path_normspeed'
    end
  end
  object StopQuery: TADOQuery [12]
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' stop_id,'
      ' stop_name'
      'FROM'
      ' stop')
    Left = 64
    Top = 296
  end
end
