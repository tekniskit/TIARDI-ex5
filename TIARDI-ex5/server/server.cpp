// server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include "EventQueue.h"

using namespace std;

void reactorTask(EventQueue* queue)
{

}

int _tmain(int argc, _TCHAR* argv[])
{
	EventQueue eventQueue;
	
	thread reactorThread(reactorTask, eventQueue);

	while (true) {
		if (eventQueue.isEmpty()) continue;

		QueueItem next = eventQueue.getNext();
		next.eventHandler(next.event);
	}

	return 0;
}