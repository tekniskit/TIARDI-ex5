#include "CprNumber.h"

CprNumber::CprNumber()
{
	
}

CprNumber::CprNumber(string cprNumber)
{
	setCprNumber(cprNumber);
}

void CprNumber::setCprNumber(string cprNumber) {
	cprNumber_ = cprNumber;
	/*regex rgx("[0-9]{6}-[0-9]{4}");

	if (regex_match(cprNumber, rgx))
		cprNumber_ = cprNumber;
	else
		throw exception("Invalid CPR-number");*/
}

string CprNumber::getCprNumber() {
	return cprNumber_;
}