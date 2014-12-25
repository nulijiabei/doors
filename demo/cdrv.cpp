#include <QtGui>

extern "C" inline int drv_appmain() { /* CGO */ }

extern "C" int start() {
    int i = drv_appmain();
    qDebug("%d", i);
    int argc = 0;
    char **argv = 0;
    QApplication a(argc, argv);
    QDialog w;
    w.show();
    return a.exec();
}
