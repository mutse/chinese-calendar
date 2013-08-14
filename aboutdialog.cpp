/*!
 * Copyright(C) 2013 mutse
 *
 * @file    aboutdialog.cpp
 * @brief   about Chinese Calendar
 * @author  mutse <yyhoo2.young@gmail.com>
 * @date    Aug 6th, 2013
 */
#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QtGui>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    connect(ui->closeBtn, SIGNAL(clicked()), this, SLOT(hide()));

#ifdef DEBUG
    QFile file(QCoreApplication::applicationDirPath() + "/qss/aboutus.qss");
#else
    QFile file(":/qss/aboutus.qss");
#endif
    file.open(QFile::ReadOnly);
    QString stylesheet = QObject::tr(file.readAll());
    this->setStyleSheet(stylesheet);
    file.close();
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::accept()
{
    hide();
}

