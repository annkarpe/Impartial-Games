cmake_minimum_required(VERSION 3.14)
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
test/test_impartial_game.cc src/impartial_game.cc
test/test_chomp.cc src/chomp.cc
test/test_nim.cc src/nim.cc
src/player.cc src/user_input_handler.cc src/ui.cc
)

target_link_libraries(${PROJECT_NAME} gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

include_directories(lib)