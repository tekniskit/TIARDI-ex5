#include "Reactor.h"
#include "NetworkEvent.h"
#include "EventHandlerInterface.h"

void Reactor::registerHandler(EventHandlerInterface* handler, Event_Type type)
{
	handlerTabel.addHandler(type, handler);
}

void Reactor::removeHandler(Event_Type type)
{
	handlerTabel.removeHandler(type);
}


void Reactor::handleEvents(Time_Value* time)
{
	NetworkEvent event = demultiplexer->getNetworkEvent();
	if (event.getEventType() != 0)
	{

		EventHandlerInterface* handler = handlerTabel.getHandler(event.getEventType());

		if (handler != nullptr)
		{
			QueueItem item(handler, event);
			eventQueue_->add(item);			
		}
	}
}


Reactor::Reactor()
{

}

Reactor::Reactor(EventQueue* eventQueue)
{
	eventQueue_ = eventQueue;
}

Reactor::Reactor(SynchronousEventDemultiplexerInterface* _demultiplexer)
{
	setSynchronousEventDemultiplexer(_demultiplexer);
}

void Reactor::setSynchronousEventDemultiplexer(SynchronousEventDemultiplexerInterface* _demultiplexer)
{
	demultiplexer = _demultiplexer;
}