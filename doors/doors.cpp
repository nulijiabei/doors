#include "cgo.h"
#include "doors.h"
#include "ui_doors.h"
#include <QtGui>

Doors::Doors(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Doors)
{
    ui->setupUi(this);
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(sendText()));
}

Doors::~Doors()
{
    delete ui;
}

void Doors::sendText()
{
    void * p = request((void*)ui->lineEdit->text().toLatin1().data(), ui->lineEdit->text().toLatin1().length());
    ui->lineEdit->clear();
    ui->textBrowser->setText(tr((char*)p));
    delete(p);
}
