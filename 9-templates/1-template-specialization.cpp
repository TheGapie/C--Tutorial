/*
Full Specialization:
    - This occurs when we provide specific implementation for specific type or set of types

Partial Specialization:
    - This occurs when we provide general implementation for a subset of types
*/

#include<iostream>
using namespace std;


// Full Specialization
template<typename T>
void print(T data){
    cout<<"General Data :"<<data<<endl;
}

void print(int data){
    cout<<"Specific for int Data :"<<data<<endl;
}

// Partial Specialization

template<typename T,typename X>
void func(T a, X b){
    cout<<"General Data-> A: "<<a<<"\t B : "<<b<<endl;
}

template<typename T>
void func(T a,int b){
    b+=6;
    cout<<"Partial Specific Data-> A: "<<a<<"\t B : "<<b<<endl;
}


int main(){
    print("Hello"); //  General Data :Hello
    print(6);   //  Specific for int Data :6
    
    func("Hello", 7.8); //  General Data-> A: Hello  B : 7.8
    func("World", 8);   //  Partial Specific Data-> A: World   B : 14
    return 0;
}