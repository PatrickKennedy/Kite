#include "windowmanager.h"
#include "webwindowbase.h"

#include <QDebug>

WindowManager::WindowManager(WebWindowBase *window)
	: AutomaticBridge("window_manager",
					  window->page()->mainFrame(),
					  window)
	, window(window)
	, folded(false)
	, dragging(false)
	, resizing(false)
{
}

void WindowManager::minimize() {
	window->showMinimized();
}

void WindowManager::close() {
	window->close();
}

void WindowManager::toggle_fold() {
	if (folded) {
		folded = false;
		window->setMinimumHeight(200);
		window->resize(window->width(), original_height);
	} else {
		folded = true;
		original_height = window->height();
		window->setMinimumHeight(25);
		window->resize(window->width(), 25);
	}
}

void WindowManager::start_drag() {
	dragging = true;
}

void WindowManager::stop_drag() {
	dragging = false;
}

void WindowManager::start_resize() {
	resizing = true;
}
