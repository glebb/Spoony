#ifndef SPOONYMESSAGING_H
#define SPOONYMESSAGING_H

#include <QObject>

class SpoonyMessage : public QObject
{
    Q_OBJECT
public:
    explicit SpoonyMessage(QObject *parent = 0);

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

#endif // SPOONYMESSAGING_H
