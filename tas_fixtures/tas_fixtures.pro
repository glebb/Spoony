#-------------------------------------------------
#
# Project created by QtCreator 2011-04-11T08:05:01
#
#-------------------------------------------------

QT       += declarative \
            phonon

TARGET = tas_noopsy
TEMPLATE = lib
CONFIG += dll

DESTDIR = $$[QT_INSTALL_PLUGINS]/tasfixtures

DEFINES += TAS_FIXTURES_LIBRARY

SOURCES += snoopyfixture.cpp \
        ../game.cpp \
        ../levels/*.cpp \
        ../sprites/*.cpp \
        ../inputhandler.cpp \
        ../movehandler.cpp \
        ../soundhandler.cpp \
        ../runningstate.cpp \
        ../snoopystate.cpp \
        ../standingstate.cpp \
        ../jumpingstate.cpp \
        ../snoopymessaging.cpp \
        ../inputintercepter.cpp \
        ../snoopyapp.cpp \
        ../levelfactory.cpp

HEADERS += snoopyfixture.h \
    ../levels/*.h \
    ../sprites/*.h \
    ../*.h


INCLUDEPATH += ../sprites/ \
        ../levels/ \
        ../

OTHER_FILES += \
    ../features/test_fixtures.xml \
    ../features/step_definitions.rb \
    ../features/startup.feature \
    ../features/gamescreen.feature \
    ../features/movement.feature \
    ../features/movement.rb \
    ../features/gamescreen.rb

RCC_DIR = "Build/RCCFiles"
UI_DIR = "Build/UICFiles"
MOC_DIR = "Build/MOCFiles"
OBJECTS_DIR = "Build/ObjFiles"

unix {
LIBS += -lqttestability
INCLUDEPATH += /usr/include/tdriver/
}

win32 {
LIBS += c:/qttas/lib/qttestability.dll
INCLUDEPATH += c:/qttas/inc
}
