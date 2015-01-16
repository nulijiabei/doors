#include "doors.h"

using namespace std;

extern "C" inline void input(void *, int) { /* CGO */ }

extern "C" inline void * output() { /* CGO */ }

Doors * w;

extern "C" void init()
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
}

extern "C" int start()
{
    int argc = 0 ;
    char *argv[] = {};
    QApplication a(argc, argv);
    w = new Doors();
    w->init();
    w->show();
    return a.exec();
}

extern "C" void message(void * p)
{
    w->message((char*)p);
    free(p);
}
