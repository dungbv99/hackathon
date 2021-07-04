//
// Created by ADMIN on 04/07/2021.
//
#define NOMINMAX 1

#include <Windows.h>
#include "model.h"
#include "string"
#include "iostream"
#include "json_struct.h"
using namespace JS;
using namespace std;


LPSTR User::getStringJson() {

//    LPSTR value = "{ \"userName\" : " + "\"" +userName +"\"" + ",\"passWd\" : " + "\"" + passWd + "\" }" ;
    string result = "{ \"userName\" : \"";
    result.append(userName);
    result.append("\"passWd\" :  \"");
    result.append("\"}");

    return const_cast<char *>(result.c_str());
}

void User::getStringJsonValue(string data) {
    User userStruct;
    ParseContext parseContext(data);
    if (parseContext.parseTo(userStruct) != Error::NoError){
        string errorStr = parseContext.makeErrorString();
        cout << errorStr << "\n";
        return;
    }
    userName = userStruct.userName;
    passWd = userStruct.passWd;
}