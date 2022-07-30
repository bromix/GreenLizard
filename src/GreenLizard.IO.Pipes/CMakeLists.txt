project(GreenLizard.IO.Pipes VERSION 0.0.0)

add_library(${PROJECT_NAME} STATIC "")

file(GLOB_RECURSE Source_Files "src/*.cpp")
file(GLOB_RECURSE Include_Files "include/GreenLizard/Win32/*.hpp")

target_sources(${PROJECT_NAME}
    PRIVATE
        ${Source_Files}
        ${Include_Files}
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