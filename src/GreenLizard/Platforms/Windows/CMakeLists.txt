file(GLOB_RECURSE Platform_Source_Files "*.cpp" "*.hpp")

target_sources(${PROJECT_NAME} PRIVATE ${Platform_Source_Files})

target_compile_definitions(${PROJECT_NAME} PUBLIC UNICODE _UNICODE)