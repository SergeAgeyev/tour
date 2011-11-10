object TourDataDBModule: TTourDataDBModule
  OldCreateOrder = False
  Left = 65522
  Top = 125
  Height = 426
  Width = 734
  object StopSetQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    CursorType = ctOpenForwardOnly
    Parameters = <>
    SQL.Strings = (
      'SELECT Stop_Id FROM Stop')
    Left = 24
    Top = 8
  end
  object StopDistanceQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    CursorType = ctOpenForwardOnly
    Parameters = <
      item
        Name = 'FromStopId'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'ToStopId'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT Path_Length'
      'FROM Paths'
      'WHERE Path_FromStopId = :FromStopId AND'
      '      Path_ToStopId = :ToStopId'
      ' ')
    Left = 112
    Top = 8
  end
  object TourInfoQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    CursorType = ctOpenForwardOnly
    Parameters = <
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT Trip_Name,Bus_Model FROM Trip WHERE Trip_Id = :TripId')
    Left = 24
    Top = 56
  end
  object StopInfoQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    CursorType = ctOpenForwardOnly
    Parameters = <
      item
        Name = 'StopId'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT Stop_Name FROM Stop WHERE Stop_Id = :StopId')
    Left = 200
    Top = 56
  end
  object TourAverageSpeedQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    CursorType = ctOpenForwardOnly
    Parameters = <
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT'
      ' CurrStep.TripStep_InTime     AS CurrInTime,'
      ' CurrStep.TripStep_WaitTime AS CurrWaitTime,'
      ' NextStep.TripStep_InTime    AS NextInTime,'
      ' Paths.Path_Length               AS PathLength'
      'FROM'
      ' TripStep AS CurrStep,'
      ' TripStep AS NextStep,'
      ' Paths'
      'WHERE'
      ' CurrStep.Trip_Id = :TripId AND'
      ' NextStep.Trip_Id = CurrStep.Trip_Id AND'
      ' NextStep.TripStep_Num = (CurrStep.TripStep_Num + 1) AND'
      ' Paths.Path_FromStopId = CurrStep.Stop_Id AND'
      ' Paths.Path_ToStopId   = NextStep.Stop_Id'
      'ORDER BY'
      ' CurrStep.TripStep_Num')
    Left = 48
    Top = 112
  end
  object TourScheduleQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    CursorType = ctOpenForwardOnly
    Parameters = <
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT Stop_Id,TripStep_InTime,TripStep_WaitTime'
      'FROM TripStep'
      'WHERE Trip_Id = :TripId'
      'ORDER BY TripStep_Num')
    Left = 112
    Top = 56
  end
  object TourDeleteQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    CursorType = ctOpenForwardOnly
    Parameters = <
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'DELETE FROM Trip WHERE Trip_Id = :TripId')
    Left = 152
    Top = 112
  end
  object TourAppendQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    CursorType = ctOpenForwardOnly
    Parameters = <
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'INSERT INTO Trip (Trip_Id) VALUES (:TripId)')
    Left = 240
    Top = 112
  end
  object TourScheduleDeleteAllQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    CursorType = ctOpenForwardOnly
    Parameters = <
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'DELETE FROM TripStep WHERE Trip_Id = :TripId')
    Left = 56
    Top = 160
  end
  object TourScheduleAppendStopQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'StepNum'
        DataType = ftInteger
        Size = -1
        Value = Null
      end
      item
        Name = 'StopId'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'ToStopId'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      
        'INSERT INTO TripStep (Trip_Id,TripStep_Num,Stop_Id,Path_ToStopId' +
        ')'
      'VALUES (:TripId,:StepNum,:StopId,:ToStopId)')
    Left = 208
    Top = 161
  end
  object TourScheduleDeleteStopQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'StepNum'
        DataType = ftInteger
        Size = -1
        Value = Null
      end>
    SQL.Strings = (
      'DELETE FROM TripStep '
      'WHERE Trip_Id = :TripId AND'
      '               TripStep_Num = :StepNum')
    Left = 64
    Top = 216
  end
  object TourScheduleDecStepNumQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'StepNum'
        DataType = ftInteger
        Size = -1
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE TripStep'
      'SET TripStep_Num = TripStep_Num - 1'
      'WHERE Trip_Id = :TripId AND TripStep_Num > :StepNum')
    Left = 232
    Top = 216
  end
  object TourScheduleUpdateToStopIdQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <
      item
        Name = 'StopId'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'StepNum'
        DataType = ftInteger
        Size = -1
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE TripStep'
      'SET Path_ToStopId = :StopId'
      'WHERE Trip_Id = :TripId AND TripStep_Num = :StepNum')
    Left = 56
    Top = 272
  end
  object TourScheduleIncStepNumQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'StepNum'
        DataType = ftInteger
        Size = -1
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE TripStep'
      'SET TripStep_Num = TripStep_Num + 1'
      'WHERE Trip_Id = :TripId AND TripStep_Num >= :StepNum')
    Left = 232
    Top = 272
  end
  object TourStopScheduleSetInTimeQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <
      item
        Name = 'InTime'
        DataType = ftDateTime
        Size = -1
        Value = Null
      end
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'StepNum'
        DataType = ftInteger
        Size = -1
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE TripStep'
      'SET TripStep_InTime = :InTime'
      'WHERE Trip_Id = :TripId AND TripStep_Num = :StepNum')
    Left = 296
    Top = 8
  end
  object TourSetQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    CursorType = ctOpenForwardOnly
    Parameters = <>
    Left = 184
    Top = 8
  end
  object TourStopScheduleSetWaitTimeQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <
      item
        Name = 'WaitTime'
        DataType = ftDateTime
        Size = -1
        Value = Null
      end
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end
      item
        Name = 'StepNum'
        DataType = ftInteger
        Size = -1
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE TripStep'
      'SET TripStep_WaitTime = :WaitTime'
      'WHERE Trip_Id = :TripId AND TripStep_Num = :StepNum')
    Left = 368
    Top = 72
  end
  object TourSetNameQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    Parameters = <
      item
        Name = 'TripName'
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE Trip'
      'SET Trip_Name = :TripName'
      'WHERE Trip_Id = :TripId')
    Left = 384
    Top = 136
  end
  object TourTotalDistanceQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    CursorType = ctOpenForwardOnly
    Parameters = <
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'SELECT SUM(Paths.Path_Length)'
      'FROM Paths, TripStep'
      'WHERE '
      ' Paths.Path_FromStopId = TripStep.Stop_Id AND'
      ' Paths.Path_ToStopId = TripStep.Path_ToStopId AND'
      ' TripStep.Trip_Id = :TripId')
    Left = 352
    Top = 200
  end
  object BusInfoQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    CursorType = ctOpenForwardOnly
    Parameters = <
      item
        Name = 'BusModel'
        DataType = ftString
        Size = 15
        Value = Null
      end>
    SQL.Strings = (
      'SELECT Bus_Desc,Bus_Capacity '
      'FROM Bus '
      'WHERE Bus_Model = :BusModel')
    Left = 368
    Top = 272
  end
  object TourSetBusModelQuery: TADOQuery
    Connection = TourDataModule.TourDataBaseConnection
    CursorType = ctOpenForwardOnly
    Parameters = <
      item
        Name = 'BusModel'
        DataType = ftString
        Size = 15
        Value = Null
      end
      item
        Name = 'TripId'
        DataType = ftString
        Size = 10
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE Trip'
      'SET Bus_Model = :BusModel'
      'WHERE Trip_Id = :TripId')
    Left = 424
    Top = 184
  end
end
