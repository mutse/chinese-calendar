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

#ifndef DATEITEM_H
#define DATEITEM_H

#include <QWidget>
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#include <QtGui>
#else
#include <QtWidgets>
#endif
#include "datemaskwidget.h"
#include "ui_dateitem.h"

namespace Ui {
class DateItem;
}

class DateItem : public QWidget
{
    Q_OBJECT
    
public:
    explicit DateItem(QWidget *parent = 0);
    ~DateItem();
    int row;
    int column;
    void setday(int day);
    void setcday(QString cday);
    void clear();
    void clearstyle();
    void setcolor();
    void setToday();
    QString day();
    QString cday();
    void resizeItem(int x,int y);

protected:
    bool eventFilter(QObject *o, QEvent *ev);
    void enter();
    void leave();

public slots:
    void click();
    void clickday();
    
signals:
    void clicked(QString);
    void day(QString);
    void resetColor();

private:
    Ui::DateItem *ui;
    bool isFocus;
    QString oriItemStyle, oriDayStyle, oriCDayStyle;
    QString clickiItemStyle, clickDayStyle, clickCDayStyle;
    QString hoverItemStyle, hoverDayStyle, hoverCDayStyle;
};

#endif // DATEITEM_H
