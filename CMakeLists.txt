cmake_minimum_required(VERSION 3.0)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess CommandLineApplication.cpp Player.cpp Player.h Move.h)
