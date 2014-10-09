#pragma once
#include "IReactor.h"
#include "DemuxTable.h" 
#include "SynchronousEventDemultiplexerInterface.h"
#include "SOCK_Stream.h"
#include <list>
#include "EventQueue.h"
#include "QueueItem.h"

class ServerReactor:IReactor
{

public:
	void registerHandler(EventHandlerInterface* handler, Event_Type type);
	void removeHandler(Event_Type type);
	void handleEvents(Time_Value* = 0);
	void setSynchronousEventDemultiplexer(SynchronousEventDemultiplexerInterface*);
	void pushStream(SOCK_Stream* stream);
	void removeStream(SOCK_Stream* stream);
	ServerReactor(SynchronousEventDemultiplexerInterface* _demultiplexer);
	ServerReactor(EventQueue* eventQueue);
	ServerReactor();

private:
	// variables 
	EventQueue* eventQueue_;
	SynchronousEventDemultiplexerInterface* demultiplexer; 
	DemuxTable handlerTabel;
};