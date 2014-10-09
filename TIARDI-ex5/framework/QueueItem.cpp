#include "QueueItem.h"

QueueItem::QueueItem(EventHandlerInterface* eventHandler, NetworkEvent networkEvent){
	eventHandler_ = eventHandler;
	networkEvent_ = networkEvent;
}

void QueueItem::execute(){
	eventHandler_->handleEvent(networkEvent_.getHandle());
	delete networkEvent_.getHandle();
}