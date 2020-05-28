#include "Person.h"	
#include <string>
#include <vector>

struct Person::mImplemantationStr{
    std::string mName;
    std::vector<double> mData;
};



Person::Person()
    :mStrPtr(std::make_unique<mImplemantationStr>())
{

}

Person::Person(const std::string &pName)
    :mName(std::move(pName))
    ,mStrPtr(std::make_unique<mImplemantationStr>())
{
    std::cout<<" Person created : "<< mName << std::endl;
}

Person::Person(const Person &rhs)
    :mStrPtr(std::make_unique<mImplemantationStr>(*rhs.mStrPtr))
{}

Person &Person::operator=(const Person &rhs)
{
    *mStrPtr = *rhs.mStrPtr;
    return *this;
}

Person::Person(Person &&rhs) = default;

Person &Person::operator=(Person &&rhs)=default;

Person::~Person() = default;

//Person::~Person()
//{
//    std::cout<<" Person destroyed :"<< mName << std::endl;
//}

const std::shared_ptr<Person> Person::getPartner() const
{
    return mPartner.lock();
}

const std::string &Person::getName() const
{
    return mName;
}
