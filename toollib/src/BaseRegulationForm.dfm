object TourBaseRegulationForm: TTourBaseRegulationForm
  Left = 192
  Top = 104
  BorderStyle = bsDialog
  Caption = 'Регламент базы данных'
  ClientHeight = 329
  ClientWidth = 490
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
  object RichEdit: TRichEdit
    Left = 0
    Top = 0
    Width = 489
    Height = 281
    Lines.Strings = (
      'Для запуска нажмите кнопку "Старт" ...')
    ReadOnly = True
    TabOrder = 0
  end
  object CancelButton: TButton
    Left = 407
    Top = 296
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 2
  end
  object OkButton: TButton
    Left = 320
    Top = 296
    Width = 75
    Height = 25
    Caption = 'Старт'
    Default = True
    TabOrder = 1
    OnClick = OkButtonClick
  end
  object VStringStorage: TVStringStorage
    Lines.Strings = (
      'Генерация обратных путей'
      ' - просмотрено участков пути: '
      ' - односторонних участков: '
      ' - создано обратных участков: ')
    Left = 8
    Top = 288
  end
  object GenerationReversePathQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'INSERT INTO Paths (Path_FromStopId,Path_ToStopId,Path_Length)'
      'SELECT '
      ' Path_ToStopId,Path_FromStopId,Path_Length '
      'FROM Paths DirectPaths'
      'WHERE NOT EXISTS '
      ' (SELECT *'
      '  FROM Paths BackPaths'
      
        '  WHERE BackPaths.Path_FromStopId = DirectPaths.Path_ToStopId AN' +
        'D'
      '        BackPaths.Path_ToStopId = DirectPaths.Path_FromStopId);')
    Left = 40
    Top = 288
  end
  object PathCountQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' COUNT(*) as Result'
      'FROM'
      ' paths')
    Left = 72
    Top = 288
  end
  object DirectPathCountQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT '
      ' COUNT(*) as Result'
      'FROM Paths DirectPaths'
      'WHERE NOT EXISTS '
      ' (SELECT *'
      '  FROM Paths BackPaths'
      
        '  WHERE BackPaths.Path_FromStopId = DirectPaths.Path_ToStopId AN' +
        'D'
      '        BackPaths.Path_ToStopId = DirectPaths.Path_FromStopId);')
    Left = 104
    Top = 288
  end
end
