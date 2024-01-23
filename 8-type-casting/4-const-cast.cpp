/*
const_cast:
    - const_cast is used to convert const identifier to normal identifier
*/

#include<iostream>
using namespace std;

int main(){
    const int a = 5;
    cout<<"Before : "<<a<<endl;

    //a = 7; // can lead to compilation error
    int* ptr = const_cast<int*>(&a);
    *ptr = 7;
    cout<<"After : "<<*ptr<<endl;
    return 0;
}