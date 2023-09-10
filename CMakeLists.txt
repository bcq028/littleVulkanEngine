cmake_minimum_required(VERSION 3.12)

project(VulkanTest)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the required packages
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

# Add the source files
add_executable(VulkanTest main.cpp lve_window.cpp first_app.cpp lve_pipeline.cpp)
link_directories(${CMAKE_SOURCE_DIR})

# Link the necessary libraries
target_link_libraries(VulkanTest PRIVATE
    Vulkan::Vulkan
    glfw
    dl
    pthread
    X11
    Xxf86vm
    Xrandr
    Xi
)

# Set the optimization level
target_compile_options(VulkanTest PRIVATE -O2)
