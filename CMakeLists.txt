cmake_minimum_required(VERSION 3.20)

project(NavigationScreenGame VERSION 1.0 LANGUAGES CXX)


add_library(NavigationPage STATIC
    Navigator.cpp
    Screen.cpp
)
target_include_directories(NavigationPage
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
) 