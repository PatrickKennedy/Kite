#-------------------------------------------------
#
# Project created by QtCreator 2011-11-12T14:46:39
#
#-------------------------------------------------

QT       += core gui webkit

TARGET = Kite
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
	automaticbridge.cpp \
    manualbridge.cpp \
    basebridge.cpp \
    windowmanager.cpp \
    webwindowbase.cpp \
    buddylist.cpp

HEADERS  += widget.h \
	automaticbridge.h \
    manualbridge.h \
    basebridge.h \
    windowmanager.h \
    webwindowbase.h \
    buddylist.h

RESOURCES += \
    HTML5.qrc

OTHER_FILES += \
    index.html \
    css/structure.css \
    css/index.css \
    css/flex-box.css \
    css/design.css \
    css/blocking.css \
    js/snapping.js \
    js/main.js \
    js/jquery-ui-1.8.16.custom.min.js \
    js/jquery-1.7.min.js \
    minimum.html \
    text_only.html




































