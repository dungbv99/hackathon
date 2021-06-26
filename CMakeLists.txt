cmake_minimum_required(VERSION 3.19)
project(hackathon)

set(WIN32  14)

add_executable(hackathon WIN32 main.cpp MyCreateBox/MyCreateBox.cpp MyCreateBox/MyCreateBox.h HandleButton/HandleButton.cpp HandleButton/HandleButton.h)