QT += declarative \
    phonon

TEMPLATE = app
TARGET = spoony
DEPENDPATH += .spoony

INCLUDEPATH += src/. \
    src/levels \
    src/sprites \

RESOURCES += src/spoony.qrc

# Input
SOURCES += src/main.cpp \
    src/standingstate.cpp \
    src/sprites/spoonysprite.cpp \
    src/runningstate.cpp \
    src/spoonystate.cpp \
    src/sprites/ground.cpp \
    src/inputhandler.cpp \
    src/movehandler.cpp \
    src/sprites/hole.cpp \
    src/game.cpp \
    src/levels/level1.cpp \
    src/levels/level.cpp \
    src/levels/level2.cpp \
    src/levels/level3.cpp \
    src/sprites/movingtriangle.cpp \
    src/spoonymessaging.cpp \
    src/jumpingstate.cpp \
    src/soundhandler.cpp \
    src/sprites/basicsprite.cpp \
    src/levels/level4.cpp \
    src/sprites/movingstick.cpp \
    src/inputintercepter.cpp \
    src/spoonyapp.cpp \
    src/levelfactory.cpp

HEADERS += \
    src/standingstate.h \
    src/runningstate.h \
    src/sprites/spoonysprite.h \
    src/spoonystate.h \
    src/sprites/ground.h \
    src/inputhandler.h \
    src/movehandler.h \
    src/sprites/hole.h \
    src/game.h \
    src/levels/level1.h \
    src/levels/level.h \
    src/levels/level2.h \
    src/levels/level3.h \
    src/sprites/movingtriangle.h \
    src/spoonymessaging.h \
    src/globals.h \
    src/jumpingstate.h \
    src/soundhandler.h \
    src/sprites/basicsprite.h \
    src/levels/level4.h \
    src/sprites/movingstick.h \
    src/inputintercepter.h \
    src/spoonyapp.h \
    src/levelfactory.h

OTHER_FILES += \
    src/startscreen.qml

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
QMAKE_POST_LINK += && mkdir -p $$DESTDIR/spoony.app/Contents/MacOS/sounds && cp sounds/* $$DESTDIR/spoony.app/Contents/MacOS/sounds/
}

win32{
QMAKE_POST_LINK += xcopy /Y /i /e /c sounds $$DESTDIR\\sounds
}
