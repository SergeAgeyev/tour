inherited TourRefBookStopModelViewForm: TTourRefBookStopModelViewForm
  Caption = 'Виды остановочных пунктов'
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
        Caption = 'Тип'
        FieldName = 'stop_model'
      end
      item
        Caption = 'Наименование'
        FieldName = 'stopmodel_name'
      end>
  end
  inherited MainQuery: TADOQuery
    SQL.Strings = (
      'SELECT'
      ' stop_model,'
      ' stopmodel_name'
      'FROM'
      ' stopmodel'
      ' ')
    object MainQueryStopModel_id: TStringField
      DisplayLabel = 'Тип'
      DisplayWidth = 5
      FieldName = 'stop_model'
      Size = 5
    end
    object MainQueryStopModel_name: TStringField
      DisplayLabel = 'Наименование'
      FieldName = 'stopmodel_name'
      Size = 50
    end
  end
end
