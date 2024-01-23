/*
Inheritance :
    - Inhertance is one of the main cornerstones of OOPs.
    - It specifies the hierarchical relation between classes in C++
    - C++ supports all types of Inheritance
        - Hierarchical Inheritance
        - Multi-Level Inheritance
        - Multiple Inheritance
        - Hybrid Inheritance
    
    - Access Modifiers
                How acccess
                right changes   Publicly Derived        Protectedly Derived         Privately Derived
    
    Base Class  
    Access 
    Protection

    Public Members              Remain Public           Become Protected            Become Private

    Protected Members           Remain Protected        Remain Protected            Become Private

    Private Members             Not Accessible          Not Accessible              Not Accessible

    # Syntax
        class DerivedClass : access-specifier BaseClass1, access-specifier BaseClass2, .... {
            DerivedClass(x,y,z,...) : BaseClass1(x,..) , BaseClass2(y,..), ... {}
        };
    
    - '::' operator can public the private members of base class in derived class

*/

// DIAMOND PROBLEM

#include<iostream>
using namespace std;

class Base{
    public:
        void print(){
            cout<<"Base Class\n";
        }
};

/*
Ambiguous code : 
    - as there both Deriving classes are inheriting same class and 
       from Derived3 it is ambiguous to say from which direction Base class will be invoked
class Derived1 : public Base{};
class Derived2 : public Base{};
*/

//Now virtual will indicate that Base class will be invoked only once 
class Derived1 : virtual public Base{};
class Derived2 : virtual public Base{};

class Derived3 : public Derived1, public Derived2{};

int main(){
    Derived3 d;
    d.print();
    return 0;
}


/*
Virtual Base Class :
    - A virtual base class is a class that is intended to be used as a base class 
      when multiple classes are deriving from it and it is designed to prevernt the 
      inheritance ob duplicate base class instances in a class hierarchy
*/