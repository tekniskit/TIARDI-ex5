#pragma once 
#include "IConnector.h"
#include "Reactor.h"
#include "SOCK_Connector.h"

typedef void(*ConnectFunction) (Handle*);

class Connector:EventHandlerInterface
{

public:
	Connector(Reactor *reactor_);
	~Connector();

	void handleEvent(Handle* handle); 

	void Connect(ConnectFunction sh_, INET_Addr addr);

private:
	SOCK_Connector sock_connector;
	Reactor * reactor =  nullptr; 
	ConnectFunction sh;
};


