#include "HAMutex.h"
#include <iostream>

#ifdef _WIN32
HAMutex::HAMutex(PSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCTSTR lpName)
{
	hMutex = CreateMutex(lpMutexAttributes, bInitialOwner, lpName);
	if(hMutex == NULL)
	{
		std::cout << "CreateMutex failed, error : " << GetLastError() << std::endl;
	}
}
#else
//Linux and other OS
#endif

HAMutex::~HAMutex()
{
#ifdef _WIN32
	if(hMutex != NULL)
	{
		CloseHandle(hMutex);
	}
#else
//Linux and other OS
#endif

}

int HAMutex::GetMutex()
{
#ifdef _WIN32
	int iRet = 0xFFFFFFFF;
	iRet = WaitForSingleObject(hMutex, INFINITE);

	if(iRet != WAIT_OBJECT_0)
	{
		std::cout << "Failed to acquire mutex "  << GetLastError() << std::endl;
		return -1;
	}
	else
	{
		return iRet;
	}
#else
//Linux and other OS
#endif
}

void HAMutex::FreeMutex()
{
#ifdef _WIN32
	bool bStatus = ReleaseMutex(hMutex);
	if(!bStatus)
	{
		std::cout << "Release Mutex Failed " << GetLastError() << std::endl;
	}
#else
//Linux and other OS
#endif
}