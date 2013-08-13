/*
 * This file is part of the chinese-calendar project
 * Copyright (C) 2013 National University of Defense Technology(NUDT) & Kylin Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * This project is developed by "UbuntuKylin Members" team,
 * see <https://launchpad.net/~ubuntukylin~members>
 * Authors: Abel Liu <guiltyritter@gmail.com>
 *                 Shine Huang <hostc@163.com>
 */

//#include <QtGui>
#include <QApplication>
#include <QTranslator>
#include <QTextCodec>
#include <QDesktopWidget>
#include "chinesecalendar.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
#endif
    QApplication app(argc, argv);
    QTranslator translator;

    translator.load(":/translate/i18_zh_CN.qm");
    app.installTranslator(&translator);

    // load default skin
#ifdef DEBUG
    QFile file(QCoreApplication::applicationDirPath() + "/skin/default-skin.qss");
#else
    QFile file("/usr/share/chinese-calendar/skin/default-skin.qss");
#endif
    file.open(QFile::ReadOnly);
    QString stylesheet = QObject::tr(file.readAll());
    app.setStyleSheet(stylesheet);

    app.setQuitOnLastWindowClosed(false);

    ChineseCalendar *window = new ChineseCalendar;
    app.setWindowIcon(window->icon64);
    window->setWindowFlags(Qt::FramelessWindowHint);
    window->resetDateItemColor();

    QDesktopWidget desktop;
    int width = desktop.screenGeometry().width();
    int height = desktop.screenGeometry().height();

    window->setGeometry(QRect(width-525,30,520,350));
    window->hide();
    return app.exec();
}
