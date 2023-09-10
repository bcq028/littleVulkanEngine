#include "lve_window.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace lve {
LveWindow::LveWindow(const int width, const int height,
                     const std::string window_name):width(width),height(height),window_name(window_name) {
                        initWindow();
                     }
void LveWindow::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window=glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);
}

void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface)
{
    if(glfwCreateWindowSurface(instance,window,nullptr,surface)!=VK_SUCCESS){
        throw std::runtime_error("failed to create window surface");
    }
}

LveWindow::~LveWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

} // namespace lve