cmake_minimum_required(VERSION 3.7)
project(exam-benchmark)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (BENCHMARK_ENABLE_TESTING OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/../3rdparty/benchmark
                 ${CMAKE_SOURCE_DIR}/../3rdparty/benchmark/build)


add_executable(exam-benchmark benchmark.cpp)

target_link_libraries(exam-benchmark benchmark)