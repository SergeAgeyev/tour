object TourSessionTimeForm: TTourSessionTimeForm
  Left = 192
  Top = 156
  BorderIcons = [biSystemMenu, biMaximize]
  BorderStyle = bsDialog
  Caption = 'Время'
  ClientHeight = 26
  ClientWidth = 221
  Color = clHighlightText
  DefaultMonitor = dmDesktop
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object TimeLabel: TLabel
    Left = 4
    Top = 6
    Width = 213
    Height = 13
    Alignment = taCenter
    AutoSize = False
  end
  object Timer: TTimer
    Enabled = False
    Interval = 500
    OnTimer = TimerTimer
    Top = 65535
  end
end
