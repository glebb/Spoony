#include <QtGui/QApplication>
#include <QtTest/QtTest>
#include <iostream>

#include "testgame.h"
#include "testlevel.h"
#include "testinputhandler.h"
#include "testmovehandler.h"
#include "testinputintercepter.h"

void countMethods(QStringList *methods, QObject *tc);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList methods;
    int res = 0;

    GameSpec testGame;
    res |= QTest::qExec(&testGame, argc, argv);
    countMethods(&methods, &testGame);

    LevelSpec testLevel;
    res |= QTest::qExec(&testLevel, argc, argv);
    countMethods(&methods, &testLevel);

    InputHandlerSpec testInput;
    res |= QTest::qExec(&testInput, argc, argv);
    countMethods(&methods, &testInput);

    MoveHandlerSpec testMoving;
    res |= QTest::qExec(&testMoving, argc, argv);
    countMethods(&methods, &testMoving);

    InputIntercepterSpec testInputIntercepter;
    res |= QTest::qExec(&testInputIntercepter, argc, argv);
    countMethods(&methods, &testInputIntercepter);

    qDebug() << "number of failed cases: " << res;
    qDebug() << "examples executed: "  << methods.size();

    #ifdef WIN32
    if (argc > 0)
        std::cin.get();
    #endif

    return res;
}

void countMethods(QStringList *methods, QObject *tc)
{
    const QMetaObject* metaObject = tc->metaObject();
    for(int i = metaObject->methodOffset(); i < metaObject->methodCount(); ++i)
    {
        if (QString(metaObject->method(i).signature()).startsWith("should"))
            methods->append(QString::fromLatin1(metaObject->method(i).signature()));
    }
}
