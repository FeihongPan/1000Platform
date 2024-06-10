#include "Logger/loggermanager.h"
#include "FileSystem/fileoperatormanager.h"
#include "AppConfig/Manager/appconfigmanager.h"
#include "Communication/MQTT/mqttclientmanager.h"
#include "NetworkEquipmentMonitor/Manage/heartbeat.h"

#include <iostream>
#include <QCoreApplication>

using namespace NS_Log;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // MqttClient
    AppConfigManager::getInstance()->SetPath(m_AppConfig.appDataPath + "AppConfig", m_AppConfig.appDataPath_Backup + "AppConfig",
            "appConfig.json", m_AppConfig.appDataPath + "CommunicationCommand");
    AppConfigManager::getInstance()->Initialize(); // Read Config Data
    MqttClientManager::getInstance()->AddClient(0, "Platform");

    // AppConfig
    AppConfig config;
    if (AppConfigManager::getInstance()->IsInitialized())
    {
        config = AppConfigManager::getInstance()->GetAppConfig();
        MqttClientManager::getInstance()->Connect(0, config.serverAdd.IP, config.serverAdd.port);
    }
    LOG()->Initialize_DebugLogger("D:/");
    LOG()->Log_Debug("Server.IP = " + config.serverAdd.IP.toStdString());
    LOG()->Log_Debug("Server.Port = " + std::to_string(config.serverAdd.port));
    LOG()->Log_Debug("Local IP = " + config.LocalIP.toStdString());

    return a.exec();
}
