object TourTripTourMoveDialogForm: TTourTripTourMoveDialogForm
  Left = 192
  Top = 107
  BorderStyle = bsDialog
  Caption = 'Перенос рейса'
  ClientHeight = 95
  ClientWidth = 265
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
  object TimeStartLabel: TLabel
    Left = 8
    Top = 10
    Width = 147
    Height = 13
    Caption = 'Перенести начало рейса на  '
  end
  object OkButton: TButton
    Left = 101
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Ok'
    Default = True
    ModalResult = 1
    TabOrder = 2
  end
  object CancelButton: TButton
    Left = 181
    Top = 64
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 3
  end
  object TourCopyCheckBox: TCheckBox
    Left = 8
    Top = 40
    Width = 97
    Height = 17
    Caption = 'Создать копию'
    TabOrder = 1
  end
  object TimeStartPicker: TShortTimePicker
    Left = 216
    Top = 8
    Width = 41
    Height = 21
    TabStop = True
    TabOrder = 0
  end
  object VStringStorage: TVStringStorage
    Left = 60
    Top = 61
  end
end
