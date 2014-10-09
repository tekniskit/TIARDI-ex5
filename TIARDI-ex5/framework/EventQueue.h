#pragma once

#include <vector>
#include <mutex>

#include "QueueItem.h"

class EventQueue
{
public:
	bool isEmpty();
	QueueItem pop();
	void add(QueueItem item);

private:
	std::vector<QueueItem> queue_;
	std::mutex mutex_;
};