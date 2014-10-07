#include "ReadFromDatabaseEvent.h"


ReadFromDatabaseEvent::ReadFromDatabaseEvent()
{
}


ReadFromDatabaseEvent::~ReadFromDatabaseEvent()
{
}

void ReadFromDatabaseEvent::handleEvent(Handle* handle){
	string request = handle->receive();
	request = request.substr(1, request.length() - 1);
	CprNumber cpr(request);
	Patient patient = database_.getPatient(cpr);
	handle->send(patient.getPatientEvent());
}