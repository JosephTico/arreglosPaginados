cmake_minimum_required(VERSION 3.6)
project(tareaArreglosPaginados)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Sorting.cpp Sorting.h PagedArray.cpp PagedArray.h FileHandler.cpp FileHandler.h cmdline.h)
add_executable(tareaArreglosPaginados ${SOURCE_FILES})