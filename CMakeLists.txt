cmake_minimum_required(VERSION 3.6)
project(Cpp_Primer_Practice)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ch1.cpp Sales_item.h Sales_item.cpp Sales_item.cpp Sales_item.h ch2.cpp ch3.cpp ch4.cpp)
add_executable(Cpp_Primer_Practice ${SOURCE_FILES})