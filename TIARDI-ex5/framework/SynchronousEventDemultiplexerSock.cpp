#include "SynchronousEventDemultiplexerSock.h"
#include <string>
#include <iostream>
#include <WinSock2.h>

SynchronousEventDemultiplexerSock::SynchronousEventDemultiplexerSock(SOCK_Acceptor* acceptor, std::list<SOCK_Stream*>* socketList)
{
	acceptorPtr = acceptor;
	socketList_ = socketList;
}

SynchronousEventDemultiplexerSock::~SynchronousEventDemultiplexerSock()
{
	
	delete acceptorPtr; 
}

NetworkEvent SynchronousEventDemultiplexerSock::getNetworkEvent()
{
	struct timeval tv;
	NetworkEvent Nevent; 
	prepFdsSet();
	// wait until either socket has data ready to be recv()d (timeout 10.5 secs)
	tv.tv_sec = 10;
	tv.tv_usec = 500000;

	// to make it work with special sockets 
	int n = socketList_->size() > 0 ? (socketList_->back())->get_handle() + 1 : *acceptorPtr->getSocket() + 1;

	int rv = select(n, &readfds, &writefds, &Errorfds, &tv);

	if (rv == -1) {
		Nevent.setEventType(0); 
	}
	else if (rv == 0) {
		Nevent.setEventType(0);
	}
	else 
	{
		int response = FD_ISSET(*(acceptorPtr->getSocket()), &readfds);
		if ( response > 0)
		{
			Nevent.setEventType(6); 
			Nevent.setHandle(nullptr); 
			std::cout << "Client connect event" << std::endl;
			return Nevent; 
		}
		try{
		for (std::list<SOCK_Stream*>::iterator it = socketList_->begin(); it != socketList_->end(); it++)
			{
				SOCK_Stream* value = *it;

				//Create Read Events
				if (FD_ISSET(value->get_handle(), &readfds)) {
					// can be disconnect 
					// can be data 
				
						char networkdata[100]; 
						int resived = value->recv(networkdata, 100, 0);
						if (resived == 0)
						{
							Disconnect(value);
						}
						else
						{
							std::cout << "Networkdata: " << networkdata << std::endl;
							char ev = networkdata[0]; 
							handle = NetworkHandle(value);
							Nevent.setEventType(ev-48);
							std::string data(networkdata + 1, resived-1);
							handle.setData(data);
							Nevent.setHandle((Handle*)&handle); 
						
							return Nevent; 
						}
				

				}


				//Create write Event 
				if (FD_ISSET(value->get_handle(), &writefds)) {
					handle = NetworkHandle(value);
					Nevent.setEventType(4);
					Nevent.setHandle((Handle*)&handle);
					return Nevent;
				}
			}
		}
		catch (exception e)
		{
			//Disconnect(value);
		}
	}

	
	return Nevent; 
}

void SynchronousEventDemultiplexerSock::prepFdsSet()
{
	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	FD_ZERO(&Errorfds);

	FD_SET(*acceptorPtr->getSocket(), &readfds);

	for (std::list<SOCK_Stream*>::iterator it = socketList_->begin(); it != socketList_->end(); it++)
	{
		SOCK_Stream* value = *it;
		FD_SET(value->get_handle(), &readfds);
		FD_SET(value->get_handle(), &writefds);
		FD_SET(value->get_handle(), &Errorfds);
	}

}


void SynchronousEventDemultiplexerSock::Disconnect(SOCK_Stream* value)
{
	socketList_->remove(value);
	delete value;
}