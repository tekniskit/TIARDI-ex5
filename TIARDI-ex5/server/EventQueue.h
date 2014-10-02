#pragma once

#include <vector>

#include "QueueItem.h"

class EventQueue
{
public:
	bool isEmpty();
	QueueItem getNext();
	void add(Event, EventHandler);

private:
	std::vector<QueueItem> queue;
};

