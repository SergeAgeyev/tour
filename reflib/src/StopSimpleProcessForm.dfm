inherited TourStopSimpleProcessForm: TTourStopSimpleProcessForm
  ClientHeight = 174
  OldCreateOrder = True
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  inherited Bevel: TBevel
    Height = 137
    Shape = bsBox
    Style = bsRaised
  end
  object StopLabel: TLabel [1]
    Left = 78
    Top = 11
    Width = 19
    Height = 13
    Caption = '���'
  end
  object StopNameLabel: TLabel [2]
    Left = 48
    Top = 106
    Width = 50
    Height = 13
    Caption = '��������'
  end
  object CityZIPLabel: TLabel [3]
    Left = 262
    Top = 12
    Width = 89
    Height = 13
    Caption = '��� �����.������'
  end
  object StopModelLabel: TLabel [4]
    Left = 75
    Top = 41
    Width = 19
    Height = 13
    Caption = '���'
  end
  object StopOwnerLabel: TLabel [5]
    Left = 51
    Top = 73
    Width = 49
    Height = 13
    Caption = '��������'
  end
  inherited CancelButton: TButton
    Left = 440
    Top = 144
    TabOrder = 10
  end
  inherited OkButton: TButton
    Left = 360
    Top = 144
    TabOrder = 9
  end
  object StopIdEdit: TEdit [8]
    Left = 104
    Top = 8
    Width = 123
    Height = 21
    MaxLength = 15
    TabOrder = 0
  end
  object StopNameEdit: TEdit [9]
    Left = 104
    Top = 104
    Width = 403
    Height = 21
    MaxLength = 50
    TabOrder = 5
  end
  object CityZIPEdit: TEdit [10]
    Left = 360
    Top = 8
    Width = 123
    Height = 21
    TabOrder = 1
  end
  object StopModelVMemoKeyComboBox: TVMemoKeyComboBox [11]
    Left = 104
    Top = 40
    Width = 404
    Height = 21
    FormatString = '[%s] %s'
    EmptyString = '<�������� �� ����������>'
    CanEmpty = True
    TabOrder = 3
    Items = <>
  end
  object StopOwnerVMemoKeyComboBox: TVMemoKeyComboBox [12]
    Left = 104
    Top = 72
    Width = 404
    Height = 21
    FormatString = '[%s] %s'
    EmptyString = '<�������� �� ����������>'
    CanEmpty = True
    TabOrder = 4
    Items = <>
  end
  object CityZIPButton: TButton [13]
    Left = 484
    Top = 8
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 2
    OnClick = CityZIPButtonClick
  end
  object AddCityButton: TButton [14]
    Left = 0
    Top = 144
    Width = 105
    Height = 25
    Caption = '����� ���.�����'
    TabOrder = 6
    OnClick = AddCityButtonClick
  end
  object AddStopOwnerButton: TButton [15]
    Left = 112
    Top = 144
    Width = 97
    Height = 25
    Caption = '����� ��������'
    TabOrder = 7
    OnClick = AddStopOwnerButtonClick
  end
  object AddStopModelButton: TButton [16]
    Left = 216
    Top = 144
    Width = 121
    Height = 25
    Caption = '����� ��� ���������'
    TabOrder = 8
    OnClick = AddStopModelButtonClick
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      '�������� �� �������� ��������� ������ ����'
      '��� ��������� �������� ������ ���� ���� Integer'
      '�������� �� �������� ��������� �������� ����'
      '��� ��������� �������� ������ ���� ���� Float'
      '������� ��� ������������� ������'
      
        '���� "��� ������������� ������" �������� ��������. ��� ���������' +
        '�� �����������.'
      '������� ��� ����������� ������'
      '����������� ���� "��� ����������� ������" �����������.'
      '����������� ������ � ����� ����� �� ����������'
      '����������� ���������� � ���������� ������'
      '������ ���������� �������'
      '���'
      '��������'
      '������ ��� ���������� ������ ����������� ������'
      '������ ��� ���������� ������ ���� ������������� ������'
      '������ ��� ���������� ������ ��������� ������������� ������'
      '������ ��� �������� �����')
    Top = 144
  end
end
