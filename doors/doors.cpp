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
    ui->textBrowser->moveCursor(QTextCursor::End);
    free(p);
}

void Doors::sendLine() {
    input((void*)ui->lineEdit->text().toLatin1().data(), ui->lineEdit->text().toLatin1().length());
    ui->lineEdit->clear();
}

void Doors::on_pushButton_clicked() {
    if ((number % 2) == 0) {
        timer->stop();
    } else {
        timer->start(1000);
    }
    number += 1;
}
