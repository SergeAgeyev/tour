inherited TourRefBookCityProcessForm: TTourRefBookCityProcessForm
  ClientHeight = 149
  ClientWidth = 480
  OldCreateOrder = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object CityZIPLabel: TLabel [0]
    Left = 44
    Top = 12
    Width = 19
    Height = 13
    Caption = 'Код'
  end
  object CityNameLabel: TLabel [1]
    Left = 13
    Top = 38
    Width = 50
    Height = 13
    Caption = 'Название'
  end
  object RegionIdLabel: TLabel [2]
    Left = 26
    Top = 67
    Width = 36
    Height = 13
    Caption = 'Регион'
  end
  object CityPopulationLabel: TLabel [3]
    Left = 7
    Top = 95
    Width = 56
    Height = 13
    Caption = 'Население'
  end
  inherited CancelButton: TButton
    Left = 400
    Top = 119
    TabOrder = 5
  end
  inherited SaveButton: TButton
    Left = 320
    Top = 119
    TabOrder = 4
  end
  object CityZIPDBEdit: TDBEdit [6]
    Left = 70
    Top = 8
    Width = 83
    Height = 21
    DataField = 'city_zip'
    DataSource = FMainQueryDataSource
    MaxLength = 10
    TabOrder = 0
  end
  object CityNameDBEdit: TDBEdit [7]
    Left = 70
    Top = 36
    Width = 403
    Height = 21
    DataField = 'city_name'
    DataSource = FMainQueryDataSource
    MaxLength = 50
    TabOrder = 1
  end
  object CityPopulationDBEdit: TDBEdit [8]
    Left = 71
    Top = 92
    Width = 123
    Height = 21
    DataField = 'City_population'
    DataSource = FMainQueryDataSource
    TabOrder = 3
  end
  object RegionIdDBLookupComboBoxExt: TDBLookupComboBoxExt [9]
    Left = 70
    Top = 64
    Width = 404
    Height = 21
    DataField = 'region_id'
    DataSource = FMainQueryDataSource
    KeyField = 'region_id'
    ListField = 'region_name;region_id'
    ListSource = RegionDataSource
    TabOrder = 2
  end
  inherited FMainQueryDataSource: TDataSource
    Left = 7
    Top = 116
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Введите '
      'Код населенного пункта'
      'Неккоректное значение населения')
    Left = 278
    Top = 115
  end
  object RegionDataSource: TDataSource
    Left = 40
    Top = 116
  end
end
