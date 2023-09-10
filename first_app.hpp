#pragma once
#include "lve_window.hpp"

namespace lve {
    class FirstApp {
        public:
        static constexpr int WIDTH=800;
        static constexpr int HEIGHT=800;
        void run();
        private:
        LveWindow lve_window {WIDTH,HEIGHT,"Hello vulkan!"};           
    };
}