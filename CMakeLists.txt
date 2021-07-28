cmake_minimum_required(VERSION 3.7)
project(ft_containers)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 98)

include_directories(.)

add_executable(contain_test
        main.cpp map.hpp lexicographical_compare.hpp stack.hpp)
