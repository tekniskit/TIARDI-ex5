#include "PatientService.h"

PatientService::PatientService()
{
	// Open connection.
}

Patient PatientService::getPatient(CprNumber cprNumber) {
	// Send request and parse response.
	return Patient(cprNumber, "vef", "adawd");
}

PatientService::~PatientService()
{
	// Close connection.
}