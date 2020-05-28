#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <memory> // for std::shared_ptr
#include <string>
class Person
{
public:
    Person();
    Person(const std::string &pName);
    Person(Person&& rhs) ;//move ctor
    Person& operator=(Person&& rhs); //move operator
    Person(const Person& rhs); //copy ctor
    Person& operator=(const Person& rhs); //copy operator

    ~Person();




    friend bool partnerUp(std::shared_ptr<Person> &pPerson1,std::shared_ptr<Person> &pPerson2){
     if(!pPerson1 || !pPerson2)
         return false;
     pPerson1->mPartner =pPerson2;
     pPerson2->mPartner =pPerson1;

     std::cout << pPerson1->mName << " is now partnered with " << pPerson2->mName << "\n";
     return true;
    }

    const std::shared_ptr<Person> getPartner() const;
    const std::string& getName() const;
private:
    std::string mName;
    std::weak_ptr<Person> mPartner;
    struct mImplemantationStr;
    std::unique_ptr<mImplemantationStr> mStrPtr;

};

#endif // PERSON_H
