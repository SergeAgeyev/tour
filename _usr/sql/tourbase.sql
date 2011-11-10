--============================================================================
-- 
-- создан: 17:57:09 14/03/2002
-- 
--============================================================================

--============================================================================
-- Table : Bus
--============================================================================
create table Bus (
   Bus_Model            VARCHAR(15)                     not null,
   Bus_Desc             VARCHAR(50),
   Bus_Capacity         INTEGER,
   Bus_SpeedFactor      FLOAT,
primary key (Bus_Model)
      constraint PK_BUS
);
--============================================================================
-- Table : City
--============================================================================
create table City (
   City_ZIP             VARCHAR(10)                     not null,
   Region_Id            VARCHAR(10),
   City_Name            VARCHAR(50),
   City_Population      INTEGER,
primary key (City_ZIP)
      constraint PK_CITY
);
--============================================================================
-- Table : Path
--============================================================================
create table Path (
   Path_FromStopId      VARCHAR(10)                     not null,
   Path_ToStopId        VARCHAR(10)                     not null,
   Path_Length          FLOAT,
   Path_NormSpeed       FLOAT,
primary key (Path_FromStopId, Path_ToStopId)
      constraint PK_PATH
);
--============================================================================
-- Table : Region
--============================================================================
create table Region (
   Region_Id            VARCHAR(10)                     not null,
   Region_Name          VARCHAR(50),
primary key (Region_Id)
      constraint PK_REGION
);
--============================================================================
-- Table : Stats
--============================================================================
create table Stats (
   Trip_Id              VARCHAR(10)                     not null,
   Stats_Date           DATETIME YEAR TO SECOND         not null,
   Stats_FromStopId     VARCHAR(10)                     not null,
   Stats_ToStopId       VARCHAR(10)                     not null,
   Stats_Flow           INTEGER,
primary key (Trip_Id, Stats_FromStopId, Stats_ToStopId, Stats_Date)
      constraint PK_STATS
);
--============================================================================
-- Table : Stop
--============================================================================
create table Stop (
   Stop_Id              VARCHAR(10)                     not null,
   City_ZIP             VARCHAR(10)                     not null,
   Stop_Model           VARCHAR(5),
   StopOwner_Id         VARCHAR(10),
   Stop_Name            VARCHAR(50),
primary key (Stop_Id)
      constraint PK_STOP
);
--============================================================================
-- Table : StopModel
--============================================================================
create table StopModel (
   Stop_Model           VARCHAR(5)                      not null,
   StopModel_Name       VARCHAR(50),
primary key (Stop_Model)
      constraint PK_STOPMODEL
);
--============================================================================
-- Table : StopOwner
--============================================================================
create table StopOwner (
   StopOwner_Id         VARCHAR(10)                     not null,
   StopOwner_Name       VARCHAR(50),
primary key (StopOwner_Id)
      constraint PK_STOPOWNER
);
--============================================================================
-- Table : Trip
--============================================================================
create table Trip (
   Trip_Id              VARCHAR(10)                     not null,
   Bus_Model            VARCHAR(15),
   TripOwner_Id         VARCHAR(10),
   Trip_Name            VARCHAR(50),
   Trip_Notes           VARCHAR(50),
primary key (Trip_Id)
      constraint PK_TRIP
);
--============================================================================
-- Table : TripOwner
--============================================================================
create table TripOwner (
   TripOwner_Id         VARCHAR(10)                     not null,
   TripOwner_Name       VARCHAR(50),
primary key (TripOwner_Id)
      constraint PK_TRIPOWNER
);
--============================================================================
-- Table : TripStep
--============================================================================
create table TripStep (
   Trip_Id              VARCHAR(10)                     not null,
   TripStep_Num         INTEGER                         not null,
   Stop_Id              VARCHAR(10)                     not null,
   Path_ToStopId        VARCHAR(10)                     not null,
   TripStep_InTime      DATETIME HOUR TO SECOND,
   TripStep_WaitTime    DATETIME HOUR TO SECOND,
primary key (Trip_Id, TripStep_Num)
      constraint PK_TRIPSTEP
);
alter table Stop
   add constraint (foreign key (City_ZIP)
      references City (City_ZIP)
      
      constraint  FK_REFEREN_CITY
);
alter table Stop
   add constraint (foreign key (StopOwner_Id)
      references StopOwner (StopOwner_Id)
      
      constraint  FK_REFEREN_STOPOWN
);
alter table City
   add constraint (foreign key (Region_Id)
      references Region (Region_Id)
      
      constraint  FK_REFEREN_REGION
);
alter table Stats
   add constraint (foreign key (Trip_Id)
      references Trip (Trip_Id)
      
      constraint  FK_REFEREN_TRIP
);
alter table Stats
   add constraint (foreign key (Stats_FromStopId)
      references Stop (Stop_Id)
      
      constraint  FK_REFEREN_STOP5
);
alter table Stats
   add constraint (foreign key (Stats_ToStopId)
      references Stop (Stop_Id)
      
      constraint  FK_REFEREN_STOP
);
alter table Stop
   add constraint (foreign key (Stop_Model)
      references StopModel (Stop_Model)
      
      constraint  FK_REFEREN_STOPMOD
);
alter table Path
   add constraint (foreign key (Path_FromStopId)
      references Stop (Stop_Id)
      
      constraint  FK_REFEREN_STOP2
);
alter table Path
   add constraint (foreign key (Path_ToStopId)
      references Stop (Stop_Id)
      
      constraint  FK_REFEREN_STOP3
);
alter table Trip
   add constraint (foreign key (Bus_Model)
      references Bus (Bus_Model)
      
      constraint  FK_REFEREN_BUS
);
alter table TripStep
   add constraint (foreign key (Trip_Id)
      references Trip (Trip_Id)
      
      constraint  FK_REFEREN_TRIP2
);
alter table TripStep
   add constraint (foreign key (Stop_Id)
      references Stop (Stop_Id)
      
      constraint  FK_REFEREN_STOP4
);
alter table Trip
   add constraint (foreign key (TripOwner_Id)
      references TripOwner (TripOwner_Id)
      
      constraint  FK_REFEREN_TRIPOWN
);
alter table TripStep
   add constraint (foreign key (Stop_Id, Path_ToStopId)
      references Path (Path_FromStopId, Path_ToStopId)
      
      constraint  FK_REFEREN_PATH
);



