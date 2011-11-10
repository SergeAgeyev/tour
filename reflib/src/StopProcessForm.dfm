inherited TourRefBookStopProcessForm: TTourRefBookStopProcessForm
  Left = 250
  ClientHeight = 155
  ClientWidth = 480
  OldCreateOrder = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object StopIdLabel: TLabel [0]
    Left = 41
    Top = 12
    Width = 19
    Height = 13
    Caption = 'Код'
  end
  object CityZIPLabel: TLabel [1]
    Left = 268
    Top = 12
    Width = 89
    Height = 13
    Caption = 'Код насел.пункта'
  end
  object StopModelLabel: TLabel [2]
    Left = 38
    Top = 43
    Width = 22
    Height = 13
    Caption = 'Тип '
  end
  object StopNameLabel: TLabel [3]
    Left = 10
    Top = 99
    Width = 50
    Height = 13
    Caption = 'Название'
  end
  object StopOwnerIdLabel: TLabel [4]
    Left = 8
    Top = 71
    Width = 52
    Height = 13
    Caption = 'Владелец '
  end
  inherited CancelButton: TButton
    Left = 398
    Top = 124
    TabOrder = 7
  end
  inherited SaveButton: TButton
    Left = 318
    Top = 124
    TabOrder = 6
  end
  object StopIdDBEdit: TDBEdit [7]
    Left = 69
    Top = 8
    Width = 83
    Height = 21
    DataField = 'stop_id'
    DataSource = FMainQueryDataSource
    MaxLength = 10
    TabOrder = 0
  end
  object CityZIPDBEdit: TDBEdit [8]
    Left = 366
    Top = 8
    Width = 83
    Height = 21
    DataField = 'city_zip'
    DataSource = FMainQueryDataSource
    MaxLength = 10
    TabOrder = 1
  end
  object StopNameDBEdit: TDBEdit [9]
    Left = 69
    Top = 96
    Width = 403
    Height = 21
    DataField = 'stop_name'
    DataSource = FMainQueryDataSource
    MaxLength = 50
    TabOrder = 5
  end
  object StopModelDBLookupComboBoxExt: TDBLookupComboBoxExt [10]
    Left = 69
    Top = 40
    Width = 404
    Height = 21
    DataField = 'stop_model'
    DataSource = FMainQueryDataSource
    KeyField = 'stop_model'
    ListField = 'stopmodel_name;stop_model'
    ListSource = StopModelDataSource
    TabOrder = 3
  end
  object CityZIPButton: TButton [11]
    Left = 450
    Top = 8
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 2
    OnClick = CityZIPButtonClick
  end
  object StopOwnerIdDBLookupComboBoxExt: TDBLookupComboBoxExt [12]
    Left = 69
    Top = 68
    Width = 404
    Height = 21
    DataField = 'stopowner_id'
    DataSource = FMainQueryDataSource
    KeyField = 'stopowner_id'
    ListField = 'stopowner_name;stopowner_id'
    ListSource = StopOwnerDataSource
    TabOrder = 4
  end
  inherited FMainQueryDataSource: TDataSource
    Left = 3
    Top = 124
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Введите '
      'код остановочного пункта'
      'код населенного пункта'
      'Код'
      'Название'
      'Населенного пункта с таким кодом не существует')
    Left = 276
    Top = 121
  end
  object CityDataSource: TDataSource
    Left = 38
    Top = 124
  end
  object StopOwnerDataSource: TDataSource
    Left = 70
    Top = 124
  end
  object StopModelDataSource: TDataSource
    Left = 103
    Top = 123
  end
end
