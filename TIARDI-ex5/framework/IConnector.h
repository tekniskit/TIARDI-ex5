#pragma once 
#include "EventHandlerInterface.h"

template < class SERVICE_HANDLER, class ICONNECTOR>
class IConnector : EventHandlerInterface
{

public:
	virtual void handleEvent(Handle* handle) = 0; 

	virtual void Connect(SERVICE_HANDLER* SH, const ICONNECTOR) = 0; 

private:

};