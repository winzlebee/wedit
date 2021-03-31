cmake_minimum_required(VERSION 3.5)

project(editor)

find_package(PkgConfig)

# Include gtkmm, the windowing library that we are going to use
pkg_check_modules(GTKMM gtkmm-3.0)

set(SOURCE_FILES src/main.cpp)

add_executable(editor ${SOURCE_FILES})

target_include_directories(editor PUBLIC ${GTKMM_INCLUDE_DIRS})
target_link_libraries(editor PUBLIC ${GTKMM_LIBRARIES})