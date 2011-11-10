inherited TourRefBookStopModelProcessForm: TTourRefBookStopModelProcessForm
  ClientHeight = 110
  ClientWidth = 498
  OldCreateOrder = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object StopModelIdLabel: TLabel [0]
    Left = 62
    Top = 12
    Width = 19
    Height = 13
    Caption = 'Тип'
  end
  object StopModelNameLabel: TLabel [1]
    Left = 5
    Top = 38
    Width = 76
    Height = 13
    Caption = 'Наименование'
  end
  inherited CancelButton: TButton
    Left = 416
    Top = 80
    TabOrder = 3
  end
  inherited SaveButton: TButton
    Left = 336
    Top = 80
    TabOrder = 2
  end
  object StopModelDBEdit: TDBEdit [4]
    Left = 87
    Top = 8
    Width = 43
    Height = 21
    DataField = 'stop_model'
    DataSource = FMainQueryDataSource
    MaxLength = 5
    TabOrder = 0
  end
  object StopModelNameDBEdit: TDBEdit [5]
    Left = 87
    Top = 36
    Width = 403
    Height = 21
    DataField = 'stopmodel_name'
    DataSource = FMainQueryDataSource
    MaxLength = 50
    TabOrder = 1
  end
  inherited FMainQueryDataSource: TDataSource
    Left = 7
    Top = 77
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Введите '
      'тип остановочного пункта')
    Left = 294
    Top = 76
  end
end
