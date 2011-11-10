inherited TourTripProcessForm: TTourTripProcessForm
  Left = 250
  ClientHeight = 187
  ClientWidth = 483
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
  object BusModelLabel: TLabel [1]
    Left = 27
    Top = 75
    Width = 41
    Height = 13
    Caption = 'Автобус'
  end
  object TripNotesLabel: TLabel [2]
    Left = 5
    Top = 131
    Width = 63
    Height = 13
    Caption = 'Примечание'
  end
  object TripOwnerIdLabel: TLabel [3]
    Left = 7
    Top = 103
    Width = 61
    Height = 13
    Caption = 'Перевозчик'
  end
  object TripNameLabel: TLabel [4]
    Left = 15
    Top = 39
    Width = 50
    Height = 13
    Caption = 'Название'
  end
  object Bevel: TBevel [5]
    Left = 3
    Top = 64
    Width = 476
    Height = 9
    Shape = bsTopLine
  end
  inherited CancelButton: TButton
    Left = 402
    Top = 156
    TabOrder = 6
  end
  inherited SaveButton: TButton
    Left = 322
    Top = 156
    TabOrder = 5
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
  end
  object TripNotesDBEdit: TDBEdit [9]
    Left = 73
    Top = 128
    Width = 403
    Height = 21
    DataField = 'trip_notes'
    DataSource = FMainQueryDataSource
    MaxLength = 50
    TabOrder = 4
  end
  object BusModelDBLookupComboBoxExt: TDBLookupComboBoxExt [10]
    Left = 73
    Top = 72
    Width = 404
    Height = 21
    DataField = 'bus_model'
    DataSource = FMainQueryDataSource
    KeyField = 'bus_model'
    ListField = 'bus_desc;bus_model'
    ListSource = BusDataSource
    TabOrder = 2
  end
  object TripOwnerIdDBLookupComboBoxExt: TDBLookupComboBoxExt [11]
    Left = 73
    Top = 100
    Width = 404
    Height = 21
    DataField = 'tripowner_id'
    DataSource = FMainQueryDataSource
    KeyField = 'tripowner_id'
    ListField = 'tripowner_name;tripowner_id'
    ListSource = TripOwnerDataSource
    TabOrder = 3
  end
  object TripNameDBEdit: TDBEdit [12]
    Left = 73
    Top = 36
    Width = 403
    Height = 21
    DataField = 'trip_name'
    DataSource = FMainQueryDataSource
    MaxLength = 50
    TabOrder = 1
  end
  inherited FMainQueryDataSource: TDataSource
    Left = 3
    Top = 156
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Введите '
      'код рейса')
    Left = 280
    Top = 153
  end
  object TripOwnerDataSource: TDataSource
    Left = 37
    Top = 156
  end
  object BusDataSource: TDataSource
    Left = 70
    Top = 156
  end
end
