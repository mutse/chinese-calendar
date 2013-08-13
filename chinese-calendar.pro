TEMPLATE = app
TARGET = chinese-calendar
DEPENDPATH += $$PWD/
INCLUDEPATH += $$PWD/

inst.files += KylinLunar.db
inst.path = /usr/share/chinese-calendar/db
inst1.files += img/chinesecalendar-64.png
inst1.path = /usr/share/pixmaps
inst2.files += chinese-calendar.desktop
inst2.path = /usr/share/applications
default_skin.files += skin/default/chinesecalendarBGyellow.png \
	skin/default/no.png \
	skin/default/note.png \
	skin/default/ok.png
default_skin.path = /usr/share/chinese-calendar/skin/default
blue_skin.files += skin/blue/chinesecalendarBGblue.png \
	skin/blue/no.png \
	skin/blue/note.png \
	skin/blue/ok.png
blue_skin.path = /usr/share/chinese-calendar/skin/blue
black_skin.files += skin/black/chinesecalendar.png \
	skin/black/no.png \
	skin/black/no-hover.png \
	skin/black/ok.png \
	skin/black/ok-hover.png \
	skin/black/note.png \
	skin/black/arrow-left.png \
	skin/black/arrow-right.png \
	skin/black/arrow-down.png
black_skin.path = /usr/share/chinese-calendar/skin/black
qss.files += skin/default-skin.qss \
	skin/blue-skin.qss \
	skin/black.qss
qss.path = /usr/share/chinese-calendar/skin
readme.files += skin/README.md
readme.path = /usr/share/chinese-calendar/skin

target.source += $$TARGET
target.path = /usr/bin
INSTALLS += inst \
    inst1 \
    inst2 \
    default_skin \
    blue_skin \
    black_skin \
    qss \
    readme \
    target

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += core gui\
    sql \
    svg

HEADERS += \  
    dateitem.h \
    datemaskwidget.h \
    chinesecalendar.h \
    ccbo.h \
    cnote.h \
    aboutdialog.h
FORMS += calendar.ui \
    dateitem.ui \
    aboutdialog.ui
SOURCES += main.cpp \
    dateitem.cpp \
    datemaskwidget.cpp \
    chinesecalendar.cpp \
    ccbo.cpp \
    cnote.cpp \
    aboutdialog.cpp
RESOURCES += \
    chinese-calendar.qrc
TRANSLATIONS += translate/i18_zh_CN.ts
