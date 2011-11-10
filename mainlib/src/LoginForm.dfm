object TourLoginForm: TTourLoginForm
  Left = 198
  Top = 114
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Tour - Авторизация'
  ClientHeight = 91
  ClientWidth = 370
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001001010100000000000280100001600000028000000100000002000
    00000100040000000000C0000000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00EEEE
    EEEEEEEEEEEEEECCCCCCCCCCCCCEEEECCCCCCCCCCCE0ECEECCEEEEEEEE00ECCE
    ECCE00000000ECCCEECCE000000EECCCCEECCE0000EEECCECCEECCE00ECEECCE
    ECCEECCEECCEECCE0ECCEECCECCEECCE00ECCEECCCCEECCE000ECCEECCCEECCE
    0000ECCEECCEECCE00000ECCEECEECEE000000ECCEEEEE000000000EEE000000
    000000000000000100000003000000FF0000007E0000003C0000001800000000
    0000080000000C0000000E0000000F0000000F8000000FC000003FE30000}
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object UserIDLabel: TLabel
    Left = 8
    Top = 20
    Width = 79
    Height = 13
    Caption = 'Пользователь :'
  end
  object PasswordLabel: TLabel
    Left = 9
    Top = 52
    Width = 44
    Height = 13
    Caption = 'Пароль :'
  end
  object UserIDEdit: TEdit
    Left = 104
    Top = 16
    Width = 145
    Height = 21
    TabOrder = 0
    OnExit = UserIDEditExit
  end
  object PasswordEdit: TEdit
    Left = 104
    Top = 48
    Width = 145
    Height = 21
    PasswordChar = '*'
    TabOrder = 1
  end
  object AcceptButton: TButton
    Left = 264
    Top = 16
    Width = 97
    Height = 25
    Caption = 'Принять'
    Default = True
    TabOrder = 2
    OnClick = AcceptButtonClick
  end
  object ExitButton: TButton
    Left = 264
    Top = 48
    Width = 97
    Height = 25
    Cancel = True
    Caption = 'Выход'
    ModalResult = 2
    TabOrder = 3
  end
  object VStringStorage: TVStringStorage
    Lines.Strings = (
      'Введите имя пользователя'
      'База данных уже открыта'
      'Невозможно открыть базу данных'
      'Возможно введены некорректные имя либо пароль пользователя'
      'Некорректные настройки ODBC драйвера')
    Left = 68
    Top = 42
  end
end
