#include <QtGui>

#include "webwindowbase.h"

#include <QWebFrame>
#include <QWebElement>
#include <QMapIterator>
#include <QDebug>

int WebWindowBase::snap_distance = 25;
// The buffer as an implied 1/x fraction of the width of the window being
// snapped to. Default: 4;
int WebWindowBase::snap_buffer = 4;

WebWindowBase::WebWindowBase(QWidget *parent)
	: QWebView(parent)
	, window_manager(this)
	, dragging(false)
	, resizing(false)
{
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setMinimumSize(150, 200);
	resize(200, 300);
}

void WebWindowBase::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		last_mouse_pos = event->globalPos();
		drag_position = last_mouse_pos - frameGeometry().topLeft();
	}
	QWebView::mousePressEvent(event);
}

void WebWindowBase::mouseMoveEvent(QMouseEvent *event) {
	if (dragging) {
		if (event->buttons() & Qt::LeftButton) {
			QDesktopWidget *screen = QApplication::desktop();
			QRect screen_rect = screen->screenGeometry(this);
			QPoint new_pos = event->globalPos() - drag_position;
			QRect new_rect(new_pos, this->size());

			// We only want to snap to the outside edge of the screen
			if (!screen_rect.contains(new_rect, true)){
				QRect intersected = screen_rect & new_rect;
				if (0 < intersected.left() - new_rect.left() &&
						intersected.left() - new_rect.left() < snap_distance) {
					new_rect.moveLeft(intersected.left());
				} else if (new_rect.right() - intersected.right() > 0  &&
						   new_rect.right() - intersected.right() < snap_distance) {
					new_rect.moveRight(intersected.right());
				}

				if (0 < intersected.top() - new_rect.top() &&
						intersected.top() - new_rect.top() < snap_distance) {
					new_rect.moveTop(intersected.top());
				} else if (new_rect.bottom() - intersected.bottom() > 0 &&
						   new_rect.bottom() - intersected.bottom() < snap_distance) {
					new_rect.moveBottom(intersected.bottom());
				}

			}

			foreach (QWidget *w, QApplication::topLevelWidgets()) {
				if (w->isHidden() || w == this)
					continue;
				QRect window_rect = w->geometry();
				QRect intersected;
				// We don't want to snap from the inside.
//				intersected = window_rect & new_rect;
//				if (!intersected.isNull())
//					continue;

				intersected = new_rect & window_rect.adjusted(-snap_distance, -snap_distance, snap_distance, snap_distance);
				if (intersected.isNull())
					continue;

				// Because the top and bottom snapping snaps to the corners
				// we want to add a small buffer so it's not so shocking when it
				// happens.
				if ((new_rect.width() / intersected.width()) < snap_buffer) {
					// TODO: No window should be able to snap to the top of the
					// buddy list. We'll need to design a way to check that.
					if (abs(window_rect.top() - new_rect.bottom()) < snap_distance)
						new_rect.moveBottomLeft(window_rect.topLeft());
					else if (abs(new_rect.top() - window_rect.bottom()) < snap_distance)
						new_rect.moveTopLeft(window_rect.bottomLeft());
				}

				if (abs(window_rect.left() - new_rect.right()) < snap_distance)
					new_rect.moveRight(window_rect.left());
				else if (abs(new_rect.left() - window_rect.right()) < snap_distance)
					new_rect.moveLeft(window_rect.right());
			}

			setGeometry(new_rect);
		}
	} else if (resizing) {
		if (event->buttons() & Qt::LeftButton) {
			QPoint move_diff = event->globalPos() - last_mouse_pos;
			QSize size_diff(move_diff.x(), move_diff.y());
			QSize new_size = (this->size() + size_diff).expandedTo(this->minimumSize());
			resize(new_size);
			last_mouse_pos = event->globalPos();
		}
	} else {
		// Without this drag events (e.g. selecting text)
		// won't be propegated to the view.
		QWebView::mouseMoveEvent(event);
	}
}

void WebWindowBase::mouseReleaseEvent(QMouseEvent *event) {
	dragging = false;
	resizing = false;
	QWebView::mouseReleaseEvent(event);
}

void WebWindowBase::mouseDoubleClickEvent(QMouseEvent *event) {
	QWebView::mouseDoubleClickEvent(event);
}
