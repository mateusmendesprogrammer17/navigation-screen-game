cmake_minimum_required(VERSION 3.20)

project(NavigationScreenGame VERSION 1.0 LANGUAGES CXX)

add_library(NavigationPage STATIC
    Navigator.cpp
    Screen.cpp
)

target_include_directories(NavigationPage
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(
    TARGETS NavigationPage
    EXPORT NavigationPageTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    FILES
        Navigator.h
        Screen.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT NavigationPageTargets
    FILE NavigationPageTargets.cmake
    NAMESPACE NavigationPage::
    DESTINATION cmake
)

configure_package_config_file(
    cmake/NavigationPageConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/NavigationPageConfig.cmake
    INSTALL_DESTINATION cmake
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/NavigationPageConfig.cmake
    DESTINATION cmake
)