#-------------------------------------------------
#
# Project created by QtCreator 2011-04-04T10:50:54
#
#-------------------------------------------------

QT       += testlib \
        declarative \
        phonon

TARGET = SnoopyTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
INCLUDEPATH += ../src/ \
        ../src/sprites/ \
        ../src/levels/

SOURCES += testgame.cpp \
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
        ../src/levelfactory.cpp \
        main.cpp \
        fakelevel.cpp \
        testlevel.cpp \
        fakegraphics.cpp \
        testinputhandler.cpp \
        testmovehandler.cpp \
        testinputintercepter.cpp


HEADERS += ../src/*.h \
    ../src/levels/*.h \
    ../src/sprites/*.h \
    testgame.h \
    fakelevel.h \
    testlevel.h \
    fakegraphics.h \
    testinputhandler.h \
    testmovehandler.h \
    testinputintercepter.h

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32 {
DEFINES += WIN32
}

unix {
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_LDFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
}

RCC_DIR = "Build/RCCFiles"
UI_DIR = "Build/UICFiles"
MOC_DIR = "Build/MOCFiles"
OBJECTS_DIR = "Build/ObjFiles"

CONFIG(debug, debug|release) {
    DESTDIR = "debug"
}
CONFIG(release, debug|release) {
    DESTDIR = "release"
}
