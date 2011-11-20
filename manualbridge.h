#ifndef MANUALBRIDGE_H
#define MANUALBRIDGE_H

#include <QObject>
#include "basebridge.h"

class ManualBridge : public BaseBridge
{
    Q_OBJECT
public:
	explicit ManualBridge(QString name, QWebFrame *frame, QObject *parent = 0);

signals:

public slots:

};

#endif // MANUALBRIDGE_H
