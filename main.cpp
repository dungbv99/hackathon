#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include "fstream"
#include <winhttp.h>
#include "MyCreateBox/MyCreateBox.h"
#include "HandleButton/HandleButton.h"
#include "FrontEnd/Login.h"
using namespace std;


ofstream logFile("log.txt");
int widthScreen = GetSystemMetrics(SM_CXFULLSCREEN);
int heightScreen = GetSystemMetrics(SM_CYMAXIMIZED);
int startPoint = GetSystemMetrics(ARW_TOPLEFT);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow){
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"BkTrust";

    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
            0,                              // Optional window styles.
            CLASS_NAME,                     // Window class
            L"BKTrust",    // Window text
            WS_OVERLAPPEDWINDOW,            // Window style

            // Size and position
            startPoint, startPoint, widthScreen, heightScreen,

            NULL,       // Parent window
            NULL,       // Menu
            hInstance,  // Instance handle
            NULL        // Additional application data
    );
    SetWindowPos(hwnd, HWND_TOPMOST, startPoint, startPoint, widthScreen, heightScreen, NULL );
    SetWindowLongA(hwnd, GWL_STYLE, (GetWindowLongA(hwnd, GWL_STYLE) & \
                    ~WS_MAXIMIZEBOX &
                    ~WS_MINIMIZEBOX &
                    ~WS_THICKFRAME &
                    ~WS_SIZEBOX
//                    WS_CAPTION&
//                    WS_SYSMENU
    ));

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    switch (uMsg)
    {
        case WM_CREATE:
            Login(hwnd);
            return 0;
        case WM_COMMAND:
            switch (wParam) {
                case LOGINBUTTON:
                    HandleLoginButton();
                    return 0;
            }
            return 0;
        case WM_MOVE:
            SetWindowPos(hwnd, HWND_TOPMOST,  0, 0, widthScreen, heightScreen, NULL );
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);



            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
            return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

