/*
reinterpret_cast:
    - reinterpret_cast is a type of casting in C++ that allows us to change the type of a pointer 
       or an integer without altering the representation of the data.
    - It is generally used when type casting required in too low level or not supported by other casting
       methods.
    - It is very powerful but can lead to unexpected behaviour if not used safely
*/
#include<iostream>
using namespace std;

int main(){
    int* nptr = new int(100); 
    char* cptr = reinterpret_cast<char*>(nptr); // d <- 1100100 <- 100

    cout<<cptr<<endl; // d
    
    return 0;
}