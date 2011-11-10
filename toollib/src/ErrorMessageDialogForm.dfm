object TourErrorMessageDialogForm: TTourErrorMessageDialogForm
  Left = 250
  Top = 174
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  ClientHeight = 173
  ClientWidth = 392
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object ErrorMessageLabel: TLabel
    Left = 2
    Top = 6
    Width = 387
    Height = 32
    Alignment = taCenter
    AutoSize = False
    Caption = 'Внутренняя ошибка'
  end
  object DetailsButton: TButton
    Left = 176
    Top = 46
    Width = 105
    Height = 25
    Caption = 'Подробнее...'
    TabOrder = 1
    OnClick = DetailsButtonClick
  end
  object DetailsMemo: TMemo
    Left = 1
    Top = 76
    Width = 389
    Height = 93
    TabStop = False
    Lines.Strings = (
      '<нет данных>')
    ReadOnly = True
    TabOrder = 2
  end
  object CloseButton: TButton
    Left = 285
    Top = 46
    Width = 105
    Height = 25
    Cancel = True
    Caption = 'Закрыть'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object VStringStorage: TVStringStorage
    Lines.Strings = (
      'Внутренняя ошибка'
      'Подробнее...'
      'Скрыть...')
    Left = 4
    Top = 44
  end
end
