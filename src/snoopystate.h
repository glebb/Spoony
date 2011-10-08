#ifndef SNOOPYSTATE_H
#define SNOOPYSTATE_H

#include <QState>
#include "snoopysprite.h"

class SnoopyState : public QState
{
    Q_OBJECT
public:
    explicit SnoopyState(SnoopySprite* snoopy);

private slots:
    virtual void nextFrame();

public:
    virtual void onEntry ( QEvent * event );
    virtual void onExit ( QEvent * event );

protected:
    SnoopySprite* _snoopy;

};

#endif // SNOOPYSTATE_H
