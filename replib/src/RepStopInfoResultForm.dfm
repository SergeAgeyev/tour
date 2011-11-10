object TourStopInfoResultForm: TTourStopInfoResultForm
  Left = 221
  Top = 191
  Width = 696
  Height = 480
  Caption = 'Станционное расписание по остановочному пункту'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object Report: TQuickRep
    Left = 8
    Top = 48
    Width = 794
    Height = 1123
    Frame.Color = clBlack
    Frame.DrawTop = False
    Frame.DrawBottom = False
    Frame.DrawLeft = False
    Frame.DrawRight = False
    DataSet = ReportQuery
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    Functions.Strings = (
      'PAGENUMBER'
      'COLUMNNUMBER'
      'REPORTTITLE')
    Functions.DATA = (
      '0'
      '0'
      #39#39)
    Options = [FirstPageHeader, LastPageFooter]
    Page.Columns = 1
    Page.Orientation = poPortrait
    Page.PaperSize = A4
    Page.Values = (
      100
      2970
      100
      2100
      100
      100
      0)
    PrinterSettings.Copies = 1
    PrinterSettings.Duplex = False
    PrinterSettings.FirstPage = 0
    PrinterSettings.LastPage = 0
    PrinterSettings.OutputBin = Auto
    PrintIfEmpty = True
    SnapToGrid = True
    Units = MM
    Zoom = 100
    object TitleBand: TQRBand
      Left = 38
      Top = 38
      Width = 718
      Height = 91
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Courier'
      Font.Style = []
      ForceNewColumn = False
      ForceNewPage = False
      ParentFont = False
      Size.Values = (
        240.770833333333
        1899.70833333333)
      BandType = rbTitle
      object StopIdLabel: TQRLabel
        Left = 0
        Top = 8
        Width = 145
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          0
          21.1666666666667
          383.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'Остановочный пункт'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object StopIdDBText: TQRDBText
        Left = 152
        Top = 8
        Width = 57
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          402.166666666667
          21.1666666666667
          150.8125)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ReportQuery
        DataField = 'stop_id'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object StopNameDBText: TQRDBText
        Left = 216
        Top = 8
        Width = 73
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          571.5
          21.1666666666667
          193.145833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ReportQuery
        DataField = 'stop_name'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object FirstTitleDelimeterLabel: TQRLabel
        Left = 0
        Top = 24
        Width = 473
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          0
          63.5
          1251.47916666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '-----------------------------------------------------------'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object SecondTitleDelimeterLabel: TQRLabel
        Left = 0
        Top = 72
        Width = 473
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          0
          190.5
          1251.47916666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '-----------------------------------------------------------'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripIdFirstLabel: TQRLabel
        Left = 0
        Top = 40
        Width = 41
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          0
          105.833333333333
          108.479166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'Номер'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripNameFirstLabel: TQRLabel
        Left = 168
        Top = 40
        Width = 65
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          444.5
          105.833333333333
          171.979166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'Название'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripStepInTimeFirstTitleLabel: TQRLabel
        Left = 312
        Top = 40
        Width = 41
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          825.5
          105.833333333333
          108.479166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'Прибы'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripStepWaitTimeFirstTitleLabel: TQRLabel
        Left = 424
        Top = 40
        Width = 41
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1121.83333333333
          105.833333333333
          108.479166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'Стоян'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripStepOutTimeFirstTitleLabel: TQRLabel
        Left = 368
        Top = 40
        Width = 49
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          973.666666666667
          105.833333333333
          129.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'Отправ'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripIdSecondLabel: TQRLabel
        Left = 0
        Top = 56
        Width = 41
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          0
          148.166666666667
          108.479166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'рейса'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripNameSecondLabel: TQRLabel
        Left = 176
        Top = 56
        Width = 41
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          465.666666666667
          148.166666666667
          108.479166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'рейса'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripStepInTimeSecondTitleLabel: TQRLabel
        Left = 320
        Top = 56
        Width = 25
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          846.666666666667
          148.166666666667
          66.1458333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'тие'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripStepOutTimeSecondTitleLabel: TQRLabel
        Left = 368
        Top = 56
        Width = 41
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          973.666666666667
          148.166666666667
          108.479166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'ление'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripStepWaitTimeSecondTitleLabel: TQRLabel
        Left = 432
        Top = 56
        Width = 17
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1143
          148.166666666667
          44.9791666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'ка'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object DetailBand: TQRBand
      Left = 38
      Top = 129
      Width = 718
      Height = 40
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = DetailBandBeforePrint
      Color = clWhite
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Courier'
      Font.Style = []
      ForceNewColumn = False
      ForceNewPage = False
      ParentFont = False
      Size.Values = (
        105.833333333333
        1899.70833333333)
      BandType = rbDetail
      object TripIdDBText: TQRDBText
        Left = 0
        Top = 8
        Width = 40
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          0
          21.1666666666667
          105.833333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = ReportQuery
        DataField = 'trip_id'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripNameDBText: TQRDBText
        Left = 48
        Top = 8
        Width = 250
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          127
          21.1666666666667
          661.458333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = ReportQuery
        DataField = 'trip_name'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripStepOutTimeLabel: TQRLabel
        Left = 360
        Top = 8
        Width = 50
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          952.5
          21.1666666666667
          132.291666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'TripStepOutTimeLabel'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripStepInTimeLabel: TQRLabel
        Left = 304
        Top = 8
        Width = 50
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          804.333333333333
          21.1666666666667
          132.291666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'TripStepInTimeLabel'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripStepWaitTimeLabel: TQRLabel
        Left = 416
        Top = 8
        Width = 50
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1100.66666666667
          21.1666666666667
          132.291666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'TripStepWaitTimeLabel'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object SummaryBand: TQRBand
      Left = 38
      Top = 169
      Width = 718
      Height = 32
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Courier'
      Font.Style = []
      ForceNewColumn = False
      ForceNewPage = False
      ParentFont = False
      Size.Values = (
        84.6666666666667
        1899.70833333333)
      BandType = rbSummary
      object SummaryDelimeterLabel: TQRLabel
        Left = 0
        Top = 8
        Width = 473
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          0
          21.1666666666667
          1251.47916666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '-----------------------------------------------------------'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
  end
  object ReportQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <
      item
        Name = 'StopIdValue'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT   Trip.Trip_Id,'
      '         Trip.Trip_Name,'
      '         TripStep.TripStep_InTime,'
      '         TripStep.TripStep_WaitTime,'
      '         TripStep.Stop_Id,'
      '         Stop.Stop_Name'
      'FROM     Trip,TripStep,Stop'
      'WHERE    TripStep.Stop_Id = :StopIdValue AND'
      '         TripStep.Stop_Id = Stop.Stop_Id AND'
      '         TripStep.Trip_Id = Trip.Trip_Id'
      'ORDER BY TripStep.TripStep_InTime,Trip.Trip_Id;')
    Left = 8
    Top = 8
  end
end
