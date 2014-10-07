#pragma once
#include "Patient.h"

class PatientService
{
public:
	PatientService();
	~PatientService();
	Patient getPatient(CprNumber cprNumber);
};

