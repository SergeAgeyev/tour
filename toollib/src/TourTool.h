//---------------------------------------------------------------------------
#ifndef TourToolH
#define TourToolH

#include <vcl.h>
//#include <ADODB.hpp>
//#include <stdio.h>

/*
  В данном модуле нельзя распологать функции использующие TourDataModule
  или другой подобный модуль.
*/
//---------------------------------------------------------------------------

//Макросы для вывода стандартных сообщений

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


// Получение локальной даты-времени
extern TDateTime   TourLocalDateTime              (void);

// Функция для вывода диалога с информацией об исключении
extern void        TourShowDialogException
                   (AnsiString                       *ErrorMessageStrPtr = NULL,
                    Exception                        *ExceptionPtr = NULL);

// Функция для вывода диалога с информацией об исключении
extern void        TourShowDialogExceptionStr
                   (AnsiString                       *ErrorMessageStrPtr = NULL,
                    AnsiString                       *ExceptionStrPtr = NULL);


#if !defined(TOUR_DEMO_MODE)

// Функция проверки существования записи в таблице
// В случае возникновения ошибки генерируется исключение (Exception)
// Количество элементов в KeyFieldListPtr и KeyValueListPtr
// должно быть одинаковым
extern bool        TourCheckRecordExist
                   (AnsiString                        TableNameStr,
                    TStringList                      *KeyFieldListPtr,
                    TStringList                      *KeyValueListPtr);

// Функция проверки существования марки автобуса в таблице bus
extern bool        TourCheckBusExist
                   (AnsiString                        BusModelStr);

// Функция проверки существования региона в таблице region
extern bool        TourCheckRegionExist
                   (AnsiString                        RegionIdStr);

// Функция проверки существования рейса в таблице paths
extern bool        TourCheckPathExist
                   (AnsiString                        FromStopIdStr,
                    AnsiString                        ToStopIdStr);

// Функция проверки существования рейса в таблице trip
extern bool        TourCheckTripExist
                   (AnsiString                        TripIdStr);

// Функция проверки существования рейса в таблице trip
extern bool        TourCheckStopExist
                   (AnsiString                        StopIdStr);

// Функция проверки существования модели ост.пункта в таблице stopmodel
extern bool        TourCheckStopModelExist
                   (AnsiString                        StopModelStr);

// Функция проверки существования владельца ост.пункта в таблице stopowner
extern bool        TourCheckStopOwnerExist
                   (AnsiString                        StopOwnerStr);

// Функция проверки существования владельца рейса в таблице tripowner
extern bool        TourCheckTripOwnerExist
                   (AnsiString                        TripOwnerStr);

// Функция проверки существования населенного пункта в таблице city
extern bool        TourCheckCityExist
                   (AnsiString                        CityZIPStr);

#endif

// имя инишника
extern AnsiString __fastcall TourDefaultIniNameStr(void);

// Функция получения параметров командной строки
extern bool        TourGetCommandLineParameter
                   (AnsiString                       *DataSourceNameStrPtr,
                    bool                             *DataBaseEditModeFlagPtr);
// Функция конвертации времени чч:mm:cc -> чч:mm
extern AnsiString  TourTimeStrByDateTime
                   (TDateTime                         DateTimeVar);

#if !defined(TOUR_DEMO_MODE)

// Функция добавления записи в таблицу
// В случае возникновения ошибки генерируется исключение (Exception)
// Количество элементов в KeyFieldListPtr и KeyValueListPtr
// должно быть одинаковым
extern bool        TourRecordAppend
                   (AnsiString                        TableNameStr,
                    TStringList                      *ValueListPtr);

// Функция добавления записи в таблицу Path
extern bool        TourPathRecordAppend
                   (AnsiString                        PathFromStopIdStr,
                    AnsiString                        PathToStopIdStr,
                    const float                      *PathLengthValuePtr = NULL,
                    const float                      *PathNormSpeedValuePtr = NULL);

// Пользовательский диалог добавления записи в таблицу Path
extern bool        TourPathRecordAppendDialog
                   (AnsiString                        PathFromStopId,
                    AnsiString                        PathToStopIdStr,
                    const float                      *PathLengthValuePtr = NULL,
                    const float                      *PathNormSpeedValuePtr = NULL);

// Функция получения записи в таблице по ключу
// В случае возникновения ошибки генерируется исключение (Exception)
// В случае нахождения нескольких записей возвращается первая
extern bool        TourGetRecord
                   (AnsiString                        TableNameStr,
                    TStringList                      *KeyFieldListPtr,
                    TStringList                      *KeyValueListPtr,
                    TStringList                      *UserFieldListPtr,
                    TStringList                      *UserValueListPtr);

// Функция получения записи в таблице Stop
extern bool        TourGetStopRecord
                   (AnsiString                        StopIdStr,
                    AnsiString                       *CityZIPStrPtr,
                    AnsiString                       *StopModelStrPtr,
                    AnsiString                       *StopOwnerIdStrPtr,
                    AnsiString                       *StopNameStrPtr);

// Функция получения StopName по StopId в таблице Stop
extern bool        TourGetStopNameById
                   (AnsiString                        StopIdStr,
                    AnsiString                       *StopNameStrPtr);
#endif

#endif

