cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(smart_pointers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_library(person_resources
            STATIC
            src/Person.h
            src/Person.cpp
            src/ResourceEx.h
            src/ResourceEx.cpp
)   

add_executable(smart_ptrs main.cpp)
target_link_libraries(smart_ptrs person_resources)
   


