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
INCLUDEPATH += ./ \
        sprites/ \
        levels/

SOURCES += tests/testgame.cpp \
        game.cpp \
        levels/*.cpp \
        sprites/*.cpp \
        inputhandler.cpp \
        movehandler.cpp \
        soundhandler.cpp \
        runningstate.cpp \
        snoopystate.cpp \
        standingstate.cpp \
        jumpingstate.cpp \
        snoopymessaging.cpp \
        inputintercepter.cpp \
        snoopyapp.cpp \
        tests/main.cpp \
        tests/fakelevel.cpp \
        tests/testlevel.cpp \
        tests/fakegraphics.cpp \
        tests/testinputhandler.cpp \
        tests/testmovehandler.cpp \
        tests/testinputintercepter.cpp


HEADERS += *.h \
    levels/*.h \
    sprites/*.h \
    tests/testgame.h \
    tests/fakelevel.h \
    tests/testlevel.h \
    tests/fakegraphics.h \
    tests/testinputhandler.h \
    tests/testmovehandler.h \
    tests/testinputintercepter.h

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32 {
DEFINES += WIN32
}

macx{
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

RESOURCES += \
    snoopy.qrc
