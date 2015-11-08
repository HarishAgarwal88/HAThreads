#include "HAEvent.h"
#include <iostream>

#ifdef _WIN32
HAEvent::HAEvent(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL  bInitialState, LPCTSTR lpName)
{
	hEvent = CreateEvent(lpEventAttributes,bManualReset, bInitialState, lpName);
	if(hEvent == NULL)
	{
		std::cout << "Create Event Failed : " << GetLastError() << std::endl;
	}
}
#else
//Linux and other OS
#endif

HAEvent::~HAEvent()
{
#ifdef _WIN32
	if(hEvent != NULL)
	{
		CloseHandle(hEvent);
	}
#else
//Linux and other OS
#endif
}

int HAEvent::SignalEvent()
{
#ifdef _WIN32
	if(hEvent != NULL)
	{
		bool bStatus = SetEvent(hEvent);
		if(bStatus == false)
		{
			std::cout << "Signal Event Failed : " << GetLastError() << std::endl;
		}

		return (int)bStatus;
	}
#else
//Linux and other OS
#endif
	return 0;
}

int HAEvent::SetEventStateNonSignalled()
{
#ifdef _WIN32
	if(hEvent != NULL)
	{
		bool bStatus = ResetEvent(hEvent);
		if(bStatus == false)
		{
			std::cout << "Non Signalling Event Failed : " << GetLastError() << std::endl;
		}
		return (int)bStatus;
	}
#else
//Linux and other OS
#endif
	return 0;
}

int HAEvent::WaitForSignal()
{
#ifdef _WIN32
	int iRet = 0xFFFFFFFF;
	if(hEvent != NULL)
	{
		iRet = WaitForSingleObject(hEvent, INFINITE);
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

