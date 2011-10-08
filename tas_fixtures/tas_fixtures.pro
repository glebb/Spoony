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
        ../src/game.cpp \
        ../src/levels/*.cpp \
        ../src/sprites/*.cpp \
        ../src/inputhandler.cpp \
        ../src/movehandler.cpp \
        ../src/soundhandler.cpp \
        ../src/runningstate.cpp \
        ../src/snoopystate.cpp \
        ../src/standingstate.cpp \
        ../src/jumpingstate.cpp \
        ../src/snoopymessaging.cpp \
        ../src/inputintercepter.cpp \
        ../src/snoopyapp.cpp \
        ../src/levelfactory.cpp

HEADERS += snoopyfixture.h \
    ../src/levels/*.h \
    ../src/sprites/*.h \
    ../src/*.h


INCLUDEPATH += ../src/sprites/ \
        ../src/levels/ \
        ../src/

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
