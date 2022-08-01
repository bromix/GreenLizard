project(GreenLizard VERSION 0.0.0)

add_library(${PROJECT_NAME} STATIC "")

file(GLOB_RECURSE Source_Files
        "src/*.cpp" "src/*.hpp"
        "include/GreenLizard/*.hpp")

add_subdirectory(Platforms)

target_compile_features(${PROJECT_NAME}
        PUBLIC
        cxx_std_17
        )

target_sources(${PROJECT_NAME}
        PRIVATE
        ${Source_Files}
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )