project(GreenLizard.IO VERSION 0.0.0)

add_library(${PROJECT_NAME} STATIC "")

file(GLOB_RECURSE Source_Files
    "src/*.cpp"
    "include/GreenLizard/**/*.hpp"
)

if(WIN32)
    file(GLOB_RECURSE Platform_Source_Files
        "Platforms/Windows/**/*.cpp" "Platforms/Windows/**/*.hpp"
    )

    target_include_directories(${PROJECT_NAME}
        PRIVATE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Platforms/Windows>
            $<INSTALL_INTERFACE:Platforms/Windows/>
    )
endif()

target_sources(${PROJECT_NAME}
    PRIVATE
        ${Source_Files}
        ${Platform_Source_Files}
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