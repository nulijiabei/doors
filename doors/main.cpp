#include "doors.h"
#include <QtGui>

extern "C" void init()
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
}

extern "C" int start()
{
    int argc = 0 ;
    char *argv[] = {};
    QApplication a(argc, argv);
    Doors w;
    w.show();
    return a.exec();
}
