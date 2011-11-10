object TourRepStopInfoInputForm: TTourRepStopInfoInputForm
  Left = 404
  Top = 187
  ActiveControl = StopGrid
  BorderStyle = bsDialog
  Caption = 'Выбор остановки для формирования станционного расписания'
  ClientHeight = 356
  ClientWidth = 427
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
    Left = 344
    Top = 320
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 2
  end
  object StopGrid: TVDBSortGrid
    Left = 8
    Top = 8
    Width = 409
    Height = 305
    DataSource = StopDataSource
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnDblClick = StopGridDblClick
    OnKeyDown = StopGridKeyDown
    TitleButtons = True
    DataSourceOrdering = StopDataSourceOrdering
    Columns = <
      item
        Expanded = False
        FieldName = 'Stop_Id'
        Width = 105
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Stop_Name'
        Width = 269
        Visible = True
      end>
  end
  object StopQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM Stop;')
    Left = 16
    Top = 272
    object StopQueryStop_Id: TStringField
      DisplayLabel = 'Код остановки'
      FieldName = 'Stop_Id'
      Size = 10
    end
    object StopQueryStop_Name: TStringField
      DisplayLabel = 'Название остановки'
      FieldName = 'Stop_Name'
      Size = 50
    end
  end
  object StopDataSource: TDataSource
    DataSet = StopQuery
    Left = 48
    Top = 272
  end
  object StopDataSourceOrdering: TVADODataSourceOrdering
    Items = <>
    Query = StopQuery
    Left = 80
    Top = 272
  end
end
