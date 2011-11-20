#include <QtGui/QApplication>
#include <QWebView>
#include "webwindowbase.h"
#include "buddylist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	BuddyList w;
	w.load(QUrl("qrc:///index.html"));
	w.show();

	WebWindowBase w2;
	w2.load(QUrl("qrc:///index.html"));
	w2.show();

    return a.exec();
}
