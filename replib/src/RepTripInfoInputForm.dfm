object TourRepTripInfoInputForm: TTourRepTripInfoInputForm
  Left = 250
  Top = 183
  ActiveControl = TripGrid
  BorderStyle = bsDialog
  Caption = 'Выбор остановки для формирования станционного расписания'
  ClientHeight = 356
  ClientWidth = 513
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object CreateReportButton: TButton
    Left = 8
    Top = 320
    Width = 129
    Height = 25
    Caption = 'Сформировать отчет'
    TabOrder = 1
    OnClick = CreateReportButtonClick
  end
  object CancelButton: TButton
    Left = 432
    Top = 320
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 2
  end
  object TripGrid: TVDBSortGrid
    Left = 8
    Top = 8
    Width = 497
    Height = 305
    DataSource = TripDataSource
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnDblClick = TripGridDblClick
    OnKeyDown = TripGridKeyDown
    TitleButtons = True
    DataSourceOrdering = TripDataSourceOrdering
    Columns = <
      item
        Expanded = False
        FieldName = 'Trip_Id'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Trip_Name'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Bus_Model'
        Visible = True
      end>
  end
  object TripQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM Trip;')
    Left = 16
    Top = 272
    object TripQueryTrip_Id: TStringField
      DisplayLabel = 'Код рейса'
      FieldName = 'Trip_Id'
      Size = 10
    end
    object TripQueryTrip_Name: TStringField
      DisplayLabel = 'Название рейса'
      FieldName = 'Trip_Name'
      Size = 50
    end
    object TripQueryBus_Model: TStringField
      DisplayLabel = 'Тип автобуса'
      FieldName = 'Bus_Model'
      Size = 15
    end
  end
  object TripDataSource: TDataSource
    DataSet = TripQuery
    Left = 48
    Top = 272
  end
  object TripDataSourceOrdering: TVADODataSourceOrdering
    Items = <>
    Query = TripQuery
    Left = 80
    Top = 272
  end
end
