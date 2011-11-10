object TourTripInfoResultForm: TTourTripInfoResultForm
  Left = 217
  Top = 190
  Width = 696
  Height = 480
  Caption = 'Информация по рейсу'
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
    Left = 16
    Top = 32
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
      Height = 107
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
        283.104166666667
        1899.70833333333)
      BandType = rbTitle
      object TripIdLabel: TQRLabel
        Left = 0
        Top = 8
        Width = 89
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          0
          21.1666666666667
          235.479166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'Номер рейса'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripIdDBText: TQRDBText
        Left = 96
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
          254
          21.1666666666667
          150.8125)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ReportQuery
        DataField = 'trip_id'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object BasModelLabel: TQRLabel
        Left = 0
        Top = 24
        Width = 57
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
          150.8125)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'Автобус'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object BusModelDBText: TQRDBText
        Left = 64
        Top = 24
        Width = 73
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          169.333333333333
          63.5
          193.145833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ReportQuery
        DataField = 'bus_model'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object FirstTitleDelimeterLabel: TQRLabel
        Left = 0
        Top = 40
        Width = 393
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
          1039.8125)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '-------------------------------------------------'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object SecondTitleDelimeterLabel: TQRLabel
        Left = 0
        Top = 88
        Width = 393
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          0
          232.833333333333
          1039.8125)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '-------------------------------------------------'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object StopIdFirstLabel: TQRLabel
        Left = 32
        Top = 56
        Width = 97
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          84.6666666666667
          148.166666666667
          256.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'Остановочный'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripStepInTimeFirstTitleLabel: TQRLabel
        Left = 168
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
          444.5
          148.166666666667
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
        Left = 280
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
          740.833333333333
          148.166666666667
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
        Left = 224
        Top = 56
        Width = 49
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          592.666666666667
          148.166666666667
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
      object TripNameDBText: TQRDBText
        Left = 160
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
          423.333333333333
          21.1666666666667
          193.145833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ReportQuery
        DataField = 'trip_name'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object PathLengthFirstTitleLabel: TQRLabel
        Left = 328
        Top = 56
        Width = 57
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          867.833333333333
          148.166666666667
          150.8125)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'Расстоя'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object StopIdSecondLabel: TQRLabel
        Left = 64
        Top = 72
        Width = 41
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          169.333333333333
          190.5
          108.479166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'пункт'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripStepInTimeSecondTitleLabel: TQRLabel
        Left = 176
        Top = 72
        Width = 25
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          465.666666666667
          190.5
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
        Left = 224
        Top = 72
        Width = 41
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          592.666666666667
          190.5
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
        Left = 288
        Top = 72
        Width = 17
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          762
          190.5
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
      object PathLengthSecondTitleLabel: TQRLabel
        Left = 344
        Top = 72
        Width = 25
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          910.166666666667
          190.5
          66.1458333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'ние'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object DetailBand: TQRBand
      Left = 38
      Top = 145
      Width = 718
      Height = 32
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AfterPrint = DetailBandAfterPrint
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
        84.6666666666667
        1899.70833333333)
      BandType = rbDetail
      object StopIdDBText: TQRDBText
        Left = 0
        Top = 8
        Width = 150
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
          396.875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = ReportQuery
        DataField = 'stop_name'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TripStepOutTimeLabel: TQRLabel
        Left = 216
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
          571.5
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
        Left = 158
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
          418.041666666667
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
        Left = 272
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
          719.666666666667
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
      object PathLengthLabel: TQRLabel
        Left = 335
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
          886.354166666667
          21.1666666666667
          132.291666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'PathLengthLabel'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object SummaryBand: TQRBand
      Left = 38
      Top = 177
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
        Width = 393
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
          1039.8125)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '-------------------------------------------------'
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
        Name = 'TripIdValue'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'TripIdAddValue'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT   Trip.Trip_Id,'
      '         Trip.Bus_Model,'
      '         Trip.Trip_Name,'
      '         TripStep.TripStep_Num,'
      '         TripStep.TripStep_InTime,'
      '         TripStep.TripStep_WaitTime,'
      '         Stop.Stop_Name,'
      '         Paths.Path_Length'
      'FROM     Trip,'
      '         TripStep,'
      '         Stop,'
      '         Paths'
      'WHERE    Trip.Trip_Id          = :TripIdValue            AND'
      '         Trip.Trip_Id          = TripStep.Trip_Id        AND'
      '         TripStep.Stop_Id      = Stop.Stop_Id            AND'
      '         Paths.Path_FromStopId = TripStep.Stop_Id        AND'
      '         Paths.Path_ToStopId   = TripStep.Path_ToStopId'
      ''
      'UNION'
      ''
      'SELECT   Trip.Trip_Id,'
      '         Trip.Bus_Model,'
      '         Trip.Trip_Name,'
      '         TripStep.TripStep_Num,'
      '         TripStep.TripStep_InTime,'
      '         TripStep.TripStep_WaitTime,'
      '         Stop.Stop_Name,'
      '         0'
      'FROM     Trip,'
      '         TripStep,'
      '         Stop'
      'WHERE    Trip.Trip_Id          = :TripIdAddValue         AND'
      '         Trip.Trip_Id          = TripStep.Trip_Id        AND'
      '         TripStep.Stop_Id      = Stop.Stop_Id            AND'
      '         TripStep.Path_ToStopId IS NULL'
      ''
      'ORDER BY 4;'
      '')
    Left = 16
  end
end
