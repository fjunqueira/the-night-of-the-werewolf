cmake_minimum_required(VERSION 3.3)
project(the_night_of_the_werewolf)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(SOURCE_FILES
    source/Animation.cpp
    source/Animation.h
    source/AssetManager.cpp
    source/AssetManager.h
    source/Cop.cpp
    source/Cop.h
    source/Game.cpp
    source/GameObject.cpp
    source/GameObject.h
    source/Image.cpp
    source/Image.h
    source/ImageLoader.cpp
    source/ImageLoader.h
    source/Layer.cpp
    source/Layer.h
    source/Player.cpp
    source/Player.h
    source/Vector2.cpp
    source/Vector2.h)

add_executable(the_night_of_the_werewolf ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

target_link_libraries( the_night_of_the_werewolf ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} )