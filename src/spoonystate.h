#ifndef SPOONYSTATE_H
#define SPOONYSTATE_H

#include <QState>
#include "spoonysprite.h"

class SpoonyState : public QState
{
    Q_OBJECT
public:
    explicit SpoonyState(SpoonySprite* spoony);

private slots:
    virtual void nextFrame();

public:
    virtual void onEntry ( QEvent * event );
    virtual void onExit ( QEvent * event );

protected:
    SpoonySprite* _spoony;

};

#endif // SPOONYSTATE_H
