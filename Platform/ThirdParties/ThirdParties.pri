win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ThirdParties/Mqtt/lib/ -lQt5Mqtt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ThirdParties/Mqtt/lib/ -lQt5Mqttd
else:unix: LIBS += -L$$PWD/../ThirdParties/Mqtt/lib/ -lQt5Mqtt

INCLUDEPATH += $$PWD/../ThirdParties/Mqtt/include
DEPENDPATH += $$PWD/../ThirdParties/Mqtt/include

#spdlog
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ThirdParties/spdlog/lib/ -lspdlog
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ThirdParties/spdlog/lib/ -lspdlogd

INCLUDEPATH += $$PWD/../ThirdParties/spdlog/include
DEPENDPATH += $$PWD/../ThirdParties/spdlog/include
