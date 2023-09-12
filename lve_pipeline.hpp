#pragma once

#include "lve_device.hpp"

#include <string>
#include <vector>
namespace lve
{
    struct PipelineConfigInfo
    {
        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineViewportStateCreateInfo viewportInfo;
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        VkPipelineLayout pipelineLayout=nullptr;
        VkRenderPass renderPass=nullptr;
        uint32_t subpass=0;
    };

    class LvePipeline
    {
    public:
        LvePipeline(
            LveDevice &device,
            const std::string &vertFilePath, 
            const std::string &fragFilePath,
            const PipelineConfigInfo &config_info
        );
        ~LvePipeline(){}
        LvePipeline(const LvePipeline&)=delete;
        void operator=(const LvePipeline&)=delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width,uint32_t height);

    private:
        static std::vector<char> readFile(const std::string &FilePath);
        void createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath,const PipelineConfigInfo &config_info);
        void createShaderModule(const std::vector<char> &code,VkShaderModule *shaderModule);
        LveDevice &lve_device;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
}