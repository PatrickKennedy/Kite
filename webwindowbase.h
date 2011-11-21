#ifndef WEBWINDOW_H
#define WEBWINDOW_H

#include <QWidget>
#include <QWebView>
#include "windowmanager.h"

class WebWindowBase : public QWebView
{
	Q_OBJECT
	QPoint last_mouse_pos;
	QPoint drag_position;
	WindowManager window_manager;

public:
	bool dragging;
	bool resizing;

	static int snap_distance;
	static int snap_buffer;

	explicit WebWindowBase(QWidget *parent = 0);

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);

signals:

public slots:

private:

};

#endif // WEBWINDOW_H
