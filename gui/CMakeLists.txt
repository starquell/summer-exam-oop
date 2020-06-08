cmake_minimum_required(VERSION 3.7)

project(exam-gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# sources for qt includes also .ui and .qrc files
set(SRC_LIST
        main.cpp
        mainwindow.hpp mainwindow.cpp)

add_executable(exam-gui ${SRC_LIST})

target_link_libraries(exam-gui Qt5::Widgets)