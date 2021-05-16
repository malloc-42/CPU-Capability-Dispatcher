add_library (AVX impl.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx2")

target_link_libraries(AVX array)
