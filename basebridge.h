#ifndef BASEBRIDGE_H
#define BASEBRIDGE_H

#include <QObject>
#include <QWebFrame>

class BaseBridge : public QObject
{
    Q_OBJECT
public:
	QString name;
	QWebFrame *frame;
	explicit BaseBridge(QString name, QWebFrame *frame, QObject *parent = 0);

signals:

public slots:

};

#endif // BASEBRIDGE_H
