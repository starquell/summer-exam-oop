cmake_minimum_required(VERSION 3.7)
project(exam-tests)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/../3rdparty/doctest)
add_executable(exam-tests tests.cpp)
target_link_libraries(exam-tests pthread)

add_test(NAME AllTests COMMAND tests)

