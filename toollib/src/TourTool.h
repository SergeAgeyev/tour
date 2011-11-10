//---------------------------------------------------------------------------
#ifndef TourToolH
#define TourToolH

#include <vcl.h>
//#include <ADODB.hpp>
//#include <stdio.h>

/*
  � ������ ������ ������ ����������� ������� ������������ TourDataModule
  ��� ������ �������� ������.
*/
//---------------------------------------------------------------------------

//������� ��� ������ ����������� ���������

#define  TourShowDialogYesNo(MessageStr)         \
          Application->MessageBox(MessageStr,Application->Title.c_str(),MB_YESNO | MB_ICONQUESTION)
#define  TourShowDialogYesDefNo(MessageStr)         \
          Application->MessageBox(MessageStr,Application->Title.c_str(),MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1)
#define  TourShowDialogYesNoDef(MessageStr)         \
          Application->MessageBox(MessageStr,Application->Title.c_str(),MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2)

#define  TourShowDialogWarning(MessageStr)       \
              Application->MessageBox(MessageStr,Application->Title.c_str(),MB_OK | MB_ICONWARNING)

#define  TourShowDialogInformation(MessageStr)   \
              Application->MessageBox(MessageStr,Application->Title.c_str(),MB_OK | MB_ICONINFORMATION)

#define  TourShowDialogError(MessageStr)         \
              Application->MessageBox(MessageStr,Application->Title.c_str(),MB_OK | MB_ICONERROR)

#define  CursorWaitOpen()                        \
              {                                  \
               TCursor   CurrentCursor;          \
               CurrentCursor = Screen->Cursor;   \
               Screen->Cursor = crSQLWait

#define  CursorWaitClose();                      \
               Screen->Cursor = CurrentCursor;   \
              }


#define  TourToolCommaSymbolStr        ","
#define  TourToolDotSymbolStr          "."


// ��������� ��������� ����-�������
extern TDateTime   TourLocalDateTime              (void);

// ������� ��� ������ ������� � ����������� �� ����������
extern void        TourShowDialogException
                   (AnsiString                       *ErrorMessageStrPtr = NULL,
                    Exception                        *ExceptionPtr = NULL);

// ������� ��� ������ ������� � ����������� �� ����������
extern void        TourShowDialogExceptionStr
                   (AnsiString                       *ErrorMessageStrPtr = NULL,
                    AnsiString                       *ExceptionStrPtr = NULL);


#if !defined(TOUR_DEMO_MODE)

// ������� �������� ������������� ������ � �������
// � ������ ������������� ������ ������������ ���������� (Exception)
// ���������� ��������� � KeyFieldListPtr � KeyValueListPtr
// ������ ���� ����������
extern bool        TourCheckRecordExist
                   (AnsiString                        TableNameStr,
                    TStringList                      *KeyFieldListPtr,
                    TStringList                      *KeyValueListPtr);

// ������� �������� ������������� ����� �������� � ������� bus
extern bool        TourCheckBusExist
                   (AnsiString                        BusModelStr);

// ������� �������� ������������� ������� � ������� region
extern bool        TourCheckRegionExist
                   (AnsiString                        RegionIdStr);

// ������� �������� ������������� ����� � ������� paths
extern bool        TourCheckPathExist
                   (AnsiString                        FromStopIdStr,
                    AnsiString                        ToStopIdStr);

// ������� �������� ������������� ����� � ������� trip
extern bool        TourCheckTripExist
                   (AnsiString                        TripIdStr);

// ������� �������� ������������� ����� � ������� trip
extern bool        TourCheckStopExist
                   (AnsiString                        StopIdStr);

// ������� �������� ������������� ������ ���.������ � ������� stopmodel
extern bool        TourCheckStopModelExist
                   (AnsiString                        StopModelStr);

// ������� �������� ������������� ��������� ���.������ � ������� stopowner
extern bool        TourCheckStopOwnerExist
                   (AnsiString                        StopOwnerStr);

// ������� �������� ������������� ��������� ����� � ������� tripowner
extern bool        TourCheckTripOwnerExist
                   (AnsiString                        TripOwnerStr);

// ������� �������� ������������� ����������� ������ � ������� city
extern bool        TourCheckCityExist
                   (AnsiString                        CityZIPStr);

#endif

// ��� ��������
extern AnsiString __fastcall TourDefaultIniNameStr(void);

// ������� ��������� ���������� ��������� ������
extern bool        TourGetCommandLineParameter
                   (AnsiString                       *DataSourceNameStrPtr,
                    bool                             *DataBaseEditModeFlagPtr);
// ������� ����������� ������� ��:mm:cc -> ��:mm
extern AnsiString  TourTimeStrByDateTime
                   (TDateTime                         DateTimeVar);

#if !defined(TOUR_DEMO_MODE)

// ������� ���������� ������ � �������
// � ������ ������������� ������ ������������ ���������� (Exception)
// ���������� ��������� � KeyFieldListPtr � KeyValueListPtr
// ������ ���� ����������
extern bool        TourRecordAppend
                   (AnsiString                        TableNameStr,
                    TStringList                      *ValueListPtr);

// ������� ���������� ������ � ������� Path
extern bool        TourPathRecordAppend
                   (AnsiString                        PathFromStopIdStr,
                    AnsiString                        PathToStopIdStr,
                    const float                      *PathLengthValuePtr = NULL,
                    const float                      *PathNormSpeedValuePtr = NULL);

// ���������������� ������ ���������� ������ � ������� Path
extern bool        TourPathRecordAppendDialog
                   (AnsiString                        PathFromStopId,
                    AnsiString                        PathToStopIdStr,
                    const float                      *PathLengthValuePtr = NULL,
                    const float                      *PathNormSpeedValuePtr = NULL);

// ������� ��������� ������ � ������� �� �����
// � ������ ������������� ������ ������������ ���������� (Exception)
// � ������ ���������� ���������� ������� ������������ ������
extern bool        TourGetRecord
                   (AnsiString                        TableNameStr,
                    TStringList                      *KeyFieldListPtr,
                    TStringList                      *KeyValueListPtr,
                    TStringList                      *UserFieldListPtr,
                    TStringList                      *UserValueListPtr);

// ������� ��������� ������ � ������� Stop
extern bool        TourGetStopRecord
                   (AnsiString                        StopIdStr,
                    AnsiString                       *CityZIPStrPtr,
                    AnsiString                       *StopModelStrPtr,
                    AnsiString                       *StopOwnerIdStrPtr,
                    AnsiString                       *StopNameStrPtr);

// ������� ��������� StopName �� StopId � ������� Stop
extern bool        TourGetStopNameById
                   (AnsiString                        StopIdStr,
                    AnsiString                       *StopNameStrPtr);
#endif

#endif

