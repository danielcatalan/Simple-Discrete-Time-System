cmake_minimum_required(VERSION 3.16)

project(SimpleDiscreteTimeSystem CXX)


add_library(sdts INTERFACE )
target_include_directories(sdts INTERFACE incl)


# Enable unit testing if this file is root
get_directory_property(hasParent PARENT_DIRECTORY)
if(hasParent STREQUAL "")
    enable_testing()
    add_subdirectory(tests)
endif()
