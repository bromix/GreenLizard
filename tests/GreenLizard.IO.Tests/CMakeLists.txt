project(GreenLizard.IO.Tests VERSION 0.0.0)

add_executable(${PROJECT_NAME} "")

file(GLOB_RECURSE Source_Files "**/test_*.cpp")

target_sources(${PROJECT_NAME}
        PRIVATE
        ${Source_Files}
        )

find_package(GTest CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        GTest::gtest GTest::gtest_main
        GreenLizard.IO
        )
