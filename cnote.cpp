#include "cnote.h"
#include "ccbo.h"
#include <QtGui>

Cnote::Cnote(QWidget *parent) :
    QDialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    //pix.load(":/img/note.png",0,Qt::AvoidDither|Qt::ThresholdDither|Qt::ThresholdAlphaDither);
    resize(224,280);

    textedit = new QTextEdit(this);
    textedit->setObjectName("textedit");
    ok = new QPushButton(this);
    ok->setObjectName("ok");
    cancel = new QPushButton(this);
    cancel->setObjectName("cancel");
    datelabel = new QLabel(this);
    datelabel->setObjectName("datelabel");
    clearplan = new QPushButton(this);
    clearplan->setObjectName("clearplan");

    textedit->resize(155,140);
    textedit->move(30,60);
    ok->resize(30,30);
    ok->move(120,210);
    cancel->resize(30,30);
    cancel->move(160,210);
    clearplan->resize(70,30);
    clearplan->setText("清空计划");
    clearplan->move(30,210);
    datelabel->resize(120,20);
    datelabel->move(50,40);

    //ok->setStyleSheet("QPushButton{background-color:transparent;}");
    //cancel->setStyleSheet("QPushButton{background-color:transparent;border:0 solid}");
    //datelabel->setStyleSheet("QLabel{background-color:transparent;border:0 solid;}");
    //clearplan->setStyleSheet("QPushButton{background-color:transparent;}");
    //ok->setIcon(QIcon(":/img/ok.png"));
    //cancel->setIcon(QIcon(":/img/no.png"));
    //textedit->setStyleSheet("QTextEdit{background-color:transparent;border:0 solid;}");
    connect(this->ok, SIGNAL(clicked()), this, SLOT(savenote()));
    connect(this->cancel, SIGNAL(clicked()), this, SLOT(cancelnote()));
    connect(this->clearplan, SIGNAL(clicked()), this, SLOT(clean()));

}

Cnote::~Cnote()
{

}

void Cnote::clean()
{
    this->textedit->clear();
}

void Cnote::savenote()
{
    emit save(this->textedit->toPlainText());

    this->hide();
    this->textedit->clear();
}

void Cnote::cancelnote()
{
    this->hide();
    this->textedit->clear();
}

void Cnote::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //painter.drawPixmap(0,0,pix.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    QStyleOption opt;
    opt.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

void  Cnote::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalPos() - dragPos);
    setWindowOpacity(0.5);
}

void  Cnote::mousePressEvent(QMouseEvent *event)
{
    dragPos = event->globalPos() - frameGeometry().topLeft();
}

void  Cnote::mouseReleaseEvent(QMouseEvent *event)
{
    setWindowOpacity(1.0);
}
