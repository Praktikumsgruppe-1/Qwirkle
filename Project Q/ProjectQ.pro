QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    benutzerhand.cpp \
    chatclient.cpp \
    chatserver.cpp \
    einstellungen.cpp \
    game.cpp \
    json.cpp \
    main.cpp \
    mainwindow.cpp \
    punkte.cpp \
    regeln.cpp \
    ruleswindow.cpp \
    serverworker.cpp \
    spielfeld.cpp \
    stein.cpp \
    tauschen.cpp \
    turn.cpp \
    undo.cpp

HEADERS += \
    benutzerhand.h \
    chatclient.h \
    chatserver.h \
    einstellungen.h \
    game.h \
    json.h \
    mainwindow.h \
    regeln.h \
    punkte.h \
    ruleswindow.h \
    serverworker.h \
    spielfeld.h \
    stein.h \
    tauschen.h \
    turn.h \
    undo.h

FORMS += \
    einstellungen.ui \
    game.ui \
    game.ui \
    mainwindow.ui \
    ruleswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc
