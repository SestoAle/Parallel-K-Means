cmake_minimum_required(VERSION 3.8)
project(K_Means_Mio_Cpp)


set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")
# try also to compile and execute without: -fopenmp
set(CMAKE_CXX_FLAGS "-I/usr/local/opt/llvm/include -fopenmp")
link_directories("/usr/local/opt/llvm/lib")

set(SOURCE_FILES main_sequential.cpp Point.h Cluster.h main_parallel.cpp)
add_executable(main main_sequential.cpp Point.h Cluster.h)

add_executable(main_parallel main_parallel.cpp Point.h Cluster.h)
