object TourDataSetViewForm: TTourDataSetViewForm
  Left = 403
  Top = 209
  BorderStyle = bsDialog
  Caption = 'Результат поиска'
  ClientHeight = 283
  ClientWidth = 427
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object OkButton: TButton
    Left = 268
    Top = 252
    Width = 75
    Height = 25
    Caption = 'Ok'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object CancelButton: TButton
    Left = 348
    Top = 252
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 2
  end
  object Grid: TVDBSortGrid
    Left = 0
    Top = 0
    Width = 427
    Height = 245
    Align = alTop
    DataSource = DataSource
    Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgConfirmDelete, dgCancelOnExit]
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    TitleButtons = True
    DataSourceOrdering = DataSourceOrdering
  end
  object DataSource: TDataSource
    AutoEdit = False
    Left = 2
    Top = 250
  end
  object DataSourceOrdering: TVADODataSourceOrdering
    Items = <>
    Left = 34
    Top = 250
  end
end
