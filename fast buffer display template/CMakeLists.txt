cmake_minimum_required(VERSION 3.15)
project(fft)

set(CMAKE_CXX_STANDARD 14)

file (GLOB SOURCES *.cpp)
add_executable(fft ${SOURCES})

set(SDL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL")
target_link_libraries(fft -L${SDL_DIR})
target_link_libraries(fft SDL2.lib SDL2main.lib SDL2.dll SDL2test.lib)