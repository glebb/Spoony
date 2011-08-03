QT += declarative \
    phonon
TEMPLATE = app
TARGET = Snoopy
DEPENDPATH += .Snoopy
INCLUDEPATH += . \
    levels \
    sprites \

RESOURCES += snoopy.qrc

# Input
SOURCES += main.cpp \
    standingstate.cpp \
    sprites/snoopysprite.cpp \
    runningstate.cpp \
    snoopystate.cpp \
    sprites/ground.cpp \
    inputhandler.cpp \
    movehandler.cpp \
    sprites/hole.cpp \
    game.cpp \
    levels/level1.cpp \
    levels/level.cpp \
    levels/level2.cpp \
    levels/level3.cpp \
    sprites/movingtriangle.cpp \
    snoopymessaging.cpp \
    jumpingstate.cpp \
    soundhandler.cpp \
    sprites/basicsprite.cpp \
    levels/level4.cpp \
    sprites/movingstick.cpp \
    inputintercepter.cpp \
    snoopyapp.cpp

HEADERS += \
    standingstate.h \
    runningstate.h \
    sprites/snoopysprite.h \
    snoopystate.h \
    sprites/ground.h \
    inputhandler.h \
    movehandler.h \
    sprites/hole.h \
    game.h \
    levels/level1.h \
    levels/level.h \
    levels/level2.h \
    levels/level3.h \
    sprites/movingtriangle.h \
    snoopymessaging.h \
    globals.h \
    jumpingstate.h \
    soundhandler.h \
    sprites/basicsprite.h \
    levels/level4.h \
    sprites/movingstick.h \
    inputintercepter.h \
    snoopyapp.h

OTHER_FILES += \
    startscreen.qml

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


QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_LDFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

unix{
QMAKE_POST_LINK += mkdir -p $$DESTDIR/sounds && cp sounds/* $$DESTDIR/sounds/
}

macx{
QMAKE_POST_LINK += mkdir -p $$DESTDIR/Snoopy.app/Contents/MacOS/sounds && cp sounds/* $$DESTDIR/Snoopy.app/Contents/MacOS/sounds/

}

win32{
QMAKE_POST_LINK += xcopy /Y /i /e /c sounds $$DESTDIR\\sounds
}
