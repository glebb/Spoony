#ifndef SNOOPYFIXTURE_H
#define SNOOPYFIXTURE_H

#include <QHash>
#include <QString>

#include "tasqtfixtureplugininterface.h"

class  SnoopyFixture : public QObject, public TasFixturePluginInterface {
    Q_OBJECT
    Q_INTERFACES(TasFixturePluginInterface)

public:
    SnoopyFixture();
    ~SnoopyFixture();
        bool execute(void* objectInstance, QString actionName, QHash<QString, QString> parameters, QString & stdOut);
};

#endif // SNOOPYFIXTURE_H
