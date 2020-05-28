#include <QCoreApplication>
#include "ResourceEx.h"
#include "Person.h"
void whenPtrDeleteFunc(ResourceEx *pRes); //forward decleration

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

        //unique_ptr
        {
            std::unique_ptr<ResourceEx> res {new ResourceEx()};
            std::unique_ptr<ResourceEx> res2 {}; //start as nullptr

            //custom delete function for std::unique_ptr. Use lambda expression always!
            auto whenPtrDelete = [](ResourceEx *pRes){
                std::cout<<"***Custom delete function for unique_ptr is called***\n";
                delete pRes;
            };
            {
                std::unique_ptr<ResourceEx,decltype(whenPtrDelete)> tUnique {new ResourceEx() ,whenPtrDelete};
                std::cout<<"size of unique ptr(lambda func)"<<sizeof (tUnique)<<std::endl;
            }
            {
                std::unique_ptr<ResourceEx,void (*)(ResourceEx*)> tUnique2 {new ResourceEx(),whenPtrDeleteFunc};
                std::cout<<"size of unique ptr(normal func)"<<sizeof (tUnique2)<<std::endl;
            }
            /*Because std::unique_ptr is designed with move semantics in mind,
         * copy initialization and copy assignment are disabled.
         * If you want to transfer the contents managed by std::unique_ptr,
         * you must use move semantics
         */
            std::cout << "res is " << (static_cast<bool>(res) ? "not null\n" : "null\n");
            std::cout << "res2 is " << (static_cast<bool>(res2) ? "not null\n" : "null\n");

            res2 = std::move(res);

            std::cout << "Ownership transferred\n";

            std::cout << "res is " << (static_cast<bool>(res) ? "not null\n" : "null\n");
            std::cout << "res2 is " << (static_cast<bool>(res2) ? "not null\n" : "null\n");
            res2->showInfo();

            std::unique_ptr<ResourceEx> f1{ std::make_unique<ResourceEx>() };
            f1->showInfo();


            auto f2 {std::make_unique<ResourceEx[]>(4)};
            f2[0].showInfo();

            std::unique_ptr<ResourceEx> r3{f1->createResource()};
            r3->showInfo();
            r3->takeOwnership(std::move(f1));
            r3->usePtr(res2.get());

        }

        //shared_ptr
        {

            ResourceEx *tRawPtr = new ResourceEx;
            std::shared_ptr<ResourceEx> tSharedPtr1(tRawPtr);
            {
                std::shared_ptr<ResourceEx> tSharedPtr2(tSharedPtr1);
                std::cout<<"Deleting shared memory...\n";
            }
            std::cout<<"Deleting other shared memory...\n";

            auto tPtr3 = std::make_shared<ResourceEx>();
            tPtr3->showInfo();
            {
                auto tPtr4 = tPtr3; // copy operator
                std::cout<<"Deleting shared memory...\n";
            }
            std::cout<<"Deleting other shared memory...\n";

        }

    //weak_ptr
    {
        auto tRick = std::make_shared<Person>("Rick");
        auto tMorty = std::make_shared<Person>("Morty");
        partnerUp(tRick,tMorty);
        auto partner = tRick->getPartner();
        std::cout<<tRick->getName()<<partner->getName()<<std::endl;
    }
    Person p;

    return a.exec();
}


void whenPtrDeleteFunc(ResourceEx *pRes){
    std::cout<<"***Custom delete function witout lambda for unique_ptr is called***\n";
    delete pRes;
}
