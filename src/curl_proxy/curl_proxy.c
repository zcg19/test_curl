#define  CURL_STATICLIB
#include "curl/curl.h"
#include <assert.h>


#pragma comment(lib, "libcurl_static_mt_ssl_dll.lib")


__declspec(dllexport) int SendHttpMsg(const char * szUrl, int nTimeout)
{
	CURLcode nRet = CURLE_OK;
	CURL  * pCurl = curl_easy_init();
	if(!pCurl) return -1;

	do
	{
		assert(szUrl);
		nRet = curl_easy_setopt(pCurl, CURLOPT_URL, szUrl);
		if(nRet != CURLE_OK) break;

		if(nTimeout > 0)
		{
			nRet = curl_easy_setopt(pCurl, CURLOPT_CONNECTTIMEOUT, nTimeout);
			if(nRet != CURLE_OK) break;
		}

		nRet = curl_easy_perform(pCurl);
	}while(0);

	curl_easy_cleanup(pCurl);
	return nRet;
}
