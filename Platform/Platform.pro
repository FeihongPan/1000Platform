TEMPLATE = subdirs

SUBDIRS += \
    CommonLib \
    TCommonLib \
    GUIComponentLib \
    CommonFunctionLib \
    MainProject

CommonLib.subdir = $$_PRO_FILE_PWD_/CommonLib
TCommonLib.subdir = $$_PRO_FILE_PWD_/TCommonLib
GUIComponentLib.subdir = $$_PRO_FILE_PWD_/GUIComponentLib
CommonFunctionLib.subdir = $$_PRO_FILE_PWD_/CommonFunctionLib
MainProject.subdir = $$_PRO_FILE_PWD_/MainProject

TCommonLib.depends = CommonLib
GUIComponentLib.depends = CommonLib TCommonLib
CommonFunctionLib.depends = CommonLib TCommonLib GUIComponentLib
MainProject.depends = CommonLib TCommonLib CommonFunctionLib
