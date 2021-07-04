#define NOMINMAX 1
#include "windows.h"
#include "iostream"
#include "winhttp.h"
using namespace std;
#pragma comment(lib, "winhttp.lib")
#include "HttpLib/HttpLib.h"
#include "json_struct.h"

using namespace JS;
struct test{
    std::string key;
    int number;
    bool boolean;

    JS_OBJ(key, number, boolean);
};
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow){

    string a = "{\"key\" : \"value\", \"number\" : 100, \"boolean\" : true}";
    test b;
    ParseContext context(a);
    context.parseTo(b);
    cout << "key" << b.key << "number " << b.number << "boolean " << b.boolean;



}