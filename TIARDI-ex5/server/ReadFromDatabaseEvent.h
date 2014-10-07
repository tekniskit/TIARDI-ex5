#pragma once
#include "EventHandlerInterface.h"
#include <string>
#include "PatientDatabase.h"

using namespace std;

class ReadFromDatabaseEvent : public EventHandlerInterface{
public:
	ReadFromDatabaseEvent();
	~ReadFromDatabaseEvent();

	void handleEvent(Handle* handle);

private:
	PatientDatabase database_;
};