#pragma once

#include "NetworkEvent.h"
#include "EventHandlerInterface.h"

class QueueItem
{
private:
	EventHandlerInterface* eventHandler_;
	NetworkEvent networkEvent_;
public:
	QueueItem(EventHandlerInterface* eventHandler, NetworkEvent NetworkEvent);
	void execute();	
};