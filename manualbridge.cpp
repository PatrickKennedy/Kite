#include "manualbridge.h"

ManualBridge::ManualBridge(QString name, QWebFrame *frame, QObject *parent)
	: BaseBridge(name, frame, parent)
{
	frame->addToJavaScriptWindowObject(name, this);
}
