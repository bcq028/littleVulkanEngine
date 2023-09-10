#include "lve_window.hpp"
#include <GLFW/glfw3.h>

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

LveWindow::~LveWindow(){
    glfwDestroyWindow(window);
    glfwTerminate();
}

} // namespace lve