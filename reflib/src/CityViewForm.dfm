inherited TourRefBookCityViewForm: TTourRefBookCityViewForm
  Caption = '���������� ������'
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited ToolBar: TToolBar
    Visible = True
  end
  inherited ActionList: TActionList
    inherited NewAction: TAction
      OnExecute = NewActionExecute
    end
    inherited EditAction: TAction
      OnExecute = EditActionExecute
    end
  end
  inherited MainDBGridFilterDialog: TVDBGridFilterDialog
    Fields = <
      item
        Caption = '��� ������'
        FieldName = 'city_zip'
      end
      item
        Caption = '��� �������'
        FieldName = 'region_id'
      end
      item
        Caption = '�������� �����.������'
        FieldName = 'city_name'
      end
      item
        Caption = '���������'
        FieldName = 'city_population'
      end>
  end
  inherited MainQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' city_zip,'
      ' region_id,'
      ' city_name,'
      ' city_population'
      'FROM'
      ' city'
      ' ')
    object MainQuerycity_zip: TStringField
      DisplayLabel = '��� ������'
      FieldName = 'city_zip'
      Size = 10
    end
    object MainQuerycity_name: TStringField
      DisplayLabel = '�������� ����������� ������'
      FieldName = 'city_name'
      Size = 50
    end
    object MainQuerycity_population: TIntegerField
      DisplayLabel = '���������'
      FieldName = 'city_population'
    end
    object MainQueryregion_id: TStringField
      DisplayLabel = '��� �������'
      FieldName = 'region_id'
      Size = 10
    end
    object MainQueryregion_name: TStringField
      DisplayLabel = '�������� �������'
      FieldKind = fkLookup
      FieldName = 'region_name'
      LookupDataSet = RegionQuery
      LookupKeyFields = 'region_id'
      LookupResultField = 'region_name'
      KeyFields = 'region_id'
      Lookup = True
    end
  end
  object RegionQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' region_id,'
      ' region_name'
      'FROM'
      ' region')
    Left = 64
    Top = 296
  end
end
