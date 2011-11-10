inherited TourStatsProcessForm: TTourStatsProcessForm
  Left = 250
  ClientHeight = 155
  ClientWidth = 482
  OldCreateOrder = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object TripIdLabel: TLabel [0]
    Left = 41
    Top = 12
    Width = 25
    Height = 13
    Caption = 'Рейс'
  end
  object StatsFromStopIdLabel: TLabel [1]
    Left = 16
    Top = 43
    Width = 50
    Height = 13
    Caption = 'Нач.пункт'
  end
  object StatsFlowLabel: TLabel [2]
    Left = 32
    Top = 99
    Width = 34
    Height = 13
    Caption = 'Кол-во'
  end
  object StatsToStopIdIdLabel: TLabel [3]
    Left = 16
    Top = 71
    Width = 50
    Height = 13
    Caption = 'Кон.пункт'
  end
  object StatsDateLabel: TLabel [4]
    Left = 185
    Top = 12
    Width = 26
    Height = 13
    Caption = 'Дата'
  end
  object StatsTimeLabel: TLabel [5]
    Left = 335
    Top = 12
    Width = 33
    Height = 13
    Caption = 'Время'
  end
  inherited CancelButton: TButton
    Left = 402
    Top = 124
    TabOrder = 7
  end
  inherited SaveButton: TButton
    Left = 322
    Top = 124
    TabOrder = 6
  end
  object TripIdDBEdit: TDBEdit [8]
    Left = 73
    Top = 8
    Width = 83
    Height = 21
    DataField = 'trip_id'
    DataSource = FMainQueryDataSource
    MaxLength = 10
    TabOrder = 0
    OnChange = TripIdDBEditChange
    OnEnter = TripIdDBEditEnter
    OnExit = TripIdDBEditExit
  end
  object StatsFlowDBEdit: TDBEdit [9]
    Left = 73
    Top = 96
    Width = 83
    Height = 21
    DataField = 'stats_flow'
    DataSource = FMainQueryDataSource
    TabOrder = 5
  end
  object StatsFromStopIdDBLookupComboBoxExt: TDBLookupComboBoxExt [10]
    Left = 73
    Top = 40
    Width = 404
    Height = 21
    DataField = 'stats_fromstopid'
    DataSource = FMainQueryDataSource
    KeyField = 'stop_id'
    ListField = 'stopfrom_name;stop_id'
    TabOrder = 3
  end
  object StatsToStopIdDBLookupComboBoxExt: TDBLookupComboBoxExt [11]
    Left = 73
    Top = 68
    Width = 404
    Height = 21
    DataField = 'stats_tostopid'
    DataSource = FMainQueryDataSource
    KeyField = 'path_tostopid'
    ListField = 'stopto_name;path_tostopid'
    TabOrder = 4
  end
  object TripIdButton: TButton [12]
    Left = 157
    Top = 8
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 1
    OnClick = TripIdButtonClick
    OnExit = TripIdDBEditExit
  end
  object StatsDatePicker: TDateTimePicker [13]
    Left = 217
    Top = 8
    Width = 104
    Height = 21
    CalAlignment = dtaLeft
    Date = 37142.7262515278
    Time = 37142.7262515278
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 2
  end
  object StatsTimePicker: TDateTimePicker [14]
    Left = 376
    Top = 8
    Width = 100
    Height = 21
    CalAlignment = dtaLeft
    Date = 37142.7262515278
    Time = 37142.7262515278
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkTime
    ParseInput = False
    TabOrder = 8
  end
  inherited FMainQueryDataSource: TDataSource
    OnDataChange = FMainQueryDataSourceDataChange
    Left = 3
    Top = 124
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Введите '
      'код рейса'
      'код начального пункта'
      'код конечного пункта'
      'Рейс'
      'Название'
      'Примечание'
      'Рейса с таким кодом не существует'
      'Неккоректное значение количества')
    Left = 280
    Top = 121
  end
  object TripDataSource: TDataSource
    Left = 37
    Top = 124
  end
  object StopDataSource: TDataSource
    Left = 70
    Top = 124
  end
  object DirectQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    DataSource = TripDataSource
    Parameters = <
      item
        Name = 'trip_id_value'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT DISTINCT'
      ' master_tripstep.trip_id,'
      ' master_tripstep.stop_id,'
      ' master_tripstep.path_tostopid,'
      ' from_stop.stop_name as stopfrom_name,'
      ' to_stop.stop_name as stopto_name'
      'FROM'
      ' tripstep master_tripstep,'
      ' stop from_stop,'
      ' stop to_stop'
      'WHERE'
      ' (master_tripstep.trip_id = :trip_id_value) AND'
      ' (master_tripstep.stop_id = from_stop.stop_id) AND'
      ' (master_tripstep.path_tostopid = to_stop.stop_id)')
    Left = 104
    Top = 124
  end
  object DirectDataSource: TDataSource
    DataSet = DirectQuery
    Left = 136
    Top = 124
  end
  object FromStopQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    DataSource = DirectDataSource
    Parameters = <
      item
        Name = 'trip_id_value'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'stop_id_value'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT DISTINCT'
      ' master_tripstep.trip_id,'
      ' master_tripstep.stop_id,'
      ' master_tripstep.path_tostopid,'
      ' from_stop.stop_name as stopfrom_name,'
      ' to_stop.stop_name as stopto_name'
      'FROM'
      ' tripstep master_tripstep,'
      ' stop from_stop,'
      ' stop to_stop'
      'WHERE'
      ' (master_tripstep.trip_id = :trip_id_value) AND'
      ' (master_tripstep.stop_id = :stop_id_value) AND'
      ' (master_tripstep.stop_id = from_stop.stop_id) AND'
      ' (master_tripstep.path_tostopid = to_stop.stop_id)')
    Left = 169
    Top = 124
  end
  object FromStopDataSource: TDataSource
    DataSet = FromStopQuery
    Left = 201
    Top = 124
  end
end
