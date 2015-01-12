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
    QTimer * timer;

private:
    Ui::Doors *ui;

signals:
    void getText(const QString &);

private slots:
    void sendText();
    void sendLine();
};

#endif // DOORS_H
