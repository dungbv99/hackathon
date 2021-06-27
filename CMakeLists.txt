cmake_minimum_required(VERSION 3.19)
project(hackathon)

set(WIN32  14)

#add_executable(hackathon WIN32 main.cpp MyCreateBox/MyCreateBox.cpp MyCreateBox/MyCreateBox.h HandleButton/HandleButton.cpp HandleButton/HandleButton.h FrontEnd/Login.cpp FrontEnd/Login.h HttpLib/HttpLib.cpp HttpLib/HttpLib.h)
add_executable(hackathon WIN32 test.cpp HttpLib/HttpLib.cpp HttpLib/HttpLib.h)