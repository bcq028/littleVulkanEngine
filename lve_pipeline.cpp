#include "lve_pipeline.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
namespace lve
{
    LvePipeline::LvePipeline(const std::string &vertFilePath, const std::string &fragFilePath)
    {
        createGraphicsPipeline(vertFilePath,fragFilePath);
    }

    std::vector<char> LvePipeline::readFile(const std::string &FilePath)
    {
        std::ifstream file{FilePath,std::ios::ate | std::ios::binary};
        if(!file.is_open()){
            throw std::runtime_error("failed to open file:"+FilePath);
        }
        size_t FileSize=static_cast<size_t>(file.tellg());
        std::vector<char> buffer(FileSize);
        file.seekg(0);
        file.read(buffer.data(),FileSize);
        file.close();
        return buffer;
    }

    void LvePipeline::createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath)
    {
        auto vertCode=readFile(vertFilePath);
        auto fragCode=readFile(fragFilePath);
        std::cout<<"vert code size is: " << vertCode.size()<<std::endl;
        std::cout<<"frag code size is: " << fragCode.size()<<std::endl;
    }
}