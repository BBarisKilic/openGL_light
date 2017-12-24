cmake_minimum_required(VERSION 3.9)
project(Light)

set(CMAKE_CXX_STANDARD 11)

add_executable(Light
        cube.cpp)


target_link_libraries(${PROJECT_NAME} /usr/lib/x86_64-linux-gnu/libGL.so
        /usr/lib/x86_64-linux-gnu/libGLU.so /usr/lib/x86_64-linux-gnu/libSDL-1.2.so.0)