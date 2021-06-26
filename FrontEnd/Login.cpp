//
// Created by ADMIN on 26/06/2021.
//

#include "Login.h"
#include <windows.h>
#include "iostream"
#include "../MyCreateBox/MyCreateBox.h"
#include "../HandleButton/HandleButton.h"
#include "string"
using namespace std;
HWND hwndUserName;
HWND hwndPassWd;
void Login(HWND hwnd){
    int widthScreen = GetSystemMetrics(SM_CXFULLSCREEN);
    int heightScreen = GetSystemMetrics(SM_CYMAXIMIZED);
    int startPoint = GetSystemMetrics(ARW_TOPLEFT);
    int xUN = startPoint + widthScreen/ 2 - 300;
    int yUN = (startPoint + heightScreen) /2 - 200;
    pair<int, int> nextCoordinates1 = CreateStaticBox(hwnd, L"User Name", xUN, yUN);
    hwndUserName = CreateEditBox(hwnd, nextCoordinates1.first, yUN, 200, 20);
    pair<int, int> nextCoordinates2 = CreateStaticBox(hwnd, L"Pass Word", xUN, nextCoordinates1.second);
    hwndPassWd = CreateSecretEditBox(hwnd, nextCoordinates1.first, nextCoordinates1.second, 200, 20);
    CreateButtonBox(hwnd, L"Login", xUN, nextCoordinates2.second, LOGINBUTTON);
}

void HandleLoginButton(){
    int userNameLength = GetWindowTextLengthA(hwndUserName);
    int passwdLength = GetWindowTextLengthA(hwndPassWd);
    char* userName = (char*)malloc(sizeof(char)*(userNameLength+1));
    char* passWd = (char*) malloc(sizeof(char) * (passwdLength+1));
    GetWindowTextA(hwndUserName, userName, userNameLength+1);
    GetWindowTextA(hwndPassWd, passWd, passwdLength+1);
    User user = {
            userName,
            passWd,
    };

    cout << "name " <<  user.UserName << "     " << " passwd " << user.PassWd << "\n" ;
}