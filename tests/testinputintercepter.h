#ifndef TESTINPUTINTERCEPTER_H
#define TESTINPUTINTERCEPTER_H

#include <QtTest/QtTest>
#include "inputintercepter.h"

class TestInputIntercepter : public QObject
{
    Q_OBJECT
public:
    TestInputIntercepter();

private Q_SLOTS:
    void init();
    void cleanup();
    void testInputIntercepterCatchesMouseEvents();
    void testInputIntercepterDoesntCatchKeyboardEvents();

private:
    InputIntercepter *i;
    QObject *o;

};

#endif // TESTINPUTINTERCEPTER_H
