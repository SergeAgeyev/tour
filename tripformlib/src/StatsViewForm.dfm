inherited TourStatsViewForm: TTourStatsViewForm
  Caption = 'Статистика перевозок'
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
        Caption = 'Рейс'
        FieldName = 'trip_id'
      end
      item
        Caption = 'Код нач.пункта'
        FieldName = 'stats_fromstopid'
      end
      item
        Caption = 'Код кон.пункта'
        FieldName = 'stats_tostopid'
      end
      item
        Caption = 'Примечание к рейсу'
        FieldName = 'trip_notes'
      end
      item
        Caption = 'Кол-во'
        FieldName = 'stats_flow'
      end>
  end
  inherited MainQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' trip_id,'
      ' stats_date,'
      ' stats_fromstopid,'
      ' stats_tostopid,'
      ' stats_flow'
      'FROM'
      ' stats'
      ' ')
    object MainQuerytrip_id: TStringField
      DisplayLabel = 'Рейс'
      FieldName = 'trip_id'
      Size = 10
    end
    object MainQuerytrip_name: TStringField
      DisplayLabel = 'Название рейса'
      FieldKind = fkLookup
      FieldName = 'trip_name'
      LookupDataSet = TripQuery
      LookupKeyFields = 'trip_id'
      LookupResultField = 'trip_name'
      KeyFields = 'trip_id'
      Size = 50
      Lookup = True
    end
    object MainQuerytrip_notes: TStringField
      DisplayLabel = 'Примечания к рейсу'
      FieldKind = fkLookup
      FieldName = 'trip_notes'
      LookupDataSet = TripQuery
      LookupKeyFields = 'trip_id'
      LookupResultField = 'trip_notes'
      KeyFields = 'trip_id'
      Size = 50
      Lookup = True
    end
    object MainQuerystats_date: TDateTimeField
      DisplayLabel = 'Дата'
      FieldName = 'stats_date'
    end
    object MainQuerystats_fromstopid: TStringField
      DisplayLabel = 'Код нач.пункта'
      FieldName = 'stats_fromstopid'
      Size = 10
    end
    object MainQueryfromstopid_name: TStringField
      DisplayLabel = 'Начальный пункта'
      FieldKind = fkLookup
      FieldName = 'fromstopid_name'
      LookupDataSet = StopQuery
      LookupKeyFields = 'stop_id'
      LookupResultField = 'stop_name'
      KeyFields = 'stats_fromstopid'
      Size = 50
      Lookup = True
    end
    object MainQuerystats_tostopid: TStringField
      DisplayLabel = 'Код кон.пункта'
      FieldName = 'stats_tostopid'
      Size = 10
    end
    object MainQuerytostopid_name: TStringField
      DisplayLabel = 'Конечный пункт'
      FieldKind = fkLookup
      FieldName = 'tostopid_name'
      LookupDataSet = StopQuery
      LookupKeyFields = 'stop_id'
      LookupResultField = 'stop_name'
      KeyFields = 'stats_tostopid'
      Size = 50
      Lookup = True
    end
    object MainQuerystats_flow: TIntegerField
      DisplayLabel = 'Кол-во'
      FieldName = 'stats_flow'
    end
  end
  object TripQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' trip_name,'
      ' trip_id,'
      ' trip_notes'
      'FROM'
      ' trip'
      'ORDER BY '
      ' trip_name')
    Left = 64
    Top = 296
  end
  object StopQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' stop_id,'
      ' stop_name'
      'FROM'
      ' stop')
    Left = 96
    Top = 296
  end
end
