/*
Dynamic Typing: 
    - By default, C++ uses static typing. But it also allows dynaminc typing i.e. determinig the datatypes of variable at runtime.
    - We can achieve this by using void pointers and std::any (C++ 17)
*/

#include<iostream>
#include<any>
using namespace std;
int main(){
    int a = 5;
    float b = 5.6f;
    string str = "Hello World";

    // void Pointers

    void *voidPtr;
    voidPtr = &a;
    cout<<"int :"<<*static_cast<int*>(voidPtr)<<"\n";
    voidPtr = &b;
    cout<<"float :"<<*static_cast<float*>(voidPtr)<<"\n";
    voidPtr = &str;
    cout<<"String :"<<*static_cast<string*>(voidPtr)<<"\n";


    // std::any (C++ 17)

    any anyType;
    anyType = a;
    cout<<"int :"<<any_cast<int>(anyType)<<"\n";
    anyType = b;
    cout<<"float :"<<any_cast<float>(anyType)<<"\n";
    anyType = str;
    cout<<"String :"<<any_cast<string>(anyType)<<"\n";

    return 0;
}

// static_cast: - It is used for type conversion but with safer and predictable way
//              - restult_type result = static_type<result_type>(expression);