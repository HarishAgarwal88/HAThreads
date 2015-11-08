#ifndef HA_SEMAPHORE
#define HA_SEMAPHORE

#ifdef _WIN32
#include <windows.h>
#else
//Linux and other OS
#endif
#include "Common.h"

class Semaphore
{
public:
#ifdef _WIN32
	Semaphore(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes = NULL, LONG lInitialCount = 1, LONG  lMaximumCount = 1, LPCTSTR lpName = NULL);
#else
//Linux and other OS
#endif
	~Semaphore();

	int GetSemaphore();
	void FreeSemaphore(LONG lReleaseCount = 1, LPLONG lpPreviousCount = NULL);

private:
	VPHANDLE hSemaphore;
};

#endif // HA_SEMAPHORE