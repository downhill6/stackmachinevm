cmake_minimum_required(VERSION 3.27)
project(StackMachineVM)

set(CMAKE_CXX_STANDARD 17)

add_executable(StackMachineVM main.cpp
        vm.cpp
        vm.h
        instr.h
)
