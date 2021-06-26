//
// Created by ADMIN on 26/06/2021.
//
#include <windows.h>
#include <windows.h>
#include "iostream"
using namespace std;

#ifndef HACKATHON_MYCREATEBOX_H
#define HACKATHON_MYCREATEBOX_H


pair<int,int> CreateStaticBox(HWND hwnd, wchar_t name[], int x, int y);
HWND CreateEditBox(HWND hwnd, int x, int y, int nWidth, int nHeight);
void CreateButtonBox(HWND hwnd, wchar_t name[], int x, int y, int idButton);
HWND CreateSecretEditBox(HWND hwnd, int x, int y, int nWidth, int nHeight);
#endif //HACKATHON_MYCREATEBOX_H
