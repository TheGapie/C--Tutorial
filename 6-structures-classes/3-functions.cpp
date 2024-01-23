/*
Friend Function :
    - Friend functions of a class are a special kind of function that have access to all private and protected members of the class
    - Use Cases
        - Accessing Private Members
        - Operator Overloading
        - Allowing external function access

Inline Functions:
    - Inline functions are special functions works similar to MACROs.
    - That means it only replaces the function call with function body
    - Like register specifier, inline is just a request to compiler, not a command.
    - Compiler can choose to ignore it
    - All function defined inside of class are by default inline function 

*/

#include<iostream>
using namespace std;

class Shape{
    int x,y;
    public:

    // Shape() = default;
    Shape(int x = 0,int y = 0) : x(x),y(y) {}
    
    // Getter
    int getX(){
        return this->x;
    }

    int getY(){
        return this->y;
    } 

    // Setter
    void setX(int x){   // these are also inline function
        this->x = x;
    }

    void setY(int y){
        this->y = y;
    }

    void printCoords(){
        cout<<"x :"<<x<<", y :"<<y<<endl;
    }

    friend void sum(Shape& obj1,Shape& obj2);
};

void sum(Shape& obj1,Shape& obj2){
    int x = obj1.x + obj2.x;
    int y = obj1.y + obj2.y;
    cout<<"x :"<<x<<", y :"<<y<<endl;
}

inline int max(int x,int y){
    return x>y? x:y;
}

int main(){
    Shape s1(4,5),s2(6,7);
    sum(s1,s2);

    cout<<max(5,6)<<endl;
    return 0;
}

