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
      Caption = '&�����'
      Hint = '���� ������'
      object SessionCurrentDateMenuItem: TMenuItem
        Action = SessionCurrentDateAction
        Enabled = False
        Hint = '�������� ������� ����'
        Visible = False
      end
      object SessionCurrentTimeMenuItem: TMenuItem
        Action = SessionCurrentTimeAction
        Enabled = False
        Hint = '�������� ������� �����'
        Visible = False
      end
      object SessionSeparatorMenuItem: TMenuItem
        Caption = '-'
        Enabled = False
        Visible = False
      end
      object SessionExitMenuItem: TMenuItem
        Action = SessionExitAction
        Hint = '����� �� ������'
      end
    end
    object SetupMenuItem: TMenuItem
      Caption = '&���������'
      Enabled = False
      Hint = '��������� ����������'
      Visible = False
    end
    object DoMenuItem: TMenuItem
      Caption = '&������'
      object DoFlightDiagramMenuItem: TMenuItem
        Action = DoFlightDiagramAction
        Hint = '�������� ������������ ������'
      end
      object DoFlightDiagramWizardMenuItem: TMenuItem
        Action = DoFlightDiagramWizardAction
      end
    end
    object ReportsMenuItem: TMenuItem
      Caption = '�&�����'
      Hint = '������ ���������� ��������'
      object ReportsStopInfoMenuItem: TMenuItem
        Caption = '����������� ����������'
        OnClick = ReportsStopInfoMenuItemClick
      end
      object ReportsTripInfoMenuItem: TMenuItem
        Caption = '���������� � �����'
        OnClick = ReportsTripInfoMenuItemClick
      end
    end
    object DataBaseMenuItem: TMenuItem
      Caption = '&����'
      Hint = '������� ���������� ��������'
      object DoFlightDataNewMenuItem: TMenuItem
        Action = DoFlightDataNewAction
        Hint = '������ ����� ����� ������'
      end
      object ObjectsTopologyMenuItem: TMenuItem
        Caption = '���������'
        Hint = '�������������� �������'
        object ObjectsPopulatedPointsMenuItem: TMenuItem
          Action = ObjectsTopologyPopulatedPointsAction
          Hint = '�������� ���������� �������'
        end
        object ObjectsRegionsMenuItem: TMenuItem
          Action = ObjectsTopologyRegionsAction
          Hint = '�������� ��������'
        end
        object ObjectsStopPointsMenuItem: TMenuItem
          Action = ObjectsTopologyStopPointsAction
          Hint = '�������� ������������ �������'
        end
        object ObjectsWayAreasMenuItem: TMenuItem
          Action = ObjectsTopologyWayAreasAction
          Hint = '�������� ������� ��������'
        end
      end
      object ObjectsTransportationsMenuItem: TMenuItem
        Caption = '���������'
        Hint = '������� ���������'
        object ObjectsFlightsMenuItem: TMenuItem
          Action = ObjectsTransportationsFlightsAction
          Hint = '�������� ������'
        end
        object ObjectsFlightTimetableMenuItem: TMenuItem
          Action = ObjectsTranportationsFlightTimetableAction
          Hint = '������ ���������� ������'
        end
        object ObjectsTransportStatisticsMenuItem: TMenuItem
          Action = ObjectsTransportationsTransportStatisticsAction
          Hint = '���������� ���������� ���������'
        end
      end
      object ObjectsStopPointOwnersMenuItem: TMenuItem
        Action = ObjectsStopPointOwnersAction
        Hint = '������ ���������� ������������ �������'
      end
      object ObjectsTransportersMenuItem: TMenuItem
        Action = ObjectsTransportersAction
        Hint = '�������� ������������'
      end
      object SetupStopPointTypesMenuItem: TMenuItem
        Action = SetupStopPointTypesAction
        Hint = '��������� ������������ �������'
      end
      object SetupTransportTypesMenuItem: TMenuItem
        Action = SetupTransportTypesAction
        Hint = '��������� ����� ����������'
      end
      object N2: TMenuItem
        Action = BaseRegulationAction
      end
    end
    object WindowMenuItem: TMenuItem
      Caption = '�&���'
      Hint = '���������� ������ �������'
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
      Caption = '&�������'
      Hint = '���������� ����������'
      object HelpUserGuideMenuItem: TMenuItem
        Caption = '����������� ������������'
        Hint = '����������� ������������'
      end
      object HelpSeparatorMenuItem: TMenuItem
        Caption = '-'
      end
      object HelpAboutMenuItem: TMenuItem
        Action = HelpAboutAction
        Hint = '�������� �������� � ���������'
      end
    end
  end
  object ActionList: TActionList
    Left = 32
    Top = 384
    object HelpAboutAction: TAction
      Category = 'Help'
      Caption = '� ���������'
      OnExecute = HelpAboutActionExecute
    end
    object SessionExitAction: TAction
      Category = 'Session'
      Caption = '&�����'
      OnExecute = SessionExitActionExecute
    end
    object ObjectsTransportationsFlightsAction: TAction
      Category = 'Objects'
      Caption = '�����'
      OnExecute = ObjectsTransportationsFlightsActionExecute
    end
    object ObjectsTopologyPopulatedPointsAction: TAction
      Category = 'Objects'
      Caption = '���������� ������'
      OnExecute = ObjectsTopologyPopulatedPointsActionExecute
    end
    object SetupStopPointTypesAction: TAction
      Category = 'Setup'
      Caption = '���� ������������ �������'
      OnExecute = SetupStopPointTypesActionExecute
    end
    object ObjectsTranportationsFlightTimetableAction: TAction
      Category = 'Objects'
      Caption = '���������� ������'
      OnExecute = ObjectsTranportationsFlightTimetableActionExecute
    end
    object SetupTransportTypesAction: TAction
      Category = 'Setup'
      Caption = '���� ����������'
      OnExecute = SetupTransportTypesActionExecute
    end
    object WindowCascadeAction: TWindowCascade
      Category = 'Window'
      Caption = '&��������'
      ImageIndex = 17
    end
    object WindowTileHorzAction: TWindowTileHorizontal
      Category = 'Window'
      Caption = '&�������������'
      ImageIndex = 15
    end
    object WindowTileVertAction: TWindowTileVertical
      Category = 'Window'
      Caption = '&�����������'
      ImageIndex = 16
    end
    object WindowMinimizeAllAction: TWindowMinimizeAll
      Category = 'Window'
      Caption = '&��������'
    end
    object WindowArrangeAction: TWindowArrange
      Category = 'Window'
      Caption = '&�����������'
    end
    object SessionCurrentDateAction: TAction
      Category = 'Session'
      Caption = '������� ����'
      OnExecute = SessionCurrentDateActionExecute
    end
    object SessionCurrentTimeAction: TAction
      Category = 'Session'
      Caption = '������� �����'
      OnExecute = SessionCurrentTimeActionExecute
    end
    object DoFlightDataNewAction: TAction
      Category = 'Do'
      Caption = '���� ������ ������ �����'
      OnExecute = DoFlightDataNewActionExecute
    end
    object ObjectsTopologyRegionsAction: TAction
      Category = 'Objects'
      Caption = '�������'
      OnExecute = ObjectsTopologyRegionsActionExecute
    end
    object ObjectsTopologyStopPointsAction: TAction
      Category = 'Objects'
      Caption = '������������ ������'
      OnExecute = ObjectsTopologyStopPointsActionExecute
    end
    object DoFlightDiagramAction: TAction
      Category = 'Do'
      Caption = '��������� ������'
      OnExecute = DoFlightDiagramActionExecute
    end
    object ObjectsTopologyWayAreasAction: TAction
      Category = 'Objects'
      Caption = '������� ����'
      OnExecute = ObjectsTopologyWayAreasActionExecute
    end
    object ObjectsTransportationsTransportStatisticsAction: TAction
      Category = 'Objects'
      Caption = '���������� ���������'
      OnExecute = ObjectsTransportationsTransportStatisticsActionExecute
    end
    object ObjectsStopPointOwnersAction: TAction
      Category = 'Objects'
      Caption = '��������� ������������ �������'
      OnExecute = ObjectsStopPointOwnersActionExecute
    end
    object ObjectsTransportersAction: TAction
      Category = 'Objects'
      Caption = '�����������'
      OnExecute = ObjectsTransportersActionExecute
    end
    object DoFlightDiagramWizardAction: TAction
      Category = 'Do'
      Caption = '��������� ������ (������)'
      OnExecute = DoFlightDiagramWizardActionExecute
    end
    object BaseRegulationAction: TAction
      Category = 'Base'
      Caption = '��������� ���� ������'
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
      '������������ ������ ��� �������� ���������� ������� '
      '������ ���������� ������� '
      '������ ��������� �������, ������� ��������� ����?'
      '��������� ������ ����������?')
    Left = 612
    Top = 384
  end
end
