inherited TourTripStepNewMasterForm: TTourTripStepNewMasterForm
  Caption = 'Мастер маршрута '
  PixelsPerInch = 96
  TextHeight = 13
  inherited ChainLabel: TLabel
    Top = 127
  end
  inherited AvailableLabel: TLabel
    Top = 301
  end
  object TripIdLabel: TLabel [2]
    Left = 6
    Top = 12
    Width = 25
    Height = 13
    Caption = 'Рейс'
  end
  object BusModelLabel: TLabel [3]
    Left = 259
    Top = 39
    Width = 41
    Height = 13
    Caption = 'Автобус'
  end
  object TripOwnerIdLabel: TLabel [4]
    Left = 239
    Top = 67
    Width = 61
    Height = 13
    Caption = 'Перевозчик'
  end
  object TripNotesLabel: TLabel [5]
    Left = 237
    Top = 95
    Width = 63
    Height = 13
    Caption = 'Примечание'
  end
  object Bevel: TBevel [6]
    Left = 3
    Top = 120
    Width = 767
    Height = 2
    Shape = bsBottomLine
  end
  object TripNameLabel: TLabel [7]
    Left = 250
    Top = 12
    Width = 50
    Height = 13
    Caption = 'Название'
  end
  inherited ChainListView: TListView
    Top = 144
    Height = 138
    TabOrder = 5
  end
  inherited AvailableListView: TListView
    Top = 320
    Height = 145
    TabOrder = 8
  end
  inherited CancelButton: TButton
    TabOrder = 11
  end
  inherited NextButton: TButton
    ModalResult = 0
    TabOrder = 10
    OnClick = NextButtonClick
  end
  inherited SelectButton: TButton
    TabOrder = 9
  end
  inherited DeleteButton: TBitBtn
    Top = 290
    TabOrder = 6
  end
  inherited AddButton: TBitBtn
    Top = 290
    TabOrder = 7
  end
  object BackButton: TButton [15]
    Left = 534
    Top = 473
    Width = 75
    Height = 25
    Caption = '< Назад'
    ModalResult = 4
    TabOrder = 12
    Visible = False
  end
  object TripIdDBEdit: TDBEdit [16]
    Left = 89
    Top = 8
    Width = 83
    Height = 21
    DataField = 'trip_id'
    DataSource = TripQueryDataSource
    MaxLength = 10
    TabOrder = 0
  end
  object BusModelDBLookupComboBoxExt: TDBLookupComboBoxExt [17]
    Left = 309
    Top = 36
    Width = 461
    Height = 21
    DataField = 'bus_model'
    DataSource = TripQueryDataSource
    KeyField = 'bus_model'
    ListField = 'bus_desc;bus_model'
    ListSource = BusDataSource
    TabOrder = 2
  end
  object TripOwnerIdDBLookupComboBoxExt: TDBLookupComboBoxExt [18]
    Left = 309
    Top = 64
    Width = 461
    Height = 21
    DataField = 'tripowner_id'
    DataSource = TripQueryDataSource
    KeyField = 'tripowner_id'
    ListField = 'tripowner_name;tripowner_name;Tripowner_id'
    ListSource = TripOwnerDataSource
    TabOrder = 3
  end
  object TripNotesDBEdit: TDBEdit [19]
    Left = 309
    Top = 91
    Width = 461
    Height = 21
    DataField = 'trip_notes'
    DataSource = TripQueryDataSource
    MaxLength = 50
    TabOrder = 4
  end
  object TripNameDBEdit: TDBEdit [20]
    Left = 309
    Top = 8
    Width = 461
    Height = 21
    DataField = 'trip_name'
    DataSource = TripQueryDataSource
    MaxLength = 50
    TabOrder = 1
  end
  inherited ToAvailableQuery: TADOQuery
    Left = 184
    Top = 468
  end
  inherited ActionList: TActionList
    Left = 376
    Top = 468
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Выбор рейса'
      'Рейс'
      'Название'
      'Примечание'
      'Введите '
      'код рейса'
      'Рейс с таким кодом уже существует')
    Left = 345
    Top = 468
  end
  inherited TripQuery: TADOQuery
    Left = 248
    Top = 468
    object TripQuerytrip_id: TWideStringField
      FieldName = 'trip_id'
      Size = 10
    end
    object TripQuerytrip_name: TWideStringField
      FieldName = 'trip_name'
      Size = 50
    end
    object TripQuerytrip_notes: TWideStringField
      FieldName = 'trip_notes'
      Size = 50
    end
  end
  inherited TripStepQuery: TADOQuery
    Left = 280
    Top = 468
  end
  inherited StopQuery: TADOQuery
    Left = 312
    Top = 468
  end
  inherited FromAvailableQuery: TADOQuery
    Left = 216
    Top = 468
  end
  object TripQueryDataSource: TDataSource [28]
    DataSet = ExistTripQuery
    Left = 123
    Top = 36
  end
  object TripOwnerDataSource: TDataSource [29]
    DataSet = TripOwnerQuery
    Left = 157
    Top = 36
  end
  object BusDataSource: TDataSource [30]
    DataSet = BusQuery
    Left = 190
    Top = 36
  end
  object TripOwnerQuery: TADOQuery [31]
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' tripowner_id,'
      ' tripowner_name'
      'FROM'
      ' tripowner')
    Left = 157
    Top = 68
  end
  object BusQuery: TADOQuery [32]
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' bus_model,'
      ' bus_speedfactor,'
      ' bus_desc'
      'FROM'
      ' bus')
    Left = 190
    Top = 68
  end
  object ExistTripQuery: TADOQuery [33]
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' trip_id,'
      ' bus_model,'
      ' tripowner_id,'
      ' trip_name,'
      ' trip_notes'
      'FROM'
      ' trip')
    Left = 123
    Top = 68
  end
  inherited TripStepInfoQuery: TADOQuery
    Top = 287
  end
  inherited TimeInInfoQuery: TADOQuery
    Parameters = <
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
      ' paths'
      'WHERE'
      ' (paths.path_fromstopid = :from_stopid_value) AND'
      ' (paths.path_tostopid = :to_stopid_value)')
    Top = 288
  end
  inherited ChainPopupMenu: TPopupMenu
    Top = 245
  end
end
