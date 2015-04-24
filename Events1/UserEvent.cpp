#include "UserEvent.h"

UserEvent::UserEvent(): QEvent(QEvent::Type(UserEventType))
{
	Q_UNUSED(0)
}

UserEvent::~UserEvent()
{

}

