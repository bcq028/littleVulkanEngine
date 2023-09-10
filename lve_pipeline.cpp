#include "lve_pipeline.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
namespace lve
{
    LvePipeline::LvePipeline(
        LveDevice &device,
        const std::string &vertFilePath,
        const std::string &fragFilePath,
        const PipelineConfigInfo &config_info):lve_device(device)
    {
        createGraphicsPipeline(vertFilePath, fragFilePath, {});
    }

    PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height)
    {
        return PipelineConfigInfo{};
    }

    std::vector<char> LvePipeline::readFile(const std::string &FilePath)
    {
        std::ifstream file{FilePath, std::ios::ate | std::ios::binary};
        if (!file.is_open())
        {
            throw std::runtime_error("failed to open file:" + FilePath);
        }
        size_t FileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(FileSize);
        file.seekg(0);
        file.read(buffer.data(), FileSize);
        file.close();
        return buffer;
    }

    void LvePipeline::createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath, const PipelineConfigInfo &config_info)
    {
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);
        std::cout << "vert code size is: " << vertCode.size() << std::endl;
        std::cout << "frag code size is: " << fragCode.size() << std::endl;
    }
    void LvePipeline::createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule)
    {
        VkShaderModuleCreateInfo createInfo {
            .sType=VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
            .codeSize=code.size(),
            .pCode=reinterpret_cast<const uint32_t*>(code.data())
        };

        if(!vkCreateShaderModule(lve_device.device(),&createInfo,nullptr,shaderModule)){
            throw std::runtime_error("failed to create shader module");
        }
    }
}