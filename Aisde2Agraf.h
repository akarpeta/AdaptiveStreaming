#pragma once

#include <QtWidgets/QMainWindow>
#include "Event.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "ui_Aisde2Agraf.h"
#include "qcustomplot.h"

class Aisde2Agraf : public QMainWindow
{
	Q_OBJECT

public:
	Aisde2Agraf(QWidget *parent = Q_NULLPTR);
public slots:
	void startSimulation();
	void drawGraph();

private:
	Ui::Aisde2AgrafClass ui;
	//bool sortmethod(Event x, Event y);
	double randomize(int time);
	QVector<double> bandlist;
	QVector<double> time_points;
	QVector<double> bufferlist;
};
