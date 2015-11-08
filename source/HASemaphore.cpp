#include "HASemaphore.h"
#include <iostream>

#ifdef _WIN32
Semaphore::Semaphore(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, LONG lInitialCount, LONG  lMaximumCount, LPCTSTR lpName)
{
	hSemaphore = CreateSemaphore(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName);
	if(hSemaphore == NULL)
	{
		std::cout << "Semaphore Creation Failed : " << GetLastError() << std::endl;
	}
}
#else
//Linux and other OS
#endif

Semaphore::~Semaphore()
{
#ifdef _WIN32
	if(hSemaphore != NULL)
	{
		CloseHandle(hSemaphore);
	}
#else
//Linux and other OS
#endif
}

int Semaphore::GetSemaphore()
{
#ifdef _WIN32
	int iRet = 0xFFFFFFFF;
	if(hSemaphore != NULL)
	{
		iRet = WaitForSingleObject(hSemaphore, INFINITE);
	}

	if(iRet != WAIT_OBJECT_0)
	{
		std::cout << "Failed to acquire semaphore "  << GetLastError() << std::endl;
		return -1;
	}
#else
//Linux and other OS
#endif
}

void Semaphore::FreeSemaphore(LONG lReleaseCount, LPLONG lpPreviousCount)
{
#ifdef _WIN32
	if(hSemaphore != NULL)
	{
		bool bStatus = ReleaseSemaphore(hSemaphore, lReleaseCount, lpPreviousCount);
		if(bStatus == 0)
		{
			std::cout << "Not able to Release Semaphore : " << GetLastError() << std::endl;
		}
	}
#else
//Linux and other OS
#endif
}