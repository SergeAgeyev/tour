inherited TourPathSimpleProcessForm: TTourPathSimpleProcessForm
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
  object SpeedLabel: TLabel [1]
    Left = 46
    Top = 51
    Width = 48
    Height = 13
    Caption = '��������'
  end
  object LengthLabel: TLabel [2]
    Left = 290
    Top = 50
    Width = 60
    Height = 13
    Caption = '����������'
  end
  object ToStopIdLabel: TLabel [3]
    Left = 262
    Top = 12
    Width = 88
    Height = 13
    Caption = '��� �����.������'
  end
  object FromStopIdLabel: TLabel [4]
    Left = 14
    Top = 12
    Width = 79
    Height = 13
    Caption = '��� ���. ������'
  end
  inherited CancelButton: TButton
    Left = 440
    Top = 144
    TabOrder = 8
  end
  inherited OkButton: TButton
    Left = 360
    Top = 144
    TabOrder = 7
  end
  object SpeedEdit: TEdit [7]
    Left = 104
    Top = 48
    Width = 123
    Height = 21
    MaxLength = 15
    TabOrder = 4
  end
  object LengthEdit: TEdit [8]
    Left = 360
    Top = 48
    Width = 121
    Height = 21
    MaxLength = 50
    TabOrder = 5
  end
  object ToStopIdEdit: TEdit [9]
    Left = 360
    Top = 8
    Width = 123
    Height = 21
    TabOrder = 2
  end
  object ToStopIdButton: TButton [10]
    Left = 484
    Top = 8
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 3
    OnClick = ToStopIdButtonClick
  end
  object FromStopIdEdit: TEdit [11]
    Left = 104
    Top = 8
    Width = 123
    Height = 21
    TabOrder = 0
  end
  object FromStopIdButton: TButton [12]
    Left = 228
    Top = 8
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 1
    OnClick = FromStopIdButtonClick
  end
  object AddCityButton: TButton [13]
    Left = 0
    Top = 144
    Width = 169
    Height = 25
    Caption = '����� ���������� �����'
    TabOrder = 6
    OnClick = AddCityButtonClick
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      '�������� �� �������� ��������� ������ ����'
      '��� ��������� �������� ������ ���� ���� Integer'
      '�������� �� �������� ��������� �������� ����'
      '��� ��������� �������� ������ ���� ���� Float'
      '������� ��� ���������� ������������� ������'
      
        '���� "��� ���������� ������������� ������" �������� ��������. ��' +
        '� ����������� �����������.'
      '������� ��� ��������� ������������� ������'
      
        '���� "��� ��������� ������������� ������" �������� ��������. ���' +
        ' ����������� �����������.'
      '������������� ������ � ����� ����� �� ����������'
      '����������� ���������� � ������������ ������'
      '������������ ������� ����'
      '��������� � �������� ����� �������� �� ����� ���� �����������'
      '������ ������������ �������'
      '���'
      '��������'
      '������ ��� ���������� ������ ����������� ������'
      '������ ��� �������� �����')
    Top = 144
  end
end
