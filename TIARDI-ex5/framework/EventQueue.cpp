#include "EventQueue.h"

bool EventQueue::isEmpty()
{
	return queue_.empty();
}

QueueItem EventQueue::pop()
{
	//mutex_.lock();
	
	QueueItem item = queue_.back();
	queue_.pop_back();

	//mutex_.unlock();

	return item;
}

void EventQueue::add(QueueItem item)
{
	//mutex_.lock();

	queue_.push_back(item);
	
	//mutex_.unlock();
}