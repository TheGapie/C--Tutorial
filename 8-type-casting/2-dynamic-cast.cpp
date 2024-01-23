/*
dynamic_cast:
    - dynamic_cast is a type casting used in C++ specially for polymorphism.
    - It safely converts pointers and references of a base class to its derived class and
       checks the validity of the conversion during runtime
    - If the converion is invalid it return a NULL pointer instead of undefined behaviour
*/

#include<iostream>
using namespace std;
class Base{
    public:
        virtual void print(){
            std::cout<<"Printing from Base\n";
        }
};

class Derived:public Base{
    public:
        void print(){
            std::cout<<"Printing from Derived\n";
        }
};

int main(){
    Base *b = new Derived();

    b->print();

    Derived* d = dynamic_cast<Derived*>(b);
    d->print();
    
    delete b;
    return 0;
}