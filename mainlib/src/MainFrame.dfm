object TourMainFrame: TTourMainFrame
  Left = 370
  Top = 226
  Width = 654
  Height = 480
  Caption = 'Tour'
  Color = clAppWorkSpace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = MainMenu
  OldCreateOrder = False
  Position = poDesktopCenter
  WindowState = wsMaximized
  WindowMenu = WindowMenuItem
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar: TStatusBar
    Left = 0
    Top = 416
    Width = 646
    Height = 18
    Panels = <
      item
        Width = 50
      end
      item
        Alignment = taCenter
        Width = 250
      end
      item
        Alignment = taCenter
        Width = 100
      end>
    SimplePanel = False
    OnResize = StatusBarResize
  end
  object MainMenu: TMainMenu
    Left = 1
    Top = 384
    object SessionMenuItem: TMenuItem
      Caption = '&Сеанс'
      Hint = 'Меню сеанса'
      object SessionCurrentDateMenuItem: TMenuItem
        Action = SessionCurrentDateAction
        Enabled = False
        Hint = 'Показать текущую дату'
        Visible = False
      end
      object SessionCurrentTimeMenuItem: TMenuItem
        Action = SessionCurrentTimeAction
        Enabled = False
        Hint = 'Показать текущее время'
        Visible = False
      end
      object SessionSeparatorMenuItem: TMenuItem
        Caption = '-'
        Enabled = False
        Visible = False
      end
      object SessionExitMenuItem: TMenuItem
        Action = SessionExitAction
        Hint = 'Выход из задачи'
      end
    end
    object SetupMenuItem: TMenuItem
      Caption = '&Настройки'
      Enabled = False
      Hint = 'Настройка параметров'
      Visible = False
    end
    object DoMenuItem: TMenuItem
      Caption = '&Работа'
      object DoFlightDiagramMenuItem: TMenuItem
        Action = DoFlightDiagramAction
        Hint = 'Диграммы существующих рейсов'
      end
      object DoFlightDiagramWizardMenuItem: TMenuItem
        Action = DoFlightDiagramWizardAction
      end
    end
    object ReportsMenuItem: TMenuItem
      Caption = 'О&тчеты'
      Hint = 'Отчеты выдаваемые системой'
      object ReportsStopInfoMenuItem: TMenuItem
        Caption = 'Станционное расписание'
        OnClick = ReportsStopInfoMenuItemClick
      end
      object ReportsTripInfoMenuItem: TMenuItem
        Caption = 'Информация о рейсе'
        OnClick = ReportsTripInfoMenuItemClick
      end
    end
    object DataBaseMenuItem: TMenuItem
      Caption = '&База'
      Hint = 'Объекты управления системой'
      object DoFlightDataNewMenuItem: TMenuItem
        Action = DoFlightDataNewAction
        Hint = 'Визард ввода новых рейсов'
      end
      object ObjectsTopologyMenuItem: TMenuItem
        Caption = 'Топология'
        Hint = 'Топологические объекты'
        object ObjectsPopulatedPointsMenuItem: TMenuItem
          Action = ObjectsTopologyPopulatedPointsAction
          Hint = 'Перечень населенных пунктов'
        end
        object ObjectsRegionsMenuItem: TMenuItem
          Action = ObjectsTopologyRegionsAction
          Hint = 'Перечень регионов'
        end
        object ObjectsStopPointsMenuItem: TMenuItem
          Action = ObjectsTopologyStopPointsAction
          Hint = 'Перечень остановочных пунктов'
        end
        object ObjectsWayAreasMenuItem: TMenuItem
          Action = ObjectsTopologyWayAreasAction
          Hint = 'Перечень путевых участков'
        end
      end
      object ObjectsTransportationsMenuItem: TMenuItem
        Caption = 'Перевозки'
        Hint = 'Объекты перевозок'
        object ObjectsFlightsMenuItem: TMenuItem
          Action = ObjectsTransportationsFlightsAction
          Hint = 'Перечень рейсов'
        end
        object ObjectsFlightTimetableMenuItem: TMenuItem
          Action = ObjectsTranportationsFlightTimetableAction
          Hint = 'Список расписаний рейсов'
        end
        object ObjectsTransportStatisticsMenuItem: TMenuItem
          Action = ObjectsTransportationsTransportStatisticsAction
          Hint = 'Обобщенная статистика перевозок'
        end
      end
      object ObjectsStopPointOwnersMenuItem: TMenuItem
        Action = ObjectsStopPointOwnersAction
        Hint = 'Список владельцев установочных пунктов'
      end
      object ObjectsTransportersMenuItem: TMenuItem
        Action = ObjectsTransportersAction
        Hint = 'Перечень перевозчиков'
      end
      object SetupStopPointTypesMenuItem: TMenuItem
        Action = SetupStopPointTypesAction
        Hint = 'Настройка остановочных пунктов'
      end
      object SetupTransportTypesMenuItem: TMenuItem
        Action = SetupTransportTypesAction
        Hint = 'Настройка видов транспорта'
      end
      object N2: TMenuItem
        Action = BaseRegulationAction
      end
    end
    object WindowMenuItem: TMenuItem
      Caption = 'О&кна'
      Hint = 'Управление окнами системы'
      object WindowArrangeMenuItem: TMenuItem
        Action = WindowArrangeAction
      end
      object WindowCascadeMenuItem: TMenuItem
        Action = WindowCascadeAction
      end
      object WindowTileHorzMenuItem: TMenuItem
        Action = WindowTileHorzAction
      end
      object WindowTileVertMenuItem: TMenuItem
        Action = WindowTileVertAction
      end
      object WindowMinimizeAllMenuItem: TMenuItem
        Action = WindowMinimizeAllAction
      end
    end
    object HelpMenuItem: TMenuItem
      Caption = '&Справка'
      Hint = 'Справочная информация'
      object HelpUserGuideMenuItem: TMenuItem
        Caption = 'Руководство пользователя'
        Hint = 'Руководство пользователя'
      end
      object HelpSeparatorMenuItem: TMenuItem
        Caption = '-'
      end
      object HelpAboutMenuItem: TMenuItem
        Action = HelpAboutAction
        Hint = 'Основные сведенья о программе'
      end
    end
  end
  object ActionList: TActionList
    Left = 32
    Top = 384
    object HelpAboutAction: TAction
      Category = 'Help'
      Caption = 'О программе'
      OnExecute = HelpAboutActionExecute
    end
    object SessionExitAction: TAction
      Category = 'Session'
      Caption = '&Выход'
      OnExecute = SessionExitActionExecute
    end
    object ObjectsTransportationsFlightsAction: TAction
      Category = 'Objects'
      Caption = 'Рейсы'
      OnExecute = ObjectsTransportationsFlightsActionExecute
    end
    object ObjectsTopologyPopulatedPointsAction: TAction
      Category = 'Objects'
      Caption = 'Населенные пункты'
      OnExecute = ObjectsTopologyPopulatedPointsActionExecute
    end
    object SetupStopPointTypesAction: TAction
      Category = 'Setup'
      Caption = 'Виды остановочных пунктов'
      OnExecute = SetupStopPointTypesActionExecute
    end
    object ObjectsTranportationsFlightTimetableAction: TAction
      Category = 'Objects'
      Caption = 'Расписание рейсов'
      OnExecute = ObjectsTranportationsFlightTimetableActionExecute
    end
    object SetupTransportTypesAction: TAction
      Category = 'Setup'
      Caption = 'Виды транспорта'
      OnExecute = SetupTransportTypesActionExecute
    end
    object WindowCascadeAction: TWindowCascade
      Category = 'Window'
      Caption = '&Каскадом'
      ImageIndex = 17
    end
    object WindowTileHorzAction: TWindowTileHorizontal
      Category = 'Window'
      Caption = '&Горизонтально'
      ImageIndex = 15
    end
    object WindowTileVertAction: TWindowTileVertical
      Category = 'Window'
      Caption = '&Вертикально'
      ImageIndex = 16
    end
    object WindowMinimizeAllAction: TWindowMinimizeAll
      Category = 'Window'
      Caption = '&Свернуть'
    end
    object WindowArrangeAction: TWindowArrange
      Category = 'Window'
      Caption = '&Расположить'
    end
    object SessionCurrentDateAction: TAction
      Category = 'Session'
      Caption = 'Текущая дата'
      OnExecute = SessionCurrentDateActionExecute
    end
    object SessionCurrentTimeAction: TAction
      Category = 'Session'
      Caption = 'Текущее время'
      OnExecute = SessionCurrentTimeActionExecute
    end
    object DoFlightDataNewAction: TAction
      Category = 'Do'
      Caption = 'Ввод данных нового рейса'
      OnExecute = DoFlightDataNewActionExecute
    end
    object ObjectsTopologyRegionsAction: TAction
      Category = 'Objects'
      Caption = 'Регионы'
      OnExecute = ObjectsTopologyRegionsActionExecute
    end
    object ObjectsTopologyStopPointsAction: TAction
      Category = 'Objects'
      Caption = 'Остановочные пункты'
      OnExecute = ObjectsTopologyStopPointsActionExecute
    end
    object DoFlightDiagramAction: TAction
      Category = 'Do'
      Caption = 'Диаграмма рейсов'
      OnExecute = DoFlightDiagramActionExecute
    end
    object ObjectsTopologyWayAreasAction: TAction
      Category = 'Objects'
      Caption = 'Участки пути'
      OnExecute = ObjectsTopologyWayAreasActionExecute
    end
    object ObjectsTransportationsTransportStatisticsAction: TAction
      Category = 'Objects'
      Caption = 'Статистика перевозок'
      OnExecute = ObjectsTransportationsTransportStatisticsActionExecute
    end
    object ObjectsStopPointOwnersAction: TAction
      Category = 'Objects'
      Caption = 'Владельцы остановочных пунктов'
      OnExecute = ObjectsStopPointOwnersActionExecute
    end
    object ObjectsTransportersAction: TAction
      Category = 'Objects'
      Caption = 'Перевозчики'
      OnExecute = ObjectsTransportersActionExecute
    end
    object DoFlightDiagramWizardAction: TAction
      Category = 'Do'
      Caption = 'Диаграмма рейсов (мастер)'
      OnExecute = DoFlightDiagramWizardActionExecute
    end
    object BaseRegulationAction: TAction
      Category = 'Base'
      Caption = 'Регламент базы данных'
      OnExecute = BaseRegulationActionExecute
    end
  end
  object ClockTimer: TTimer
    Enabled = False
    Interval = 500
    OnTimer = ClockTimerTimer
    Left = 64
    Top = 384
  end
  object DataTimer: TTimer
    Enabled = False
    Interval = 180000
    OnTimer = DataTimerTimer
    Left = 96
    Top = 384
  end
  object VStringStorage: TVStringStorage
    Lines.Strings = (
      'Недостаточно памяти для создания экземпляра объекта '
      'Ошибка исполнения функции '
      'Данные добавлены успешно, вводить следующий рейс?'
      'Завершить работу приложения?')
    Left = 612
    Top = 384
  end
end
