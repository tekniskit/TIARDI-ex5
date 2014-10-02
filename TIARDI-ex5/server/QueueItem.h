#pragma once

#include "Event.h"

class QueueItem
{
public:
	void (*eventHandler)(Event*);
	Event* event;
};