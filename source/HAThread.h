#ifndef HA_THREAD
#define HA_THREAD

#ifdef _WIN32
#include <windows.h>
#else
//Linux and other OS
#endif
#include "Common.h"

class HAThread
{
public:
	HAThread(void* arg = NULL);
	virtual ~HAThread();
	/*template <class T>
	HAThread(T threadObj);*/
	virtual void Run(void *arg = NULL);
	void Join();
	void Detach();
	bool isJoinable();
	ULONG GetThreadId();

private:

	ULONG threadId;
	VPHANDLE threadHandle;
};

#endif // HA_THREAD