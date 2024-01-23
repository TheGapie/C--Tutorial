// pragma : - pragma is an implementation-defined directive that allows various instructions to be given to compiler.
        //  - exact behaviour of pragma can vary between compiler to compiler.
        //  - It is generally used to turn on and turn off some features of compiler

#pragma once 
    #include<iostream>  //  This code will only included once. It used to avoid multiple-include
                        //  pragma once can reduce build times, as compiler won't read the file again after the first include.
                        //  It is called multiple-include-optimization


void func1();
void func2();

#pragma startup func1   //  (DEPENDS UPON COMPILER) runs before starting of the program. Works as constructor

#pragma exit func2      //  (DEPENDS UPON COMPILER) runs after ending of a program. Works as destructor

void func1(){
    std::cout<<"Inside Func1\n";
}
void func2(){
    std::cout<<"Inside Func2\n";
}

int main(){
    std::cout<<"Inside Main\n";
    return 0;
}