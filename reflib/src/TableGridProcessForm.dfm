object TourRefBookTableGridProcessForm: TTourRefBookTableGridProcessForm
  Left = 259
  Top = 227
  BorderStyle = bsDialog
  ClientHeight = 208
  ClientWidth = 423
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
  object CancelButton: TButton
    Left = 342
    Top = 176
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 1
  end
  object SaveButton: TButton
    Left = 262
    Top = 176
    Width = 75
    Height = 25
    Caption = 'Сохранить'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object FMainQueryDataSource: TDataSource
    Left = 5
    Top = 173
  end
  object VStringStorage: TVStringStorage
    Lines.Strings = (
      'Введите ')
    Left = 392
    Top = 4
  end
end
