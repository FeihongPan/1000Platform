/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        appconfig.cpp
* Description:      AppConfig模块数据类型
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-2-19
* Modify Record：
***********************************************************************/

#include "appconfig.h"

AppConfig::AppConfig()
{
    appDataPath = "C:/App_Data/";
    appDataPath_Backup = "D:/App_Data/";
    LocalIP = "127.0.0.1";
    serverAdd.IP = "192.168.1.101";
    serverAdd.port = 1883;
}

AppConfig::AppConfig(const AppConfig &instance)
{
    appDataPath = instance.appDataPath;
    appDataPath_Backup = instance.appDataPath_Backup;
    LocalIP = instance.LocalIP;
    serverAdd.IP = instance.serverAdd.IP;
    serverAdd.port = instance.serverAdd.port;
}

AppConfig &AppConfig::operator=(const AppConfig &instance)
{
    appDataPath = instance.appDataPath;
    appDataPath_Backup = instance.appDataPath_Backup;
    LocalIP = instance.LocalIP;
    serverAdd.IP = instance.serverAdd.IP;
    serverAdd.port = instance.serverAdd.port;
    return *this;
}
