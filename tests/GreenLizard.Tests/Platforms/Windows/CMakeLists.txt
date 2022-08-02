file(GLOB_RECURSE Tests_Files "test_*.cpp")

target_sources(${PROJECT_NAME}
        PRIVATE
        ${Tests_Files}
        )