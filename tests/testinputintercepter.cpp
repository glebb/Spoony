#include "testinputintercepter.h"

#include "inputintercepter.h"

#include <QtTest/QtTest>
#include <QEvent>
#include <QMouseEvent>
#include <QWidget>


TestInputIntercepter::TestInputIntercepter()
{
}

void TestInputIntercepter::init()

{
    i = new InputIntercepter;
    o = new QObject;

}

void TestInputIntercepter::cleanup()
{
    delete i;
    delete o;
}

void TestInputIntercepter::testInputIntercepterCatchesMouseEvents()
{
    QMouseEvent *e = new QMouseEvent(QEvent::MouseButtonPress, QPoint(0,0), Qt::LeftButton, Qt::NoButton, Qt::NoModifier);
    o->installEventFilter(i);
    QVERIFY(QCoreApplication::sendEvent(o, e) == true);
    delete e;
}

void TestInputIntercepter::testInputIntercepterDoesntCatchKeyboardEvents()
{
    QEvent *e = new QKeyEvent(QEvent::KeyPress, 0, 0, "");
    o->installEventFilter(i);
    QVERIFY(QCoreApplication::sendEvent(o, e) == false);
    delete e;
}
