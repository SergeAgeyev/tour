object TourTripDiagramForm: TTourTripDiagramForm
  Left = 216
  Top = 135
  Width = 780
  Height = 573
  Caption = 'Диаграмма рейсов'
  Color = clBtnFace
  Constraints.MinHeight = 468
  Constraints.MinWidth = 754
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object HorizSplitter: TSplitter
    Left = 0
    Top = 330
    Width = 772
    Height = 3
    Cursor = crVSplit
    Align = alBottom
    AutoSnap = False
    MinSize = 100
  end
  object ChartScrollBox: TScrollBox
    Left = 0
    Top = 0
    Width = 772
    Height = 330
    Align = alClient
    Color = clWhite
    ParentColor = False
    TabOrder = 0
    object ChartPaintBox: TPaintBox
      Left = 0
      Top = 0
      Width = 768
      Height = 297
      Color = clWhite
      ParentColor = False
      PopupMenu = ChartPopupMenu
      OnMouseDown = ChartPaintBoxMouseDown
      OnMouseMove = ChartPaintBoxMouseMove
      OnMouseUp = ChartPaintBoxMouseUp
      OnPaint = ChartPaintBoxPaint
    end
  end
  object EditPanel: TPanel
    Left = 0
    Top = 333
    Width = 772
    Height = 213
    Align = alBottom
    TabOrder = 1
    object GroupToTimetableSplitter: TSplitter
      Left = 517
      Top = 42
      Width = 3
      Height = 170
      Cursor = crHSplit
      Align = alRight
      AutoSnap = False
    end
    object TourListView: TListView
      Left = 1
      Top = 42
      Width = 516
      Height = 170
      Align = alClient
      Checkboxes = True
      Columns = <
        item
          Caption = 'Время'
          Width = -1
          WidthType = (
            -1)
        end
        item
          Caption = 'Рейс'
          Width = -1
          WidthType = (
            -1)
        end
        item
          Caption = 'Скорость, км/ч'
          Width = -1
          WidthType = (
            -1)
        end
        item
          Caption = 'Отпр.'
          Width = -1
          WidthType = (
            -1)
        end
        item
          Caption = 'Приб.'
          Width = -1
          WidthType = (
            -1)
        end>
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      HideSelection = False
      ReadOnly = True
      RowSelect = True
      ParentFont = False
      PopupMenu = TourListViewPopupMenu
      SmallImages = FakeImageList
      SortType = stBoth
      TabOrder = 0
      ViewStyle = vsReport
      OnChange = TourListViewChange
      OnColumnClick = TourListViewColumnClick
      OnCompare = TourListViewCompare
      OnCustomDrawItem = TourListViewCustomDrawItem
      OnDblClick = TourListViewDblClick
      OnSelectItem = TourListViewSelectItem
    end
    object TimetableListView: TListView
      Left = 520
      Top = 42
      Width = 251
      Height = 170
      Align = alRight
      Columns = <
        item
          Caption = 'Пункт'
          Width = -1
          WidthType = (
            -1)
        end
        item
          Caption = 'Приб.'
          Width = -1
          WidthType = (
            -1)
        end
        item
          Caption = 'Отпр.'
          Width = -1
          WidthType = (
            -1)
        end
        item
          Caption = 'Ст.'
          Width = -1
          WidthType = (
            -1)
        end
        item
          Caption = 'Скорость,км/ч'
          Width = -1
          WidthType = (
            -1)
        end
        item
          Caption = 'Расстояние'
          Width = -1
          WidthType = (
            -1)
        end>
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      HideSelection = False
      ReadOnly = True
      RowSelect = True
      ParentFont = False
      TabOrder = 1
      ViewStyle = vsReport
      OnDblClick = TimetableListViewDblClick
    end
    object InfoPanel: TPanel
      Left = 1
      Top = 1
      Width = 770
      Height = 41
      Align = alTop
      TabOrder = 2
      object TimetableToHintSplitter: TSplitter
        Left = 766
        Top = 1
        Width = 3
        Height = 39
        Cursor = crHSplit
        Align = alRight
        AutoSnap = False
        MinSize = 175
      end
      object Panel1: TPanel
        Left = 1
        Top = 1
        Width = 352
        Height = 39
        Align = alLeft
        BevelInner = bvLowered
        TabOrder = 0
        object BusModelLabel: TLabel
          Left = 7
          Top = 4
          Width = 53
          Height = 13
          AutoSize = False
          BiDiMode = bdLeftToRight
          Caption = 'Автобус :'
          ParentBiDiMode = False
        end
        object BusModelValueLabel: TLabel
          Left = 59
          Top = 4
          Width = 41
          Height = 13
          Caption = 'Автобус'
        end
        object BusCapacityLabel: TLabel
          Left = 179
          Top = 5
          Width = 37
          Height = 13
          AutoSize = False
          BiDiMode = bdLeftToRight
          Caption = 'Мест :'
          ParentBiDiMode = False
        end
        object BusCapacityValueLabel: TLabel
          Left = 216
          Top = 5
          Width = 26
          Height = 13
          Caption = 'Мест'
        end
        object TripPathLengthLabel: TLabel
          Left = 5
          Top = 21
          Width = 70
          Height = 13
          AutoSize = False
          BiDiMode = bdLeftToRight
          Caption = 'Расстояние :'
          ParentBiDiMode = False
        end
        object TripPathLengthValueLabel: TLabel
          Left = 77
          Top = 21
          Width = 60
          Height = 13
          Caption = 'Расстояние'
        end
        object TripPathTimeLabel: TLabel
          Left = 178
          Top = 21
          Width = 73
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          BiDiMode = bdLeftToRight
          Caption = 'Время в пути :'
          ParentBiDiMode = False
        end
        object TripPathTimeValueLabel: TLabel
          Left = 256
          Top = 21
          Width = 67
          Height = 13
          Caption = 'Время в пути'
        end
      end
      object HintPanel: TPanel
        Left = 353
        Top = 1
        Width = 239
        Height = 39
        Align = alClient
        BevelInner = bvLowered
        TabOrder = 1
        object HintTimeLabel: TLabel
          Left = 8
          Top = 5
          Width = 33
          Height = 13
          Caption = 'Время'
        end
        object HintTimeValueLabel: TLabel
          Left = 48
          Top = 5
          Width = 33
          Height = 13
          AutoSize = False
          Caption = '00:00'
        end
        object HintFromLabel: TLabel
          Left = 88
          Top = 21
          Width = 13
          Height = 13
          Caption = 'От'
        end
        object HintToLabel: TLabel
          Left = 88
          Top = 5
          Width = 15
          Height = 13
          Caption = 'До'
        end
        object HintFromValueLabel: TLabel
          Left = 112
          Top = 21
          Width = 23
          Height = 13
          Caption = 'From'
        end
        object HintToValueLabel: TLabel
          Left = 112
          Top = 5
          Width = 13
          Height = 13
          Caption = 'To'
        end
      end
      object ButtonsPanel: TPanel
        Left = 592
        Top = 1
        Width = 174
        Height = 39
        Align = alRight
        BevelInner = bvLowered
        TabOrder = 2
        object OkButton: TButton
          Left = 10
          Top = 7
          Width = 75
          Height = 25
          Anchors = [akRight, akBottom]
          Caption = 'Сохранить'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBtnText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ModalResult = 1
          ParentFont = False
          TabOrder = 0
          OnClick = OkButtonClick
        end
        object CancelButton: TButton
          Left = 90
          Top = 7
          Width = 75
          Height = 25
          Anchors = [akRight, akBottom]
          Caption = 'Отменить'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBtnText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ModalResult = 2
          ParentFont = False
          TabOrder = 1
          OnClick = CancelButtonClick
        end
      end
    end
  end
  object FormStorage: TFormStorage
    StoredProps.Strings = (
      'TourListView.Columns'
      'TourListView.Width'
      'TimetableListView.Left'
      'TimetableListView.Columns'
      'TimetableListView.Width'
      'EditPanel.Top'
      'EditPanel.Height')
    StoredValues = <>
    Left = 30
    Top = 2
  end
  object FakeImageList: TImageList
    Left = 59
    Top = 1
  end
  object ChartPopupMenu: TPopupMenu
    Left = 2
    Top = 2
    object ScalePopupMenuItem: TMenuItem
      Caption = 'Масштаб'
      object ScaleFitToHeightPrcPopupMenuItem: TMenuItem
        Caption = 'По высоте'
        OnClick = ScaleFitToHeightPrcPopupMenuItemClick
      end
      object Scale25PrcPopupMenuItem: TMenuItem
        Caption = '25%'
        RadioItem = True
        OnClick = Scale25PrcPopupMenuItemClick
      end
      object Scale50PrcPopupMenuItem: TMenuItem
        Caption = '50%'
        RadioItem = True
        OnClick = Scale50PrcPopupMenuItemClick
      end
      object Scale75PrcPopupMenuItem: TMenuItem
        Caption = '75%'
        RadioItem = True
        OnClick = Scale75PrcPopupMenuItemClick
      end
      object Scale100PrcPopupMenuItem: TMenuItem
        Caption = '100%'
        Checked = True
        RadioItem = True
        OnClick = Scale100PrcPopupMenuItemClick
      end
      object Scale150PrcPopupMenuItem: TMenuItem
        Caption = '150%'
        RadioItem = True
        OnClick = Scale150PrcPopupMenuItemClick
      end
      object Scale200PrcPopupMenuItem: TMenuItem
        Caption = '200%'
        RadioItem = True
        OnClick = Scale200PrcPopupMenuItemClick
      end
      object Scale500PrcPopupMenuItem: TMenuItem
        Caption = '500%'
        OnClick = Scale500PrcPopupMenuItemClick
      end
    end
    object ShowGridPopupMenuItem: TMenuItem
      Caption = 'Показывать сетку'
      Checked = True
      OnClick = ShowGridPopupMenuItemClick
    end
    object ShowForwardToursPopupMenuItem: TMenuItem
      Caption = 'Отображать прямые рейсы'
      Checked = True
      OnClick = ShowForwardToursPopupMenuItemClick
    end
    object ShowBackwardToursPopupMenuItem: TMenuItem
      Caption = 'Отображать обратные рейсы'
      Checked = True
      OnClick = ShowBackwardToursPopupMenuItemClick
    end
    object ShowTourInOutRowPopupMenuItem: TMenuItem
      Caption = 'Отображать метки входа/выхода рейса'
      Checked = True
      OnClick = ShowTourInOutRowPopupMenuItemClick
    end
    object MonoColorToursPopupMenuItem: TMenuItem
      Caption = 'Одноцветные рейсы'
      Checked = True
      OnClick = MonoColorToursPopupMenuItemClick
    end
    object OptionsDialogPopupMenuItem: TMenuItem
      Caption = 'Настройка изображения...'
      OnClick = OptionsDialogPopupMenuItemClick
    end
    object PrintPopupMenuItem: TMenuItem
      Caption = 'Распечатать'
      object PrintTourInfoPopupMenuItem: TMenuItem
        Caption = 'Информация о рейсе'
        OnClick = PrintTourInfoPopupMenuItemClick
      end
      object PrintStopPopupMenuItem: TMenuItem
        Caption = 'Станционное расписание'
        OnClick = PrintStopPopupMenuItemClick
      end
      object PrintDiagramPopupMenuItem: TMenuItem
        Caption = 'Диаграмма'
        OnClick = PrintDiagramPopupMenuItemClick
      end
      object PrintDiagramFullPopupMenuItem: TMenuItem
        Caption = 'Диаграмма(полностью)'
        Visible = False
        OnClick = PrintDiagramFullPopupMenuItemClick
      end
    end
  end
  object TourListViewPopupMenu: TPopupMenu
    Left = 168
    Top = 434
    object TourMoveMenuItem: TMenuItem
      Action = TourMoveAction
    end
    object TourInvertMenuItem: TMenuItem
      Action = TourInvertAction
    end
    object TourCopyMenuItem: TMenuItem
      Action = TourCopyAction
    end
    object TourDeleteMenuItem: TMenuItem
      Action = TourDeleteAction
    end
  end
  object TourListViewActionList: TActionList
    Left = 136
    Top = 434
    object TourMoveAction: TAction
      Caption = 'Перенести рейс'
      OnExecute = TourMoveActionExecute
    end
    object TourInvertAction: TAction
      Caption = 'Инвертировать рейс'
      OnExecute = TourInvertActionExecute
    end
    object TourCopyAction: TAction
      Caption = 'Создать копию рейса'
      OnExecute = TourCopyActionExecute
    end
    object TourDeleteAction: TAction
      Caption = 'Удалить рейс'
      OnExecute = TourDeleteActionExecute
    end
  end
  object VStringStorage: TVStringStorage
    Lines.Strings = (
      'Перенос рейса'
      'Инвертирование рейса'
      'Создание копии рейса'
      'Отменить все изменения?'
      'Сохранить выбранные изменения?'
      'Отменить выбранные изменения?'
      'Изменения отсутствуют.'
      'Удалить рейс?'
      'Изменения успешно сохранены.')
    Left = 104
    Top = 434
  end
end
