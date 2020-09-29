#include "Event.h"


Event::Event(double time, std::string type)
{
	this->time = time;
	this->type = type;
}

Event::Event(const Event & event)
{
	time = event.time;
	type = event.type;
}

Event::~Event()
{
}
