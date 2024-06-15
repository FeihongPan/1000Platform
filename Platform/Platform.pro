TEMPLATE = subdirs

SUBDIRS += \
    CommonLib \
    TCommonLib \
    MCtrlCommFuncLib \
    MainProject

CommonLib.subdir = $$_PRO_FILE_PWD_/CommonLib
TCommonLib.subdir = $$_PRO_FILE_PWD_/TCommonLib
MCtrlCommFuncLib.subdir = $$_PRO_FILE_PWD_/MCtrlCommFuncLib
MainProject.subdir = $$_PRO_FILE_PWD_/MainProject

TCommonLib.depends = CommonLib
MCtrlCommFuncLib.depends = CommonLib TCommonLib
MainProject.depends = CommonLib TCommonLib MCtrlCommFuncLib
