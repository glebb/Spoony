#ifndef SNOOPYMESSAGING_H
#define SNOOPYMESSAGING_H

#include <QObject>

class SnoopyMessaging : public QObject
{
    Q_OBJECT
public:
    explicit SnoopyMessaging(QObject *parent = 0);

signals:
    void die();
    void finish();
    void collides();
    void reset();

public slots:
    void onDie();
    void onCollide();
    void onFinish();
    void onResetLevel();
};

#endif // SNOOPYMESSAGING_H
