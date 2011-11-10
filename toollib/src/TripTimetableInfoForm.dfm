object TourTripTimetableInfoForm: TTourTripTimetableInfoForm
  Left = 192
  Top = 107
  BorderStyle = bsDialog
  Caption = 'Информация'
  ClientHeight = 78
  ClientWidth = 365
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
  object InTimeLabel: TLabel
    Left = 8
    Top = 5
    Width = 51
    Height = 13
    Caption = 'Прибытие'
  end
  object TimeOutLabel: TLabel
    Left = 128
    Top = 5
    Width = 67
    Height = 13
    Caption = 'Отправление'
  end
  object TimeWaitLabel: TLabel
    Left = 272
    Top = 5
    Width = 42
    Height = 13
    Caption = 'Стоянка'
  end
  object SaveButton: TButton
    Left = 206
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Сохранить'
    Default = True
    ModalResult = 1
    TabOrder = 4
  end
  object CancelButton: TButton
    Left = 286
    Top = 48
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 5
  end
  object TimeInShortTimePicker: TShortTimePicker
    Left = 64
    Top = 2
    Width = 41
    Height = 21
    TabStop = True
    TabOrder = 0
    OnTimeChange = TimeInShortTimePickerTimeChange
  end
  object TimeWaitShortTimePicker: TShortTimePicker
    Left = 320
    Top = 2
    Width = 41
    Height = 21
    TabStop = True
    TabOrder = 3
    OnTimeChange = TimeWaitShortTimePickerTimeChange
  end
  object TimeOutShortTimePicker: TShortTimePicker
    Left = 200
    Top = 2
    Width = 41
    Height = 21
    TabStop = True
    TabOrder = 2
    OnTimeChange = TimeOutShortTimePickerTimeChange
  end
  object WaitTimeEmptyCheckBox: TCheckBox
    Left = 111
    Top = 3
    Width = 18
    Height = 17
    Checked = True
    State = cbChecked
    TabOrder = 1
    OnClick = WaitTimeEmptyCheckBoxClick
  end
  object VStringStorage: TVStringStorage
    Left = 165
    Top = 45
  end
end
