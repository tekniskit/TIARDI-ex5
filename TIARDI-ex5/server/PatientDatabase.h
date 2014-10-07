#pragma once

#include "Patient.h"
#include "CprNumber.h"

using namespace std;

class PatientDatabase
{
public:
	Patient getPatient(CprNumber cprNumber);
};