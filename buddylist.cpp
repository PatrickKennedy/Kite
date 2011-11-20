#include "buddylist.h"

BuddyList::BuddyList(QWidget *parent) :
    WebWindowBase(parent)
{
	setAttribute(Qt::WA_DeleteOnClose, false);
	resize(width(), 400);
}
