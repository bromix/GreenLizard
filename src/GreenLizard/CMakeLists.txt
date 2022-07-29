project(GreenLizard VERSION 0.0.0)

add_library(${PROJECT_NAME} STATIC "")

file(GLOB_RECURSE GreenLizard_Source_Files "src/*.cpp")
file(GLOB_RECURSE GreenLizard_Include_Files "include/GreenLizard/*.hpp")

target_compile_features(${PROJECT_NAME}
    PUBLIC
        cxx_std_17
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${GreenLizard_Source_Files}
        ${GreenLizard_Include_Files}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)