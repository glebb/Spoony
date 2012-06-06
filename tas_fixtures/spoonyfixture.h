#ifndef SPOONYFIXTURE_H
#define SPOONYFIXTURE_H

#include <QHash>
#include <QString>

#include "tasqtfixtureplugininterface.h"

class  SpoonyFixture : public QObject, public TasFixturePluginInterface {
    Q_OBJECT
    Q_INTERFACES(TasFixturePluginInterface)

public:
    SpoonyFixture();
    ~SpoonyFixture();
        bool execute(void* objectInstance, QString actionName, QHash<QString, QString> parameters, QString & stdOut);
};

#endif // SPOONYFIXTURE_H
