//
// Created by ADMIN on 27/06/2021.
//

#include "HttpLib.h"
#include "windows.h"
#include "iostream"
#include "winhttp.h"
#include "string"
using namespace std;
#pragma comment(lib, "winhttp.lib")
const HttpResponse ErrorResponse = HttpResponse{"", false};

HttpResponse HttpGet(LPCWSTR domain,  int port, LPCWSTR path){
    BOOL  bResults = FALSE;
    HINTERNET hSession = NULL,
            hConnect = NULL,
            hRequest = NULL;
    LPSTR pszOutBuffer;
    DWORD dwSize = 0;
    DWORD dwDownloaded = 0;

    // Use WinHttpOpen to obtain a session handle.
    hSession = WinHttpOpen(  L"A WinHTTP Example Program/1.0",
                             WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                             WINHTTP_NO_PROXY_NAME,
                             WINHTTP_NO_PROXY_BYPASS, 0);

    // Specify an HTTP server.
    if (hSession)
        hConnect = WinHttpConnect( hSession, domain,
                                   port, 0);
    // Create an HTTP Request handle.
    if (hConnect)
        hRequest = WinHttpOpenRequest( hConnect, L"GET",
                                       path,
                                       NULL, WINHTTP_NO_REFERER,
                                       WINHTTP_DEFAULT_ACCEPT_TYPES,
                                       0);


    // Send a Request.
    if (hRequest)
        bResults = WinHttpSendRequest( hRequest,
                                       WINHTTP_NO_ADDITIONAL_HEADERS,
                                       0, WINHTTP_NO_REQUEST_DATA, 0,
                                       0, 0);



    // End the request.
    if (bResults)
        bResults = WinHttpReceiveResponse( hRequest, NULL);

    // Report any errors.
    HttpResponse res = {"", false};
    if (bResults){
        do
        {
            // Check for available data.
            dwSize = 0;
            if (!WinHttpQueryDataAvailable( hRequest, &dwSize))
            {
                printf( "Error %u in WinHttpQueryDataAvailable.\n",
                        GetLastError());
                break;
            }


            // No more available data.
            if (!dwSize)
                break;

            // Allocate space for the buffer.
            pszOutBuffer = new char[dwSize+1];
            if (!pszOutBuffer)
            {
                printf("Out of memory\n");
                break;
            }

            // Read the Data.
            ZeroMemory(pszOutBuffer, dwSize+1);

            if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer,
                                  dwSize, &dwDownloaded))
            {
                printf( "Error %u in WinHttpReadData.\n", GetLastError());
            }
            else
            {
                res = {pszOutBuffer, true};
            }

            // Free the memory allocated to the buffer.
            delete [] pszOutBuffer;

            // This condition should never be reached since WinHttpQueryDataAvailable
            // reported that there are bits to read.
            if (!dwDownloaded)
                break;

        } while (dwSize > 0);
    }
    else
    {
        // Report any errors.
        printf( "Error %d has occurred.\n", GetLastError() );
    }
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);
    return res;
}

HttpResponse HttpPost(LPCWSTR domain,  int port, LPCWSTR path, LPSTR data){
    BOOL  bResults = FALSE;
    HINTERNET hSession = NULL,
            hConnect = NULL,
            hRequest = NULL;
    LPSTR pszOutBuffer;
    DWORD dwSize = 0;
    DWORD dwDownloaded = 0;

    // Use WinHttpOpen to obtain a session handle.
    hSession = WinHttpOpen(  L"A WinHTTP Example Program/1.0",
                             WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                             WINHTTP_NO_PROXY_NAME,
                             WINHTTP_NO_PROXY_BYPASS, 0);

    // Specify an HTTP server.
    if (hSession)
        hConnect = WinHttpConnect( hSession, domain,
                                   port, 0);
    // Create an HTTP Request handle.
    if (hConnect)
        hRequest = WinHttpOpenRequest( hConnect, L"POST",
                                       path,
                                       NULL, WINHTTP_NO_REFERER,
                                       WINHTTP_DEFAULT_ACCEPT_TYPES,
                                       0);


    // Send a Request.
    if (hRequest)
        bResults = WinHttpSendRequest( hRequest,
                                       WINHTTP_NO_ADDITIONAL_HEADERS,
                                       0, data, strlen(data),
                                       (DWORD)strlen(data), 0);



    // End the request.
    if (bResults)
        bResults = WinHttpReceiveResponse( hRequest, NULL);

    // Report any errors.
    HttpResponse res = {"", false};
    if (bResults){
        do
        {
            // Check for available data.
            dwSize = 0;
            if (!WinHttpQueryDataAvailable( hRequest, &dwSize))
            {
                printf( "Error %u in WinHttpQueryDataAvailable.\n",
                        GetLastError());
                break;
            }


            // No more available data.
            if (!dwSize)
                break;

            // Allocate space for the buffer.
            pszOutBuffer = new char[dwSize+1];
            if (!pszOutBuffer)
            {
                printf("Out of memory\n");
                break;
            }

            // Read the Data.
            ZeroMemory(pszOutBuffer, dwSize+1);

            if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer,
                                  dwSize, &dwDownloaded))
            {
                printf( "Error %u in WinHttpReadData.\n", GetLastError());
            }
            else
            {
                res = {pszOutBuffer, true};
            }

            // Free the memory allocated to the buffer.
            delete [] pszOutBuffer;

            // This condition should never be reached since WinHttpQueryDataAvailable
            // reported that there are bits to read.
            if (!dwDownloaded)
                break;

        } while (dwSize > 0);
    }
    else
    {
        // Report any errors.
        printf( "Error %d has occurred.\n", GetLastError() );
    }
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);
    return res;
}