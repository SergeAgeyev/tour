inherited TourTripNewMasterForm: TTourTripNewMasterForm
  Caption = 'Ввод данных нового рейса '
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  inherited SaveButton: TButton
    Caption = 'Дальше >'
    ModalResult = 0
    OnClick = SaveButtonClick
  end
  inherited FMainQueryDataSource: TDataSource
    DataSet = TripQuery
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Введите '
      'код рейса'
      'Рейс с таким кодом уже существует')
  end
  inherited TripOwnerDataSource: TDataSource
    DataSet = TripOwnerQuery
  end
  inherited BusDataSource: TDataSource
    DataSet = BusQuery
  end
  object TripQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' trip_id,'
      ' bus_model,'
      ' tripowner_id,'
      ' trip_notes'
      'FROM'
      ' trip')
    Left = 104
    Top = 124
  end
  object TripOwnerQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' tripowner_id,'
      ' tripowner_name'
      'FROM'
      ' tripowner')
    Left = 136
    Top = 124
  end
  object BusQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' bus_model,'
      ' bus_desc'
      'FROM'
      ' bus')
    Left = 168
    Top = 124
  end
end
