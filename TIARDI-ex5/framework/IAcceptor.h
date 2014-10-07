#pragma once 
#include "EventHandlerInterface.h"
class IAcceptor : public EventHandlerInterface {
public:
	virtual void handleEvent(Handle* handle) = 0;
	virtual void accept() = 0;
};