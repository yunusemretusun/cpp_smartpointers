#ifndef RESOURCEEX_H
#define RESOURCEEX_H

#include <iostream>
#include <memory>
class ResourceEx
{
public:
    ResourceEx();
    ~ResourceEx();
    void showInfo();
    std::unique_ptr<ResourceEx> createResource();
    void takeOwnership(std::unique_ptr<ResourceEx> pRes);
    void usePtr(const ResourceEx *pRes);
};

#endif // RESOURCEEX_H
