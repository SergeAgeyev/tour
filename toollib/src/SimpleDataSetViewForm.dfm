inherited TourSimpleDataSetViewForm: TTourSimpleDataSetViewForm
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited Panel: TPanel
    TabOrder = 1
    inherited CancelButton: TButton
      Caption = 'Отмена'
    end
  end
  object ListView: TListView [2]
    Left = 0
    Top = 0
    Width = 517
    Height = 232
    Align = alClient
    Columns = <>
    GridLines = True
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = ()
  end
end
