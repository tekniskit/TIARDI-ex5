#include "Reactor.h" 
#include <string>
#include "CprNumber.h"
#include "PatientService.h"
#include "Connector.h"
#include "Reactor.h"
#include "EventHandlerInterface.h"

using namespace std;

#define RECIVE 0 
#define WRITE 1

class Controller : EventHandlerInterface
{
public:
	Controller(Reactor* reactor_);
	Controller(){};

	void Setup(string ip, u_short port);

	void handleEvent(Handle* handle); 

	void ConnectedFunction(Handle* stream);

	~Controller();

private:

	
	int State = 1; 
	Reactor* reactor; 
	PatientService patientService;
};

