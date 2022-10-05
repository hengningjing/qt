#include "demo.h"
#include <QtWidgets/QApplication>
#include <QComboBox>
#include <QStyleFactory>
#include <QDebug>

int main(int argc, char *argv[])
{
	qDebug() << QStyleFactory::keys();  // ("windowsvista", "Windows", "Fusion")  ����ͨ�������в��� -style����
    QApplication a(argc, argv);
	a.setStyle("Fusion");
	qDebug() << "-------->��ǰ�������п���style " << a.style();
	Demo w;
	QComboBox* box = new QComboBox(&w);
    w.show();
    return a.exec();
}
