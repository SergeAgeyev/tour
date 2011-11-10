object TourDiagramChangesForm: TTourDiagramChangesForm
  Tag = 10
  Left = 240
  Top = 200
  BorderStyle = bsDialog
  ClientHeight = 347
  ClientWidth = 504
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object ScrollBox: TScrollBox
    Tag = 10
    Left = 0
    Top = 0
    Width = 505
    Height = 305
    TabOrder = 0
  end
  object OkButton: TButton
    Left = 344
    Top = 316
    Width = 75
    Height = 25
    Caption = 'Да'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object CancelButton: TButton
    Left = 424
    Top = 316
    Width = 75
    Height = 25
    Caption = 'Нет'
    ModalResult = 2
    TabOrder = 2
  end
  object VStringStorage: TVStringStorage
    Lines.Strings = (
      'Рейс №'
      ' модифицирован'
      ' добавлен'
      ' удален')
    Top = 312
  end
end
