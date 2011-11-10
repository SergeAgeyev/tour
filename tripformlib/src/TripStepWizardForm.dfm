inherited TourTripStepWizardForm: TTourTripStepWizardForm
  Caption = 'Мастер маршрута'
  ClientHeight = 501
  ClientWidth = 774
  OldCreateOrder = True
  Position = poDesktopCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  inherited AvailableLabel: TLabel
    Top = 245
  end
  inherited ChainListView: TListView
    Width = 770
    Height = 204
    Columns = <
      item
        Caption = 'Код'
        Width = 83
      end
      item
        Caption = 'Название'
        Width = 403
      end
      item
        Alignment = taCenter
        Caption = 'Время прибытия'
        Width = 100
      end
      item
        Alignment = taCenter
        Caption = 'Стоянка'
        Width = 100
      end>
    OnDblClick = TripStepEditActionExecute
  end
  inherited AvailableListView: TListView
    Top = 261
    Width = 770
    Height = 204
    HideSelection = False
    OnDblClick = AvailableAddActionExecute
  end
  inherited CancelButton: TButton
    Left = 696
    Top = 472
  end
  inherited NextButton: TButton
    Left = 615
    Top = 472
    Caption = 'Сохранить'
  end
  inherited SelectButton: TButton
    Left = 0
    Top = 473
  end
  inherited DeleteButton: TBitBtn
    Left = 308
    Top = 232
  end
  inherited AddButton: TBitBtn
    Left = 391
    Top = 232
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
      ' :fromstop_id = path_fromstopid')
    Left = 190
    Top = 469
  end
  inherited ActionList: TActionList
    Left = 382
    Top = 469
    inherited ChainDeleteItemAction: TAction
      OnExecute = ChainDeleteItemActionExecute
    end
    inherited AvailableAddAction: TAction
      OnExecute = AvailableAddActionExecute
    end
    inherited SelectAction: TAction
      OnExecute = SelectActionExecute
    end
    object TripStepEditAction: TAction
      Caption = 'Изменить'
      OnExecute = TripStepEditActionExecute
    end
    object SaveAction: TAction
      Caption = 'Сохранить'
      OnExecute = SaveActionExecute
    end
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Выбор рейса'
      'Рейс'
      'Название'
      'Примечание')
    Left = 350
    Top = 469
  end
  inherited TripQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' trip_name,'
      ' trip_id,'
      ' trip_notes'
      'FROM'
      ' trip'
      'ORDER BY'
      ' trip_name')
    Left = 254
    Top = 469
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
      ' path_tostopid,'
      ' tripstep_intime,'
      ' tripstep_waittime'
      'FROM'
      ' tripstep'
      'WHERE'
      ' trip_id = :trip_id_value'
      'ORDER BY'
      ' tripstep_num')
    Left = 286
    Top = 469
  end
  inherited StopQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' stop_id,'
      ' stop_name'
      'FROM'
      ' stop')
    Left = 318
    Top = 469
  end
  inherited FromAvailableQuery: TADOQuery
    SQL.Strings = (
      'SELECT DISTINCT'
      ' path_fromstopid as stop_id'
      'FROM'
      ' paths')
    Left = 222
    Top = 469
  end
  inherited AvailablePopupMenu: TPopupMenu
    Left = 736
    Top = 428
  end
  object TripStepInfoQuery: TADOQuery [17]
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <
      item
        Name = 'trip_id_value'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'tripstep_num_value'
        DataType = ftInteger
        Value = Null
      end>
    SQL.Strings = (
      'SELECT'
      ' trip_id,'
      ' tripstep_num,'
      ' tripstep_intime,'
      ' tripstep_waittime'
      'FROM'
      ' tripstep'
      'WHERE'
      ' (trip_id = :trip_id_value) AND'
      ' (tripstep_num = :tripstep_num_value)')
    Left = 736
    Top = 231
  end
  object TimeInInfoQuery: TADOQuery [18]
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <
      item
        Name = 'trip_id_value'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'from_stopid_value'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'to_stopid_value'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT'
      ' path_normspeed,'
      ' path_length,'
      ' bus_speedfactor'
      'FROM'
      ' paths,'
      ' trip,'
      ' bus'
      'WHERE'
      ' (trip.trip_id = :trip_id_value) AND'
      ' (paths.path_fromstopid = :from_stopid_value) AND'
      ' (paths.path_tostopid = :to_stopid_value) AND'
      ' (trip.bus_model = bus.bus_model)')
    Left = 704
    Top = 232
  end
  object TimeInInfoSimpleQuery: TADOQuery [19]
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <
      item
        Name = 'trip_id_value'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'from_stopid_value'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'to_stopid_value'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT'
      ' path_normspeed,'
      ' path_length'
      'FROM'
      ' paths,'
      ' trip'
      'WHERE'
      ' (trip.trip_id = :trip_id_value) AND'
      ' (paths.path_fromstopid = :from_stopid_value) AND'
      ' (paths.path_tostopid = :to_stopid_value)')
    Left = 672
    Top = 232
  end
  inherited ChainPopupMenu: TPopupMenu
    Left = 736
    Top = 184
    object ChangeMenuItem: TMenuItem [0]
      Action = TripStepEditAction
    end
  end
  object TripStepClearQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <
      item
        Name = 'trip_id_value'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'DELETE'
      ' *'
      'FROM'
      ' tripstep'
      'WHERE'
      ' trip_id = :trip_id_value')
    Left = 440
    Top = 470
  end
end
