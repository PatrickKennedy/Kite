#include "windowmanager.h"
#include "webwindowbase.h"

WindowManager::WindowManager(WebWindowBase *webwindow)
	: AutomaticBridge("window_manager",
					  webwindow->page()->mainFrame(),
					  webwindow)
	, webwindow(webwindow)
{
}

void WindowManager::minimize() {
	webwindow->showMinimized();
}

void WindowManager::close() {
	webwindow->close();
}

void WindowManager::start_drag() {
	webwindow->dragging = true;
}

void WindowManager::stop_drag() {
	webwindow->dragging = false;
}

void WindowManager::start_resize() {
	webwindow->resizing = true;
}
