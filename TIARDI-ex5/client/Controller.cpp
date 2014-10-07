#include "Controller.h"
#include <iostream>
#include "PatientEvent.h"
#include "PatientEventHandler.h"

Controller::Controller(Reactor* reactor_)
{
	reactor = reactor_;
}


void Controller::handleEvent(Handle* handle)
{
	switch (State)
	{

	case WRITE:
	{
				  cout << "Enter CPR-number: ";
				  string input;
				  cin >> input;

				  try {
					  CprNumber cpr(input);

					  handle->send("7;" + input); 

					  reactor->removeHandler(4);
					  reactor->registerHandler(this, 3);
					  State = RECIVE;
				  }
				  catch (exception e) {
					  cout << e.what() << endl;
				  }
	}
	break;

	case RECIVE:
	{

		PatientEventHandler handler;
		handler.handleEvent(handle);

		reactor->removeHandler(3);
		reactor->registerHandler(this, 4);
		State = WRITE;
	}
	default:
		break;
	}



}

Controller::~Controller()
{

}


void Controller::ConnectedFunction(Handle* stream)
{
	cout << "Connected";

	reactor->registerHandler(this, 4);
	State = WRITE;
}