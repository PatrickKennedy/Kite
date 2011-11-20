#include "automaticbridge.h"

AutomaticBridge::AutomaticBridge(QString name, QWebFrame *frame, QObject *parent)
	: BaseBridge(name, frame, parent)
{
	connect(frame, SIGNAL(javaScriptWindowObjectCleared()),
			this, SLOT(rebridge()));
}

void AutomaticBridge::rebridge(){
	frame->addToJavaScriptWindowObject(name, this);
}
