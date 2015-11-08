#ifndef HA_MUTEX
#define HA_MUTEX

#ifdef _WIN32
#include <windows.h>
#else
//Linux and other OS
#endif
#include "Common.h"

class HAMutex
{
public:
#ifdef _WIN32
	HAMutex(PSECURITY_ATTRIBUTES lpMutexAttributes = NULL, BOOL bInitialOwner = false, LPCTSTR lpName = NULL);
#else
//Linux and other OS
#endif
	~HAMutex();

	int GetMutex();
	void FreeMutex();
private:
	VPHANDLE hMutex;
};

#endif // HA_MUTEX