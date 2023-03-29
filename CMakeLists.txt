cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 17)

project(imp LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        bf66935e07825318ae519675d73d0f3e313b3ec6 
)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} 
src/play.cc src/game.cc src/game_factory.cc src/user_input_handler.cc
test/test_game.cc test/test_play.cc test/test_game_factory.cc
)

target_link_libraries(${PROJECT_NAME} gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

include_directories(lib)
