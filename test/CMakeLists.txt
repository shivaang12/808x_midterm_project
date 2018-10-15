set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    ../app/sdl_wrapper.cpp
    ../app/bfs.cpp
    ../app/obstacle_generator.cpp
    test_sdl.cpp
    test_bfs.cpp
    test_obstacle.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include
                                           ${SDL2_INCLUDE_DIRS})
target_link_libraries(cpp-test PUBLIC ${SDL2_LIBRARIES})
target_link_libraries(cpp-test PUBLIC gtest)
