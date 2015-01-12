#include "cgo.h"
#include "doors.h"
#include "ui_doors.h"
#include <QtGui>

Doors::Doors(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Doors)
{
    ui->setupUi(this);
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(sendLine()));
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(sendText()));
    timer->start(1000);
}

Doors::~Doors()
{
    delete ui;
}

void Doors::sendText()
{
    void * p = output();
    ui->textBrowser->setText(tr((char*)p));
    free(p);
}

void Doors::sendLine() {
    input((void*)ui->lineEdit->text().toLatin1().data(), ui->lineEdit->text().toLatin1().length());
    ui->lineEdit->clear();
}
