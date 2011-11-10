object TourTripSwitchDialogForm: TTourTripSwitchDialogForm
  Left = 192
  Top = 107
  Width = 587
  Height = 408
  Caption = 'Выбор рейсов'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object TourListView: TListView
    Left = 0
    Top = 0
    Width = 579
    Height = 340
    Align = alClient
    Checkboxes = True
    Columns = <
      item
        Caption = 'Время (баз.), приб.'
      end
      item
        Caption = 'Название'
        Width = 300
      end
      item
        Caption = 'Рейс'
      end
      item
        Caption = 'Время отпр.'
      end
      item
        Caption = 'Время приб.'
      end
      item
        Caption = 'Расстояние'
      end
      item
        Caption = 'Скорость,км/ч'
        Width = 83
      end>
    GridLines = True
    MultiSelect = True
    ReadOnly = True
    RowSelect = True
    SortType = stBoth
    TabOrder = 0
    ViewStyle = vsReport
    OnChange = TourListViewChange
    OnChanging = TourListViewChanging
    OnColumnClick = TourListViewColumnClick
    OnCompare = TourListViewCompare
  end
  object Panel: TPanel
    Tag = 10
    Left = 0
    Top = 340
    Width = 579
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    OnResize = PanelResize
    object NextButton: TButton
      Tag = 10
      Left = 414
      Top = 8
      Width = 75
      Height = 25
      Anchors = [akTop]
      Caption = 'Ok'
      Default = True
      ModalResult = 1
      TabOrder = 0
    end
    object CancelButton: TButton
      Tag = 10
      Left = 495
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
  object VStringStorage: TVStringStorage
    Lines.Strings = (
      'Выбор рейса')
    Left = 336
    Top = 345
  end
  object ActionList: TActionList
    Left = 368
    Top = 344
  end
  object FormStorage: TFormStorage
    StoredValues = <>
    Left = 304
    Top = 343
  end
end
