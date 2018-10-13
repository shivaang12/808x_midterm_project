add_executable(shell-app main.cpp sdl_wrapper.cpp bfs.cpp obstacle_generator.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
)
target_link_libraries(shell-app ${SDL2_LIBRARIES})
