inherited TourRefBookStopOwnerProcessForm: TTourRefBookStopOwnerProcessForm
  ClientHeight = 110
  ClientWidth = 497
  OldCreateOrder = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object StopOwnerIdLabel: TLabel [0]
    Left = 61
    Top = 12
    Width = 19
    Height = 13
    Caption = '���'
  end
  object StopOwnerNameLabel: TLabel [1]
    Left = 4
    Top = 38
    Width = 79
    Height = 13
    Caption = '������������ '
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
  object StopOwnerIdDBEdit: TDBEdit [4]
    Left = 87
    Top = 8
    Width = 83
    Height = 21
    DataField = 'stopowner_id'
    DataSource = FMainQueryDataSource
    MaxLength = 10
    TabOrder = 0
  end
  object StopOwnerNameDBEdit: TDBEdit [5]
    Left = 87
    Top = 36
    Width = 403
    Height = 21
    DataField = 'stopowner_name'
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
      '������� '
      '��� ��������� ������������� ������')
    Left = 294
    Top = 76
  end
end
