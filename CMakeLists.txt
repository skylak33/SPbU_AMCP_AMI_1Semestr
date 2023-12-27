cmake_minimum_required(VERSION 3.26)
project(zachet)
set(CMAKE_CXX_STANDARD 14)

add_executable(zachet
        7.cpp)

find_package(ICU REQUIRED COMPONENTS uc io)
target_link_libraries(zachet PRIVATE ICU::uc ICU::io)