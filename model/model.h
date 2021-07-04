//
// Created by ADMIN on 04/07/2021.
//
#define NOMINMAX 1
#include "Windows.h"
#include "string"
using namespace std;


#include "json_struct.h"
using namespace JS;
#ifndef HACKATHON_MODEL_H
#define HACKATHON_MODEL_H

struct User{
    string userName;
    string passWd;

    JS_OBJ(userName, passWd);
    LPSTR getStringJson();
    void getStringJsonValue(string data);
};


#endif //HACKATHON_MODEL_H
