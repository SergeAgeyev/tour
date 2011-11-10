object TourSimpleProcessForm: TTourSimpleProcessForm
  Left = 195
  Top = 106
  BorderStyle = bsDialog
  ClientHeight = 273
  ClientWidth = 517
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
  object Bevel: TBevel
    Left = 0
    Top = 0
    Width = 517
    Height = 232
    Align = alClient
    Shape = bsFrame
  end
  object Panel: TPanel
    Left = 0
    Top = 232
    Width = 517
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object OkButton: TButton
      Left = 352
      Top = 8
      Width = 75
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = 'Ok'
      Default = True
      ModalResult = 1
      TabOrder = 0
    end
    object CancelButton: TButton
      Left = 432
      Top = 8
      Width = 75
      Height = 25
      Anchors = [akRight, akBottom]
      Cancel = True
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 1
    end
  end
  object VStringStorage: TVStringStorage
    Lines.Strings = (
      'Значение не является величиной целого типа'
      'Тип вводимого значения должен быть типа Integer'
      'Значение не является величиной дробного типа'
      'Тип вводимого значения должен быть типа Float')
    Left = 320
    Top = 240
  end
end
