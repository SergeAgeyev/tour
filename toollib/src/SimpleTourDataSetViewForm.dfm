inherited TourSimpleTourDataSetViewForm: TTourSimpleTourDataSetViewForm
  BorderStyle = bsSizeable
  Caption = 'Выбор рейса'
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  inherited Panel: TPanel
    Tag = 10
    OnResize = PanelResize
    inherited OkButton: TButton
      Anchors = [akTop]
    end
    inherited CancelButton: TButton
      Anchors = [akTop]
    end
  end
  inherited ListView: TListView
    Columns = <
      item
        Caption = 'Код'
        Width = 100
      end
      item
        Caption = 'Название'
        Width = 400
      end>
    SortType = stBoth
    OnColumnClick = ListViewColumnClick
    OnCompare = ListViewCompare
  end
  inherited VStringStorage: TVStringStorage
    Lines.Strings = (
      'Не выбран рейс')
  end
  object FormStorage: TFormStorage
    StoredValues = <>
    Left = 288
    Top = 240
  end
end
