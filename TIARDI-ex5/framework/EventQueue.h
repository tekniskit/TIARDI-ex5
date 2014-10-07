#pragma once

#include <vector>

#include "QueueItem.h"

class EventQueue
{
public:
	bool isEmpty();
	QueueItem getNext();
	void add(QueueItem* item);

private:
	std::vector<QueueItem> queue;
};

