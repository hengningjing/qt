/**
����ο�:https://blog.csdn.net/hitzsf/article/details/108847841
*/
#include "demo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Demo w;
    w.show();
    return a.exec();
}


/**
output
"hello qt!"
"hello qt!"
"�Ҵ�������?"
"��Ҫ������ȥ?"
-------------------
"hello qt!"
"hello qt!"
"�Ҵ�������?"
"��Ҫ������ȥ?"
*/