#-------------------------------------------------
#
# Project created by QtCreator 2011-04-11T08:05:01
#
#-------------------------------------------------

QT       += declarative \
            phonon

TARGET = tas_noopsy
TEMPLATE = lib

DEFINES += TAS_FIXTURES_LIBRARY

SOURCES += snoopyfixture.cpp \
        ../../game.cpp \
        ../../levels/*.cpp \
        ../../sprites/*.cpp \
        ../../inputhandler.cpp \
        ../../movehandler.cpp \
        ../../soundhandler.cpp \
        ../../runningstate.cpp \
        ../../snoopystate.cpp \
        ../../standingstate.cpp \
        ../../jumpingstate.cpp \
        ../../snoopymessaging.cpp \
        ../../inputintercepter.cpp \
        ../../snoopyapp.cpp

HEADERS += snoopyfixture.h \
    ../../levels/*.h \
    ../../sprites/*.h \
    ../../*.h


INCLUDEPATH += ../../sprites/ \
        ../../levels/ \
        ../../

OTHER_FILES += \
    ../features/test_fixtures.xml \
    ../features/step_definitions.rb \
    ../features/startup.feature \
    ../features/gamescreen.feature \
    ../features/basic_movement.feature.incomplete

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

macx {
LIBS += /Users/antti/tinkerin/tdriver/agent_qt/tascore/lib/libqttestability.dylib
INCLUDEPATH += /usr/include/tdriver/
}

win32 {
LIBS += c:/qttas/lib/qttestability.dll
INCLUDEPATH += c:/qttas/inc
}

win32{
QMAKE_POST_LINK += "xcopy /Y /i /e /c $$DESTDIR\\tas_noopsy.dll C:\\QtSDK\\Desktop\\Qt\\4.7.3\\mingw\plugins\\tasfixtures\\"
}

macx{
QMAKE_POST_LINK += "cp $$DESTDIR/libtas_noopsy.dylib /Users/antti/tasfixtures/"
}
