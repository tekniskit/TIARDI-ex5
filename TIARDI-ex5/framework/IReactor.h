#pragma once
#include "EventHandlerInterface.h"
#include "SynchronousEventDemultiplexerInterface.h"

typedef unsigned int Time_Value;
typedef unsigned int Event_Type;

class IReactor
{
	public:
		virtual void registerHandler(EventHandlerInterface* handler, Event_Type type) = 0;
		virtual void removeHandler(Event_Type type) = 0;
		virtual void handleEvents(Time_Value* = 0) = 0; 
		virtual void setSynchronousEventDemultiplexer(SynchronousEventDemultiplexerInterface* demux) = 0;

	private:



};