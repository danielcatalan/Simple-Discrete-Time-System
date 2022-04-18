cmake_minimum_required(VERSION 3.16)


project(SimpleDiscreteTimeSystem CXX)



add_library(sdts INTERFACE 
    incl/sdts/Filter.hpp
    incl/sdts/InputSignal.hpp
    incl/sdts/OutputSignal.hpp)
target_include_directories(sdts INTERFACE incl)

enable_testing()
add_subdirectory(tests)