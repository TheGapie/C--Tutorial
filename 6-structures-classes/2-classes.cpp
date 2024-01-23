/*
this : 
    - When a member function is called, it is automatically passed as an implicit arguement 
       that is a pointer to the invoking arguement. This pointer is called 'this' pointer
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
    void setX(int x){
        this->x = x;
    }

    void setY(int y){
        this->y = y;
    }

    void printCoords(){
        cout<<"x :"<<x<<", y :"<<y<<endl;
    }
};

int main(){
    Shape s1;
    Shape s2(3,4);
    Shape s3(5);
    s1.printCoords();
    s2.printCoords();
    s3.printCoords();

    return 0;
}
