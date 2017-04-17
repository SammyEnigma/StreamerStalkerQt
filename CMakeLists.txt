cmake_minimum_required(VERSION 3.7)
project(StreamStalkerQt)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5Core)
find_package(Qt5Quick)

FILE(GLOB_RECURSE SOURCES "src/*.cc")
FILE(GLOB_RECURSE HEADERS "src/*.hh")
FILE(GLOB_RECURSE QRC     "res/*.qrc")
FILE(GLOB_RECURSE RES     "res/*.*")


add_executable(stalker ${SOURCES} ${HEADERS} ${QRC} ${RES})

target_link_libraries(stalker Qt5::Core Qt5::Quick)
