/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        appconfigsubscriber.cpp
* Description:      AppConfigSubscriber订阅者，发送当前AppConfig数据结构
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-2-19
* Modify Record：
***********************************************************************/

#include "appconfigsubscriber.h"
#include "AppConfig/Command/cmd_appconfig.h"
#include "Converter/enumconverter.h"
#include "AppConfig/Manager/appconfigmanager.h"

#include <QMutex>

AppConfigSubscriber *AppConfigSubscriber::self = nullptr;

AppConfigSubscriber::AppConfigSubscriber(QString name, QObject *parent) : ISubscriber(name, parent)
{

}

AppConfigSubscriber::~AppConfigSubscriber()
{

}

AppConfigSubscriber *AppConfigSubscriber::getInstance()
{
    if(nullptr == self)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(nullptr == self)
        {
            self = new AppConfigSubscriber("AppConfigSubscriber");
        }
    }
    return self;
}

void AppConfigSubscriber::decoding(const QString &topic, const QByteArray &message)
{
    TaskInfo task_Recived;
    task_Recived.fromJson(message);
    CMD_AppConfig::Command cmd = EnumConverter::ConvertStringToEnum<CMD_AppConfig::Command>(task_Recived.task);
    switch (cmd)
    {
        case CMD_AppConfig::CMD_Config:
        {
            QByteArray message = AppConfigManager::getInstance()->GetAppConfig().toRawJson();
            AppConfigManager::getInstance()->Publish(EnumConverter::ConvertToString(CMD_AppConfig::CMD_Config), true, message);
        }
        break;

        default:
            break;
    }
}


