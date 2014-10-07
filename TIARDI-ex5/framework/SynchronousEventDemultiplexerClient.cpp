#include "SynchronousEventDemultiplexerClient.h"
#include <iostream>

SynchronousEventDemultiplexerClient::SynchronousEventDemultiplexerClient(SOCK_Stream* stream){
	stream_ = stream;
}

NetworkEvent SynchronousEventDemultiplexerClient::getNetworkEvent() {
	
	NetworkEvent networkEvent;
	
	struct timeval tv;
	// wait until either socket has data ready to be recv()d (timeout 10.5 secs)
	tv.tv_sec = 10;
	tv.tv_usec = 500000;

	fd_set writefds;
	fd_set readfds;
	FD_ZERO(&writefds);
	FD_ZERO(&readfds); 

	FD_SET(stream_->get_handle(), &writefds);
	FD_SET(stream_->get_handle(), &readfds);

	int rv = select(stream_->get_handle() + 1, &readfds, &writefds, NULL, &tv);

	if (rv == -1) {
		networkEvent.setEventType(0);
		return networkEvent;		
	}
	else if (rv == 0) {
		networkEvent.setEventType(0);
		return networkEvent;
	}


	if (FD_ISSET(stream_->get_handle(), &readfds)) {
		// can be disconnect 
		// can be data 
		try
		{
			char networkdata[100];
			int resived = stream_->recv(networkdata, 100, 0);
			if (resived != 0)
			{
				std::cout << "Networkdata: " << networkdata << std::endl;
				char ev = networkdata[0];
				handle = NetworkHandle(stream_);
				networkEvent.setEventType(ev - 48);
				std::string data(networkdata + 1, resived - 1);
				handle.setData(data);
				networkEvent.setHandle((Handle*)&handle);

				return networkEvent;
			}
		}
		catch (std::exception e)
		{

		}
	}

	//Create write Event 
	if (FD_ISSET(stream_->get_handle(), &writefds)) {
		if (isOpen == false)
		{
			networkEvent.setEventType(10);
			isOpen = true; 
		}
		else
		{
			networkEvent.setEventType(4);
		}
		
		handle = NetworkHandle(stream_);
		networkEvent.setHandle(&handle);
		return networkEvent;
	}
	return networkEvent;
}