#include "makefonts.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MakeFonts w;
	w.show();
	return a.exec();
}
