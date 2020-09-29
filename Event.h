#pragma once

#include <string>

class Event
{
public:
	Event(double time, std::string type);
	Event(const Event &event);
	~Event();
	double time;
	std::string type;
};

