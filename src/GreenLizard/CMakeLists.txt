project(GreenLizard VERSION 0.0.0)

add_library(${PROJECT_NAME} STATIC "")

file(GLOB_RECURSE Source_Files
        "src/*.cpp" "src/*.hpp"
        "include/GreenLizard/*.hpp")

if (WIN32)
    file(GLOB_RECURSE Platform_Source_Files
            "Platforms/Windows/*.cpp" "Platforms/Windows/*.hpp"
            )
endif ()

target_compile_features(${PROJECT_NAME}
        PUBLIC
        cxx_std_17
        )

target_sources(${PROJECT_NAME}
        PRIVATE
        ${Source_Files}
        ${Platform_Source_Files}
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )