#!/usr/bin/python

import string
import sys
import time
import dbi
import odbc

MaxLongWordStr = '0x7FFFFFFFL'

class TourClass:
    def __init__(self):
        self.Id                = None
        self.Name              = None
        self.BusModel          = None
        self.StopScheduleIndex = None
        self.StopScheduleSize  = None

Connection = None
HeaderFile = None
SourceFile = None

def ShowUsage():
    print
    print 'Usage: python dbdump2src.py DSN HeaderFileName SourceFileName'

def DumpTable(ArrayName,EntryType,Query):
    HeaderFile.write('extern %s %s[];\n' % (EntryType,ArrayName))
    SourceFile.write('%s %s[] =\n' % (EntryType,ArrayName))
    SourceFile.write(' {\n')

    Cursor = Connection.cursor()
    Cursor.execute(Query)

    Result = Cursor.fetchone()

    while Result != None:
        ValueArray = []

        for FieldIndex in xrange(len(Cursor.description)):
            if Cursor.description[FieldIndex][1] == 'STRING':
                if Result[FieldIndex] != None:
                    ValueArray.append('"%s"' % Result[FieldIndex])
                else:
                    ValueArray.append('""')
            else:
                if Result[FieldIndex] != None:
                    ValueArray.append(str(Result[FieldIndex]))
                else:
                    ValueArray.append("0")

        SourceFile.write('  { %s },\n' % string.join(ValueArray,' , '))

        Result = Cursor.fetchone()

    Cursor.close()

    SourceFile.write(' };\n')
    SourceFile.write('\n')
    HeaderFile.write('\n')


def DumpTourInfo():
    HeaderFile.write('extern TourDemoStopScheduleType TourDemoDataStopScheduleArray[];\n')
    HeaderFile.write('\n')
    SourceFile.write('TourDemoStopScheduleType TourDemoDataStopScheduleArray[] =\n')
    SourceFile.write(' {\n')
    StopScheduleCount = 0

    TourCursor = Connection.cursor()
    TourCursor.execute('SELECT Trip_Id,Trip_Name,Bus_Model FROM Trip')

    TourArray  = []
    TourResult = TourCursor.fetchone()

    while TourResult != None:
        Tour = TourClass()

        Tour.Id                = TourResult[0]
        Tour.Name              = TourResult[1]
        Tour.BusModel          = TourResult[2]
        Tour.StopScheduleIndex = StopScheduleCount

        ScheduleCursor = Connection.cursor()

        ScheduleCursor.execute("""
         SELECT
          Stop_Id,
          Hour(TripStep_InTime),
          Minute(TripStep_InTime),
          Hour(TripStep_WaitTime),
          Minute(TripStep_WaitTime)
         FROM
          TripStep
         WHERE
          Trip_Id = '%s'
         ORDER BY
          TripStep_Num
         """ % Tour.Id)

        ScheduleResult = ScheduleCursor.fetchone()
        StopCounter    = 0

        while ScheduleResult != None:
            StopScheduleCount = StopScheduleCount + 1
            StopCounter       = StopCounter + 1

            if ScheduleResult[1] != None:
                InTime = str(int(ScheduleResult[1]) * 60 + ScheduleResult[2])
            else:
                InTime = MaxLongWordStr

            if ScheduleResult[3] != None:
                WaitTime = str(int(ScheduleResult[3]) * 60 + ScheduleResult[4])
            else:
                WaitTime = MaxLongWordStr

            SourceFile.write('  { "%s" , %s , %s },\n' % (ScheduleResult[0],InTime,WaitTime))

            ScheduleResult = ScheduleCursor.fetchone()

        Tour.StopScheduleCount = StopCounter

        TourArray.append(Tour)

        TourResult = TourCursor.fetchone()

    TourCursor.close()

    SourceFile.write(' };\n')
    SourceFile.write('\n')

    HeaderFile.write('extern TourDemoTourType TourDemoDataTourArray[];\n')
    HeaderFile.write('\n')
    SourceFile.write('TourDemoTourType TourDemoDataTourArray[] =\n')
    SourceFile.write(' {\n')

    for Tour in TourArray:
        SourceFile.write('  { "%s" , "%s" , "%s" , %s , %s },\n' % (Tour.Id,Tour.Name,Tour.BusModel,Tour.StopScheduleIndex,Tour.StopScheduleCount))

    SourceFile.write(' };\n')
    SourceFile.write('\n')

if len(sys.argv) != 4:
    ShowUsage()
    sys.exit(1)

DSN            = sys.argv[1]
HeaderFileName = sys.argv[2]
SourceFileName = sys.argv[3]

Connection = odbc.odbc(DSN)
HeaderFile = open(HeaderFileName,'wt')
SourceFile = open(SourceFileName,'wt')

HeaderFile.write('#ifndef __TourDemoDataH__\n')
HeaderFile.write('#define __TourDemoDataH__\n')
HeaderFile.write('\n')
HeaderFile.write('#include <TourDataDM.h>\n')
HeaderFile.write('\n')

SourceFile.write('#include <TourDataDM.h>\n')
SourceFile.write('#include <TourDemoData.h>\n')
SourceFile.write('\n')

DumpTable('TourDemoDataStopArray',
          'TourDemoStopType',
          'SELECT Stop_Id,Stop_Name FROM Stop')

DumpTable('TourDemoDataBusArray',
          'TourDemoBusType',
          'SELECT Bus_Model,Bus_Desc,Bus_Capacity FROM Bus')

DumpTable('TourDemoDataTopologyArray',
          'TourDemoTopologyType',
          'SELECT Path_FromStopId,Path_ToStopId,Path_Length FROM Paths')

DumpTourInfo()

HeaderFile.write('extern TourDemoDataType TourDemoData;\n')
HeaderFile.write('\n')

SourceFile.write('\n')
SourceFile.write('#define DeclaredArraySize(Array) (sizeof(Array) / sizeof(Array[0]))\n')
SourceFile.write('\n')

SourceFile.write('TourDemoDataType TourDemoData =\n')
SourceFile.write(' {\n')
SourceFile.write('  TourDemoDataBusArray,\n')
SourceFile.write('  DeclaredArraySize(TourDemoDataBusArray),\n')
SourceFile.write('  TourDemoDataStopArray,\n')
SourceFile.write('  DeclaredArraySize(TourDemoDataStopArray),\n')
SourceFile.write('  TourDemoDataStopScheduleArray,\n')
SourceFile.write('  DeclaredArraySize(TourDemoDataStopScheduleArray),\n')
SourceFile.write('  TourDemoDataTourArray,\n')
SourceFile.write('  DeclaredArraySize(TourDemoDataTourArray),\n')
SourceFile.write('  TourDemoDataTopologyArray,\n')
SourceFile.write('  DeclaredArraySize(TourDemoDataTopologyArray)\n')
SourceFile.write(' };\n')
SourceFile.write('\n')

HeaderFile.write('#endif\n')

HeaderFile.close()
SourceFile.close()
Connection.close()

