cmake_minimum_required(VERSION 3.29)
project(Strings)

set(CMAKE_CXX_STANDARD 14)

add_executable(Strings
        String/MyStringv1.cpp
        main.cpp
        String/MyString.cpp)
