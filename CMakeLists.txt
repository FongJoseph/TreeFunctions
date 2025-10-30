cmake_minimum_required(VERSION 3.28)
project(TreeFunctions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Main program ----
add_executable(tree
    main.cpp
    tree.cpp
)
target_include_directories(tree PRIVATE .)

# ---- Unit tests ----
enable_testing()

find_package(GTest QUIET)

if (GTest_FOUND)
    message(STATUS "Using system-installed GTest")
else()
    include(FetchContent)
    FetchContent_Declare(
        googletest
        # GIT_REPOSITORY https://github.com/google/googletest.git
        # GIT_TAG v1.14.0
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

add_executable(test_tree
    test.cpp
    tree.cpp
)
target_include_directories(test_tree PRIVATE .)
target_link_libraries(test_tree GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_tree)
