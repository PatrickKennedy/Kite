#ifndef WINDOWMOVEMENT_H
#define WINDOWMOVEMENT_H

#include <QObject>
#include <QWebFrame>
#include "automaticbridge.h"

class WebWindowBase;

class WindowManager : public AutomaticBridge
{
	Q_OBJECT

	Q_PROPERTY(bool folded READ get_folded WRITE set_folded)
	Q_PROPERTY(bool dragging READ get_dragging WRITE set_dragging)
	Q_PROPERTY(bool resizing READ get_resizing WRITE set_resizing)

	int original_height;

public:
	bool folded;
	bool get_folded() const { return folded; }
	void set_folded(bool collapsed) { this->folded = collapsed; }

	bool dragging;
	bool get_dragging() const { return dragging; }
	void set_dragging(bool dragging) { this->dragging = dragging; }

	bool resizing;
	bool get_resizing() const { return resizing; }
	void set_resizing(bool resizing) { this->resizing = resizing; }

	WebWindowBase *window;
	explicit WindowManager(WebWindowBase *window);

signals:

public slots:
	void minimize();
	void close();
	void toggle_fold();
	void start_drag();
	void stop_drag();
	void start_resize();

};

#endif // WINDOWMOVEMENT_H
