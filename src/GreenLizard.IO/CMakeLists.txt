project(GreenLizard.IO VERSION 0.0.0)

add_library(${PROJECT_NAME} STATIC "")

file(GLOB_RECURSE Source_Files
    "src/*.cpp"
    "include/GreenLizard/**/*.hpp"
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${Source_Files}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        GreenLizard
)


target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)