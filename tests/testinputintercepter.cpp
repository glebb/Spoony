#include "testinputintercepter.h"

#include "inputintercepter.h"

#include <QtTest/QtTest>
#include <QEvent>
#include <QMouseEvent>
#include <QWidget>


InputIntercepterSpec::InputIntercepterSpec()
{
}

void InputIntercepterSpec::init()

{
    i = new InputIntercepter;
    o = new QObject;

}

void InputIntercepterSpec::cleanup()
{
    delete i;
    delete o;
}

void InputIntercepterSpec::shouldCatchMouseEvents()
{
    QMouseEvent *e = new QMouseEvent(QEvent::MouseButtonPress, QPoint(0,0), Qt::LeftButton, Qt::NoButton, Qt::NoModifier);
    o->installEventFilter(i);
    QVERIFY(QCoreApplication::sendEvent(o, e) == true);
    delete e;
}

void InputIntercepterSpec::shouldNotCatchKeyboardEvents()
{
    QEvent *e = new QKeyEvent(QEvent::KeyPress, 0, 0, "");
    o->installEventFilter(i);
    QVERIFY(QCoreApplication::sendEvent(o, e) == false);
    delete e;
}
