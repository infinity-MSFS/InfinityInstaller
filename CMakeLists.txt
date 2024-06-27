cmake_minimum_required(VERSION 3.0)
project(InfinityInstaller)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vulkan REQUIRED)

file(GLOB_RECURSE SRC_FILES
    "src/*.c"
    "src/*.cpp"
    "src/*.h"
    "src/*.hpp"
    "dependencies/Walnut/*.c"
    "dependencies/Walnut/*.cpp"
    "dependencies/Walnut/*.h"
    "dependencies/glm/glm/*.c"
    "dependencies/glm/glm/*.cpp"
    "dependencies/glm/glm/*.h"
    "dependencies/glm/glm/*.hpp"
    "dependencies/stb_image/*.h"

)



set(IMGUI_SOURCES
        dependencies/imgui/imgui.cpp
        dependencies/imgui/imgui_draw.cpp
        dependencies/imgui/imgui_widgets.cpp
        dependencies/imgui/imgui_tables.cpp
        dependencies/imgui/misc/cpp/imgui_stdlib.cpp
        dependencies/imgui/backends/imgui_impl_glfw.cpp
        dependencies/imgui/backends/imgui_impl_vulkan.cpp
)



include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/imgui
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/Walnut/src/GUI
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/Walnut/src/
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/GLFW/include
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/spdlog/include
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/stb_image
        "C:/VulkanSDK/1.3.283.0/Include"
        ${IncludeDir.glm}
        ${IncludeDir.spdlog}
)

add_executable(InfinityInstaller ${SRC_FILES})

target_sources(InfinityInstaller PRIVATE ${IMGUI_SOURCES})

add_subdirectory(dependencies/GLFW)
add_subdirectory(dependencies/yaml-cpp)

add_library(GLFW INTERFACE)
target_include_directories(GLFW INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/GLFW/include)
target_link_libraries(GLFW INTERFACE glfw)

target_link_libraries(
    InfinityInstaller PRIVATE
    yaml-cpp
        glfw
        ${Vulkan_LIBRARIES}
)