file(GLOB_RECURSE Platform_Source_Files "src/*.cpp" "include/**/*.hpp")

target_sources(${PROJECT_NAME} PRIVATE ${Platform_Source_Files})

target_compile_definitions(${PROJECT_NAME} PUBLIC UNICODE _UNICODE)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )