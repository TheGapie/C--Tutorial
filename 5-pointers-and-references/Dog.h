#ifndef _DOG_
#define _DOG_
#include<iostream>

class Dog{
    std::string name;
    public:
        explicit Dog(std::string dname);
        Dog() = default;
        ~Dog();
        void display(){
            std::cout<<"Dog :"<<this->name<<"\n";
        }
};

#endif