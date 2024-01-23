/*
Pointers :
    - Pointer is a variable that stores memory location of another variable.
    - It allows us to modify the value of the variable indirectly.
    - pointers can be assigned many times to different similar variables.
    - Pointers can be NULL or can be declared without initializing

    # syntax:
        dataType* ptr = &data;

References : 
    - References are like another name of some existing variable.
    - Unlike pointers, references can't be NULL;
    - It must be initialized at the time of declaration.
    - It cannot be changed to refer to another variable.
    - It behaves like const pointers

    # syntax:
        dataType &ref = data;

*/

#include<iostream>
using namespace std;

int main(){
    int a = 5;
    int &b = a;
    int c = 6;
    b = c; // changes b's value meaning a's value to c
    return 0;
}