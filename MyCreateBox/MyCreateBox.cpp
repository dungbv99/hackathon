//
// Created by ADMIN on 26/06/2021.
//

#include "MyCreateBox.h"
#include <windows.h>
#include "iostream"
//#include "../HandleButton/HandleButton.h"
using namespace std;


pair<int,int> CreateStaticBox(HWND hwnd, wchar_t name[], int x, int y){
    CreateWindowW(L"static", name, WS_VISIBLE | WS_CHILD | WS_BORDER, x, y, wcslen(name) * 10, 20, hwnd, NULL, NULL, NULL);
    return {x + wcslen(name) * 10 + 30, y+25};
}

HWND CreateEditBox(HWND hwnd, int x, int y, int nWidth, int nHeight){
    return CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, x, y, nWidth, nHeight, hwnd, NULL, NULL, NULL);
}

void CreateButtonBox(HWND hwnd, wchar_t name[], int x, int y, int idButton){
    CreateWindowW(L"Button", name, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | SS_CENTER, x, y, wcslen(name)*10, 30, hwnd, (HMENU) idButton , NULL, NULL);
}