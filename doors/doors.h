#ifndef DOORS_H
#define DOORS_H

#include <QtGui>

namespace Ui {

class Doors;
}

class Doors : public QMainWindow
{
    Q_OBJECT

public:
    explicit Doors(QWidget *parent = 0);
    ~Doors();
    void init();

public:
    int number;

public:
    void message(const char *);

public:
    QTimer * timer;

private:
    Ui::Doors *ui;

signals:
    void getText(const QString &);

private slots:
    void sendText();
    void sendLine();
    void on_pushButton_clicked();
};

#endif // DOORS_H
