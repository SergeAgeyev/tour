object TourTripStepDataTimeInfoForm: TTourTripStepDataTimeInfoForm
  Left = 192
  Top = 107
  BorderStyle = bsDialog
  Caption = '����������'
  ClientHeight = 219
  ClientWidth = 283
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object InTimeLabel: TLabel
    Left = 8
    Top = 8
    Width = 85
    Height = 13
    Caption = '����� ��������'
  end
  object SaveButton: TButton
    Left = 126
    Top = 191
    Width = 75
    Height = 25
    Caption = '���������'
    Default = True
    ModalResult = 1
    TabOrder = 3
  end
  object CancelButton: TButton
    Left = 206
    Top = 191
    Width = 75
    Height = 25
    Cancel = True
    Caption = '������'
    ModalResult = 2
    TabOrder = 4
  end
  object WaitTimeRadioGroup: TRadioGroup
    Left = 0
    Top = 32
    Width = 281
    Height = 153
    Columns = 2
    ItemIndex = 0
    Items.Strings = (
      '��� ������'
      '��� ���������'
      '������� 5 �����'
      '������� ...'
      '������� 10 ����� '
      '������� 15 �����'
      '������� 20 �����')
    TabOrder = 1
    OnClick = WaitTimeRadioGroupClick
  end
  object TimeInPicker: TShortTimePicker
    Left = 144
    Top = 8
    Width = 41
    Height = 21
    TabStop = True
    TabOrder = 0
  end
  object TimeWaitPicker: TShortTimePicker
    Left = 144
    Top = 152
    Width = 41
    Height = 21
    TabStop = True
    TabOrder = 2
  end
  object VStringStorage: TVStringStorage
    Left = 85
    Top = 188
  end
end
