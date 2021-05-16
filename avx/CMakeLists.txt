add_library (AVX impl.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx2")