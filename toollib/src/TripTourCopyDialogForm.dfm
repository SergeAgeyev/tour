object TourTripTourCopyDialogForm: TTourTripTourCopyDialogForm
  Left = 192
  Top = 107
  BorderStyle = bsDialog
  Caption = 'Cоздание копии рейса '
  ClientHeight = 110
  ClientWidth = 416
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
  object TripIdLabel: TLabel
    Left = 8
    Top = 10
    Width = 25
    Height = 13
    Caption = 'Рейс'
  end
  object TripNameLabel: TLabel
    Left = 8
    Top = 34
    Width = 50
    Height = 13
    Caption = 'Название'
  end
  object OkButton: TButton
    Left = 253
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Ok'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelButton: TButton
    Left = 333
    Top = 80
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 1
  end
  object TripIdEdit: TEdit
    Left = 80
    Top = 8
    Width = 329
    Height = 21
    TabOrder = 2
  end
  object TripNameEdit: TEdit
    Left = 80
    Top = 32
    Width = 329
    Height = 21
    TabOrder = 3
  end
  object VStringStorage: TVStringStorage
    Left = 212
    Top = 77
  end
end
