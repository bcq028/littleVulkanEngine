#pragma once
#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"
namespace lve
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 800;
        void run();

    private:
        LveWindow lve_window{WIDTH, HEIGHT, "Hello vulkan!"};
        LveDevice lve_device {lve_window};
        LvePipeline lve_pipeline{lve_device, "../shaders/simple_shader.vert.spv", "../shaders/simple_shader.frag.spv",LvePipeline::defaultPipelineConfigInfo(WIDTH,HEIGHT)};
    };
}