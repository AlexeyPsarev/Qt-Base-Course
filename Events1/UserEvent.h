#ifndef USEREVENT_H
#define USEREVENT_H

#include <QEvent>

class UserEvent : public QEvent
{
public:
	static const int UserEventType = QEvent::User + 1;

	UserEvent();
	~UserEvent();
};

#endif // USEREVENT_H
