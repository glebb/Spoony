#include "spoonyfixture.h"

#include <QtPlugin>

#include "game.h"
#include "level.h"
#include "spoonyapp.h"
#include "globals.h"

Q_EXPORT_PLUGIN2(tas_spoony, SpoonyFixture)


SpoonyFixture::SpoonyFixture()
{
}

SpoonyFixture::~SpoonyFixture()
{

}

bool SpoonyFixture::execute(void *objectInstance, QString actionName, QHash<QString, QString> parameters, QString &stdOut)
{
    SpoonyApplication *app = static_cast<SpoonyApplication *>(objectInstance);
    if (actionName == "getLevelName") {
        stdOut = app->getGame()->getCurrentLevel()->getName();
        return true;
    }
    if (actionName == "start") {
        int level = 1;
        int lives = LIVES;
        if (parameters.contains("lives"))
            level = (parameters["lives"]).toInt();
        if (parameters.contains("level"))
            level = (parameters["level"]).toInt();
        app->getGame()->start(lives, level);
        return true;
    }

    if (actionName == "startupScreen") {
        app->getGame()->restartGame();
        return true;
    }

    if (actionName == "changeLevel") {
        int level = 1;
        if (parameters.contains("level"))
            level = (parameters["level"]).toInt();
        app->getGame()->setCurrentLevel(level);
        return true;
    }

    if (actionName == "getLives") {
        stdOut = QString::number(app->getGame()->getLives());
        return true;
    }

    if (actionName == "die") {
        app->getGame()->onDie();
        return true;
    }

    return false;
}
