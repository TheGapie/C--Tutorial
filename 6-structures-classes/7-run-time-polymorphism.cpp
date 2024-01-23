/*
Method Overriding :
    - Method Overriding is a concept where derived class defines a specified implimentation 
       for a method that has already been defined in the Base class.
    - This allows objects of the derived class to exhibit behaviour that is tailored to their own type.
    - Method Overriding is used for achieving runtime polymorphism
    - Method overriding uses virtual function at the Base class

Virtual Function -
    - Virtual Function are special classes that is declared in Base class and is redifined in the Derived class
    - It indicates that this function will be overridden in the next deriving classes
    - Virtual functions are inherited that means when a class is inheriting the Base class for that class this 
       function also defined as virtual for that Class so that when another class will derive the deriving class 
       that method will work as virtual method for that class

Pure Virtual Function -
    - Pure Virtual function doesn't have any function body.
    - If one class has a Pure Virtual Function it is called Abstract class.
    - If any one is deriving an abstract class. it must need to define the virtual function
    - We cannot create Objects of abstract class
    - If we do not define virtual function in the deriving class, It also becomes an abstract class.
    
    # Syntax
        virtual retType funcName() = 0;

Virtual Destructor
    - When virtual functions are used and objects of deriving classes are created through the references and pointers of Base class,
       It is important that proper cleanup of resources is present. That's why virtual destructor is needed.
    - When a derived class object is deleted through a pointer to the base class and that base class has a virtual destructor
       It enables the correct destructor of the most derived class to be called.
*/

#include<iostream>
using namespace std;

class Shape{
    public:
        virtual double area(){
            return 0;
        }
};

class Circle : public Shape{
    int radius;
    public:
        Circle(int radius) : radius(radius) {}

        double area(){
            return 3.14*radius*radius;
        }
};

class Rectangle : public Shape{
    int x,y;
    public:
        Rectangle(int x,int y) : x(x),y(y){}

        double area(){
            return x*y;
        }
};

int main(){
    Shape* s;
    Circle c(4);
    Rectangle r(4,5);
    s = &r;
    cout<<s->area()<<endl;
    s = &c;
    cout<<s->area()<<endl;
    return 0;
}