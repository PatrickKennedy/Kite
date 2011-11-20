#ifndef AUTOMATICBRIDGE_H
#define AUTOMATICBRIDGE_H

#include <QObject>
#include "basebridge.h"

class AutomaticBridge : public BaseBridge
{
    Q_OBJECT
public:
	explicit AutomaticBridge(QString name, QWebFrame *frame, QObject *parent = 0);

signals:

public slots:
	void rebridge();

};

#endif // AUTOMATICBRIDGE_H
