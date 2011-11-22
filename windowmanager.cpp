#include "windowmanager.h"
#include "webwindowbase.h"

#include <QDebug>

WindowManager::WindowManager(WebWindowBase *window)
	: AutomaticBridge("window_manager",
					  window->page()->mainFrame(),
					  window)
	, window(window)
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

void WindowManager::start_drag() {
	dragging = true;
}

void WindowManager::stop_drag() {
	dragging = false;
}

void WindowManager::start_resize() {
	resizing = true;
}
