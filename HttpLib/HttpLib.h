//
// Created by ADMIN on 27/06/2021.
//

#include "string"
#include "windows.h"
using namespace std;

#ifndef HACKATHON_HTTPLIB_H
#define HACKATHON_HTTPLIB_H

struct HttpResponse{
    string value;
    bool err;
};

HttpResponse HttpGet(LPCWSTR domain,  int port, LPCWSTR path);
HttpResponse HttpPost(LPCWSTR domain,  int port, LPCWSTR path, LPSTR data);

#endif //HACKATHON_HTTPLIB_H
