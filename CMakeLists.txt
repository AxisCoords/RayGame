cmake_minimum_required(VERSION 3.10)
project(game)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/includes)
link_directories(${CMAKE_SOURCE_DIR}/libs)

file(GLOB SOURCES
    "${CMAKE_SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Linux
target_link_libraries(${PROJECT_NAME}
    raylib
    m
    pthread
    dl
    rt
    X11
)

# Windows
# target_link_libraries(${PROJECT_NAME}
#     raylib
#     winmm
#     gdi32
#     opengl32
# )
