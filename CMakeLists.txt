CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

project (CPUDispatch)

add_subdirectory (cpu)
add_subdirectory (avx)
add_subdirectory (cpuinfo)

add_executable(test_bin main.cpp)
target_include_directories(test_bin PRIVATE "cpuinfo/include")
target_link_libraries (test_bin LINK_PUBLIC AVX CPU cpuinfo)
