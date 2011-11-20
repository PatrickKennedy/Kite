#include "basebridge.h"

BaseBridge::BaseBridge(QString name, QWebFrame *frame, QObject *parent)
	: QObject(parent)
	, name(name)
	, frame(frame)
{
}
