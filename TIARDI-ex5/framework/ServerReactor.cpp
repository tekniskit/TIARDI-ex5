#include "ServerReactor.h"
#include "NetworkEvent.h"
#include "EventHandlerInterface.h"

void ServerReactor::registerHandler(EventHandlerInterface* handler, Event_Type type)
{
	handlerTabel.addHandler(type, handler);
}

void ServerReactor::removeHandler(Event_Type type)
{
	handlerTabel.removeHandler(type);
}


void ServerReactor::handleEvents(Time_Value* time)
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


ServerReactor::ServerReactor()
{

}

ServerReactor::ServerReactor(EventQueue* eventQueue)
{
	eventQueue_ = eventQueue;
}

ServerReactor::ServerReactor(SynchronousEventDemultiplexerInterface* _demultiplexer)
{
	setSynchronousEventDemultiplexer(_demultiplexer);
}

void ServerReactor::setSynchronousEventDemultiplexer(SynchronousEventDemultiplexerInterface* _demultiplexer)
{
	demultiplexer = _demultiplexer;
}