#ifndef DOORS_H
#define DOORS_H

#include <QMainWindow>

namespace Ui {
class Doors;
}

class Doors : public QMainWindow
{
    Q_OBJECT

public:
    explicit Doors(QWidget *parent = 0);
    ~Doors();

public:
    int number;

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
