cmake_minimum_required(VERSION 3.7...3.20)

if( ${CMAKE_VERSION} VERSION_LESS 3.20)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(TextEditor LANGUAGES CXX)

add_library(reslib STATIC ../src/resource.cpp ../include/resource.hpp)
add_library(namlib STATIC ../src/namespace.cpp ../include/namespace.hpp)

target_include_directories(reslib PUBLIC include)
target_include_directories(namlib PUBLIC include)
target_compile_features(reslib PUBLIC cxx_std_17)
target_compile_features(namlib PUBLIC cxx_std_17)

add_executable(app ../index.cpp)
target_link_libraries(app PUBLIC reslib namlib ncurses stdc++fs)
