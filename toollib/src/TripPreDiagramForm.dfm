inherited TourTripPreDiagramForm: TTourTripPreDiagramForm
  Caption = 'Мастер маршрута'
  OldCreateOrder = True
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  inherited AvailableListView: TListView
    OnDblClick = AvailableAddActionExecute
  end
  inherited ToAvailableQuery: TADOQuery
    Parameters = <
      item
        Name = 'fromstop_id'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT'
      ' path_tostopid as stop_id'
      'FROM'
      ' paths'
      'WHERE'
      ' :fromstop_id = paths.path_fromstopid')
  end
  inherited ActionList: TActionList
    inherited ChainDeleteItemAction: TAction
      OnExecute = ChainDeleteItemActionExecute
    end
    inherited AvailableAddAction: TAction
      OnExecute = AvailableAddActionExecute
    end
    inherited SelectAction: TAction
      OnExecute = SelectActionExecute
    end
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Выбор рейса'
      'Рейс'
      'Название'
      'Примечание'
      'Неккорректный маршрут')
    Top = 352
  end
  inherited TripQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' trip_id,'
      ' trip_name,'
      ' trip_notes'
      'FROM'
      ' trip'
      'ORDER BY'
      ' trip_name')
  end
  inherited TripStepQuery: TADOQuery
    Parameters = <
      item
        Name = 'trip_id_value'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT'
      ' trip_id,'
      ' tripstep_num,'
      ' stop_id,'
      ' path_tostopid'
      'FROM'
      ' tripstep'
      'WHERE'
      ' trip_id = :trip_id_value'
      'ORDER BY'
      ' tripstep_num')
  end
  inherited StopQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' stop_id,'
      ' stop_name'
      'FROM'
      ' stop')
  end
  inherited FromAvailableQuery: TADOQuery
    SQL.Strings = (
      'SELECT DISTINCT'
      ' path_fromstopid as stop_id'
      'FROM'
      ' paths')
  end
end
