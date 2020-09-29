#include "Aisde2Agraf.h"

bool sortmethod(Event x, Event y)
{
	return x.time < y.time;
}


Aisde2Agraf::Aisde2Agraf(QWidget *parent) :
	QMainWindow(parent)
{
	ui.setupUi(this);
}

void Aisde2Agraf::drawGraph()
{
	ui.customplot->clearGraphs();
	ui.customplot->addGraph(ui.customplot->xAxis, ui.customplot->yAxis);
	ui.customplot->addGraph(ui.customplot->xAxis, ui.customplot->yAxis2);
	ui.customplot->graph(0)->setData(time_points, bufferlist);
	ui.customplot->graph(0)->setPen(QPen(Qt::blue));
	ui.customplot->graph(0)->setName("Wykres bufora od czasu");
	ui.customplot->graph(1)->setData(time_points, bandlist);
	ui.customplot->graph(1)->setPen(QPen(Qt::red));
	ui.customplot->graph(1)->setName("Wykres pasma od czasu");
	ui.customplot->legend->setVisible(true);
	ui.customplot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom | Qt::AlignRight);
	ui.customplot->xAxis->setLabel("czas [s]");
	ui.customplot->yAxis->setLabel("bufor [s]");
	ui.customplot->yAxis2->setVisible(true);
	ui.customplot->yAxis2->setLabel("pasmo [MB/s]");
	ui.customplot->xAxis->setRange(0, 150);
	ui.customplot->yAxis->setRange(0, 30);
	ui.customplot->yAxis2->setRange(0, 6);
	ui.customplot->replot();
	bandlist.clear();
	time_points.clear();
	bufferlist.clear();
}

double Aisde2Agraf::randomize(int time)
{
	return (double)((rand() % 16 ) + 10 + time);
}

void Aisde2Agraf::startSimulation()
{
	using namespace std;
	srand(time(NULL));

	int HIGH = 5;
	int LOW = 1;
	int bandwidth = HIGH;
	double start_time = 0;
	double temp_time = 0;
	double end_time = 150;
	double play_time = 1.25;
	double packet_size = 2.5;
	double buffer = 0;
	ofstream out;
	out.open("wyniki2a.txt");
	vector<Event> events;

	Event bandswitch(randomize(temp_time), "Bandwidth switch");
	events.push_back(bandswitch);

	Event bufferchange(temp_time + (packet_size / bandwidth), "Buffer change");
	events.push_back(bufferchange);
	out << (int)(temp_time * 100) << " " << bandwidth << " " << (int)(buffer * 100) << endl;
	time_points.push_back(temp_time);
	bandlist.push_back(bandwidth);
	bufferlist.push_back(buffer);

	while (temp_time < end_time)
	{
		sort(events.begin(), events.end(), sortmethod);
		Event choice = events.front();

		if (choice.type == "Buffer change") start_time = temp_time;

		temp_time = choice.time;

		if (choice.type == "Bandwidth switch")
		{
			if (bandwidth == LOW) bandwidth = HIGH;
			else bandwidth = LOW;
			Event bandswitch(randomize(temp_time), "Bandwidth switch");
			events.push_back(bandswitch);
		}
		else if (choice.type == "Buffer change")
		{
			buffer = buffer - (temp_time - start_time) + play_time;
			if (buffer < 0) buffer = 0;
			else if (buffer > 30) buffer = 30;
			Event bufferchange(temp_time + (packet_size / bandwidth), "Buffer change");
			events.push_back(bufferchange);
		}
		out << (int)(temp_time * 100) << " " << bandwidth << " " << (int)(buffer * 100) << endl;
		time_points.push_back(temp_time);
		bandlist.push_back(bandwidth);
		bufferlist.push_back(buffer);
		events.erase(events.begin());
	}
	out.close();
}