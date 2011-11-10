inherited TourPathViewForm: TTourPathViewForm
  Caption = '������� ����'
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
        Caption = '��� ���.������'
        FieldName = 'path_fromstopid'
      end
      item
        Caption = '��� ���.������'
        FieldName = 'path_tostopid'
      end
      item
        Caption = '����������'
        FieldName = 'path_length'
      end
      item
        Caption = '����.��������'
        FieldName = 'path_normspeed'
      end>
  end
  inherited MainQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' path_fromstopid,'
      ' path_tostopid,'
      ' path_length,'
      ' path_normspeed'
      'FROM'
      ' paths'
      ' ')
    object MainQueryPath_fromstopid: TStringField
      DisplayLabel = '��� ���.������'
      FieldName = 'path_fromstopid'
      Size = 10
    end
    object MainQueryfromstopid_name: TStringField
      DisplayLabel = '��������� �����'
      FieldKind = fkLookup
      FieldName = 'fromstopid_name'
      LookupDataSet = StopQuery
      LookupKeyFields = 'stop_id'
      LookupResultField = 'stop_name'
      KeyFields = 'path_fromstopid'
      Size = 50
      Lookup = True
    end
    object MainQueryPath_tostopid: TStringField
      DisplayLabel = '��� ���.������'
      FieldName = 'path_tostopid'
      Size = 10
    end
    object MainQuerytostopid_name: TStringField
      DisplayLabel = '�������� �����'
      FieldKind = fkLookup
      FieldName = 'tostopid_name'
      LookupDataSet = StopQuery
      LookupKeyFields = 'stop_id'
      LookupResultField = 'stop_name'
      KeyFields = 'Path_tostopid'
      Size = 50
      Lookup = True
    end
    object MainQuerypath_length: TFloatField
      DisplayLabel = '����������'
      FieldName = 'path_length'
    end
    object MainQuerypath_normspeed: TFloatField
      DisplayLabel = '����.��������'
      FieldName = 'path_normspeed'
    end
  end
  object StopQuery: TADOQuery [12]
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' stop_id,'
      ' stop_name'
      'FROM'
      ' stop')
    Left = 64
    Top = 296
  end
end
