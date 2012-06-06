#-------------------------------------------------
#
# Project created by QtCreator 2011-04-11T08:05:01
#
#-------------------------------------------------

QT       += declarative \
            phonon

TARGET = tas_spoony
TEMPLATE = lib
CONFIG += dll

DESTDIR = $$[QT_INSTALL_PLUGINS]/tasfixtures

DEFINES += TAS_FIXTURES_LIBRARY

SOURCES += spoonyfixture.cpp \
        ../src/game.cpp \
        ../src/levels/*.cpp \
        ../src/sprites/*.cpp \
        ../src/inputhandler.cpp \
        ../src/movehandler.cpp \
        ../src/soundhandler.cpp \
        ../src/runningstate.cpp \
        ../src/spoonystate.cpp \
        ../src/standingstate.cpp \
        ../src/jumpingstate.cpp \
        ../src/spoonymessaging.cpp \
        ../src/inputintercepter.cpp \
        ../src/spoonyapp.cpp \
        ../src/levelfactory.cpp

HEADERS += spoonyfixture.h \
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
