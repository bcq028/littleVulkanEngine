#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>
namespace lve
{
    class LveWindow
    {
    public:
        LveWindow(const int width, const int height, const std::string window_name);
        LveWindow(const LveWindow &) = delete;
        LveWindow &operator=(const LveWindow &) = delete;
        bool shouldClose()
        {
            return glfwWindowShouldClose(window);
        }

        VkExtent2D getExtent()
        {
            return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};
        }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

        ~LveWindow();

    private:
        void initWindow();
        const int width;
        const int height;
        const std::string window_name;
        GLFWwindow *window;
    };
};