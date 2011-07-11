#ifndef INPUTINTERCEPTER_H
#define INPUTINTERCEPTER_H

#include <QObject>

class QEvent;

class InputIntercepter : public QObject
{
    Q_OBJECT
public:
    explicit InputIntercepter(QObject *parent = 0);

protected:
    bool eventFilter(QObject *obj, QEvent *event);

signals:

public slots:

};

#endif // INPUTINTERCEPTER_H
