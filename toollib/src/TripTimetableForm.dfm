object TourTripTimeTableDialogForm: TTourTripTimeTableDialogForm
  Left = 192
  Top = 107
  Width = 591
  Height = 408
  Caption = 'Расписание'
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
  object ChainListView: TListView
    Left = 0
    Top = 0
    Width = 583
    Height = 340
    Align = alClient
    Columns = <
      item
        Caption = 'Название'
        Width = 340
      end
      item
        Caption = 'Код'
        Width = 83
      end
      item
        Caption = 'Прибытие'
      end
      item
        Caption = 'Отправление'
      end
      item
        Caption = 'Стоянка'
      end
      item
        Caption = 'Скорость'
      end
      item
        Caption = 'Расстояние'
      end>
    HideSelection = False
    ReadOnly = True
    RowSelect = True
    PopupMenu = ChainPopupMenu
    TabOrder = 0
    ViewStyle = vsReport
    OnDblClick = ChangeInfoActionExecute
  end
  object Panel: TPanel
    Tag = 10
    Left = 0
    Top = 340
    Width = 583
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    OnResize = PanelResize
    object NextButton: TButton
      Left = 422
      Top = 8
      Width = 75
      Height = 25
      Anchors = [akTop]
      Caption = 'Ok'
      Default = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ModalResult = 1
      ParentFont = False
      TabOrder = 0
    end
    object CancelButton: TButton
      Left = 503
      Top = 8
      Width = 75
      Height = 25
      Anchors = [akTop]
      Cancel = True
      Caption = 'Отмена'
      ModalResult = 2
      TabOrder = 1
    end
  end
  object ChainPopupMenu: TPopupMenu
    OnPopup = ChainPopupMenuPopup
    Left = 544
    Top = 136
    object ChangeInfoMenuItem: TMenuItem
      Caption = 'Изменить расписание'
      OnClick = ChangeInfoActionExecute
    end
    object UpdateBySpeedMenuItem: TMenuItem
      Caption = 'Пересчитать по скорости'
      OnClick = UpdateBySpeedActionExecute
    end
    object MoveMenuItem: TMenuItem
      Caption = 'Перенести рейс'
      OnClick = MoveActionExecute
    end
    object InvertMenuItem: TMenuItem
      Caption = 'Инвертировать'
      OnClick = InvertActionExecute
    end
    object N1: TMenuItem
      Caption = 'Создать копию рейса'
      Enabled = False
      Visible = False
    end
    object DeleteStopMenuItem: TMenuItem
      Caption = 'Удалить ост.пункт'
      OnClick = DeleteStopActionExecute
    end
    object InsertStopMenuItem: TMenuItem
      Caption = 'Вставить ост.пункт'
      OnClick = InsertStopActionExecute
    end
    object AppendStopMenuItem: TMenuItem
      Caption = 'Добавить ост.пункт'
      OnClick = AppendStopActionExecute
    end
  end
  object VStringStorage: TVStringStorage
    Lines.Strings = (
      'Расписание рейса № '
      'Выбор рейса'
      'Перенос рейса'
      'Инвертирование рейса'
      'Создание копии рейса'
      'Некорректное значение времени (более суток). Участок  ')
    Left = 352
    Top = 352
  end
  object ActionList: TActionList
    Left = 384
    Top = 352
    object ChangeInfoAction: TAction
      Caption = 'Изменить расписание'
      OnExecute = ChangeInfoActionExecute
    end
    object UpdateBySpeedAction: TAction
      Caption = 'Пересчитать по скорости'
      OnExecute = UpdateBySpeedActionExecute
    end
    object MoveAction: TAction
      Caption = 'Перенести рейс'
      OnExecute = MoveActionExecute
    end
    object InvertAction: TAction
      Caption = 'Инвертировать'
      OnExecute = InvertActionExecute
    end
    object CopyAction: TAction
      Caption = 'Создать копию рейса'
      Enabled = False
      Visible = False
    end
    object DeleteStopAction: TAction
      Caption = 'Удалить ост.пункт'
      OnExecute = DeleteStopActionExecute
    end
    object InsertStopAction: TAction
      Caption = 'Вставить ост.пункт'
      OnExecute = InsertStopActionExecute
    end
    object AppendStopAction: TAction
      Caption = 'Добавить ост.пункт'
      OnExecute = AppendStopActionExecute
    end
  end
  object FormStorage: TFormStorage
    StoredProps.Strings = (
      'ChainListView.Columns')
    StoredValues = <>
    Left = 320
    Top = 351
  end
end
