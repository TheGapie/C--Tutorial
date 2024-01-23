/*
Friend Class: 
    - Friend class can access all the private and protected members of the class where it is defined.
    - But vice versa is not True.
*/

#include<iostream>
using namespace std;

/// Friend Class
class TwoValues{
    int x,y;
    public:
        TwoValues(int x,int y):x(x),y(y){}
        friend class Min;
};

class Min{
    public:
        int min(TwoValues& obj){
            return obj.x < obj.y ? obj.x : obj.y;
        }
};

/// Nested Class
class Outer{
    int x;
    public:
        class Inner{
            public:
                void innerFunction(Outer& outer){
                    outer.x = 6;
                    cout<<"Inner Function :"<<outer.x<<endl;
                }
        };

        Outer(int x) : x(x){}

        void outerFunction(){
            Inner inner;
            cout<<"Outer Function :"<<x<<endl;
            inner.innerFunction(*this);
        }
};

int main(){
    TwoValues obj(5,6);
    Min m;
    cout<<m.min(obj)<<endl;

    Outer o(9);
    o.outerFunction();

    return 0;
}