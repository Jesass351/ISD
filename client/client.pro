QT       += core gui
QT += network
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutsplit.cpp \
    addclient.cpp \
    addsplit.cpp \
    authwindow.cpp \
    controltable.cpp \
    eventadd.cpp \
    functions_for_client.cpp \
    main.cpp \
    mainwindow.cpp \
    posts.cpp \
    rent.cpp \
    servicetable.cpp \
    split.cpp

HEADERS += \
    aboutsplit.h \
    addclient.h \
    addsplit.h \
    authwindow.h \
    client.h \
    controltable.h \
    eventadd.h \
    functions_for_client.h \
    mainwindow.h \
    posts.h \
    rent.h \
    servicetable.h \
    split.h

FORMS += \
    aboutsplit.ui \
    addclient.ui \
    addsplit.ui \
    authwindow.ui \
    controltable.ui \
    eventadd.ui \
    mainwindow.ui \
    posts.ui \
    rent.ui \
    servicetable.ui \
    split.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc


