cmake_minimum_required(VERSION 3.5)

set(OpenGL_GL_PREFERENCE GLVND)

project(editor)

find_package(PkgConfig)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# Include gtkmm, the windowing library that we are going to use
pkg_check_modules(GTKMM gtkmm-3.0)

set(SOURCE_FILES
  src/main.cpp
  src/main_window.cpp
  src/viewport.cpp
)

add_executable(editor ${SOURCE_FILES})

target_include_directories(editor
  PUBLIC ${GTKMM_INCLUDE_DIRS})

target_link_libraries(editor
  PUBLIC
    ${GTKMM_LIBRARIES}
    GLEW::glew
    OpenGL::GL
    )

install(TARGETS editor DESTINATION ${CMAKE_INSTALL_BIN_DIR})
