// server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include "EventQueue.h"
#include "Acceptor.h"
#include "ServerReactor.h"
#include "INET_Addr.h"
#include "SynchronousEventDemultiplexerSock.h"
#include "ReadFromDatabaseEvent.h"

using namespace std;

EventQueue eventQueue;

void reactorTask()
{
	ServerReactor reactor(&eventQueue);
	ReadFromDatabaseEvent databaseHandler;
	reactor.registerHandler(&databaseHandler, 7);
	Acceptor acceptor(5500, (IReactor*)&reactor); // &SOCK_Acceptor

	for (;;){
		reactor.handleEvents();
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	thread reactorThread(reactorTask);

	while (true) {
		if (eventQueue.isEmpty()) continue;

		QueueItem next = eventQueue.pop();
		next.execute();

	}

	return 0;
}