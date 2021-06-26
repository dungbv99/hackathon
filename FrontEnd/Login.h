//
// Created by ADMIN on 26/06/2021.
//

#include "windows.h"
#include "string"
#include "test.h"
using namespace std;

#ifndef HACKATHON_LOGIN_H
#define HACKATHON_LOGIN_H
struct User{
    string UserName;
    string PassWd;
};
void HandleLoginButton();
void Login(HWND hwnd);

#endif //HACKATHON_LOGIN_H
