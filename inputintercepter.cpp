#include "inputintercepter.h"

#include <QEvent>

InputIntercepter::InputIntercepter(QObject *parent) :
    QObject(parent)
{
}

bool InputIntercepter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick
            || event->type() == QEvent::MouseButtonPress
            || event->type() == QEvent::MouseButtonRelease
            || event->type() == QEvent::MouseMove
            || event->type() == QEvent::MouseTrackingChange) {
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }

}
