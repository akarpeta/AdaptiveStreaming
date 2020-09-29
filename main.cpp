#include "Aisde2Agraf.h"
#include "qcustomplot.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Aisde2Agraf w;
	w.show();
	return a.exec();
}
