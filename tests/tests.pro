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
INCLUDEPATH += ../ \
        ../sprites/ \
        ../levels/

SOURCES += testgame.cpp \
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
        main.cpp \
        fakelevel.cpp \
        testlevel.cpp \
        fakegraphics.cpp \
        testinputhandler.cpp \
        testmovehandler.cpp \
        testinputintercepter.cpp


HEADERS += ../*.h \
    ../levels/*.h \
    ../sprites/*.h \
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

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_LDFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

RCC_DIR = "Build"
UI_DIR = "Build"
MOC_DIR = "Build"
OBJECTS_DIR = "Build"

CONFIG(debug, debug|release) {
    DESTDIR = "debug"
}
CONFIG(release, debug|release) {
    DESTDIR = "release"
}

OTHER_FILES += \
    features/squatting.feature \
    features/squatting.rb

RESOURCES += \
    fake.qrc
