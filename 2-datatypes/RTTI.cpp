/*
//// RTTI : Run Time Type Indication

typeid : 
    - typeid is an operator that returns a reference to an object of 
       type std::type_info, which contains information about the type of the object.

    - const std::type_info typePtr = typeid(*basePtr);

dynamic_cast : 
    - dynamic_cast is a typecasting operator that performs a runtime typecheck and 
       safely downcasts a base pointer to a derived pointer or reference
    - It returns null or throws a bad_cast exception when casting fails.
*/

#include<iostream>
#include<typeinfo>
class Base{
    public:
        virtual ~Base(){}
};

class Derived : public Base {};

int main(){
    Base* bptr = new Derived;
    using namespace std;
    cout<<"Type :"<<typeid(*bptr).name()<<"\n";

    Derived* dptr = dynamic_cast<Derived*>(bptr);
    if(dptr)
        cout<<"Downcast to Derived\n";
    else
        cout<<"Downcast failed\n";
    return 0;
}