#include "ResourceEx.h"

ResourceEx::ResourceEx()
{
   std::cout<<"Resource acquired\n";
}

ResourceEx::~ResourceEx()
{
    std::cout<<"Resource destroyed\n";
}

void ResourceEx::showInfo()
{
    std::cout<<"Info message\n";
}

std::unique_ptr<ResourceEx> ResourceEx::createResource()
{

    std::cout<<"Info message for creating resource\n";
    return std::make_unique<ResourceEx>();
}

void ResourceEx::takeOwnership(std::unique_ptr<ResourceEx> pRes)
{
    if(pRes)
        std::cout<<"Taking ownership pointer\n";
}

void ResourceEx::usePtr(const ResourceEx *pRes)
{
    if(pRes)
        std::cout<<"Taking ownership pointer without deleting...\n";
}
