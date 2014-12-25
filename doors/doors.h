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

private:
    Ui::Doors *ui;

signals:
    void getText(const QString &);

private slots:
    void sendText();

};

#endif // DOORS_H
