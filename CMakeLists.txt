cmake_minimum_required(VERSION 3.7)
project(summer-exam-oop)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SRC_DIR          ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR      ${CMAKE_SOURCE_DIR}/include)
set(TESTS_DIR        ${CMAKE_SOURCE_DIR}/tests)
set(GUI_DIR          ${CMAKE_SOURCE_DIR}/gui)
set(THIRD_PARTY_DIR  ${CMAKE_SOURCE_DIR}/3rdparty)


option(BUILD_TESTS ON)
option(BUILD_BENCHMARK ON)
option(BUILD_GUI ON)

include_directories(${THIRD_PARTY_DIR})

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(${TESTS_DIR})
endif()

if (BUILD_BENCHMARK)
    add_subdirectory(${BENCHMARK_DIR})
endif()

if (BUILD_GUI)
    add_subdirectory(${GUI_DIR})
endif()

add_executable(main main.cpp)