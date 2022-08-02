project(GreenLizard.Tests VERSION 0.0.0)

add_executable(${PROJECT_NAME} "")

add_subdirectory(Platforms)

file(GLOB_RECURSE Tests_Files "test_*.cpp")

target_sources(${PROJECT_NAME}
    PRIVATE
        ${Tests_Files}
)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        GTest::gtest GTest::gtest_main
        GreenLizard
)
