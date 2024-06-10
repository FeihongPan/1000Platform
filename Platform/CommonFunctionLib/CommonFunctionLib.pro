QT       += gui
QT       += network xml serialport printsupport

TEMPLATE = lib
DEFINES += COMMONFUNCTIONLIB_LIBRARY

CONFIG += c++11

CONFIG(debug,debug|release){
    TARGET = CommonFunctionLibd
} else {
    TARGET = CommonFunctionLib
}

DEFINES += QS_HAS_JSON
DEFINES += QS_HAS_XML

QMAKE_CXXFLAGS_EXCEPTIONS_ON = /EHa
QMAKE_CXXFLAGS_STL_ON = /EHa

include($$PWD/AppConfig/AppConfig.pri)

include($$PWD/../ThirdParties/ThirdParties.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=

HEADERS += \
    CommonFunctionLib_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

CONFIG(debug,debug|release){
    DLLDESTDIR = $$OUT_PWD/../MainProject/debug
} else {
    DLLDESTDIR = $$OUT_PWD/../MainProject/release
}

# CommonLib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../CommonLib/release/ -lCommonLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../CommonLib/debug/ -lCommonLibd
else:unix: LIBS += -L$$OUT_PWD/../CommonLib/ -lCommonLib

INCLUDEPATH += $$PWD/../CommonLib
DEPENDPATH += $$PWD/../CommonLib

# TCommonLib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../TCommonLib/release/ -lTCommonLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../TCommonLib/debug/ -lTCommonLibd
else:unix: LIBS += -L$$OUT_PWD/../TCommonLib/ -lTCommonLib

INCLUDEPATH += $$PWD/../TCommonLib
DEPENDPATH += $$PWD/../TCommonLib

# GUIComponentLib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../GUIComponentLib/release/ -lGUIComponentLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../GUIComponentLib/debug/ -lGUIComponentLibd
else:unix: LIBS += -L$$OUT_PWD/../GUIComponentLib/ -lGUIComponentLib

INCLUDEPATH += $$PWD/../GUIComponentLib
DEPENDPATH += $$PWD/../GUIComponentLib
