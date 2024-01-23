/*
structure : 
    - Structures are user defined data structures that is used for defining complex data structures
    - The main difference between classes and structures is that structure members are by default public, 
       while classe members are private by default 
    - Structures and classes have remaining similar characteristics
    - Structures can define Constructors, Destructors, Inheritance, member Functions etc.
*/

#include<iostream>
using namespace std;

struct Shape{
    int x,y;
    
    Shape(int x,int y) : x(x),y(y) {}

    void printCoords(){
        cout<<"x :"<<x<<", y :"<<y<<endl;
    }
};

struct Rectangle : public Shape{
    Rectangle(int x,int y) : Shape(x,y) {}

    void printCoords(){
        cout<<"Rectangle x :"<<x<<", y :"<<y<<endl;
    }
};

int main(){
    Rectangle* r = new Rectangle(4,5);
    r->printCoords();
    return 0;
}