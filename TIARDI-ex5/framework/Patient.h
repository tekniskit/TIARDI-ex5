#pragma once

#include <string>
#include "CprNumber.h"

using namespace std;

class Patient
{
public:
	Patient(CprNumber cprNumber, string name, string address);
	friend ostream& operator<<(ostream& os, const Patient& dt);
	string getPatientEvent();

private:
	CprNumber cprNumber_;
	string name_;
	string address_;
};