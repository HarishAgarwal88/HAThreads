#include "HAThread.h"
#include <iostream>

/*template<class T>
HAThread::HAThread(T threadObj)
{	
}*/
typedef struct 
{
	HAThread *pth;
	void* arg;
}sThArg;

ULONG threadFunc(PVOID lpVoid)
{
	sThArg *pArg = reinterpret_cast<sThArg*> (lpVoid);
	HAThread *pthread = pArg->pth;
	pthread->Run(pArg->arg);

	return 0;
}

HAThread::HAThread(void* arg)
{
	sThArg *funcArg = new sThArg;
	funcArg->pth = this;
	funcArg->arg = arg;

#ifdef _WIN32
	threadHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)threadFunc, (LPVOID)funcArg, 0, &threadId);
	if(threadHandle == NULL)
	{
		std::cout << "Thread creation failed" << std::endl;
	}
#else
//Linux and other OS
#endif	
}

HAThread::~HAThread()
{
#ifdef _WIN32
	bool bStatus = CloseHandle(threadHandle);
	if(!bStatus)
	{
		std::cout << "Close Hanlde failed for , threadId : " << threadId << std::endl;
	}
#else
//Linux and other OS
#endif
}

void HAThread::Run(void* arg)
{
	std::cout << "Overwrite Run Method that need to be executed in thread" << std::endl;
}

void HAThread::Join()
{
#ifdef _WIN32
	int iRet = 0xFFFFFFFF;
	iRet = WaitForSingleObject(threadHandle, INFINITE);
	if(iRet != WAIT_OBJECT_0)
	{
		std::cout << "Wait Single Object failed , threadId : " << threadId << std::endl;
	}
#else
//Linux and other OS
#endif
}

ULONG HAThread::GetThreadId()
{
#ifdef _WIN32
	if(threadId != NULL)
	{
		return threadId;
	}
	else
		return 0.0;
#else
//Linux and other OS
#endif
}

void HAThread::Detach()
{
	//implement for linux
}

bool HAThread::isJoinable()
{
	return true;
}