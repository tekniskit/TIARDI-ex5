#pragma once
#include "IAcceptor.h"
#include "IReactor.h"
class Acceptor : public IAcceptor
{
public:
	Acceptor();
	Acceptor(int port, IReactor* reactor);
	~Acceptor();
	void handleEvent(Handle* handle);
	void accept();
};