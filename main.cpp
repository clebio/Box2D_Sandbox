#include "sandbox.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
	qsrand(QTime::currentTime().msec());
    QApplication a(argc, argv);
    sandbox* sb = new sandbox();
    sb->show();
    return a.exec();
}
