cmake_minimum_required(VERSION 3.16)


project(SimpleDiscreteTimeSystem CXX)

find_package(GTest CONFIG REQUIRED)


add_library(sdts INTERFACE 
    incl/sdts/Filter.hpp
    incl/sdts/InputSignal.hpp
    incl/sdts/OutputSignal.hpp)
target_include_directories(sdts INTERFACE incl)

add_subdirectory(tests)