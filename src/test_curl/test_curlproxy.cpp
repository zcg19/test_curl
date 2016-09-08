#include <windows.h>
#include <stdio.h>
#include <assert.h>


void main()
{
	// for test. 
	printf(">> please enter key to start:\n");
	getchar();

	HMODULE hMod = ::LoadLibraryA("curl_proxy.dll");
	assert(hMod);

	typedef int (*pfSendHttpMsg)(const char * szUrl, int nTimeout);
	pfSendHttpMsg pSend = (pfSendHttpMsg)::GetProcAddress(hMod, "SendHttpMsg");
	if(pSend)
	{
		printf("%08u [test]: to send\n", GetTickCount());
		int nRet = pSend("http://1936.168.10.101/adfafa.aadfadf.1", 3);
		printf("%08u [test]: to send ->ret = %d\n", GetTickCount(), nRet);
	}

	::FreeLibrary(hMod);

	// prevent the process from exiting.
	getchar();
}
