project(GreenLizard.Tests VERSION 0.0.0)

add_executable(${PROJECT_NAME} "")

file(GLOB_RECURSE GreenLizard_Tests_Files "test_*.cpp")

target_sources(${PROJECT_NAME}
    PRIVATE
        ${GreenLizard_Tests_Files}
)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(main PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)