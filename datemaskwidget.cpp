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

#include "datemaskwidget.h"
#include <QDebug>
#include "chinesecalendar.h"
DateMaskWidget::DateMaskWidget(QWidget *parent) :
    QWidget(parent)
{

}

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
void DateMaskWidget::mousePressEvent(QMouseEvent *ev)
{
    if( ev->button() == Qt::LeftButton)
        emit clicked();
    if( ev->button() == Qt::LeftButton && ev->type() == QEvent::MouseButtonDblClick)
    {
        emit clickday();
    }

    ev->ignore();
}

#else
bool DateMaskWidget::event(QEvent *event)
{
    const QEvent::Type et = event->type();
    switch ( et )
    {
    case QEvent::MouseButtonDblClick:
        emit clickday();
        return true;
    case QEvent::MouseButtonPress:
        emit clicked();
        return true;
    case QEvent::MouseButtonRelease:
        return true;
    default:
        break;
    }

    return QWidget::event(event);
}
#endif
