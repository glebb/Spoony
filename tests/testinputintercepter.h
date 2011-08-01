#ifndef TESTINPUTINTERCEPTER_H
#define TESTINPUTINTERCEPTER_H

#include <QtTest/QtTest>
#include "inputintercepter.h"

class InputIntercepterSpec : public QObject
{
    Q_OBJECT
public:
    InputIntercepterSpec();

private Q_SLOTS:
    void init();
    void cleanup();
    void shouldCatchMouseEvents();
    void shouldNotCatchKeyboardEvents();

private:
    InputIntercepter *i;
    QObject *o;

};

#endif // TESTINPUTINTERCEPTER_H
