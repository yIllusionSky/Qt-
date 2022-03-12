QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mywidget.cpp \
    widget.cpp

HEADERS += \
    mywidget.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Pic.qrc

RC_FILE += logo.rc

DISTFILES += \
    logo.rc

#可执行文件名称
TARGET=ComputerTest

#版本信息
VERSION = 0.9.1

#公司名称
QMAKE_TARGET_COMPANY = "Student Union Team"

#产品名称
QMAKE_TARGET_PRODUCT = "Picture puzzle"

#文件说明
QMAKE_TARGET_DESCRIPTION = "Qt Creator based on 6.2.0 (MinGW 64 bit)"

#版权信息
QMAKE_TARGET_COPYRIGHT = "Copyright 2021 IllusionAutumn"

#中文（简体）
RC_LANG = 0x0004
