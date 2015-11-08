#ifndef EVENT_HA
#define EVENT_HA

#ifdef _WIN32
#include <windows.h>
#else
//Linux and other OS
#endif
#include "Common.h"

class HAEvent
{
public:
#ifdef _WIN32
	HAEvent(LPSECURITY_ATTRIBUTES lpEventAttributes = NULL, BOOL bManualReset = true, BOOL  bInitialState = false, LPCTSTR lpName = NULL);
#else
//Linux and other OS
#endif
	~HAEvent();
	int SignalEvent();
	int SetEventStateNonSignalled();
	int WaitForSignal();
private:
	VPHANDLE hEvent;
};

#endif //EVENT_HA