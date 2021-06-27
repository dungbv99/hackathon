#include "windows.h"
#include "iostream"
#include "winhttp.h"
using namespace std;
#pragma comment(lib, "winhttp.lib")
#include "HttpLib/HttpLib.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow){
    LPSTR  data = "{\"A\":0,\"B\":\"22\"}";
    HttpResponse res = HttpGet(L"192.168.1.108", 8080, L"/hello/");
    cout << res.value << "  " << res.err << "\n";
    res = HttpPost(L"192.168.1.108", 8080, L"/hello/", data);
    cout << res.value << "  " << res.err << "\n";
}