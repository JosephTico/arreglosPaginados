cmake_minimum_required(VERSION 3.6)
project(tareaArreglosPaginados)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp QuickSort.cpp QuickSort.h PagedArray.cpp PagedArray.h FileHandler.cpp FileHandler.h)
add_executable(tareaArreglosPaginados ${SOURCE_FILES})