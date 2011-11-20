#ifndef WINDOWMOVEMENT_H
#define WINDOWMOVEMENT_H

#include <QObject>
#include <QWebFrame>
#include "automaticbridge.h"

class WebWindowBase;

class WindowManager : public AutomaticBridge
{
	Q_OBJECT
public:
	WebWindowBase *webwindow;
	explicit WindowManager(WebWindowBase *webwindow);

signals:

public slots:
	void minimize();
	void close();
	void start_drag();
	void stop_drag();
	void start_resize();

};

#endif // WINDOWMOVEMENT_H
